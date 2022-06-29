/*
 * File: Mount_Control.h
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

#ifndef RTW_HEADER_Mount_Control_h_
#define RTW_HEADER_Mount_Control_h_
#include <string.h>
#ifndef Mount_Control_COMMON_INCLUDES_
# define Mount_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Control_COMMON_INCLUDES_ */

#include "Mount_Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RTout;                        /* '<S3>/RTout' */
  real_T RTout_p;                      /* '<S2>/RTout' */
  real_T RTout_f;                      /* '<S5>/RTout' */
  real_T RTout_j;                      /* '<S4>/RTout' */
  real_T RTout_o;                      /* '<S7>/RTout' */
  real_T RTout_pe;                     /* '<S6>/RTout' */
  real_T RTin;                         /* '<S2>/RTin' */
  real_T RTin_j;                       /* '<S3>/RTin' */
  real_T RTin_p;                       /* '<S4>/RTin' */
  real_T RTin_c;                       /* '<S5>/RTin' */
  real_T RTin_n;                       /* '<S6>/RTin' */
  real_T RTin_h;                       /* '<S7>/RTin' */
} B_Mount_Control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteSS_DSTATE[13];        /* '<S2>/Discrete SS' */
  real_T DiscreteSS_DSTATE_h[2];       /* '<S3>/Discrete SS' */
  real_T DiscreteSS_DSTATE_l[11];      /* '<S4>/Discrete SS' */
  real_T DiscreteSS_DSTATE_o[2];       /* '<S5>/Discrete SS' */
  real_T DiscreteSS_DSTATE_p[7];       /* '<S6>/Discrete SS' */
  real_T DiscreteSS_DSTATE_oc[2];      /* '<S7>/Discrete SS' */
  real_T RTout_Buffer0;                /* '<S3>/RTout' */
  real_T RTout_Buffer0_m;              /* '<S2>/RTout' */
  real_T RTout_Buffer0_g;              /* '<S5>/RTout' */
  real_T RTout_Buffer0_e;              /* '<S4>/RTout' */
  real_T RTout_Buffer0_o;              /* '<S7>/RTout' */
  real_T RTout_Buffer0_h;              /* '<S6>/RTout' */
} DW_Mount_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: DiscreteSS_A
   * Referenced by: '<S2>/Discrete SS'
   */
  real_T DiscreteSS_A[145];

  /* Computed Parameter: DiscreteSS_C
   * Referenced by: '<S2>/Discrete SS'
   */
  real_T DiscreteSS_C[13];

  /* Computed Parameter: DiscreteSS_A_i
   * Referenced by: '<S4>/Discrete SS'
   */
  real_T DiscreteSS_A_i[101];

  /* Computed Parameter: DiscreteSS_C_n
   * Referenced by: '<S4>/Discrete SS'
   */
  real_T DiscreteSS_C_n[11];

  /* Computed Parameter: DiscreteSS_A_b
   * Referenced by: '<S6>/Discrete SS'
   */
  real_T DiscreteSS_A_b[37];

  /* Computed Parameter: DiscreteSS_C_e
   * Referenced by: '<S6>/Discrete SS'
   */
  real_T DiscreteSS_C_e[7];
} ConstP_Mount_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_SP[3];                  /* '<Root>/Mount_SP' */
  real_T Mount_FB[14];                 /* '<Root>/Mount_FB' */
} ExtU_Mount_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
} ExtY_Mount_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Control_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Mount_Control_T Mount_Control_B;

/* Block states (default storage) */
extern DW_Mount_Control_T Mount_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mount_Control_T Mount_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mount_Control_T Mount_Control_Y;

/* Constant parameters (default storage) */
extern const ConstP_Mount_Control_T Mount_Control_ConstP;

/* Model entry point functions */
extern void Mount_Control_initialize(void);
extern void Mount_Control_step(void);
extern void Mount_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mount_Control_T *const Mount_Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ims_Build5pt1f/Mount_Control')    - opens subsystem ims_Build5pt1f/Mount_Control
 * hilite_system('ims_Build5pt1f/Mount_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1f'
 * '<S1>'   : 'ims_Build5pt1f/Mount_Control'
 * '<S2>'   : 'ims_Build5pt1f/Mount_Control/AZ FB controller'
 * '<S3>'   : 'ims_Build5pt1f/Mount_Control/AZ FF controller'
 * '<S4>'   : 'ims_Build5pt1f/Mount_Control/EL FB controller'
 * '<S5>'   : 'ims_Build5pt1f/Mount_Control/EL FF controller'
 * '<S6>'   : 'ims_Build5pt1f/Mount_Control/GIR FB controller'
 * '<S7>'   : 'ims_Build5pt1f/Mount_Control/GIR FF controller'
 */
#endif                                 /* RTW_HEADER_Mount_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
