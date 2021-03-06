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
 *     Contains base address definitions for the s16_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm55_82_50_apb_bridge.xml
 *     block_uri "file:pm55_82_50_apb_bridge.xml"
 *     block_part_number "PM55_82_50"
 *     block_mnemonic "PM55_82_50_BRIDGE"
 * 
 *****************************************************************************/
#ifndef _S16_MTSB_MAP_H
#define _S16_MTSB_MAP_H


/*
 * ==================================================================================
 *                          S16_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define S16_MTSB_MAP_FILE_NAME    "../src/ioxml-filtered/pm55_82_50_apb_bridge.xml"
#define S16_MTSB_MAP_FILE_VERSION "../src/ioxml-filtered/pm55_82_50_apb_bridge.xml"
/*
 * ==================================================================================
 *                          S16_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef S16_MTSB_TSB_BASE_ADDR_DEFS_H
#define S16_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_PM55_82_50_BRIDGE_MTSB                          0x00000000
#define BASE_ADDR_PM55_82_50_BRIDGE_CHANNEL_PCBI_PCBI             0x00000000
#define BASE_ADDR_PM55_82_50_BRIDGE_TITAN_BR2_MDSP_TITAN_BR2_DIGI 0x00000200
#define BASE_ADDR_PM55_82_50_BRIDGE_ADAPT_DSP_16_ADSP             0x00000300
#define BASE_ADDR_PM55_82_50_BRIDGE_MTSB_CTRL_PCBI                0x00000400
#define BASE_ADDR_PM55_82_50_BRIDGE_CSU_PCBI_PCBI                 0x00000500
#define BASE_ADDR_PM55_82_50_BRIDGE_ACB_PCBI_ACB_FT               0x00000600

#endif /* S16_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _S16_MTSB_MAP_H */
