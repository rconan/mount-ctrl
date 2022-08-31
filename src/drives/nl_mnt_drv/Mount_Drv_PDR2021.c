/*
 * File: Mount_Drv_PDR2021.c
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021'.
 *
 * Model version                  : 5.59
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Aug 31 13:56:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Drv_PDR2021.h"
#include "Mount_Drv_PDR2021_private.h"

/* Block signals (default storage) */
B_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_B;

/* Block states (default storage) */
DW_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_Y;

/* Real-time model */
static RT_MODEL_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_M_;
RT_MODEL_Mount_Drv_PDR2021_T *const Mount_Drv_PDR2021_M = &Mount_Drv_PDR2021_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * Output and update for enable system:
 *    '<S2>/g(v)'
 *    '<S4>/g(v)'
 */
void Mount_Drv_PDR2021_gv(real_T rtu_Enable, real_T *rty_g,
  B_gv_Mount_Drv_PDR2021_T *localB, const struct_1utrxinkom0IYpuKJbdriH
  *rtp_frParStruct)
{
  /* Outputs for Enabled SubSystem: '<S2>/g(v)' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/gc'
     */
    *rty_g = rtp_frParStruct->Tc / rtp_frParStruct->sigm0 + localB->Divide;
  }

  /* End of Outputs for SubSystem: '<S2>/g(v)' */
}

/*
 * Output and update for enable system:
 *    '<S2>/v2z'
 *    '<S4>/v2z'
 */
