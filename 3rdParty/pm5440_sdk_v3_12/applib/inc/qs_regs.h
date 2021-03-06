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
 *     qs block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm70_82_12_dcpb_map.xml
 *     block_uri "file:../docs/rda/pm70_60_59_qs_reg.xml"
 *     block_part_number "PM70_60_59_qs"
 *     block_mnemonic "QS"
 * 
 *****************************************************************************/
#ifndef _QS_REGS_H
#define _QS_REGS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*--------------------.
 | register addresses |
 +-------------------*/
#define PMC_QS_REG_PUSH_PORT_P0_RST( N )     (0x000a0000 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL( N ) (0x000a0400 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P1_RST( N )     (0x000a0800 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL( N ) (0x000a0c00 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P2_RST( N )     (0x000a1000 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL( N ) (0x000a1400 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P3_RST( N )     (0x000a1800 + (N) * 0x4)
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL( N ) (0x000a1c00 + (N) * 0x4)
#define PMC_QS_REG_POP_PORT_RST( N )         (0x000a2000 + (N) * 0x4)
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG( N ) (0x000a2400 + (N) * 0x4)
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG( N )   (0x000a2600 + (N) * 0x4)
#define PMC_QS_REG_FIFO_CFG                  0x000a3d00
#define PMC_QS_REG_FIFO_CFG_RID              0x000a3d04
#define PMC_QS_REG_FIFO_CFG_WID              0x000a3d08
#define PMC_QS_REG_FIFO_CFG_STAT             0x000a3d0c
#define PMC_QS_REG_DBG_CTRL                  0x000a3e00

/* index definitions for PMC_QS_REG_PUSH_PORT_P0_RST */
#define PMC_QS_REG_PUSH_PORT_P0_RST_INDEX_N_MIN          0
#define PMC_QS_REG_PUSH_PORT_P0_RST_INDEX_N_MAX          255
#define PMC_QS_REG_PUSH_PORT_P0_RST_INDEX_N_SIZE         256
#define PMC_QS_REG_PUSH_PORT_P0_RST_INDEX_N_OFFSET       0x4

/*----------------------------------------------------.
 | Register (0x000a0000 + (N) * 0x4) PUSH_PORT_P0_RST |
 +----------------------------------------------------+
 | bit  0 R/W  WPTR_RST_PUSH_P0                       |
 +---------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P0_RST_UNUSED_MASK          0xfffffffe
#define QS_REG_PUSH_PORT_P0_RST_BIT_WPTR_RST_PUSH_P0_MSK 0x00000001
#define QS_REG_PUSH_PORT_P0_RST_BIT_WPTR_RST_PUSH_P0_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P0_RST_VAL */
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL_INDEX_N_MIN              0
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL_INDEX_N_MAX              7
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL_INDEX_N_SIZE             8
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL_INDEX_N_OFFSET           0x4

/*--------------------------------------------------------.
 | Register (0x000a0400 + (N) * 0x4) PUSH_PORT_P0_RST_VAL |
 +--------------------------------------------------------+
 | bit  31:0 R  WPTR_RST_PUSH_P0_VAL                      |
 +-------------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P0_RST_VAL_UNUSED_MASK              0x00000000
#define QS_REG_PUSH_PORT_P0_RST_VAL_BIT_WPTR_RST_PUSH_P0_VAL_MSK 0xffffffff
#define QS_REG_PUSH_PORT_P0_RST_VAL_BIT_WPTR_RST_PUSH_P0_VAL_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P1_RST */
#define PMC_QS_REG_PUSH_PORT_P1_RST_INDEX_N_MIN          0
#define PMC_QS_REG_PUSH_PORT_P1_RST_INDEX_N_MAX          255
#define PMC_QS_REG_PUSH_PORT_P1_RST_INDEX_N_SIZE         256
#define PMC_QS_REG_PUSH_PORT_P1_RST_INDEX_N_OFFSET       0x4

/*----------------------------------------------------.
 | Register (0x000a0800 + (N) * 0x4) PUSH_PORT_P1_RST |
 +----------------------------------------------------+
 | bit  0 R/W  WPTR_RST_PUSH_P1                       |
 +---------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P1_RST_UNUSED_MASK          0xfffffffe
#define QS_REG_PUSH_PORT_P1_RST_BIT_WPTR_RST_PUSH_P1_MSK 0x00000001
#define QS_REG_PUSH_PORT_P1_RST_BIT_WPTR_RST_PUSH_P1_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P1_RST_VAL */
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL_INDEX_N_MIN              0
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL_INDEX_N_MAX              7
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL_INDEX_N_SIZE             8
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL_INDEX_N_OFFSET           0x4

