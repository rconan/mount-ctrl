/*
 * File: Mount_Drv_PDR2021_linear.c
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021_linear'.
 *
 * Model version                  : 5.60
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Aug 31 15:34:37 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Drv_PDR2021_linear.h"
#include "Mount_Drv_PDR2021_linear_private.h"

/* Block states (default storage) */
DW_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_Y;

/* Real-time model */
static RT_MODEL_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_M_;
RT_MODEL_Mount_Drv_PDR2021_linear_T *const Mount_Drv_PDR2021_linear_M =
  &Mount_Drv_PDR2021_linear_M_;

/* Model step function */
void Mount_Drv_PDR2021_linear_step(void)
{
  real_T rtb_converttoAzdrivetorques[12];
  real_T AZ_TFd_tmp;
  real_T EL_TFd_tmp;
  real_T GIR_TFd_tmp;
  real_T rtb_GIR_TFd;
  real_T rtb_converttoEldrivetorques_idx_0_tmp;
  int32_T i;

  /* DiscreteTransferFcn: '<S1>/AZ_TFd' incorporates:
   *  Delay: '<S1>/AZ_delay'
   */
  AZ_TFd_tmp =
    Mount_Drv_PDR2021_linear_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx]
    - -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW.AZ_TFd_states;
  rtb_GIR_TFd = 0.058823529411764705 * AZ_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW.AZ_TFd_states;

  /* DiscreteTransferFcn: '<S1>/EL_TFd' incorporates:
   *  Delay: '<S1>/EL_delay'
   */
  EL_TFd_tmp =
    Mount_Drv_PDR2021_linear_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx_g]
    - -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW.EL_TFd_states;

  /* DiscreteTransferFcn: '<S1>/GIR_TFd' incorporates:
   *  Delay: '<S1>/GIR_delay'
   */
  GIR_TFd_tmp =
    Mount_Drv_PDR2021_linear_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx_l]
    - -0.88235294117647056 * Mount_Drv_PDR2021_linear_DW.GIR_TFd_states;
  for (i = 0; i < 12; i++) {
    /* Gain: '<S1>/convert to Az drive torques' */
    rtb_converttoAzdrivetorques[i] = 0.083333333333333329 * rtb_GIR_TFd;

    /* Outport: '<Root>/Mount_T' incorporates:
     *  Gain: '<S1>/convert to Az drive torques'
     */
    Mount_Drv_PDR2021_linear_Y.Mount_T[i] = rtb_converttoAzdrivetorques[i];
  }

  /* Gain: '<S1>/convert to El drive torques' incorporates:
   *  DiscreteTransferFcn: '<S1>/EL_TFd'
   */
  rtb_converttoEldrivetorques_idx_0_tmp = 0.25 * (0.058823529411764705 *
    EL_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW.EL_TFd_states);

  /* DiscreteTransferFcn: '<S1>/GIR_TFd' */
  rtb_GIR_TFd = 0.058823529411764705 * GIR_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_linear_DW.GIR_TFd_states;

  /* Outport: '<Root>/Mount_T' incorporates:
   *  Gain: '<S1>/convert to El drive torques'
   *  Gain: '<S1>/convert to GIR drive torques'
   */
  Mount_Drv_PDR2021_linear_Y.Mount_T[12] = rtb_converttoEldrivetorques_idx_0_tmp;
  Mount_Drv_PDR2021_linear_Y.Mount_T[16] = 0.25 * rtb_GIR_TFd;
  Mount_Drv_PDR2021_linear_Y.Mount_T[13] = rtb_converttoEldrivetorques_idx_0_tmp;
  Mount_Drv_PDR2021_linear_Y.Mount_T[17] = 0.25 * rtb_GIR_TFd;
  Mount_Drv_PDR2021_linear_Y.Mount_T[14] = rtb_converttoEldrivetorques_idx_0_tmp;
  Mount_Drv_PDR2021_linear_Y.Mount_T[18] = 0.25 * rtb_GIR_TFd;
  Mount_Drv_PDR2021_linear_Y.Mount_T[15] = rtb_converttoEldrivetorques_idx_0_tmp;
  Mount_Drv_PDR2021_linear_Y.Mount_T[19] = 0.25 * rtb_GIR_TFd;

  /* Update for Delay: '<S1>/AZ_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_linear_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx]
    = Mount_Drv_PDR2021_linear_U.Mount_cmd[0];
  if (Mount_Drv_PDR2021_linear_DW.CircBufIdx < 31U) {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx++;
  } else {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S1>/AZ_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/AZ_TFd' */
  Mount_Drv_PDR2021_linear_DW.AZ_TFd_states = AZ_TFd_tmp;

  /* Update for Delay: '<S1>/EL_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_linear_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx_g]
    = Mount_Drv_PDR2021_linear_U.Mount_cmd[1];
  if (Mount_Drv_PDR2021_linear_DW.CircBufIdx_g < 31U) {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx_g++;
  } else {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx_g = 0U;
  }

  /* End of Update for Delay: '<S1>/EL_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/EL_TFd' */
  Mount_Drv_PDR2021_linear_DW.EL_TFd_states = EL_TFd_tmp;

  /* Update for Delay: '<S1>/GIR_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_linear_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_linear_DW.CircBufIdx_l]
    = Mount_Drv_PDR2021_linear_U.Mount_cmd[2];
  if (Mount_Drv_PDR2021_linear_DW.CircBufIdx_l < 31U) {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx_l++;
  } else {
    Mount_Drv_PDR2021_linear_DW.CircBufIdx_l = 0U;
  }

  /* End of Update for Delay: '<S1>/GIR_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/GIR_TFd' */
  Mount_Drv_PDR2021_linear_DW.GIR_TFd_states = GIR_TFd_tmp;
}

/* Model initialize function */
void Mount_Drv_PDR2021_linear_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Mount_Drv_PDR2021_linear_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Mount_Drv_PDR2021_linear_DW, 0,
                sizeof(DW_Mount_Drv_PDR2021_linear_T));

  /* external inputs */
  (void)memset(&Mount_Drv_PDR2021_linear_U, 0, sizeof
               (ExtU_Mount_Drv_PDR2021_linear_T));

  /* external outputs */
  (void) memset(&Mount_Drv_PDR2021_linear_Y.Mount_T[0], 0,
                20U*sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/AZ_delay' */
  Mount_Drv_PDR2021_linear_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S1>/EL_delay' */
  Mount_Drv_PDR2021_linear_DW.CircBufIdx_g = 0U;

  /* InitializeConditions for Delay: '<S1>/GIR_delay' */
  Mount_Drv_PDR2021_linear_DW.CircBufIdx_l = 0U;
}

/* Model terminate function */
void Mount_Drv_PDR2021_linear_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
