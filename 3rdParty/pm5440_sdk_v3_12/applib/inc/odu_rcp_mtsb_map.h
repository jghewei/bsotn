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
 *     Contains base address definitions for the odu_rcp_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm55_82_09_ad_map.xml
 *     block_uri "file:../docs/rda/pm55_60_20_map.xml"
 *     block_part_number "PM55_60_20"
 *     block_mnemonic "ODU_RCP"
 * 
 *****************************************************************************/
#ifndef _ODU_RCP_MTSB_MAP_H
#define _ODU_RCP_MTSB_MAP_H


/*
 * ==================================================================================
 * ODU_RCP_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define ODU_RCP_MTSB_MAP_FILE_NAME    "../src/ioxml-filtered/pm55_82_09_ad_map.xml"
#define ODU_RCP_MTSB_MAP_FILE_VERSION "../src/ioxml-filtered/pm55_82_09_ad_map.xml"
/*
 * ==================================================================================
 * ODU_RCP_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef ODU_RCP_MTSB_TSB_BASE_ADDR_DEFS_H
#define ODU_RCP_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_COREOTN120_ODU_RCP_MTSB                               0x001c0000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_RCP_ODU_RCP                     0x001c0000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_MTSB             0x001c4000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_TOP_ENET_FEGE    0x001c4000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_L1RPP_FEGE       0x001c4080
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_RMAC             0x001c4100
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_RX_ECLASS_ECLASS 0x001c4800
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_MSTATX           0x001c5000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_TX_ECLASS_ECLASS 0x001c5800
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_TMAC             0x001c6000
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_L1TPP_FEGE       0x001c6040
#define BASE_ADDR_COREOTN120_ODU_RCP_RI_FEGE_ENET_FEGE_GE_GFPT          0x001c6100
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_RCP_ODU_RCP                     0x001c8000
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_MTSB             0x001cc000
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_TOP_ENET_FEGE    0x001cc000
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_L1RPP_FEGE       0x001cc080
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_RMAC             0x001cc100
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_RX_ECLASS_ECLASS 0x001cc800
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_MSTATX           0x001cd000
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_TX_ECLASS_ECLASS 0x001cd800
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_TMAC             0x001ce000
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_L1TPP_FEGE       0x001ce040
#define BASE_ADDR_COREOTN120_ODU_RCP_DI_FEGE_ENET_FEGE_GE_GFPT          0x001ce100

#endif /* ODU_RCP_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _ODU_RCP_MTSB_MAP_H */