/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl_data.c
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

#include "DCmotor_OL_Ctrl.h"

/* Block parameters (default storage) */
P_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_P = {
  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S4>/Gain3'
   */
  100.0,

  /* Expression: 255
   * Referenced by: '<Root>/Constant'
   */
  255.0,

  /* Expression: [0]
   * Referenced by: '<Root>/Merge1'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S1>/Out1'
   */
  false,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S1>/Unit Delay'
   */
  false,

  /* Start of '<S4>/If Action Subsystem11' */
  {
    /* Expression: 0
     * Referenced by: '<S6>/Constant'
     */
    0.0
  }
  ,

  /* End of '<S4>/If Action Subsystem11' */

  /* Start of '<S4>/If Action Subsystem10' */
  {
    /* Expression: 0.2
     * Referenced by: '<S5>/Constant'
     */
    0.2
  }
  ,

  /* End of '<S4>/If Action Subsystem10' */

  /* Start of '<S4>/If Action Subsystem9' */
  {
    /* Expression: 0.3
     * Referenced by: '<S10>/Constant'
     */
    0.3
  }
  ,

  /* End of '<S4>/If Action Subsystem9' */

  /* Start of '<S4>/If Action Subsystem8' */
  {
    /* Expression: 0.4
     * Referenced by: '<S9>/Constant'
     */
    0.4
  }
  ,

  /* End of '<S4>/If Action Subsystem8' */

  /* Start of '<S4>/If Action Subsystem7' */
  {
    /* Expression: 0.5
     * Referenced by: '<S8>/Constant'
     */
    0.5
  }
  ,

  /* End of '<S4>/If Action Subsystem7' */

  /* Start of '<S4>/If Action Subsystem6' */
  {
    /* Expression: 0.6
     * Referenced by: '<S7>/Constant'
     */
    0.6
  }
  ,

  /* End of '<S4>/If Action Subsystem6' */

  /* Start of '<Root>/If Action Subsystem7' */
  {
    /* Expression: 0
     * Referenced by: '<S3>/Constant'
     */
    0.0
  }
  ,

  /* End of '<Root>/If Action Subsystem7' */

  /* Start of '<Root>/If Action Subsystem6' */
  {
    /* Expression: 1
     * Referenced by: '<S2>/Constant'
     */
    1.0
  }
  /* End of '<Root>/If Action Subsystem6' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
