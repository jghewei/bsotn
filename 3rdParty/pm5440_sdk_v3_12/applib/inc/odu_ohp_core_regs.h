/******************************************************************************
 *   COPYRIGHT (C) 2013 PMC-SIERRA, INC. ALL RIGHTS RESERVED.
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
 *     odu_ohp_core block
 *****************************************************************************/
#ifndef _ODU_OHP_CORE_REGS_H
#define _ODU_OHP_CORE_REGS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*--------------------.
 | register addresses |
 +-------------------*/
#define PMC_OHP_CORE_REG_OHP_CFG_CTRL          0x00000000
#define PMC_OHP_CORE_REG_SCH_RXFA_CFG          0x00000004
#define PMC_OHP_CORE_REG_SCH_RXFB_CFG          0x00000008
#define PMC_OHP_CORE_REG_STGA_SA_UID           0x0000000c
#define PMC_OHP_CORE_REG_STGB_SA_UID           0x00000010
#define PMC_OHP_CORE_REG_STGA_DA_UID           0x00000014
#define PMC_OHP_CORE_REG_STGB_DA_UID           0x00000018
#define PMC_OHP_CORE_REG_RXFA_PWR_CTRL         0x0000001c
#define PMC_OHP_CORE_REG_RXFB_PWR_CTRL         0x00000020
#define PMC_OHP_CORE_REG_TXFA_PWR_CTRL         0x00000024
#define PMC_OHP_CORE_REG_TXFB_PWR_CTRL         0x00000028
#define PMC_OHP_CORE_REG_STGA_CH_EN( N )       (0x0000002c + (N) * 4)
#define PMC_OHP_CORE_REG_STGB_CH_EN( N )       (0x000001ac + (N) * 4)
#define PMC_OHP_CORE_REG_TXFA_OFFSET( N )      (0x0000032c + (N) * 4)
#define PMC_OHP_CORE_REG_TXFB_OFFSET( N )      (0x000004ac + (N) * 4)
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK( N )   (0x0000062c + (N) * 4)
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK( N )   (0x00000638 + (N) * 4)
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK( N )   (0x00000644 + (N) * 4)
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK( N )   (0x00000650 + (N) * 4)
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK( N )   (0x0000065c + (N) * 4)
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK( N )   (0x00000668 + (N) * 4)
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN0 0x00000674
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN1 0x00000678
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN2 0x0000067c
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT0    0x00000680
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT1    0x00000684
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT2    0x00000688
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN0 0x0000068c
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN1 0x00000690
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN2 0x00000694
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT0    0x00000698
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT1    0x0000069c
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT2    0x000006a0
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN0    0x000006a4
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN1    0x000006a8
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN2    0x000006ac
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT0       0x000006b0
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT1       0x000006b4
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT2       0x000006b8
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN0    0x000006bc
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN1    0x000006c0
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN2    0x000006c4
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT0       0x000006c8
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT1       0x000006cc
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT2       0x000006d0
#define PMC_OHP_CORE_REG_RXMAC_UID_FAIL_EN     0x000006d4
#define PMC_OHP_CORE_REG_RXMAC_FRMRID_FAIL_EN  0x000006d8
#define PMC_OHP_CORE_REG_RXMAC_CHID_FAIL_EN    0x000006dc
#define PMC_OHP_CORE_REG_RXMAC_PKTERR_INT_EN   0x000006e0
#define PMC_OHP_CORE_REG_RXMAC_RXFIFO_ERR_EN   0x000006e4
#define PMC_OHP_CORE_REG_RXMAC_UID_FAIL_INT    0x000006e8
#define PMC_OHP_CORE_REG_RXMAC_FRMRID_FAIL_INT 0x000006ec
#define PMC_OHP_CORE_REG_RXMAC_CHID_FAIL_INT   0x000006f0
#define PMC_OHP_CORE_REG_RXMAC_PKTERR_INT      0x000006f4
#define PMC_OHP_CORE_REG_RXMAC_RXFIFO_ERR_INT  0x000006f8
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK( N )    (0x00000800 + (N) * 4)
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK( N )    (0x00000a00 + (N) * 4)
#define PMC_OHP_CORE_REG_TXFA_INS_MASK( N )    (0x00000c00 + (N) * 4)
#define PMC_OHP_CORE_REG_TXFB_INS_MASK( N )    (0x00000e00 + (N) * 4)
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE( N ) (0x00001000 + (N) * 4)
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE( N ) (0x00001200 + (N) * 4)
#define PMC_OHP_CORE_REG_OHP_ENET_IO_CTRL      0x00001390

