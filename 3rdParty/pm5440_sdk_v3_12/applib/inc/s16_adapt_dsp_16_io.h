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
 *     contains prototypes for the field accessor functions
 *     and register accessor functions for the s16_adapt_dsp_16 block
 *****************************************************************************/

/*--------------------------------------------------------------------------------.
 | The pattern for accessing s16_adapt_dsp_16 io functions is:
 | {
 |     s16_adapt_dsp_16_buffer_t b_ptr[1];
 |     s16_adapt_dsp_16_buffer_init( b_ptr, h_ptr, A );
 |     value = s16_adapt_dsp_16_field_<FIELD>_get( b_ptr, h_ptr, A );
 |     s16_adapt_dsp_16_field_<FIELD>_set( b_ptr, h_ptr, A , value );
 | ...
 |     s16_adapt_dsp_16_buffer_flush( b_ptr );
 | }
 | 
 | alternatively, if register coalescing is not needed then omit the buffer like:
 | 
 | value = s16_adapt_dsp_16_field_<FIELD>_get( NULL, h_ptr, A );
 | s16_adapt_dsp_16_field_<FIELD>_set( NULL, h_ptr, A , value );
 | 
 +-------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | 
 | +----------------------------------------+
 | | Register 0x00000300 ADAPT_DSP_CLK_CTRL |
 | +----------------------------------------+
 | | bit  0 R/W  ADAPT_CLK_ENB              |
 | +----------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_ADAPT_CLK_ENB_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_CLK_ENB_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +----------------------------------+
 | | Register 0x00000304 ADAPT_CTRL_1 |
 | +----------------------------------+
 | | bit  18   R/W  ADAPT_START       |
 | | bit  17   R/W  EQ_ADAPT_CTRL_ENB |
 | | bit  15   R/W  INV_DFE_OUT       |
 | | bit  14   R/W  ADAPT_INITB       |
 | | bit  11   R/W  PRELOAD_ENB       |
 | | bit  10:8 R/W  ADAPT_DELAY       |
 | | bit  7:4  R/W  ADAPT_LOOPS       |
 | | bit  3    R/W  ADAPT_ENB         |
 | +----------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_EQ_ADAPT_CTRL_ENB_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_EQ_ADAPT_CTRL_ENB_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_INV_DFE_OUT_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_INV_DFE_OUT_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_ADAPT_INITB_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_INITB_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_PRELOAD_ENB_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PRELOAD_ENB_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_ADAPT_DELAY_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_DELAY_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_ADAPT_DELAY_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_ADAPT_DELAY_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_ADAPT_LOOPS_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_LOOPS_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_ADAPT_LOOPS_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_ADAPT_LOOPS_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_ADAPT_ENB_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_ENB_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_ADAPT_START_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_START_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +----------------------------------+
 | | Register 0x00000308 ADAPT_CTRL_2 |
 | +----------------------------------+
 | | bit  17:0 R/W  LMS_DATA_SEL      |
 | +----------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_LMS_DATA_SEL_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_LMS_DATA_SEL_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_LMS_DATA_SEL_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_LMS_DATA_SEL_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +----------------------------------+
 | | Register 0x0000030c ADAPT_CTRL_3 |
 | +----------------------------------+
 | | bit  17:0 R/W  OBJECTS_EN        |
 | +----------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_OBJECTS_EN_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_OBJECTS_EN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_OBJECTS_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_OBJECTS_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------------------+
 | | Register 0x00000310 ADAPT_STAT              |
 | +---------------------------------------------+
 | | bit  17:1 R    ADAPT_STATUS                 |
 | | bit  0    R/W  CAPTURE_ADAPT_STATUS_REQUEST |
 | +---------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_CAPTURE_ADAPT_STATUS_REQUEST_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CAPTURE_ADAPT_STATUS_REQUEST_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_ADAPT_STATUS_get                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_ADAPT_STATUS_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------------------------+
 | | Register 0x00000314 ADAPT_RESULTS_CAPTURE_REQUEST |
 | +---------------------------------------------------+
 | | bit  0 R/W  CAPTURE_RESULTS_REQUEST               |
 | +---------------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_CAPTURE_RESULTS_REQUEST_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CAPTURE_RESULTS_REQUEST_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +---------------------------------------------+
 | | Register 0x00000318 ADAPT_RESULTS_CAPTURE_1 |
 | +---------------------------------------------+
 | | bit  30:26 R  TR_FFE_B                      |
 | | bit  25:21 R  TR_FFE_A                      |
 | | bit  20:14 R  DP_FFE_C                      |
 | | bit  13:7  R  DP_FFE_B                      |
 | | bit  6:0   R  DP_FFE_A                      |
 | +---------------------------------------------+
 | 
 | UINT32 s16_adapt_dsp_16_field_TR_FFE_B_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_TR_FFE_B_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_TR_FFE_A_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_TR_FFE_A_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_C_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_C_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_B_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_B_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_A_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_A_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------------------+
 | | Register 0x0000031c ADAPT_RESULTS_CAPTURE_2 |
 | +---------------------------------------------+
 | | bit  26:18 R  DFE_COEF2                     |
 | | bit  17:9  R  DFE_COEF1                     |
 | | bit  8:0   R  DFE_COEF0                     |
 | +---------------------------------------------+
 | 
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF2_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF2_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF1_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF1_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF0_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF0_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------------------+
 | | Register 0x00000320 ADAPT_RESULTS_CAPTURE_3 |
 | +---------------------------------------------+
 | | bit  26:18 R  DFE_COEF5                     |
 | | bit  17:9  R  DFE_COEF4                     |
 | | bit  8:0   R  DFE_COEF3                     |
 | +---------------------------------------------+
 | 
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF5_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF5_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF4_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF4_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF3_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF3_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------------------+
 | | Register 0x00000324 ADAPT_RESULTS_CAPTURE_4 |
 | +---------------------------------------------+
 | | bit  22:19 R  ADC_MAP_SCALE                 |
 | | bit  18:13 R  TARGET_AMP                    |
 | | bit  12:5  R  PGA_OFFSET                    |
 | | bit  4:0   R  PGA_GAIN                      |
 | +---------------------------------------------+
 | 
 | UINT32 s16_adapt_dsp_16_field_ADC_MAP_SCALE_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_ADC_MAP_SCALE_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_TARGET_AMP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_TARGET_AMP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_PGA_OFFSET_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_PGA_OFFSET_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_PGA_GAIN_get            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_PGA_GAIN_get      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +---------------------------------+
 | | Register 0x00000328 STAT_INT_EN |
 | +---------------------------------+
 | | bit  9 R/W  PROG_REF_DONE_E     |
 | | bit  8 R/W  PROG_REF_TIMEOUT_E  |
 | | bit  0 R/W  STOP_ADAPT_E        |
 | +---------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_PROG_REF_DONE_E_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PROG_REF_DONE_E_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_E_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_E_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_STOP_ADAPT_E_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_STOP_ADAPT_E_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +------------------------------------+
 | | Register 0x0000032c STAT_INT_EVENT |
 | +------------------------------------+
 | | bit  9 R/W  PROG_REF_DONE_I        |
 | | bit  8 R/W  PROG_REF_TIMEOUT_I     |
 | | bit  0 R/W  STOP_ADAPT_I           |
 | +------------------------------------+
 | 
 | void                 s16_adapt_dsp_16_field_PROG_REF_DONE_I_set_to_clear    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32               s16_adapt_dsp_16_field_PROG_REF_DONE_I_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_PROG_REF_DONE_I_poll            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | void                 s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_I_set_to_clear ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32               s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_I_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_I_poll         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | void                 s16_adapt_dsp_16_field_STOP_ADAPT_I_set_to_clear       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32               s16_adapt_dsp_16_field_STOP_ADAPT_I_get                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_STOP_ADAPT_I_poll               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | +------------------------------+
 | | Register 0x00000330 STAT_INT |
 | +------------------------------+
 | | bit  9 R  PROG_REF_DONE_V    |
 | | bit  8 R  PROG_REF_TIMEOUT_V |
 | | bit  0 R  STOP_ADAPT_V       |
 | +------------------------------+
 | 
 | UINT32               s16_adapt_dsp_16_field_PROG_REF_DONE_V_get     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_PROG_REF_DONE_V_poll    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | UINT32               s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_V_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_V_poll ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | UINT32               s16_adapt_dsp_16_field_STOP_ADAPT_V_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_field_STOP_ADAPT_V_poll       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | +--------------------------------------+
 | | Register 0x00000334 DSS_CTRL         |
 | +--------------------------------------+
 | | bit  31:28 R/W  EXPECTED_EQ2         |
 | | bit  27:24 R/W  EXPECTED_EQ1         |
 | | bit  23:16 R/W  H_LIMIT              |
 | | bit  15:8  R/W  S_LIMIT              |
 | | bit  7:2   R/W  OFL_DECAY            |
 | | bit  1     R/W  PATH_PATTERN_CHK_ENB |
 | | bit  0     R/W  DSS_ENB              |
 | +--------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_EXPECTED_EQ2_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_EXPECTED_EQ2_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_EXPECTED_EQ2_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_EXPECTED_EQ2_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_EXPECTED_EQ1_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_EXPECTED_EQ1_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_EXPECTED_EQ1_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_EXPECTED_EQ1_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_H_LIMIT_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_H_LIMIT_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_H_LIMIT_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_H_LIMIT_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_S_LIMIT_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_S_LIMIT_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_S_LIMIT_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_S_LIMIT_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_OFL_DECAY_set            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_OFL_DECAY_get            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_OFL_DECAY_set      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_OFL_DECAY_get      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_PATH_PATTERN_CHK_ENB_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PATH_PATTERN_CHK_ENB_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DSS_ENB_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DSS_ENB_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +----------------------------------------+
 | | Register 0x00000338 DSS_TAPS_1         |
 | +----------------------------------------+
 | | bit  30    R/W  DFE_COEF5_TAP_OFL1_EN  |
 | | bit  29    R/W  DFE_COEF4_TAP_OFL1_EN  |
 | | bit  28    R/W  DFE_COEF3_TAP_OFL1_EN  |
 | | bit  27    R/W  DFE_COEF2_TAP_OFL1_EN  |
 | | bit  26    R/W  DFE_COEF1_TAP_OFL1_EN  |
 | | bit  25    R/W  DFE_COEF0_TAP_OFL1_EN  |
 | | bit  24    R/W  TARGET_AMP_TAP_OFL1_EN |
 | | bit  23:20 R/W  DFE_COEF5_TAP          |
 | | bit  19:16 R/W  DFE_COEF4_TAP          |
 | | bit  15:12 R/W  DFE_COEF3_TAP          |
 | | bit  11:8  R/W  DFE_COEF2_TAP          |
 | | bit  7:4   R/W  DFE_COEF1_TAP          |
 | | bit  3:0   R/W  DFE_COEF0_TAP          |
 | +----------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_DFE_COEF5_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF5_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF4_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF4_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF3_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF3_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF2_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF2_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF1_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF1_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF0_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF0_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_TARGET_AMP_TAP_OFL1_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TARGET_AMP_TAP_OFL1_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DFE_COEF5_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF5_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF5_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF5_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF4_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF4_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF4_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF4_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF3_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF3_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF3_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF3_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF2_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF2_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF2_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF2_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF1_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF1_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF1_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF1_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF0_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF0_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF0_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF0_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +--------------------------------+
 | | Register 0x0000033c DSS_TAPS_2 |
 | +--------------------------------+
 | | bit  3:0 R/W  GAIN_TAP         |
 | +--------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_GAIN_TAP_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_GAIN_TAP_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_GAIN_TAP_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_GAIN_TAP_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +--------------------------------------+
 | | Register 0x00000340 DSS_TAPS_3       |
 | +--------------------------------------+
 | | bit  30    R/W  TAP_OFL2_EN          |
 | | bit  29:27 R/W  TAP2                 |
 | | bit  26    R/W  DP_FFE_C_TAP_OFL1_EN |
 | | bit  25    R/W  DP_FFE_B_TAP_OFL1_EN |
 | | bit  24    R/W  DP_FFE_A_TAP_OFL1_EN |
 | | bit  23:20 R/W  DP_FFE_C_TAP         |
 | | bit  19:16 R/W  DP_FFE_B_TAP         |
 | | bit  15:12 R/W  DP_FFE_A_TAP         |
 | | bit  11:8  R/W  TARGET_AMP_TAP       |
 | | bit  7:4   R/W  ADC_TAP              |
 | | bit  3:0   R/W  OFFSET_TAP           |
 | +--------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_TAP_OFL2_EN_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TAP_OFL2_EN_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_TAP2_set                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TAP2_get                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TAP2_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TAP2_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_C_TAP_OFL1_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_C_TAP_OFL1_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DP_FFE_B_TAP_OFL1_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_B_TAP_OFL1_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DP_FFE_A_TAP_OFL1_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_A_TAP_OFL1_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DP_FFE_C_TAP_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_C_TAP_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_C_TAP_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_C_TAP_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_B_TAP_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_B_TAP_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_B_TAP_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_B_TAP_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_A_TAP_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_A_TAP_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_A_TAP_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_A_TAP_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_TARGET_AMP_TAP_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TARGET_AMP_TAP_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TARGET_AMP_TAP_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TARGET_AMP_TAP_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_ADC_TAP_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADC_TAP_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_ADC_TAP_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_ADC_TAP_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_OFFSET_TAP_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_OFFSET_TAP_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_OFFSET_TAP_set     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_OFFSET_TAP_get     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +--------------------------------------+
 | | Register 0x00000344 DSS_TAPS_4       |
 | +--------------------------------------+
 | | bit  14   R/W  FETX_POST_TAP_OFL1_EN |
 | | bit  13   R/W  FETX_CTR_TAP_OFL1_EN  |
 | | bit  12   R/W  FETX_PRE_TAP_OFL1_EN  |
 | | bit  11:8 R/W  FETX_POST_TAP         |
 | | bit  7:4  R/W  FETX_CTR_TAP          |
 | | bit  3:0  R/W  FETX_PRE_TAP          |
 | +--------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_FETX_POST_TAP_OFL1_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_POST_TAP_OFL1_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_CTR_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_CTR_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_PRE_TAP_OFL1_EN_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_PRE_TAP_OFL1_EN_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_POST_TAP_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_POST_TAP_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_POST_TAP_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_POST_TAP_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_CTR_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_CTR_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_CTR_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_CTR_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_PRE_TAP_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_PRE_TAP_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_PRE_TAP_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_PRE_TAP_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------+
 | | Register 0x00000348 LMS_MU_FACTORS |
 | +------------------------------------+
 | | bit  13   R/W  LSB_HYSTERESIS_EN   |
 | | bit  12   R/W  DELTA_H_RND_EN      |
 | | bit  11:9 R/W  MU_STEP_ADC         |
 | | bit  8:6  R/W  MU_STEP_COEF        |
 | | bit  5:3  R/W  MU_STEP_OFFSET      |
 | | bit  2:0  R/W  MU_STEP_GAIN        |
 | +------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_LSB_HYSTERESIS_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_LSB_HYSTERESIS_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_DELTA_H_RND_EN_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DELTA_H_RND_EN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_MU_STEP_ADC_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_MU_STEP_ADC_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_MU_STEP_ADC_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_MU_STEP_ADC_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_MU_STEP_COEF_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_MU_STEP_COEF_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_MU_STEP_COEF_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_MU_STEP_COEF_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_MU_STEP_OFFSET_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_MU_STEP_OFFSET_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_MU_STEP_OFFSET_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_MU_STEP_OFFSET_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_MU_STEP_GAIN_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_MU_STEP_GAIN_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_MU_STEP_GAIN_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_MU_STEP_GAIN_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-----------------------------------------+
 | | Register 0x0000034c ROUND_ROBIN_PERIODS |
 | +-----------------------------------------+
 | | bit  23:20 R/W  RR_PERIOD_FETX          |
 | | bit  19:16 R/W  RR_PERIOD_DSS           |
 | | bit  15:12 R/W  RR_PERIOD_ADC_MAP       |
 | | bit  11:8  R/W  RR_PERIOD_OFFSET        |
 | | bit  7:4   R/W  RR_PERIOD_GAIN          |
 | | bit  3:0   R/W  RR_PERIOD_COEF          |
 | +-----------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_RR_PERIOD_FETX_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_FETX_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_FETX_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_FETX_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_RR_PERIOD_DSS_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_DSS_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_DSS_set     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_DSS_get     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_RR_PERIOD_ADC_MAP_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_ADC_MAP_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_ADC_MAP_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_ADC_MAP_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_RR_PERIOD_OFFSET_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_OFFSET_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_OFFSET_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_OFFSET_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_RR_PERIOD_GAIN_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_GAIN_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_GAIN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_GAIN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_RR_PERIOD_COEF_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_RR_PERIOD_COEF_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_RR_PERIOD_COEF_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_RR_PERIOD_COEF_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000350 OBJECT_PRELOAD_VAL_1 |
 | +------------------------------------------+
 | | bit  30:26 R/W  TR_FFE_B_PRELOAD         |
 | | bit  25:21 R/W  TR_FFE_A_PRELOAD         |
 | | bit  20:14 R/W  DP_FFE_C_PRELOAD         |
 | | bit  13:7  R/W  DP_FFE_B_PRELOAD         |
 | | bit  6:0   R/W  DP_FFE_A_PRELOAD         |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_TR_FFE_B_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TR_FFE_B_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TR_FFE_B_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TR_FFE_B_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_TR_FFE_A_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TR_FFE_A_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TR_FFE_A_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TR_FFE_A_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_C_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_C_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_C_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_C_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_B_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_B_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_B_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_B_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DP_FFE_A_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DP_FFE_A_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DP_FFE_A_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DP_FFE_A_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000354 OBJECT_PRELOAD_VAL_2 |
 | +------------------------------------------+
 | | bit  26:18 R/W  DFE_COEF2_PRELOAD        |
 | | bit  17:9  R/W  DFE_COEF1_PRELOAD        |
 | | bit  8:0   R/W  DFE_COEF0_PRELOAD        |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_DFE_COEF2_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF2_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF2_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF2_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF1_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF1_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF1_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF1_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF0_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF0_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF0_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF0_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000358 OBJECT_PRELOAD_VAL_3 |
 | +------------------------------------------+
 | | bit  26:18 R/W  DFE_COEF5_PRELOAD        |
 | | bit  17:9  R/W  DFE_COEF4_PRELOAD        |
 | | bit  8:0   R/W  DFE_COEF3_PRELOAD        |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_DFE_COEF5_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF5_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF5_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF5_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF4_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF4_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF4_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF4_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_DFE_COEF3_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_DFE_COEF3_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_DFE_COEF3_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_DFE_COEF3_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x0000035c OBJECT_PRELOAD_VAL_4 |
 | +------------------------------------------+
 | | bit  22:19 R/W  ADC_MAP_PRELOAD          |
 | | bit  18:13 R/W  TARGET_AMP_PRELOAD       |
 | | bit  12:5  R/W  PGA_OFFSET_PRELOAD       |
 | | bit  4:0   R/W  PGA_GAIN_PRELOAD         |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_ADC_MAP_PRELOAD_set          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADC_MAP_PRELOAD_get          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_ADC_MAP_PRELOAD_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_ADC_MAP_PRELOAD_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_TARGET_AMP_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TARGET_AMP_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TARGET_AMP_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TARGET_AMP_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_PGA_OFFSET_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PGA_OFFSET_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_PGA_OFFSET_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_PGA_OFFSET_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_PGA_GAIN_PRELOAD_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PGA_GAIN_PRELOAD_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_PGA_GAIN_PRELOAD_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_PGA_GAIN_PRELOAD_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000360 OBJECT_PRELOAD_VAL_5 |
 | +------------------------------------------+
 | | bit  20:14 R/W  FETX_POST_PRELOAD        |
 | | bit  13:7  R/W  FETX_CTR_PRELOAD         |
 | | bit  6:0   R/W  FETX_PRE_PRELOAD         |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_FETX_POST_PRELOAD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_POST_PRELOAD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_POST_PRELOAD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_POST_PRELOAD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_CTR_PRELOAD_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_CTR_PRELOAD_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_CTR_PRELOAD_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_CTR_PRELOAD_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_PRE_PRELOAD_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_PRE_PRELOAD_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_PRE_PRELOAD_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_PRE_PRELOAD_get  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000364 CLIP_RATE_MON_PARAMS |
 | +------------------------------------------+
 | | bit  19    R/W  PROG_REF_OVR_EN          |
 | | bit  18    R/W  PROG_REF_OVR             |
 | | bit  17:14 R/W  PROG_REF_TIMEOUT_PERIOD  |
 | | bit  13:11 R/W  CLIP_RATE_THRESH         |
 | | bit  10:5  R/W  CLIP_RATE_AMP            |
 | | bit  4:2   R/W  GAIN_OFFSET              |
 | | bit  1:0   R/W  ADC_OFFSET               |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_PROG_REF_OVR_EN_set               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PROG_REF_OVR_EN_get               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_PROG_REF_OVR_set                  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PROG_REF_OVR_get                  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_PERIOD_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_PROG_REF_TIMEOUT_PERIOD_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_PROG_REF_TIMEOUT_PERIOD_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_PROG_REF_TIMEOUT_PERIOD_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_CLIP_RATE_THRESH_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CLIP_RATE_THRESH_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_CLIP_RATE_THRESH_set        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_CLIP_RATE_THRESH_get        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_CLIP_RATE_AMP_set                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CLIP_RATE_AMP_get                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_CLIP_RATE_AMP_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_CLIP_RATE_AMP_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_GAIN_OFFSET_set                   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_GAIN_OFFSET_get                   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_GAIN_OFFSET_set             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_GAIN_OFFSET_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_ADC_OFFSET_set                    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_ADC_OFFSET_get                    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_ADC_OFFSET_set              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_ADC_OFFSET_get              ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-----------------------------------------------+
 | | Register 0x00000368 CLIP_RATE_MON_ADC_RESULTS |
 | +-----------------------------------------------+
 | | bit  9   R/W  CAPTURE_GAIN_CLIP_FLAG_REQUEST  |
 | | bit  7:2 R    CLIP_FLAG_ADC                   |
 | | bit  0   R/W  CAPTURE_ADC_CLIP_FLAGS_REQUEST  |
 | +-----------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_CAPTURE_GAIN_CLIP_FLAG_REQUEST_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CAPTURE_GAIN_CLIP_FLAG_REQUEST_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_CAPTURE_ADC_CLIP_FLAGS_REQUEST_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CAPTURE_ADC_CLIP_FLAGS_REQUEST_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_CLIP_FLAG_ADC_get                  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_CLIP_FLAG_ADC_get            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +----------------------------------------------------+
 | | Register 0x0000036c CLIP_RATE_MON_PGA_GAIN_RESULTS |
 | +----------------------------------------------------+
 | | bit  31:0 R  CLIP_FLAG_GAIN                        |
 | +----------------------------------------------------+
 | 
 | UINT32 s16_adapt_dsp_16_field_CLIP_FLAG_GAIN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_CLIP_FLAG_GAIN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-------------------------------------+
 | | Register 0x00000370 ADAPT_FORCE_VAL |
 | +-------------------------------------+
 | | bit  17:0 R/W  FORCE_ADAPT_VALUE_EN |
 | +-------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_FORCE_ADAPT_VALUE_EN_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FORCE_ADAPT_VALUE_EN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FORCE_ADAPT_VALUE_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FORCE_ADAPT_VALUE_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------+
 | | Register 0x00000374 FETX_TTIU_CTRL |
 | +------------------------------------+
 | | bit  17:0 R/W  TTIU_REJECT_EN      |
 | +------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_TTIU_REJECT_EN_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TTIU_REJECT_EN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TTIU_REJECT_EN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TTIU_REJECT_EN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +-----------------------------------------+
 | | Register 0x00000378 FETX_CTRL           |
 | +-----------------------------------------+
 | | bit  30:25 R/W  TTIU_COUNT_MAX          |
 | | bit  24    R/W  FETX_UPDATE_REQ_CLR_EN  |
 | | bit  23    R/W  FETX_READY_CHECK_ENB    |
 | | bit  22    R/W  SWAP_DEC_INC_EN         |
 | | bit  21    R/W  HANDLE_MIN_FETX_PRE_EN  |
 | | bit  20    R/W  HANDLE_MAX_FETX_PRE_EN  |
 | | bit  19    R/W  HANDLE_MIN_FETX_CTR_EN  |
 | | bit  18    R/W  HANDLE_MAX_FETX_CTR_EN  |
 | | bit  17    R/W  HANDLE_MIN_FETX_POST_EN |
 | | bit  16    R/W  HANDLE_MAX_FETX_POST_EN |
 | | bit  15    R/W  FETX_COEF_SET_SEL       |
 | | bit  14:8  R/W  FETX_ADJ_NEG_THRESH     |
 | | bit  7:1   R/W  FETX_ADJ_POS_THRESH     |
 | | bit  0     R/W  FETX_ADAPT_MODE         |
 | +-----------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_TTIU_COUNT_MAX_set            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TTIU_COUNT_MAX_get            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TTIU_COUNT_MAX_set      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TTIU_COUNT_MAX_get      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_UPDATE_REQ_CLR_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_UPDATE_REQ_CLR_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_READY_CHECK_ENB_set      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_READY_CHECK_ENB_get      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_SWAP_DEC_INC_EN_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_SWAP_DEC_INC_EN_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MIN_FETX_PRE_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MIN_FETX_PRE_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MAX_FETX_PRE_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MAX_FETX_PRE_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MIN_FETX_CTR_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MIN_FETX_CTR_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MAX_FETX_CTR_EN_set    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MAX_FETX_CTR_EN_get    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MIN_FETX_POST_EN_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MIN_FETX_POST_EN_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_HANDLE_MAX_FETX_POST_EN_set   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_HANDLE_MAX_FETX_POST_EN_get   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_COEF_SET_SEL_set         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_COEF_SET_SEL_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_FETX_ADJ_NEG_THRESH_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_ADJ_NEG_THRESH_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_ADJ_NEG_THRESH_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_ADJ_NEG_THRESH_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_ADJ_POS_THRESH_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_ADJ_POS_THRESH_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_FETX_ADJ_POS_THRESH_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_ADJ_POS_THRESH_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | void   s16_adapt_dsp_16_field_FETX_ADAPT_MODE_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_ADAPT_MODE_get           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | +-----------------------------------------------+
 | | Register 0x0000037c TTIU_FRAME_MARKER_PATTERN |
 | +-----------------------------------------------+
 | | bit  13:0 R/W  TTIU_FM_PATTERN                |
 | +-----------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_TTIU_FM_PATTERN_set       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_TTIU_FM_PATTERN_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_range_TTIU_FM_PATTERN_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_range_TTIU_FM_PATTERN_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | 
 | +------------------------------------------+
 | | Register 0x00000380 FETX_ADJ_STATUS      |
 | +------------------------------------------+
 | | bit  30    R    TTIU_FM_CST_STAT         |
 | | bit  29    R    TTIU_FM_STAT             |
 | | bit  28:20 R    FETX_POST_ADJ            |
 | | bit  19:11 R    FETX_CTR_ADJ             |
 | | bit  10:2  R    FETX_PRE_ADJ             |
 | | bit  1     R/W  FETX_ADJ_CLR             |
 | | bit  0     R/W  CAPTURE_FETX_ADJ_REQUEST |
 | +------------------------------------------+
 | 
 | void   s16_adapt_dsp_16_field_FETX_ADJ_CLR_set             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_FETX_ADJ_CLR_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void   s16_adapt_dsp_16_field_CAPTURE_FETX_ADJ_REQUEST_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | UINT32 s16_adapt_dsp_16_field_CAPTURE_FETX_ADJ_REQUEST_get ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_TTIU_FM_CST_STAT_get         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_TTIU_FM_STAT_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_FETX_POST_ADJ_get            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_POST_ADJ_get      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_FETX_CTR_ADJ_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_CTR_ADJ_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 | UINT32 s16_adapt_dsp_16_field_FETX_PRE_ADJ_get             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | UINT32 s16_adapt_dsp_16_field_range_FETX_PRE_ADJ_get       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 start_bit, UINT32 stop_bit )
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef _S16_ADAPT_DSP_16_IO_H
#define _S16_ADAPT_DSP_16_IO_H

#include "s16_loc.h"
#include "s16_adapt_dsp_16_regs.h"
#include "s16_adapt_dsp_16_io_inline.h"


/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | TSB access functions
 +-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | These functions do not need to be accessed directly,... just included here for completeness.
 +-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | void                 s16_adapt_dsp_16_buffer_init               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | void                 s16_adapt_dsp_16_buffer_flush              ( s16_adapt_dsp_16_buffer_t *b_ptr )
 | UINT32               s16_adapt_dsp_16_reg_read                  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg )
 | void                 s16_adapt_dsp_16_reg_write                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 value )
 | void                 s16_adapt_dsp_16_field_set                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 unused_mask, UINT32 ofs, UINT32 value )
 | void                 s16_adapt_dsp_16_action_on_write_field_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 ofs, UINT32 value )
 | void                 s16_adapt_dsp_16_burst_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | void                 s16_adapt_dsp_16_burst_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 len, UINT32 *value )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_poll                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mem_type, UINT32 reg, UINT32 mask, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 +------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 | Functions to Access Registers
 +---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | These functions can be used if for some reason the field getters & setters are not appropriate.
 +---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
 | void                 s16_adapt_dsp_16_reg_ADAPT_DSP_CLK_CTRL_write                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_DSP_CLK_CTRL_field_set             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_DSP_CLK_CTRL_read                  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_1_write                       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_1_field_set                   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_CTRL_1_read                        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_2_write                       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_2_field_set                   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_CTRL_2_read                        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_3_write                       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_CTRL_3_field_set                   ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_CTRL_3_read                        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_DSS_CTRL_write                           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_DSS_CTRL_field_set                       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_DSS_CTRL_read                            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_1_write                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_1_field_set                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_DSS_TAPS_1_read                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_2_write                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_2_field_set                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_DSS_TAPS_2_read                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_3_write                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_3_field_set                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_DSS_TAPS_3_read                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_4_write                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_DSS_TAPS_4_field_set                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_DSS_TAPS_4_read                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_LMS_MU_FACTORS_write                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_LMS_MU_FACTORS_field_set                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_LMS_MU_FACTORS_read                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ROUND_ROBIN_PERIODS_write                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ROUND_ROBIN_PERIODS_field_set            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ROUND_ROBIN_PERIODS_read                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_1_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_1_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_1_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_2_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_2_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_2_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_3_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_3_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_3_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_4_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_4_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_4_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_5_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_5_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_OBJECT_PRELOAD_VAL_5_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_CLIP_RATE_MON_PARAMS_write               ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_CLIP_RATE_MON_PARAMS_field_set           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_CLIP_RATE_MON_PARAMS_read                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_FORCE_VAL_write                    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_FORCE_VAL_field_set                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_FORCE_VAL_read                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_FETX_TTIU_CTRL_write                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_FETX_TTIU_CTRL_field_set                 ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_FETX_TTIU_CTRL_read                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_FETX_CTRL_write                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_FETX_CTRL_field_set                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_FETX_CTRL_read                           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_TTIU_FRAME_MARKER_PATTERN_write          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_TTIU_FRAME_MARKER_PATTERN_field_set      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_TTIU_FRAME_MARKER_PATTERN_read           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_STAT_write                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_STAT_field_set                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_STAT_read                          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_REQUEST_write      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_REQUEST_field_set  ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_REQUEST_read       ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_CLIP_RATE_MON_ADC_RESULTS_write          ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_CLIP_RATE_MON_ADC_RESULTS_field_set      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_CLIP_RATE_MON_ADC_RESULTS_read           ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_FETX_ADJ_STATUS_write                    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_FETX_ADJ_STATUS_field_set                ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_FETX_ADJ_STATUS_read                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | void                 s16_adapt_dsp_16_reg_STAT_INT_EVENT_write                     ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_STAT_INT_EVENT_action_on_write_field_set ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_STAT_INT_EVENT_read                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_reg_STAT_INT_EVENT_poll                      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | void                 s16_adapt_dsp_16_reg_STAT_INT_EN_write                        ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 value )
 | void                 s16_adapt_dsp_16_reg_STAT_INT_EN_field_set                    ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 ofs, UINT32 value )
 | UINT32               s16_adapt_dsp_16_reg_STAT_INT_EN_read                         ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | UINT32               s16_adapt_dsp_16_reg_STAT_INT_read                            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | PMC_POLL_RETURN_TYPE s16_adapt_dsp_16_reg_STAT_INT_poll                            ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A, UINT32 mask, UINT32 value, PMC_POLL_COMPARISON_TYPE cmp, UINT32 max_count, UINT32 *num_failed_polls, UINT32 delay_between_polls_in_microseconds )
 | 
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_1_read             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_2_read             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_3_read             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | UINT32               s16_adapt_dsp_16_reg_ADAPT_RESULTS_CAPTURE_4_read             ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 | UINT32               s16_adapt_dsp_16_reg_CLIP_RATE_MON_PGA_GAIN_RESULTS_read      ( s16_adapt_dsp_16_buffer_t *b_ptr, s16_handle_t *h_ptr, UINT32 A )
 | 
 +--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#endif /* _S16_ADAPT_DSP_16_IO_H */