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
 *     and register accessor functions for the sample_mtsb block
 * 
 *   NOTES:
 *     This file is generated by the script codegen.pm, version 1.1
 *     Do not modify this file.
 * 
 *     The input file is ../src/ioxml/pm1234_map.xml
 *     block_uri "file:../docs/rda/pm1001_reg.xml"
 *     block_part_number "PM1234"
 *     block_mnemonic "SAMPLE_MTSB"
 * 
 *****************************************************************************/

/*--------------------------------------------------------------------------------.
 | The pattern for accessing sample_mtsb io functions is:
 | {
 |     sample_mtsb_buffer_t b[1];
 |     sample_mtsb_buffer_init( b, h );
 |     value = sample_mtsb_field_<FIELD>_get( b, h );
 |     sample_mtsb_field_<FIELD>_set( b, h , value );
 | ...
 |     sample_mtsb_buffer_flush( b );
 | }
 | 
 | alternatively, if register coalescing is not needed then omit the buffer like:
 | 
 | value = sample_mtsb_field_<FIELD>_get( NULL, h );
 | sample_mtsb_field_<FIELD>_set( NULL, h , value );
 | 
 +-------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | 
 | +---------------------------------+
 | | Register 0x00000000 MTSB_CONFIG |
 | +---------------------------------+
 | | bit  0 R/W  CORE_ENABLE         |
 | | bit  1 R/W  PMON_BUSY           |
 | | bit  2 R/W  INT_EN              |
 | +---------------------------------+
 | 
 | void      sample_mtsb_field_CORE_ENABLE_set    ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | UINT32    sample_mtsb_field_CORE_ENABLE_get    ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | void      sample_mtsb_field_PMON_BUSY_set      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | UINT32    sample_mtsb_field_PMON_BUSY_get      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | PMC_ERROR sample_mtsb_field_PMON_BUSY_poll_bit ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | void      sample_mtsb_field_INT_EN_set         ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | UINT32    sample_mtsb_field_INT_EN_get         ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | 
 | +--------------------------------------------------+
 | | Register (0x00000100 + (N) * 0x4) CHANNEL_CONFIG |
 | |     N[0..511]                                    |
 | +--------------------------------------------------+
 | | bit  0     R/W  CHANNEL_ENABLE                   |
 | | bit  8:1   R/W  CHANNEL_MAP                      |
 | | bit  9     R/W  OH_INSERT_ENABLE                 |
 | | bit  17:10 R/W  OH_INSERT_BYTE                   |
 | | bit  25:18 R    OH_EXTRACT_BYTE                  |
 | +--------------------------------------------------+
 | 
 | void   sample_mtsb_field_CHANNEL_ENABLE_set        ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 value )
 | UINT32 sample_mtsb_field_CHANNEL_ENABLE_get        ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | void   sample_mtsb_field_CHANNEL_MAP_set           ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 value )
 | UINT32 sample_mtsb_field_CHANNEL_MAP_get           ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | void   sample_mtsb_field_range_CHANNEL_MAP_set     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 sample_mtsb_field_range_CHANNEL_MAP_get     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 start_bit, UINT32 stop_bit )
 | void   sample_mtsb_field_OH_INSERT_ENABLE_set      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 value )
 | UINT32 sample_mtsb_field_OH_INSERT_ENABLE_get      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | void   sample_mtsb_field_OH_INSERT_BYTE_set        ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 value )
 | UINT32 sample_mtsb_field_OH_INSERT_BYTE_get        ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | void   sample_mtsb_field_range_OH_INSERT_BYTE_set  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 sample_mtsb_field_range_OH_INSERT_BYTE_get  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 sample_mtsb_field_OH_EXTRACT_BYTE_get       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | UINT32 sample_mtsb_field_range_OH_EXTRACT_BYTE_get ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-------------------------------------------------------+
 | | Register (0x00001000 + (N) * 0x4) CHANNEL_SOP_COUNTER |
 | |     N[0..511]                                         |
 | +-------------------------------------------------------+
 | | bit  31:0 R  SOP_COUNTER                              |
 | +-------------------------------------------------------+
 | 
 | void   sample_mtsb_lfield_SOP_COUNTER_get       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[512] )
 | UINT32 sample_mtsb_lfield_range_SOP_COUNTER_get ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +--------------------------------------------------------+
 | | Register (0x00002000 + (N) * 0x4) CHANNEL_BYTE_COUNTER |
 | |     N[0..511]                                          |
 | +--------------------------------------------------------+
 | | bit  31:0 R  BYTE_COUNTER                              |
 | +--------------------------------------------------------+
 | 
 | void   sample_mtsb_lfield_BYTE_COUNTER_get       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[512] )
 | UINT32 sample_mtsb_lfield_range_BYTE_COUNTER_get ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-------------------------------------+
 | | Register 0x00003000 OH_FF_INT_REG_0 |
 | +-------------------------------------+
 | | bit  31:0 R/W  OH_FF_I              |
 | +-------------------------------------+
 | 
 | void      sample_mtsb_lfield_OH_FF_I_set_to_clear       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[2] )
 | void      sample_mtsb_lfield_OH_FF_I_get                ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[2] )
 | void      sample_mtsb_lfield_range_OH_FF_I_set_to_clear ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32    sample_mtsb_lfield_range_OH_FF_I_get          ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit )
 | PMC_ERROR sample_mtsb_lfield_OH_FF_I_poll_bit           ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[2], UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | +----------------------------------------+
 | | Register 0x00003008 OH_FF_INT_EN_REG_0 |
 | +----------------------------------------+
 | | bit  31:0 R/W  OH_FF_E                 |
 | +----------------------------------------+
 | 
 | void   sample_mtsb_lfield_OH_FF_E_set       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[2] )
 | void   sample_mtsb_lfield_OH_FF_E_get       ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value[2] )
 | void   sample_mtsb_lfield_range_OH_FF_E_set ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 sample_mtsb_lfield_range_OH_FF_E_get ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 start_bit, UINT32 stop_bit )
 +----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef _SAMPLE_MTSB_IO_H
#define _SAMPLE_MTSB_IO_H

#include "sample_mtsb_loc.h"
#include "pmc_sys.h"
#include "pmc_types.h"
#include "sample_mtsb_regs.h"
#include "sample_mtsb_io_inline.h"


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | TSB access functions
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | These functions do not need to be accessed directly,... just included here for completeness.
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | void      sample_mtsb_buffer_init               ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | void      sample_mtsb_buffer_flush              ( sample_mtsb_buffer_t *b )
 | UINT32    sample_mtsb_reg_read                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg )
 | void      sample_mtsb_reg_write                 ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 value )
 | void      sample_mtsb_field_set                 ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 ofs, UINT32 value )
 | void      sample_mtsb_action_on_write_field_set ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 ofs, UINT32 value )
 | void      sample_mtsb_burst_read                ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | void      sample_mtsb_burst_write               ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | PMC_ERROR sample_mtsb_poll_bit                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 +-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | Functions to Access Registers
 +---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | These functions can be used if for some reason the field getters & setters are not appropriate.
 +---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | void      sample_mtsb_reg_MTSB_CONFIG_write                         ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | void      sample_mtsb_reg_MTSB_CONFIG_field_set                     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_MTSB_CONFIG_read                          ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | PMC_ERROR sample_mtsb_reg_MTSB_CONFIG_poll_bit                      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | void      sample_mtsb_reg_CHANNEL_CONFIG_array_write                ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 value )
 | void      sample_mtsb_reg_CHANNEL_CONFIG_array_field_set            ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_CHANNEL_CONFIG_array_read                 ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32  N )
 | 
 | void      sample_mtsb_reg_OH_FF_INT_EN_REG_0_write                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | void      sample_mtsb_reg_OH_FF_INT_EN_REG_0_field_set              ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_OH_FF_INT_EN_REG_0_read                   ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | 
 | void      sample_mtsb_reg_OH_FF_INT_EN_REG_1_write                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | void      sample_mtsb_reg_OH_FF_INT_EN_REG_1_field_set              ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_OH_FF_INT_EN_REG_1_read                   ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | 
 | void      sample_mtsb_reg_OH_FF_INT_REG_0_write                     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | void      sample_mtsb_reg_OH_FF_INT_REG_0_action_on_write_field_set ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_OH_FF_INT_REG_0_read                      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | PMC_ERROR sample_mtsb_reg_OH_FF_INT_REG_0_poll_bit                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | void      sample_mtsb_reg_OH_FF_INT_REG_1_write                     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 value )
 | void      sample_mtsb_reg_OH_FF_INT_REG_1_action_on_write_field_set ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32    sample_mtsb_reg_OH_FF_INT_REG_1_read                      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h )
 | PMC_ERROR sample_mtsb_reg_OH_FF_INT_REG_1_poll_bit                  ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 mask, UINT32 value, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | void      sample_mtsb_reg_CHANNEL_SOP_COUNTER_array_burst_read      ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 ofs, UINT32 len, UINT32 *value )
 | UINT32    sample_mtsb_reg_CHANNEL_SOP_COUNTER_array_read            ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 N )
 | 
 | void      sample_mtsb_reg_CHANNEL_BYTE_COUNTER_array_burst_read     ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 ofs, UINT32 len, UINT32 *value )
 | UINT32    sample_mtsb_reg_CHANNEL_BYTE_COUNTER_array_read           ( sample_mtsb_buffer_t *b, sample_mtsb_handle_t *h, UINT32 N )
 | 
 +--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif /* _SAMPLE_MTSB_IO_H */
