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
*   DESCRIPTION : This file contains C functions for G.HAO LINE <-> MAP
*                 segement.
*
*   NOTES:
*
*******************************************************************************/
/*
** Include Files
*/

#include "digi_loc.h"

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

/*
** Local Variables
*/

/*
** Log Messaging
*/

/*
** Forward References
*/                                            

/*
** Internal Functions
*/


/*
**  Exported Interface Functions - Start
*/


#ifndef DOXYGEN_PUBLIC_ONLY
/*******************************************************************************
* digi_ghao_line_map_lcr_size_tx_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for LINE<->MAP increase segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_tx_inc_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    UINT8 coreotn_tx_tpid;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    BOOL mux_passthru;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    coreotn_tx_tpid = local_ghao_segment->coreotn_tx_tpid;
    mux_passthru = local_ghao_segment->mux_passthru;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX INC RP\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Initialize G.HAO in TSBs that need to be initialized */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 0) Extract added/removed calendar slots for MUX\n");
        ret_val = coreotn_ghao_db_chnl_get_masks(digi_handle->coreotn_handle,
                                                 UTIL_GEN_DB_LINE_CORE_OTN_TX_DB,
                                                 ghao_mux_stage,
                                                 coreotn_ho_chnl_id,
                                                 coreotn_lo_chnl_id,
                                                 local_ghao_segment->coreotn_tx_new_trib_slots,
                                                 local_ghao_segment->coreotn_tx_old_cal_mask,
                                                 local_ghao_segment->coreotn_tx_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->coreotn_tx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        digi_ghao_gen_slots_add_rem_from_masks(local_ghao_segment->coreotn_tx_old_cal_mask,
                                               local_ghao_segment->coreotn_tx_new_cal_mask,
                                               local_ghao_segment->coreotn_tx_cal_slots_add_rem);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc_rp : 0a) MUX INIT: ghao_mux_stage=%d, ghao_id=%d, ho_chnl_id=%d, lo_chnl_id=%d, tbid=%d, tribslots=%d\n", ghao_mux_stage, ghao_segment_id, coreotn_ho_chnl_id, coreotn_lo_chnl_id, coreotn_tx_tpid, local_ghao_segment->ts_target);
        ret_val = coreotn_mux_ghao_init(digi_handle->coreotn_handle,
                                        ghao_mux_stage,
                                        ghao_segment_id,
                                        coreotn_ho_chnl_id, 
                                        coreotn_lo_chnl_id,
                                        coreotn_tx_tpid,
                                        local_ghao_segment->coreotn_tx_cal_slots_add_rem);
    }
    
    if(mux_passthru)
    {

        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR resize tx_inc_rp : 0b) MUX INIT (passthru mux): ghao_mux_stage=%d, ghao_id=%d, ho_chnl_id=%d, lo_chnl_id=%d, tbid=%d, tribslots=%d\n", ghao_mux_stage, ghao_segment_id, coreotn_ho_chnl_id, coreotn_lo_chnl_id, coreotn_tx_tpid, local_ghao_segment->ts_target);
              ret_val = coreotn_mux_ghao_init(digi_handle->coreotn_handle,
                                            COREOTN_MUX_STAGE_TWO,
                                            ghao_segment_id,
                                            coreotn_lo_chnl_id, 
                                            coreotn_lo_chnl_id,
                                            coreotn_tx_tpid,
                                            local_ghao_segment->coreotn_tx_cal_slots_add_rem);
        }

    }




    /* Link Connection Resize (FIFO and Calendar Setup): */
    /* 1)	Once Control plane is ready. Send: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc_rp : 1) MUX (Stage 1-2): [ADD, #a, NACK] and RP = 1, TSCC = 0 on all added Trib-slots.\n");
        ret_val = coreotn_mux_ghao_send_add_nack(digi_handle->coreotn_handle,
                                                 ghao_mux_stage,
                                                 ghao_segment_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize TX INC RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_tx_inc_rp */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_rx_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for LINE<->MAP increase segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_rx_inc_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    UINT8 coreotn_rx_tpid;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    coreotn_rx_tpid = local_ghao_segment->coreotn_rx_tpid;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX INC RP\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Initialize G.HAO in TSBs that need to be initialized */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc_rp : 0) DMX INIT: ghao_mux_stage=%d, ho_chnl_id=%d, lo_chnl_id=%d, tribslots=%d\n", ghao_mux_stage, coreotn_ho_chnl_id, coreotn_lo_chnl_id, local_ghao_segment->ts_target);
        ret_val = coreotn_dmx_ghao_init(digi_handle->coreotn_handle,
                                        ghao_mux_stage,
                                        coreotn_lo_chnl_id,
                                        coreotn_rx_tpid,
                                        local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    /* Link Connection Resize (FIFO and Calendar Setup): */
    /* 1)	Once Control plane is ready. Send: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc_rp : 1) DMX (Stage 1-2): Wait to receive RP = 1 and observe [ADD, #a, NACK] and TSCC = 0 in all new TS.\n");
        ret_val = coreotn_dmx_ghao_wait_for_add_nack(digi_handle->coreotn_handle,
                                                     ghao_mux_stage,
                                                     &coreotn_ho_chnl_id,
                                                     &coreotn_lo_chnl_id,
                                                     &coreotn_rx_tpid,
                                                     local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize RX INC RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_rx_inc_rp */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_tx_inc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for LINE<->MAP increase segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_tx_inc(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 mux_passthru;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i;
    UINT32 num_add_rem;
    UINT32 cal_add_remove[96];
    UINT32 fmf1_xoff_pre_adj;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    mux_passthru = local_ghao_segment->mux_passthru;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX INC\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Databases for TX datapath */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_LINE_CORE_OTN_TX_DB\n");
        ret_val = coreotn_ghao_db_chnl_rec_update(digi_handle->coreotn_handle,
                                                  UTIL_GEN_DB_LINE_CORE_OTN_TX_DB,
                                                  ghao_mux_stage,
                                                  coreotn_ho_chnl_id,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->coreotn_tx_new_trib_slots,
                                                  local_ghao_segment->coreotn_tx_old_cal_mask,
                                                  local_ghao_segment->coreotn_tx_new_cal_mask,
                                                  &local_ghao_segment->cal_to_add_remove_num,
                                                  local_ghao_segment->coreotn_tx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_ODUKSC_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_ODUKSC_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                 local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 dummy_mapotn_oduksc_cal_to_add_remove);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_DCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_MAPOTN_COREOTN,
                                                   coreotn_lo_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    /* TGFP -> MUX direction: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 2) MUX (Stage 1-2): Change EXPAND CFC FIFO to new TS value. Don't increase XOFF threshold.\n");
        ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                               ghao_mux_stage,
                                               ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 3) MUX (Stage 1-2): Configure all the standby pages to new configuration including STS_SW, new M value.  Configure prev_cn in standby page.\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 4) MUX (Stage 2-3A): Change FIFO size to final TS size. Do not change XOFF threshold\n");
            ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                                   COREOTN_MUX_STAGE_TWO,
                                                   ghao_segment_id);
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 5)	MPMO (stage 3B): Change FIFO Size to final TS size. Do not change XOFF threshold.\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_COREOTN,
                                                                 coreotn_lo_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 6)	ODUk Switch (MAP -> LINE): Change the FIFO size to final TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_COREOTN,
                                                               coreotn_lo_chnl_id,
                                                               0,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 7)	MPMA(stage 4): Change FIFO to final TS count\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_FROM_MAPOTN,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 9) TGFP : Change FIFO sizes and thresholds to final TS count.\n");
        ret_val = mapotn_tgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 10) CPB (Towards TGFP): Change Calendar to final TS value.\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                mapotn_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 11) ODUk SC (MAPOTN): Change Calendar to final Calendar. Credit should be scaled down to reflect old BW.\n");
        ret_val = mapotn_oduksc_scbs3_cgen_reprov(digi_handle->mapotn_handle,
                                                  mapotn_chnl_id,
                                                  local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 12) MPMA (stage 4): Change Calendar to final TS count\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_FROM_MAPOTN,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 13) ODUk Switch (MAP -> LINE) : Change Calendar to final TS count\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 DIGI_GHAO_ODUKSW_MAPOTN_COREOTN,
                                                 coreotn_lo_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 14) MPMO (Stage 3B): Change Calendar to new TS Calendar, but don't enable 'valid' into those Calendar, meaning set the new Cal. Entries user bits to be disabled.\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_COREOTN,
                                                                coreotn_lo_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->coreotn_tx_new_cal_mask,
                                                                local_ghao_segment->coreotn_tx_old_cal_mask);
    }

    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 15) MUX (Stage 2-3A) : Do passthru re-config to new TS count, but don't enable the additional calendars\n");
            ret_val = coreotn_mux_ghao_recfg_passthru(digi_handle->coreotn_handle,
                                                      COREOTN_MUX_STAGE_TWO,
                                                      ghao_segment_id);
        }
    }





    if(mux_passthru)
    {
        num_add_rem  = MPMO_USERBIT_INC_PRE_WO_PASSTHRU; /*MPMO_USERBIT_INC_PRE_W_PASSTHRU;*/
    }
    else
    {
        num_add_rem  = MPMO_USERBIT_INC_PRE_WO_PASSTHRU;
    }


    /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
    for(i = 0; i< 3; i++)
    {
        local_ghao_segment->coreotn_mpmo3b_userbits_mask[i] = local_ghao_segment->coreotn_tx_old_cal_mask[i];
    }


        
    if(ret_val == PMC_SUCCESS)
    {
        for(i=0;i<num_add_rem;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {
                cal_add_remove[i] = local_ghao_segment->coreotn_tx_cal_to_add_remove[i];
            }
        }

        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_1 : 28) MPMO (Stage 3B): Enable 'valid' on one of the to-be-added cal slots, meaning set the new Cal. Entries user bits to be enabled.\n");

        ret_val = coreotn_mpmo_update_userbit_mask(digi_handle->coreotn_handle,
                                                           COREOTN_MPMO_TO_COREOTN,
                                                           coreotn_lo_chnl_id,
                                                           cal_add_remove,
                                                           num_add_rem,
                                                           local_ghao_segment->coreotn_tx_new_cal_mask,
                                                           local_ghao_segment->coreotn_mpmo3b_userbits_mask);
    }


    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        for(i=0;i<FMF2_MUX_CAL_EN_INC_PRE_W_PASSTHRU;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {
                PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_1 : 29a) MUX (Stage 2-3A) : Enable lo_calen on the same calendar slots by setting the EXPAND.LO_FIRST_CYCLE[cal_slot_id] to 1\n");
                ret_val = coreotn_mux_ghao_passthru_cal_enable_diable(digi_handle->coreotn_handle,
                                                                      local_ghao_segment->coreotn_tx_cal_to_add_remove[i],
                                                                      TRUE);
            }
        }




        if(digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start == 1)
        {
            fmf1_xoff_pre_adj = FMF1_MUX_XOFF_INC_PRE_W_PASSTHRU_FROM1;
        }
        else
        {
            fmf1_xoff_pre_adj = FMF1_MUX_XOFF_INC_PRE_W_PASSTHRU;
        }



        for(i=0;i<fmf1_xoff_pre_adj;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {

                PMC_LOG_TRACE("G.HAO LCR resize inc : 29b) MUX (EXP Stage 1-2): Increase XOFF threshold by 1TS equivalent every 2.5s\n ");
                ret_val = coreotn_odtu_mux_xoff_thresh_update(digi_handle->coreotn_handle,
                                                          ghao_mux_stage,
                                                          coreotn_lo_chnl_id,
                                                          TRUE,
                                                          &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].coreotn_mux_xoff_thresh);
            }
        }

        for(i=0;i<FMF2_MUX_XOFF_INC_PRE_W_PASSTHRU;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {

                PMC_LOG_TRACE("G.HAO LCR resize inc : 29c) MUX (EXP Stage 2-3A): Increase XOFF threshold by 1TS equivalent every 2.5s\n ");
                ret_val = coreotn_odtu_mux_xoff_thresh_update(digi_handle->coreotn_handle,
                                                          COREOTN_MUX_STAGE_TWO,
                                                          coreotn_lo_chnl_id,
                                                          TRUE,
                                                          &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].coreotn_mux_passthru_xoff_thresh);
            }
        }

        for(i=0;i<MPMO_XOFF_INC_PRE_W_PASSTHRU;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {
                PMC_LOG_TRACE("G.HAO LCR resize inc : 29d) MPMO : Increase XOFF threshold by 1TS equivalent every 2.5s\n ");

                ret_val = coreotn_mpmo_xoff_thresh_change(digi_handle->coreotn_handle,
                                                          COREOTN_MPMO_TO_COREOTN,
                                                          coreotn_lo_chnl_id,
                                                          ghao_increase);
            }
        }
    }
    else
    {

        if(digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start == 1)
        {
            fmf1_xoff_pre_adj = FMF1_MUX_XOFF_INC_PRE_W0_PASSTHRU_FROM1;
        }
        else
        {
            fmf1_xoff_pre_adj = FMF1_MUX_XOFF_INC_PRE_W0_PASSTHRU;
        }



        for(i=0;i<fmf1_xoff_pre_adj;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {

                PMC_LOG_TRACE("G.HAO LCR resize inc : 29b) MUX (EXP Stage 1-2): Increase XOFF threshold by 1TS equivalent every 2.5s\n ");
                ret_val = coreotn_odtu_mux_xoff_thresh_update(digi_handle->coreotn_handle,
                                                          ghao_mux_stage,
                                                          coreotn_lo_chnl_id,
                                                          TRUE,
                                                          &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].coreotn_mux_xoff_thresh);
            }
        }


    }






    PMC_LOG_TRACE("End G.HAO LCR resize TX INC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_tx_inc */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_rx_inc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for LINE<->MAP increase segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_rx_inc(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i;
    UINT32 j;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX INC\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Databases for RX datapath */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_LINE_CORE_OTN_RX_DB\n");
        ret_val = coreotn_ghao_db_chnl_rec_update(digi_handle->coreotn_handle,
                                                  UTIL_GEN_DB_LINE_CORE_OTN_RX_DB,
                                                  ghao_mux_stage,
                                                  coreotn_ho_chnl_id,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->coreotn_rx_new_trib_slots,
                                                  local_ghao_segment->coreotn_rx_old_cal_mask,
                                                  local_ghao_segment->coreotn_rx_new_cal_mask,
                                                  &local_ghao_segment->cal_to_add_remove_num,
                                                  local_ghao_segment->coreotn_rx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_MPMA_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_MPMA_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                 local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_COREOTN_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 18) ODUk Switch (LINE -> MAP): Change ODUk FIFO size.\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_MAPOTN,
                                                               mapotn_chnl_id,
                                                               0,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }



    /*Pinch the ODUKSW port 3 entries so that only the starting calendar entries
    are set (the entries are added during the ramp */
    if (ret_val == PMC_SUCCESS)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<32;j++)
            {
                if(((local_ghao_segment->mapotn_oduksc_new_cal_mask[i] >> j) & 1) == 1)
                {
                    if(((local_ghao_segment->mapotn_oduksc_old_cal_mask[i] >> j) & 1) == 1)
                    {
                        ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                        (32*i)+j,
                                                                        FALSE);
                    }
                    else
                    {
                        ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                        (32*i)+j,
                                                                        TRUE);
                    }
                }
            }
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_COREOTN_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 17) MPMO (Stage 4): Increase FIFO to final TS. Do not update XOFF threshold.\n");

        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_MAPOTN,
                                                                 mapotn_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 19) RGFP: Increase the unpacking and egress FIFO to final TS size.\n");
        ret_val = mapotn_rgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 20) MPMA (stage 3B) : Increase FIFO to final TS size.\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_TO_COREOTN,
                                                coreotn_lo_chnl_id,
                                                local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 20b) ODUJAT (1-2 and 2-3a) : Increase FIFO to final TS size.\n");
        ret_val = coreotn_odujat_ghao_resize_fifo(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 21) ODUkSC (COREOTN) :  Change to new Calendar and scale down credits to reflect old BW.\n");
        ret_val = coreotn_oduksc_scbs3_cgen_reprov(digi_handle->coreotn_handle,
                                                   ghao_mux_stage,
                                                   coreotn_lo_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 22) DMX(Stage 1-2): Configure all the standby pages to new configuration including STS_SW, new M value.\n");
        ret_val = coreotn_dmx_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       &coreotn_ho_chnl_id,
                                                       &coreotn_lo_chnl_id,
                                                       ghao_increase,
                                                       local_ghao_segment->old_trib_slot_mask_rx,
                                                       local_ghao_segment->coreotn_rx_trib_slots_add_rem,
                                                       local_ghao_segment->coreotn_rx_tpid);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 23) MPMA (stage 3B): Increase Calendar\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_TO_COREOTN,
                                                 coreotn_lo_chnl_id,
                                                 local_ghao_segment->ts_target);
    }





    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 24) ODUk (LINE -> MAP) : Change the Calendar to final TS\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 DIGI_GHAO_ODUKSW_COREOTN_MAPOTN,
                                                 mapotn_chnl_id);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 25) MPMO (stage 4): Change the Calendar to final TS. But pinch the new calendar locations using the USER bits in the scbs3.\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_MAPOTN,
                                                                mapotn_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                                local_ghao_segment->mapotn_mpma_old_cal_mask);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 26) MPMA (MAPOTN): Change the Calendar to final TS. NOTE:  Calendar burstiness adds noise to continuous pacing, we should be aware of this.\n");
        ret_val = mapotn_mpma_scbs3_reprov(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           local_ghao_segment->ts_target);
    }


    /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
    for(i = 0; i< 3; i++)
    {
        local_ghao_segment->coreotn_mpmo4_userbits_mask[i] = local_ghao_segment->mapotn_mpma_old_cal_mask[i];
    }


    PMC_LOG_TRACE("End G.HAO LCR resize RX INC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_rx_inc */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_tx_dec_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for LINE<->MAP decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_tx_dec_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    PMC_LOG_TRACE("Start G.HAO LCR resize TX DEC RP\n");

    /* Initialize G.HAO in TSB that need to be initialized */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 0) Extract added/removed calendar slots for MUX\n");
        ret_val = coreotn_ghao_db_chnl_get_masks(digi_handle->coreotn_handle,
                                                 UTIL_GEN_DB_LINE_CORE_OTN_TX_DB,
                                                 ghao_mux_stage,
                                                 coreotn_ho_chnl_id,
                                                 coreotn_lo_chnl_id,
                                                 local_ghao_segment->coreotn_tx_new_trib_slots,
                                                 local_ghao_segment->coreotn_tx_old_cal_mask,
                                                 local_ghao_segment->coreotn_tx_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->coreotn_tx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        digi_ghao_gen_slots_add_rem_from_masks(local_ghao_segment->coreotn_tx_old_cal_mask,
                                               local_ghao_segment->coreotn_tx_new_cal_mask,
                                               local_ghao_segment->coreotn_tx_cal_slots_add_rem);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 0) MUX INIT: ghao_mux_stage=%d, ghao_id=%d, ho_chnl_id=%d, lo_chnl_id=%d, tbid=%d, tribslots=%d\n", ghao_mux_stage, ghao_segment_id, coreotn_ho_chnl_id, coreotn_lo_chnl_id, local_ghao_segment->coreotn_tx_tpid, local_ghao_segment->ts_target);
        ret_val = coreotn_mux_ghao_init(digi_handle->coreotn_handle,
                                        ghao_mux_stage,
                                        ghao_segment_id,
                                        coreotn_ho_chnl_id, 
                                        coreotn_lo_chnl_id,
                                        local_ghao_segment->coreotn_tx_tpid,
                                        local_ghao_segment->coreotn_tx_cal_slots_add_rem);
    }

        
    if(local_ghao_segment->mux_passthru)
    {
        if (ret_val == PMC_SUCCESS)
        {
            
              PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 0) MUX INIT: ghao_mux_stage=%d, ghao_id=%d, ho_chnl_id=%d, lo_chnl_id=%d, tbid=%d, tribslots=%d\n", ghao_mux_stage, ghao_segment_id, coreotn_ho_chnl_id, coreotn_lo_chnl_id, local_ghao_segment->coreotn_tx_tpid, local_ghao_segment->ts_target);
              ret_val = coreotn_mux_ghao_init(digi_handle->coreotn_handle,
                                            COREOTN_MUX_STAGE_TWO,
                                            ghao_segment_id,
                                            coreotn_lo_chnl_id, 
                                            coreotn_lo_chnl_id,
                                            local_ghao_segment->coreotn_tx_tpid,
                                            local_ghao_segment->coreotn_tx_cal_slots_add_rem);
        }

    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 0) Extract added/removed calendar slots for ODUKSC\n");
        ret_val = mapotn_ghao_db_chnl_get_masks(digi_handle->mapotn_handle,
                                                UTIL_GEN_DB_ODUKSC_DB,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target,
                                                local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                &local_ghao_segment->cal_to_add_remove_num,
                                                dummy_mapotn_oduksc_cal_to_add_remove);
    }


    /* 1)	Once Control plane is ready. Send: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 1) MUX (Stage 1-2): [REM, #a, NACK] and RP = 1, TSCC = 0 on all removed Trib-slots.\n");
        ret_val = coreotn_mux_ghao_send_remove_nack(digi_handle->coreotn_handle,
                                                    ghao_mux_stage,
                                                    ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 2) Set MUX (Stage 1-2) in prev_Cn mode and do a config update.\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 2b) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 2c) MUX (Stage 1-2): Synchronize standby page with active page\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 2) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }

    /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
    for(i = 0; i< 3; i++)
    {
        local_ghao_segment->coreotn_mpmo3b_userbits_mask[i] = local_ghao_segment->coreotn_tx_old_cal_mask[i];
    }

    PMC_LOG_TRACE("Start G.HAO LCR resize TX DEC RP\n");


    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_tx_dec_rp */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_rx_dec_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for LINE<->MAP decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_rx_dec_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    PMC_LOG_TRACE("Start G.HAO LCR resize RX DEC RP\n");

    /* Initialize G.HAO in TSB that need to be initialized */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec_rp : 0) Extract added/removed calendar slots for DMX\n");
        ret_val = coreotn_ghao_db_chnl_get_masks(digi_handle->coreotn_handle,
                                                 UTIL_GEN_DB_LINE_CORE_OTN_RX_DB,
                                                 ghao_mux_stage,
                                                 coreotn_ho_chnl_id,
                                                 coreotn_lo_chnl_id,
                                                 local_ghao_segment->coreotn_rx_new_trib_slots,
                                                 local_ghao_segment->coreotn_rx_old_cal_mask,
                                                 local_ghao_segment->coreotn_rx_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->coreotn_rx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec_rp : 0) DMX INIT: ghao_mux_stage=%d, ho_chnl_id=%d, lo_chnl_id=%d, tribslots=%d\n", ghao_mux_stage, coreotn_ho_chnl_id, coreotn_lo_chnl_id, local_ghao_segment->ts_target);
        ret_val = coreotn_dmx_ghao_init(digi_handle->coreotn_handle,
                                        ghao_mux_stage,
                                        coreotn_lo_chnl_id,
                                        local_ghao_segment->coreotn_rx_tpid,
                                        local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec_rp : 0) Extract added/removed calendar slots for MPMA\n");
        ret_val = mapotn_ghao_db_chnl_get_masks(digi_handle->mapotn_handle,
                                                UTIL_GEN_DB_MPMA_DB,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target,
                                                local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                &local_ghao_segment->cal_to_add_remove_num,
                                                local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }


    /* 1)	Once Control plane is ready. Send: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec_rp : 1) DMX (Stage 1-2): DMX (Stage 1-2): Wait to receive RP = 1 and observe [REM, #a, NACK] and TSCC = 0 in all removed TS.\n");
        ret_val = coreotn_dmx_ghao_wait_for_remove_nack(digi_handle->coreotn_handle,
                                                        ghao_mux_stage,
                                                        &coreotn_ho_chnl_id,
                                                        &coreotn_lo_chnl_id,
                                                        &local_ghao_segment->coreotn_rx_tpid,
                                                        local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
    for(i = 0; i< 3; i++)
    {
        local_ghao_segment->coreotn_mpmo4_userbits_mask[i] = local_ghao_segment->mapotn_mpma_old_cal_mask[i];
    }

    PMC_LOG_TRACE("End G.HAO LCR resize RX DEC RP\n");


    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_rx_dec_rp */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_tx_dec
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for LINE<->MAP decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_tx_dec(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 mux_passthru;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i,j;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    mux_passthru = local_ghao_segment->mux_passthru;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX DEC\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* LCR (FIFO and Calendar resizing) - Calendar against Traffic, FIFO with traffic: */


    if(ret_val == PMC_SUCCESS)
    {
        /* Before updating the database, it's required to perform
        the ghao "deprovision" step on all active entries */
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : Deprov MUX lo channel\n");
        ret_val = coreotn_mux_ghao_lo_chnl_deprov(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  coreotn_lo_chnl_id,
                                                  coreotn_ho_chnl_id);
    }

    /* Databases for TX datapath */
    if (ret_val == PMC_SUCCESS)
    {

        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_LINE_CORE_OTN_TX_DB\n");
        ret_val = coreotn_ghao_db_chnl_rec_update(digi_handle->coreotn_handle,
                                                  UTIL_GEN_DB_LINE_CORE_OTN_TX_DB,
                                                  ghao_mux_stage,
                                                  coreotn_ho_chnl_id,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->coreotn_tx_new_trib_slots,
                                                  local_ghao_segment->coreotn_tx_old_cal_mask,
                                                  local_ghao_segment->coreotn_tx_new_cal_mask,
                                                  &local_ghao_segment->cal_to_add_remove_num,
                                                  local_ghao_segment->coreotn_tx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_ODUKSC_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_ODUKSC_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                 local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 dummy_mapotn_oduksc_cal_to_add_remove);
    }

    
    /*after ODUKSC DB is updated, calendar pinch mode can now be removed from DCS */
    if (ret_val == PMC_SUCCESS)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<32;j++)
            {
                if(((local_ghao_segment->mapotn_oduksc_old_cal_mask[i] >> j) & 1) == 1)
                {
                    ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                    (32*i)+j,
                                                                    FALSE);
                }
            }
        }
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_DCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    
    /*this call replaces digi_ghao_cpb_db_chnl_rec_update() and digi_ghao_cpb_dcs_calendar_cfg()
    for the ODUKSW at queue 2 (towards COREOTN) for the decrease only.  There
    is a special calendar requirement on this resize*/
    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_OCPB_DCS TX\n");
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 24) ODUk Switch (MAP -> LINE): Change Calendar to final TS + 2\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg_plus_userbits(digi_handle,
                                                               ghao_segment_id);
    }

    /* TGFP -> MUX direction: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 21) MUX (Stage 1-2): Configure all the standby pages to new configuration including STS_SW, new M value. Set the TXJC.PREV_CN_SEL to 0 in the standby page\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 25) MPMA (Stage 4): Change Calendar to final TS\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_FROM_MAPOTN,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 26) ODUk SC MAPOTN : Change Calendar to final TS and credits to match new rate.\n");
        ret_val = mapotn_oduksc_scbs3_cgen_reprov(digi_handle->mapotn_handle,
                                                  mapotn_chnl_id,
                                                  local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 27) CPB (Towards TGFP): Change Calendar to final TS value.\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                 mapotn_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 28) TGFP:  Change XOFF threshold and FIFO size to final TS\n");
        ret_val = mapotn_tgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 30) MPMA (Stage 4): Change FIFO to final TS\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_FROM_MAPOTN,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 31) ODUk Switch (MAP -> LINE): Change FIFO to final size.\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_COREOTN,
                                                               coreotn_lo_chnl_id,
                                                               0, 
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 32) MPMO(Stage 3B): Change FIFO to final size + 2\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_COREOTN,
                                                                 coreotn_lo_chnl_id,
                                                                 local_ghao_segment->ts_target+local_ghao_segment->fo1_mpmo_thresh_pre_post_fw);
    }

    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 33) MUX (Stage 2-3A): Change FIFO to final size(final size + 1TS)\n");
            ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                                   COREOTN_MUX_STAGE_TWO,
                                                   ghao_segment_id);
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 34) MUX (Stage 1-2): Change expand FIFO to final size(final size + 1TS)\n");
        ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                               ghao_mux_stage,
                                               ghao_segment_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize TX DEC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_tx_dec */



