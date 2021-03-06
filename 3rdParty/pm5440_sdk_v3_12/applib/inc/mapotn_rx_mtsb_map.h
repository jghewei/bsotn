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
 *     Contains base address definitions for the mapotn_rx_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml-filtered/pm55_82_08_ad_map.xml
 *     block_uri "file:../docs/rda/pm55_82_38_ad_map.xml"
 *     block_part_number "PM55_82_38"
 *     block_mnemonic "MAPOTN_RX"
 * 
 *****************************************************************************/
#ifndef _MAPOTN_RX_MTSB_MAP_H
#define _MAPOTN_RX_MTSB_MAP_H


/*
 * ==================================================================================
 * MAPOTN_RX_MTSB RDA XML Version Info
 * ==================================================================================
 */
#define MAPOTN_RX_MTSB_MAP_FILE_NAME    "../src/ioxml-filtered/pm55_82_08_ad_map.xml"
#define MAPOTN_RX_MTSB_MAP_FILE_VERSION "../src/ioxml-filtered/pm55_82_08_ad_map.xml"
/*
 * ==================================================================================
 * MAPOTN_RX_MTSB Block Base Addresses
 * ==================================================================================
 */
#ifndef MAPOTN_RX_MTSB_TSB_BASE_ADDR_DEFS_H
#define MAPOTN_RX_MTSB_TSB_BASE_ADDR_DEFS_H

#define BASE_ADDR_MAPOTN_MAPOTN_RX_MTSB                                         0x00000000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MAPOTN_RX_TOP_MTSB                           0x00000000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MAPOTN_RX_TOP_MAPOTN_RX_REG                  0x00000000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MAPOTN_RX_TOP_INT_SUMMARY_MAPOTN_RX_TOP_ISUM 0x00005000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_MTSB                                  0x00010000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_RGMP96_CORE                           0x00010000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_INT_SUMRY_RGMP96_ISUM                 0x00010530
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_OHFS_REMOVE                           0x00012000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_RXJC_PROC                             0x00014000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_CPACT_OBUF                            0x00015000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGMP96_MP_MGEN                               0x00016000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_MTSB                                 0x00020000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_OHFS_REMOVE                          0x00020000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_UNPACK_CFC_CFC                       0x00024000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_EGRESS_CFC_CFC                       0x00028000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_RGFPF96_CORE                         0x00030000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_RGFPF96_INT_SUMMARY_RGFPF96_ISUM             0x0003a000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MTSB                                    0x00040000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MPMA_DP_MTSB                            0x00040000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MPMA_DP_CORE                            0x00040000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MPMA_DP_CFC                             0x00041000
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MPMA_DP_SCBS3                           0x00042800
#define BASE_ADDR_MAPOTN_MAPOTN_RX_MPMA_MPMA_DSP                                0x00043800

#endif /* MAPOTN_RX_MTSB_TSB_BASE_ADDR_DEFS_H */
#endif /* _MAPOTN_RX_MTSB_MAP_H */
