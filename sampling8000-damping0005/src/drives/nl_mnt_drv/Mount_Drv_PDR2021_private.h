/*
 * File: Mount_Drv_PDR2021_private.h
 *
 * Code generated for Simulink model 'Mount_Drv_PDR2021'.
 *
 * Model version                  : 5.59
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Aug 31 13:56:46 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Mount_Drv_PDR2021_private_h_
#define RTW_HEADER_Mount_Drv_PDR2021_private_h_
#include "rtwtypes.h"
#include "Mount_Drv_PDR2021.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Mount_Drv_PDR2021_gv(real_T rtu_Enable, real_T *rty_g,
  B_gv_Mount_Drv_PDR2021_T *localB, const struct_1utrxinkom0IYpuKJbdriH
  *rtp_frParStruct);
extern void Mount_Drv_PDR2021_v2z(real_T rtu_Enable, real_T rtu_v, real_T rtu_gv,
  real_T rtu_z, real_T *rty_dz);

#endif                             /* RTW_HEADER_Mount_Drv_PDR2021_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