/*******************************************************************************
* digi_ghao_line_map_lcr_size_rx_dec
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for LINE<->MAP decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_size_rx_dec(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX DEC\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* LCR (FIFO and Calendar resizing) - Calendar against Traffic, FIFO with traffic: */


    if (ret_val == PMC_SUCCESS)
    {
        /*It is nessecary to call this deprov API in the demux before
        changing the database */
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : Deprov DMX lo channel\n");
        ret_val = coreotn_dmx_ghao_lo_chnl_deprov(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  coreotn_lo_chnl_id,
                                                  coreotn_ho_chnl_id);
    }


    /* Databases for RX datapath */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : DB) Setup database UTIL_GEN_DB_LINE_CORE_OTN_RX_DB\n");
        ret_val = coreotn_ghao_db_chnl_rec_update(digi_handle->coreotn_handle,
                                                  UTIL_GEN_DB_LINE_CORE_OTN_RX_DB,
                                                  ghao_mux_stage,
                                                  coreotn_ho_chnl_id,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->coreotn_rx_new_trib_slots,
                                                  local_ghao_segment->coreotn_rx_old_cal_mask,
                                                  local_ghao_segment->coreotn_rx_new_cal_mask,
                                                  &local_ghao_segment->cal_to_add_remove_num,
                                                  local_ghao_segment->coreotn_rx_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : DB) Setup database UTIL_GEN_DB_MPMA_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_MPMA_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                 local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        /* in the LCR resize, it's required keep the DPI calendar >= to the DCI
        calendar.  It's required to change the ODUKSW calendar after removing
        the userbits */
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_COREOTN_MAPOTN,
                                                   mapotn_chnl_id,
                                                   (local_ghao_segment->ts_target+ digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw));
    }


    /* DMX -> RGFP */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 35) MPMA (MAPOTN): Change Calendar to final TS\n");
        ret_val = mapotn_mpma_scbs3_reprov(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 36) MPMO(Stage4) : Change Calendar to final TS.\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_MAPOTN,
                                                                mapotn_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                                local_ghao_segment->mapotn_mpma_new_cal_mask);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 38) MPMA(Stage 3B) : Change Calendar to final TS\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_TO_COREOTN,
                                                 coreotn_lo_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 39) ODUkSC (COREOTN): Change Calendar to final TS and credits to match new rate.\n");
        ret_val = coreotn_oduksc_scbs3_cgen_reprov(digi_handle->coreotn_handle,
                                                   ghao_mux_stage,
                                                   coreotn_lo_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 40) DMX (Stage 1-2): Configure all the standby pages to new configuration including STS_SW, new M value.\n");
        ret_val = coreotn_dmx_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       &coreotn_ho_chnl_id,
                                                       &coreotn_lo_chnl_id,
                                                       ghao_increase,
                                                       local_ghao_segment->old_trib_slot_mask_rx,
                                                       local_ghao_segment->coreotn_rx_trib_slots_add_rem,
                                                       local_ghao_segment->coreotn_rx_tpid);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 40b) ODUJAT (1-2 and 2-3a) : Decrease FIFO to final TS size.\n");
        ret_val = coreotn_odujat_ghao_resize_fifo(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  coreotn_lo_chnl_id,
                                                  local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 42) ODUk Switch (LINE->MAP): Change FIFO size to final TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_MAPOTN,
                                                               mapotn_chnl_id,
                                                               0, 
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 43) MPMO(Stage 4): Change FIFO size to final TS.\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_MAPOTN,
                                                                 mapotn_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 44) RGFP: Change XOFF threshold and FIFO size to final TS.\n");
        ret_val = mapotn_rgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    PMC_LOG_TRACE("End G.HAO LCR resize RX DEC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_lcr_size_rx_dec */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_inc_1_add_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (add ack) for LINE<->MAP increase segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_inc_1_add_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 mux_passthru;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    mux_passthru = local_ghao_segment->mux_passthru;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX INC 1 ADD_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_1 : 27) MUX: Send [ADD, #a, ACK] on all TS\n");
        ret_val = coreotn_mux_ghao_send_add_ack(digi_handle->coreotn_handle,
                                                ghao_mux_stage,
                                                ghao_segment_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX INC 1 ADD_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_inc_1_add_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_inc_1_add_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (add ack) for LINE<->MAP increase segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_inc_1_add_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX INC 1 ADD_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_inc_1 : 27) DMX: Wait to receive [ADD, #a, ACK] on all TS.\n");
        ret_val = coreotn_dmx_ghao_wait_for_add_ack(digi_handle->coreotn_handle,
                                                    ghao_mux_stage,
                                                    &coreotn_ho_chnl_id,
                                                    &coreotn_lo_chnl_id,
                                                    &local_ghao_segment->coreotn_rx_tpid,
                                                    local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }

    PMC_LOG_TRACE("End G.HAO LCR knife edge RX INC 1 ADD_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_inc_1_add_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_inc_2_norm_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 2 (norm ack) for LINE<->MAP increase segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_inc_2_norm_ack(digi_handle_t *digi_handle,
                                                                     UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX INC 2 NORM_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_2 : 30) MUX: Once DMX ACK is received send [NORM, #a, ACK] in all TS that needs to be changed. This is done by setting G.HAO update bit in the MUX. The MUX will automatically do Knife Edge in the next RMF after sending NORM command.\n");
        ret_val = coreotn_mux_ghao_send_norm(digi_handle->coreotn_handle,
                                                ghao_mux_stage,
                                                ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_2 : 30b) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX INC 2 NORM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_inc_2_norm_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_inc_2_norm_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 2 (norm ack) for LINE<->MAP increase segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_inc_2_norm_ack(digi_handle_t *digi_handle,
                                                                     UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX INC 2 NORM_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_inc_2 : 30) DMX: After ACK cmd is sent in MUX, DMX can receive NORM as soon as one RMF later. Wait to receive NORM in all TS. DMX HW will automatically do Knife edge in the next RMF after receiving NORM Command.\n");
        ret_val = coreotn_dmx_ghao_wait_for_norm_ack(digi_handle->coreotn_handle,
                                                    ghao_mux_stage,
                                                    &coreotn_ho_chnl_id,
                                                    &coreotn_lo_chnl_id,
                                                    &local_ghao_segment->coreotn_rx_tpid,
                                                    local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX INC 2 NORM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_inc_2_norm_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_inc_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for LINE<->MAP increase
*   segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_inc_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX INC 3 IDLE_NACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_3 : 31) MUX (Stage 1-2): Finish LCR by sending [IDLE, 0, NACK] for every added TS at the RMF.\n");
        ret_val = coreotn_mux_ghao_send_idle_nack(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_3 : 31b) MUX (Stage 1-2): Synchronize standby page with active page\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_inc_3 : 31c) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }


    /* After changing the last tribslot, two bits will be set in
    TC_WR_IPT_VALID.  It's required to remove the "old" valid*/
    if(ret_val == PMC_SUCCESS)
    {
        ret_val = coreotn_mux_ghao_clear_old_last_cal_slot(digi_handle->coreotn_handle, 
                                                           ghao_mux_stage,
                                                           coreotn_lo_chnl_id,
                                                           ghao_increase,
                                                           local_ghao_segment->coreotn_tx_old_trib_slots,
                                                           local_ghao_segment->coreotn_tx_new_trib_slots,
                                                           local_ghao_segment->coreotn_tx_old_cal_mask);

    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX INC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_inc_3_idle_nack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_inc_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for LINE<->MAP increase
*   segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_inc_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX INC 3 IDLE_NACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_inc_3 : 31) DMX(Stage 1-2): Wait to receive [IDLE, 0, NACK] on every added TS to exit LCR.\n");
        ret_val = coreotn_dmx_ghao_wait_for_idle_nack(digi_handle->coreotn_handle,
                                                      ghao_mux_stage,
                                                      &coreotn_ho_chnl_id,
                                                      &coreotn_lo_chnl_id,
                                                      &local_ghao_segment->coreotn_rx_tpid,
                                                      local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_inc_3 : 31d) DMX (Stage 1-2): Wait until config update is done\n");
        ret_val = coreotn_dmx_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_inc_3 : 31e) DMX (Stage 1-2): Synchronize standby page with active page\n");
        ret_val = coreotn_dmx_ghao_update_stdby_config_after_knife_edge(digi_handle->coreotn_handle,
                                                                        ghao_mux_stage,
                                                                        coreotn_ho_chnl_id,
                                                                        coreotn_lo_chnl_id,
                                                                        local_ghao_segment->ts_target,
                                                                        local_ghao_segment->new_trib_slot_mask_rx,
                                                                        local_ghao_segment->coreotn_rx_tpid,
                                                                        local_ghao_segment->ghao_increase,
                                                                        local_ghao_segment->cal_to_add_remove_num,
                                                                        local_ghao_segment->coreotn_rx_cal_to_add_remove);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX INC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_inc_3_idle_nack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_dec_1_rem_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (rem ack) for LINE<->MAP decrease segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_dec_1_rem_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX DEC 1 REM_ACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_1 : 46) MUX: Send [REM, #a, ACK] on all TS\n");
        ret_val = coreotn_mux_ghao_send_remove_ack(digi_handle->coreotn_handle,
                                                   ghao_mux_stage,
                                                   ghao_segment_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX DEC 1 REM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_dec_1_rem_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_dec_1_rem_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (rem ack) for LINE<->MAP decrease segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_dec_1_rem_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX DEC 1 REM_ACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_1 : 46) DMX: Wait to receive [REM, #a, ACK] on all TS.\n");
        ret_val = coreotn_dmx_ghao_wait_for_remove_ack(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       &coreotn_ho_chnl_id,
                                                       &coreotn_lo_chnl_id,
                                                       &local_ghao_segment->coreotn_rx_tpid,
                                                       local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX DEC 1 REM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_dec_1_rem_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_dec_2_norm_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 2 (norm ack) for LINE<->MAP decrease segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_dec_2_norm_ack(digi_handle_t *digi_handle,
                                                                     UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX DEC 2 NORM_ACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_2 : 47) MUX: Once DMX ACK is received Send [NORM, #a, ACK] in all TS that needs to be changed. This is done by setting G.HAO update bit in the MUX. The MUX will automatically do Knife Edge in the next RMF after sending NORM command.\n");
        ret_val = coreotn_mux_ghao_send_norm(digi_handle->coreotn_handle,
                                             ghao_mux_stage,
                                             ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_2 : 47b) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX DEC 2 NORM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_dec_2_norm_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_dec_2_norm_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 2 (norm ack) for LINE<->MAP decrease segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_dec_2_norm_ack(digi_handle_t *digi_handle,
                                                                     UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX DEC 2 NORM_ACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_2 : 47) DMX: After ACK cmd is sent in MUX, DMX can receive NORM as soon as one RMF later. Wait to receive NORM in all TS. DMX HW will automatically do Knife edge in the next RMF after receiving NORM Command.\n");
        ret_val = coreotn_dmx_ghao_wait_for_norm_ack(digi_handle->coreotn_handle,
                                                     ghao_mux_stage,
                                                     &coreotn_ho_chnl_id,
                                                     &coreotn_lo_chnl_id,
                                                     &local_ghao_segment->coreotn_rx_tpid,
                                                     local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX DEC 2 NORM_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_dec_2_norm_ack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_dec_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for LINE<->MAP decrease
*   segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_dec_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 mux_passthru;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 cal_add_remove[96];
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    mux_passthru = local_ghao_segment->mux_passthru;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX DEC 3 IDLE_NACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 48) MUX (Stage 2-3A): Turn valid off on last to-be-removed Calendar (by clear EXP.LO_FIRST_CYCLE).\n");
            ret_val = coreotn_mux_ghao_recfg_exp_lo_calen(digi_handle->coreotn_handle,
                                                          COREOTN_MUX_STAGE_TWO,
                                                          ghao_segment_id,
                                                          local_ghao_segment->coreotn_tx_cal_to_add_remove[local_ghao_segment->cal_to_add_remove_num-1]);
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 49) MPMO (stage 3B): Turn valid off  on the last to-be-removed calendar\n");
        for(i=0;i< local_ghao_segment->fo1_mpmo_userbit_update_pre_post_fw;i++)
        {
            cal_add_remove[i] = local_ghao_segment->coreotn_tx_cal_to_add_remove[local_ghao_segment->cal_to_add_remove_num-(i+1)];
        }
        ret_val = coreotn_mpmo_update_userbit_mask(digi_handle->coreotn_handle,
                                                   COREOTN_MPMO_TO_COREOTN,
                                                   coreotn_lo_chnl_id,
                                                   cal_add_remove,
                                                   local_ghao_segment->fo1_mpmo_userbit_update_pre_post_fw,
                                                   local_ghao_segment->coreotn_tx_old_cal_mask,
                                                   local_ghao_segment->coreotn_mpmo3b_userbits_mask);

    }

    if (ret_val == PMC_SUCCESS)
    {
        /* in the LCR resize, it's required keep the DPI calendar >= to the DCI
        calendar.  It's required to change the ODUKSW calendar after removing
        the userbits */
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : DB) Setup database UTIL_GEN_DB_OCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_MAPOTN_COREOTN,
                                                   coreotn_lo_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 49c) ODUk Switch (MAP -> LINE): Change Calendar to final TS\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 DIGI_GHAO_ODUKSW_MAPOTN_COREOTN,
                                                 coreotn_lo_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 49e) MPMO (Stage 3B): Decrease XOFF threshold\n");
        for(i=0;i<local_ghao_segment->fo1_mpmo_thresh_pre_post_fw ;i++)
        {
            ret_val = coreotn_mpmo_xoff_thresh_change(digi_handle->coreotn_handle,
                                                      COREOTN_MPMO_TO_COREOTN,
                                                      coreotn_lo_chnl_id,
                                                      ghao_increase);
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 49f) MPMO (Stage 3B): Change FIFO to final size\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_COREOTN,
                                                                 coreotn_lo_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }

    /* perform XOFF on 1st FMF1 if needed*/
    if (ret_val == PMC_SUCCESS)
    {
        for(i=0;i<digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw ;i++)
        {
            PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 49d) MUX (EXP Stage 1-2 and Stage 2-3A): Decrease XOFF threshold by 1TS equivalent every 2.5s\n ");
            ret_val = coreotn_odtu_mux_xoff_thresh_update(digi_handle->coreotn_handle,
                                                          ghao_mux_stage,
                                                          coreotn_lo_chnl_id,
                                                          FALSE,
                                                          &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].coreotn_mux_xoff_thresh);
        }
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 51) MPMO (stage 3B): Change Calendar to new configuration.\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_COREOTN,
                                                                coreotn_lo_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->coreotn_tx_new_cal_mask,
                                                                local_ghao_segment->coreotn_tx_new_cal_mask);
    }

    if (ghao_mux_stage == COREOTN_MUX_STAGE_ONE && mux_passthru == TRUE)
    {
        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 52) MUX (Stage 2-3A): Reconfigure MUX passthru to clear configuration on all to-be-removed calendar slots.\n");
            ret_val = coreotn_mux_ghao_recfg_passthru(digi_handle->coreotn_handle,
                                                      COREOTN_MUX_STAGE_TWO,
                                                      ghao_segment_id);
        }


        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 53) MUX (Stage 2-3A): Change FIFO to final size\n");
            ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                                   COREOTN_MUX_STAGE_TWO,
                                                   ghao_segment_id);
        }


        for(i=0;i<digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_passthru_thresh_pre_post_fw ;i++)
        {
            PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 53a) MUX (EXP Stage 2-3A): Decrease XOFF threshold by 1TS equivalent every 2.5s\n ");
            ret_val = coreotn_odtu_mux_xoff_thresh_update(digi_handle->coreotn_handle,
                                                          COREOTN_MUX_STAGE_TWO,
                                                          coreotn_lo_chnl_id,
                                                          FALSE,
                                                          &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].coreotn_mux_passthru_xoff_thresh);
        }

        for(i=0;i<digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fmf2_mux_cal_en_pre_post_fw;i++)
        {
            if (ret_val == PMC_SUCCESS)
            {
               PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 53b) MUX (EXP Stage 2-3A): removed last calendat valid\n ");

                ret_val = coreotn_mux_ghao_passthru_cal_enable_diable(digi_handle->coreotn_handle,
                                                                      local_ghao_segment->coreotn_tx_cal_to_add_remove[local_ghao_segment->cal_to_add_remove_num-(i+1)],
                                                                      FALSE);
            }
        }

    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 54) MUX (Stage 1-2): Change expand FIFO to final size\n");
        ret_val = coreotn_mux_ghao_resize_fifo(digi_handle->coreotn_handle,
                                               ghao_mux_stage,
                                               ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 55) MUX(Stage 1-2): Finish LCR by sending [IDLE, 0, NACK] for every added TS at the RMF.\n");
        ret_val = coreotn_mux_ghao_send_idle_nack(digi_handle->coreotn_handle,
                                                  ghao_mux_stage,
                                                  ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 55b) MUX (Stage 1-2): Synchronize standby page with active page\n");
        ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                       ghao_mux_stage,
                                                       ghao_segment_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_3 : 55c) MUX: Wait until config update is done\n");
        ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX DEC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_dec_3_idle_nack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_dec_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for LINE<->MAP decrease