/*--------------------------------------------------------.
 | Register (0x000a0c00 + (N) * 0x4) PUSH_PORT_P1_RST_VAL |
 +--------------------------------------------------------+
 | bit  31:0 R  WPTR_RST_PUSH_P1_VAL                      |
 +-------------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P1_RST_VAL_UNUSED_MASK              0x00000000
#define QS_REG_PUSH_PORT_P1_RST_VAL_BIT_WPTR_RST_PUSH_P1_VAL_MSK 0xffffffff
#define QS_REG_PUSH_PORT_P1_RST_VAL_BIT_WPTR_RST_PUSH_P1_VAL_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P2_RST */
#define PMC_QS_REG_PUSH_PORT_P2_RST_INDEX_N_MIN          0
#define PMC_QS_REG_PUSH_PORT_P2_RST_INDEX_N_MAX          255
#define PMC_QS_REG_PUSH_PORT_P2_RST_INDEX_N_SIZE         256
#define PMC_QS_REG_PUSH_PORT_P2_RST_INDEX_N_OFFSET       0x4

/*----------------------------------------------------.
 | Register (0x000a1000 + (N) * 0x4) PUSH_PORT_P2_RST |
 +----------------------------------------------------+
 | bit  0 R/W  WPTR_RST_PUSH_P2                       |
 +---------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P2_RST_UNUSED_MASK          0xfffffffe
#define QS_REG_PUSH_PORT_P2_RST_BIT_WPTR_RST_PUSH_P2_MSK 0x00000001
#define QS_REG_PUSH_PORT_P2_RST_BIT_WPTR_RST_PUSH_P2_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P2_RST_VAL */
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL_INDEX_N_MIN              0
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL_INDEX_N_MAX              7
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL_INDEX_N_SIZE             8
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL_INDEX_N_OFFSET           0x4

/*--------------------------------------------------------.
 | Register (0x000a1400 + (N) * 0x4) PUSH_PORT_P2_RST_VAL |
 +--------------------------------------------------------+
 | bit  31:0 R  WPTR_RST_PUSH_P2_VAL                      |
 +-------------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P2_RST_VAL_UNUSED_MASK              0x00000000
#define QS_REG_PUSH_PORT_P2_RST_VAL_BIT_WPTR_RST_PUSH_P2_VAL_MSK 0xffffffff
#define QS_REG_PUSH_PORT_P2_RST_VAL_BIT_WPTR_RST_PUSH_P2_VAL_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P3_RST */
#define PMC_QS_REG_PUSH_PORT_P3_RST_INDEX_N_MIN          0
#define PMC_QS_REG_PUSH_PORT_P3_RST_INDEX_N_MAX          255
#define PMC_QS_REG_PUSH_PORT_P3_RST_INDEX_N_SIZE         256
#define PMC_QS_REG_PUSH_PORT_P3_RST_INDEX_N_OFFSET       0x4

/*----------------------------------------------------.
 | Register (0x000a1800 + (N) * 0x4) PUSH_PORT_P3_RST |
 +----------------------------------------------------+
 | bit  0 R/W  WPTR_RST_PUSH_P3                       |
 +---------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P3_RST_UNUSED_MASK          0xfffffffe
#define QS_REG_PUSH_PORT_P3_RST_BIT_WPTR_RST_PUSH_P3_MSK 0x00000001
#define QS_REG_PUSH_PORT_P3_RST_BIT_WPTR_RST_PUSH_P3_OFF 0

/* index definitions for PMC_QS_REG_PUSH_PORT_P3_RST_VAL */
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL_INDEX_N_MIN              0
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL_INDEX_N_MAX              7
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL_INDEX_N_SIZE             8
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL_INDEX_N_OFFSET           0x4

/*--------------------------------------------------------.
 | Register (0x000a1c00 + (N) * 0x4) PUSH_PORT_P3_RST_VAL |
 +--------------------------------------------------------+
 | bit  31:0 R  WPTR_RST_PUSH_P3_VAL                      |
 +-------------------------------------------------------*/
#define PMC_QS_REG_PUSH_PORT_P3_RST_VAL_UNUSED_MASK              0x00000000
#define QS_REG_PUSH_PORT_P3_RST_VAL_BIT_WPTR_RST_PUSH_P3_VAL_MSK 0xffffffff
#define QS_REG_PUSH_PORT_P3_RST_VAL_BIT_WPTR_RST_PUSH_P3_VAL_OFF 0

/* index definitions for PMC_QS_REG_POP_PORT_RST */
#define PMC_QS_REG_POP_PORT_RST_INDEX_N_MIN      0
#define PMC_QS_REG_POP_PORT_RST_INDEX_N_MAX      127
#define PMC_QS_REG_POP_PORT_RST_INDEX_N_SIZE     128
#define PMC_QS_REG_POP_PORT_RST_INDEX_N_OFFSET   0x4

/*------------------------------------------------.
 | Register (0x000a2000 + (N) * 0x4) POP_PORT_RST |
 +------------------------------------------------+
 | bit  0 R/W  RPTR_RST_POP                       |
 +-----------------------------------------------*/
#define PMC_QS_REG_POP_PORT_RST_UNUSED_MASK      0xfffffffe
#define QS_REG_POP_PORT_RST_BIT_RPTR_RST_POP_MSK 0x00000001
#define QS_REG_POP_PORT_RST_BIT_RPTR_RST_POP_OFF 0