/*----------------------------------.
 | Register 0x00000000 OHP_CFG_CTRL |
 +----------------------------------+
 |                                  |
 | bit  8 R/W  STGB_GCC_EN          |
 |                                  |
 |                                  |
 | bit  4 R/W  STGA_GCC_EN          |
 |                                  |
 | bit  0 R/W  OHP_EN               |
 +---------------------------------*/
#define PMC_OHP_CORE_REG_OHP_CFG_CTRL_UNUSED_MASK     0xfffffeee
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_STGB_GCC_EN_MSK 0x00000100
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_STGB_GCC_EN_OFF 8
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_STGA_GCC_EN_MSK 0x00000010
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_STGA_GCC_EN_OFF 4
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_OHP_EN_MSK      0x00000001
#define OHP_CORE_REG_OHP_CFG_CTRL_BIT_OHP_EN_OFF      0

/*----------------------------------.
 | Register 0x00000004 SCH_RXFA_CFG |
 +----------------------------------+
 | bit  16 R/W  RXFA_SCH_FORCE      |
 | bit  8  R/W  RXFA_SCH_REQ        |
 | bit  0  R/W  RXFA_SCH_EN         |
 +---------------------------------*/
#define PMC_OHP_CORE_REG_SCH_RXFA_CFG_UNUSED_MASK        0xfffefefe
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_FORCE_MSK 0x00010000
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_FORCE_OFF 16
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_REQ_MSK   0x00000100
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_REQ_OFF   8
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_EN_MSK    0x00000001
#define OHP_CORE_REG_SCH_RXFA_CFG_BIT_RXFA_SCH_EN_OFF    0

/*----------------------------------.
 | Register 0x00000008 SCH_RXFB_CFG |
 +----------------------------------+
 | bit  16 R/W  RXFB_SCH_FORCE      |
 | bit  8  R/W  RXFB_SCH_REQ        |
 | bit  0  R/W  RXFB_SCH_EN         |
 +---------------------------------*/
#define PMC_OHP_CORE_REG_SCH_RXFB_CFG_UNUSED_MASK        0xfffefefe
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_FORCE_MSK 0x00010000
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_FORCE_OFF 16
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_REQ_MSK   0x00000100
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_REQ_OFF   8
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_EN_MSK    0x00000001
#define OHP_CORE_REG_SCH_RXFB_CFG_BIT_RXFB_SCH_EN_OFF    0

/*---------------------------------.
 | Register 0x0000000c STGA_SA_UID |
 +---------------------------------+
 | bit  31:0 R/W  STGA_SADDR_UID   |
 +--------------------------------*/
#define PMC_OHP_CORE_REG_STGA_SA_UID_UNUSED_MASK        0x00000000
#define OHP_CORE_REG_STGA_SA_UID_BIT_STGA_SADDR_UID_MSK 0xffffffff
#define OHP_CORE_REG_STGA_SA_UID_BIT_STGA_SADDR_UID_OFF 0

/*---------------------------------.
 | Register 0x00000010 STGB_SA_UID |
 +---------------------------------+
 | bit  31:0 R/W  STGB_SADDR_UID   |
 +--------------------------------*/
#define PMC_OHP_CORE_REG_STGB_SA_UID_UNUSED_MASK        0x00000000
#define OHP_CORE_REG_STGB_SA_UID_BIT_STGB_SADDR_UID_MSK 0xffffffff
#define OHP_CORE_REG_STGB_SA_UID_BIT_STGB_SADDR_UID_OFF 0

/*---------------------------------.
 | Register 0x00000014 STGA_DA_UID |
 +---------------------------------+
 | bit  31:0 R/W  STGA_DADDR_UID   |
 +--------------------------------*/
#define PMC_OHP_CORE_REG_STGA_DA_UID_UNUSED_MASK        0x00000000
#define OHP_CORE_REG_STGA_DA_UID_BIT_STGA_DADDR_UID_MSK 0xffffffff
#define OHP_CORE_REG_STGA_DA_UID_BIT_STGA_DADDR_UID_OFF 0

/*---------------------------------.
 | Register 0x00000018 STGB_DA_UID |
 +---------------------------------+
 | bit  31:0 R/W  STGB_DADDR_UID   |
 +--------------------------------*/