*   segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_dec_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 cal_add_remove[96];
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX DEC 3 IDLE_NACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 49a) MPMA(Stage 3B): Change  FIFO size to final TS\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_TO_COREOTN,
                                                coreotn_lo_chnl_id,
                                                local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 49b) MPMO (Stage 4): Turn valid off  on the last to-be-removed calendar\n");
        for(i=0;i< local_ghao_segment->fo2_mpmo_userbit_update_pre_post_fw;i++)
        {
            cal_add_remove[i] = local_ghao_segment->mapotn_mpma_cal_to_add_remove[local_ghao_segment->cal_to_add_remove_num-(i+1)];
        }
        ret_val = coreotn_mpmo_update_userbit_mask(digi_handle->coreotn_handle,
                                                   COREOTN_MPMO_TO_MAPOTN,
                                                   mapotn_chnl_id,
                                                   cal_add_remove,
                                                   local_ghao_segment->fo2_mpmo_userbit_update_pre_post_fw,
                                                   local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                   local_ghao_segment->coreotn_mpmo4_userbits_mask);
    }

    if (ret_val == PMC_SUCCESS)
    {
        /* in the LCR resize, it's required keep the DPI calendar >= to the DCI
        calendar.  It's required to change the ODUKSW calendar after removing
        the userbits */
        PMC_LOG_TRACE("G.HAO LCR resize dec : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_ODUKSW_COREOTN_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 55) DMX(Stage 1-2): Wait to receive [IDLE, 0, NACK] on every added TS to exit LCR.\n");
        ret_val = coreotn_dmx_ghao_wait_for_idle_nack(digi_handle->coreotn_handle,
                                                      ghao_mux_stage,
                                                      &coreotn_ho_chnl_id,
                                                      &coreotn_lo_chnl_id,
                                                      &local_ghao_segment->coreotn_rx_tpid,
                                                      local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 55d) DMX (Stage 1-2): Wait until config update is done\n");
        ret_val = coreotn_dmx_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           coreotn_ho_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 55e) DMX (Stage 1-2): Synchronize standby page with active page\n");
        ret_val = coreotn_dmx_ghao_update_stdby_config_after_knife_edge(digi_handle->coreotn_handle,
                                                                        ghao_mux_stage,
                                                                        coreotn_ho_chnl_id,
                                                                        coreotn_lo_chnl_id,
                                                                        local_ghao_segment->ts_target,
                                                                        local_ghao_segment->new_trib_slot_mask_rx,
                                                                        local_ghao_segment->coreotn_rx_tpid,
                                                                        local_ghao_segment->ghao_increase,
                                                                        local_ghao_segment->cal_to_add_remove_num,
                                                                        local_ghao_segment->coreotn_rx_cal_to_add_remove);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX DEC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_dec_3_idle_nack */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_tx_dec_4_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 4 (rp) for LINE<->MAP decrease segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_tx_dec_4_rp(digi_handle_t *digi_handle,
                                                               UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 dummy_userbit_mask[3] = {0,0,0};
    UINT32 dummy_set_mask[3] = {0,0,0};

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX DEC 4 RP\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_4 : 56) After receiving IDLE NACK in the DMX, then the MUX  can set RP = 0.\n");
        ret_val = coreotn_mux_ghao_send_rp(digi_handle->coreotn_handle,
                                           ghao_mux_stage,
                                           ghao_segment_id,
                                           0);
    }


    /* Perform clean-up */
    /* take MPMOs out of custom userbit mode */
    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge tx_dec_4 : 56b) Take MPMO (Stage 3B) out of custom userbit mode\n");
        ret_val = coreotn_mpmo_set_custom_userbit_mask(digi_handle->coreotn_handle,
                                                       coreotn_lo_chnl_id,
                                                       COREOTN_MPMO_TO_COREOTN,
                                                       FALSE,
                                                       dummy_userbit_mask,
                                                       dummy_set_mask,
                                                       FALSE);
    }

    
    /* After changing the last tribslot, two bits will be set in
    TC_WR_IPT_VALID.  It's required to remove the "old" valid*/
    if(ret_val == PMC_SUCCESS)
    {
        ret_val = coreotn_mux_ghao_clear_old_last_cal_slot(digi_handle->coreotn_handle, 
                                                           ghao_mux_stage,
                                                           coreotn_lo_chnl_id,
                                                           ghao_increase,
                                                           local_ghao_segment->coreotn_tx_old_trib_slots,
                                                           local_ghao_segment->coreotn_tx_new_trib_slots,
                                                           local_ghao_segment->coreotn_tx_old_cal_mask);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX DEC 4 RP\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_tx_dec_4_rp */



/*******************************************************************************
* digi_ghao_line_map_lcr_knife_edge_rx_dec_4_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 4 (rp) for LINE<->MAP decrease segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_lcr_knife_edge_rx_dec_4_rp(digi_handle_t *digi_handle,
                                                               UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    coreotn_mux_stage_t ghao_mux_stage;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 dummy_userbit_mask[3] = {0,0,0};
    UINT32 dummy_set_mask[3] = {0,0,0};

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX DEC 4 RP\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_4 : 56) DMX, wait to receive RP = 0 and terminate G.HAO protocol.\n");
        ret_val = coreotn_dmx_ghao_wait_for_rp(digi_handle->coreotn_handle,
                                               ghao_mux_stage,
                                               &coreotn_ho_chnl_id,
                                               &coreotn_lo_chnl_id,
                                               &local_ghao_segment->coreotn_rx_tpid,
                                               local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }
    

    /* Perform clean-up */
    /* take MPMOs out of custom userbit mode */
    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_4 : 56b) Take MPMO (Stage 4) out of custom userbit mode\n");
        ret_val = coreotn_mpmo_set_custom_userbit_mask(digi_handle->coreotn_handle,
                                                       mapotn_chnl_id,
                                                       COREOTN_MPMO_TO_MAPOTN,
                                                       FALSE,
                                                       dummy_userbit_mask,
                                                       dummy_set_mask,
                                                       FALSE);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX DEC 4 RP\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_line_map_lcr_knife_edge_rx_dec_4_rp */



