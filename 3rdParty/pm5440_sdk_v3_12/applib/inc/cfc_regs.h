/******************************************************************************
 *   COPYRIGHT (C) 2011 PMC-SIERRA, INC. ALL RIGHTS RESERVED.
 * --------------------------------------------------------------------------
 *  This software embodies materials and concepts which are proprietary and
 *  confidential to PMC-Sierra, Inc.
 *  PMC-Sierra distributes this software to its customers pursuant to the
 *  terms and conditions of the Software License Agreement
 *  contained in the text file software.lic that is distributed along with
 *  the software. This software can only be utilized if all
 *  terms and conditions of the Software License Agreement are
 *  accepted. If there are any questions, concerns, or if the
 *  Software License Agreement text file, software.lic, is missing please
 *  contact PMC-Sierra for assistance.
 * -------------------------------------------------------------------------
 *   DESCRIPTION:
 *     Contains all register offset and register bit definitions for the
 *     cfc block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml/lw20_15_99_generic_reg.xml
 *     block_uri "file:../docs/rda/lw20_15_99_reg.xml"
 *     block_part_number "LW20_15_99"
 *     block_mnemonic "CFC"
 * 
 *****************************************************************************/
#ifndef _CFC_REGS_H
#define _CFC_REGS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*--------------------.
 | register addresses |
 +-------------------*/
#define PMC_CFC_REG_FIFO_CLRB_0               0x00000000
#define PMC_CFC_REG_FIFO_CLRB_1               0x00000004
#define PMC_CFC_REG_FIFO_CLRB_2               0x00000008
#define PMC_CFC_REG_FIFO_CLRB_3               0x00000010
#define PMC_CFC_REG_FIFO_IPT_BYPASS           0x00000080
#define PMC_CFC_REG_FIFO_IPT_MASK_CFC         0x00000084
#define PMC_CFC_REG_FIFO_CFG                  0x000000a0
#define PMC_CFC_REG_FIFO_CFG_STAT             0x000000a4
#define PMC_CFC_REG_FIFO_CFG_VAL              0x000000a8
#define PMC_CFC_REG_DBG_CTRL                  0x00000100
#define PMC_CFC_REG_DBG_RDATA                 0x00000104
#define PMC_CFC_REG_FIFO_OVR_INT_REG_0        0x00000200
#define PMC_CFC_REG_FIFO_OVR_INT_REG_1        0x00000204
#define PMC_CFC_REG_FIFO_OVR_INT_REG_2        0x00000208
#define PMC_CFC_REG_FIFO_OVR_INT_REG_3        0x0000020c
#define PMC_CFC_REG_FIFO_UDR_INT_REG_0        0x00000220
#define PMC_CFC_REG_FIFO_UDR_INT_REG_1        0x00000224
#define PMC_CFC_REG_FIFO_UDR_INT_REG_2        0x00000228
#define PMC_CFC_REG_FIFO_UDR_INT_REG_3        0x0000022c
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_0    0x00000240
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_1    0x00000244
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_2    0x00000248
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_3    0x0000024c
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_0     0x00000280
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_1     0x00000284
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_2     0x00000288
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_3     0x0000028c
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_0     0x000002a0
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_1     0x000002a4
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_2     0x000002a8
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_3     0x000002ac
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_0 0x000002c0
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_1 0x000002c4
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_2 0x000002c8
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_3 0x000002cc
#define PMC_CFC_REG_FIFO_IPT( N )             (0x00000400 + (N) * 0x04)
#define PMC_CFC_REG_FIFO_STAT( N )            (0x00000800 + (N) * 0x4)

/*---------------------------------.
 | Register 0x00000000 FIFO_CLRB_0 |
 +---------------------------------+
 | bit  31:0 R/W  FIFO_CLRB        |
 +--------------------------------*/
