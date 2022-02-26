use simulink_binder::import;

import! {Mount_Drv_PDR2021,
r##"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
/*
 * File: Mount_Drv_PDR2021.h
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021'.
 *
 * Model version                  : 1.901
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 24 14:59:10 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Mount_Drv_PDR2021_h_
#define RTW_HEADER_Mount_Drv_PDR2021_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Mount_Drv_PDR2021_COMMON_INCLUDES_
# define Mount_Drv_PDR2021_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Mount_Drv_PDR2021_COMMON_INCLUDES_ */

#include "Mount_Drv_PDR2021_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sum;                          /* '<S5>/Sum' */
  real_T Divide;                       /* '<S16>/Divide' */
  real_T Sum_o;                        /* '<S4>/Sum' */
  real_T Sum_h;                        /* '<S12>/Sum' */
  real_T Sum_n;                        /* '<S11>/Sum' */
  real_T Sum_oy;                       /* '<S2>/Sum' */
  real_T Sum_e;                        /* '<S9>/Sum' */
  real_T Sum_a;                        /* '<S10>/Sum' */
} B_Mount_Drv_PDR2021_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE[14];                /* '<S3>/UD' */
  real_T AZ_delay_DSTATE[4];           /* '<S1>/AZ_delay' */
  real_T AZ_TFd_states;                /* '<S1>/AZ_TFd' */
  real_T EL_delay_DSTATE[4];           /* '<S1>/EL_delay' */
  real_T EL_TFd_states;                /* '<S1>/EL_TFd' */
  real_T GIR_delay_DSTATE[4];          /* '<S1>/GIR_delay' */
  real_T GIR_TFd_states;               /* '<S1>/GIR_TFd' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S5>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S4>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S2>/Discrete-Time Integrator' */
  uint32_T CircBufIdx;                 /* '<S1>/AZ_delay' */
  uint32_T CircBufIdx_k;               /* '<S1>/EL_delay' */
  uint32_T CircBufIdx_m;               /* '<S1>/GIR_delay' */
} DW_Mount_Drv_PDR2021_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: ParasiticModelStruc.oEmf.Amp
   * Referenced by: '<S30>/EMF Distortion'
   */
  real_T EMFDistortion_tableData[361];

  /* Pooled Parameter (Expression: ParasiticModelStruc.Pos)
   * Referenced by:
   *   '<S30>/Cogging'
   *   '<S30>/EMF Distortion'
   *   '<S31>/Cogging'
   *   '<S31>/EMF Distortion'
   */
  real_T pooled8[361];

  /* Expression: ParasiticModelStruc.oCog.Amp
   * Referenced by: '<S30>/Cogging'
   */
  real_T Cogging_tableData[361];

  /* Expression: ParasiticModelStruc.oEmf.Amp
   * Referenced by: '<S31>/EMF Distortion'
   */
  real_T EMFDistortion_tableData_h[361];

  /* Expression: ParasiticModelStruc.oCog.Amp
   * Referenced by: '<S31>/Cogging'
   */
  real_T Cogging_tableData_h[361];
} ConstP_Mount_Drv_PDR2021_T;

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

/* Block signals (default storage) */
extern B_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_B;

/* Block states (default storage) */
extern DW_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_Y;

/* Constant parameters (default storage) */
extern const ConstP_Mount_Drv_PDR2021_T Mount_Drv_PDR2021_ConstP;

/* Model entry point functions */
extern void Mount_Drv_PDR2021_initialize(void);
extern void Mount_Drv_PDR2021_step(void);
extern void Mount_Drv_PDR2021_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Mount_Drv_PDR2021_T *const Mount_Drv_PDR2021_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/To Workspace' : Unused code path elimination
 * Block '<S4>/To Workspace1' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/To Workspace' : Unused code path elimination
 * Block '<S5>/To Workspace1' : Unused code path elimination
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
 * hilite_system('ims_Build5pt1e/Mount_Drv_PDR2021')    - opens subsystem ims_Build5pt1e/Mount_Drv_PDR2021
 * hilite_system('ims_Build5pt1e/Mount_Drv_PDR2021/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ims_Build5pt1e'
 * '<S1>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021'
 * '<S2>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/AZ DT Lugre Fr model'
 * '<S3>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/Discrete Derivative'
 * '<S4>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/EL DT Lugre Fr model'
 * '<S5>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/GIR DT Lugre Fr model'
 * '<S6>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model'
 * '<S7>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model '
 * '<S8>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/AZ DT Lugre Fr model/g(v)'
 * '<S9>'   : 'ims_Build5pt1e/Mount_Drv_PDR2021/AZ DT Lugre Fr model/v2z'
 * '<S10>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/AZ DT Lugre Fr model/g(v)/gs'
 * '<S11>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/EL DT Lugre Fr model/g(v)'
 * '<S12>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/EL DT Lugre Fr model/v2z'
 * '<S13>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/EL DT Lugre Fr model/g(v)/gs'
 * '<S14>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/GIR DT Lugre Fr model/g(v)'
 * '<S15>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/GIR DT Lugre Fr model/v2z'
 * '<S16>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/GIR DT Lugre Fr model/g(v)/gs'
 * '<S17>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction'
 * '<S18>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Alt'
 * '<S19>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Az'
 * '<S20>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Gir'
 * '<S21>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Alt/g(v)'
 * '<S22>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Alt/v2z'
 * '<S23>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Alt/g(v)/gs'
 * '<S24>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Az/g(v)'
 * '<S25>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Az/v2z'
 * '<S26>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Az/g(v)/gs'
 * '<S27>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Gir/g(v)'
 * '<S28>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Gir/v2z'
 * '<S29>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/MTM CT LUGRE Fr model/Friction/Friction Gir/g(v)/gs'
 * '<S30>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /AZ_Parasitic_Torque'
 * '<S31>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /EL_Parasitic_Torque'
 * '<S32>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /GIR_Parasitic_Torque'
 * '<S33>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem'
 * '<S34>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques'
 * '<S35>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic AZ'
 * '<S36>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic EL'
 * '<S37>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR'
 * '<S38>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR/Cogging'
 * '<S39>'  : 'ims_Build5pt1e/Mount_Drv_PDR2021/Parasitic torques model /Subsystem/Parasitic Torques/Parasitic GIR/Emf'
 */
#endif                                 /* RTW_HEADER_Mount_Drv_PDR2021_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
"##}
