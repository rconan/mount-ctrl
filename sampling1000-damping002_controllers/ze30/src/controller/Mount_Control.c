/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 1.1309
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Jun 28 09:40:48 2022
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
    rtb_Sum2 = (725703.23025879019)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (-124510.98979647842)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    rtb_Sum2 += 2.0083729612418442E+10*Mount_Control_U.Mount_SP[0];
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
      static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.AZFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_Sum3;
      int_T numNonZero = 12;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Sum3 += 9.3437749564506744E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum2' */
  rtb_Sum2 += rtb_Sum3;

  /* DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum3 = (640680.60984232358)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (-109923.4143500115)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    rtb_Sum3 += 1.5653426341288635E+10*Mount_Control_U.Mount_SP[1];
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

    rtb_Sum5 += 7.2981280334477417E+10*rtb_Sum;
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
      static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.GIRFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_GIRFBcontroller;
      int_T numNonZero = 6;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_GIRFBcontroller += 5.9016914454483242E+9*rtb_Sum4;
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
      + (0.008774802711462441)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[0] += (-711.38590119105493)*Mount_Control_U.Mount_SP[0];
    xnew[1] = (-0.0087748027114624358)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.9962870592351184)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[1] += (-117.69338258889817)*Mount_Control_U.Mount_SP[0];
    (void) memcpy(&Mount_Control_DW.AZFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[13];
    xnew[0] = (1.0)*Mount_Control_DW.AZFBcontroller_DSTATE[0];
    xnew[0] += (383.24945222041941)*rtb_Sum1;

    {
      static const int_T colAidxRow1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.AZFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 11;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (6361.7298511026038)*rtb_Sum1;

    {
      static const int_T colAidxRow2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA13 = &Mount_Control_ConstP.AZFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 11;
      *pxnew2 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[2] += (2098.9164676959263)*rtb_Sum1;

    {
      static const int_T colAidxRow3[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA25 = &Mount_Control_ConstP.AZFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 11;
      *pxnew3 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-58.133344837330149)*rtb_Sum1;

    {
      static const int_T colAidxRow4[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA37 = &Mount_Control_ConstP.AZFBcontroller_A[37];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 11;
      *pxnew4 = (*pA37++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA37++) * xd[*pAidx++];
      }
    }

    xnew[4] += (946.30335769122053)*rtb_Sum1;

    {
      static const int_T colAidxRow5[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA49 = &Mount_Control_ConstP.AZFBcontroller_A[49];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 11;
      *pxnew5 = (*pA49++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA49++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-125.16819156970507)*rtb_Sum1;

    {
      static const int_T colAidxRow6[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA61 = &Mount_Control_ConstP.AZFBcontroller_A[61];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 11;
      *pxnew6 = (*pA61++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA61++) * xd[*pAidx++];
      }
    }

    xnew[6] += (-459.51551358989423)*rtb_Sum1;

    {
      static const int_T colAidxRow7[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA73 = &Mount_Control_ConstP.AZFBcontroller_A[73];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 11;
      *pxnew7 = (*pA73++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA73++) * xd[*pAidx++];
      }
    }

    xnew[7] += (-3.3994373278899275)*rtb_Sum1;

    {
      static const int_T colAidxRow8[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA85 = &Mount_Control_ConstP.AZFBcontroller_A[85];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 11;
      *pxnew8 = (*pA85++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA85++) * xd[*pAidx++];
      }
    }

    xnew[8] += (139.74698670375187)*rtb_Sum1;

    {
      static const int_T colAidxRow9[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA97 = &Mount_Control_ConstP.AZFBcontroller_A[97];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 11;
      *pxnew9 = (*pA97++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA97++) * xd[*pAidx++];
      }
    }

    xnew[9] += (-36.798872401753982)*rtb_Sum1;

    {
      static const int_T colAidxRow10[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA109 = &Mount_Control_ConstP.AZFBcontroller_A[109];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 11;
      *pxnew10 = (*pA109++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA109++) * xd[*pAidx++];
      }
    }

    xnew[10] += (-189.22940492162226)*rtb_Sum1;

    {
      static const int_T colAidxRow11[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA121 = &Mount_Control_ConstP.AZFBcontroller_A[121];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 11;
      *pxnew11 = (*pA121++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA121++) * xd[*pAidx++];
      }
    }

    xnew[11] += (45.126784679035069)*rtb_Sum1;

    {
      static const int_T colAidxRow12[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA133 = &Mount_Control_ConstP.AZFBcontroller_A[133];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 11;
      *pxnew12 = (*pA133++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA133++) * xd[*pAidx++];
      }
    }

    xnew[12] += (-60.714950962126444)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW.AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*13);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.97873745381219357)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.0087748027114624219)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[0] += (-628.0406838561064)*Mount_Control_U.Mount_SP[1];
    xnew[1] = (-0.00877480271146243)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.9962870592351184)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[1] += (-103.90455076873745)*Mount_Control_U.Mount_SP[1];
    (void) memcpy(&Mount_Control_DW.ELFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[11];
    xnew[0] = (1.0)*Mount_Control_DW.ELFBcontroller_DSTATE[0];
    xnew[0] += (-601.62475891368081)*rtb_Sum;

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

    xnew[1] += (-1697.2804965512223)*rtb_Sum;

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

    xnew[2] += (-5221.712195787386)*rtb_Sum;

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

    xnew[3] += (-439.60094887734436)*rtb_Sum;

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

    xnew[4] += (1303.4491299466856)*rtb_Sum;

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

    xnew[5] += (-47.741456825217085)*rtb_Sum;

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

    xnew[6] += (187.07871016375756)*rtb_Sum;

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

    xnew[7] += (-35.317200963237788)*rtb_Sum;

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

    xnew[8] += (-72.137863555319143)*rtb_Sum;

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

    xnew[9] += (10.782664448710506)*rtb_Sum;

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

    xnew[10] += (38.890634075654468)*rtb_Sum;
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
    real_T xnew[7];
    xnew[0] = (1.0)*Mount_Control_DW.GIRFBcontroller_DSTATE[0];
    xnew[0] += (111.17965832012311)*rtb_Sum4;

    {
      static const int_T colAidxRow1[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA1 = &Mount_Control_ConstP.GIRFBcontroller_A[1];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 5;
      *pxnew1 = (*pA1++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA1++) * xd[*pAidx++];
      }
    }

    xnew[1] += (1254.7464861325589)*rtb_Sum4;

    {
      static const int_T colAidxRow2[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA7 = &Mount_Control_ConstP.GIRFBcontroller_A[7];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 5;
      *pxnew2 = (*pA7++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA7++) * xd[*pAidx++];
      }
    }

    xnew[2] += (996.95022798859759)*rtb_Sum4;

    {
      static const int_T colAidxRow3[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA13 = &Mount_Control_ConstP.GIRFBcontroller_A[13];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 5;
      *pxnew3 = (*pA13++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA13++) * xd[*pAidx++];
      }
    }

    xnew[3] += (-14.623425787542544)*rtb_Sum4;

    {
      static const int_T colAidxRow4[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA19 = &Mount_Control_ConstP.GIRFBcontroller_A[19];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 5;
      *pxnew4 = (*pA19++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA19++) * xd[*pAidx++];
      }
    }

    xnew[4] += (117.11869218551109)*rtb_Sum4;

    {
      static const int_T colAidxRow5[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA25 = &Mount_Control_ConstP.GIRFBcontroller_A[25];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 5;
      *pxnew5 = (*pA25++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA25++) * xd[*pAidx++];
      }
    }

    xnew[5] += (-0.38705854393794803)*rtb_Sum4;

    {
      static const int_T colAidxRow6[6] = { 1, 2, 3, 4, 5, 6 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA31 = &Mount_Control_ConstP.GIRFBcontroller_A[31];
      const real_T *xd = &Mount_Control_DW.GIRFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 5;
      *pxnew6 = (*pA31++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA31++) * xd[*pAidx++];
      }
    }

    xnew[6] += (2.7889031441029655)*rtb_Sum4;
    (void) memcpy(&Mount_Control_DW.GIRFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*7);
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
