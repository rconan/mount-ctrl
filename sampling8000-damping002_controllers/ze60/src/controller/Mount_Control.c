/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 1.1352
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Thu Sep 15 17:17:21 2022
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
    rtb_Sum2 += 1.9906517459704861E+10*Mount_Control_U.Mount_SP[0];
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

    rtb_Sum3 += 1.8213855463096222E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum2' */
  rtb_Sum2 += rtb_Sum3;

  /* DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum3 = (640690.340915277)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (-109925.08393817773)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    rtb_Sum3 += 1.5826975271483265E+10*Mount_Control_U.Mount_SP[1];
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

    rtb_Sum5 += 1.4486590543091078E+10*rtb_Sum;
  }

  /* Sum: '<S1>/Sum3' */
  rtb_Sum3 += rtb_Sum5;

  /* DiscreteStateSpace: '<S1>/GIR FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum5 = (91226.608932439645)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (-15652.01159419358)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    rtb_Sum5 += 3.2088146652559686E+8*Mount_Control_U.Mount_SP[2];
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

    rtb_GIRFBcontroller += 1.0689932861588811E+9*rtb_Sum4;
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
    xnew[0] = (0.99732145933997551)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.0011089773880692607)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[0] += (-89.5932059814842)*Mount_Control_U.Mount_SP[0];
    xnew[1] = (-0.0011089773880692594)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.999539414116114)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[1] += (-15.303424018617452)*Mount_Control_U.Mount_SP[0];
    (void) memcpy(&Mount_Control_DW.AZFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[15];
    xnew[0] = (1.0)*Mount_Control_DW.AZFBcontroller_DSTATE[0];
    xnew[0] += (-50.538329527838428)*rtb_Sum1;

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

    xnew[1] += (-235.31691094278631)*rtb_Sum1;

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

    xnew[2] += (-1714.291358073729)*rtb_Sum1;

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

    xnew[3] += (-14.305558140334281)*rtb_Sum1;

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

    xnew[4] += (-513.44918938985347)*rtb_Sum1;

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

    xnew[5] += (108.13004304778804)*rtb_Sum1;

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

    xnew[6] += (-5.8219450702731343)*rtb_Sum1;

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

    xnew[7] += (-146.92829610899813)*rtb_Sum1;

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

    xnew[8] += (11.641413413479119)*rtb_Sum1;

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

    xnew[9] += (-33.93998500947815)*rtb_Sum1;

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

    xnew[10] += (5.6090693896305934)*rtb_Sum1;

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

    xnew[11] += (-23.688506712809478)*rtb_Sum1;

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

    xnew[12] += (-4.4754271663747467)*rtb_Sum1;

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

    xnew[13] += (-17.113613897891778)*rtb_Sum1;

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

    xnew[14] += (23.995831610552468)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW.AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.99732145933997551)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.0011089773880692598)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[0] += (-79.887051965611946)*Mount_Control_U.Mount_SP[1];
    xnew[1] = (-0.0011089773880692589)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.999539414116114)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[1] += (-13.645514929778768)*Mount_Control_U.Mount_SP[1];
    (void) memcpy(&Mount_Control_DW.ELFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[11];
    xnew[0] = (1.0)*Mount_Control_DW.ELFBcontroller_DSTATE[0];
    xnew[0] += (64.041228486352139)*rtb_Sum;

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

    xnew[1] += (-1530.9538086070381)*rtb_Sum;

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

    xnew[2] += (184.86361572085411)*rtb_Sum;

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

    xnew[3] += (0.734377606907632)*rtb_Sum;

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

    xnew[4] += (-410.94538415404907)*rtb_Sum;

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

    xnew[5] += (-174.66450556410481)*rtb_Sum;

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

    xnew[6] += (-11.402617257960992)*rtb_Sum;

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

    xnew[7] += (-25.616279825500204)*rtb_Sum;

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

    xnew[8] += (-12.093367533239814)*rtb_Sum;

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

    xnew[9] += (-20.4042067711195)*rtb_Sum;

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

    xnew[10] += (-8.1881344003242784)*rtb_Sum;
    (void) memcpy(&Mount_Control_DW.ELFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*11);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.99732145933997551)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (0.00110897738806926)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    xnew[0] += (-11.374956641333366)*Mount_Control_U.Mount_SP[2];
    xnew[1] = (-0.0011089773880692583)*Mount_Control_DW.GIRFFcontroller_DSTATE[0]
      + (0.999539414116114)*Mount_Control_DW.GIRFFcontroller_DSTATE[1];
    xnew[1] += (-1.9429574237101024)*Mount_Control_U.Mount_SP[2];
    (void) memcpy(&Mount_Control_DW.GIRFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/GIR FB controller' */
  {
    real_T xnew[9];
    xnew[0] = (1.0)*Mount_Control_DW.GIRFBcontroller_DSTATE[0];
    xnew[0] += (7.94767040342251)*rtb_Sum4;

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

    xnew[1] += (43.262302888841624)*rtb_Sum4;

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

    xnew[2] += (435.15268038029194)*rtb_Sum4;

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

    xnew[3] += (-4.452044734987874)*rtb_Sum4;

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

    xnew[4] += (83.144938618884851)*rtb_Sum4;

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

    xnew[5] += (-54.729926342225838)*rtb_Sum4;

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

    xnew[6] += (-8.8414646445170071)*rtb_Sum4;

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

    xnew[7] += (4.39411354954734)*rtb_Sum4;

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

    xnew[8] += (3.0173724348774345)*rtb_Sum4;
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
