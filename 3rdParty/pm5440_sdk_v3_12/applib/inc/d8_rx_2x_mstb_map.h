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
 *     Contains base address definitions for the d8_rx_2x_mstb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm55_82_53_map.xml
 *     block_uri "file:../docs/rda"
 *     block_part_number "pm55_82_53_A"
 *     block_mnemonic "SFI5_1_RX_2X_SERDES_SLICE"
 * 
 *****************************************************************************/
#ifndef _D8_RX_2X_MSTB_MAP_H
#define _D8_RX_2X_MSTB_MAP_H


/*
 * ==================================================================================
 * D8_RX_2X_MSTB RDA XML Version Info
 * ==================================================================================
 */
#define D8_RX_2X_MSTB_MAP_FILE_NAME    "../src/ioxml-filtered/pm55_82_53_map.xml"
#define D8_RX_2X_MSTB_MAP_FILE_VERSION "../src/ioxml-filtered/pm55_82_53_map.xml"
/*
 * ==================================================================================
 * D8_RX_2X_MSTB Block Base Addresses
 * ==================================================================================
 */
#ifndef D8_RX_2X_MSTB_TSB_BASE_ADDR_DEFS_H
#define D8_RX_2X_MSTB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_SFI5_1_RX_2X_SERDES_SLICE_MTSB                             0x00000000
#define BASE_ADDR_SFI5_1_RX_2X_SERDES_SLICE_SFI51_RX_2X_SLICE                0x00000000
#define BASE_ADDR_SFI5_1_RX_2X_SERDES_SLICE_DELTA8_40NM_CDRU_DELTA8_CDRU(A)  (0x00000200 + (A) * 0x40)
#define MAX_SFI5_1_RX_2X_SERDES_SLICE_DELTA8_40NM_CDRU_DELTA8_CDRU           1

#endif /* D8_RX_2X_MSTB_TSB_BASE_ADDR_DEFS_H */
#endif /* _D8_RX_2X_MSTB_MAP_H */