#define PMC_OHP_CORE_REG_STGB_DA_UID_UNUSED_MASK        0x00000000
#define OHP_CORE_REG_STGB_DA_UID_BIT_STGB_DADDR_UID_MSK 0xffffffff
#define OHP_CORE_REG_STGB_DA_UID_BIT_STGB_DADDR_UID_OFF 0

/*-----------------------------------.
 | Register 0x0000001c RXFA_PWR_CTRL |
 +-----------------------------------+
 | bit  5:0 R/W  RXFA_SD_CONFIG      |
 +----------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_PWR_CTRL_UNUSED_MASK        0xffffffc0
#define OHP_CORE_REG_RXFA_PWR_CTRL_BIT_RXFA_SD_CONFIG_MSK 0x0000003f
#define OHP_CORE_REG_RXFA_PWR_CTRL_BIT_RXFA_SD_CONFIG_OFF 0

/*-----------------------------------.
 | Register 0x00000020 RXFB_PWR_CTRL |
 +-----------------------------------+
 | bit  5:0 R/W  RXFB_SD_CONFIG      |
 +----------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_PWR_CTRL_UNUSED_MASK        0xffffffc0
#define OHP_CORE_REG_RXFB_PWR_CTRL_BIT_RXFB_SD_CONFIG_MSK 0x0000003f
#define OHP_CORE_REG_RXFB_PWR_CTRL_BIT_RXFB_SD_CONFIG_OFF 0

/*-----------------------------------.
 | Register 0x00000024 TXFA_PWR_CTRL |
 +-----------------------------------+
 | bit  5:0 R/W  TXFA_SD_CONFIG      |
 +----------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_PWR_CTRL_UNUSED_MASK        0xffffffc0
#define OHP_CORE_REG_TXFA_PWR_CTRL_BIT_TXFA_SD_CONFIG_MSK 0x0000003f
#define OHP_CORE_REG_TXFA_PWR_CTRL_BIT_TXFA_SD_CONFIG_OFF 0

/*-----------------------------------.
 | Register 0x00000028 TXFB_PWR_CTRL |
 +-----------------------------------+
 | bit  5:0 R/W  TXFB_SD_CONFIG      |
 +----------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_PWR_CTRL_UNUSED_MASK        0xffffffc0
#define OHP_CORE_REG_TXFB_PWR_CTRL_BIT_TXFB_SD_CONFIG_MSK 0x0000003f
#define OHP_CORE_REG_TXFB_PWR_CTRL_BIT_TXFB_SD_CONFIG_OFF 0

/* index definitions for PMC_OHP_CORE_REG_STGA_CH_EN */
#define PMC_OHP_CORE_REG_STGA_CH_EN_INDEX_N_MIN         0
#define PMC_OHP_CORE_REG_STGA_CH_EN_INDEX_N_MAX         95
#define PMC_OHP_CORE_REG_STGA_CH_EN_INDEX_N_SIZE        96
#define PMC_OHP_CORE_REG_STGA_CH_EN_INDEX_N_OFFSET      4

/*--------------------------------------------.
 | Register (0x0000002c + (N) * 4) STGA_CH_EN |
 +--------------------------------------------+
 | bit  0 R/W  STGA_CH_EN_CTRL                |
 +-------------------------------------------*/
#define PMC_OHP_CORE_REG_STGA_CH_EN_UNUSED_MASK         0xfffffffe
#define OHP_CORE_REG_STGA_CH_EN_BIT_STGA_CH_EN_CTRL_MSK 0x00000001
#define OHP_CORE_REG_STGA_CH_EN_BIT_STGA_CH_EN_CTRL_OFF 0

/* index definitions for PMC_OHP_CORE_REG_STGB_CH_EN */
#define PMC_OHP_CORE_REG_STGB_CH_EN_INDEX_N_MIN         0
#define PMC_OHP_CORE_REG_STGB_CH_EN_INDEX_N_MAX         95
#define PMC_OHP_CORE_REG_STGB_CH_EN_INDEX_N_SIZE        96
#define PMC_OHP_CORE_REG_STGB_CH_EN_INDEX_N_OFFSET      4

/*--------------------------------------------.
 | Register (0x000001ac + (N) * 4) STGB_CH_EN |
 +--------------------------------------------+
 | bit  0 R/W  STGB_CH_EN_CTRL                |
 +-------------------------------------------*/
