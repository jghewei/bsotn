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
 *     Contains base address definitions for the sample_mtsb_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml/pm1234_map.xml
 *     block_uri "file:../docs/rda/pm1234_map.xml"
 *     block_part_number "PM1234"
 *     block_mnemonic "SAMPLE_MTSB"
 * 
 *****************************************************************************/
#ifndef _SAMPLE_MTSB_MTSB_MAP_H
#define _SAMPLE_MTSB_MTSB_MAP_H


/*
 * ==================================================================================
 *                      SAMPLE_MTSB_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define SAMPLE_MTSB_MTSB_MAP_FILE_NAME    "../src/ioxml/pm1234_map.xml"
#define SAMPLE_MTSB_MTSB_MAP_FILE_VERSION "../src/ioxml/pm1234_map.xml"
/*
 * ==================================================================================
 *                      SAMPLE_MTSB_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef SAMPLE_MTSB_MTSB_TSB_BASE_ADDR_DEFS_H
#define SAMPLE_MTSB_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_SAMPLE_MTSB_MTSB                    0x00000000
#define BASE_ADDR_SAMPLE_MTSB                         0x00000000
#define BASE_ADDR_SAMPLE_MTSB_TSB1                    0x00010000
#define BASE_ADDR_SAMPLE_MTSB_TSB2(A)                 (0x00011000 + (A) * 0x100)
#define MAX_SAMPLE_MTSB_TSB2                          3
#define BASE_ADDR_SAMPLE_MTSB_MTSB2_SAMPLE_MTSB2_MTSB 0x00020000
#define BASE_ADDR_SAMPLE_MTSB_MTSB2_SAMPLE_MTSB2_TSB1 0x00020000
#define BASE_ADDR_SAMPLE_MTSB_MTSB2_SAMPLE_MTSB2_TSB2 0x00020100

#endif /* SAMPLE_MTSB_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _SAMPLE_MTSB_MTSB_MAP_H */
