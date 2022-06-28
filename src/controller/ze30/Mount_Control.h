/*
 * File: Mount_Control.h
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

#ifndef RTW_HEADER_Mount_Control_h_
#define RTW_HEADER_Mount_Control_h_
#include <string.h>
#include <stddef.h>
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AZFFcontroller_DSTATE[2];     /* '<S1>/AZ FF controller' */
  real_T AZFBcontroller_DSTATE[13];    /* '<S1>/AZ FB controller' */
  real_T ELFFcontroller_DSTATE[2];     /* '<S1>/EL FF controller' */
  real_T ELFBcontroller_DSTATE[11];    /* '<S1>/EL FB controller' */
  real_T GIRFFcontroller_DSTATE[2];    /* '<S1>/GIR FF controller' */
  real_T GIRFBcontroller_DSTATE[7];    /* '<S1>/GIR FB controller' */
} DW_Mount_Control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: AZFBcontroller_A
   * Referenced by: '<S1>/AZ FB controller'
   */
  real_T AZFBcontroller_A[145];

  /* Computed Parameter: AZFBcontroller_C
   * Referenced by: '<S1>/AZ FB controller'
   */
  real_T AZFBcontroller_C[13];

  /* Computed Parameter: ELFBcontroller_A
   * Referenced by: '<S1>/EL FB controller'
   */
  real_T ELFBcontroller_A[101];

  /* Computed Parameter: ELFBcontroller_C
   * Referenced by: '<S1>/EL FB controller'
   */
  real_T ELFBcontroller_C[11];

  /* Computed Parameter: GIRFBcontroller_A
   * Referenced by: '<S1>/GIR FB controller'
   */
  real_T GIRFBcontroller_A[37];

  /* Computed Parameter: GIRFBcontroller_C
   * Referenced by: '<S1>/GIR FB controller'
   */
  real_T GIRFBcontroller_C[7];
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
};

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
 * hilite_system('ims_Build5pt1g/Mount_Control')    - opens subsystem ims_Build5pt1g/Mount_Control
 * hilite_system('ims_Build5pt1g/Mount_Control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1g'
 * '<S1>'   : 'ims_Build5pt1g/Mount_Control'
 */
#endif                                 /* RTW_HEADER_Mount_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