#define PMC_OHP_CORE_REG_STGB_CH_EN_UNUSED_MASK         0xfffffffe
#define OHP_CORE_REG_STGB_CH_EN_BIT_STGB_CH_EN_CTRL_MSK 0x00000001
#define OHP_CORE_REG_STGB_CH_EN_BIT_STGB_CH_EN_CTRL_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFA_OFFSET */
#define PMC_OHP_CORE_REG_TXFA_OFFSET_INDEX_N_MIN         0
#define PMC_OHP_CORE_REG_TXFA_OFFSET_INDEX_N_MAX         95
#define PMC_OHP_CORE_REG_TXFA_OFFSET_INDEX_N_SIZE        96
#define PMC_OHP_CORE_REG_TXFA_OFFSET_INDEX_N_OFFSET      4

/*---------------------------------------------.
 | Register (0x0000032c + (N) * 4) TXFA_OFFSET |
 +---------------------------------------------+
 | bit  8:0 R/W  TXFA_INS_OFFSET               |
 +--------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_OFFSET_UNUSED_MASK         0xfffffe00
#define OHP_CORE_REG_TXFA_OFFSET_BIT_TXFA_INS_OFFSET_MSK 0x000001ff
#define OHP_CORE_REG_TXFA_OFFSET_BIT_TXFA_INS_OFFSET_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFB_OFFSET */
#define PMC_OHP_CORE_REG_TXFB_OFFSET_INDEX_N_MIN         0
#define PMC_OHP_CORE_REG_TXFB_OFFSET_INDEX_N_MAX         95
#define PMC_OHP_CORE_REG_TXFB_OFFSET_INDEX_N_SIZE        96
#define PMC_OHP_CORE_REG_TXFB_OFFSET_INDEX_N_OFFSET      4

/*---------------------------------------------.
 | Register (0x000004ac + (N) * 4) TXFB_OFFSET |
 +---------------------------------------------+
 | bit  8:0 R/W  TXFB_INS_OFFSET               |
 +--------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_OFFSET_UNUSED_MASK         0xfffffe00
#define OHP_CORE_REG_TXFB_OFFSET_BIT_TXFB_INS_OFFSET_MSK 0x000001ff
#define OHP_CORE_REG_TXFB_OFFSET_BIT_TXFB_INS_OFFSET_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFA_GCC0_MASK */
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x0000062c + (N) * 4) TXFA_GCC0_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFA_GCC0_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_GCC0_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFA_GCC0_MASK_BIT_TXFA_GCC0_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFA_GCC0_MASK_BIT_TXFA_GCC0_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFA_GCC1_MASK */
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x00000638 + (N) * 4) TXFA_GCC1_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFA_GCC1_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_GCC1_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFA_GCC1_MASK_BIT_TXFA_GCC1_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFA_GCC1_MASK_BIT_TXFA_GCC1_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFA_GCC2_MASK */
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x00000644 + (N) * 4) TXFA_GCC2_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFA_GCC2_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_GCC2_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFA_GCC2_MASK_BIT_TXFA_GCC2_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFA_GCC2_MASK_BIT_TXFA_GCC2_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFB_GCC0_MASK */
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x00000650 + (N) * 4) TXFB_GCC0_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFB_GCC0_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_GCC0_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFB_GCC0_MASK_BIT_TXFB_GCC0_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFB_GCC0_MASK_BIT_TXFB_GCC0_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFB_GCC1_MASK */
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x0000065c + (N) * 4) TXFB_GCC1_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFB_GCC1_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_GCC1_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFB_GCC1_MASK_BIT_TXFB_GCC1_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFB_GCC1_MASK_BIT_TXFB_GCC1_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFB_GCC2_MASK */
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK_INDEX_N_MIN            0
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK_INDEX_N_MAX            2
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK_INDEX_N_SIZE           3
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK_INDEX_N_OFFSET         4

