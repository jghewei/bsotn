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
 *     Contains base address definitions for the empei_wrap_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml/lw30_82_37_map.xml
 *     block_uri "file:../docs/rda/lw30_82_37_map.xml"
 *     block_part_number "LW30_82_37"
 *     block_mnemonic "EMPEI120_WRAP"
 * 
 *****************************************************************************/
#ifndef _EMPEI_WRAP_MTSB_MAP_H
#define _EMPEI_WRAP_MTSB_MAP_H


/*
 * ==================================================================================
 *                       EMPEI_WRAP_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define EMPEI_WRAP_MTSB_MAP_FILE_NAME    "../src/ioxml/lw30_82_37_map.xml"
#define EMPEI_WRAP_MTSB_MAP_FILE_VERSION "../src/ioxml/lw30_82_37_map.xml"
/*
 * ==================================================================================
 *                       EMPEI_WRAP_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef EMPEI_WRAP_MTSB_TSB_BASE_ADDR_DEFS_H
#define EMPEI_WRAP_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_EMPEI120_WRAP_MTSB                 0x00000000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_I_MTSB      0x00000000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_I           0x00000000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_I_ECLASS120 0x00004000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_E_MTSB      0x00008000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_E           0x00008000
#define BASE_ADDR_EMPEI120_WRAP_EMPEI120_E_ECLASS120 0x0000c000

#endif /* EMPEI_WRAP_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _EMPEI_WRAP_MTSB_MAP_H */