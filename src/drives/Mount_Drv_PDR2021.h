/*
 * File: Mount_Drv_PDR2021.h
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021'.
 *
 * Model version                  : 1.1193
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 20 15:30:05 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Mount_Drv_PDR2021_h_
#define RTW_HEADER_Mount_Drv_PDR2021_h_
#include <string.h>
#include <stddef.h>
#ifndef Mount_Drv_PDR2021_COMMON_INCLUDES_
# define Mount_Drv_PDR2021_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Drv_PDR2021_COMMON_INCLUDES_ */

#include "Mount_Drv_PDR2021_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T AZ_delay_DSTATE[4];           /* '<S1>/AZ_delay' */
  real_T AZ_TFd_states;                /* '<S1>/AZ_TFd' */
  real_T EL_delay_DSTATE[4];           /* '<S1>/EL_delay' */
  real_T EL_TFd_states;                /* '<S1>/EL_TFd' */
  real_T GIR_delay_DSTATE[4];          /* '<S1>/GIR_delay' */
  real_T GIR_TFd_states;               /* '<S1>/GIR_TFd' */
  uint32_T CircBufIdx;                 /* '<S1>/AZ_delay' */
  uint32_T CircBufIdx_p;               /* '<S1>/EL_delay' */
  uint32_T CircBufIdx_n;               /* '<S1>/GIR_delay' */
} DW_Mount_Drv_PDR2021_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Mount_cmd[3];                 /* '<Root>/Mount_cmd' */
  real_T Mount_pos[14];                /* '<Root>/Mount_pos' */
} ExtU_Mount_Drv_PDR2021_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Mount_T[20];                  /* '<Root>/Mount_T' */
} ExtY_Mount_Drv_PDR2021_T;

/* Real-time Model Data Structure */
struct tag_RTM_Mount_Drv_PDR2021_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_Y;