/*------------------------------------------------.
 | Register (0x00000668 + (N) * 4) TXFB_GCC2_MASK |
 +------------------------------------------------+
 |                                                |
 | bit  31:0 R/W  TXFB_GCC2_INS_MASK              |
 |                                                |
 +-----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_GCC2_MASK_UNUSED_MASK            0x00000000
#define OHP_CORE_REG_TXFB_GCC2_MASK_BIT_TXFB_GCC2_INS_MASK_MSK 0xffffffff
#define OHP_CORE_REG_TXFB_GCC2_MASK_BIT_TXFB_GCC2_INS_MASK_OFF 0

/*-------------------------------------------.
 | Register 0x00000674 RXFA_CFC_FULL_INT_EN0 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN0_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN0_BIT_RXFA_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN0_BIT_RXFA_CFC_FULL_E_OFF 0

/*-------------------------------------------.
 | Register 0x00000678 RXFA_CFC_FULL_INT_EN1 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN1_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN1_BIT_RXFA_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN1_BIT_RXFA_CFC_FULL_E_OFF 0

/*-------------------------------------------.
 | Register 0x0000067c RXFA_CFC_FULL_INT_EN2 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT_EN2_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN2_BIT_RXFA_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT_EN2_BIT_RXFA_CFC_FULL_E_OFF 0

/*----------------------------------------.
 | Register 0x00000680 RXFA_CFC_FULL_INT0 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT0_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT0_BIT_RXFA_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT0_BIT_RXFA_CFC_FULL_I_OFF 0

/*----------------------------------------.
 | Register 0x00000684 RXFA_CFC_FULL_INT1 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT1_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT1_BIT_RXFA_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT1_BIT_RXFA_CFC_FULL_I_OFF 0

/*----------------------------------------.
 | Register 0x00000688 RXFA_CFC_FULL_INT2 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CFC_FULL_INT2_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFA_CFC_FULL_INT2_BIT_RXFA_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_CFC_FULL_INT2_BIT_RXFA_CFC_FULL_I_OFF 0

/*-------------------------------------------.
 | Register 0x0000068c RXFB_CFC_FULL_INT_EN0 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN0_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN0_BIT_RXFB_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN0_BIT_RXFB_CFC_FULL_E_OFF 0

/*-------------------------------------------.
 | Register 0x00000690 RXFB_CFC_FULL_INT_EN1 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN1_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN1_BIT_RXFB_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN1_BIT_RXFB_CFC_FULL_E_OFF 0

/*-------------------------------------------.
 | Register 0x00000694 RXFB_CFC_FULL_INT_EN2 |
 +-------------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_E            |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT_EN2_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN2_BIT_RXFB_CFC_FULL_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT_EN2_BIT_RXFB_CFC_FULL_E_OFF 0

/*----------------------------------------.
 | Register 0x00000698 RXFB_CFC_FULL_INT0 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT0_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT0_BIT_RXFB_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT0_BIT_RXFB_CFC_FULL_I_OFF 0

/*----------------------------------------.
 | Register 0x0000069c RXFB_CFC_FULL_INT1 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT1_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT1_BIT_RXFB_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT1_BIT_RXFB_CFC_FULL_I_OFF 0

/*----------------------------------------.
 | Register 0x000006a0 RXFB_CFC_FULL_INT2 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_CFC_FULL_I         |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CFC_FULL_INT2_UNUSED_MASK         0x00000000
#define OHP_CORE_REG_RXFB_CFC_FULL_INT2_BIT_RXFB_CFC_FULL_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_CFC_FULL_INT2_BIT_RXFB_CFC_FULL_I_OFF 0

/*----------------------------------------.
 | Register 0x000006a4 RXFA_TXDLY_INT_EN0 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN0_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN0_BIT_RXFA_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN0_BIT_RXFA_TXDLY_E_OFF 0

/*----------------------------------------.
 | Register 0x000006a8 RXFA_TXDLY_INT_EN1 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN1_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN1_BIT_RXFA_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN1_BIT_RXFA_TXDLY_E_OFF 0

/*----------------------------------------.
 | Register 0x000006ac RXFA_TXDLY_INT_EN2 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT_EN2_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN2_BIT_RXFA_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT_EN2_BIT_RXFA_TXDLY_E_OFF 0

/*-------------------------------------.
 | Register 0x000006b0 RXFA_TXDLY_INT0 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT0_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT0_BIT_RXFA_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT0_BIT_RXFA_TXDLY_I_OFF 0

/*-------------------------------------.
 | Register 0x000006b4 RXFA_TXDLY_INT1 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT1_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT1_BIT_RXFA_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT1_BIT_RXFA_TXDLY_I_OFF 0

/*-------------------------------------.
 | Register 0x000006b8 RXFA_TXDLY_INT2 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFA_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_TXDLY_INT2_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFA_TXDLY_INT2_BIT_RXFA_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFA_TXDLY_INT2_BIT_RXFA_TXDLY_I_OFF 0

/*----------------------------------------.
 | Register 0x000006bc RXFB_TXDLY_INT_EN0 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN0_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN0_BIT_RXFB_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN0_BIT_RXFB_TXDLY_E_OFF 0

/*----------------------------------------.
 | Register 0x000006c0 RXFB_TXDLY_INT_EN1 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN1_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN1_BIT_RXFB_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN1_BIT_RXFB_TXDLY_E_OFF 0

/*----------------------------------------.
 | Register 0x000006c4 RXFB_TXDLY_INT_EN2 |
 +----------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_E            |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT_EN2_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN2_BIT_RXFB_TXDLY_E_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT_EN2_BIT_RXFB_TXDLY_E_OFF 0

/*-------------------------------------.
 | Register 0x000006c8 RXFB_TXDLY_INT0 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT0_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT0_BIT_RXFB_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT0_BIT_RXFB_TXDLY_I_OFF 0

/*-------------------------------------.
 | Register 0x000006cc RXFB_TXDLY_INT1 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT1_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT1_BIT_RXFB_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT1_BIT_RXFB_TXDLY_I_OFF 0

/*-------------------------------------.
 | Register 0x000006d0 RXFB_TXDLY_INT2 |
 +-------------------------------------+
 | bit  31:0 R/W  RXFB_TXDLY_I         |
 +------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_TXDLY_INT2_UNUSED_MASK      0x00000000
#define OHP_CORE_REG_RXFB_TXDLY_INT2_BIT_RXFB_TXDLY_I_MSK 0xffffffff
#define OHP_CORE_REG_RXFB_TXDLY_INT2_BIT_RXFB_TXDLY_I_OFF 0

/*---------------------------------------.
 | Register 0x000006d4 RXMAC_UID_FAIL_EN |
 +---------------------------------------+
 | bit  0 R/W  RXMAC_UID_FAIL_E          |
 +--------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_UID_FAIL_EN_UNUSED_MASK          0xfffffffe
#define OHP_CORE_REG_RXMAC_UID_FAIL_EN_BIT_RXMAC_UID_FAIL_E_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_UID_FAIL_EN_BIT_RXMAC_UID_FAIL_E_OFF 0

/*------------------------------------------.
 | Register 0x000006d8 RXMAC_FRMRID_FAIL_EN |
 +------------------------------------------+
 | bit  0 R/W  RXMAC_FRMRID_FAIL_E          |
 +-----------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_FRMRID_FAIL_EN_UNUSED_MASK             0xfffffffe
#define OHP_CORE_REG_RXMAC_FRMRID_FAIL_EN_BIT_RXMAC_FRMRID_FAIL_E_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_FRMRID_FAIL_EN_BIT_RXMAC_FRMRID_FAIL_E_OFF 0

/*----------------------------------------.
 | Register 0x000006dc RXMAC_CHID_FAIL_EN |
 +----------------------------------------+
 | bit  0 R/W  RXMAC_CHID_FAIL_E          |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_CHID_FAIL_EN_UNUSED_MASK           0xfffffffe
#define OHP_CORE_REG_RXMAC_CHID_FAIL_EN_BIT_RXMAC_CHID_FAIL_E_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_CHID_FAIL_EN_BIT_RXMAC_CHID_FAIL_E_OFF 0

/*-----------------------------------------.
 | Register 0x000006e0 RXMAC_PKTERR_INT_EN |
 +-----------------------------------------+
 | bit  0 R/W  RXMAC_PKTERR_E              |
 +----------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_PKTERR_INT_EN_UNUSED_MASK        0xfffffffe
#define OHP_CORE_REG_RXMAC_PKTERR_INT_EN_BIT_RXMAC_PKTERR_E_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_PKTERR_INT_EN_BIT_RXMAC_PKTERR_E_OFF 0

/*-----------------------------------------.
 | Register 0x000006e4 RXMAC_RXFIFO_ERR_EN |
 +-----------------------------------------+
 | bit  0 R/W  RXMAC_FIFO_ERR_E            |
 +----------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_RXFIFO_ERR_EN_UNUSED_MASK          0xfffffffe
#define OHP_CORE_REG_RXMAC_RXFIFO_ERR_EN_BIT_RXMAC_FIFO_ERR_E_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_RXFIFO_ERR_EN_BIT_RXMAC_FIFO_ERR_E_OFF 0

/*----------------------------------------.
 | Register 0x000006e8 RXMAC_UID_FAIL_INT |
 +----------------------------------------+
 | bit  0 R/W  RXMAC_UID_FAIL_I           |
 +---------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_UID_FAIL_INT_UNUSED_MASK          0xfffffffe
#define OHP_CORE_REG_RXMAC_UID_FAIL_INT_BIT_RXMAC_UID_FAIL_I_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_UID_FAIL_INT_BIT_RXMAC_UID_FAIL_I_OFF 0

/*-------------------------------------------.
 | Register 0x000006ec RXMAC_FRMRID_FAIL_INT |
 +-------------------------------------------+
 | bit  0 R/W  RXMAC_FRMRID_FAIL_I           |
 +------------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_FRMRID_FAIL_INT_UNUSED_MASK             0xfffffffe
#define OHP_CORE_REG_RXMAC_FRMRID_FAIL_INT_BIT_RXMAC_FRMRID_FAIL_I_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_FRMRID_FAIL_INT_BIT_RXMAC_FRMRID_FAIL_I_OFF 0

/*-----------------------------------------.
 | Register 0x000006f0 RXMAC_CHID_FAIL_INT |
 +-----------------------------------------+
 | bit  0 R/W  RXMAC_CHID_FAIL_I           |
 +----------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_CHID_FAIL_INT_UNUSED_MASK           0xfffffffe
#define OHP_CORE_REG_RXMAC_CHID_FAIL_INT_BIT_RXMAC_CHID_FAIL_I_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_CHID_FAIL_INT_BIT_RXMAC_CHID_FAIL_I_OFF 0

/*--------------------------------------.
 | Register 0x000006f4 RXMAC_PKTERR_INT |
 +--------------------------------------+
 | bit  0 R/W  RXMAC_PKTERR_I           |
 +-------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_PKTERR_INT_UNUSED_MASK        0xfffffffe
#define OHP_CORE_REG_RXMAC_PKTERR_INT_BIT_RXMAC_PKTERR_I_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_PKTERR_INT_BIT_RXMAC_PKTERR_I_OFF 0

/*------------------------------------------.
 | Register 0x000006f8 RXMAC_RXFIFO_ERR_INT |
 +------------------------------------------+
 | bit  0 R/W  RXMAC_FIFO_ERR_I             |
 +-----------------------------------------*/
