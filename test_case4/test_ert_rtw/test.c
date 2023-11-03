/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: test.c
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov  1 16:01:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test.h"
#include "rtwtypes.h"
#include "test_private.h"
#include <math.h>

/* Block states (default storage) */
DW_test_T test_DW;

/* Real-time model */
static RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(test_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_M->Timing.TaskCounters.TID[1])++;
  if ((test_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [2.0s, 0.0s] */
    test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void test_step0(void)                  /* Sample time: [0.1s, 0.0s] */
{
  boolean_T b_value;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<Root>/Digital Input' */
  if (test_DW.obj.SampleTime != test_P.DigitalInput_SampleTime) {
    test_DW.obj.SampleTime = test_P.DigitalInput_SampleTime;
  }

  b_value = readDigitalPin(3);

  /* MATLABSystem: '<Root>/Digital Output1' incorporates:
   *  Logic: '<Root>/NOT'
   *  MATLABSystem: '<Root>/Digital Input'
   */
  writeDigitalPin(12, (uint8_T)!b_value);
}

/* Model step function for TID1 */
void test_step1(void)                  /* Sample time: [2.0s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  uint8_T tmp;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (test_DW.clockTickCounter < test_P.PulseGenerator_Duty) &&
    (test_DW.clockTickCounter >= 0L) ? test_P.PulseGenerator_Amp : 0.0;
  if (test_DW.clockTickCounter >= test_P.PulseGenerator_Period - 1.0) {
    test_DW.clockTickCounter = 0L;
  } else {
    test_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<Root>/Digital Output' */
  rtb_PulseGenerator = rt_roundd_snf(rtb_PulseGenerator);
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      tmp = (uint8_T)rtb_PulseGenerator;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */
}

/* Model initialize function */
void test_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/Digital Input' */
  test_DW.obj.matlabCodegenIsDeleted = false;
  test_DW.obj.SampleTime = test_P.DigitalInput_SampleTime;
  test_DW.obj.isInitialized = 1L;
  digitalIOSetup(3, 0);
  test_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output1' */
  test_DW.obj_h.matlabCodegenIsDeleted = false;
  test_DW.obj_h.isInitialized = 1L;
  digitalIOSetup(12, 1);
  test_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  test_DW.obj_p.matlabCodegenIsDeleted = false;
  test_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(13, 1);
  test_DW.obj_p.isSetupComplete = true;
}

/* Model terminate function */
void test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Input' */
  if (!test_DW.obj.matlabCodegenIsDeleted) {
    test_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Input' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!test_DW.obj_h.matlabCodegenIsDeleted) {
    test_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!test_DW.obj_p.matlabCodegenIsDeleted) {
    test_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
