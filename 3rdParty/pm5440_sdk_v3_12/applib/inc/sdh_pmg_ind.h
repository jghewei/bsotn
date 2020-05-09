/*******************************************************************************
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
* --------------------------------------------------------------------------
*   DESCRIPTION :
*    Prototypes for the indirect access functions for each indirect register
*    within the SDH_PMG.
*
*   NOTES:
*    This file is auto generated. Do not edit this file.
*
*******************************************************************************/
#ifndef _SDH_PMG_IND_H
#define _SDH_PMG_IND_H

#ifdef __cplusplus
extern "C" {
#endif

/*
** Include Files
*/
#include "pmc_sys.h"
#include "pmc_types.h"


/*
** Local Enumerated Types
*/

/*
** Local Constants
*/


/*
** Local Macro Definitions
*/
/*
** Local Structures and Unions
*/


/*******************************************************************************
* STRUCTURE: rttp_indirect_buffer_t 
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Buffer for reading/writing to rttp_indirect registers.
*
* ELEMENTS:
*   data - Data to read/write
*   mask - Mask of valid bits in data
*
*******************************************************************************/
typedef struct 
{
  UINT32 data[1];
  UINT32 mask[1];
} rttp_indirect_buffer_t;


#ifndef rttp_indirect_buffer_init
#define rttp_indirect_buffer_init( b ) \
       _rttp_indirect_init( LOG_CALLER b )
#endif
/*******************************************************************************
* _rttp_indirect_init
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize buffer
*
* INPUTS:
*   b   - pointer to buffer
*
* OUTPUTS:
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
static INLINE void _rttp_indirect_init(LOG_CALLER_DEFN
                                         rttp_indirect_buffer_t *b)
{
    b->data[0] = 0;
    b->mask[0] = 0;
}

#include "rttp_indirect_io.h"






/*******************************************************************************
* STRUCTURE: sber_indirect_buf 
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Buffer for reading/writing to sber_indirect registers.
*
* ELEMENTS:
*   data - Data to read/write
*   mask - Mask of valid bits in data
*
*******************************************************************************/
typedef struct 
{
  UINT32 data[1];
  UINT32 mask[1];
} sber_indirect_buffer_t;


#ifndef sber_indirect_buffer_init
#define sber_indirect_buffer_init( b ) \
       _sber_indirect_init( LOG_CALLER b )
#endif
/*******************************************************************************
* _sber_indirect_init
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize buffer
*
* INPUTS:
*   b   - pointer to buffer
*
* OUTPUTS:
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
static INLINE void _sber_indirect_init(LOG_CALLER_DEFN
                                         sber_indirect_buffer_t *b)
{
    PMC_ENTRY();

    b->data[0] = 0;
    b->mask[0] = 0;

    PMC_RETURN();
}

#include "sber_indirect_io.h"











PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_STAT_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_STAT_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_STAT_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_STAT_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_EN_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_EN_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_EN_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_EN_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_STAT_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_STAT_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_STAT_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_MISMATCH_UNSTBL_INT_STAT_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_TRACE_CFG_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_CFG_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_TRACE_CFG_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      rttp_indirect_TRACE_CFG_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_CAPTURED_TRACE_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_CAPTURED_TRACE_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_CAPTURED_TRACE_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_CAPTURED_TRACE_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_ACCEPTED_TRACE_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_ACCEPTED_TRACE_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_ACCEPTED_TRACE_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_ACCEPTED_TRACE_buffer_t *b);




PUBLIC PMC_ERROR rttp_indirect_EXPECTED_TRACE_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_EXPECTED_TRACE_buffer_t *b);

PUBLIC PMC_ERROR rttp_indirect_EXPECTED_TRACE_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      UINT32 trace_byte,
                                      rttp_indirect_EXPECTED_TRACE_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_STAT_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_STAT_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_STAT_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_STAT_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_INT_EN_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_INT_EN_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_INT_EN_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_INT_EN_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_INT_STAT_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_INT_STAT_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_SF_BERM_INT_STAT_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_SF_BERM_INT_STAT_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_BERM_BER_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_BER_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_BERM_BER_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_BER_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_BERM_CLEAR_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_CLEAR_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_BERM_CLEAR_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_CLEAR_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_PATH_MONING_EN_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_PATH_MONING_EN_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_PATH_MONING_EN_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_PATH_MONING_EN_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_2_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_2_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_2_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_2_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_1_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_1_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_1_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SD_BERM_SET_INTEGRATION_PERIOD_1_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_BERM_BER_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_BER_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_BERM_BER_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_BER_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_BERM_CLEAR_TH_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_CLEAR_TH_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_BERM_CLEAR_TH_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_CLEAR_TH_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_PATH_MONING_EN_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_PATH_MONING_EN_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_PATH_MONING_EN_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_PATH_MONING_EN_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_2_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_2_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_2_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_2_buffer_t *b);




PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_1_buffer_apply(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_1_buffer_t *b);

PUBLIC PMC_ERROR sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_1_buffer_retrieve(sdh_pmg_handle_t * h,  
                                      UINT32 index_a,
                                      sber_indirect_SF_BERM_SET_INTEGRATION_PERIOD_1_buffer_t *b);






#ifdef __cplusplus
}
#endif

#endif /* _SDH_PMG_IND_H */
