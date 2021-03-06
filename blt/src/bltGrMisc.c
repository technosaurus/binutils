
/*
 * bltGrMisc.c --
 *
 *	This module implements miscellaneous routines for the BLT
 *	graph widget.
 *
 * Copyright 1993-1998 Lucent Technologies, Inc.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and warranty
 * disclaimer appear in supporting documentation, and that the names
 * of Lucent Technologies any of their entities not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * Lucent Technologies disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Lucent Technologies be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether in
 * an action of contract, negligence or other tortuous action, arising
 * out of or in connection with the use or performance of this
 * software.  
 */

#include "bltGraph.h"
#include <X11/Xutil.h>

#if defined(__STDC__)
#include <stdarg.h>
#else
#include <varargs.h>
#endif


static Tk_OptionParseProc StringToPoint;
static Tk_OptionPrintProc PointToString;
static Tk_OptionParseProc StringToColorPair;
static Tk_OptionPrintProc ColorPairToString;
Tk_CustomOption bltPointOption =
{
    StringToPoint, PointToString, (ClientData)0
};
Tk_CustomOption bltColorPairOption =
{
    StringToColorPair, ColorPairToString, (ClientData)0
};

/* ----------------------------------------------------------------------
 * Custom option parse and print procedures
 * ----------------------------------------------------------------------
 */

/*
 *----------------------------------------------------------------------
 *
 * Blt_GetXY --
 *
 *	Converts a string in the form "@x,y" into an XPoint structure
 *	of the x and y coordinates.
 *
 * Results:
 *	A standard Tcl result. If the string represents a valid position
 *	*pointPtr* will contain the converted x and y coordinates and
 *	TCL_OK is returned.  Otherwise,	TCL_ERROR is returned and
 *	interp->result will contain an error message.
 *
 *----------------------------------------------------------------------
 */
int
Blt_GetXY(interp, tkwin, string, xPtr, yPtr)
    Tcl_Interp *interp;
    Tk_Window tkwin;
    char *string;
    int *xPtr, *yPtr;
{
    char *comma;
    int result;
    int x, y;

    if ((string == NULL) || (*string == '\0')) {
	*xPtr = *yPtr = -SHRT_MAX;
	return TCL_OK;
    }
    if (*string != '@') {
	goto badFormat;
    }
    comma = strchr(string + 1, ',');
    if (comma == NULL) {
	goto badFormat;
    }
    *comma = '\0';
    result = ((Tk_GetPixels(interp, tkwin, string + 1, &x) == TCL_OK) &&
	(Tk_GetPixels(interp, tkwin, comma + 1, &y) == TCL_OK));
    *comma = ',';
    if (!result) {
	Tcl_AppendResult(interp, ": can't parse position \"", string, "\"",
	    (char *)NULL);
	return TCL_ERROR;
    }
    *xPtr = x, *yPtr = y;
    return TCL_OK;

  badFormat:
    Tcl_AppendResult(interp, "bad position \"", string, 
	     "\": should be \"@x,y\"", (char *)NULL);
    return TCL_ERROR;
}

