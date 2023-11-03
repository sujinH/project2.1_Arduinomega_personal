/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl_private.h
 *
 * Code generated for Simulink model 'DCmotor_OL_Ctrl'.
 *
 * Model version                  : 3.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Nov  3 10:51:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DCmotor_OL_Ctrl_private_h_
#define RTW_HEADER_DCmotor_OL_Ctrl_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "DCmotor_OL_Ctrl.h"
#include "DCmotor_OL_Ctrl_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void MW_ISR_2(void);
extern void DCmotor__IfActionSubsystem6(real_T *rty_Out1,
  P_IfActionSubsystem6_DCmotor__T *localP);

#endif                               /* RTW_HEADER_DCmotor_OL_Ctrl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
