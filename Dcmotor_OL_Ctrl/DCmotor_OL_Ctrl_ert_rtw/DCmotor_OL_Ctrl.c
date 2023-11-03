/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.c
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
#include "rtwtypes.h"
#include "DCmotor_OL_Ctrl_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "DCmotor_OL_Ctrl_types.h"

/* Block signals (default storage) */
B_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_B;

/* Block states (default storage) */
DW_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_DW;

/* Real-time model */
static RT_MODEL_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_M_;
RT_MODEL_DCmotor_OL_Ctrl_T *const DCmotor_OL_Ctrl_M = &DCmotor_OL_Ctrl_M_;
static void rate_monotonic_scheduler(void);

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt' */
void MW_ISR_2(void)
{
  /* Call the system: <Root>/Function-Call Subsystem2 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(DCmotor_OL_Ctrl_DW.FunctionCallSubsystem2_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem2' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 =
        DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    DCmotor_OL_Ctrl_M->Timing.clockTick2 =
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick2
      [DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2];
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* Logic: '<S1>/XOR' incorporates:
     *  Constant: '<S1>/Constant'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = (DCmotor_OL_Ctrl_P.Constant_Value !=
      0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE;
    DCmotor_OL_Ctrl_DW.FunctionCallSubsystem2_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void DCmotor_OL_Ctrl_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(DCmotor_OL_Ctrl_M, 1));
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
  (DCmotor_OL_Ctrl_M->Timing.TaskCounters.TID[1])++;
  if ((DCmotor_OL_Ctrl_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    DCmotor_OL_Ctrl_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<Root>/If Action Subsystem6'
 *    '<Root>/If Action Subsystem7'
 *    '<S4>/If Action Subsystem6'
 *    '<S4>/If Action Subsystem7'
 *    '<S4>/If Action Subsystem8'
 *    '<S4>/If Action Subsystem9'
 *    '<S4>/If Action Subsystem10'
 *    '<S4>/If Action Subsystem11'
 */
void DCmotor__IfActionSubsystem6(real_T *rty_Out1,
  P_IfActionSubsystem6_DCmotor__T *localP)
{
  /* SignalConversion generated from: '<S2>/Out1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Model step function for TID0 */
void DCmotor_OL_Ctrl_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DCmotor_OL_Ctrl_M->Timing.taskTime0 =
    ((time_T)(++DCmotor_OL_Ctrl_M->Timing.clockTick0)) *
    DCmotor_OL_Ctrl_M->Timing.stepSize0;
  switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2) {
   case 0:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 = 1;
    break;

   case 1:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 = 0;
    break;

   default:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 =
      !DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2;
    break;
  }

  DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick2
    [DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2] =
    DCmotor_OL_Ctrl_M->Timing.clockTick0;
  DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2 =
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2;
  DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
}

