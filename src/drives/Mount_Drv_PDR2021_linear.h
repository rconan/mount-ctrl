/*
 * File: Mount_Drv_PDR2021_linear.h
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

#ifndef RTW_HEADER_Mount_Drv_PDR2021_linear_h_
#define RTW_HEADER_Mount_Drv_PDR2021_linear_h_
#include <string.h>
#include <stddef.h>
#ifndef Mount_Drv_PDR2021_linear_COMMON_INCLUDES_
#define Mount_Drv_PDR2021_linear_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                           /* Mount_Drv_PDR2021_linear_COMMON_INCLUDES_ */

#include "Mount_Drv_PDR2021_linear_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AZ_delay_DSTATE[32];          /* '<S1>/AZ_delay' */
  real_T AZ_TFd_states;                /* '<S1>/AZ_TFd' */
  real_T EL_delay_DSTATE[32];          /* '<S1>/EL_delay' */
  real_T EL_TFd_states;                /* '<S1>/EL_TFd' */
  real_T GIR_delay_DSTATE[32];         /* '<S1>/GIR_delay' */
  real_T GIR_TFd_states;               /* '<S1>/GIR_TFd' */
  uint32_T CircBufIdx;                 /* '<S1>/AZ_delay' */
  uint32_T CircBufIdx_g;               /* '<S1>/EL_delay' */
  uint32_T CircBufIdx_l;               /* '<S1>/GIR_delay' */
} DW_Mount_Drv_PDR2021_linear_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
  real_T Mount_pos;                    /* '<Root>/Mount_pos' */
} ExtU_Mount_Drv_PDR2021_linear_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_T[20];                  /* '<Root>/Mount_T' */
} ExtY_Mount_Drv_PDR2021_linear_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Drv_PDR2021_linear_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mount_Drv_PDR2021_linear_T Mount_Drv_PDR2021_linear_Y;

/* Model entry point functions */
extern void Mount_Drv_PDR2021_linear_initialize(void);
extern void Mount_Drv_PDR2021_linear_step(void);
extern void Mount_Drv_PDR2021_linear_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mount_Drv_PDR2021_linear_T *const Mount_Drv_PDR2021_linear_M;

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
 * hilite_system('ims_Build5pt3b_PTTasm/Mount_Drv_PDR2021_linear')    - opens subsystem ims_Build5pt3b_PTTasm/Mount_Drv_PDR2021_linear
 * hilite_system('ims_Build5pt3b_PTTasm/Mount_Drv_PDR2021_linear/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt3b_PTTasm'
 * '<S1>'   : 'ims_Build5pt3b_PTTasm/Mount_Drv_PDR2021_linear'
 */
#endif                              /* RTW_HEADER_Mount_Drv_PDR2021_linear_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
