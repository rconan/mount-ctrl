/*
 * File: Mount_Control.c
 *
 * Code generated for Simulink model 'Mount_Control'.
 *
 * Model version                  : 1.980
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar  9 16:22:21 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mount_Control.h"
#include "Mount_Control_private.h"

/* Block signals (default storage) */
B_Mount_Control_T Mount_Control_B;

/* Block states (default storage) */
DW_Mount_Control_T Mount_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Mount_Control_T Mount_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Mount_Control_T Mount_Control_Y;

/* Real-time model */
RT_MODEL_Mount_Control_T Mount_Control_M_;
RT_MODEL_Mount_Control_T *const Mount_Control_M = &Mount_Control_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Mount_Control_M->Timing.TaskCounters.TID[1])++;
  if ((Mount_Control_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.002s, 0.0s] */
    Mount_Control_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Mount_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_DiscreteSS;
  real_T rtb_DiscreteSS_a;
  real_T rtb_DiscreteSS_d;
  real_T rtb_DiscreteSS_g;
  real_T rtb_DiscreteSS_l;
  real_T rtb_DiscreteSS_o;
  real_T rtb_Sum1;
  real_T rtb_Sum;
  real_T rtb_Sum4;
  int32_T i;

  /* RateTransition: '<S3>/RTout' incorporates:
   *  RateTransition: '<S5>/RTout'
   */
  if (Mount_Control_M->Timing.TaskCounters.TID[1] == 0) {
    Mount_Control_B.RTout = Mount_Control_DW.RTout_Buffer0;

    /* RateTransition: '<S2>/RTout' */
    Mount_Control_B.RTout_p = Mount_Control_DW.RTout_Buffer0_m;
    Mount_Control_B.RTout_f = Mount_Control_DW.RTout_Buffer0_g;

    /* RateTransition: '<S4>/RTout' */
    Mount_Control_B.RTout_j = Mount_Control_DW.RTout_Buffer0_e;
  }

  /* End of RateTransition: '<S3>/RTout' */

  /* Sum: '<S1>/Sum2' */
  rtb_Sum4 = Mount_Control_B.RTout + Mount_Control_B.RTout_p;

  /* Sum: '<S1>/Sum3' */
  rtb_Sum = Mount_Control_B.RTout_f + Mount_Control_B.RTout_j;

  /* RateTransition: '<S7>/RTout' */
  if (Mount_Control_M->Timing.TaskCounters.TID[1] == 0) {
    Mount_Control_B.RTout_o = Mount_Control_DW.RTout_Buffer0_o;

    /* RateTransition: '<S6>/RTout' */
    Mount_Control_B.RTout_pe = Mount_Control_DW.RTout_Buffer0_h;
  }

  /* End of RateTransition: '<S7>/RTout' */

  /* Sum: '<S1>/Sum5' */
  rtb_Sum1 = Mount_Control_B.RTout_o + Mount_Control_B.RTout_pe;

  /* Outport: '<Root>/Mount_cmd' */
  Mount_Control_Y.Mount_cmd[0] = rtb_Sum4;
  Mount_Control_Y.Mount_cmd[1] = rtb_Sum;
  Mount_Control_Y.Mount_cmd[2] = rtb_Sum1;

  /* Gain: '<S1>/AZ average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum1 = ((0.25 * Mount_Control_U.Mount_FB[0] + 0.25 *
               Mount_Control_U.Mount_FB[1]) + 0.25 * Mount_Control_U.Mount_FB[2])
    + 0.25 * Mount_Control_U.Mount_FB[3];

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum1 = Mount_Control_U.Mount_SP[0] - rtb_Sum1;

  /* RateTransition: '<S2>/RTin' */
  if (Mount_Control_M->Timing.TaskCounters.TID[1] == 0) {
    Mount_Control_B.RTin = rtb_Sum1;

    /* DiscreteStateSpace: '<S2>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[13] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = Mount_Control_ConstP.DiscreteSS_C;
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *y0 = &rtb_DiscreteSS;
        int_T numNonZero = 12;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS += 1.1275325064575505E+11*Mount_Control_B.RTin;
    }

    /* RateTransition: '<S3>/RTin' incorporates:
     *  Inport: '<Root>/Mount_SP'
     */
    Mount_Control_B.RTin_j = Mount_Control_U.Mount_SP[0];

    /* DiscreteStateSpace: '<S3>/Discrete SS' */
    {
      rtb_DiscreteSS_a = (725703.23025879019)*
        Mount_Control_DW.DiscreteSS_DSTATE_h[0]
        + (-124510.98979647842)*Mount_Control_DW.DiscreteSS_DSTATE_h[1];
      rtb_DiscreteSS_a += 1.9832929148970306E+10*Mount_Control_B.RTin_j;
    }
  }

  /* End of RateTransition: '<S2>/RTin' */

  /* Gain: '<S1>/EL average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum = 0.0;
  for (i = 0; i < 6; i++) {
    rtb_Sum += Mount_Control_U.Mount_FB[i + 4] * 0.16666666666666666;
  }

  /* End of Gain: '<S1>/EL average and  m2rad conv+' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum = Mount_Control_U.Mount_SP[1] - rtb_Sum;

  /* RateTransition: '<S4>/RTin' */
  if (Mount_Control_M->Timing.TaskCounters.TID[1] == 0) {
    Mount_Control_B.RTin_p = rtb_Sum;

    /* DiscreteStateSpace: '<S4>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = Mount_Control_ConstP.DiscreteSS_C_n;
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *y0 = &rtb_DiscreteSS_d;
        int_T numNonZero = 10;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_d += 8.88504406743453E+10*Mount_Control_B.RTin_p;
    }

    /* RateTransition: '<S5>/RTin' incorporates:
     *  Inport: '<Root>/Mount_SP'
     */
    Mount_Control_B.RTin_c = Mount_Control_U.Mount_SP[1];

    /* DiscreteStateSpace: '<S5>/Discrete SS' */
    {
      rtb_DiscreteSS_g = (640680.60984232358)*
        Mount_Control_DW.DiscreteSS_DSTATE_o[0]
        + (-109923.4143500115)*Mount_Control_DW.DiscreteSS_DSTATE_o[1];
      rtb_DiscreteSS_g += 1.5457950368612776E+10*Mount_Control_B.RTin_c;
    }
  }

  /* End of RateTransition: '<S4>/RTin' */

  /* Gain: '<S1>/GIR average and  m2rad conv+' incorporates:
   *  Inport: '<Root>/Mount_FB'
   */
  rtb_Sum4 = ((0.25 * Mount_Control_U.Mount_FB[10] + 0.25 *
               Mount_Control_U.Mount_FB[11]) + 0.25 * Mount_Control_U.Mount_FB
              [12]) + 0.25 * Mount_Control_U.Mount_FB[13];

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/Mount_SP'
   */
  rtb_Sum4 = Mount_Control_U.Mount_SP[2] - rtb_Sum4;

  /* RateTransition: '<S6>/RTin' */
  if (Mount_Control_M->Timing.TaskCounters.TID[1] == 0) {
    Mount_Control_B.RTin_n = rtb_Sum4;

    /* DiscreteStateSpace: '<S6>/Discrete SS' */
    {
      {
        static const int_T colCidxRow0[7] = { 0, 1, 2, 3, 4, 5, 6 };

        const int_T *pCidx = &colCidxRow0[0];
        const real_T *pC0 = Mount_Control_ConstP.DiscreteSS_C_e;
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *y0 = &rtb_DiscreteSS_l;
        int_T numNonZero = 6;
        *y0 = (*pC0++) * xd[*pCidx++];
        while (numNonZero--) {
          *y0 += (*pC0++) * xd[*pCidx++];
        }
      }

      rtb_DiscreteSS_l += 7.981638686038805E+9*Mount_Control_B.RTin_n;
    }

    /* RateTransition: '<S7>/RTin' incorporates:
     *  Inport: '<Root>/Mount_SP'
     */
    Mount_Control_B.RTin_h = Mount_Control_U.Mount_SP[2];

    /* DiscreteStateSpace: '<S7>/Discrete SS' */
    {
      rtb_DiscreteSS_o = (91226.608932439645)*
        Mount_Control_DW.DiscreteSS_DSTATE_oc[0]
        + (-15652.01159419358)*Mount_Control_DW.DiscreteSS_DSTATE_oc[1];
      rtb_DiscreteSS_o += 3.1340925074916041E+8*Mount_Control_B.RTin_h;
    }

    /* Update for RateTransition: '<S3>/RTout' */
    Mount_Control_DW.RTout_Buffer0 = rtb_DiscreteSS_a;

    /* Update for RateTransition: '<S2>/RTout' */
    Mount_Control_DW.RTout_Buffer0_m = rtb_DiscreteSS;

    /* Update for RateTransition: '<S5>/RTout' */
    Mount_Control_DW.RTout_Buffer0_g = rtb_DiscreteSS_g;

    /* Update for RateTransition: '<S4>/RTout' */
    Mount_Control_DW.RTout_Buffer0_e = rtb_DiscreteSS_d;

    /* Update for RateTransition: '<S7>/RTout' */
    Mount_Control_DW.RTout_Buffer0_o = rtb_DiscreteSS_o;

    /* Update for RateTransition: '<S6>/RTout' */
    Mount_Control_DW.RTout_Buffer0_h = rtb_DiscreteSS_l;

    /* Update for DiscreteStateSpace: '<S2>/Discrete SS' */
    {
      real_T xnew[13];
      xnew[0] = (1.0)*Mount_Control_DW.DiscreteSS_DSTATE[0];
      xnew[0] += (766.49890444083849)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &Mount_Control_ConstP.DiscreteSS_A[1];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 11;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (10300.161479743674)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow2[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA13 = &Mount_Control_ConstP.DiscreteSS_A[13];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 11;
        *pxnew2 = (*pA13++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA13++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-3189.0520110335933)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow3[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA25 = &Mount_Control_ConstP.DiscreteSS_A[25];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 11;
        *pxnew3 = (*pA25++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA25++) * xd[*pAidx++];
        }
      }

      xnew[3] += (451.35923731329569)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow4[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA37 = &Mount_Control_ConstP.DiscreteSS_A[37];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 11;
        *pxnew4 = (*pA37++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA37++) * xd[*pAidx++];
        }
      }

      xnew[4] += (2402.4605856747121)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow5[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA49 = &Mount_Control_ConstP.DiscreteSS_A[49];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 11;
        *pxnew5 = (*pA49++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA49++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-317.40144816375715)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow6[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA61 = &Mount_Control_ConstP.DiscreteSS_A[61];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 11;
        *pxnew6 = (*pA61++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA61++) * xd[*pAidx++];
        }
      }

      xnew[6] += (-878.57427609884644)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow7[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA73 = &Mount_Control_ConstP.DiscreteSS_A[73];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 11;
        *pxnew7 = (*pA73++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA73++) * xd[*pAidx++];
        }
      }

      xnew[7] += (417.49218394446649)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow8[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA85 = &Mount_Control_ConstP.DiscreteSS_A[85];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 11;
        *pxnew8 = (*pA85++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA85++) * xd[*pAidx++];
        }
      }

      xnew[8] += (212.80379359174168)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow9[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
          12 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA97 = &Mount_Control_ConstP.DiscreteSS_A[97];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 11;
        *pxnew9 = (*pA97++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA97++) * xd[*pAidx++];
        }
      }

      xnew[9] += (-41.742854362578527)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow10[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA109 = &Mount_Control_ConstP.DiscreteSS_A[109];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 11;
        *pxnew10 = (*pA109++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA109++) * xd[*pAidx++];
        }
      }

      xnew[10] += (-263.02335892275011)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow11[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow11[0];
        const real_T *pA121 = &Mount_Control_ConstP.DiscreteSS_A[121];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew11 = &xnew[11];
        int_T numNonZero = 11;
        *pxnew11 = (*pA121++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew11 += (*pA121++) * xd[*pAidx++];
        }
      }

      xnew[11] += (41.225903114718989)*Mount_Control_B.RTin;

      {
        static const int_T colAidxRow12[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
          11, 12 };

        const int_T *pAidx = &colAidxRow12[0];
        const real_T *pA133 = &Mount_Control_ConstP.DiscreteSS_A[133];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE[0];
        real_T *pxnew12 = &xnew[12];
        int_T numNonZero = 11;
        *pxnew12 = (*pA133++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew12 += (*pA133++) * xd[*pAidx++];
        }
      }

      xnew[12] += (-72.760952199710317)*Mount_Control_B.RTin;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE[0], xnew,
                    sizeof(real_T)*13);
    }

    /* Update for DiscreteStateSpace: '<S3>/Discrete SS' */
    {
      real_T xnew[2];
      xnew[0] = (0.95785000633215067)*Mount_Control_DW.DiscreteSS_DSTATE_h[0]
        + (0.017330450452292336)*Mount_Control_DW.DiscreteSS_DSTATE_h[1];
      xnew[0] += (-1394.7060470658025)*Mount_Control_B.RTin_j;
      xnew[1] = (-0.017330450452292333)*Mount_Control_DW.DiscreteSS_DSTATE_h[0]
        + (0.9925109072367353)*Mount_Control_DW.DiscreteSS_DSTATE_h[1];
      xnew[1] += (-222.1024782987171)*Mount_Control_B.RTin_j;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE_h[0], xnew,
                    sizeof(real_T)*2);
    }

    /* Update for DiscreteStateSpace: '<S4>/Discrete SS' */
    {
      real_T xnew[11];
      xnew[0] = (1.0)*Mount_Control_DW.DiscreteSS_DSTATE_l[0];
      xnew[0] += (-1203.2495178273616)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &Mount_Control_ConstP.DiscreteSS_A_i[1];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 9;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (2713.7650999261296)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA11 = &Mount_Control_ConstP.DiscreteSS_A_i[11];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 9;
        *pxnew2 = (*pA11++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA11++) * xd[*pAidx++];
        }
      }

      xnew[2] += (-8023.215776361847)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA21 = &Mount_Control_ConstP.DiscreteSS_A_i[21];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 9;
        *pxnew3 = (*pA21++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA21++) * xd[*pAidx++];
        }
      }

      xnew[3] += (203.00216480929555)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA31 = &Mount_Control_ConstP.DiscreteSS_A_i[31];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 9;
        *pxnew4 = (*pA31++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA31++) * xd[*pAidx++];
        }
      }

      xnew[4] += (3613.3023564463747)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA41 = &Mount_Control_ConstP.DiscreteSS_A_i[41];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 9;
        *pxnew5 = (*pA41++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA41++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-472.5139795724632)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA51 = &Mount_Control_ConstP.DiscreteSS_A_i[51];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 9;
        *pxnew6 = (*pA51++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA51++) * xd[*pAidx++];
        }
      }

      xnew[6] += (308.409476298827)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow7[0];
        const real_T *pA61 = &Mount_Control_ConstP.DiscreteSS_A_i[61];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew7 = &xnew[7];
        int_T numNonZero = 9;
        *pxnew7 = (*pA61++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew7 += (*pA61++) * xd[*pAidx++];
        }
      }

      xnew[7] += (9.8988871151512114)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow8[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow8[0];
        const real_T *pA71 = &Mount_Control_ConstP.DiscreteSS_A_i[71];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew8 = &xnew[8];
        int_T numNonZero = 9;
        *pxnew8 = (*pA71++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew8 += (*pA71++) * xd[*pAidx++];
        }
      }

      xnew[8] += (-103.42298113086716)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow9[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow9[0];
        const real_T *pA81 = &Mount_Control_ConstP.DiscreteSS_A_i[81];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew9 = &xnew[9];
        int_T numNonZero = 9;
        *pxnew9 = (*pA81++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew9 += (*pA81++) * xd[*pAidx++];
        }
      }

      xnew[9] += (0.097034924813360846)*Mount_Control_B.RTin_p;

      {
        static const int_T colAidxRow10[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        const int_T *pAidx = &colAidxRow10[0];
        const real_T *pA91 = &Mount_Control_ConstP.DiscreteSS_A_i[91];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_l[0];
        real_T *pxnew10 = &xnew[10];
        int_T numNonZero = 9;
        *pxnew10 = (*pA91++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew10 += (*pA91++) * xd[*pAidx++];
        }
      }

      xnew[10] += (54.730225339716711)*Mount_Control_B.RTin_p;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE_l[0], xnew,
                    sizeof(real_T)*11);
    }

    /* Update for DiscreteStateSpace: '<S5>/Discrete SS' */
    {
      real_T xnew[2];
      xnew[0] = (0.95785000633215067)*Mount_Control_DW.DiscreteSS_DSTATE_o[0]
        + (0.0173304504522923)*Mount_Control_DW.DiscreteSS_DSTATE_o[1];
      xnew[0] += (-1231.3037665083086)*Mount_Control_B.RTin_c;
      xnew[1] = (-0.017330450452292322)*Mount_Control_DW.DiscreteSS_DSTATE_o[0]
        + (0.9925109072367353)*Mount_Control_DW.DiscreteSS_DSTATE_o[1];
      xnew[1] += (-196.08118761324744)*Mount_Control_B.RTin_c;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE_o[0], xnew,
                    sizeof(real_T)*2);
    }

    /* Update for DiscreteStateSpace: '<S6>/Discrete SS' */
    {
      real_T xnew[7];
      xnew[0] = (1.0)*Mount_Control_DW.DiscreteSS_DSTATE_p[0];
      xnew[0] += (222.35931664024622)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow1[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow1[0];
        const real_T *pA1 = &Mount_Control_ConstP.DiscreteSS_A_b[1];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew1 = &xnew[1];
        int_T numNonZero = 5;
        *pxnew1 = (*pA1++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew1 += (*pA1++) * xd[*pAidx++];
        }
      }

      xnew[1] += (2649.5749037265773)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow2[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow2[0];
        const real_T *pA7 = &Mount_Control_ConstP.DiscreteSS_A_b[7];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew2 = &xnew[2];
        int_T numNonZero = 5;
        *pxnew2 = (*pA7++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew2 += (*pA7++) * xd[*pAidx++];
        }
      }

      xnew[2] += (72.787896303320849)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow3[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow3[0];
        const real_T *pA13 = &Mount_Control_ConstP.DiscreteSS_A_b[13];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew3 = &xnew[3];
        int_T numNonZero = 5;
        *pxnew3 = (*pA13++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew3 += (*pA13++) * xd[*pAidx++];
        }
      }

      xnew[3] += (75.734595433818384)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow4[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow4[0];
        const real_T *pA19 = &Mount_Control_ConstP.DiscreteSS_A_b[19];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew4 = &xnew[4];
        int_T numNonZero = 5;
        *pxnew4 = (*pA19++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew4 += (*pA19++) * xd[*pAidx++];
        }
      }

      xnew[4] += (253.59014658051404)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow5[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow5[0];
        const real_T *pA25 = &Mount_Control_ConstP.DiscreteSS_A_b[25];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew5 = &xnew[5];
        int_T numNonZero = 5;
        *pxnew5 = (*pA25++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew5 += (*pA25++) * xd[*pAidx++];
        }
      }

      xnew[5] += (-1.9289719405259194)*Mount_Control_B.RTin_n;

      {
        static const int_T colAidxRow6[6] = { 1, 2, 3, 4, 5, 6 };

        const int_T *pAidx = &colAidxRow6[0];
        const real_T *pA31 = &Mount_Control_ConstP.DiscreteSS_A_b[31];
        const real_T *xd = &Mount_Control_DW.DiscreteSS_DSTATE_p[0];
        real_T *pxnew6 = &xnew[6];
        int_T numNonZero = 5;
        *pxnew6 = (*pA31++) * xd[*pAidx++];
        while (numNonZero--) {
          *pxnew6 += (*pA31++) * xd[*pAidx++];
        }
      }

      xnew[6] += (0.8477861980910113)*Mount_Control_B.RTin_n;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE_p[0], xnew,
                    sizeof(real_T)*7);
    }

    /* Update for DiscreteStateSpace: '<S7>/Discrete SS' */
    {
      real_T xnew[2];
      xnew[0] = (0.95785000633215067)*Mount_Control_DW.DiscreteSS_DSTATE_oc[0]
        + (0.017330450452292343)*Mount_Control_DW.DiscreteSS_DSTATE_oc[1];
      xnew[0] += (-175.32552953637563)*Mount_Control_B.RTin_h;
      xnew[1] = (-0.017330450452292326)*Mount_Control_DW.DiscreteSS_DSTATE_oc[0]
        + (0.9925109072367353)*Mount_Control_DW.DiscreteSS_DSTATE_oc[1];
      xnew[1] += (-27.920029959708582)*Mount_Control_B.RTin_h;
      (void) memcpy(&Mount_Control_DW.DiscreteSS_DSTATE_oc[0], xnew,
                    sizeof(real_T)*2);
    }
  }

  /* End of RateTransition: '<S6>/RTin' */
  rate_scheduler();
}

/* Model initialize function */
void Mount_Control_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Mount_Control_M, 0,
                sizeof(RT_MODEL_Mount_Control_T));

  /* block I/O */
  (void) memset(((void *) &Mount_Control_B), 0,
                sizeof(B_Mount_Control_T));

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