/*******************************************************************************
* digi_ghao_line_map_bwr_setup_tx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 1 (tscc) for LINE<->MAP decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_setup_tx_1_tscc(digi_handle_t *digi_handle,
                                                        UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 ghao_increase;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    ts_target = local_ghao_segment->ts_target;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup TX 1 TSCC\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        /* set up ODUKSC in MAPOTN to begin ramp */
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 32a/3a)	ODUk SC (MAPOTN): Set up ODUkSc to begin RAMP. But don't begin ramp \n");
        ret_val = mapotn_oduksc_ramp_prov(digi_handle->mapotn_handle,
                                          mapotn_chnl_id,
                                          ts_target,
                                          END_FOR_BWR_IND_250US);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 33/4) MPMO (stage 3B): set target rate and set into GMP special mode. (get ready for ramp)  \n");
        ret_val = coreotn_ghao_mpmo_bwr_rate_param_set(digi_handle->coreotn_handle,
                                                       COREOTN_MPMO_TO_COREOTN,
                                                       coreotn_lo_chnl_id,
                                                       ts_target,
                                                       ghao_increase);
    }

    if(ret_val == PMC_SUCCESS)
    {
        
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 34/5) MPMA (Stage 4) : Disable MPMA DSP  \n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_FROM_MAPOTN,
                                                   mapotn_chnl_id,
                                                   FALSE,
                                                   0);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 35/6) MUX (Stage 1-2): Set TSCC bit on all TS to be sent  \n");
        ret_val = coreotn_mux_ghao_send_tscc(digi_handle->coreotn_handle,
                                             ghao_mux_stage,
                                             ghao_segment_id,
                                             1);
    }


    PMC_LOG_TRACE("End G.HAO BWR setup TX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_setup_tx_1_tscc */



/*******************************************************************************
* digi_ghao_line_map_bwr_setup_rx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 1 (tscc) for LINE<->MAP decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_setup_rx_1_tscc(digi_handle_t *digi_handle,
                                                        UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 coreotn_ho_chnl_id;
    UINT8 coreotn_lo_chnl_id;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    coreotn_mux_stage_t ghao_mux_stage;
    BOOL8 ghao_increase;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;
    ts_target = local_ghao_segment->ts_target;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup RX 1 TSCC\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        /* set up ODUKSC in COREOTN to begin ramp */
        PMC_LOG_TRACE("G.HAO BWR set-up rx_1 : 32b/3b) ODUk SC (COREOTN): Set up ODUkSc to begin RAMP. But don't begin ramp \n");
        ret_val = coreotn_oduksc_ramp_prov(digi_handle->coreotn_handle,
                                           ghao_mux_stage,
                                           coreotn_lo_chnl_id,
                                           ts_target);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR start : 39b/11b) ODUkSc (COREOTN): Begins ramp after RFRM(3A) BWR_IND received.\n");
        ret_val = coreotn_oduksc_ramp_start(digi_handle->coreotn_handle,
                                            local_ghao_segment->ghao_mux_stage,
                                            coreotn_lo_chnl_id);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_1 : 36/7) DMX(Stage 1-2): Wait to receive TSCC bit on all TS  \n");
        ret_val = coreotn_dmx_ghao_wait_for_tscc(digi_handle->coreotn_handle,
                                                 ghao_mux_stage,
                                                 &coreotn_ho_chnl_id,
                                                 &coreotn_lo_chnl_id,
                                                 &local_ghao_segment->coreotn_rx_tpid,
                                                 local_ghao_segment->coreotn_rx_trib_slots_add_rem,
                                                 1);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_1 : 37a/8a) MPMO (Stage 4) : Set BWR parameters  \n");
        ret_val = coreotn_ghao_mpmo_bwr_rate_param_set(digi_handle->coreotn_handle,
                                                       COREOTN_MPMO_TO_MAPOTN,
                                                       mapotn_chnl_id,
                                                       ts_target,
                                                       ghao_increase);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_1 : 37b/8b) MPMA (Stage 3B) : Disable MPMA DSP  \n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_TO_COREOTN,
                                                   coreotn_lo_chnl_id,
                                                   FALSE,
                                                   0);
    }


    PMC_LOG_TRACE("End G.HAO BWR setup RX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_setup_rx_1_tscc */



/*******************************************************************************
* digi_ghao_line_map_bwr_setup_tx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 2 (ncs) for LINE<->MAP decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_setup_tx_2_ncs(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    BOOL8 ghao_increase;
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup TX 2 NCS\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up tx_2 : 38a/9) TGFP: Set NCS bit to 1.\n");
        ret_val = mapotn_tgfpf_rcoh_ncs_set(digi_handle->mapotn_handle,
                                            mapotn_chnl_id,
                                            1);
    }

    if(!ghao_increase)
    {
        /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
        for(i = 0; i< 3; i++)
        {
            local_ghao_segment->coreotn_mpmo3b_userbits_mask[i] = local_ghao_segment->coreotn_tx_old_cal_mask[i];
        }
    }

    PMC_LOG_TRACE("End G.HAO BWR setup TX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_setup_tx_2_ncs */



/*******************************************************************************
* digi_ghao_line_map_bwr_setup_rx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 2 (ncs) for LINE<->MAP decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_setup_rx_2_ncs(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    BOOL8 ghao_increase;
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup RX 2 NCS\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_2 : 38b/10) RGFP: Wait to receive NCS bit.\n");
        ret_val = mapotn_rgfpf_rcoh_ncs_poll(digi_handle->mapotn_handle,
                                             mapotn_chnl_id,
                                             1,
                                             50);
#ifdef PMC_SW_SIMULATION
        ret_val = PMC_SUCCESS;
#endif
    }


    if(!ghao_increase)
    {
        /* Initialize userbit to old cal mask for COREOTN and MAPOTN */
        for(i = 0; i< 3; i++)
        {
            local_ghao_segment->coreotn_mpmo4_userbits_mask[i] = local_ghao_segment->mapotn_mpma_old_cal_mask[i];
        }
    }

    PMC_LOG_TRACE("End G.HAO BWR setup RX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_setup_rx_2_ncs */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_start_tx
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Starts the ramp in TX. Triggers the firmware routine that will perform the
*   per TS ramp in the datapath.  It is required that this API is called
*   on all intermediate nodes before it is called for source nodes.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_start_tx(digi_handle_t *digi_handle,
                                                      UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    BOOL mux_passthru;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    mux_passthru = local_ghao_segment->mux_passthru;

    /* perform bwr start operation */

    PMC_LOG_TRACE("Start G.HAO BWR start TX\n");

    if(ret_val == PMC_SUCCESS)
    {
        
        PMC_LOG_TRACE("G.HAO BWR start : 39a/11a) TGFP: Set BWR_IND bit in OHFS_INSERT\n");
        PMC_LOG_TRACE("G.HAO BWR start : 39b/11b) ODUkSc (MAPOTN): Trigger Ramp in the range of 125us to 250us after setting the BWR_IND bit.\n");
        
        /* this API set BWR_IND and starts the ramp */
        ret_val = mapotn_oduksc_ramp_start(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           TRUE);
    }

    
    /* Update pre-firmware operations done */
    if (local_ghao_segment->ghao_increase)
    {

        if(mux_passthru == FALSE)
        {
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = MPMO_XOFF_INC_PRE_WO_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
              /*on an increase, one xoff threshold adjustment is performed before the firmware
              to avoid underflows in the EXP CFC*/
              if(digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start == 1)
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_INC_PRE_W0_PASSTHRU_FROM1;
              }
              else
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_INC_PRE_W0_PASSTHRU;
              }
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = MPMO_USERBIT_INC_PRE_WO_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;
        }
        else
        {
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = MPMO_XOFF_INC_PRE_W_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
              
              if(digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start == 1)
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_INC_PRE_W_PASSTHRU_FROM1;
              }
              else
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_INC_PRE_W_PASSTHRU;
              }

              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = MPMO_USERBIT_INC_PRE_WO_PASSTHRU; /*MPMO_USERBIT_INC_PRE_W_PASSTHRU;*/
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;

              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_passthru_thresh_pre_post_fw = FMF2_MUX_XOFF_INC_PRE_W_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fmf2_mux_cal_en_pre_post_fw = FMF2_MUX_CAL_EN_INC_PRE_W_PASSTHRU;
        }
    }
    else
    {

        
        if(mux_passthru == FALSE)
        {

              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = MPMO_USERBIT_DEC_PRE_WO_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_DEC_PRE_W0_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;

              /*decreasing by 1 is a special case for userbit adjustments*/
              if( ((digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start 
                   - digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_target) == 1) &&
                   MPMO_USERBIT_DEC_PRE_WO_PASSTHRU > 1)
              {

                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = 1;
              }
              else
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = MPMO_USERBIT_DEC_PRE_WO_PASSTHRU;
              }


        }
        else
        {


              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = MPMO_XOFF_DEC_POST_W_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = FMF1_MUX_XOFF_DEC_POST_W_PASSTHRU;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;
              digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_passthru_thresh_pre_post_fw = FMF2_MUX_XOFF_DEC_POST_W_PASSTHRU;

              /*decreasing by 1 is a special case for userbit adjustments*/
              if( ((digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start 
                   - digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_target) == 1) &&
                   MPMO_USERBIT_DEC_POST_W_PASSTHRU > 1)
              {

                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = 1;
              }
              else
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = MPMO_USERBIT_DEC_POST_W_PASSTHRU;
              }


              /*decreasing by 1 is a special case for fmf2 cal adjustments*/
              if( ((digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_start 
                   - digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].ts_target) == 1) &&
                   FMF2_MUX_CAL_EN_DEC_POST_W_PASSTHRU > 1)
              {

                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fmf2_mux_cal_en_pre_post_fw = 1;
              }
              else
              {
                  digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fmf2_mux_cal_en_pre_post_fw = FMF2_MUX_CAL_EN_DEC_POST_W_PASSTHRU;
              }



        }


    }

    PMC_LOG_TRACE("End G.HAO BWR start TX\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_start_tx */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_start_rx
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Starts the ramp in RX. Triggers the firmware routine that will perform the
*   per TS ramp in the datapath.  It is required that this API is called
*   on all intermediate nodes before it is called for source nodes.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_start_rx(digi_handle_t *digi_handle,
                                                      UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT8 coreotn_lo_chnl_id;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;

    /* perform bwr start operation */

    PMC_LOG_TRACE("Start G.HAO BWR start RX\n");


    PMC_LOG_TRACE("Start G.HAO BWR start RX\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_start_rx */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_tx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 1 (tscc) for LINE<->MAP decrease segment in TX
*  This need to be called when the ramp is complete to put to datapath
*  back into normal operating more.
*
*  For source nodes, call once RAMP #2 done interrupt is seen
*  in MAPOTN-ODUKSC.
*
*  For intermediate nodes, call after source nodes have
*  completed.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_tx_1_tscc(digi_handle_t *digi_handle,
                                                           UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    DOUBLE odu_bitrate;
    UINT32 ts_target;
    UINT8 coreotn_lo_chnl_id;
    UINT8 coreotn_ho_chnl_id;
    UINT32 oif_pkt_size;
    UINT32 oif_header_size;
    coreotn_mux_stage_t ghao_mux_stage;

    UINT32 pkt_size_ptr;
    UINT32 pkt_per_int_ptr;
    UINT32 pkt_per_n_ptr;
    UINT32 pkt_per_d_ptr;
    DOUBLE eps_ptr;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    oif_pkt_size = local_ghao_segment->oif_pkt_size;
    oif_header_size = local_ghao_segment->header_size;

    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 1 TSCC\n");

    if (ts_target <= 8)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU2_TS_RATE);
    } 
    else if (ts_target <= 32)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU3_TS_RATE);
    } 
    else 
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU4_TS_RATE);
    }
    

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 41a/13a) MPMA (Stage 4): Set new Packet size, period and MPMA_DSP gain. \n");
        ret_val = coreotn_ghao_mpma_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMA_FROM_MAPOTN,
                                                      mapotn_chnl_id,
                                                      odu_bitrate,
                                                      oif_pkt_size,
                                                      oif_header_size,
                                                      FALSE,
                                                      &pkt_size_ptr,
                                                      &pkt_per_int_ptr,
                                                      &pkt_per_n_ptr,
                                                      &pkt_per_d_ptr,
                                                      &eps_ptr);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 41b/13b) MPMA (Stage 4): Turn on DSP. \n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_FROM_MAPOTN,
                                                   mapotn_chnl_id,
                                                   TRUE,
                                                   0);
    }

    
    PMC_LOG_TRACE("G.HAO BWR end tx_1 : 42/14)	Wait 3ms \n");

    /* wait 20 ms */
    PMC_Q_USLEEP(digi_handle,20000);

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 43/15) MPMO (Stage 3B): Set new Packet size, Cn_base(DSP) and take it out of GMP special mode. \n");
        ret_val = coreotn_ghao_mpmo_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMO_TO_COREOTN,
                                                      coreotn_lo_chnl_id,
                                                      odu_bitrate,
                                                      pkt_size_ptr,
                                                      pkt_per_int_ptr,
                                                      pkt_per_n_ptr,
                                                      pkt_per_d_ptr,
                                                      eps_ptr);
    }

    if (local_ghao_segment->ghao_increase)
    {
        if(ret_val == PMC_SUCCESS)
        {

            PMC_LOG_TRACE("G.HAO BWR end tx_1 : 44) MUX (Stage 1-2): Do a config_update to disable PREV_CN_SEL \n");

            ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                               ghao_mux_stage,
                                                               ghao_segment_id);        
        }

        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO BWR end tx_1 : 44b) MUX: Wait until config update is done\n");
            ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                               ghao_mux_stage,
                                                               coreotn_ho_chnl_id);
        }

        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO BWR end tx_1 : 44c) MUX (Stage 1-2): Synchronize standby page with active page\n");
            ret_val = coreotn_mux_ghao_update_stdby_config(digi_handle->coreotn_handle,
                                                           ghao_mux_stage,
                                                           ghao_segment_id);
        }

        if (ret_val == PMC_SUCCESS)
        {
            PMC_LOG_TRACE("G.HAO BWR end tx_1 : 44d) MUX: Wait until config update is done\n");
            ret_val = coreotn_mux_ghao_wait_config_update_done(digi_handle->coreotn_handle,
                                                               ghao_mux_stage,
                                                               coreotn_ho_chnl_id);
        }
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 45a/16a) MUX (Stage 1-2): Unset TSCC. \n");
        ret_val = coreotn_mux_ghao_send_tscc(digi_handle->coreotn_handle,
                                             ghao_mux_stage,
                                             ghao_segment_id,
                                             0);
    }


    PMC_LOG_TRACE("End G.HAO BWR end TX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_tx_1_tscc */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_rx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 1 (tscc) for LINE<->MAP decrease segment in RX
*  This need to be called when the ramp is complete to put to datapath
*  back into normal operating more.
*
*  For source nodes, call once RAMP #2 done interrupt is seen
*  in MAPOTN-ODUKSC.
*
*  For intermediate nodes, call after source nodes have
*  completed.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_rx_1_tscc(digi_handle_t *digi_handle,
                                                           UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    DOUBLE odu_bitrate;
    UINT32 ts_target;
    UINT8 coreotn_lo_chnl_id;
    UINT8 coreotn_ho_chnl_id;
    UINT32 oif_pkt_size;
    UINT32 oif_header_size;
    coreotn_mux_stage_t ghao_mux_stage;

    UINT32 pkt_size_ptr;
    UINT32 pkt_per_int_ptr;
    UINT32 pkt_per_n_ptr;
    UINT32 pkt_per_d_ptr;
    DOUBLE eps_ptr;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    oif_pkt_size = local_ghao_segment->oif_pkt_size;
    oif_header_size = local_ghao_segment->header_size;

    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 1 TSCC\n");

    if (ts_target <= 8)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU2_TS_RATE);
    } 
    else if (ts_target <= 32)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU3_TS_RATE);
    } 
    else 
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU4_TS_RATE);
    }
    

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_1 : 45b/16b) DMX (Stage 1-2): Wait till TSCC is unset. \n");
        ret_val = coreotn_dmx_ghao_wait_for_tscc(digi_handle->coreotn_handle,
                                                 ghao_mux_stage,
                                                 &coreotn_ho_chnl_id,
                                                 &coreotn_lo_chnl_id,
                                                 &local_ghao_segment->coreotn_rx_tpid,
                                                 local_ghao_segment->coreotn_rx_trib_slots_add_rem,
                                                 0);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_1 : 46a/17a) MPMA (Stage 3B): Set new Packet size, period and MPMA_DSP gain. \n");
        ret_val = coreotn_ghao_mpma_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMA_TO_COREOTN,
                                                      coreotn_lo_chnl_id,
                                                      odu_bitrate,
                                                      oif_pkt_size,
                                                      oif_header_size,
                                                      FALSE,
                                                      &pkt_size_ptr,
                                                      &pkt_per_int_ptr,
                                                      &pkt_per_n_ptr,
                                                      &pkt_per_d_ptr,
                                                      &eps_ptr);
    }

    
    /*before turning on the DSP, */


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_1 : 46b/17b) MPMA (Stage 3B): Turn on DSP. \n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_TO_COREOTN,
                                                   coreotn_lo_chnl_id,
                                                   TRUE,
                                                   ts_target);
    }

    
    PMC_LOG_TRACE("G.HAO BWR end rx_1 : 47) Wait 3ms \n");

    /* wait 20 ms */
    PMC_Q_USLEEP(digi_handle,20000);

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_1 : 48/19) MPMO (Stage 4): Set new Packet size, Cn_base(DSP) and take it out of GMP special mode. \n");
        ret_val = coreotn_ghao_mpmo_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMO_TO_MAPOTN,
                                                      mapotn_chnl_id,
                                                      odu_bitrate,
                                                      pkt_size_ptr,
                                                      pkt_per_int_ptr,
                                                      pkt_per_n_ptr,
                                                      pkt_per_d_ptr,
                                                      eps_ptr);
    }


    PMC_LOG_TRACE("End G.HAO BWR end RX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_rx_1_tscc */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_tx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 2 (ncs) for LINE<->MAP decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_tx_2_ncs(digi_handle_t *digi_handle,
                                                          UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    
    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 2 NCS\n");

    if(ret_val == PMC_SUCCESS)
    {
        
        PMC_LOG_TRACE("G.HAO BWR end tx_2 : 49/20) TGFP: unset NCS bit\n");

        ret_val = mapotn_tgfpf_rcoh_ncs_set(digi_handle->mapotn_handle,
                                            mapotn_chnl_id,
                                            0);
    }


    PMC_LOG_TRACE("End G.HAO BWR end TX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_tx_2_ncs */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_rx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 2 (ncs) for LINE<->MAP decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_rx_2_ncs(digi_handle_t *digi_handle,
                                                          UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 2 NCS\n");

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_2 : 49/20) RGFP: wait for NCS bit to be unset.\n");
        ret_val = mapotn_rgfpf_rcoh_ncs_poll(digi_handle->mapotn_handle,
                                             mapotn_chnl_id,
                                             0,
                                             50);
#ifdef PMC_SW_SIMULATION
        ret_val = PMC_SUCCESS;
#endif
    }


    PMC_LOG_TRACE("End G.HAO BWR end RX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_rx_2_ncs */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_tx_3_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 3 (rp) for LINE<->MAP decrease segment in TX
*  This API will deprovision the G.HAO segment and free up the ghao_segment_id
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_tx_3_inc_rp(digi_handle_t *digi_handle,
                                                             UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    UINT8 coreotn_lo_chnl_id;
    UINT8 coreotn_ho_chnl_id;
    coreotn_mux_stage_t ghao_mux_stage;
    UINT32 dummy_userbit_mask[3] = {0,0,0};
    UINT32 dummy_set_mask[3] = {0,0,0};

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 3 RP\n");

    if (!local_ghao_segment->ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_3 : 50a) Remove RP bit out of MUX \n");
        ret_val = coreotn_mux_ghao_send_rp(digi_handle->coreotn_handle,
                                           ghao_mux_stage,
                                           ghao_segment_id,
                                           0);
    }

    /* Perform clean-up */
    /* take MPMOs out of custom userbit mode */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_3 : 50c) Take MPMO (Stage 3B) out of custer userbit mode\n");
        ret_val = coreotn_mpmo_set_custom_userbit_mask(digi_handle->coreotn_handle,
                                                       coreotn_lo_chnl_id,
                                                       COREOTN_MPMO_TO_COREOTN,
                                                       FALSE,
                                                       dummy_userbit_mask,
                                                       dummy_set_mask,
                                                       FALSE);
    }


    PMC_LOG_TRACE("End G.HAO BWR end TX 3 RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_tx_3_inc_rp */



/*******************************************************************************
* digi_ghao_line_map_bwr_ramp_end_rx_3_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 3 (rp) for LINE<->MAP decrease segment in RX
*  This API will deprovision the G.HAO
*  segment and free up the ghao_segment_id
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_line_map_bwr_ramp_end_rx_3_inc_rp(digi_handle_t *digi_handle,
                                                             UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    UINT8 coreotn_lo_chnl_id;
    UINT8 coreotn_ho_chnl_id;
    coreotn_mux_stage_t ghao_mux_stage;
    UINT32 dummy_userbit_mask[3] = {0,0,0};
    UINT32 dummy_set_mask[3] = {0,0,0};

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    coreotn_ho_chnl_id = (UINT8) local_ghao_segment->coreotn_ho_chnl_id;
    coreotn_lo_chnl_id = (UINT8) local_ghao_segment->coreotn_lo_chnl_id;
    ghao_mux_stage = local_ghao_segment->ghao_mux_stage;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 3 RP\n");

    if (!local_ghao_segment->ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_3 : 50b) Wait in DMX for RP bit to be unset. G. HAO is finished. \n");
        ret_val = coreotn_dmx_ghao_wait_for_rp(digi_handle->coreotn_handle,
                                               ghao_mux_stage,
                                               &coreotn_ho_chnl_id,
                                               &coreotn_lo_chnl_id,
                                               &local_ghao_segment->coreotn_rx_tpid,
                                               local_ghao_segment->coreotn_rx_trib_slots_add_rem);
    }

    /* Perform clean-up */
    /* take MPMOs out of custom userbit mode */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_3 : 50c) Take MPMO (Stage 4) out of custer userbit mode\n");
        ret_val = coreotn_mpmo_set_custom_userbit_mask(digi_handle->coreotn_handle,
                                                       mapotn_chnl_id,
                                                       COREOTN_MPMO_TO_MAPOTN,
                                                       FALSE,
                                                       dummy_userbit_mask,
                                                       dummy_set_mask,
                                                       FALSE);
    }


    PMC_LOG_TRACE("End G.HAO BWR end RX 3 RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_line_map_bwr_ramp_end_rx_3_inc_rp */





/******************************************************************************** 
* This section of the file contains C functions for G.HAO MAP <-> ILKN segement.
********************************************************************************/

/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_tx_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for MAP<->ILKN increase segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_tx_inc_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX INC RP\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }



    PMC_LOG_TRACE("End G.HAO LCR resize TX INC RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_tx_inc_rp */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_rx_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for MAP<->ILKN increase segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_rx_inc_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX INC RP\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }



    PMC_LOG_TRACE("End G.HAO LCR resize RX INC RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_rx_inc_rp */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_tx_inc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for MAP<->ILKN increase segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_tx_inc(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    util_global_oduk_port_t sifd_port_type;
    digi_ghao_cpb_datapath_t oduksw_datapath;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_port_type = ((util_global_oduk_port_data_t*)digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].sifd_ptr)->port_type;
    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX INC\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Databases for TX datapath */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_ODUKSC_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_ODUKSC_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                 local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 dummy_mapotn_oduksc_cal_to_add_remove);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_DCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    if(sifd_port_type == UTIL_GLOBAL_ODUK_PORT_ILKN1)
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_MAPOTN_SIFD1;
    }
    else
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_MAPOTN_SIFD2;
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   oduksw_datapath,
                                                   sifd_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {

        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 3) ODUk Switch (MAP -> SIFD): Configure FIFO for the ending number of TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               (UINT32)sifd_port_type,
                                                               sifd_chnl_id,
                                                               local_ghao_segment->ts_target*2,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 4)	MPMA(stage 4): Configure for FIFO to final TS count\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_FROM_MAPOTN,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 6) TGFP : Change FIFO's sizes and thresholds to final TS count.\n");
        ret_val = mapotn_tgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 7) CPB (Towards TGFP): Change Calendar to final TS value.\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                mapotn_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 8) ODUk SC (MAPOTN): Change Calendar to final Calendar. Credit should be scaled down to reflect old BW.\n");
        ret_val = mapotn_oduksc_scbs3_cgen_reprov(digi_handle->mapotn_handle,
                                                  mapotn_chnl_id,
                                                  local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 9) MPMA (stage 4): Change Calendar to final TS count\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_FROM_MAPOTN,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_inc : 10) ODUk Switch (MAP -> SIFD) : Change Calendar to final TS count\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 oduksw_datapath,
                                                 sifd_chnl_id);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize TX INC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_tx_inc */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_rx_inc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_rx_inc(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 i;
    util_global_oduk_port_t sifd_port_type;
    digi_ghao_cpb_datapath_t oduksw_datapath;
    UINT32 j;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_port_type = ((util_global_oduk_port_data_t*)digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].sifd_ptr)->port_type;
    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX INC\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_MPMA_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_MPMA_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                 local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }

    if(sifd_port_type == UTIL_GLOBAL_ODUK_PORT_ILKN1)
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_SIFD1_MAPOTN;
    }
    else
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_SIFD2_MAPOTN;
    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   oduksw_datapath,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {


        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 13) ODUk Switch (SIFD -> MAP): Change FIFO size to final TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_MAPOTN,
                                                               mapotn_chnl_id,
                                                               local_ghao_segment->ts_target*2,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }



    /*Pinch the ODUKSW port 3 entries so that only the starting calendar entries
    are set (the entries are added during the ramp */
    if (ret_val == PMC_SUCCESS)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<32;j++)
            {
                if(((local_ghao_segment->mapotn_oduksc_new_cal_mask[i] >> j) & 1) == 1)
                {
                    if(((local_ghao_segment->mapotn_oduksc_old_cal_mask[i] >> j) & 1) == 1)
                    {
                        ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                        (32*i)+j,
                                                                        FALSE);
                    }
                    else
                    {
                        ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                        (32*i)+j,
                                                                        TRUE);
                    }
                }
            }
        }
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   oduksw_datapath,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 12) MPMO (Stage 4): Increase FIFO to final TS size. Do not change final XOFF threshold value.\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_MAPOTN,
                                                                 mapotn_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 14) RGFP: Increase the unpacking and egress FIFO to final TS size.\n");
        ret_val = mapotn_rgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 17) ODUk (SIFD -> MAP) : Change the Calendar to final TS. NOTE: Calendar burstiness adds noise to continuous pacing, we should be aware of this.\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 oduksw_datapath,
                                                 mapotn_chnl_id);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 18) MPMO (stage 4): Change the Calendar to final TS, but make sure the user bits for the new calendar entries are disabled (i.e pinch calendars).\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_MAPOTN,
                                                                mapotn_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                                local_ghao_segment->mapotn_mpma_old_cal_mask);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_inc : 19) MPMA (MAPOTN): Change the Calendar to final TS.\n");
        ret_val = mapotn_mpma_scbs3_reprov(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           local_ghao_segment->ts_target);
    }


    /* Initialize userbit to old cal mask for MAPOTN */
    for(i = 0; i< 3; i++)
    {
        local_ghao_segment->coreotn_mpmo4_userbits_mask[i] = local_ghao_segment->mapotn_mpma_old_cal_mask[i];
    }


    PMC_LOG_TRACE("End G.HAO LCR resize RX INC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_rx_inc */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_tx_dec_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for MAP<->ILKN decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_tx_dec_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX DEC RP\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec_rp : 0) Extract added/removed calendar slots for ODUKSC\n");
        ret_val = mapotn_ghao_db_chnl_get_masks(digi_handle->mapotn_handle,
                                                UTIL_GEN_DB_ODUKSC_DB,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target,
                                                local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                &local_ghao_segment->cal_to_add_remove_num,
                                                dummy_mapotn_oduksc_cal_to_add_remove);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize TX DEC RP\n");


    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_tx_dec_rp */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_rx_dec_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Initialize the LCR step for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_rx_dec_rp(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX DEC RP\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec_rp : 0) Extract added/removed calendar slots for MPMA\n");
        ret_val = mapotn_ghao_db_chnl_get_masks(digi_handle->mapotn_handle,
                                                UTIL_GEN_DB_MPMA_DB,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target,
                                                local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                &local_ghao_segment->cal_to_add_remove_num,
                                                local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize RX DEC RP\n");


    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_rx_dec_rp */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_tx_dec
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for MAP<->ILKN decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_tx_dec(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    util_global_oduk_port_t sifd_port_type;
    digi_ghao_cpb_datapath_t oduksw_datapath;
    UINT32 i,j;
    UINT32 dummy_mapotn_oduksc_cal_to_add_remove[79];

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_port_type = ((util_global_oduk_port_data_t*)digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].sifd_ptr)->port_type; 
    
    PMC_LOG_TRACE("Start G.HAO LCR resize TX DEC\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    /* Databases for TX datapath */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_ODUKSC_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_ODUKSC_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_oduksc_old_cal_mask,
                                                 local_ghao_segment->mapotn_oduksc_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 dummy_mapotn_oduksc_cal_to_add_remove);
    }

    /*after ODUKSC DB is updated, calendar pinch mode can now be removed from DCS */
    if (ret_val == PMC_SUCCESS)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<32;j++)
            {
                if(((local_ghao_segment->mapotn_oduksc_old_cal_mask[i] >> j) & 1) == 1)
                {
                    ret_val = coreotn_dcs_to_mapotn_pinch_entry_set(digi_handle->coreotn_handle,
                                                                    (32*i)+j,
                                                                    FALSE);
                }
            }
        }
    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_DCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }



    if(sifd_port_type == UTIL_GLOBAL_ODUK_PORT_ILKN1)
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_MAPOTN_SIFD1;
    }
    else
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_MAPOTN_SIFD2;
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : DB) Setup database UTIL_GEN_DB_OCPB_DCS TX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   oduksw_datapath,
                                                   sifd_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    /* TGFP -> MUX direction: */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 30) ODUk Switch (MAP -> SIFD) : Change Calendar to final TS count\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                 oduksw_datapath,
                                                 sifd_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 31) MPMA (stage 4): Change Calendar to final TS count\n");
        ret_val = coreotn_mpma_ghao_scbs3_reprov(digi_handle->coreotn_handle,
                                                 COREOTN_MPMA_FROM_MAPOTN,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 32) ODUk SC (MAPOTN): Change Calendar to final Calendar. Credit should be scaled accordingly.\n");
        ret_val = mapotn_oduksc_scbs3_cgen_reprov(digi_handle->mapotn_handle,
                                                  mapotn_chnl_id,
                                                  local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 33) CPB (Towards TGFP): Change Calendar to final TS value.\n");
        ret_val = digi_ghao_cpb_dcs_calendar_cfg(digi_handle,
                                                DIGI_GHAO_DCPB_SIFD_MAPOTN,
                                                mapotn_chnl_id);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 34) TGFP : Change FIFO's sizes and thresholds to final TS count.\n");
        ret_val = mapotn_tgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 36) MPMA(stage 4): Configure for FIFO to final TS count\n");
        ret_val = coreotn_mpma_ghao_fifo_resize(digi_handle->coreotn_handle,
                                                COREOTN_MPMA_FROM_MAPOTN,
                                                mapotn_chnl_id,
                                                local_ghao_segment->ts_target);
    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize tx_dec : 37) ODUk Switch (MAP -> SIFD): Configure FIFO for the ending number of TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               (UINT32)sifd_port_type,
                                                               sifd_chnl_id,
                                                               local_ghao_segment->ts_target*2,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    PMC_LOG_TRACE("End G.HAO LCR resize TX DEC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_tx_dec */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_size_rx_dec
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR resize step for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_size_rx_dec(digi_handle_t *digi_handle,
                                                    UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    util_global_oduk_port_t sifd_port_type;
    digi_ghao_cpb_datapath_t oduksw_datapath;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_port_type = ((util_global_oduk_port_data_t*)digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].sifd_ptr)->port_type;
    
    PMC_LOG_TRACE("Start G.HAO LCR resize RX DEC\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }



    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : DB) Setup database UTIL_GEN_DB_MPMA_DB\n");
        ret_val = mapotn_ghao_db_chnl_rec_update(digi_handle->mapotn_handle,
                                                 UTIL_GEN_DB_MPMA_DB,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target,
                                                 local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                 local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                 &local_ghao_segment->cal_to_add_remove_num,
                                                 local_ghao_segment->mapotn_mpma_cal_to_add_remove);
    }

    if(sifd_port_type == UTIL_GLOBAL_ODUK_PORT_ILKN1)
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_SIFD1_MAPOTN;
    }
    else
    {
        oduksw_datapath = DIGI_GHAO_ODUKSW_SIFD2_MAPOTN;
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : DB) Setup database UTIL_GEN_DB_OCPB_DCS RX\n");
        ret_val = digi_ghao_cpb_db_chnl_rec_update(digi_handle,
                                                   oduksw_datapath,
                                                   mapotn_chnl_id,
                                                   local_ghao_segment->ts_target);
    }


    /* DMX -> RGFP */
    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 21) MPMA (MAPOTN): Change the Calendar to final TS.\n");
        ret_val = mapotn_mpma_scbs3_reprov(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 22) MPMO (stage 4): Change the Calendar to final TS, but make sure the user bits for the new calendar entries are disabled (i.e pinch calendars).\n");
        ret_val = coreotn_mpmo_ghao_scbs3_reprov_force_userbits(digi_handle->coreotn_handle,
                                                                COREOTN_MPMO_TO_MAPOTN,
                                                                mapotn_chnl_id,
                                                                local_ghao_segment->ts_target,
                                                                local_ghao_segment->mapotn_mpma_new_cal_mask,
                                                                local_ghao_segment->mapotn_mpma_old_cal_mask);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 26) MPMO (Stage 4): Change FIFO to final TS size. Do not change final XOFF threshold value.\n");
        ret_val = coreotn_mpmo_ghao_fifo_resize_no_thresh_update(digi_handle->coreotn_handle,
                                                                 COREOTN_MPMO_TO_MAPOTN,
                                                                 mapotn_chnl_id,
                                                                 local_ghao_segment->ts_target);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 27) ODUk Switch (SIFD -> MAP): Change FIFO size to final TS\n");
        ret_val = coreotn_oduksw_ghao_queue_resize_zone_update(digi_handle->coreotn_handle,
                                                               COREOTN_ODUKSW_OUTPUT_MAPOTN,
                                                               mapotn_chnl_id,
                                                               local_ghao_segment->ts_target*2,
                                                               local_ghao_segment->ts_target,
                                                               ghao_increase);
    }

    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR resize rx_dec : 28) RGFP: Change the unpacking and egress FIFO to final TS size.\n");
        ret_val = mapotn_rgfpf_cfc_thresh_reprov(digi_handle->mapotn_handle,
                                                 mapotn_chnl_id,
                                                 local_ghao_segment->ts_target);
    }


    PMC_LOG_TRACE("End G.HAO LCR resize RX DEC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_lcr_size_rx_dec */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_knife_edge_tx_inc_1_add_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (add ack) for MAP<->ILKN increase segment
*   in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_knife_edge_tx_inc_1_add_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX INC 1 ADD_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX INC 1 ADD_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_map_ilkn_lcr_knife_edge_tx_inc_1_add_ack */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_knife_edge_rx_inc_1_add_ack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 1 (add ack) for MAP<->ILKN increase segment
*   in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_knife_edge_rx_inc_1_add_ack(digi_handle_t *digi_handle,
                                                                    UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX INC 1 ADD_ACK\n");

    if (!ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }




    PMC_LOG_TRACE("End G.HAO LCR knife edge RX INC 1 ADD_ACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_map_ilkn_lcr_knife_edge_rx_inc_1_add_ack */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_knife_edge_tx_dec_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for MAP<->ILKN decrease
*   segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_knife_edge_tx_dec_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge TX DEC 3 IDLE_NACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge TX DEC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_map_ilkn_lcr_knife_edge_tx_dec_3_idle_nack */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_knife_edge_rx_dec_3_idle_nack
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge step 3 (idle nack) for MAP<->ILKN decrease
*   segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_knife_edge_rx_dec_3_idle_nack(digi_handle_t *digi_handle,
                                                                      UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT32 mapotn_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT32 cal_add_remove[96];
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge RX DEC 3 IDLE_NACK\n");

    if (ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    if (ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO LCR knife edge rx_dec_3 : 38b) MPMO (Stage 4): Turn valid off  on the last to-be-removed calendar\n");
        for(i=0;i< local_ghao_segment->fo2_mpmo_userbit_update_pre_post_fw;i++)
        {
            cal_add_remove[i] = local_ghao_segment->mapotn_mpma_cal_to_add_remove[local_ghao_segment->cal_to_add_remove_num-(i+1)];
        }
        ret_val = coreotn_mpmo_update_userbit_mask(digi_handle->coreotn_handle,
                                                   COREOTN_MPMO_TO_MAPOTN,
                                                   mapotn_chnl_id,
                                                   cal_add_remove,
                                                   local_ghao_segment->fo2_mpmo_userbit_update_pre_post_fw,
                                                   local_ghao_segment->mapotn_mpma_old_cal_mask,
                                                   local_ghao_segment->coreotn_mpmo4_userbits_mask);
    }


    PMC_LOG_TRACE("End G.HAO LCR knife edge RX DEC 3 IDLE_NACK\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_map_ilkn_lcr_knife_edge_rx_dec_3_idle_nack */



/*******************************************************************************
* digi_ghao_map_ilkn_lcr_knife_edge_ilkn
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the LCR knife edge ILKN step for MAP<->ILKN increase segment in
*   TX & RX
*  
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_lcr_knife_edge_ilkn(digi_handle_t *digi_handle,
                                                        UINT32 ghao_segment_id)
{
    PMC_ERROR ret_val = PMC_SUCCESS;

    UINT8 sifd_chnl_id;
    BOOL8 ghao_increase;
    digi_ghao_seg_ctrl_t *local_ghao_segment;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    ghao_increase = local_ghao_segment->ghao_increase;
    sifd_chnl_id = (UINT8) local_ghao_segment->sifd_chnl_id;

    
    PMC_LOG_TRACE("Start G.HAO LCR knife edge ILKN\n");



    PMC_LOG_TRACE("End G.HAO LCR knife edge ILKN\n");

    PMC_RETURN(ret_val);

} /*  digi_ghao_map_ilkn_lcr_knife_edge_ilkn */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_setup_tx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 1 (tscc) for MAP<->ILKN decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_setup_tx_1_tscc(digi_handle_t *digi_handle,
                                                        UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 sifd_chnl_id;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    UINT32 ts_start;
    BOOL8 ghao_increase;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    ts_start = local_ghao_segment->ts_start;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup TX 1 TSCC\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        /* set up ODUKSC in MAPOTN to begin ramp */
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 22/2) ODUk SC (MAPOTN): Set up ODUkSc to begin RAMP. But don't begin ramp\n");
        ret_val = mapotn_oduksc_ramp_prov(digi_handle->mapotn_handle,
                                          mapotn_chnl_id,
                                          ts_target,
                                          END_FOR_BWR_IND_250US);
    }


    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up tx_1 : 24/3b) MPMA (Stage 4) : Disable MPMA DSP\n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_FROM_MAPOTN,
                                                   mapotn_chnl_id,
                                                   FALSE,
                                                   0);
    }


    PMC_LOG_TRACE("End G.HAO BWR setup TX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_setup_tx_1_tscc */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_setup_rx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 1 (tscc) for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_setup_rx_1_tscc(digi_handle_t *digi_handle,
                                                        UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 sifd_chnl_id;
    UINT8 mapotn_chnl_id;
    UINT32 ts_target;
    BOOL8 ghao_increase;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup RX 1 TSCC\n");

    /* perform bwr_setup operation */
    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_1 : 26b/4c) MPMO (Stage 4) : Set BWR parameters\n");
        ret_val = coreotn_ghao_mpmo_bwr_rate_param_set(digi_handle->coreotn_handle,
                                                       COREOTN_MPMO_TO_MAPOTN,
                                                       mapotn_chnl_id,
                                                       ts_target,
                                                       ghao_increase);
    }



    PMC_LOG_TRACE("End G.HAO BWR setup RX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_setup_rx_1_tscc */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_setup_tx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 2 (ncs) for MAP<->ILKN decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_setup_tx_2_ncs(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    BOOL8 ghao_increase;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup TX 2 NCS\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up tx_2 : 28a/5) TGFP: Set NCS bit to 1.\n");
        ret_val = mapotn_tgfpf_rcoh_ncs_set(digi_handle->mapotn_handle,
                                            mapotn_chnl_id,
                                            1);
    }

    PMC_LOG_TRACE("End G.HAO BWR setup TX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_setup_tx_2_ncs */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_setup_rx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR setup step 2 (ncs) for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_setup_rx_2_ncs(digi_handle_t *digi_handle,
                                                       UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;
    
    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    BOOL8 ghao_increase;
    UINT32 i;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    ghao_increase = local_ghao_segment->ghao_increase;


    PMC_LOG_TRACE("Start G.HAO BWR setup RX 2 NCS\n");

    /* perform bwr_setup operation */

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR set-up rx_2 : 28b/6) RGFP: Wait to receive NCS bit.\n");
        ret_val = mapotn_rgfpf_rcoh_ncs_poll(digi_handle->mapotn_handle,
                                             mapotn_chnl_id,
                                             1,
                                             50);