#define PMC_CFC_REG_FIFO_CLRB_0_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_CLRB_0_BIT_FIFO_CLRB_MSK 0xffffffff
#define CFC_REG_FIFO_CLRB_0_BIT_FIFO_CLRB_OFF 0

/*---------------------------------.
 | Register 0x00000004 FIFO_CLRB_1 |
 +---------------------------------+
 | bit  31:0 R/W  FIFO_CLRB        |
 +--------------------------------*/
#define PMC_CFC_REG_FIFO_CLRB_1_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_CLRB_1_BIT_FIFO_CLRB_MSK 0xffffffff
#define CFC_REG_FIFO_CLRB_1_BIT_FIFO_CLRB_OFF 0

/*---------------------------------.
 | Register 0x00000008 FIFO_CLRB_2 |
 +---------------------------------+
 | bit  31:0 R/W  FIFO_CLRB        |
 +--------------------------------*/
#define PMC_CFC_REG_FIFO_CLRB_2_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_CLRB_2_BIT_FIFO_CLRB_MSK 0xffffffff
#define CFC_REG_FIFO_CLRB_2_BIT_FIFO_CLRB_OFF 0

/*---------------------------------.
 | Register 0x00000010 FIFO_CLRB_3 |
 +---------------------------------+
 | bit  31:0 R/W  FIFO_CLRB        |
 +--------------------------------*/
#define PMC_CFC_REG_FIFO_CLRB_3_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_CLRB_3_BIT_FIFO_CLRB_MSK 0xffffffff
#define CFC_REG_FIFO_CLRB_3_BIT_FIFO_CLRB_OFF 0

/*-------------------------------------.
 | Register 0x00000080 FIFO_IPT_BYPASS |
 +-------------------------------------+
 | bit  16 R/W  IPT_BYPASS             |
 +------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_BYPASS_UNUSED_MASK    0xfffeffff
#define CFC_REG_FIFO_IPT_BYPASS_BIT_IPT_BYPASS_MSK 0x00010000
#define CFC_REG_FIFO_IPT_BYPASS_BIT_IPT_BYPASS_OFF 16

/*---------------------------------------.
 | Register 0x00000084 FIFO_IPT_MASK_CFC |
 +---------------------------------------+
 | bit  15:0 R/W  IPT_PAGE_MASK          |
 +--------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_MASK_CFC_UNUSED_MASK       0xffff0000
#define CFC_REG_FIFO_IPT_MASK_CFC_BIT_IPT_PAGE_MASK_MSK 0x0000ffff
#define CFC_REG_FIFO_IPT_MASK_CFC_BIT_IPT_PAGE_MASK_OFF 0

/*-----------------------------------------.
 | Register 0x000000a0 FIFO_CFG            |
 +-----------------------------------------+
 | bit  28    R/W  FIFO_END_ADDR_CHG_ABORT |
 | bit  24    R/W  FIFO_END_ADDR_CHG_REQ   |
 | bit  22:16 R/W  FIFO_END_ADDR_CHG_ID    |
 +----------------------------------------*/
#define PMC_CFC_REG_FIFO_CFG_UNUSED_MASK                 0xee80ffff
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ABORT_MSK 0x10000000
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ABORT_OFF 28
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_REQ_MSK   0x01000000
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_REQ_OFF   24
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ID_MSK    0x007f0000
#define CFC_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ID_OFF    16

/*-------------------------------------.
 | Register 0x000000a4 FIFO_CFG_STAT   |
 +-------------------------------------+
 | bit  0 R  FIFO_END_ADDR_CHG_SUCCESS |
 +------------------------------------*/
#define PMC_CFC_REG_FIFO_CFG_STAT_UNUSED_MASK                   0xfffffffe
#define CFC_REG_FIFO_CFG_STAT_BIT_FIFO_END_ADDR_CHG_SUCCESS_MSK 0x00000001
#define CFC_REG_FIFO_CFG_STAT_BIT_FIFO_END_ADDR_CHG_SUCCESS_OFF 0

