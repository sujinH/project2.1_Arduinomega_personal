/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl_data.c
 *
 * Code generated for Simulink model 'DCmotor_OL_Ctrl'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov  2 11:52:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCmotor_OL_Ctrl.h"

/* Block parameters (default storage) */
P_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_P = {
  /* Expression: -1
   * Referenced by: '<Root>/Analog Input'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S1>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  32768U,

  /* Computed Parameter: Out1_Y0_a
   * Referenced by: '<S3>/Out1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition_a
   * Referenced by: '<S3>/Unit Delay'
   */
  false,

  /* Computed Parameter: Out1_Y0_c
   * Referenced by: '<S2>/Out1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition_a4
   * Referenced by: '<S2>/Unit Delay'
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
