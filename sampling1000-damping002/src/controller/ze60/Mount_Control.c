/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 1.1309
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Jun 28 10:08:14 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Control.h"
#include "Mount_Control_private.h"

/* Block states (default storage) */
DW_Mount_Control_T Mount_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_Control_T Mount_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_Control_T Mount_Control_Y;

/* Real-time model */
RT_MODEL_Mount_Control_T Mount_Control_M_;
RT_MODEL_Mount_Control_T *const Mount_Control_M = &Mount_Control_M_;

/* Model step function */
void Mount_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum1;
  real_T rtb_Sum;
  real_T rtb_Sum4;
  real_T rtb_Sum2;
  real_T rtb_GIRFBcontroller;
  real_T rtb_Sum3;
  real_T rtb_Sum5;
  real_T tmp;
  int32_T i;

  /* DiscreteStateSpace: '<S1>/AZ FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum2 = (718533.23250279273)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (-123280.81266591896)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    rtb_Sum2 += 1.9688832845061981E+10*Mount_Control_U.Mount_SP[0];
  }

  /* Gain: '<S1>/AZ average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum3 = ((0.25 * Mount_Control_U.Mount_FB[0] + 0.25 *
               Mount_Control_U.Mount_FB[1]) + 0.25 * Mount_Control_U.Mount_FB[2])
    + 0.25 * Mount_Control_U.Mount_FB[3];

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum1 = Mount_Control_U.Mount_SP[0] - rtb_Sum3;

  /* DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    {
      static const int_T colCidxRow0[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.AZFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_Sum3;
      int_T numNonZero = 14;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Sum3 += 9.1975970452021973E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum2' */
  rtb_Sum2 += rtb_Sum3;

  /* DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum3 = (640690.340915277)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (-109925.08393817773)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    rtb_Sum3 += 1.56539018536989E+10*Mount_Control_U.Mount_SP[1];
  }

  /* Gain: '<S1>/EL average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  tmp = 0.0;
  for (i = 0; i < 6; i++) {
    tmp += Mount_Control_U.Mount_FB[i + 4] * 0.16666666666666666;
  }

  rtb_Sum5 = tmp;

  /* End of Gain: '<S1>/EL average and  m2rad conv+' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum = Mount_Control_U.Mount_SP[1] - rtb_Sum5;

  /* DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    {
      static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.ELFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_Sum5;
      int_T numNonZero = 10;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Sum5 += 7.2481498492308655E+10*rtb_Sum;
  }

  /* Sum: '<S1>/Sum3' */
  rtb_Sum3 += rtb_Sum5;

  /* DiscreteStateSpace: '<S1>/GIR FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum5 = (91226.608932439645)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (-15652.01159419358)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    rtb_Sum5 += 3.1737251733204454E+8*Mount_Control_U.Mount_SP[2];
  }

  /* Gain: '<S1>/GIR average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_GIRFBcontroller = ((0.25 * Mount_Control_U.Mount_FB[10] + 0.25 *
    Mount_Control_U.Mount_FB[11]) + 0.25 * Mount_Control_U.Mount_FB[12]) + 0.25 *
    Mount_Control_U.Mount_FB[13];

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum4 = Mount_Control_U.Mount_SP[2] - rtb_GIRFBcontroller;

  /* DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    {
      static const int_T colCidxRow0[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.GIRFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_GIRFBcontroller;
      int_T numNonZero = 8;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_GIRFBcontroller += 5.7849761030229216E+9*rtb_Sum4;
  }

  /* Sum: '<S1>/Sum5' */
  rtb_Sum5 += rtb_GIRFBcontroller;

  /* Outport: '<Root>/Mount_cmd' */
  Mount_Control_Y.Mount_cmd[0] = rtb_Sum2;
  Mount_Control_Y.Mount_cmd[1] = rtb_Sum3;
  Mount_Control_Y.Mount_cmd[2] = rtb_Sum5;

  /* Update for DiscreteStateSpace: '<S1>/AZ FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.97873745381219357)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.00877480271146245)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[0] += (-704.35735962955573)*Mount_Control_U.Mount_SP[0];
    xnew[1] = (-0.008774802711462441)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.99628705923511851)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[1] += (-116.53056388578005)*Mount_Control_U.Mount_SP[0];
    (void) memcpy(&Mount_Control_DW.AZFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[15];
    xnew[0] = (1.0)*Mount_Control_DW.AZFBcontroller_DSTATE[0];
    xnew[0] += (-404.30663622270748)*rtb_Sum1;

    {
      static const int_T colAidxRow1[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.AZFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 13;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-6225.5542631678763)*rtb_Sum1;

    {
      static const int_T colAidxRow2[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA15 = &Mount_Control_ConstP.AZFBcontroller_A[15];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 13;
      *pxnew2 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[2] += (-2115.7376724819187)*rtb_Sum1;

    {
      static const int_T colAidxRow3[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA29 = &Mount_Control_ConstP.AZFBcontroller_A[29];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 13;
      *pxnew3 = (*pA29++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA29++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-180.07238842042995)*rtb_Sum1;

    {
      static const int_T colAidxRow4[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA43 = &Mount_Control_ConstP.AZFBcontroller_A[43];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 13;
      *pxnew4 = (*pA43++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA43++) * xd[*pAidx++];
      }
    }

    xnew[4] += (-974.95598389474367)*rtb_Sum1;

    {
      static const int_T colAidxRow5[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA57 = &Mount_Control_ConstP.AZFBcontroller_A[57];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 13;
      *pxnew5 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA57++) * xd[*pAidx++];
      }
    }

    xnew[5] += (80.669372293284141)*rtb_Sum1;

    {
      static const int_T colAidxRow6[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA71 = &Mount_Control_ConstP.AZFBcontroller_A[71];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 13;
      *pxnew6 = (*pA71++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA71++) * xd[*pAidx++];
      }
    }

    xnew[6] += (463.72150955484449)*rtb_Sum1;

    {
      static const int_T colAidxRow7[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA85 = &Mount_Control_ConstP.AZFBcontroller_A[85];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 13;
      *pxnew7 = (*pA85++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA85++) * xd[*pAidx++];
      }
    }

    xnew[7] += (72.183505675800632)*rtb_Sum1;

    {
      static const int_T colAidxRow8[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA99 = &Mount_Control_ConstP.AZFBcontroller_A[99];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 13;
      *pxnew8 = (*pA99++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA99++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-106.93002990844215)*rtb_Sum1;

    {
      static const int_T colAidxRow9[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA113 = &Mount_Control_ConstP.AZFBcontroller_A[113];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 13;
      *pxnew9 = (*pA113++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA113++) * xd[*pAidx++];
      }
    }

    xnew[9] += (64.137484105521622)*rtb_Sum1;

    {
      static const int_T colAidxRow10[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA127 = &Mount_Control_ConstP.AZFBcontroller_A[127];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 13;
      *pxnew10 = (*pA127++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA127++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-39.152476710967456)*rtb_Sum1;

    {
      static const int_T colAidxRow11[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA141 = &Mount_Control_ConstP.AZFBcontroller_A[141];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 13;
      *pxnew11 = (*pA141++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA141++) * xd[*pAidx++];
      }
    }

    xnew[11] += (54.892078477850461)*rtb_Sum1;

    {
      static const int_T colAidxRow12[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA155 = &Mount_Control_ConstP.AZFBcontroller_A[155];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 13;
      *pxnew12 = (*pA155++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA155++) * xd[*pAidx++];
      }
    }

    xnew[12] += (31.807243790378756)*rtb_Sum1;

    {
      static const int_T colAidxRow13[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA169 = &Mount_Control_ConstP.AZFBcontroller_A[169];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 13;
      *pxnew13 = (*pA169++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA169++) * xd[*pAidx++];
      }
    }

    xnew[13] += (43.734009726692044)*rtb_Sum1;

    {
      static const int_T colAidxRow14[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow14[0];
      const real_T *pA183 = &Mount_Control_ConstP.AZFBcontroller_A[183];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 13;
      *pxnew14 = (*pA183++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew14 += (*pA183++) * xd[*pAidx++];
      }
    }

    xnew[14] += (-139.64531920303887)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW.AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.97873745381219357)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.0087748027114624427)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[0] += (-628.05022294565958)*Mount_Control_U.Mount_SP[1];
    xnew[1] = (-0.0087748027114624375)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.99628705923511851)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[1] += (-103.90612893849655)*Mount_Control_U.Mount_SP[1];
    (void) memcpy(&Mount_Control_DW.ELFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[11];
    xnew[0] = (1.0)*Mount_Control_DW.ELFBcontroller_DSTATE[0];
    xnew[0] += (512.32982789081734)*rtb_Sum;

    {
      static const int_T colAidxRow1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.ELFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 9;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (-1618.5350303849409)*rtb_Sum;

    {
      static const int_T colAidxRow2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA11 = &Mount_Control_ConstP.ELFBcontroller_A[11];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 9;
      *pxnew2 = (*pA11++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA11++) * xd[*pAidx++];
      }
    }

    xnew[2] += (5324.3722084776737)*rtb_Sum;

    {
      static const int_T colAidxRow3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA21 = &Mount_Control_ConstP.ELFBcontroller_A[21];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 9;
      *pxnew3 = (*pA21++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA21++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-291.251711817713)*rtb_Sum;

    {
      static const int_T colAidxRow4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA31 = &Mount_Control_ConstP.ELFBcontroller_A[31];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 9;
      *pxnew4 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[4] += (-1219.9170812968323)*rtb_Sum;

    {
      static const int_T colAidxRow5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA41 = &Mount_Control_ConstP.ELFBcontroller_A[41];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 9;
      *pxnew5 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-44.521142544005045)*rtb_Sum;

    {
      static const int_T colAidxRow6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA51 = &Mount_Control_ConstP.ELFBcontroller_A[51];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 9;
      *pxnew6 = (*pA51++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA51++) * xd[*pAidx++];
      }
    }

    xnew[6] += (171.23383119312635)*rtb_Sum;

    {
      static const int_T colAidxRow7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA61 = &Mount_Control_ConstP.ELFBcontroller_A[61];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 9;
      *pxnew7 = (*pA61++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA61++) * xd[*pAidx++];
      }
    }

    xnew[7] += (26.035340312398628)*rtb_Sum;

    {
      static const int_T colAidxRow8[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA71 = &Mount_Control_ConstP.ELFBcontroller_A[71];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 9;
      *pxnew8 = (*pA71++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA71++) * xd[*pAidx++];
      }
    }

    xnew[8] += (116.18180289612279)*rtb_Sum;

    {
      static const int_T colAidxRow9[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA81 = &Mount_Control_ConstP.ELFBcontroller_A[81];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 9;
      *pxnew9 = (*pA81++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA81++) * xd[*pAidx++];
      }
    }

    xnew[9] += (105.63150846257837)*rtb_Sum;

    {
      static const int_T colAidxRow10[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA91 = &Mount_Control_ConstP.ELFBcontroller_A[91];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 9;
      *pxnew10 = (*pA91++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA91++) * xd[*pAidx++];
      }
    }

    xnew[10] += (25.148450237685893)*rtb_Sum;
    (void) memcpy(&Mount_Control_DW.ELFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.97873745381219357)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (0.0087748027114624445)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    xnew[0] += (-89.426807959590789)*Mount_Control_U.Mount_SP[2];
    xnew[1] = (-0.0087748027114624323)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (0.99628705923511851)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    xnew[1] += (-14.794984698558686)*Mount_Control_U.Mount_SP[2];
    (void) memcpy(&Mount_Control_DW.GIRFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*Mount_Control_DW.GIRFBcontroller_DSTATE[0];
    xnew[0] += (63.581363227380095)*rtb_Sum4;

    {
      static const int_T colAidxRow1[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.GIRFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 7;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (1323.8469534790568)*rtb_Sum4;

    {
      static const int_T colAidxRow2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA9 = &Mount_Control_ConstP.GIRFBcontroller_A[9];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 7;
      *pxnew2 = (*pA9++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA9++) * xd[*pAidx++];
      }
    }

    xnew[2] += (868.99407197057371)*rtb_Sum4;

    {
      static const int_T colAidxRow3[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA17 = &Mount_Control_ConstP.GIRFBcontroller_A[17];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 7;
      *pxnew3 = (*pA17++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA17++) * xd[*pAidx++];
      }
    }

    xnew[3] += (42.512935262099489)*rtb_Sum4;

    {
      static const int_T colAidxRow4[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA25 = &Mount_Control_ConstP.GIRFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 7;
      *pxnew4 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[4] += (179.1841051427526)*rtb_Sum4;

    {
      static const int_T colAidxRow5[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA33 = &Mount_Control_ConstP.GIRFBcontroller_A[33];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 7;
      *pxnew5 = (*pA33++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA33++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-10.578686719441919)*rtb_Sum4;

    {
      static const int_T colAidxRow6[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA41 = &Mount_Control_ConstP.GIRFBcontroller_A[41];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 7;
      *pxnew6 = (*pA41++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA41++) * xd[*pAidx++];
      }
    }

    xnew[6] += (98.98865984765041)*rtb_Sum4;

    {
      static const int_T colAidxRow7[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA49 = &Mount_Control_ConstP.GIRFBcontroller_A[49];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-1.7471991036026253)*rtb_Sum4;

    {
      static const int_T colAidxRow8[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA57 = &Mount_Control_ConstP.GIRFBcontroller_A[57];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA57++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA57++) * xd[*pAidx++];
      }
    }

    xnew[8] += (-32.265044658601916)*rtb_Sum4;
    (void) memcpy(&Mount_Control_DW.GIRFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*9);
  }
}

/* Model initialize function */
void Mount_Control_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Mount_Control_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Mount_Control_DW, 0,
                sizeof(DW_Mount_Control_T));

  /* external inputs */
  (void)memset(&Mount_Control_U, 0, sizeof(ExtU_Mount_Control_T));

  /* external outputs */
  (void) memset(&Mount_Control_Y.Mount_cmd[0], 0,
                3U*sizeof(real_T));
}

/* Model terminate function */
void Mount_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