#define PMC_OHP_CORE_REG_RXMAC_RXFIFO_ERR_INT_UNUSED_MASK          0xfffffffe
#define OHP_CORE_REG_RXMAC_RXFIFO_ERR_INT_BIT_RXMAC_FIFO_ERR_I_MSK 0x00000001
#define OHP_CORE_REG_RXMAC_RXFIFO_ERR_INT_BIT_RXMAC_FIFO_ERR_I_OFF 0

/* index definitions for PMC_OHP_CORE_REG_RXFA_EXT_MASK */
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK_INDEX_N_MIN       0
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK_INDEX_N_MAX       95
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK_INDEX_N_SIZE      96
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK_INDEX_N_OFFSET    4

/*-----------------------------------------------.
 | Register (0x00000800 + (N) * 4) RXFA_EXT_MASK |
 +-----------------------------------------------+
 | bit  15:0 R/W  RXFA_EXT_MASK                  |
 +----------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_EXT_MASK_UNUSED_MASK       0xffff0000
#define OHP_CORE_REG_RXFA_EXT_MASK_BIT_RXFA_EXT_MASK_MSK 0x0000ffff
#define OHP_CORE_REG_RXFA_EXT_MASK_BIT_RXFA_EXT_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_RXFB_EXT_MASK */
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK_INDEX_N_MIN       0
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK_INDEX_N_MAX       95
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK_INDEX_N_SIZE      96
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK_INDEX_N_OFFSET    4

