/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 5.59
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Aug 31 13:54:57 2022
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
static RT_MODEL_Mount_Control_T Mount_Control_M_;
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
    rtb_Sum2 += 2.0305780303572926E+10*Mount_Control_U.Mount_SP[0];
  }

  /* Sum: '<S1>/Sum3' incorporates:
   *  Gain: '<S1>/AZ average and  m2rad conv+'
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

    rtb_Sum3 += 1.434338636291778E+10*rtb_Sum1;
  }

  /* Sum: '<S1>/Sum2' */
  rtb_Sum2 += rtb_Sum3;

  /* DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    rtb_Sum3 = (640680.60984232358)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (-109923.4143500115)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    rtb_Sum3 += 1.5826494501689964E+10*Mount_Control_U.Mount_SP[1];
  }

  /* Gain: '<S1>/EL average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  tmp = 0.0;
  for (i = 0; i < 6; i++) {
    tmp += Mount_Control_U.Mount_FB[i + 4] * 0.16666666666666666;
  }

  /* Sum: '<S1>/Sum5' incorporates:
   *  Gain: '<S1>/EL average and  m2rad conv+'
   */
  rtb_Sum5 = tmp;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum = Mount_Control_U.Mount_SP[1] - rtb_Sum5;

  /* DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    {
      static const int_T colCidxRow0[19] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 = Mount_Control_ConstP.ELFBcontroller_C;
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *y0 = &rtb_Sum5;
      int_T numNonZero = 18;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }

    rtb_Sum5 += 1.0054484696700634E+10*rtb_Sum;
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

  /* DiscreteStateSpace: '<S1>/GIR FB controller' incorporates:
   *  Gain: '<S1>/GIR average and  m2rad conv+'
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

    rtb_GIRFBcontroller += 1.0714601612324175E+9*rtb_Sum4;
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
      + (0.0011089773880692596)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[0] += (-90.487225988884973)*Mount_Control_U.Mount_SP[0];
    xnew[1] = (-0.0011089773880692587)*Mount_Control_DW.AZFFcontroller_DSTATE[0]
      + (0.999539414116114)*Mount_Control_DW.AZFFcontroller_DSTATE[1];
    xnew[1] += (-15.456131660949278)*Mount_Control_U.Mount_SP[0];
    (void) memcpy(&Mount_Control_DW.AZFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/AZ FB controller' */
  {
    real_T xnew[15];

    {
      static const int_T colAidxRow0[14] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = Mount_Control_ConstP.AZFBcontroller_A;
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 13;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (14443.006826302388)*rtb_Sum1;

    {
      static const int_T colAidxRow1[14] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA14 = &Mount_Control_ConstP.AZFBcontroller_A[14];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 13;
      *pxnew1 = (*pA14++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA14++) * xd[*pAidx++];
      }
    }

    xnew[1] += (462.17621844167644)*rtb_Sum1;

    {
      static const int_T colAidxRow2[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA28 = &Mount_Control_ConstP.AZFBcontroller_A[28];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 14;
      *pxnew2 = (*pA28++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA28++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.028886013652604774)*rtb_Sum1;

    {
      static const int_T colAidxRow3[12] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        14 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA43 = &Mount_Control_ConstP.AZFBcontroller_A[43];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 11;
      *pxnew3 = (*pA43++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA43++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.029610987347991984)*rtb_Sum1;

    {
      static const int_T colAidxRow4[12] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        14 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA55 = &Mount_Control_ConstP.AZFBcontroller_A[55];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 11;
      *pxnew4 = (*pA55++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA55++) * xd[*pAidx++];
      }
    }

    xnew[4] += (5.922197469598398E-5)*rtb_Sum1;

    {
      static const int_T colAidxRow5[10] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA67 = &Mount_Control_ConstP.AZFBcontroller_A[67];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 9;
      *pxnew5 = (*pA67++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA67++) * xd[*pAidx++];
      }
    }

    xnew[5] += (0.029631178245141006)*rtb_Sum1;

    {
      static const int_T colAidxRow6[10] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA77 = &Mount_Control_ConstP.AZFBcontroller_A[77];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 9;
      *pxnew6 = (*pA77++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA77++) * xd[*pAidx++];
      }
    }

    xnew[6] += (0.00011852471298056403)*rtb_Sum1;

    {
      static const int_T colAidxRow7[8] = { 7, 8, 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA87 = &Mount_Control_ConstP.AZFBcontroller_A[87];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 7;
      *pxnew7 = (*pA87++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA87++) * xd[*pAidx++];
      }
    }

    xnew[7] += (0.029654198212646747)*rtb_Sum1;

    {
      static const int_T colAidxRow8[8] = { 7, 8, 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA95 = &Mount_Control_ConstP.AZFBcontroller_A[95];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 7;
      *pxnew8 = (*pA95++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA95++) * xd[*pAidx++];
      }
    }

    xnew[8] += (0.00011861679285058699)*rtb_Sum1;

    {
      static const int_T colAidxRow9[6] = { 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA103 = &Mount_Control_ConstP.AZFBcontroller_A[103];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 5;
      *pxnew9 = (*pA103++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA103++) * xd[*pAidx++];
      }
    }

    xnew[9] += (0.0296862331815199)*rtb_Sum1;

    {
      static const int_T colAidxRow10[6] = { 9, 10, 11, 12, 13, 14 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA109 = &Mount_Control_ConstP.AZFBcontroller_A[109];
      const real_T *xd = &Mount_Control_DW.AZFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 5;
      *pxnew10 = (*pA109++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA109++) * xd[*pAidx++];
      }
    }

    xnew[10] += (0.00011874493272607961)*rtb_Sum1;
    xnew[11] = (0.99263837685316181)*Mount_Control_DW.AZFBcontroller_DSTATE[11]
      + (-0.020319543494745851)*Mount_Control_DW.AZFBcontroller_DSTATE[12]
      + (-0.019633416704121557)*Mount_Control_DW.AZFBcontroller_DSTATE[13]
      + (0.0016274416143017059)*Mount_Control_DW.AZFBcontroller_DSTATE[14];
    xnew[11] += (0.0807023837545911)*rtb_Sum1;
    xnew[12] = (0.015941107014825293)*Mount_Control_DW.AZFBcontroller_DSTATE[11]
      + (0.99983744365204208)*Mount_Control_DW.AZFBcontroller_DSTATE[12]
      + (-0.00015706733363297248)*Mount_Control_DW.AZFBcontroller_DSTATE[13]
      + (1.3019532914413646E-5)*Mount_Control_DW.AZFBcontroller_DSTATE[14];
    xnew[12] += (0.00064561907003672875)*rtb_Sum1;
    xnew[13] = (0.95601148505547107)*Mount_Control_DW.AZFBcontroller_DSTATE[13]
      + (-0.041645387276679637)*Mount_Control_DW.AZFBcontroller_DSTATE[14];
    xnew[13] += (0.17160347392010261)*rtb_Sum1;
    xnew[14] = (0.031296183760887539)*Mount_Control_DW.AZFBcontroller_DSTATE[13]
      + (0.99933367380357319)*Mount_Control_DW.AZFBcontroller_DSTATE[14];
    xnew[14] += (0.0027456555827216418)*rtb_Sum1;
    (void) memcpy(&Mount_Control_DW.AZFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*15);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FF controller' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  {
    real_T xnew[2];
    xnew[0] = (0.99732145933997551)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.0011089773880692572)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[0] += (-79.885838607643137)*Mount_Control_U.Mount_SP[1];
    xnew[1] = (-0.0011089773880692581)*Mount_Control_DW.ELFFcontroller_DSTATE[0]
      + (0.999539414116114)*Mount_Control_DW.ELFFcontroller_DSTATE[1];
    xnew[1] += (-13.645307675988931)*Mount_Control_U.Mount_SP[1];
    (void) memcpy(&Mount_Control_DW.ELFFcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*2);
  }

  /* Update for DiscreteStateSpace: '<S1>/EL FB controller' */
  {
    real_T xnew[19];

    {
      static const int_T colAidxRow0[18] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 = Mount_Control_ConstP.ELFBcontroller_A;
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 17;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (18328.046391891483)*rtb_Sum;

    {
      static const int_T colAidxRow1[18] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA18 = &Mount_Control_ConstP.ELFBcontroller_A[18];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 17;
      *pxnew1 = (*pA18++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA18++) * xd[*pAidx++];
      }
    }

    xnew[1] += (586.49748454052747)*rtb_Sum;

    {
      static const int_T colAidxRow2[19] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA36 = &Mount_Control_ConstP.ELFBcontroller_A[36];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 18;
      *pxnew2 = (*pA36++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA36++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.036656092783782956)*rtb_Sum;

    {
      static const int_T colAidxRow3[16] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA55 = &Mount_Control_ConstP.ELFBcontroller_A[55];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 15;
      *pxnew3 = (*pA55++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA55++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.037573447927248788)*rtb_Sum;

    {
      static const int_T colAidxRow4[16] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
        14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA71 = &Mount_Control_ConstP.ELFBcontroller_A[71];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 15;
      *pxnew4 = (*pA71++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA71++) * xd[*pAidx++];
      }
    }

    xnew[4] += (0.00015029379170899518)*rtb_Sum;

    {
      static const int_T colAidxRow5[14] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow5[0];
      const real_T *pA87 = &Mount_Control_ConstP.ELFBcontroller_A[87];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew5 = &xnew[5];
      int_T numNonZero = 13;
      *pxnew5 = (*pA87++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew5 += (*pA87++) * xd[*pAidx++];
      }
    }

    xnew[5] += (0.037613549797663605)*rtb_Sum;

    {
      static const int_T colAidxRow6[14] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow6[0];
      const real_T *pA101 = &Mount_Control_ConstP.ELFBcontroller_A[101];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew6 = &xnew[6];
      int_T numNonZero = 13;
      *pxnew6 = (*pA101++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew6 += (*pA101++) * xd[*pAidx++];
      }
    }

    xnew[6] += (0.0001504541991906544)*rtb_Sum;

    {
      static const int_T colAidxRow7[12] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18 };

      const int_T *pAidx = &colAidxRow7[0];
      const real_T *pA115 = &Mount_Control_ConstP.ELFBcontroller_A[115];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew7 = &xnew[7];
      int_T numNonZero = 11;
      *pxnew7 = (*pA115++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew7 += (*pA115++) * xd[*pAidx++];
      }
    }

    xnew[7] += (0.075311494764803824)*rtb_Sum;

    {
      static const int_T colAidxRow8[12] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
        17, 18 };

      const int_T *pAidx = &colAidxRow8[0];
      const real_T *pA127 = &Mount_Control_ConstP.ELFBcontroller_A[127];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew8 = &xnew[8];
      int_T numNonZero = 11;
      *pxnew8 = (*pA127++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew8 += (*pA127++) * xd[*pAidx++];
      }
    }

    xnew[8] += (0.00060249195811843065)*rtb_Sum;

    {
      static const int_T colAidxRow9[10] = { 9, 10, 11, 12, 13, 14, 15, 16, 17,
        18 };

      const int_T *pAidx = &colAidxRow9[0];
      const real_T *pA139 = &Mount_Control_ConstP.ELFBcontroller_A[139];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew9 = &xnew[9];
      int_T numNonZero = 9;
      *pxnew9 = (*pA139++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew9 += (*pA139++) * xd[*pAidx++];
      }
    }

    xnew[9] += (0.07547595906301556)*rtb_Sum;

    {
      static const int_T colAidxRow10[10] = { 9, 10, 11, 12, 13, 14, 15, 16, 17,
        18 };

      const int_T *pAidx = &colAidxRow10[0];
      const real_T *pA149 = &Mount_Control_ConstP.ELFBcontroller_A[149];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew10 = &xnew[10];
      int_T numNonZero = 9;
      *pxnew10 = (*pA149++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew10 += (*pA149++) * xd[*pAidx++];
      }
    }

    xnew[10] += (0.0006038076725041247)*rtb_Sum;

    {
      static const int_T colAidxRow11[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow11[0];
      const real_T *pA159 = &Mount_Control_ConstP.ELFBcontroller_A[159];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew11 = &xnew[11];
      int_T numNonZero = 7;
      *pxnew11 = (*pA159++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew11 += (*pA159++) * xd[*pAidx++];
      }
    }

    xnew[11] += (0.0865295831326422)*rtb_Sum;

    {
      static const int_T colAidxRow12[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow12[0];
      const real_T *pA167 = &Mount_Control_ConstP.ELFBcontroller_A[167];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew12 = &xnew[12];
      int_T numNonZero = 7;
      *pxnew12 = (*pA167++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew12 += (*pA167++) * xd[*pAidx++];
      }
    }

    xnew[12] += (0.0013844733301222754)*rtb_Sum;

    {
      static const int_T colAidxRow13[6] = { 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow13[0];
      const real_T *pA175 = &Mount_Control_ConstP.ELFBcontroller_A[175];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew13 = &xnew[13];
      int_T numNonZero = 5;
      *pxnew13 = (*pA175++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew13 += (*pA175++) * xd[*pAidx++];
      }
    }

    xnew[13] += (0.089087028584918432)*rtb_Sum;

    {
      static const int_T colAidxRow14[6] = { 13, 14, 15, 16, 17, 18 };

      const int_T *pAidx = &colAidxRow14[0];
      const real_T *pA181 = &Mount_Control_ConstP.ELFBcontroller_A[181];
      const real_T *xd = &Mount_Control_DW.ELFBcontroller_DSTATE[0];
      real_T *pxnew14 = &xnew[14];
      int_T numNonZero = 5;
      *pxnew14 = (*pA181++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew14 += (*pA181++) * xd[*pAidx++];
      }
    }

    xnew[14] += (0.0014253924573586949)*rtb_Sum;
    xnew[15] = (0.98297589084833259)*Mount_Control_DW.ELFBcontroller_DSTATE[15]
      + (-0.051680167202304138)*Mount_Control_DW.ELFBcontroller_DSTATE[16]
      + (-0.026378309702732732)*Mount_Control_DW.ELFBcontroller_DSTATE[17]
      + (0.00047924048420368911)*Mount_Control_DW.ELFBcontroller_DSTATE[18];
    xnew[15] += (0.20919080434673049)*rtb_Sum;
    xnew[16] = (0.031727614253573323)*Mount_Control_DW.ELFBcontroller_DSTATE[15]
      + (0.9991731173247631)*Mount_Control_DW.ELFBcontroller_DSTATE[16]
      + (-0.00042205295524372382)*Mount_Control_DW.ELFBcontroller_DSTATE[17]
      + (7.6678477472590271E-6)*Mount_Control_DW.ELFBcontroller_DSTATE[18];
    xnew[16] += (0.0033470528695476883)*rtb_Sum;
    xnew[17] = (0.9703493759580597)*Mount_Control_DW.ELFBcontroller_DSTATE[17]
      + (-0.035797259173386414)*Mount_Control_DW.ELFBcontroller_DSTATE[18];
    xnew[17] += (0.21066108574018153)*rtb_Sum;
    xnew[18] = (0.063051180030657919)*Mount_Control_DW.ELFBcontroller_DSTATE[17]
      + (0.99885448770645169)*Mount_Control_DW.ELFBcontroller_DSTATE[18];
    xnew[18] += (0.0067411547436858092)*rtb_Sum;
    (void) memcpy(&Mount_Control_DW.ELFBcontroller_DSTATE[0], xnew,
                  sizeof(real_T)*19);
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
    real_T xnew[7];
    xnew[0] = (1.0)*Mount_Control_DW.GIRFBcontroller_DSTATE[0];
    xnew[0] += (-13.897457290015392)*rtb_Sum4;

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

    xnew[1] += (42.803374428405021)*rtb_Sum4;

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

    xnew[2] += (446.61870778474059)*rtb_Sum4;

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

    xnew[3] += (-54.518183836010557)*rtb_Sum4;

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

    xnew[4] += (-11.463503262000142)*rtb_Sum4;

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

    xnew[5] += (0.24893763873834704)*rtb_Sum4;

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

    xnew[6] += (4.7646539818566493)*rtb_Sum4;
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