/* index definitions for PMC_QS_REG_RPTR_RST_POP_VAL_REG */
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG_INDEX_N_MIN          0
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG_INDEX_N_MAX          7
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG_INDEX_N_SIZE         8
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG_INDEX_N_OFFSET       0x4

/*--------------------------------------------------------.
 | Register (0x000a2400 + (N) * 0x4) RPTR_RST_POP_VAL_REG |
 +--------------------------------------------------------+
 | bit  31:0 R  RPTR_RST_POP_VAL                          |
 +-------------------------------------------------------*/
#define PMC_QS_REG_RPTR_RST_POP_VAL_REG_UNUSED_MASK          0x00000000
#define QS_REG_RPTR_RST_POP_VAL_REG_BIT_RPTR_RST_POP_VAL_MSK 0xffffffff
#define QS_REG_RPTR_RST_POP_VAL_REG_BIT_RPTR_RST_POP_VAL_OFF 0

/* index definitions for PMC_QS_REG_FIFO_PTR_EMPTY_REG */
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG_INDEX_N_MIN        0
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG_INDEX_N_MAX        7
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG_INDEX_N_SIZE       8
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG_INDEX_N_OFFSET     0x4

/*------------------------------------------------------.
 | Register (0x000a2600 + (N) * 0x4) FIFO_PTR_EMPTY_REG |
 +------------------------------------------------------+
 | bit  31:0 R  FIFO_PKT_EMPTY                          |
 +-----------------------------------------------------*/
#define PMC_QS_REG_FIFO_PTR_EMPTY_REG_UNUSED_MASK        0x00000000
#define QS_REG_FIFO_PTR_EMPTY_REG_BIT_FIFO_PKT_EMPTY_MSK 0xffffffff
#define QS_REG_FIFO_PTR_EMPTY_REG_BIT_FIFO_PKT_EMPTY_OFF 0

/*----------------------------------------.
 | Register 0x000a3d00 FIFO_CFG           |
 +----------------------------------------+
 | bit  28   R/W  FIFO_END_ADDR_CHG_ABORT |
 | bit  24   R/W  FIFO_END_ADDR_CHG_REQ   |
 | bit  16:0 R/W  FIFO_END_ADDR           |
 +---------------------------------------*/
#define PMC_QS_REG_FIFO_CFG_UNUSED_MASK                 0xeefe0000
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ABORT_MSK 0x10000000
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_ABORT_OFF 28
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_REQ_MSK   0x01000000
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_CHG_REQ_OFF   24
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_MSK           0x0001ffff
#define QS_REG_FIFO_CFG_BIT_FIFO_END_ADDR_OFF           0

/*-------------------------------------.
 | Register 0x000a3d04 FIFO_CFG_RID    |
 +-------------------------------------+
 | bit  7:0 R/W  FIFO_END_ADDR_CHG_RID |
 +------------------------------------*/
#define PMC_QS_REG_FIFO_CFG_RID_UNUSED_MASK               0xffffff00
#define QS_REG_FIFO_CFG_RID_BIT_FIFO_END_ADDR_CHG_RID_MSK 0x000000ff
#define QS_REG_FIFO_CFG_RID_BIT_FIFO_END_ADDR_CHG_RID_OFF 0

/*-------------------------------------.
 | Register 0x000a3d08 FIFO_CFG_WID    |
 +-------------------------------------+
 | bit  9:0 R/W  FIFO_END_ADDR_CHG_WID |
 +------------------------------------*/
#define PMC_QS_REG_FIFO_CFG_WID_UNUSED_MASK               0xfffffc00
#define QS_REG_FIFO_CFG_WID_BIT_FIFO_END_ADDR_CHG_WID_MSK 0x000003ff
#define QS_REG_FIFO_CFG_WID_BIT_FIFO_END_ADDR_CHG_WID_OFF 0

/*-------------------------------------.
 | Register 0x000a3d0c FIFO_CFG_STAT   |
 +-------------------------------------+
 | bit  0 R  FIFO_END_ADDR_CHG_SUCCESS |
 +------------------------------------*/
#define PMC_QS_REG_FIFO_CFG_STAT_UNUSED_MASK                   0xfffffffe
#define QS_REG_FIFO_CFG_STAT_BIT_FIFO_END_ADDR_CHG_SUCCESS_MSK 0x00000001
#define QS_REG_FIFO_CFG_STAT_BIT_FIFO_END_ADDR_CHG_SUCCESS_OFF 0

/*------------------------------.
 | Register 0x000a3e00 DBG_CTRL |
 +------------------------------+
 | bit  10:0 R/W  DBG_RADDR     |
 +-----------------------------*/
#define PMC_QS_REG_DBG_CTRL_UNUSED_MASK   0xfffef800
#define QS_REG_DBG_CTRL_BIT_DBG_RADDR_MSK 0x000007ff
#define QS_REG_DBG_CTRL_BIT_DBG_RADDR_OFF 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _QS_REGS_H */