/* Model entry point functions */
extern void Mount_Drv_PDR2021_initialize(void);
extern void Mount_Drv_PDR2021_step(void);
extern void Mount_Drv_PDR2021_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mount_Drv_PDR2021_T *const Mount_Drv_PDR2021_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S2>/Sum' : Unused code path elimination
 * Block '<S9>/Divide' : Unused code path elimination
 * Block '<S9>/Gain' : Unused code path elimination
 * Block '<S9>/Math Function' : Unused code path elimination
 * Block '<S9>/Math Function1' : Unused code path elimination
 * Block '<S9>/Sum' : Unused code path elimination
 * Block '<S9>/Unary Minus' : Unused code path elimination
 * Block '<S9>/gc' : Unused code path elimination
 * Block '<S9>/gs' : Unused code path elimination
 * Block '<S2>/sigma_0' : Unused code path elimination
 * Block '<S2>/sigma_1' : Unused code path elimination
 * Block '<S2>/sigma_v' : Unused code path elimination
 * Block '<S8>/Abs' : Unused code path elimination
 * Block '<S8>/Divide' : Unused code path elimination
 * Block '<S8>/Sum' : Unused code path elimination
 * Block '<S1>/AZ enc avg + m2rad' : Unused code path elimination
 * Block '<S1>/AZ vel avg => rad//s' : Unused code path elimination
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Diff' : Unused code path elimination
 * Block '<S3>/TSamp' : Unused code path elimination
 * Block '<S3>/UD' : Unused code path elimination
 * Block '<S4>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S4>/Sum' : Unused code path elimination
 * Block '<S4>/To Workspace' : Unused code path elimination
 * Block '<S4>/To Workspace1' : Unused code path elimination
 * Block '<S10>/Sum' : Unused code path elimination
 * Block '<S10>/gc' : Unused code path elimination
 * Block '<S12>/Divide' : Unused code path elimination
 * Block '<S12>/Gain' : Unused code path elimination
 * Block '<S12>/Math Function' : Unused code path elimination
 * Block '<S12>/Math Function1' : Unused code path elimination
 * Block '<S12>/Unary Minus' : Unused code path elimination
 * Block '<S12>/gs' : Unused code path elimination
 * Block '<S4>/sigma_0' : Unused code path elimination
 * Block '<S4>/sigma_1' : Unused code path elimination
 * Block '<S4>/sigma_v' : Unused code path elimination
 * Block '<S11>/Abs' : Unused code path elimination
 * Block '<S11>/Divide' : Unused code path elimination
 * Block '<S11>/Sum' : Unused code path elimination
 * Block '<S1>/EL enc avg + m2rad' : Unused code path elimination
 * Block '<S1>/EL vel avg => rad//s' : Unused code path elimination
 * Block '<S5>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S5>/Gain' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Sum' : Unused code path elimination
 * Block '<S5>/To Workspace' : Unused code path elimination
 * Block '<S5>/To Workspace1' : Unused code path elimination
 * Block '<S13>/Sum' : Unused code path elimination
 * Block '<S13>/gc' : Unused code path elimination
 * Block '<S15>/Divide' : Unused code path elimination
 * Block '<S15>/Gain' : Unused code path elimination
 * Block '<S15>/Math Function' : Unused code path elimination
 * Block '<S15>/Math Function1' : Unused code path elimination
 * Block '<S15>/Unary Minus' : Unused code path elimination
 * Block '<S15>/gs' : Unused code path elimination
 * Block '<S5>/sigma_0' : Unused code path elimination
 * Block '<S5>/sigma_1' : Unused code path elimination
 * Block '<S5>/sigma_v' : Unused code path elimination
 * Block '<S14>/Abs' : Unused code path elimination
 * Block '<S14>/Divide' : Unused code path elimination
 * Block '<S14>/Sum' : Unused code path elimination
 * Block '<S1>/GIR enc avg + m2rad' : Unused code path elimination
 * Block '<S1>/GIR vel avg =>r ad//s' : Unused code path elimination
 * Block '<S16>/Cogging' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/Divide' : Unused code path elimination
 * Block '<S16>/EMF Distortion' : Unused code path elimination
 * Block '<S16>/Gain' : Unused code path elimination
 * Block '<S16>/Gain1' : Unused code path elimination
 * Block '<S16>/Gain2' : Unused code path elimination
 * Block '<S16>/Mod' : Unused code path elimination
 * Block '<S16>/Mod1' : Unused code path elimination
 * Block '<S16>/Radius' : Unused code path elimination
 * Block '<S16>/Sum1' : Unused code path elimination
 * Block '<S16>/Sum2' : Unused code path elimination
 * Block '<S17>/Cogging' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S17>/Divide' : Unused code path elimination
 * Block '<S17>/EMF Distortion' : Unused code path elimination
 * Block '<S17>/Gain' : Unused code path elimination
 * Block '<S17>/Gain1' : Unused code path elimination
 * Block '<S17>/Gain2' : Unused code path elimination
 * Block '<S17>/Mod' : Unused code path elimination
 * Block '<S17>/Mod1' : Unused code path elimination
 * Block '<S17>/Radius' : Unused code path elimination
 * Block '<S17>/Sum1' : Unused code path elimination
 * Block '<S17>/Sum2' : Unused code path elimination
 * Block '<S18>/CogAmp' : Unused code path elimination
 * Block '<S18>/CogSpatFreq' : Unused code path elimination
 * Block '<S18>/Product' : Unused code path elimination
 * Block '<S18>/Product1' : Unused code path elimination
 * Block '<S18>/Product2' : Unused code path elimination
 * Block '<S18>/Product3' : Unused code path elimination
 * Block '<S18>/Product4' : Unused code path elimination
 * Block '<S18>/RippleAmpFactor' : Unused code path elimination
 * Block '<S18>/RippleSpatFreq' : Unused code path elimination
 * Block '<S18>/Sign' : Unused code path elimination
 * Block '<S18>/Sum' : Unused code path elimination
 * Block '<S18>/Sum1' : Unused code path elimination
 * Block '<S18>/ToPretension' : Unused code path elimination
 * Block '<S18>/Trigonometric Function' : Unused code path elimination
 * Block '<S18>/Trigonometric Function1' : Unused code path elimination
 */

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
 * hilite_system('ims_Build5pt1f/Mount_Drv_PDR2021')    - opens subsystem ims_Build5pt1f/Mount_Drv_PDR2021
 * hilite_system('ims_Build5pt1f/Mount_Drv_PDR2021/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1f'
 * '<S1>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021'
 * '<S2>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/AZ DT Lugre Fr model'
 * '<S3>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/Discrete Derivative'
 * '<S4>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/EL DT Lugre Fr model'
 * '<S5>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/GIR DT Lugre Fr model'
 * '<S6>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model '
 * '<S7>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/AZ DT Lugre Fr model/g(v)'
 * '<S8>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/AZ DT Lugre Fr model/v2z'
 * '<S9>'   : 'ims_Build5pt1f/Mount_Drv_PDR2021/AZ DT Lugre Fr model/g(v)/gs'
 * '<S10>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/EL DT Lugre Fr model/g(v)'
 * '<S11>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/EL DT Lugre Fr model/v2z'
 * '<S12>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/EL DT Lugre Fr model/g(v)/gs'
 * '<S13>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/GIR DT Lugre Fr model/g(v)'
 * '<S14>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/GIR DT Lugre Fr model/v2z'
 * '<S15>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/GIR DT Lugre Fr model/g(v)/gs'
 * '<S16>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /AZ_Parasitic_Torque'
 * '<S17>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /EL_Parasitic_Torque'
 * '<S18>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /GIR_Parasitic_Torque'
 * '<S19>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem'
 * '<S20>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques'
 * '<S21>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic AZ'
 * '<S22>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic EL'
 * '<S23>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR'
 * '<S24>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR/Cogging'
 * '<S25>'  : 'ims_Build5pt1f/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR/Emf'
 */
#endif                                 /* RTW_HEADER_Mount_Drv_PDR2021_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
