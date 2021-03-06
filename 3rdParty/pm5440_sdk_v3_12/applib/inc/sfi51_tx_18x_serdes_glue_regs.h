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
 *     sfi51_tx_18x_serdes_glue block
 *****************************************************************************/
#ifndef _SFI51_TX_18X_SERDES_GLUE_REGS_H
#define _SFI51_TX_18X_SERDES_GLUE_REGS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*--------------------.
 | register addresses |
 +-------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL        0x00000000
#define PMC_SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1 0x00000004
#define PMC_SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2 0x00000008
#define PMC_SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2    0x0000000c
#define PMC_SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG       0x00000010
#define PMC_SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG    0x00000014
#define PMC_SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG      0x00000018
#define PMC_SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG      0x0000001c
#define PMC_SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG  0x00000020

/*-----------------------------------.
 | Register 0x00000000 SW_RESET_CTRL |
 +-----------------------------------+
 | bit  3 R/W  RXS_CTRL_RSTB         |
 | bit  2 R/W  LOOPTIME_RSTB         |
 | bit  1 R/W  DIGITAL_RSTB          |
 | bit  0 R/W  SW_RESET              |
 +----------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_UNUSED_MASK       0xfffffff0
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_RXS_CTRL_RSTB_MSK 0x00000008
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_RXS_CTRL_RSTB_OFF 3
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_LOOPTIME_RSTB_MSK 0x00000004
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_LOOPTIME_RSTB_OFF 2
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_DIGITAL_RSTB_MSK  0x00000002
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_DIGITAL_RSTB_OFF  1
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_SW_RESET_MSK      0x00000001
#define SFI51_TX_18X_GLUE_REG_SW_RESET_CTRL_BIT_SW_RESET_OFF      0

/*------------------------------------------.
 | Register 0x00000004 LOOPTIMING_CFG_REG_1 |
 +------------------------------------------+
 | bit  29:16 R/W  DSM_DENOM                |
 | bit  15:12 R/W  LOOPTIME_FREEZE_CNT      |
 | bit  8     R/W  LOOPTIME_FREEZE          |
 | bit  7:6   R/W  RCLK_WIDTH               |
 | bit  3:2   R/W  DSM_TYPE                 |
 | bit  0     R/W  PMM_ENABLE               |
 +-----------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_UNUSED_MASK             0xc0000e32
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_DSM_DENOM_MSK           0x3fff0000
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_DSM_DENOM_OFF           16
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_LOOPTIME_FREEZE_CNT_MSK 0x0000f000
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_LOOPTIME_FREEZE_CNT_OFF 12
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_LOOPTIME_FREEZE_MSK     0x00000100
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_LOOPTIME_FREEZE_OFF     8
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_RCLK_WIDTH_MSK          0x000000c0
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_RCLK_WIDTH_OFF          6
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_DSM_TYPE_MSK            0x0000000c
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_DSM_TYPE_OFF            2
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_PMM_ENABLE_MSK          0x00000001
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_1_BIT_PMM_ENABLE_OFF          0

/*------------------------------------------.
 | Register 0x00000008 LOOPTIMING_CFG_REG_2 |
 +------------------------------------------+
 | bit  31:16 R/W  PKT_PERIOD               |
 | bit  13:9  R/W  INC_STEP                 |
 | bit  8:0   R/W  PKT_SIZE                 |
 +-----------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_UNUSED_MASK    0x0000c000
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_PKT_PERIOD_MSK 0xffff0000
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_PKT_PERIOD_OFF 16
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_INC_STEP_MSK   0x00003e00
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_INC_STEP_OFF   9
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_PKT_SIZE_MSK   0x000001ff
#define SFI51_TX_18X_GLUE_REG_LOOPTIMING_CFG_REG_2_BIT_PKT_SIZE_OFF   0

/*---------------------------------------.
 | Register 0x0000000c RXS_CTRLLER_CFG_2 |
 +---------------------------------------+
 | bit  10  R/W  SQUELCH_OVR             |
 | bit  9:8 R/W  SQUELCH_OVR_MODE        |
 | bit  6   R/W  GEN_FORCE_NOMINAL       |
 | bit  5   R/W  GEN_HOLDOVER            |
 | bit  4   R/W  GEN_FREEZE              |
 | bit  3:2 R/W  RXS_OVR_MODE            |
 | bit  1   R/W  RXS_OVR                 |
 | bit  0   R/W  RXS_CTRL_EN             |
 +--------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_UNUSED_MASK           0xfffff880
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_SQUELCH_OVR_MSK       0x00000400
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_SQUELCH_OVR_OFF       10
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_SQUELCH_OVR_MODE_MSK  0x00000300
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_SQUELCH_OVR_MODE_OFF  8
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_FORCE_NOMINAL_MSK 0x00000040
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_FORCE_NOMINAL_OFF 6
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_HOLDOVER_MSK      0x00000020
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_HOLDOVER_OFF      5
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_FREEZE_MSK        0x00000010
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_GEN_FREEZE_OFF        4
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_OVR_MODE_MSK      0x0000000c
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_OVR_MODE_OFF      2
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_OVR_MSK           0x00000002
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_OVR_OFF           1
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_CTRL_EN_MSK       0x00000001
#define SFI51_TX_18X_GLUE_REG_RXS_CTRLLER_CFG_2_BIT_RXS_CTRL_EN_OFF       0

/*------------------------------------.
 | Register 0x00000010 GLUE_LOGIC_CFG |
 +------------------------------------+
 | bit  28    R/W  LI_RX_OOF_LOF_POL  |
 | bit  27    R/W  RXS_POL            |
 | bit  24:22 R/W  REFCLK_SEL         |
 | bit  20    R/W  CKCTL_SEL          |
 | bit  19:0  R/W  DCK_DATA_PATT      |
 +-----------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_UNUSED_MASK           0xe6200000
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_LI_RX_OOF_LOF_POL_MSK 0x10000000
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_LI_RX_OOF_LOF_POL_OFF 28
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_RXS_POL_MSK           0x08000000
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_RXS_POL_OFF           27
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_REFCLK_SEL_MSK        0x01c00000
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_REFCLK_SEL_OFF        22
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_CKCTL_SEL_MSK         0x00100000
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_CKCTL_SEL_OFF         20
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_DCK_DATA_PATT_MSK     0x000fffff
#define SFI51_TX_18X_GLUE_REG_GLUE_LOGIC_CFG_BIT_DCK_DATA_PATT_OFF     0

/*---------------------------------------.
 | Register 0x00000014 DEVICE_INT_EN_REG |
 +---------------------------------------+
 | bit  9 R/W  TX_2X_SLICE8_INT_DEV_E    |
 | bit  8 R/W  TX_2X_SLICE7_INT_DEV_E    |
 | bit  7 R/W  TX_2X_SLICE6_INT_DEV_E    |
 | bit  6 R/W  TX_2X_SLICE5_INT_DEV_E    |
 | bit  5 R/W  TX_2X_SLICE4_INT_DEV_E    |
 | bit  4 R/W  TX_2X_SLICE3_INT_DEV_E    |
 | bit  3 R/W  TX_2X_SLICE2_INT_DEV_E    |
 | bit  2 R/W  TX_2X_SLICE1_INT_DEV_E    |
 | bit  1 R/W  TX_2X_SLICE0_INT_DEV_E    |
 | bit  0 R/W  CSU_INT_DEV_E             |
 +--------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_UNUSED_MASK                0xfffffc00
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE8_INT_DEV_E_MSK 0x00000200
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE8_INT_DEV_E_OFF 9
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE7_INT_DEV_E_MSK 0x00000100
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE7_INT_DEV_E_OFF 8
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE6_INT_DEV_E_MSK 0x00000080
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE6_INT_DEV_E_OFF 7
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE5_INT_DEV_E_MSK 0x00000040
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE5_INT_DEV_E_OFF 6
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE4_INT_DEV_E_MSK 0x00000020
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE4_INT_DEV_E_OFF 5
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE3_INT_DEV_E_MSK 0x00000010
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE3_INT_DEV_E_OFF 4
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE2_INT_DEV_E_MSK 0x00000008
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE2_INT_DEV_E_OFF 3
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE1_INT_DEV_E_MSK 0x00000004
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE1_INT_DEV_E_OFF 2
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE0_INT_DEV_E_MSK 0x00000002
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_TX_2X_SLICE0_INT_DEV_E_OFF 1
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_CSU_INT_DEV_E_MSK          0x00000001
#define SFI51_TX_18X_GLUE_REG_DEVICE_INT_EN_REG_BIT_CSU_INT_DEV_E_OFF          0

/*-------------------------------------.
 | Register 0x00000018 MIPS_INT_EN_REG |
 +-------------------------------------+
 | bit  9 R/W  TX_2X_SLICE8_INT_MIP_E  |
 | bit  8 R/W  TX_2X_SLICE7_INT_MIP_E  |
 | bit  7 R/W  TX_2X_SLICE6_INT_MIP_E  |
 | bit  6 R/W  TX_2X_SLICE5_INT_MIP_E  |
 | bit  5 R/W  TX_2X_SLICE4_INT_MIP_E  |
 | bit  4 R/W  TX_2X_SLICE3_INT_MIP_E  |
 | bit  3 R/W  TX_2X_SLICE2_INT_MIP_E  |
 | bit  2 R/W  TX_2X_SLICE1_INT_MIP_E  |
 | bit  1 R/W  TX_2X_SLICE0_INT_MIP_E  |
 | bit  0 R/W  CSU_INT_MIP_E           |
 +------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_UNUSED_MASK                0xfffffc00
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE8_INT_MIP_E_MSK 0x00000200
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE8_INT_MIP_E_OFF 9
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE7_INT_MIP_E_MSK 0x00000100
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE7_INT_MIP_E_OFF 8
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE6_INT_MIP_E_MSK 0x00000080
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE6_INT_MIP_E_OFF 7
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE5_INT_MIP_E_MSK 0x00000040
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE5_INT_MIP_E_OFF 6
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE4_INT_MIP_E_MSK 0x00000020
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE4_INT_MIP_E_OFF 5
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE3_INT_MIP_E_MSK 0x00000010
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE3_INT_MIP_E_OFF 4
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE2_INT_MIP_E_MSK 0x00000008
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE2_INT_MIP_E_OFF 3
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE1_INT_MIP_E_MSK 0x00000004
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE1_INT_MIP_E_OFF 2
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE0_INT_MIP_E_MSK 0x00000002
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_TX_2X_SLICE0_INT_MIP_E_OFF 1
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_CSU_INT_MIP_E_MSK          0x00000001
#define SFI51_TX_18X_GLUE_REG_MIPS_INT_EN_REG_BIT_CSU_INT_MIP_E_OFF          0

/*-------------------------------------.
 | Register 0x0000001c PCIE_INT_EN_REG |
 +-------------------------------------+
 | bit  9 R/W  TX_2X_SLICE8_INT_PCI_E  |
 | bit  8 R/W  TX_2X_SLICE7_INT_PCI_E  |
 | bit  7 R/W  TX_2X_SLICE6_INT_PCI_E  |
 | bit  6 R/W  TX_2X_SLICE5_INT_PCI_E  |
 | bit  5 R/W  TX_2X_SLICE4_INT_PCI_E  |
 | bit  4 R/W  TX_2X_SLICE3_INT_PCI_E  |
 | bit  3 R/W  TX_2X_SLICE2_INT_PCI_E  |
 | bit  2 R/W  TX_2X_SLICE1_INT_PCI_E  |
 | bit  1 R/W  TX_2X_SLICE0_INT_PCI_E  |
 | bit  0 R/W  CSU_INT_PCI_E           |
 +------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_UNUSED_MASK                0xfffffc00
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE8_INT_PCI_E_MSK 0x00000200
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE8_INT_PCI_E_OFF 9
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE7_INT_PCI_E_MSK 0x00000100
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE7_INT_PCI_E_OFF 8
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE6_INT_PCI_E_MSK 0x00000080
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE6_INT_PCI_E_OFF 7
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE5_INT_PCI_E_MSK 0x00000040
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE5_INT_PCI_E_OFF 6
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE4_INT_PCI_E_MSK 0x00000020
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE4_INT_PCI_E_OFF 5
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE3_INT_PCI_E_MSK 0x00000010
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE3_INT_PCI_E_OFF 4
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE2_INT_PCI_E_MSK 0x00000008
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE2_INT_PCI_E_OFF 3
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE1_INT_PCI_E_MSK 0x00000004
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE1_INT_PCI_E_OFF 2
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE0_INT_PCI_E_MSK 0x00000002
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_TX_2X_SLICE0_INT_PCI_E_OFF 1
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_CSU_INT_PCI_E_MSK          0x00000001
#define SFI51_TX_18X_GLUE_REG_PCIE_INT_EN_REG_BIT_CSU_INT_PCI_E_OFF          0

/*-----------------------------------------.
 | Register 0x00000020 GLOBAL_INT_STAT_REG |
 +-----------------------------------------+
 | bit  9 R  TX_2X_SLICE8_INT_V            |
 | bit  8 R  TX_2X_SLICE7_INT_V            |
 | bit  7 R  TX_2X_SLICE6_INT_V            |
 | bit  6 R  TX_2X_SLICE5_INT_V            |
 | bit  5 R  TX_2X_SLICE4_INT_V            |
 | bit  4 R  TX_2X_SLICE3_INT_V            |
 | bit  3 R  TX_2X_SLICE2_INT_V            |
 | bit  2 R  TX_2X_SLICE1_INT_V            |
 | bit  1 R  TX_2X_SLICE0_INT_V            |
 | bit  0 R  CSU_INT_V                     |
 +----------------------------------------*/
#define PMC_SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_UNUSED_MASK            0xfffffc00
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE8_INT_V_MSK 0x00000200
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE8_INT_V_OFF 9
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE7_INT_V_MSK 0x00000100
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE7_INT_V_OFF 8
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE6_INT_V_MSK 0x00000080
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE6_INT_V_OFF 7
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE5_INT_V_MSK 0x00000040
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE5_INT_V_OFF 6
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE4_INT_V_MSK 0x00000020
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE4_INT_V_OFF 5
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE3_INT_V_MSK 0x00000010
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE3_INT_V_OFF 4
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE2_INT_V_MSK 0x00000008
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE2_INT_V_OFF 3
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE1_INT_V_MSK 0x00000004
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE1_INT_V_OFF 2
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE0_INT_V_MSK 0x00000002
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_TX_2X_SLICE0_INT_V_OFF 1
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_CSU_INT_V_MSK          0x00000001
#define SFI51_TX_18X_GLUE_REG_GLOBAL_INT_STAT_REG_BIT_CSU_INT_V_OFF          0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SFI51_TX_18X_SERDES_GLUE_REGS_H */