/*
 *----------------------------------------------------------------------
 *
 * StringToPoint --
 *
 *	Convert the string representation of a legend XY position into
 *	window coordinates.  The form of the string must be "@x,y" or
 *	none.
 *
 * Results:
 *	A standard Tcl result.  The symbol type is written into the
 *	widget record.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
StringToPoint(clientData, interp, tkwin, string, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    char *string;		/* New legend position string */
    char *widgRec;		/* Widget record */
    int offset;			/* offset to XPoint structure */
{
    XPoint *pointPtr = (XPoint *)(widgRec + offset);
    int x, y;

    if (Blt_GetXY(interp, tkwin, string, &x, &y) != TCL_OK) {
	return TCL_ERROR;
    }
    pointPtr->x = x, pointPtr->y = y;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * PointToString --
 *
 *	Convert the window coordinates into a string.
 *
 * Results:
 *	The string representing the coordinate position is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static char *
PointToString(clientData, tkwin, widgRec, offset, freeProcPtr)
    ClientData clientData;	/* Not used. */
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;		/* Widget record */
    int offset;			/* offset of XPoint in record */
    Tcl_FreeProc **freeProcPtr;	/* Memory deallocation scheme to use */
{
    char *result;
    XPoint *pointPtr = (XPoint *)(widgRec + offset);

    result = "";
    if ((pointPtr->x != -SHRT_MAX) && (pointPtr->y != -SHRT_MAX)) {
	char string[200];

	sprintf(string, "@%d,%d", pointPtr->x, pointPtr->y);
	result = Blt_Strdup(string);
	assert(result);
	*freeProcPtr = (Tcl_FreeProc *)Blt_Free;
    }
    return result;
}

/*LINTLIBRARY*/
static int
GetColorPair(interp, tkwin, fgStr, bgStr, pairPtr, allowDefault)
    Tcl_Interp *interp;
    Tk_Window tkwin;
    char *fgStr, *bgStr;
    ColorPair *pairPtr;
    int allowDefault;
{
    unsigned int length;
    XColor *fgColor, *bgColor;

    fgColor = bgColor = NULL;
    length = strlen(fgStr);
    if (fgStr[0] == '\0') {
	fgColor = NULL;
    } else if ((allowDefault) && (fgStr[0] == 'd') &&
	(strncmp(fgStr, "defcolor", length) == 0)) {
	fgColor = COLOR_DEFAULT;
    } else {
	fgColor = Tk_GetColor(interp, tkwin, Tk_GetUid(fgStr));
	if (fgColor == NULL) {
	    return TCL_ERROR;
	}
    }
    length = strlen(bgStr);
    if (bgStr[0] == '\0') {
	bgColor = NULL;
    } else if ((allowDefault) && (bgStr[0] == 'd') &&
	(strncmp(bgStr, "defcolor", length) == 0)) {
	bgColor = COLOR_DEFAULT;
    } else {
	bgColor = Tk_GetColor(interp, tkwin, Tk_GetUid(bgStr));
	if (bgColor == NULL) {
	    return TCL_ERROR;
	}
    }
    pairPtr->fgColor = fgColor;
    pairPtr->bgColor = bgColor;
    return TCL_OK;
}

void
Blt_FreeColorPair(pairPtr)
    ColorPair *pairPtr;
{
    if ((pairPtr->bgColor != NULL) && (pairPtr->bgColor != COLOR_DEFAULT)) {
	Tk_FreeColor(pairPtr->bgColor);
    }
    if ((pairPtr->fgColor != NULL) && (pairPtr->fgColor != COLOR_DEFAULT)) {
	Tk_FreeColor(pairPtr->fgColor);
    }
    pairPtr->bgColor = pairPtr->fgColor = NULL;
}

/*
 *----------------------------------------------------------------------
 *
 * StringToColorPair --
 *
 *	Convert the color names into pair of XColor pointers.
 *
 * Results:
 *	A standard Tcl result.  The color pointer is written into the
 *	widget record.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static int
StringToColorPair(clientData, interp, tkwin, string, widgRec, offset)
    ClientData clientData;	/* Not used. */
    Tcl_Interp *interp;		/* Interpreter to send results back to */
    Tk_Window tkwin;		/* Not used. */
    char *string;		/* String representing color */
    char *widgRec;		/* Widget record */
    int offset;			/* Offset of color field in record */
{
    ColorPair *pairPtr = (ColorPair *)(widgRec + offset);
    ColorPair sample;
    int allowDefault = (int)clientData;

    sample.fgColor = sample.bgColor = NULL;
    if ((string != NULL) && (*string != '\0')) {
	int nColors;
	char **colors;
	int result;

	if (Tcl_SplitList(interp, string, &nColors, &colors) != TCL_OK) {
	    return TCL_ERROR;
	}
	result = TCL_ERROR;
	switch (nColors) {
	case 0:
	    result = TCL_OK;
	    break;
	case 1:
	    result = GetColorPair(interp, tkwin, colors[0], "", &sample,
		allowDefault);
	    break;
	case 2:
	    result = GetColorPair(interp, tkwin, colors[0], colors[1],
		&sample, allowDefault);
	    break;
	default:
	    result = TCL_ERROR;
	    Tcl_AppendResult(interp, "too many names in colors list",
		(char *)NULL);
	}
	Blt_Free(colors);
	if (result != TCL_OK) {
	    return TCL_ERROR;
	}
    }
    Blt_FreeColorPair(pairPtr);
    *pairPtr = sample;
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * NameOfColor --
 *
 *	Convert the color option value into a string.
 *
 * Results:
 *	The static string representing the color option is returned.
 *
 *----------------------------------------------------------------------
 */
static char *
NameOfColor(colorPtr)
    XColor *colorPtr;
{
    if (colorPtr == NULL) {
	return "";
    } else if (colorPtr == COLOR_DEFAULT) {
	return "defcolor";
    } else {
	return Tk_NameOfColor(colorPtr);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * ColorPairToString --
 *
 *	Convert the color pairs into color names.
 *
 * Results:
 *	The string representing the symbol color is returned.
 *
 *----------------------------------------------------------------------
 */
/*ARGSUSED*/
static char *
ColorPairToString(clientData, tkwin, widgRec, offset, freeProcPtr)
    ClientData clientData;	/* Not used. */
    Tk_Window tkwin;		/* Not used. */
    char *widgRec;		/* Element information record */
    int offset;			/* Offset of symbol type field in record */
    Tcl_FreeProc **freeProcPtr;	/* Not used. */
{
    ColorPair *pairPtr = (ColorPair *)(widgRec + offset);
    Tcl_DString dString;
    char *result;

    Tcl_DStringInit(&dString);
    Tcl_DStringAppendElement(&dString, NameOfColor(pairPtr->fgColor));
    Tcl_DStringAppendElement(&dString, NameOfColor(pairPtr->bgColor));
    result = Tcl_DStringValue(&dString);
    if (result == dString.staticSpace) {
	result = Blt_Strdup(result);
    }
    *freeProcPtr = (Tcl_FreeProc *)Blt_Free;
    return result;
}

int
Blt_PointInSegments(samplePtr, segments, nSegments, halo)
    Point2D *samplePtr;
    Segment2D *segments;
    int nSegments;
    double halo;
{
    register Segment2D *segPtr, *endPtr;
    double left, right, top, bottom;
    Point2D p, t;
    double dist, minDist;

    minDist = DBL_MAX;
    for (segPtr = segments, endPtr = segments + nSegments; segPtr < endPtr; 
	 segPtr++) {
	t = Blt_GetProjection((int)samplePtr->x, (int)samplePtr->y, 
		      &segPtr->p, &segPtr->q);
	if (segPtr->p.x > segPtr->q.x) {
	    right = segPtr->p.x, left = segPtr->q.x;
	} else {
	    right = segPtr->q.x, left = segPtr->p.x;
	}
	if (segPtr->p.y > segPtr->q.y) {
	    bottom = segPtr->p.y, top = segPtr->q.y;
	} else {
	    bottom = segPtr->q.y, top = segPtr->p.y;
	}
	p.x = BOUND(t.x, left, right);
	p.y = BOUND(t.y, top, bottom);
	dist = hypot(p.x - samplePtr->x, p.y - samplePtr->y);
	if (dist < minDist) {
	    minDist = dist;
	}
    }
    return (minDist < halo);
}

int
Blt_PointInPolygon(samplePtr, points, nPoints)
    Point2D *samplePtr;
    Point2D *points;
    int nPoints;
{
    double b;
    register Point2D *p, *q, *endPtr;
    register int count;

    count = 0;
    for (p = points, q = p + 1, endPtr = p + nPoints; q < endPtr; p++, q++) {
	if (((p->y <= samplePtr->y) && (samplePtr->y < q->y)) || 
	    ((q->y <= samplePtr->y) && (samplePtr->y < p->y))) {
	    b = (q->x - p->x) * (samplePtr->y - p->y) / (q->y - p->y) + p->x;
	    if (samplePtr->x < b) {
		count++;	/* Count the number of intersections. */
	    }
	}
    }
    return (count & 0x01);
}

int
Blt_RegionInPolygon(extsPtr, points, nPoints, enclosed)
    Extents2D *extsPtr;
    Point2D *points;
    int nPoints;
    int enclosed;
{
    register Point2D *pointPtr, *endPtr;

    if (enclosed) {
	/*  
	 * All points of the polygon must be inside the rectangle.
	 */
	for (pointPtr = points, endPtr = points + nPoints; pointPtr < endPtr; 
	     pointPtr++) {
	    if ((pointPtr->x < extsPtr->left) ||
		(pointPtr->x > extsPtr->right) ||
		(pointPtr->y < extsPtr->top) ||
		(pointPtr->y > extsPtr->bottom)) {
		return FALSE;	/* One point is exterior. */
	    }
	}
	return TRUE;
    } else {
	Point2D p, q;

	/*
	 * If any segment of the polygon clips the bounding region, the
	 * polygon overlaps the rectangle.
	 */
	points[nPoints] = points[0];
	for (pointPtr = points, endPtr = points + nPoints; pointPtr < endPtr; 
	     pointPtr++) {
	    p = *pointPtr;
	    q = *(pointPtr + 1);
	    if (Blt_LineRectClip(extsPtr, &p, &q)) {
		return TRUE;
	    }
	}
	/* 
	 * Otherwise the polygon and rectangle are either disjoint
	 * or enclosed.  Check if one corner of the rectangle is
	 * inside the polygon.  
	 */
	p.x = extsPtr->left;
	p.y = extsPtr->top;
	return Blt_PointInPolygon(&p, points, nPoints);
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_GraphExtents --
 *
 *	Generates a bounding box representing the plotting area of
 *	the graph. This data structure is used to clip the points and
 *	line segments of the line element.
 *
 *	The clip region is the plotting area plus such arbitrary extra
 *	space.  The reason we clip with a bounding box larger than the
 *	plot area is so that symbols will be drawn even if their center
 *	point isn't in the plotting area.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	The bounding box is filled with the dimensions of the plotting
 *	area.
 *
 *----------------------------------------------------------------------
 */
void
Blt_GraphExtents(graphPtr, extsPtr)
    Graph *graphPtr;
    Extents2D *extsPtr;
{
    extsPtr->left = (double)(graphPtr->hOffset - graphPtr->padX.side1);
    extsPtr->top = (double)(graphPtr->vOffset - graphPtr->padY.side1);
    extsPtr->right = (double)(graphPtr->hOffset + graphPtr->hRange + 
	graphPtr->padX.side2);
    extsPtr->bottom = (double)(graphPtr->vOffset + graphPtr->vRange + 
	graphPtr->padY.side2);
}

static int 
ClipTest (double ds, double dr, double *t1, double *t2)
{
  double t;

  if (ds < 0.0) {
      t = dr / ds;
      if (t > *t2) {
	  return FALSE;
      } 
      if (t > *t1) {
	  *t1 = t;
      }
  } else if (ds > 0.0) {
      t = dr / ds;
      if (t < *t1) {
	  return FALSE;
      } 
      if (t < *t2) {
	  *t2 = t;
      }
  } else {
      /* d = 0, so line is parallel to this clipping edge */
      if (dr < 0.0) { /* Line is outside clipping edge */
	  return FALSE;
      }
  }
  return TRUE;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_LineRectClip --
 *
 *	Clips the given line segment to a rectangular region.  The
 *	coordinates of the clipped line segment are returned.  The
 *	original coordinates are overwritten.
 *
 *	Reference:  Liang-Barsky Line Clipping Algorithm.
 *
 * Results:
 *	Returns if line segment is visible within the region. The
 *	coordinates of the original line segment are overwritten
 *	by the clipped coordinates.
 *
 *---------------------------------------------------------------------- 
 */
int 
Blt_LineRectClip(extsPtr, p, q)
    Extents2D *extsPtr;		/* Rectangular region to clip. */
    Point2D *p, *q;		/* (in/out) Coordinates of original
				 * and clipped line segment. */
{
    double t1, t2;
    double dx, dy;

    t1 = 0.0;
    t2 = 1.0;
    dx = q->x - p->x;
    if ((ClipTest (-dx, p->x - extsPtr->left, &t1, &t2)) &&
	(ClipTest (dx, extsPtr->right - p->x, &t1, &t2))) {
	dy = q->y - p->y;
	if ((ClipTest (-dy, p->y - extsPtr->top, &t1, &t2)) && 
	    (ClipTest (dy, extsPtr->bottom - p->y, &t1, &t2))) {
	    if (t2 < 1.0) {
		q->x = p->x + t2 * dx;
		q->y = p->y + t2 * dy;
	    }
	    if (t1 > 0.0) {
		p->x += t1 * dx;
		p->y += t1 * dy;
	    }
	    return TRUE;
	}
    }
    return FALSE;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_PolyRectClip --
 *
 *	Clips the given polygon to a rectangular region.  The resulting
 *	polygon is returned. Note that the resulting polyon may be 
 *	complex, connected by zero width/height segments.  The drawing 
 *	routine (such as XFillPolygon) will not draw a connecting
 *	segment.
 *
 *	Reference:  Liang-Barsky Polygon Clipping Algorithm 
 *
 * Results:
 *	Returns the number of points in the clipped polygon. The
 *	points of the clipped polygon are stored in *outputPts*.
 *
 *---------------------------------------------------------------------- 
 */
#define EPSILON  FLT_EPSILON
#define AddVertex(vx, vy)	    r->x=(vx), r->y=(vy), r++, count++ 

int 
Blt_PolyRectClip(extsPtr, points, nPoints, clipPts)
    Extents2D *extsPtr;
    Point2D *points;
    int nPoints;
    Point2D *clipPts;
{
    Point2D *endPtr;
    double dx, dy;
    double tin1, tin2;
    double tinx, tiny;
    double xin, yin, xout, yout;
    int count;
    register Point2D *p;	/* First vertex of input polygon edge. */
    register Point2D *q;	/* Last vertex of input polygon edge. */
    register Point2D *r;

    r = clipPts;
    count = 0;			/* Counts # of vertices in output polygon. */

    points[nPoints] = points[0];

    for (p = points, q = p + 1, endPtr = p + nPoints; p < endPtr; p++, q++) {
	dx = q->x - p->x;	/* X-direction */
	dy = q->y - p->y;	/* Y-direction */

	if (FABS(dx) < EPSILON) { 
	    dx = (p->x > extsPtr->left) ? -EPSILON : EPSILON ;
	}
	if (FABS(dy) < EPSILON) { 
	    dy = (p->y > extsPtr->top) ? -EPSILON : EPSILON ;
	}

	if (dx > 0.0) {		/* Left */
	    xin = extsPtr->left;
	    xout = extsPtr->right + 1.0;
	} else {		/* Right */
	    xin = extsPtr->right + 1.0;
	    xout = extsPtr->left;
	}
	if (dy > 0.0) {		/* Top */
	    yin = extsPtr->top;
	    yout = extsPtr->bottom + 1.0;
	} else {		/* Bottom */
	    yin = extsPtr->bottom + 1.0;
	    yout = extsPtr->top;
	}
	
	tinx = (xin - p->x) / dx;
	tiny = (yin - p->y) / dy;
	
	if (tinx < tiny) {	/* Hits x first */
	    tin1 = tinx;
	    tin2 = tiny;
	} else {		/* Hits y first */
	    tin1 = tiny;
	    tin2 = tinx;
	}
	
	if (tin1 <= 1.0) {
	    if (tin1 > 0.0) {
		AddVertex(xin, yin);
            }
	    if (tin2 <= 1.0) {
		double toutx, touty, tout1;

		toutx = (xout - p->x) / dx;
		touty = (yout - p->y) / dy;
		tout1 = MIN(toutx, touty);
		
		if ((tin2 > 0.0) || (tout1 > 0.0)) {
		    if (tin2 <= tout1) {
			if (tin2 > 0.0) {
			    if (tinx > tiny) {
				AddVertex(xin, p->y + tinx * dy);
			    } else {
				AddVertex(p->x + tiny * dx, yin);
			    }
			}
			if (tout1 < 1.0) {
			    if (toutx < touty) {
				AddVertex(xout, p->y + toutx * dy);
			    } else {
				AddVertex(p->x + touty * dx, yout);
			    }
			} else {
			    AddVertex(q->x, q->y);
			}
		    } else {
			if (tinx > tiny) {
			    AddVertex(xin, yout);
			} else {
			    AddVertex(xout, yin);
			}
		    }
		}
            }
	}
    }
    if (count > 0) {
	AddVertex(clipPts[0].x, clipPts[0].y);
    }
    return count;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_GetProjection --
 *
 *	Computes the projection of a point on a line.  The line (given
 *	by two points), is assumed the be infinite.
 *
 *	Compute the slope (angle) of the line and rotate it 90 degrees.
 *	Using the slope-intercept method (we know the second line from
 *	the sample test point and the computed slope), then find the
 *	intersection of both lines. This will be the projection of the
 *	sample point on the first line.
 *
 * Results:
 *	Returns the coordinates of the projection on the line.
 *
 *----------------------------------------------------------------------
 */
Point2D
Blt_GetProjection(x, y, p, q)
    int x, y;			/* Screen coordinates of the sample point. */
    Point2D *p, *q;		/* Line segment to project point onto */
{
    double dx, dy;
    Point2D t;

    dx = p->x - q->x;
    dy = p->y - q->y;

    /* Test for horizontal and vertical lines */
    if (FABS(dx) < DBL_EPSILON) {
	t.x = p->x, t.y = (double)y;
    } else if (FABS(dy) < DBL_EPSILON) {
	t.x = (double)x, t.y = p->y;
    } else {
	double m1, m2;		/* Slope of both lines */
	double b1, b2;		/* y-intercepts */
	double midX, midY;	/* Midpoint of line segment. */
	double ax, ay, bx, by;

	/* Compute the slop and intercept of the line segment. */
	m1 = (dy / dx);
	b1 = p->y - (p->x * m1);

	/* 
	 * Compute the slope and intercept of a second line segment:
	 * one that intersects through sample X-Y coordinate with a
	 * slope perpendicular to original line. 
	 */

	/* Find midpoint of original segment. */
	midX = (p->x + q->x) * 0.5;
	midY = (p->y + q->y) * 0.5;

	/* Rotate the line 90 degrees */
	ax = midX - (0.5 * dy);
	ay = midY - (0.5 * -dx);
	bx = midX + (0.5 * dy);
	by = midY + (0.5 * -dx);

	m2 = (ay - by) / (ax - bx);
	b2 = y - (x * m2);

	/*
	 * Given the equations of two lines which contain the same point,
	 *
	 *    y = m1 * x + b1
	 *    y = m2 * x + b2
	 *
	 * solve for the intersection.
	 *
	 *    x = (b2 - b1) / (m1 - m2)
	 *    y = m1 * x + b1
	 *
	 */

	t.x = (b2 - b1) / (m1 - m2);
	t.y = m1 * t.x + b1;
    }
    return t;
}


#define SetColor(c,r,g,b) ((c)->red = (int)((r) * 65535.0), \
			   (c)->green = (int)((g) * 65535.0), \
			   (c)->blue = (int)((b) * 65535.0))

void
Blt_HSV(colorPtr, huePtr, valPtr, satPtr)
    XColor *colorPtr;
    double *huePtr, *valPtr, *satPtr;
{
    unsigned short iMax, iMin;
    double range;
    unsigned short *colorValues;
    register int i;
    double hue, sat, val;

    /* Find the minimum and maximum RGB intensities */
    colorValues = (unsigned short *)&colorPtr->red;
    iMax = iMin = colorValues[0];
    for (i = 1; i < 3; i++) {
	if (iMax < colorValues[i]) {
	    iMax = colorValues[i];
	} else if (iMin > colorValues[i]) {
	    iMin = colorValues[i];
	}
    }

    val = (double)iMax / 65535.0;
    hue = 0.0, sat = 0.0;

    range = (double)iMax - (double)iMin;
    if (iMax != iMin) {
	sat = range / (double)iMax;
    }
    if (sat > 0.0) {
	double r, g, b;

	/* Normalize the RGB values */
	r = ((double)iMax - (double)colorPtr->red) / range;
	g = ((double)iMax - (double)colorPtr->green) / range;
	b = ((double)iMax - (double)colorPtr->blue) / range;

	if (colorPtr->red == iMax) {
	    hue = (double)(b - g);
	} else if (colorPtr->green == iMax) {
	    hue = (double)(2 + (r - b));
	} else if (colorPtr->blue == iMax) {
	    hue = (double)(4 + (g - r));
	}
	hue *= 60.0;
    } else {
	sat = 0.5;
    }
    if (hue < 0.0) {
	hue += 360.0;
    }
    *huePtr = hue;
    *valPtr = val;
    *satPtr = sat;
}

void
Blt_RGB(hue, sat, val, colorPtr)
    double hue, sat, val;
    XColor *colorPtr;
{
    double p, q, t;
    double frac;
    int ihue;

    if (val < 0.0) {
	val = 0.0;
    } else if (val > 1.0) {
	val = 1.0;
    }
    if (sat == 0.0) {
	SetColor(colorPtr, val, val, val);
	return;
    }
    hue = FMOD(hue, 360.0) / 60.0;
    ihue = (int)floor(hue);
    frac = hue - ihue;
    p = val * (1 - sat);
    q = val * (1 - (sat * frac));
    t = val * (1 - (sat * (1 - frac)));

    switch (ihue) {
    case 0:
	SetColor(colorPtr, val, t, p);
	break;
    case 1:
	SetColor(colorPtr, q, val, p);
	break;
    case 2:
	SetColor(colorPtr, p, val, t);
	break;
    case 3:
	SetColor(colorPtr, p, q, val);
	break;
    case 4:
	SetColor(colorPtr, t, p, val);
	break;
    case 5:
	SetColor(colorPtr, val, p, q);
	break;
    }
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_AdjustViewport --
 *
 *	Adjusts the offsets of the viewport according to the scroll mode.
 *	This is to accommodate both "listbox" and "canvas" style scrolling.
 *
 *	"canvas"	The viewport scrolls within the range of world
 *			coordinates.  This way the viewport always displays
 *			a full page of the world.  If the world is smaller
 *			than the viewport, then (bizarrely) the world and
 *			viewport are inverted so that the world moves up
 *			and down within the viewport.
 *
 *	"listbox"	The viewport can scroll beyond the range of world
 *			coordinates.  Every entry can be displayed at the
 *			top of the viewport.  This also means that the
 *			scrollbar thumb weirdly shrinks as the last entry
 *			is scrolled upward.
 *
 * Results:
 *	The corrected offset is returned.
 *
 *----------------------------------------------------------------------
 */
int
Blt_AdjustViewport(offset, worldSize, windowSize, scrollUnits, scrollMode)
    int offset, worldSize, windowSize;
    int scrollUnits;
    int scrollMode;
{
    switch (scrollMode) {
    case BLT_SCROLL_MODE_CANVAS:

	/*
	 * Canvas-style scrolling allows the world to be scrolled
	 * within the window.
	 */

	if (worldSize < windowSize) {
	    if ((worldSize - offset) > windowSize) {
		offset = worldSize - windowSize;
	    }
	    if (offset > 0) {
		offset = 0;
	    }
	} else {
	    if ((offset + windowSize) > worldSize) {
		offset = worldSize - windowSize;
	    }
	    if (offset < 0) {
		offset = 0;
	    }
	}
	break;

    case BLT_SCROLL_MODE_LISTBOX:
	if (offset < 0) {
	    offset = 0;
	}
	if (offset >= worldSize) {
	    offset = worldSize - scrollUnits;
	}
	break;

    case BLT_SCROLL_MODE_HIERBOX:

	/*
	 * Hierbox-style scrolling allows the world to be scrolled
	 * within the window.
	 */
	if ((offset + windowSize) > worldSize) {
	    offset = worldSize - windowSize;
	}
	if (offset < 0) {
	    offset = 0;
	}
	break;
    }
    return offset;
}

int
Blt_GetScrollInfo(interp, argc, argv, offsetPtr, worldSize, windowSize,
    scrollUnits, scrollMode)
    Tcl_Interp *interp;
    int argc;
    char **argv;
    int *offsetPtr;
    int worldSize, windowSize;
    int scrollUnits;
    int scrollMode;
{
    char c;
    unsigned int length;
    int offset;
    int count;
    double fract;

    offset = *offsetPtr;
    c = argv[0][0];
    length = strlen(argv[0]);
    if ((c == 's') && (strncmp(argv[0], "scroll", length) == 0)) {
	if (argc != 3) {
	    return TCL_ERROR;
	}
	/* scroll number unit/page */
	if (Tcl_GetInt(interp, argv[1], &count) != TCL_OK) {
	    return TCL_ERROR;
	}
	c = argv[2][0];
	length = strlen(argv[2]);
	if ((c == 'u') && (strncmp(argv[2], "units", length) == 0)) {
	    fract = (double)count *scrollUnits;
	} else if ((c == 'p') && (strncmp(argv[2], "pages", length) == 0)) {
	    /* A page is 90% of the view-able window. */
	    fract = (double)count *windowSize * 0.9;
	} else {
	    Tcl_AppendResult(interp, "unknown \"scroll\" units \"", argv[2],
		"\"", (char *)NULL);
	    return TCL_ERROR;
	}
	offset += (int)fract;
    } else if ((c == 'm') && (strncmp(argv[0], "moveto", length) == 0)) {
	if (argc != 2) {
	    return TCL_ERROR;
	}
	/* moveto fraction */
	if (Tcl_GetDouble(interp, argv[1], &fract) != TCL_OK) {
	    return TCL_ERROR;
	}
	offset = (int)(worldSize * fract);
    } else {
	/* Treat like "scroll units" */
	if (Tcl_GetInt(interp, argv[0], &count) != TCL_OK) {
	    return TCL_ERROR;
	}
	fract = (double)count *scrollUnits;
	offset += (int)fract;
	return TCL_OK;
    }
    *offsetPtr = Blt_AdjustViewport(offset, worldSize, windowSize, scrollUnits,
	scrollMode);
    return TCL_OK;
}

#if (TCL_MAJOR_VERSION >= 8)
int
Blt_GetScrollInfoFromObj(interp, objc, objv, offsetPtr, worldSize, windowSize,
    scrollUnits, scrollMode)
    Tcl_Interp *interp;
    int objc;
    Tcl_Obj *CONST *objv;
    int *offsetPtr;
    int worldSize, windowSize;
    int scrollUnits;
    int scrollMode;
{
    char c;
    unsigned int length;
    int offset;
    int count;
    double fract;
    char *string;

    offset = *offsetPtr;

    string = Tcl_GetString(objv[0]);
    c = string[0];
    length = strlen(string);
    if ((c == 's') && (strncmp(string, "scroll", length) == 0)) {
	if (objc != 3) {
	    return TCL_ERROR;
	}
	/* scroll number unit/page */
	if (Tcl_GetIntFromObj(interp, objv[1], &count) != TCL_OK) {
	    return TCL_ERROR;
	}
	string = Tcl_GetString(objv[2]);
	c = string[0];
	length = strlen(string);
	if ((c == 'u') && (strncmp(string, "units", length) == 0)) {
	    fract = (double)count *scrollUnits;
	} else if ((c == 'p') && (strncmp(string, "pages", length) == 0)) {
	    /* A page is 90% of the view-able window. */
	    fract = (double)count *windowSize * 0.9;
	} else {
	    Tcl_AppendResult(interp, "unknown \"scroll\" units \"", 
		     Tcl_GetString(objv[2]), "\"", (char *)NULL);
	    return TCL_ERROR;
	}
	offset += (int)fract;
    } else if ((c == 'm') && (strncmp(string, "moveto", length) == 0)) {
	if (objc != 2) {
	    return TCL_ERROR;
	}
	/* moveto fraction */
	if (Tcl_GetDoubleFromObj(interp, objv[1], &fract) != TCL_OK) {
	    return TCL_ERROR;
	}
	offset = (int)(worldSize * fract);
    } else {
	/* Treat like "scroll units" */
	if (Tcl_GetIntFromObj(interp, objv[0], &count) != TCL_OK) {
	    return TCL_ERROR;
	}
	fract = (double)count *scrollUnits;
	offset += (int)fract;
	return TCL_OK;
    }
    *offsetPtr = Blt_AdjustViewport(offset, worldSize, windowSize, scrollUnits,
	scrollMode);
    return TCL_OK;
}
#endif /* TCL_MAJOR_VERSION >= 8 */

/*
 * ----------------------------------------------------------------------
 *
 * Blt_UpdateScrollbar --
 *
 * 	Invoke a Tcl command to the scrollbar, defining the new
 *	position and length of the scroll. See the Tk documentation
 *	for further information on the scrollbar.  It is assumed the
 *	scrollbar command prefix is valid.
 *
 * Results:
 *	None.
 *
 * Side Effects:
 *	Scrollbar is commanded to change position and/or size.
 *
 * ----------------------------------------------------------------------
 */
void
Blt_UpdateScrollbar(interp, scrollCmd, firstFract, lastFract)
    Tcl_Interp *interp;
    char *scrollCmd;		/* scrollbar command */
    double firstFract, lastFract;
{
    char string[200];
    Tcl_DString dString;

    Tcl_DStringInit(&dString);
    Tcl_DStringAppend(&dString, scrollCmd, -1);
    sprintf(string, " %f %f", firstFract, lastFract);
    Tcl_DStringAppend(&dString, string, -1);
    if (Tcl_GlobalEval(interp, Tcl_DStringValue(&dString)) != TCL_OK) {
	Tcl_BackgroundError(interp);
    }
    Tcl_DStringFree(&dString);
}

/* -------------- */
/*
 *----------------------------------------------------------------------
 *
 * Blt_GetPrivateGCFromDrawable --
 *
 *      Like Tk_GetGC, but doesn't share the GC with any other widget.
 *	This is needed because the certain GC parameters (like dashes)
 *	can not be set via XCreateGC, therefore there is no way for
 *	Tk's hashing mechanism to recognize that two such GCs differ.
 *
 * Results:
 *      A new GC is returned.
 *
 *----------------------------------------------------------------------
 */
GC
Blt_GetPrivateGCFromDrawable(display, drawable, gcMask, valuePtr)
    Display *display;
    Drawable drawable;
    unsigned long gcMask;
    XGCValues *valuePtr;
{
    GC newGC;

#ifdef WIN32
    newGC = Blt_EmulateXCreateGC(display, drawable, gcMask, valuePtr);
#else
    newGC = XCreateGC(display, drawable, gcMask, valuePtr);
#endif
    return newGC;
}

/*
 *----------------------------------------------------------------------
 *
 * Blt_GetPrivateGC --
 *
 *      Like Tk_GetGC, but doesn't share the GC with any other widget.
 *	This is needed because the certain GC parameters (like dashes)
 *	can not be set via XCreateGC, therefore there is no way for
 *	Tk's hashing mechanism to recognize that two such GCs differ.
 *
 * Results:
 *      A new GC is returned.
 *
 *----------------------------------------------------------------------
 */
GC
Blt_GetPrivateGC(tkwin, gcMask, valuePtr)
    Tk_Window tkwin;
    unsigned long gcMask;
    XGCValues *valuePtr;
{
    GC gc;
    Pixmap pixmap;
    Drawable drawable;
    Display *display;

    pixmap = None;
    drawable = Tk_WindowId(tkwin);
    display = Tk_Display(tkwin);

    if (drawable == None) {
	Drawable root;
	int depth;

	root = RootWindow(display, Tk_ScreenNumber(tkwin));
	depth = Tk_Depth(tkwin);

	if (depth == DefaultDepth(display, Tk_ScreenNumber(tkwin))) {
	    drawable = root;
	} else {
	    pixmap = Tk_GetPixmap(display, root, 1, 1, depth);
	    drawable = pixmap;
	}
    }
    gc = Blt_GetPrivateGCFromDrawable(display, drawable, gcMask, valuePtr);
    if (pixmap != None) {
	Tk_FreePixmap(display, pixmap);
    }
    return gc;
}

void
Blt_FreePrivateGC(display, gc)
    Display *display;
    GC gc;
{
    Tk_FreeXId(display, (XID) XGContextFromGC(gc));
    XFreeGC(display, gc);
}

#ifndef WIN32
void
Blt_SetDashes(display, gc, dashesPtr)
    Display *display;
    GC gc;
    Blt_Dashes *dashesPtr;
{
    XSetDashes(display, gc, dashesPtr->offset, 
       (CONST char *)dashesPtr->values, strlen((char *)dashesPtr->values));
}
#endif


static double
FindSplit(points, i, j, split) 
    Point2D points[];
    int i, j;			/* Indices specifying the range of points. */
    int *split;			/* (out) Index of next split. */
{
    double maxDist;
    
    maxDist = -1.0;
    if ((i + 1) < j) {
	register int k;
	double a, b, c;	
	double sqDist;

	/* 
	 * 
	 * sqDist P(k) =  |  1  P(i).x  P(i).y  |
	 *		  |  1  P(j).x  P(j).y  |
	 *                |  1  P(k).x  P(k).y  |
	 *              ---------------------------
 	 *       (P(i).x - P(j).x)^2 + (P(i).y - P(j).y)^2
	 */

	a = points[i].y - points[j].y;
	b = points[j].x - points[i].x;
	c = (points[i].x * points[j].y) - (points[i].y * points[j].x);
	for (k = (i + 1); k < j; k++) {
	    sqDist = (points[k].x * a) + (points[k].y * b) + c;
	    if (sqDist < 0.0) {
		sqDist = -sqDist;	
	    }
	    if (sqDist > maxDist) {
		maxDist = sqDist;	/* Track the maximum. */
		*split = k;
	    }
	}
	/* Correction for segment length---should be redone if can == 0 */
	maxDist *= maxDist / (a * a + b * b);
    } 
    return maxDist;
}


/* Douglas-Peucker line simplification algorithm */
int
Blt_SimplifyLine(inputPts, low, high, tolerance, indices) 
   Point2D inputPts[];
   int low, high;
   double tolerance;
   int indices[];
{
#define StackPush(a)	s++, stack[s] = (a)
#define StackPop(a)	(a) = stack[s], s--
#define StackEmpty()	(s < 0)
#define StackTop()	stack[s]
    int *stack;
    int split = -1; 
    double sqDist, sqTolerance;
    int s = -1;			/* Points to top stack item. */
    int count;

    stack = Blt_Malloc(sizeof(int) * (high - low + 1));
    StackPush(high);
    count = 0;
    indices[count++] = 0;
    sqTolerance = tolerance * tolerance;
    while (!StackEmpty()) {
	sqDist = FindSplit(inputPts, low, StackTop(), &split);
	if (sqDist > sqTolerance) {
	    StackPush(split);
	} else {
	    indices[count++] = StackTop();
	    StackPop(low);
	}
    } 
    Blt_Free(stack);
    return count;
}

void
Blt_DrawSegments2D(display, drawable, gc, segPtr, nSegments)
    Display *display;
    Drawable drawable;
    GC gc;
    register Segment2D *segPtr;
    int nSegments;
{
    XSegment *xSegPtr, *xSegArr;
    Segment2D *endPtr;

    xSegArr = Blt_Malloc(nSegments * sizeof(XSegment));
    if (xSegArr == NULL) {
	return;
    }
    xSegPtr = xSegArr;
    for (endPtr = segPtr + nSegments; segPtr < endPtr; segPtr++) {
	xSegPtr->x1 = (short int)segPtr->p.x;
	xSegPtr->y1 = (short int)segPtr->p.y;
	xSegPtr->x2 = (short int)segPtr->q.x;
	xSegPtr->y2 = (short int)segPtr->q.y;
	xSegPtr++;
    }
    XDrawSegments(display, drawable, gc, xSegArr, nSegments);
    Blt_Free(xSegArr);
}