/*----------------------------------.
 | Register 0x000000a8 FIFO_CFG_VAL |
 +----------------------------------+
 | bit  15:0 R/W  FIFO_END_ADDR     |
 +---------------------------------*/
#define PMC_CFC_REG_FIFO_CFG_VAL_UNUSED_MASK       0xffff0000
#define CFC_REG_FIFO_CFG_VAL_BIT_FIFO_END_ADDR_MSK 0x0000ffff
#define CFC_REG_FIFO_CFG_VAL_BIT_FIFO_END_ADDR_OFF 0

/*------------------------------.
 | Register 0x00000100 DBG_CTRL |
 +------------------------------+
 | bit  16   R/W  DBG_TRIG      |
 | bit  10:0 R/W  DBG_RADDR     |
 +-----------------------------*/
#define PMC_CFC_REG_DBG_CTRL_UNUSED_MASK   0xfffef800
#define CFC_REG_DBG_CTRL_BIT_DBG_TRIG_MSK  0x00010000
#define CFC_REG_DBG_CTRL_BIT_DBG_TRIG_OFF  16
#define CFC_REG_DBG_CTRL_BIT_DBG_RADDR_MSK 0x000007ff
#define CFC_REG_DBG_CTRL_BIT_DBG_RADDR_OFF 0

/*-------------------------------.
 | Register 0x00000104 DBG_RDATA |
 +-------------------------------+
 | bit  31:0 R  DBG_RDATA        |
 +------------------------------*/
#define PMC_CFC_REG_DBG_RDATA_UNUSED_MASK   0x00000000
#define CFC_REG_DBG_RDATA_BIT_DBG_RDATA_MSK 0xffffffff
#define CFC_REG_DBG_RDATA_BIT_DBG_RDATA_OFF 0