#ifdef PMC_SW_SIMULATION
        ret_val = PMC_SUCCESS;
#endif
    }


    if(!ghao_increase)
    {
        /* Initialize userbit to old cal mask for MAPOTN */
        for(i = 0; i< 3; i++)
        {
            local_ghao_segment->coreotn_mpmo4_userbits_mask[i] = local_ghao_segment->mapotn_mpma_old_cal_mask[i];
        }
    }

    PMC_LOG_TRACE("End G.HAO BWR setup RX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_setup_rx_2_ncs */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_start_tx
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Starts the ramp in TX. Triggers the firmware routine that will perform the
*   per TS ramp in the datapath.  It is required that this API is called
*   on all intermediate nodes before it is called for source nodes.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_start_tx(digi_handle_t *digi_handle,
                                                      UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    /* perform bwr start operation */

    PMC_LOG_TRACE("Start G.HAO BWR start TX\n");


    if(ret_val == PMC_SUCCESS)
    {
        
        PMC_LOG_TRACE("G.HAO BWR start : 29a/7a) TGFP: Set BWR_IND bit in OHFS_INSERT\n");
        PMC_LOG_TRACE("G.HAO BWR start : 29b/7b) ODUkSc (MAPOTN): Trigger Ramp in the range of 125us to 250us after setting the BWR_IND bit.\n");
        
        /* this API set BWR_IND and starts the ramp */
        ret_val = mapotn_oduksc_ramp_start(digi_handle->mapotn_handle,
                                           mapotn_chnl_id,
                                           TRUE);
    }

    
    /* Update pre-firmware operations done */
    if (local_ghao_segment->ghao_increase)
    {
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = 1;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;
    }
    else
    {
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].mux_thresh_pre_post_fw = 0;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo1_mpmo_userbit_update_pre_post_fw = 1;
        digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id].fo2_mpmo_userbit_update_pre_post_fw = 0;
    }

    PMC_LOG_TRACE("End G.HAO BWR start TX\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_start_tx */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_start_rx
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Starts the ramp in RX. Triggers the firmware routine that will perform the
*   per TS ramp in the datapath.  It is required that this API is called
*   on all intermediate nodes before it is called for source nodes.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None.
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_start_rx(digi_handle_t *digi_handle,
                                                      UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];

    /* perform bwr start operation */

    PMC_LOG_TRACE("Start G.HAO BWR start RX\n");


    PMC_LOG_TRACE("End G.HAO BWR start RX\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_start_rx */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_tx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 1 (tscc) for MAP<->ILKN decrease segment in TX
*  This need to be called when the ramp is complete to put to datapath
*  back into normal operating more.
*
*  For source nodes, call once RAMP #2 done interrupt is seen
*  in MAPOTN-ODUKSC.
*
*  For intermediate nodes, call after source nodes have
*  completed.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_tx_1_tscc(digi_handle_t *digi_handle,
                                                           UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT8 sifd_chnl_id;
    DOUBLE odu_bitrate;
    UINT32 ts_target;
    UINT32 oif_pkt_size;
    UINT32 oif_header_size;

    UINT32 pkt_size_ptr;
    UINT32 pkt_per_int_ptr;
    UINT32 pkt_per_n_ptr;
    UINT32 pkt_per_d_ptr;
    DOUBLE eps_ptr;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    oif_pkt_size = local_ghao_segment->oif_pkt_size;
    oif_header_size = local_ghao_segment->header_size;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 1 TSCC\n");

    if (ts_target <= 8)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU2_TS_RATE);
    } 
    else if (ts_target <= 32)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU3_TS_RATE);
    } 
    else 
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU4_TS_RATE);
    }
    

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 31a/9a) MPMA (Stage 4): Set new Packet size, period and MPMA_DSP gain.\n");
        ret_val = coreotn_ghao_mpma_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMA_FROM_MAPOTN,
                                                      mapotn_chnl_id,
                                                      odu_bitrate,
                                                      oif_pkt_size,
                                                      oif_header_size,
                                                      FALSE,
                                                      &pkt_size_ptr,
                                                      &pkt_per_int_ptr,
                                                      &pkt_per_n_ptr,
                                                      &pkt_per_d_ptr,
                                                      &eps_ptr);
    }

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_1 : 31b/9b) MPMA (Stage 4): Turn on DSP. \n");
        ret_val = coreotn_ghao_mpma_dsp_enable_set(digi_handle->coreotn_handle,
                                                   COREOTN_MPMA_FROM_MAPOTN,
                                                   mapotn_chnl_id,
                                                   TRUE,
                                                   0);
    }

    
    PMC_LOG_TRACE("G.HAO BWR end tx_1 : 32/10) Wait 3ms \n");

    /* wait 20 ms 
    this delay should stay here to ensure that the packets
    have settles before DSP is enable at rate sink across ILKN*/
    PMC_Q_USLEEP(digi_handle,20000);


    PMC_LOG_TRACE("End G.HAO BWR end TX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_tx_1_tscc */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_rx_1_tscc
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 1 (tscc) for MAP<->ILKN decrease segment in RX
*  This need to be called when the ramp is complete to put to datapath
*  back into normal operating more.
*
*  For source nodes, call once RAMP #2 done interrupt is seen
*  in MAPOTN-ODUKSC.
*
*  For intermediate nodes, call after source nodes have
*  completed.
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_rx_1_tscc(digi_handle_t *digi_handle,
                                                           UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT8 sifd_chnl_id;
    DOUBLE odu_bitrate;
    UINT32 ts_target;
    UINT32 oif_pkt_size;
    UINT32 oif_header_size;

    UINT32 pkt_size_ptr;
    UINT32 pkt_per_int_ptr;
    UINT32 pkt_per_n_ptr;
    UINT32 pkt_per_d_ptr;
    DOUBLE eps_ptr;


    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    oif_pkt_size = local_ghao_segment->oif_pkt_size;
    oif_header_size = local_ghao_segment->header_size;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 1 TSCC\n");

    if (ts_target <= 8)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU2_TS_RATE);
    } 
    else if (ts_target <= 32)
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU3_TS_RATE);
    } 
    else 
    {
        odu_bitrate = (ts_target * UTIL_GLOBAL_ODU4_TS_RATE);
    }
    
    PMC_LOG_TRACE("G.HAO BWR end rx_1 : 36/14) Wait 3ms \n");

    /* calculate new Cn for COREOTN MPMO based on new client rate and new pkt size */
    if(ret_val == PMC_SUCCESS)
    {

          /*use OIF calculator for LINE-CORE-ILKN paths (for packets terminating at CORE MPMO */
          ret_val = coreotn_oif_pkt_period_calc(digi_handle->coreotn_handle,
                                                odu_bitrate,
                                                oif_pkt_size,
                                                oif_header_size,
                                                &pkt_size_ptr,
                                                &pkt_per_int_ptr,
                                                &pkt_per_n_ptr,
                                                &pkt_per_d_ptr,
                                                &eps_ptr);

    }

    /* wait 20 ms */
    PMC_Q_USLEEP(digi_handle,20000);

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_1 : 37/15) MPMO (Stage 4): Set new Packet size, Cn_base(DSP) and take it out of GMP special mode. \n");
        ret_val = coreotn_ghao_mpmo_bwr_end_param_set(digi_handle->coreotn_handle,
                                                      COREOTN_MPMO_TO_MAPOTN,
                                                      mapotn_chnl_id,
                                                      odu_bitrate,
                                                      pkt_size_ptr,
                                                      pkt_per_int_ptr,
                                                      pkt_per_n_ptr,
                                                      pkt_per_d_ptr,
                                                      eps_ptr);
    }

    PMC_LOG_TRACE("End G.HAO BWR end RX 1 TSCC\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_rx_1_tscc */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_tx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 2 (ncs) for MAP<->ILKN decrease segment in TX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_tx_2_ncs(digi_handle_t *digi_handle,
                                                          UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    
    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 2 NCS\n");

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end tx_2 : 38a/16a) TGFP: unset NCS bit\n");
        ret_val = mapotn_tgfpf_rcoh_ncs_set(digi_handle->mapotn_handle,
                                            mapotn_chnl_id,
                                            0);
    }


    PMC_LOG_TRACE("End G.HAO BWR end TX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_tx_2_ncs */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_rx_2_ncs
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 2 (ncs) for MAP<->ILKN decrease segment in RX
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_rx_2_ncs(digi_handle_t *digi_handle,
                                                          UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;

    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 2 NCS\n");

    if(ret_val == PMC_SUCCESS)
    {
        PMC_LOG_TRACE("G.HAO BWR end rx_2 : 38b/16b) RGFP: wait for NCS bit to be unset.\n");
        ret_val = mapotn_rgfpf_rcoh_ncs_poll(digi_handle->mapotn_handle,
                                             mapotn_chnl_id,
                                             0,
                                             50);
#ifdef PMC_SW_SIMULATION
        ret_val = PMC_SUCCESS;
#endif
    }


    PMC_LOG_TRACE("End G.HAO BWR end RX 2 NCS\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_rx_2_ncs */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_tx_3_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 3 (rp) for MAP<->ILKN decrease segment in TX
*  This API will deprovision the G.HAO segment and free up the ghao_segment_id
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_tx_3_inc_rp(digi_handle_t *digi_handle,
                                                             UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT8 sifd_chnl_id;
    UINT32 ts_target;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    ts_target = local_ghao_segment->ts_target;


    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end TX 3 RP\n");

    if (!local_ghao_segment->ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }


    PMC_LOG_TRACE("End G.HAO BWR end TX 3 RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_tx_3_inc_rp */



/*******************************************************************************
* digi_ghao_map_ilkn_bwr_ramp_end_rx_3_inc_rp
* ______________________________________________________________________________
*
* DESCRIPTION:
*   Perform the BWR end step 3 (rp) for MAP<->ILKN decrease segment in RX
*  This API will deprovision the G.HAO
*  segment and free up the ghao_segment_id
*
* INPUTS:
*   *digi_handle           - pointer to DIGI handle instance
*   ghao_segment_id        - Segement id for the G.HAO  
*
*
* OUTPUTS:
*   None.
*
* RETURNS:
*   None
*
* NOTES:
*
*******************************************************************************/
PUBLIC PMC_ERROR digi_ghao_map_ilkn_bwr_ramp_end_rx_3_inc_rp(digi_handle_t *digi_handle,
                                                             UINT32 ghao_segment_id)
{
    
    PMC_ERROR ret_val = PMC_SUCCESS;

    digi_ghao_seg_ctrl_t *local_ghao_segment;
    UINT8 mapotn_chnl_id;
    UINT8 sifd_chnl_id;
    UINT32 ts_target;

    PMC_ENTRY();

    /* set local context */
    local_ghao_segment = &digi_handle->var.ghao_cfg.ghao_segments[ghao_segment_id];
    mapotn_chnl_id = local_ghao_segment->mapotn_chnl_id;
    sifd_chnl_id = local_ghao_segment->sifd_chnl_id;
    ts_target = local_ghao_segment->ts_target;
    
    /* perform bwr end operation */

    PMC_LOG_TRACE("Start G.HAO BWR end RX 3 RP\n");

    if (!local_ghao_segment->ghao_increase)
    {
        PMC_RETURN(DIGI_ERR_INVALID_ARG);
    }



    PMC_LOG_TRACE("End G.HAO BWR end RX 3 RP\n");

    PMC_RETURN(ret_val);

} /* digi_ghao_map_ilkn_bwr_ramp_end_rx_3_inc_rp */


#endif /* DOXYGEN_PUBLIC_ONLY */

/*
** End of file
*/

