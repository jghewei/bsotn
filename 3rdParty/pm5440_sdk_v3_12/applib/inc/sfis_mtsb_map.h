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
 *     Contains base address definitions for the sfis_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm55_82_10_map.xml
 *     block_uri "file:../docs/rda/pm55_20_12_map.xml"
 *     block_part_number "PM55_20_12"
 *     block_mnemonic "SFIS"
 * 
 *****************************************************************************/
#ifndef _SFIS_MTSB_MAP_H
#define _SFIS_MTSB_MAP_H


/*
 * ==================================================================================
 *                          SFIS_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define SFIS_MTSB_MAP_FILE_NAME    "../src/ioxml-filtered/pm55_82_10_map.xml"
#define SFIS_MTSB_MAP_FILE_VERSION "../src/ioxml-filtered/pm55_82_10_map.xml"
/*
 * ==================================================================================
 *                          SFIS_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef SFIS_MTSB_TSB_BASE_ADDR_DEFS_H
#define SFIS_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_LINEOTN_SS_OTN_MLD_SFIS_MTSB(A)     (0x00016000 + (A) * 0x1000)
#define MAX_LINEOTN_SS_OTN_MLD_SFIS_MTSB              3
#define BASE_ADDR_LINEOTN_SS_OTN_MLD_SFIS_SFIS_RX(A)  (0x00016000 + (A) * 0x1000)
#define MAX_LINEOTN_SS_OTN_MLD_SFIS_SFIS_RX           3
#define BASE_ADDR_LINEOTN_SS_OTN_MLD_SFIS_SFIS_TX(A)  (0x00016080 + (A) * 0x1000)
#define MAX_LINEOTN_SS_OTN_MLD_SFIS_SFIS_TX           3

#endif /* SFIS_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _SFIS_MTSB_MAP_H */
