/*
 * File: Mount_Drv_PDR2021.c
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021'.
 *
 * Model version                  : 1.1193
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 20 15:30:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Drv_PDR2021.h"
#include "Mount_Drv_PDR2021_private.h"

/* Block states (default storage) */
DW_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_Y;

/* Real-time model */
RT_MODEL_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_M_;
RT_MODEL_Mount_Drv_PDR2021_T *const Mount_Drv_PDR2021_M = &Mount_Drv_PDR2021_M_;

/* Model step function */
void Mount_Drv_PDR2021_step(void)
{
  real_T rtb_Sum2;
  real_T rtb_converttoAzdrivetorques[12];
  real_T AZ_TFd_tmp;
  real_T EL_TFd_tmp;
  real_T GIR_TFd_tmp;
  int32_T i;
  real_T rtb_converttoEldrivetorques_idx_0;
  real_T rtb_converttoEldrivetorques_idx_1;
  real_T rtb_converttoEldrivetorques_idx_2;
  real_T rtb_converttoEldrivetorques_idx_3;

  /* DiscreteTransferFcn: '<S1>/AZ_TFd' incorporates:
   *  Delay: '<S1>/AZ_delay'
   */
  AZ_TFd_tmp =
    Mount_Drv_PDR2021_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx] -
    -0.33333333333333331 * Mount_Drv_PDR2021_DW.AZ_TFd_states;
  rtb_Sum2 = 0.33333333333333331 * AZ_TFd_tmp + 0.33333333333333331 *
    Mount_Drv_PDR2021_DW.AZ_TFd_states;

  /* DiscreteTransferFcn: '<S1>/EL_TFd' incorporates:
   *  Delay: '<S1>/EL_delay'
   */
  EL_TFd_tmp =
    Mount_Drv_PDR2021_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_p] -
    -0.33333333333333331 * Mount_Drv_PDR2021_DW.EL_TFd_states;
  for (i = 0; i < 12; i++) {
    /* Gain: '<S1>/convert to Az drive torques' */
    rtb_converttoAzdrivetorques[i] = 0.083333333333333329 * rtb_Sum2;

    /* Outport: '<Root>/Mount_T' incorporates:
     *  Gain: '<S1>/convert to Az drive torques'
     */
    Mount_Drv_PDR2021_Y.Mount_T[i] = rtb_converttoAzdrivetorques[i];
  }

  /* DiscreteTransferFcn: '<S1>/EL_TFd' */
  rtb_Sum2 = 0.33333333333333331 * EL_TFd_tmp + 0.33333333333333331 *
    Mount_Drv_PDR2021_DW.EL_TFd_states;

  /* Gain: '<S1>/convert to El drive torques' */
  rtb_converttoEldrivetorques_idx_0 = 0.25 * rtb_Sum2;
  rtb_converttoEldrivetorques_idx_1 = 0.25 * rtb_Sum2;
  rtb_converttoEldrivetorques_idx_2 = 0.25 * rtb_Sum2;
  rtb_converttoEldrivetorques_idx_3 = 0.25 * rtb_Sum2;

  /* DiscreteTransferFcn: '<S1>/GIR_TFd' incorporates:
   *  Delay: '<S1>/GIR_delay'
   */
  GIR_TFd_tmp =
    Mount_Drv_PDR2021_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_n] -
    -0.33333333333333331 * Mount_Drv_PDR2021_DW.GIR_TFd_states;
  rtb_Sum2 = 0.33333333333333331 * GIR_TFd_tmp + 0.33333333333333331 *
    Mount_Drv_PDR2021_DW.GIR_TFd_states;

  /* Outport: '<Root>/Mount_T' incorporates:
   *  Gain: '<S1>/convert to GIR drive torques'
   */
  Mount_Drv_PDR2021_Y.Mount_T[12] = rtb_converttoEldrivetorques_idx_0;
  Mount_Drv_PDR2021_Y.Mount_T[16] = 0.25 * rtb_Sum2;
  Mount_Drv_PDR2021_Y.Mount_T[13] = rtb_converttoEldrivetorques_idx_1;
  Mount_Drv_PDR2021_Y.Mount_T[17] = 0.25 * rtb_Sum2;
  Mount_Drv_PDR2021_Y.Mount_T[14] = rtb_converttoEldrivetorques_idx_2;
  Mount_Drv_PDR2021_Y.Mount_T[18] = 0.25 * rtb_Sum2;
  Mount_Drv_PDR2021_Y.Mount_T[15] = rtb_converttoEldrivetorques_idx_3;
  Mount_Drv_PDR2021_Y.Mount_T[19] = 0.25 * rtb_Sum2;

  /* Update for Delay: '<S1>/AZ_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx] =
    Mount_Drv_PDR2021_U.Mount_cmd[0];
  if (Mount_Drv_PDR2021_DW.CircBufIdx < 3U) {
    Mount_Drv_PDR2021_DW.CircBufIdx++;
  } else {
    Mount_Drv_PDR2021_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S1>/AZ_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/AZ_TFd' */
  Mount_Drv_PDR2021_DW.AZ_TFd_states = AZ_TFd_tmp;

  /* Update for Delay: '<S1>/EL_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_p] =
    Mount_Drv_PDR2021_U.Mount_cmd[1];
  if (Mount_Drv_PDR2021_DW.CircBufIdx_p < 3U) {
    Mount_Drv_PDR2021_DW.CircBufIdx_p++;
  } else {
    Mount_Drv_PDR2021_DW.CircBufIdx_p = 0U;
  }

  /* End of Update for Delay: '<S1>/EL_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/EL_TFd' */
  Mount_Drv_PDR2021_DW.EL_TFd_states = EL_TFd_tmp;

  /* Update for Delay: '<S1>/GIR_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_n] =
    Mount_Drv_PDR2021_U.Mount_cmd[2];
  if (Mount_Drv_PDR2021_DW.CircBufIdx_n < 3U) {
    Mount_Drv_PDR2021_DW.CircBufIdx_n++;
  } else {
    Mount_Drv_PDR2021_DW.CircBufIdx_n = 0U;
  }

  /* End of Update for Delay: '<S1>/GIR_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/GIR_TFd' */
  Mount_Drv_PDR2021_DW.GIR_TFd_states = GIR_TFd_tmp;
}

/* Model initialize function */
void Mount_Drv_PDR2021_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Mount_Drv_PDR2021_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Mount_Drv_PDR2021_DW, 0,
                sizeof(DW_Mount_Drv_PDR2021_T));

  /* external inputs */
  (void)memset(&Mount_Drv_PDR2021_U, 0, sizeof(ExtU_Mount_Drv_PDR2021_T));

  /* external outputs */
  (void) memset(&Mount_Drv_PDR2021_Y.Mount_T[0], 0,
                20U*sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/AZ_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S1>/EL_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx_p = 0U;

  /* InitializeConditions for Delay: '<S1>/GIR_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx_n = 0U;
}

/* Model terminate function */
void Mount_Drv_PDR2021_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