/* Model step function for TID1 */
void DCmotor_OL_Ctrl_step1(void)       /* Sample time: [0.1s, 0.0s] */
{
  codertarget_arduinobase_inter_T *obj;
  real_T Merge1_h;
  uint32_T duration;

  /* Reset subsysRan breadcrumbs */
  srClearBC(DCmotor_OL_Ctrl_DW.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

  /* MATLABSystem: '<S4>/Ultrasonic Sensor2' */
  if (DCmotor_OL_Ctrl_DW.obj_o.TunablePropsChanged) {
    DCmotor_OL_Ctrl_DW.obj_o.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* Gain: '<S4>/Gain3' incorporates:
   *  MATLABSystem: '<S4>/Ultrasonic Sensor2'
   */
  DCmotor_OL_Ctrl_B.Gain3 = (real_T)duration * 0.000343 / 2.0 *
    DCmotor_OL_Ctrl_P.Gain3_Gain;

  /* If: '<S4>/If1' */
  if (DCmotor_OL_Ctrl_B.Gain3 > 50.0) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem6_j);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem6' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 50.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              40.0)) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem7_n);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem7' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 40.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              30.0)) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem8' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 30.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              20.0)) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem9);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem9' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 20.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              10.0)) {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem10' */
  } else {
    /* Outputs for IfAction SubSystem: '<S4>/If Action Subsystem11' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem11);

    /* End of Outputs for SubSystem: '<S4>/If Action Subsystem11' */
  }

  /* End of If: '<S4>/If1' */

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant'
   */
  DCmotor_OL_Ctrl_B.Divide = DCmotor_OL_Ctrl_B.Merge1 *
    DCmotor_OL_Ctrl_P.Constant_Value_d;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  Merge1_h = floor(DCmotor_OL_Ctrl_B.Divide);
  if (rtIsNaN(Merge1_h) || rtIsInf(Merge1_h)) {
    Merge1_h = 0.0;
  } else {
    Merge1_h = fmod(Merge1_h, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  DCmotor_OL_Ctrl_B.DataTypeConversion1 = (uint8_T)(Merge1_h < 0.0 ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-Merge1_h : (int16_T)(uint8_T)Merge1_h);

  /* MATLABSystem: '<Root>/PWM' */
  obj = &DCmotor_OL_Ctrl_DW.obj_m;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)DCmotor_OL_Ctrl_B.DataTypeConversion1);

  /* If: '<Root>/If1' */
  if ((DCmotor_OL_Ctrl_B.Merge1 != 0.0) && (DCmotor_OL_Ctrl_B.Merge1 != 0.6)) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&Merge1_h, &DCmotor_OL_Ctrl_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem6' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    DCmotor__IfActionSubsystem6(&Merge1_h, &DCmotor_OL_Ctrl_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem7' */
  }

  /* End of If: '<Root>/If1' */

  /* MATLABSystem: '<Root>/PWM1' */
  obj = &DCmotor_OL_Ctrl_DW.obj_g;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  Merge1_h = floor(Merge1_h);
  if (rtIsNaN(Merge1_h) || rtIsInf(Merge1_h)) {
    Merge1_h = 0.0;
  } else {
    Merge1_h = fmod(Merge1_h, 256.0);
  }

  /* MATLABSystem: '<Root>/PWM1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)(Merge1_h < 0.0 ? (int16_T)(uint8_T)-(int8_T)
    (uint8_T)-Merge1_h : (int16_T)(uint8_T)Merge1_h));

  /* RateTransition: '<Root>/Rate Transition1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  DCmotor_OL_Ctrl_B.RateTransition1 = DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE;

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)DCmotor_OL_Ctrl_B.RateTransition1);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  DCmotor_OL_Ctrl_M->Timing.clockTick1++;
}

/* Model initialize function */
void DCmotor_OL_Ctrl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(DCmotor_OL_Ctrl_M, -1);
  DCmotor_OL_Ctrl_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  DCmotor_OL_Ctrl_M->Sizes.checksums[0] = (1943195155U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[1] = (2684608102U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[2] = (3947471434U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[3] = (610959849U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[14];
    DCmotor_OL_Ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[3] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem10.IfActionSubsystem6_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem11.IfActionSubsystem6_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem6_j.IfActionSubsystem6_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem7_n.IfActionSubsystem6_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem8.IfActionSubsystem6_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem9.IfActionSubsystem6_SubsysRanBC;
    systemRan[13] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCmotor_OL_Ctrl_M->extModeInfo,
      &DCmotor_OL_Ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCmotor_OL_Ctrl_M->extModeInfo,
                        DCmotor_OL_Ctrl_M->Sizes.checksums);
    rteiSetTPtr(DCmotor_OL_Ctrl_M->extModeInfo, rtmGetTPtr(DCmotor_OL_Ctrl_M));
  }

  {
    codertarget_arduinobase_inter_T *obj;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2 = 0;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem2'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem2' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2) {
     case 0:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 1;
      break;

     case 1:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0;
      break;

     default:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 =
        DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2;
      break;
    }

    DCmotor_OL_Ctrl_M->Timing.clockTick2 =
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick2
      [DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2];
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0xFF;

    /* SystemInitialize for Outport: '<S1>/Out1' incorporates:
     *  Logic: '<S1>/XOR'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = DCmotor_OL_Ctrl_P.Out1_Y0;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Start for MATLABSystem: '<S4>/Ultrasonic Sensor2' */
    DCmotor_OL_Ctrl_DW.obj_o.isInitialized = 1L;
    MW_UltrasonicSetup(50, 51);
    DCmotor_OL_Ctrl_DW.obj_o.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/PWM' */
    DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &DCmotor_OL_Ctrl_DW.obj_m;
    DCmotor_OL_Ctrl_DW.obj_m.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    DCmotor_OL_Ctrl_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted = false;
    obj = &DCmotor_OL_Ctrl_DW.obj_g;
    DCmotor_OL_Ctrl_DW.obj_g.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    DCmotor_OL_Ctrl_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj.isInitialized = 1L;
    digitalIOSetup(13, 1);
    DCmotor_OL_Ctrl_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void DCmotor_OL_Ctrl_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &DCmotor_OL_Ctrl_DW.obj_m;
  if (!DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((DCmotor_OL_Ctrl_DW.obj_m.isInitialized == 1L) &&
        DCmotor_OL_Ctrl_DW.obj_m.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj = &DCmotor_OL_Ctrl_DW.obj_g;
  if (!DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((DCmotor_OL_Ctrl_DW.obj_g.isInitialized == 1L) &&
        DCmotor_OL_Ctrl_DW.obj_g.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(DCmotor_OL_Ctrl_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