void Mount_Drv_PDR2021_v2z(real_T rtu_Enable, real_T rtu_v, real_T rtu_gv,
  real_T rtu_z, real_T *rty_dz)
{
  /* Outputs for Enabled SubSystem: '<S2>/v2z' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtu_Enable > 0.0) {
    /* Sum: '<S8>/Sum' incorporates:
     *  Abs: '<S8>/Abs'
     *  Product: '<S8>/Divide'
     */
    *rty_dz = rtu_v - fabs(rtu_v) / rtu_gv * rtu_z;
  }

  /* End of Outputs for SubSystem: '<S2>/v2z' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T u1_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = fabs(u0 / u1);
      if (!(fabs(u1_0 - floor(u1_0 + 0.5)) > DBL_EPSILON * u1_0)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void Mount_Drv_PDR2021_step(void)
{
  real_T rtb_Diff[14];
  real_T rtb_TSamp[14];
  real_T AZ_TFd_tmp;
  real_T rtb_AZ_drv_qt;
  real_T rtb_AZvelavgrads;
  real_T rtb_Abs;
  real_T rtb_Divide;
  real_T rtb_Divide_c;
  real_T rtb_ELvelavgrads;
  real_T rtb_GIRvelavgrads_0;
  real_T rtb_Gain;
  int32_T i;
  for (i = 0; i < 14; i++) {
    /* SampleTimeMath: '<S3>/TSamp' incorporates:
     *  Inport: '<Root>/Mount_pos'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    AZ_TFd_tmp = Mount_Drv_PDR2021_U.Mount_pos[i] * 8000.0;

    /* Sum: '<S3>/Diff' incorporates:
     *  SampleTimeMath: '<S3>/TSamp'
     *  UnitDelay: '<S3>/UD'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * Block description for '<S3>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Diff[i] = AZ_TFd_tmp - Mount_Drv_PDR2021_DW.UD_DSTATE[i];

    /* SampleTimeMath: '<S3>/TSamp'
     *
     * About '<S3>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp[i] = AZ_TFd_tmp;
  }

  /* DiscreteTransferFcn: '<S1>/AZ_TFd' incorporates:
   *  Delay: '<S1>/AZ_delay'
   *  Quantizer: '<S1>/AZ_drv_qt'
   */
  AZ_TFd_tmp = rt_roundd_snf
    (Mount_Drv_PDR2021_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx] /
     25.93994140625) * 25.93994140625 - -0.88235294117647056 *
    Mount_Drv_PDR2021_DW.AZ_TFd_states;
  rtb_Abs = 0.058823529411764705 * AZ_TFd_tmp + 0.058823529411764705 *
    Mount_Drv_PDR2021_DW.AZ_TFd_states;

  /* Saturate: '<S1>/AZ_drv_sat' */
  if (rtb_Abs > 850000.0) {
    rtb_Abs = 850000.0;
  } else {
    if (rtb_Abs < -850000.0) {
      rtb_Abs = -850000.0;
    }
  }

  /* End of Saturate: '<S1>/AZ_drv_sat' */

  /* Gain: '<S1>/AZ vel avg => rad//s' */
  rtb_Divide_c = ((0.25 * rtb_Diff[0] + 0.25 * rtb_Diff[1]) + 0.25 * rtb_Diff[2])
    + 0.25 * rtb_Diff[3];

  /* Math: '<S16>/Mod1' incorporates:
   *  Constant: '<S16>/Constant'
   *  Gain: '<S16>/Radius'
   *  Gain: '<S1>/AZ enc avg + m2rad'
   *  Inport: '<Root>/Mount_pos'
   *  Math: '<S16>/Mod'
   *  Sum: '<S16>/Sum2'
   */
  rtb_AZ_drv_qt = rt_remd_snf(rt_remd_snf((((0.25 *
    Mount_Drv_PDR2021_U.Mount_pos[0] + 0.25 * Mount_Drv_PDR2021_U.Mount_pos[1])
    + 0.25 * Mount_Drv_PDR2021_U.Mount_pos[2]) + 0.25 *
    Mount_Drv_PDR2021_U.Mount_pos[3]) * 9.369, 0.1869) + 0.1869, 0.1869);

  /* Product: '<S16>/Divide' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S16>/Gain'
   *  Gain: '<S16>/Gain1'
   *  Gain: '<S16>/Gain2'
   *  Lookup_n-D: '<S16>/EMF Distortion'
   */
  rtb_Divide = 0.10673497705197994 * rtb_Abs * 0.004 * 0.125 * look1_binlxpw
    (rtb_AZ_drv_qt, Mount_Drv_PDR2021_ConstP.pooled9,
     Mount_Drv_PDR2021_ConstP.EMFDistortion_tableData, 360U);

  /* Lookup_n-D: '<S16>/Cogging' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  rtb_AZ_drv_qt = look1_binlxpw(rtb_AZ_drv_qt, Mount_Drv_PDR2021_ConstP.pooled9,
    Mount_Drv_PDR2021_ConstP.Cogging_tableData, 360U);

  /* Outputs for Enabled SubSystem: '<S1>/AZ DT Lugre Fr model' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S2>/g(v)' */
  /* Constant: '<S2>/Constant' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S1>/AZ vel avg => rad//s'
   */
  Mount_Drv_PDR2021_gv(0.0, &Mount_Drv_PDR2021_B.Sum_b, &Mount_Drv_PDR2021_B.gv,
                       &Mount_Drv_PDR2021_ConstP.gv_rtw_collapsed_sub_expr_0);

  /* End of Outputs for SubSystem: '<S2>/g(v)' */

  /* Outputs for Enabled SubSystem: '<S2>/v2z' */
  Mount_Drv_PDR2021_v2z(0.0, rtb_Divide_c, Mount_Drv_PDR2021_B.Sum_b,
                        Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m2,
                        &Mount_Drv_PDR2021_B.Sum_m);

  /* End of Outputs for SubSystem: '<S2>/v2z' */

  /* Sum: '<S2>/Sum' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S1>/AZ vel avg => rad//s'
   *  Gain: '<S2>/sigma_0'
   *  Gain: '<S2>/sigma_1'
   *  Gain: '<S2>/sigma_v'
   */
  Mount_Drv_PDR2021_B.Sum_p = (0.0 * Mount_Drv_PDR2021_B.Sum_m + 0.0 *
    Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m2) + 835023.05537142872 *
    rtb_Divide_c;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m2 += 0.000125 *
    Mount_Drv_PDR2021_B.Sum_m;

  /* End of Outputs for SubSystem: '<S1>/AZ DT Lugre Fr model' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Sum: '<S16>/Sum1'
   */
  rtb_Abs = ((rtb_Divide + rtb_AZ_drv_qt) + rtb_Abs) - Mount_Drv_PDR2021_B.Sum_p;

  /* DiscreteTransferFcn: '<S1>/EL_TFd' incorporates:
   *  Delay: '<S1>/EL_delay'
   *  Quantizer: '<S1>/EL_drv_qt'
   */
  rtb_Divide = rt_roundd_snf
    (Mount_Drv_PDR2021_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_n] /
     14.34326171875) * 14.34326171875 - -0.88235294117647056 *
    Mount_Drv_PDR2021_DW.EL_TFd_states;
  rtb_AZvelavgrads = 0.058823529411764705 * rtb_Divide + 0.058823529411764705 *
    Mount_Drv_PDR2021_DW.EL_TFd_states;

  /* Saturate: '<S1>/EL_drv_sat' */
  if (rtb_AZvelavgrads > 470000.0) {
    rtb_AZvelavgrads = 470000.0;
  } else {
    if (rtb_AZvelavgrads < -470000.0) {
      rtb_AZvelavgrads = -470000.0;
    }
  }

  /* End of Saturate: '<S1>/EL_drv_sat' */

  /* Gain: '<S1>/EL enc avg + m2rad' */
  rtb_Divide_c = 0.0;

  /* Gain: '<S1>/EL vel avg => rad//s' */
  rtb_ELvelavgrads = 0.0;
  for (i = 0; i < 6; i++) {
    /* Gain: '<S1>/EL enc avg + m2rad' incorporates:
     *  Inport: '<Root>/Mount_pos'
     */
    rtb_Divide_c += Mount_Drv_PDR2021_U.Mount_pos[i + 4] * 0.16666666666666666;

    /* Gain: '<S1>/EL vel avg => rad//s' incorporates:
     *  Gain: '<S1>/EL enc avg + m2rad'
     */
    rtb_ELvelavgrads += rtb_Diff[i + 4] * 0.16666666666666666;
  }

  /* Math: '<S17>/Mod1' incorporates:
   *  Constant: '<S17>/Constant'
   *  Gain: '<S17>/Radius'
   *  Gain: '<S1>/EL enc avg + m2rad'
   *  Math: '<S17>/Mod'
   *  Sum: '<S17>/Sum2'
   */
  rtb_AZ_drv_qt = rt_remd_snf(rt_remd_snf(10.357 * rtb_Divide_c, 0.1869) +
    0.1869, 0.1869);

  /* Product: '<S17>/Divide' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S17>/Gain'
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S17>/Gain2'
   *  Lookup_n-D: '<S17>/EMF Distortion'
   */
  rtb_Divide_c = 0.096553055904219379 * rtb_AZvelavgrads * 0.004 * 0.25 *
    look1_binlxpw(rtb_AZ_drv_qt, Mount_Drv_PDR2021_ConstP.pooled9,
                  Mount_Drv_PDR2021_ConstP.EMFDistortion_tableData_p, 360U);

  /* Lookup_n-D: '<S17>/Cogging' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  rtb_AZ_drv_qt = look1_binlxpw(rtb_AZ_drv_qt, Mount_Drv_PDR2021_ConstP.pooled9,
    Mount_Drv_PDR2021_ConstP.Cogging_tableData_a, 360U);

  /* Outputs for Enabled SubSystem: '<S1>/EL DT Lugre Fr model' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S4>/g(v)' */
  /* Constant: '<S4>/Constant' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S1>/EL vel avg => rad//s'
   */
  Mount_Drv_PDR2021_gv(0.0, &Mount_Drv_PDR2021_B.Sum_j,
                       &Mount_Drv_PDR2021_B.gv_p,
                       &Mount_Drv_PDR2021_ConstP.gv_rtw_collapsed_sub_expr_1);

  /* End of Outputs for SubSystem: '<S4>/g(v)' */

  /* Outputs for Enabled SubSystem: '<S4>/v2z' */
  Mount_Drv_PDR2021_v2z(0.0, rtb_ELvelavgrads, Mount_Drv_PDR2021_B.Sum_j,
                        Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m,
                        &Mount_Drv_PDR2021_B.Sum_i);

  /* End of Outputs for SubSystem: '<S4>/v2z' */

  /* Sum: '<S4>/Sum' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Gain: '<S1>/EL vel avg => rad//s'
   *  Gain: '<S4>/sigma_0'
   *  Gain: '<S4>/sigma_1'
   *  Gain: '<S4>/sigma_v'
   */
  Mount_Drv_PDR2021_B.Sum_a = (0.0 * Mount_Drv_PDR2021_B.Sum_i + 0.0 *
    Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m) + 877281.23498901119 *
    rtb_ELvelavgrads;

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE_m += 0.000125 *
    Mount_Drv_PDR2021_B.Sum_i;

  /* End of Outputs for SubSystem: '<S1>/EL DT Lugre Fr model' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Sum: '<S17>/Sum1'
   */
  rtb_Divide_c = ((rtb_Divide_c + rtb_AZ_drv_qt) + rtb_AZvelavgrads) -
    Mount_Drv_PDR2021_B.Sum_a;

  /* DiscreteTransferFcn: '<S1>/GIR_TFd' incorporates:
   *  Delay: '<S1>/GIR_delay'
   *  Quantizer: '<S1>/GIR_drv_qt'
   */
  rtb_ELvelavgrads = rt_roundd_snf
    (Mount_Drv_PDR2021_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_o] /
     19.8486328125) * 19.8486328125 - -0.88235294117647056 *
    Mount_Drv_PDR2021_DW.GIR_TFd_states;
  rtb_AZvelavgrads = 0.058823529411764705 * rtb_ELvelavgrads +
    0.058823529411764705 * Mount_Drv_PDR2021_DW.GIR_TFd_states;

  /* Saturate: '<S1>/GIR_drv_sat' */
  if (rtb_AZvelavgrads > 632400.0) {
    rtb_AZvelavgrads = 632400.0;
  } else {
    if (rtb_AZvelavgrads < -632400.0) {
      rtb_AZvelavgrads = -632400.0;
    }
  }

  /* End of Saturate: '<S1>/GIR_drv_sat' */

  /* Gain: '<S1>/GIR enc avg + m2rad' incorporates:
   *  Inport: '<Root>/Mount_pos'
   */
  rtb_AZ_drv_qt = ((0.25 * Mount_Drv_PDR2021_U.Mount_pos[10] + 0.25 *
                    Mount_Drv_PDR2021_U.Mount_pos[11]) + 0.25 *
                   Mount_Drv_PDR2021_U.Mount_pos[12]) + 0.25 *
    Mount_Drv_PDR2021_U.Mount_pos[13];

  /* Gain: '<S1>/GIR vel avg =>r ad//s' */
  rtb_GIRvelavgrads_0 = ((0.25 * rtb_Diff[10] + 0.25 * rtb_Diff[11]) + 0.25 *
    rtb_Diff[12]) + 0.25 * rtb_Diff[13];

  /* Outputs for Enabled SubSystem: '<S1>/GIR DT Lugre Fr model' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Sum: '<S14>/Sum' incorporates:
   *  Abs: '<S14>/Abs'
   *  Constant: '<S13>/gc'
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S1>/GIR vel avg =>r ad//s'
   *  Product: '<S14>/Divide'
   *  Sum: '<S13>/Sum'
   */
  rtb_Gain = rtb_GIRvelavgrads_0 - fabs(rtb_GIRvelavgrads_0) /
    (Mount_Drv_PDR2021_B.Divide + 7.6436250000000009E-6) *
    Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S5>/Sum' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   *  Gain: '<S1>/GIR vel avg =>r ad//s'
   *  Gain: '<S5>/sigma_0'
   *  Gain: '<S5>/sigma_1'
   *  Gain: '<S5>/sigma_v'
   */
  Mount_Drv_PDR2021_B.Sum = (3.799854144569236E+7 * rtb_Gain + 2.304E+9 *
    Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE) + 4377.5999999999995 *
    rtb_GIRvelavgrads_0;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  Mount_Drv_PDR2021_DW.DiscreteTimeIntegrator_DSTATE += 0.000125 * rtb_Gain;

  /* End of Outputs for SubSystem: '<S1>/GIR DT Lugre Fr model' */

  /* Signum: '<S18>/Sign' */
  if (rtb_AZvelavgrads < 0.0) {
    rtb_GIRvelavgrads_0 = -1.0;
  } else if (rtb_AZvelavgrads > 0.0) {
    rtb_GIRvelavgrads_0 = 1.0;
  } else if (rtb_AZvelavgrads == 0.0) {
    rtb_GIRvelavgrads_0 = 0.0;
  } else {
    rtb_GIRvelavgrads_0 = (rtNaN);
  }

  /* End of Signum: '<S18>/Sign' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<S18>/CogAmp'
   *  Constant: '<S18>/CogSpatFreq'
   *  Constant: '<S18>/RippleAmpFactor'
   *  Constant: '<S18>/RippleSpatFreq'
   *  Constant: '<S18>/ToPretension'
   *  Gain: '<S1>/GIR enc avg + m2rad'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Product: '<S18>/Product2'
   *  Product: '<S18>/Product3'
   *  Product: '<S18>/Product4'
   *  Sum: '<S18>/Sum'
   *  Sum: '<S18>/Sum1'
   *  Trigonometry: '<S18>/Trigonometric Function'
   *  Trigonometry: '<S18>/Trigonometric Function1'
   */
  rtb_AZ_drv_qt = (((18000.0 * rtb_GIRvelavgrads_0 + rtb_AZvelavgrads) * 0.015 *
                    sin(rtb_AZ_drv_qt * 2880.0) + sin(rtb_AZ_drv_qt * 4320.0) *
                    180.0) + rtb_AZvelavgrads) - Mount_Drv_PDR2021_B.Sum;

  /* Outport: '<Root>/Mount_F' incorporates:
   *  Gain: '<S1>/convert to Az drive torques'
   *  Gain: '<S1>/convert to El drive torques'
   *  Gain: '<S1>/convert to GIR drive torques'
   */
  for (i = 0; i < 12; i++) {
    Mount_Drv_PDR2021_Y.Mount_F[i] = 0.083333333333333329 * rtb_Abs;
  }

  Mount_Drv_PDR2021_Y.Mount_F[12] = 0.25 * rtb_Divide_c;
  Mount_Drv_PDR2021_Y.Mount_F[16] = 0.25 * rtb_AZ_drv_qt;
  Mount_Drv_PDR2021_Y.Mount_F[13] = 0.25 * rtb_Divide_c;
  Mount_Drv_PDR2021_Y.Mount_F[17] = 0.25 * rtb_AZ_drv_qt;
  Mount_Drv_PDR2021_Y.Mount_F[14] = 0.25 * rtb_Divide_c;
  Mount_Drv_PDR2021_Y.Mount_F[18] = 0.25 * rtb_AZ_drv_qt;
  Mount_Drv_PDR2021_Y.Mount_F[15] = 0.25 * rtb_Divide_c;
  Mount_Drv_PDR2021_Y.Mount_F[19] = 0.25 * rtb_AZ_drv_qt;

  /* End of Outport: '<Root>/Mount_F' */

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  memcpy(&Mount_Drv_PDR2021_DW.UD_DSTATE[0], &rtb_TSamp[0], 14U * sizeof(real_T));

  /* Update for Delay: '<S1>/AZ_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_DW.AZ_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx] =
    Mount_Drv_PDR2021_U.Mount_cmd[0];
  if (Mount_Drv_PDR2021_DW.CircBufIdx < 31U) {
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
  Mount_Drv_PDR2021_DW.EL_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_n] =
    Mount_Drv_PDR2021_U.Mount_cmd[1];
  if (Mount_Drv_PDR2021_DW.CircBufIdx_n < 31U) {
    Mount_Drv_PDR2021_DW.CircBufIdx_n++;
  } else {
    Mount_Drv_PDR2021_DW.CircBufIdx_n = 0U;
  }

  /* End of Update for Delay: '<S1>/EL_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/EL_TFd' */
  Mount_Drv_PDR2021_DW.EL_TFd_states = rtb_Divide;

  /* Update for Delay: '<S1>/GIR_delay' incorporates:
   *  Inport: '<Root>/Mount_cmd'
   */
  Mount_Drv_PDR2021_DW.GIR_delay_DSTATE[Mount_Drv_PDR2021_DW.CircBufIdx_o] =
    Mount_Drv_PDR2021_U.Mount_cmd[2];
  if (Mount_Drv_PDR2021_DW.CircBufIdx_o < 31U) {
    Mount_Drv_PDR2021_DW.CircBufIdx_o++;
  } else {
    Mount_Drv_PDR2021_DW.CircBufIdx_o = 0U;
  }

  /* End of Update for Delay: '<S1>/GIR_delay' */

  /* Update for DiscreteTransferFcn: '<S1>/GIR_TFd' */
  Mount_Drv_PDR2021_DW.GIR_TFd_states = rtb_ELvelavgrads;
}

/* Model initialize function */
void Mount_Drv_PDR2021_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Mount_Drv_PDR2021_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Mount_Drv_PDR2021_B), 0,
                sizeof(B_Mount_Drv_PDR2021_T));

  /* states (dwork) */
  (void) memset((void *)&Mount_Drv_PDR2021_DW, 0,
                sizeof(DW_Mount_Drv_PDR2021_T));

  /* external inputs */
  (void)memset(&Mount_Drv_PDR2021_U, 0, sizeof(ExtU_Mount_Drv_PDR2021_T));

  /* external outputs */
  (void) memset(&Mount_Drv_PDR2021_Y.Mount_F[0], 0,
                20U*sizeof(real_T));

  /* InitializeConditions for Delay: '<S1>/AZ_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S1>/EL_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx_n = 0U;

  /* InitializeConditions for Delay: '<S1>/GIR_delay' */
  Mount_Drv_PDR2021_DW.CircBufIdx_o = 0U;
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