/*-----------------------------------------------.
 | Register (0x00000a00 + (N) * 4) RXFB_EXT_MASK |
 +-----------------------------------------------+
 | bit  15:0 R/W  RXFB_EXT_MASK                  |
 +----------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_EXT_MASK_UNUSED_MASK       0xffff0000
#define OHP_CORE_REG_RXFB_EXT_MASK_BIT_RXFB_EXT_MASK_MSK 0x0000ffff
#define OHP_CORE_REG_RXFB_EXT_MASK_BIT_RXFB_EXT_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFA_INS_MASK */
#define PMC_OHP_CORE_REG_TXFA_INS_MASK_INDEX_N_MIN       0
#define PMC_OHP_CORE_REG_TXFA_INS_MASK_INDEX_N_MAX       95
#define PMC_OHP_CORE_REG_TXFA_INS_MASK_INDEX_N_SIZE      96
#define PMC_OHP_CORE_REG_TXFA_INS_MASK_INDEX_N_OFFSET    4

/*-----------------------------------------------.
 | Register (0x00000c00 + (N) * 4) TXFA_INS_MASK |
 +-----------------------------------------------+
 | bit  15:0 R/W  TXFA_INS_MASK                  |
 +----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFA_INS_MASK_UNUSED_MASK       0xffff0000
#define OHP_CORE_REG_TXFA_INS_MASK_BIT_TXFA_INS_MASK_MSK 0x0000ffff
#define OHP_CORE_REG_TXFA_INS_MASK_BIT_TXFA_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_TXFB_INS_MASK */
#define PMC_OHP_CORE_REG_TXFB_INS_MASK_INDEX_N_MIN       0
#define PMC_OHP_CORE_REG_TXFB_INS_MASK_INDEX_N_MAX       95
#define PMC_OHP_CORE_REG_TXFB_INS_MASK_INDEX_N_SIZE      96
#define PMC_OHP_CORE_REG_TXFB_INS_MASK_INDEX_N_OFFSET    4