/*----------------------------------------.
 | Register 0x00000200 FIFO_OVR_INT_REG_0 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_REG_0_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_REG_0_BIT_FIFO_OVR_I_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_REG_0_BIT_FIFO_OVR_I_OFF 0

/*----------------------------------------.
 | Register 0x00000204 FIFO_OVR_INT_REG_1 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_REG_1_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_REG_1_BIT_FIFO_OVR_I_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_REG_1_BIT_FIFO_OVR_I_OFF 0

/*----------------------------------------.
 | Register 0x00000208 FIFO_OVR_INT_REG_2 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_REG_2_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_REG_2_BIT_FIFO_OVR_I_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_REG_2_BIT_FIFO_OVR_I_OFF 0

/*----------------------------------------.
 | Register 0x0000020c FIFO_OVR_INT_REG_3 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_REG_3_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_REG_3_BIT_FIFO_OVR_I_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_REG_3_BIT_FIFO_OVR_I_OFF 0

/*----------------------------------------.
 | Register 0x00000220 FIFO_UDR_INT_REG_0 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_REG_0_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_REG_0_BIT_FIFO_UDR_I_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_REG_0_BIT_FIFO_UDR_I_OFF 0

/*----------------------------------------.
 | Register 0x00000224 FIFO_UDR_INT_REG_1 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_REG_1_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_REG_1_BIT_FIFO_UDR_I_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_REG_1_BIT_FIFO_UDR_I_OFF 0

/*----------------------------------------.
 | Register 0x00000228 FIFO_UDR_INT_REG_2 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_REG_2_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_REG_2_BIT_FIFO_UDR_I_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_REG_2_BIT_FIFO_UDR_I_OFF 0

/*----------------------------------------.
 | Register 0x0000022c FIFO_UDR_INT_REG_3 |
 +----------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_I              |
 +---------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_REG_3_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_REG_3_BIT_FIFO_UDR_I_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_REG_3_BIT_FIFO_UDR_I_OFF 0

/*--------------------------------------------.
 | Register 0x00000240 FIFO_IPT_ERR_INT_REG_0 |
 +--------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_I                   |
 +-------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_0_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_REG_0_BIT_IPT_ERR_I_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_REG_0_BIT_IPT_ERR_I_OFF 0

/*--------------------------------------------.
 | Register 0x00000244 FIFO_IPT_ERR_INT_REG_1 |
 +--------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_I                   |
 +-------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_1_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_REG_1_BIT_IPT_ERR_I_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_REG_1_BIT_IPT_ERR_I_OFF 0

/*--------------------------------------------.
 | Register 0x00000248 FIFO_IPT_ERR_INT_REG_2 |
 +--------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_I                   |
 +-------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_2_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_REG_2_BIT_IPT_ERR_I_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_REG_2_BIT_IPT_ERR_I_OFF 0

/*--------------------------------------------.
 | Register 0x0000024c FIFO_IPT_ERR_INT_REG_3 |
 +--------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_I                   |
 +-------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_REG_3_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_REG_3_BIT_IPT_ERR_I_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_REG_3_BIT_IPT_ERR_I_OFF 0

/*-------------------------------------------.
 | Register 0x00000280 FIFO_OVR_INT_EN_REG_0 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_0_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_EN_REG_0_BIT_FIFO_OVR_E_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_EN_REG_0_BIT_FIFO_OVR_E_OFF 0

/*-------------------------------------------.
 | Register 0x00000284 FIFO_OVR_INT_EN_REG_1 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_1_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_EN_REG_1_BIT_FIFO_OVR_E_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_EN_REG_1_BIT_FIFO_OVR_E_OFF 0

/*-------------------------------------------.
 | Register 0x00000288 FIFO_OVR_INT_EN_REG_2 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_2_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_EN_REG_2_BIT_FIFO_OVR_E_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_EN_REG_2_BIT_FIFO_OVR_E_OFF 0

/*-------------------------------------------.
 | Register 0x0000028c FIFO_OVR_INT_EN_REG_3 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_OVR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_OVR_INT_EN_REG_3_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_OVR_INT_EN_REG_3_BIT_FIFO_OVR_E_MSK 0xffffffff
#define CFC_REG_FIFO_OVR_INT_EN_REG_3_BIT_FIFO_OVR_E_OFF 0

/*-------------------------------------------.
 | Register 0x000002a0 FIFO_UDR_INT_EN_REG_0 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_0_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_EN_REG_0_BIT_FIFO_UDR_E_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_EN_REG_0_BIT_FIFO_UDR_E_OFF 0

/*-------------------------------------------.
 | Register 0x000002a4 FIFO_UDR_INT_EN_REG_1 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_1_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_EN_REG_1_BIT_FIFO_UDR_E_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_EN_REG_1_BIT_FIFO_UDR_E_OFF 0

/*-------------------------------------------.
 | Register 0x000002a8 FIFO_UDR_INT_EN_REG_2 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_2_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_EN_REG_2_BIT_FIFO_UDR_E_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_EN_REG_2_BIT_FIFO_UDR_E_OFF 0

/*-------------------------------------------.
 | Register 0x000002ac FIFO_UDR_INT_EN_REG_3 |
 +-------------------------------------------+
 | bit  31:0 R/W  FIFO_UDR_E                 |
 +------------------------------------------*/
#define PMC_CFC_REG_FIFO_UDR_INT_EN_REG_3_UNUSED_MASK    0x00000000
#define CFC_REG_FIFO_UDR_INT_EN_REG_3_BIT_FIFO_UDR_E_MSK 0xffffffff
#define CFC_REG_FIFO_UDR_INT_EN_REG_3_BIT_FIFO_UDR_E_OFF 0

