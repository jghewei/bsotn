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
 *     contains prototypes for the field accessor functions
 *     and register accessor functions for the tsb2 block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml/pm1234_map.xml
 *     block_uri "file:../docs/rda/pm1002_reg.xml"
 *     block_part_number "PM1002"
 *     block_mnemonic "TSB2"
 * 
 *****************************************************************************/

/*--------------------------------------------------------------------------------.
 | The pattern for accessing tsb2 io functions is:
 | {
 |     tsb2_buffer_t b[1];
 |     tsb2_buffer_init( b, h, A );
 |     value = tsb2_field_<FIELD>_get( b, h, A );
 |     tsb2_field_<FIELD>_set( b, h, A , value );
 | ...
 |     tsb2_buffer_flush( b );
 | }
 | 
 | alternatively, if register coalescing is not needed then omit the buffer like:
 | 
 | value = tsb2_field_<FIELD>_get( NULL, h, A );
 | tsb2_field_<FIELD>_set( NULL, h, A , value );
 | 
 +-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------------------------------------------.
 | 
 | +----------------------------+
 | | Register 0x00020100 CONFIG |
 | +----------------------------+
 | | bit  0   R/W  CFG_A        |
 | | bit  1   R/W  CFG_B        |
 | | bit  3:2 R/W  CFG_C        |
 | | bit  7:4 R/W  CFG_D        |
 | +----------------------------+
 | 
 | void   tsb2_field_CFG_A_set       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 value )
 | UINT32 tsb2_field_CFG_A_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | void   tsb2_field_CFG_B_set       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 value )
 | UINT32 tsb2_field_CFG_B_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | void   tsb2_field_CFG_C_set       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 value )
 | UINT32 tsb2_field_CFG_C_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | void   tsb2_field_range_CFG_C_set ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 tsb2_field_range_CFG_C_get ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   tsb2_field_CFG_D_set       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 value )
 | UINT32 tsb2_field_CFG_D_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | void   tsb2_field_range_CFG_D_set ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 tsb2_field_range_CFG_D_get ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +----------------------------+
 | | Register 0x00020104 STATUS |
 | +----------------------------+
 | | bit  0   R  STS_A          |
 | | bit  1   R  STS_B          |
 | | bit  3:2 R  STS_C          |
 | | bit  7:4 R  STS_D          |
 | +----------------------------+
 | 
 | UINT32 tsb2_field_STS_A_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | UINT32 tsb2_field_STS_B_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | UINT32 tsb2_field_STS_C_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | UINT32 tsb2_field_range_STS_C_get ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 tsb2_field_STS_D_get       ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | UINT32 tsb2_field_range_STS_D_get ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 +-----------------------------------------------------------------------------------------------------------------------------------*/
#ifndef _TSB2_IO_H
#define _TSB2_IO_H

#include "pmc_sys.h"
#include "pmc_types.h"
#include "tsb2_regs.h"
#include "tsb2_io_inline.h"


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | TSB access functions
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | These functions do not need to be accessed directly,... just included here for completeness.
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | void      tsb2_buffer_init               ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | void      tsb2_buffer_flush              ( tsb2_buffer_t *b )
 | UINT32    tsb2_reg_read                  ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg )
 | void      tsb2_reg_write                 ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 value )
 | void      tsb2_field_set                 ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 ofs, UINT32 value )
 | void      tsb2_action_on_write_field_set ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 ofs, UINT32 value )
 | void      tsb2_burst_read                ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | void      tsb2_burst_write               ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | PMC_ERROR tsb2_poll_bit                  ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------.
 | Functions to Access Registers
 +-------------------------------------------------------------------------------------------------------------------------+
 | These functions can be used if for some reason the field getters & setters are not appropriate.
 +-------------------------------------------------------------------------------------------------------------------------+
 | void   tsb2_reg_CONFIG_write     ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 value )
 | void   tsb2_reg_CONFIG_field_set ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32 tsb2_reg_CONFIG_read      ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | 
 | UINT32 tsb2_reg_STATUS_read      ( tsb2_buffer_t *b, pmc_handle_t *h, UINT32 A )
 | 
 +------------------------------------------------------------------------------------------------------------------------*/
#endif /* _TSB2_IO_H */
