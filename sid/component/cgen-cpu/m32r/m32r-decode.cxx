/* Simulator instruction decoder for m32rbf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 2000, 2001, 2002, 2003 Red Hat, Inc.

This file is part of the Red Hat simulators.


*/


#if HAVE_CONFIG_H
#include "config.h"
#endif
#include "m32rbf.h"

using namespace m32rbf; // FIXME: namespace organization still wip


// The instruction descriptor array. 

m32rbf_idesc m32rbf_idesc::idesc_table[M32RBF_INSN_UNLOCK + 1] =
{
  { m32rbf_sem_x_invalid, "X_INVALID", M32RBF_INSN_X_INVALID, { 0|(1<<CGEN_INSN_VIRTUAL), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_add, "ADD", M32RBF_INSN_ADD, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_add3, "ADD3", M32RBF_INSN_ADD3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_and, "AND", M32RBF_INSN_AND, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_and3, "AND3", M32RBF_INSN_AND3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_or, "OR", M32RBF_INSN_OR, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_or3, "OR3", M32RBF_INSN_OR3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_xor, "XOR", M32RBF_INSN_XOR, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_xor3, "XOR3", M32RBF_INSN_XOR3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_addi, "ADDI", M32RBF_INSN_ADDI, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_addv, "ADDV", M32RBF_INSN_ADDV, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_addv3, "ADDV3", M32RBF_INSN_ADDV3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_addx, "ADDX", M32RBF_INSN_ADDX, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_bc8, "BC8", M32RBF_INSN_BC8, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_bc24, "BC24", M32RBF_INSN_BC24, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_beq, "BEQ", M32RBF_INSN_BEQ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_beqz, "BEQZ", M32RBF_INSN_BEQZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bgez, "BGEZ", M32RBF_INSN_BGEZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bgtz, "BGTZ", M32RBF_INSN_BGTZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_blez, "BLEZ", M32RBF_INSN_BLEZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bltz, "BLTZ", M32RBF_INSN_BLTZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bnez, "BNEZ", M32RBF_INSN_BNEZ, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bl8, "BL8", M32RBF_INSN_BL8, { 0|(1<<CGEN_INSN_FILL_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_bl24, "BL24", M32RBF_INSN_BL24, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bnc8, "BNC8", M32RBF_INSN_BNC8, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_bnc24, "BNC24", M32RBF_INSN_BNC24, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bne, "BNE", M32RBF_INSN_BNE, { 0|(1<<CGEN_INSN_COND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_bra8, "BRA8", M32RBF_INSN_BRA8, { 0|(1<<CGEN_INSN_FILL_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_bra24, "BRA24", M32RBF_INSN_BRA24, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_cmp, "CMP", M32RBF_INSN_CMP, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_cmpi, "CMPI", M32RBF_INSN_CMPI, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_cmpu, "CMPU", M32RBF_INSN_CMPU, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_cmpui, "CMPUI", M32RBF_INSN_CMPUI, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_div, "DIV", M32RBF_INSN_DIV, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_divu, "DIVU", M32RBF_INSN_DIVU, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_rem, "REM", M32RBF_INSN_REM, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_remu, "REMU", M32RBF_INSN_REMU, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_jl, "JL", M32RBF_INSN_JL, { 0|(1<<CGEN_INSN_FILL_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_jmp, "JMP", M32RBF_INSN_JMP, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ld, "LD", M32RBF_INSN_LD, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ld_d, "LD_D", M32RBF_INSN_LD_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_ldb, "LDB", M32RBF_INSN_LDB, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ldb_d, "LDB_D", M32RBF_INSN_LDB_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_ldh, "LDH", M32RBF_INSN_LDH, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ldh_d, "LDH_D", M32RBF_INSN_LDH_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_ldub, "LDUB", M32RBF_INSN_LDUB, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ldub_d, "LDUB_D", M32RBF_INSN_LDUB_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_lduh, "LDUH", M32RBF_INSN_LDUH, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_lduh_d, "LDUH_D", M32RBF_INSN_LDUH_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_ld_plus, "LD_PLUS", M32RBF_INSN_LD_PLUS, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_ld24, "LD24", M32RBF_INSN_LD24, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_ldi8, "LDI8", M32RBF_INSN_LDI8, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_ldi16, "LDI16", M32RBF_INSN_LDI16, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_lock, "LOCK", M32RBF_INSN_LOCK, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_machi, "MACHI", M32RBF_INSN_MACHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_maclo, "MACLO", M32RBF_INSN_MACLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_macwhi, "MACWHI", M32RBF_INSN_MACWHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_macwlo, "MACWLO", M32RBF_INSN_MACWLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mul, "MUL", M32RBF_INSN_MUL, { 0, (1<<MACH_BASE), PIPE_S } },
  { m32rbf_sem_mulhi, "MULHI", M32RBF_INSN_MULHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mullo, "MULLO", M32RBF_INSN_MULLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mulwhi, "MULWHI", M32RBF_INSN_MULWHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mulwlo, "MULWLO", M32RBF_INSN_MULWLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mv, "MV", M32RBF_INSN_MV, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_mvfachi, "MVFACHI", M32RBF_INSN_MVFACHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mvfaclo, "MVFACLO", M32RBF_INSN_MVFACLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mvfacmi, "MVFACMI", M32RBF_INSN_MVFACMI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mvfc, "MVFC", M32RBF_INSN_MVFC, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_mvtachi, "MVTACHI", M32RBF_INSN_MVTACHI, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mvtaclo, "MVTACLO", M32RBF_INSN_MVTACLO, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_mvtc, "MVTC", M32RBF_INSN_MVTC, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_neg, "NEG", M32RBF_INSN_NEG, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_nop, "NOP", M32RBF_INSN_NOP, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_not, "NOT", M32RBF_INSN_NOT, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_rac, "RAC", M32RBF_INSN_RAC, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_rach, "RACH", M32RBF_INSN_RACH, { 0, (1<<MACH_M32R), PIPE_S } },
  { m32rbf_sem_rte, "RTE", M32RBF_INSN_RTE, { 0|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_seth, "SETH", M32RBF_INSN_SETH, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_sll, "SLL", M32RBF_INSN_SLL, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_sll3, "SLL3", M32RBF_INSN_SLL3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_slli, "SLLI", M32RBF_INSN_SLLI, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_sra, "SRA", M32RBF_INSN_SRA, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_sra3, "SRA3", M32RBF_INSN_SRA3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_srai, "SRAI", M32RBF_INSN_SRAI, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_srl, "SRL", M32RBF_INSN_SRL, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_srl3, "SRL3", M32RBF_INSN_SRL3, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_srli, "SRLI", M32RBF_INSN_SRLI, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_st, "ST", M32RBF_INSN_ST, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_st_d, "ST_D", M32RBF_INSN_ST_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_stb, "STB", M32RBF_INSN_STB, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_stb_d, "STB_D", M32RBF_INSN_STB_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_sth, "STH", M32RBF_INSN_STH, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_sth_d, "STH_D", M32RBF_INSN_STH_D, { 0, (1<<MACH_BASE), PIPE_NONE } },
  { m32rbf_sem_st_plus, "ST_PLUS", M32RBF_INSN_ST_PLUS, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_st_minus, "ST_MINUS", M32RBF_INSN_ST_MINUS, { 0, (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_sub, "SUB", M32RBF_INSN_SUB, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_subv, "SUBV", M32RBF_INSN_SUBV, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_subx, "SUBX", M32RBF_INSN_SUBX, { 0, (1<<MACH_BASE), PIPE_OS } },
  { m32rbf_sem_trap, "TRAP", M32RBF_INSN_TRAP, { 0|(1<<CGEN_INSN_FILL_SLOT)|(1<<CGEN_INSN_UNCOND_CTI), (1<<MACH_BASE), PIPE_O } },
  { m32rbf_sem_unlock, "UNLOCK", M32RBF_INSN_UNLOCK, { 0, (1<<MACH_BASE), PIPE_O } },

};

// Given a canonical virtual insn id, return the target specific one.

m32rbf_insn_type
m32rbf_idesc::lookup_virtual (virtual_insn_type vit)
{
  switch (vit)
    {
      case VIRTUAL_INSN_INVALID: return M32RBF_INSN_X_INVALID;
      case VIRTUAL_INSN_COND: return M32RBF_INSN_X_INVALID;
    }
  abort ();
}


// Declare extractor functions

static void
m32rbf_extract_sfmt_empty (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_add (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_add3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_and3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_or3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_addi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_addv (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_addv3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_addx (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bc8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bc24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_beq (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_beqz (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bl8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bl24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bra8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_bra24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_cmp (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_cmpi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_div (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_jl (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_jmp (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ld (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ld_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldb (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldb_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldh (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldh_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ld_plus (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ld24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldi8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_ldi16 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_lock (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_machi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mulhi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mv (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mvfachi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mvfc (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mvtachi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_mvtc (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_nop (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_rac (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_rte (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_seth (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_sll3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_slli (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_st (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_st_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_stb (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_stb_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_sth (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_sth_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_st_plus (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_trap (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);
static void
m32rbf_extract_sfmt_unlock (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn);

// Fetch & decode instruction
void
m32rbf_scache::decode (m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn)
{
  /* Result of decoder.  */
  M32RBF_INSN_TYPE itype;

  {
    m32rbf_insn_word insn = base_insn;

    {
      unsigned int val = (((insn >> 24) & (15 << 4)) | ((insn >> 20) & (15 << 0)));
      switch (val)
      {
      case 0 : itype = M32RBF_INSN_SUBV; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_addv (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 1 : itype = M32RBF_INSN_SUBX; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_addx (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 2 : itype = M32RBF_INSN_SUB; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 3 : itype = M32RBF_INSN_NEG; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mv (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 4 : itype = M32RBF_INSN_CMP; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_cmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 5 : itype = M32RBF_INSN_CMPU; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_cmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 8 : itype = M32RBF_INSN_ADDV; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_addv (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 9 : itype = M32RBF_INSN_ADDX; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_addx (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 10 : itype = M32RBF_INSN_ADD; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 11 : itype = M32RBF_INSN_NOT; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mv (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 12 : itype = M32RBF_INSN_AND; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 13 : itype = M32RBF_INSN_XOR; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 14 : itype = M32RBF_INSN_OR; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 16 : itype = M32RBF_INSN_SRL; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 18 : itype = M32RBF_INSN_SRA; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 20 : itype = M32RBF_INSN_SLL; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 22 : itype = M32RBF_INSN_MUL; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_add (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 24 : itype = M32RBF_INSN_MV; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mv (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 25 : itype = M32RBF_INSN_MVFC; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvfc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 26 : itype = M32RBF_INSN_MVTC; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvtc (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 28 :
        {
          unsigned int val = (((insn >> 24) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_JL; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_jl (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = M32RBF_INSN_JMP; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_jmp (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 29 : itype = M32RBF_INSN_RTE; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_rte (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 31 : itype = M32RBF_INSN_TRAP; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_trap (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 32 : itype = M32RBF_INSN_STB; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_stb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 34 : itype = M32RBF_INSN_STH; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_sth (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 36 : itype = M32RBF_INSN_ST; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_st (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 37 : itype = M32RBF_INSN_UNLOCK; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_unlock (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 38 : itype = M32RBF_INSN_ST_PLUS; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_st_plus (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 39 : itype = M32RBF_INSN_ST_MINUS; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_st_plus (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 40 : itype = M32RBF_INSN_LDB; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ldb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 41 : itype = M32RBF_INSN_LDUB; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ldb (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 42 : itype = M32RBF_INSN_LDH; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ldh (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 43 : itype = M32RBF_INSN_LDUH; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ldh (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 44 : itype = M32RBF_INSN_LD; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ld (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 45 : itype = M32RBF_INSN_LOCK; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_lock (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 46 : itype = M32RBF_INSN_LD_PLUS; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ld_plus (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 48 : itype = M32RBF_INSN_MULHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mulhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 49 : itype = M32RBF_INSN_MULLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mulhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 50 : itype = M32RBF_INSN_MULWHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mulhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 51 : itype = M32RBF_INSN_MULWLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mulhi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 52 : itype = M32RBF_INSN_MACHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_machi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 53 : itype = M32RBF_INSN_MACLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_machi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 54 : itype = M32RBF_INSN_MACWHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_machi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 55 : itype = M32RBF_INSN_MACWLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_machi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 64 : /* fall through */
      case 65 : /* fall through */
      case 66 : /* fall through */
      case 67 : /* fall through */
      case 68 : /* fall through */
      case 69 : /* fall through */
      case 70 : /* fall through */
      case 71 : /* fall through */
      case 72 : /* fall through */
      case 73 : /* fall through */
      case 74 : /* fall through */
      case 75 : /* fall through */
      case 76 : /* fall through */
      case 77 : /* fall through */
      case 78 : /* fall through */
      case 79 : itype = M32RBF_INSN_ADDI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_addi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 80 : /* fall through */
      case 81 : itype = M32RBF_INSN_SRLI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_slli (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 82 : /* fall through */
      case 83 : itype = M32RBF_INSN_SRAI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_slli (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 84 : /* fall through */
      case 85 : itype = M32RBF_INSN_SLLI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_slli (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 87 :
        {
          unsigned int val = (((insn >> 16) & (1 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_MVTACHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvtachi (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = M32RBF_INSN_MVTACLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvtachi (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 88 : itype = M32RBF_INSN_RACH; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_rac (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 89 : itype = M32RBF_INSN_RAC; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_rac (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 95 :
        {
          unsigned int val = (((insn >> 16) & (3 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_MVFACHI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvfachi (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = M32RBF_INSN_MVFACLO; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvfachi (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = M32RBF_INSN_MVFACMI; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_mvfachi (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 96 : /* fall through */
      case 97 : /* fall through */
      case 98 : /* fall through */
      case 99 : /* fall through */
      case 100 : /* fall through */
      case 101 : /* fall through */
      case 102 : /* fall through */
      case 103 : /* fall through */
      case 104 : /* fall through */
      case 105 : /* fall through */
      case 106 : /* fall through */
      case 107 : /* fall through */
      case 108 : /* fall through */
      case 109 : /* fall through */
      case 110 : /* fall through */
      case 111 : itype = M32RBF_INSN_LDI8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_ldi8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 112 :
        {
          unsigned int val = (((insn >> 24) & (15 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_NOP; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_nop (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 12 : itype = M32RBF_INSN_BC8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bc8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 13 : itype = M32RBF_INSN_BNC8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bc8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 14 : itype = M32RBF_INSN_BL8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bl8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 15 : itype = M32RBF_INSN_BRA8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bra8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 113 : /* fall through */
      case 114 : /* fall through */
      case 115 : /* fall through */
      case 116 : /* fall through */
      case 117 : /* fall through */
      case 118 : /* fall through */
      case 119 : /* fall through */
      case 120 : /* fall through */
      case 121 : /* fall through */
      case 122 : /* fall through */
      case 123 : /* fall through */
      case 124 : /* fall through */
      case 125 : /* fall through */
      case 126 : /* fall through */
      case 127 :
        {
          unsigned int val = (((insn >> 24) & (3 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_BC8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bc8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = M32RBF_INSN_BNC8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bc8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = M32RBF_INSN_BL8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bl8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = M32RBF_INSN_BRA8; entire_insn = base_insn >> 16; m32rbf_extract_sfmt_bra8 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      case 132 : itype = M32RBF_INSN_CMPI; m32rbf_extract_sfmt_cmpi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 133 : itype = M32RBF_INSN_CMPUI; m32rbf_extract_sfmt_cmpi (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 136 : itype = M32RBF_INSN_ADDV3; m32rbf_extract_sfmt_addv3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 138 : itype = M32RBF_INSN_ADD3; m32rbf_extract_sfmt_add3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 140 : itype = M32RBF_INSN_AND3; m32rbf_extract_sfmt_and3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 141 : itype = M32RBF_INSN_XOR3; m32rbf_extract_sfmt_and3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 142 : itype = M32RBF_INSN_OR3; m32rbf_extract_sfmt_or3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 144 : itype = M32RBF_INSN_DIV; m32rbf_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 145 : itype = M32RBF_INSN_DIVU; m32rbf_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 146 : itype = M32RBF_INSN_REM; m32rbf_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 147 : itype = M32RBF_INSN_REMU; m32rbf_extract_sfmt_div (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 152 : itype = M32RBF_INSN_SRL3; m32rbf_extract_sfmt_sll3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 154 : itype = M32RBF_INSN_SRA3; m32rbf_extract_sfmt_sll3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 156 : itype = M32RBF_INSN_SLL3; m32rbf_extract_sfmt_sll3 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 159 : itype = M32RBF_INSN_LDI16; m32rbf_extract_sfmt_ldi16 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 160 : itype = M32RBF_INSN_STB_D; m32rbf_extract_sfmt_stb_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 162 : itype = M32RBF_INSN_STH_D; m32rbf_extract_sfmt_sth_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 164 : itype = M32RBF_INSN_ST_D; m32rbf_extract_sfmt_st_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 168 : itype = M32RBF_INSN_LDB_D; m32rbf_extract_sfmt_ldb_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 169 : itype = M32RBF_INSN_LDUB_D; m32rbf_extract_sfmt_ldb_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 170 : itype = M32RBF_INSN_LDH_D; m32rbf_extract_sfmt_ldh_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 171 : itype = M32RBF_INSN_LDUH_D; m32rbf_extract_sfmt_ldh_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 172 : itype = M32RBF_INSN_LD_D; m32rbf_extract_sfmt_ld_d (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 176 : itype = M32RBF_INSN_BEQ; m32rbf_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 177 : itype = M32RBF_INSN_BNE; m32rbf_extract_sfmt_beq (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 184 : itype = M32RBF_INSN_BEQZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 185 : itype = M32RBF_INSN_BNEZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 186 : itype = M32RBF_INSN_BLTZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 187 : itype = M32RBF_INSN_BGEZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 188 : itype = M32RBF_INSN_BLEZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 189 : itype = M32RBF_INSN_BGTZ; m32rbf_extract_sfmt_beqz (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 220 : itype = M32RBF_INSN_SETH; m32rbf_extract_sfmt_seth (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 224 : /* fall through */
      case 225 : /* fall through */
      case 226 : /* fall through */
      case 227 : /* fall through */
      case 228 : /* fall through */
      case 229 : /* fall through */
      case 230 : /* fall through */
      case 231 : /* fall through */
      case 232 : /* fall through */
      case 233 : /* fall through */
      case 234 : /* fall through */
      case 235 : /* fall through */
      case 236 : /* fall through */
      case 237 : /* fall through */
      case 238 : /* fall through */
      case 239 : itype = M32RBF_INSN_LD24; m32rbf_extract_sfmt_ld24 (this, current_cpu, pc, base_insn, entire_insn); goto done;
      case 240 : /* fall through */
      case 241 : /* fall through */
      case 242 : /* fall through */
      case 243 : /* fall through */
      case 244 : /* fall through */
      case 245 : /* fall through */
      case 246 : /* fall through */
      case 247 : /* fall through */
      case 248 : /* fall through */
      case 249 : /* fall through */
      case 250 : /* fall through */
      case 251 : /* fall through */
      case 252 : /* fall through */
      case 253 : /* fall through */
      case 254 : /* fall through */
      case 255 :
        {
          unsigned int val = (((insn >> 24) & (3 << 0)));
          switch (val)
          {
          case 0 : itype = M32RBF_INSN_BC24; m32rbf_extract_sfmt_bc24 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 1 : itype = M32RBF_INSN_BNC24; m32rbf_extract_sfmt_bc24 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 2 : itype = M32RBF_INSN_BL24; m32rbf_extract_sfmt_bl24 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          case 3 : itype = M32RBF_INSN_BRA24; m32rbf_extract_sfmt_bra24 (this, current_cpu, pc, base_insn, entire_insn); goto done;
          default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
          }
        }
      default : itype = M32RBF_INSN_X_INVALID; m32rbf_extract_sfmt_empty (this, current_cpu, pc, base_insn, entire_insn);  goto done;
      }
    }

  }

  /* The instruction has been decoded and fields extracted.  */
  done:

  this->addr = pc;
  // FIXME: To be redone (to handle ISA variants).
  this->idesc = & m32rbf_idesc::idesc_table[itype];
  // ??? record semantic handler?
  assert(this->idesc->sem_index == itype);
}

void
m32rbf_extract_sfmt_empty (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_empty)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_add (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_add3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_add3)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_and3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;
    UINT f_uimm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_uimm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_uimm16) = f_uimm16;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_and3)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_uimm16:0x" << hex << f_uimm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_or3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;
    UINT f_uimm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_uimm16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_uimm16) = f_uimm16;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_or3)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_uimm16:0x" << hex << f_uimm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_addi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_r1;
    INT f_simm8;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_simm8 = EXTRACT_MSB0_INT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_simm8) = f_simm8;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addi)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_simm8:0x" << hex << f_simm8 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_addv (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addv)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_addv3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addv3)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_addx (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_addx)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bc8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc8.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 8)) << (2))) + (((pc) & (-4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp8) = f_disp8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bc8)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bc24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc24.f
    SI f_disp24;

    f_disp24 = ((((EXTRACT_MSB0_INT (insn, 32, 8, 24)) << (2))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp24) = f_disp24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bc24)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_beq (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    UINT f_r1;
    UINT f_r2;
    SI f_disp16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_disp16 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (2))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_disp16) = f_disp16;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beq)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_beqz (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_beq.f
    UINT f_r2;
    SI f_disp16;

    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_disp16 = ((((EXTRACT_MSB0_INT (insn, 32, 16, 16)) << (2))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (i_disp16) = f_disp16;
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_beqz)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bl8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc8.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 8)) << (2))) + (((pc) & (-4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp8) = f_disp8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bl8)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bl24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc24.f
    SI f_disp24;

    f_disp24 = ((((EXTRACT_MSB0_INT (insn, 32, 8, 24)) << (2))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp24) = f_disp24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bl24)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bra8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc8.f
    SI f_disp8;

    f_disp8 = ((((EXTRACT_MSB0_INT (insn, 16, 8, 8)) << (2))) + (((pc) & (-4))));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp8) = f_disp8;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bra8)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_bra24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_bc24.f
    SI f_disp24;

    f_disp24 = ((((EXTRACT_MSB0_INT (insn, 32, 8, 24)) << (2))) + (pc));

  /* Record the fields for the semantic handler.  */
  FLD (i_disp24) = f_disp24;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_bra24)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_cmp (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmp)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_cmpi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r2;
    INT f_simm16;

    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_cmpi)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_div (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_div)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_jl (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r2;

    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jl)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_jmp (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r2;

    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_jmp)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ld (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ld)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ld_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ld_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldb (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldb)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldb_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldb_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldh (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldh)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldh_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldh_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ld_plus (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ld_plus)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ld24 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_ld24.f
    UINT f_r1;
    UINT f_uimm24;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_uimm24 = EXTRACT_MSB0_UINT (insn, 32, 8, 24);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (i_uimm24) = f_uimm24;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ld24)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldi8 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_addi.f
    UINT f_r1;
    INT f_simm8;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_simm8 = EXTRACT_MSB0_INT (insn, 16, 8, 8);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm8) = f_simm8;
  FLD (f_r1) = f_r1;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldi8)\t"
        << " f_simm8:0x" << hex << f_simm8 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_ldi16 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r1) = f_r1;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_ldi16)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_lock (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_lock)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_machi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_machi)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mulhi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mulhi)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mv (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mv)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mvfachi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_slli.f
    UINT f_r1;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mvfachi)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mvfc (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mvfc)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mvtachi (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mvtachi)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_mvtc (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_and3.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_mvtc)\t"
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_nop (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_nop)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_rac (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_rac)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_rte (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.fmt_empty.f


  /* Record the fields for the semantic handler.  */
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_rte)\t"
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_seth (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_seth.f
    UINT f_r1;
    UINT f_hi16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_hi16 = EXTRACT_MSB0_UINT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_hi16) = f_hi16;
  FLD (f_r1) = f_r1;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_seth)\t"
        << " f_hi16:0x" << hex << f_hi16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_sll3 (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_add3.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r2) = f_r2;
  FLD (f_r1) = f_r1;
  FLD (i_sr) = & current_cpu->hardware.h_gr[f_r2];
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sll3)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_slli (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_slli.f
    UINT f_r1;
    UINT f_uimm5;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_uimm5 = EXTRACT_MSB0_UINT (insn, 16, 11, 5);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_uimm5) = f_uimm5;
  FLD (i_dr) = & current_cpu->hardware.h_gr[f_r1];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_slli)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_uimm5:0x" << hex << f_uimm5 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_st (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_st)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_st_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_st_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_stb (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stb)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_stb_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_stb_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_sth (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sth)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_sth_d (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;
    INT f_simm16;

    f_r1 = EXTRACT_MSB0_UINT (insn, 32, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 32, 12, 4);
    f_simm16 = EXTRACT_MSB0_INT (insn, 32, 16, 16);

  /* Record the fields for the semantic handler.  */
  FLD (f_simm16) = f_simm16;
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_sth_d)\t"
        << " f_simm16:0x" << hex << f_simm16 << dec
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_st_plus (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_st_plus)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_trap (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_trap.f
    UINT f_uimm4;

    f_uimm4 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_uimm4) = f_uimm4;
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_trap)\t"
        << " f_uimm4:0x" << hex << f_uimm4 << dec
        << endl;
    }

#undef FLD
}

void
m32rbf_extract_sfmt_unlock (m32rbf_scache* abuf, m32rbf_cpu* current_cpu, PCADDR pc, m32rbf_insn_word base_insn, m32rbf_insn_word entire_insn){
    m32rbf_insn_word insn = entire_insn;
#define FLD(f) abuf->fields.sfmt_st_d.f
    UINT f_r1;
    UINT f_r2;

    f_r1 = EXTRACT_MSB0_UINT (insn, 16, 4, 4);
    f_r2 = EXTRACT_MSB0_UINT (insn, 16, 12, 4);

  /* Record the fields for the semantic handler.  */
  FLD (f_r1) = f_r1;
  FLD (f_r2) = f_r2;
  FLD (i_src1) = & current_cpu->hardware.h_gr[f_r1];
  FLD (i_src2) = & current_cpu->hardware.h_gr[f_r2];
  if (UNLIKELY(current_cpu->trace_extract_p))
    {
      current_cpu->trace_stream 
        << "0x" << hex << pc << dec << " (sfmt_unlock)\t"
        << " f_r1:0x" << hex << f_r1 << dec
        << " f_r2:0x" << hex << f_r2 << dec
        << endl;
    }

#undef FLD
}