/*-----------------------------------------------.
 | Register 0x000002c0 FIFO_IPT_ERR_INT_EN_REG_0 |
 +-----------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_E                      |
 +----------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_0_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_0_BIT_IPT_ERR_E_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_0_BIT_IPT_ERR_E_OFF 0

/*-----------------------------------------------.
 | Register 0x000002c4 FIFO_IPT_ERR_INT_EN_REG_1 |
 +-----------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_E                      |
 +----------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_1_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_1_BIT_IPT_ERR_E_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_1_BIT_IPT_ERR_E_OFF 0

/*-----------------------------------------------.
 | Register 0x000002c8 FIFO_IPT_ERR_INT_EN_REG_2 |
 +-----------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_E                      |
 +----------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_2_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_2_BIT_IPT_ERR_E_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_2_BIT_IPT_ERR_E_OFF 0

/*-----------------------------------------------.
 | Register 0x000002cc FIFO_IPT_ERR_INT_EN_REG_3 |
 +-----------------------------------------------+
 | bit  31:0 R/W  IPT_ERR_E                      |
 +----------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_ERR_INT_EN_REG_3_UNUSED_MASK   0x00000000
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_3_BIT_IPT_ERR_E_MSK 0xffffffff
#define CFC_REG_FIFO_IPT_ERR_INT_EN_REG_3_BIT_IPT_ERR_E_OFF 0

/* index definitions for PMC_CFC_REG_FIFO_IPT */
#define PMC_CFC_REG_FIFO_IPT_INDEX_N_MIN    0
#define PMC_CFC_REG_FIFO_IPT_INDEX_N_MAX    127
#define PMC_CFC_REG_FIFO_IPT_INDEX_N_SIZE   128
#define PMC_CFC_REG_FIFO_IPT_INDEX_N_OFFSET 0x04

/*---------------------------------------------.
 | Register (0x00000400 + (N) * 0x04) FIFO_IPT |
 +---------------------------------------------+
 | bit  24    R/W  IPT_VALID                   |
 | bit  22:16 R/W  IPT_ID                      |
 | bit  6:0   R/W  IPT_VA                      |
 +--------------------------------------------*/
#define PMC_CFC_REG_FIFO_IPT_UNUSED_MASK    0xfe80ff80
#define CFC_REG_FIFO_IPT_BIT_IPT_VALID_MSK  0x01000000
#define CFC_REG_FIFO_IPT_BIT_IPT_VALID_OFF  24
#define CFC_REG_FIFO_IPT_BIT_IPT_ID_MSK     0x007f0000
#define CFC_REG_FIFO_IPT_BIT_IPT_ID_OFF     16
#define CFC_REG_FIFO_IPT_BIT_IPT_VA_MSK     0x0000007f
#define CFC_REG_FIFO_IPT_BIT_IPT_VA_OFF     0

/* index definitions for PMC_CFC_REG_FIFO_STAT */
#define PMC_CFC_REG_FIFO_STAT_INDEX_N_MIN    0
#define PMC_CFC_REG_FIFO_STAT_INDEX_N_MAX    127
#define PMC_CFC_REG_FIFO_STAT_INDEX_N_SIZE   128
#define PMC_CFC_REG_FIFO_STAT_INDEX_N_OFFSET 0x4

/*---------------------------------------------.
 | Register (0x00000800 + (N) * 0x4) FIFO_STAT |
 +---------------------------------------------+
 | bit  8 R  FIFO_EMPTY                        |
 | bit  0 R  FIFO_FULL                         |
 +--------------------------------------------*/
#define PMC_CFC_REG_FIFO_STAT_UNUSED_MASK    0xfffffefe
#define CFC_REG_FIFO_STAT_BIT_FIFO_EMPTY_MSK 0x00000100
#define CFC_REG_FIFO_STAT_BIT_FIFO_EMPTY_OFF 8
#define CFC_REG_FIFO_STAT_BIT_FIFO_FULL_MSK  0x00000001
#define CFC_REG_FIFO_STAT_BIT_FIFO_FULL_OFF  0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CFC_REGS_H */
