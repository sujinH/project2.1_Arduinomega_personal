/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Ultrasonic.c
 *
 * Code generated for Simulink model 'Ultrasonic'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov  1 16:50:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ultrasonic.h"
#include "rtwtypes.h"
#include "Ultrasonic_private.h"

/* Block signals (default storage) */
B_Ultrasonic_T Ultrasonic_B;

/* Block states (default storage) */
DW_Ultrasonic_T Ultrasonic_DW;

/* Real-time model */
static RT_MODEL_Ultrasonic_T Ultrasonic_M_;
RT_MODEL_Ultrasonic_T *const Ultrasonic_M = &Ultrasonic_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Ultrasonic_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Ultrasonic_M, 1));
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
  (Ultrasonic_M->Timing.TaskCounters.TID[1])++;
  if ((Ultrasonic_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Ultrasonic_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Ultrasonic_step0(void)            /* Sample time: [0.01s, 0.0s] */
{
  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Ultrasonic_M->Timing.taskTime0 =
    ((time_T)(++Ultrasonic_M->Timing.clockTick0)) *
    Ultrasonic_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Ultrasonic_step1(void)            /* Sample time: [0.1s, 0.0s] */
{
  uint32_T duration;

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  if (Ultrasonic_DW.obj.TunablePropsChanged) {
    Ultrasonic_DW.obj.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor' */
  Ultrasonic_B.UltrasonicSensor = (real_T)duration * 0.000343 / 2.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Ultrasonic_M->Timing.clockTick1++;
}

/* Model initialize function */
void Ultrasonic_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Ultrasonic_M, -1);
  Ultrasonic_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Ultrasonic_M->Sizes.checksums[0] = (1674266415U);
  Ultrasonic_M->Sizes.checksums[1] = (2674035640U);
  Ultrasonic_M->Sizes.checksums[2] = (3955241535U);
  Ultrasonic_M->Sizes.checksums[3] = (1187621296U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Ultrasonic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Ultrasonic_M->extModeInfo,
      &Ultrasonic_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Ultrasonic_M->extModeInfo, Ultrasonic_M->Sizes.checksums);
    rteiSetTPtr(Ultrasonic_M->extModeInfo, rtmGetTPtr(Ultrasonic_M));
  }

  /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor' */
  Ultrasonic_DW.obj.isInitialized = 1L;
  MW_UltrasonicSetup(50, 51);
  Ultrasonic_DW.obj.TunablePropsChanged = false;
}

/* Model terminate function */
void Ultrasonic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