/*-----------------------------------------------.
 | Register (0x00000e00 + (N) * 4) TXFB_INS_MASK |
 +-----------------------------------------------+
 | bit  15:0 R/W  TXFB_INS_MASK                  |
 +----------------------------------------------*/
#define PMC_OHP_CORE_REG_TXFB_INS_MASK_UNUSED_MASK       0xffff0000
#define OHP_CORE_REG_TXFB_INS_MASK_BIT_TXFB_INS_MASK_MSK 0x0000ffff
#define OHP_CORE_REG_TXFB_INS_MASK_BIT_TXFB_INS_MASK_OFF 0

/* index definitions for PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE */
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE_INDEX_N_MIN     0
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE_INDEX_N_MAX     95
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE_INDEX_N_SIZE    96
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE_INDEX_N_OFFSET  4

/*--------------------------------------------------.
 | Register (0x00001000 + (N) * 4) RXFA_CH_SCHEDULE |
 +--------------------------------------------------+
 | bit  7:0 R/W  SRV_CH_ID_A                        |
 +-------------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFA_CH_SCHEDULE_UNUSED_MASK     0xffffff00
#define OHP_CORE_REG_RXFA_CH_SCHEDULE_BIT_SRV_CH_ID_A_MSK 0x000000ff
#define OHP_CORE_REG_RXFA_CH_SCHEDULE_BIT_SRV_CH_ID_A_OFF 0

/* index definitions for PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE */
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE_INDEX_N_MIN     0
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE_INDEX_N_MAX     95
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE_INDEX_N_SIZE    96
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE_INDEX_N_OFFSET  4

/*--------------------------------------------------.
 | Register (0x00001200 + (N) * 4) RXFB_CH_SCHEDULE |
 +--------------------------------------------------+
 | bit  7:0 R/W  SRV_CH_ID_B                        |
 +-------------------------------------------------*/
#define PMC_OHP_CORE_REG_RXFB_CH_SCHEDULE_UNUSED_MASK     0xffffff00
#define OHP_CORE_REG_RXFB_CH_SCHEDULE_BIT_SRV_CH_ID_B_MSK 0x000000ff
#define OHP_CORE_REG_RXFB_CH_SCHEDULE_BIT_SRV_CH_ID_B_OFF 0

/*--------------------------------------.
 | Register 0x00001390 OHP_ENET_IO_CTRL |
 +--------------------------------------+
 | bit  24 R/W  FEGE_RX_FLIP            |
 | bit  16 R/W  FEGE_TX_FLIP            |
 | bit  8  R/W  SGMII_RX_FLIP           |
 | bit  0  R/W  SGMII_TX_FLIP           |
 +-------------------------------------*/
#define PMC_OHP_CORE_REG_OHP_ENET_IO_CTRL_UNUSED_MASK       0xfefefefe
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_FEGE_RX_FLIP_MSK  0x01000000
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_FEGE_RX_FLIP_OFF  24
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_FEGE_TX_FLIP_MSK  0x00010000
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_FEGE_TX_FLIP_OFF  16
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_SGMII_RX_FLIP_MSK 0x00000100
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_SGMII_RX_FLIP_OFF 8
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_SGMII_TX_FLIP_MSK 0x00000001
#define OHP_CORE_REG_OHP_ENET_IO_CTRL_BIT_SGMII_TX_FLIP_OFF 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ODU_OHP_CORE_REGS_H */
