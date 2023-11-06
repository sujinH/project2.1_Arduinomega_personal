/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.c
 *
 * Code generated for Simulink model 'DCmotor_OL_Ctrl'.
 *
 * Model version                  : 3.98
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Nov  3 14:07:43 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCmotor_OL_Ctrl.h"
#include "rtwtypes.h"
#include "DCmotor_OL_Ctrl_types.h"
#include "DCmotor_OL_Ctrl_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_B;

/* Block states (default storage) */
DW_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_DW;

/* Real-time model */
static RT_MODEL_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_M_;
RT_MODEL_DCmotor_OL_Ctrl_T *const DCmotor_OL_Ctrl_M = &DCmotor_OL_Ctrl_M_;

/* Forward declaration for local functions */
static void DCmotor_OL_C_SystemCore_release(codertarget_arduinobase_int_k_T *obj);
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
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_o = (DCmotor_OL_Ctrl_P.Constant_Value !=
      0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_o;
    DCmotor_OL_Ctrl_DW.FunctionCallSubsystem2_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Callback for Hardware Interrupt Block: '<S4>/External Interrupt1' */
void MW_ISR_3(void)
{
  /* Call the system: <S4>/Function-Call Subsystem1 */
  {
    /* Reset subsysRan breadcrumbs */
    srClearBC(DCmotor_OL_Ctrl_DW.FunctionCallSubsystem1_SubsysRa);

    /* S-Function (arduinoextint_sfcn): '<S4>/External Interrupt1' */

    /* Output and update for function-call system: '<S4>/Function-Call Subsystem1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 =
        DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    DCmotor_OL_Ctrl_M->Timing.clockTick3 =
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick3
      [DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3];
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* Logic: '<S6>/XOR' incorporates:
     *  Constant: '<S6>/Constant'
     *  UnitDelay: '<S6>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = (DCmotor_OL_Ctrl_P.Constant_Value_m !=
      0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE;
    DCmotor_OL_Ctrl_DW.FunctionCallSubsystem1_SubsysRa = 4;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt1' */
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
 *    '<Root>/If Action Subsystem1'
 *    '<Root>/If Action Subsystem2'
 *    '<S5>/If Action Subsystem6'
 *    '<S5>/If Action Subsystem7'
 *    '<S5>/If Action Subsystem8'
 *    '<S5>/If Action Subsystem9'
 *    '<S5>/If Action Subsystem10'
 *    '<S5>/If Action Subsystem11'
 */
void DCmotor__IfActionSubsystem1(real_T *rty_Out1,
  P_IfActionSubsystem1_DCmotor__T *localP)
{
  /* SignalConversion generated from: '<S2>/Out1' incorporates:
   *  Constant: '<S2>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

static void DCmotor_OL_C_SystemCore_release(codertarget_arduinobase_int_k_T *obj)
{
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
    MW_PWM_SetDutyCycle(obj->PWMDriverObj.MW_PWM_HANDLE, -0.0);
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
    MW_PWM_Close(obj->PWMDriverObj.MW_PWM_HANDLE);
  }
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
  switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3 =
      !DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick3
    [DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3] =
    DCmotor_OL_Ctrl_M->Timing.clockTick0;
  DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr3 =
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3;
  DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
}

/* Model step function for TID1 */
void DCmotor_OL_Ctrl_step1(void)       /* Sample time: [0.1s, 0.0s] */
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T Merge2;
  uint32_T duration;
  uint16_T b_varargout_1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(DCmotor_OL_Ctrl_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* RateTransition: '<S4>/Rate Transition2' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  DCmotor_OL_Ctrl_B.RateTransition2 = DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE;

  /* MATLABSystem: '<S5>/Ultrasonic Sensor2' */
  if (DCmotor_OL_Ctrl_DW.obj_l.TunablePropsChanged) {
    DCmotor_OL_Ctrl_DW.obj_l.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* Gain: '<S5>/Gain3' incorporates:
   *  MATLABSystem: '<S5>/Ultrasonic Sensor2'
   */
  DCmotor_OL_Ctrl_B.Gain3 = (real_T)duration * 0.000343 / 2.0 *
    DCmotor_OL_Ctrl_P.Gain3_Gain;

  /* If: '<S5>/If1' */
  if (DCmotor_OL_Ctrl_B.Gain3 > 50.0) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem6' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 50.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              40.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem7' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 40.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              30.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem8);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem8' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 30.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              20.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem9' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem9);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem9' */
  } else if ((DCmotor_OL_Ctrl_B.Gain3 <= 20.0) && (DCmotor_OL_Ctrl_B.Gain3 >
              10.0)) {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem10' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem10);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem10' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/If Action Subsystem11' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&DCmotor_OL_Ctrl_B.Merge1,
      &DCmotor_OL_Ctrl_P.IfActionSubsystem11);

    /* End of Outputs for SubSystem: '<S5>/If Action Subsystem11' */
  }

  /* End of If: '<S5>/If1' */

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (DCmotor_OL_Ctrl_DW.obj.SampleTime !=
      DCmotor_OL_Ctrl_P.AnalogInput1_SampleTime) {
    DCmotor_OL_Ctrl_DW.obj.SampleTime =
      DCmotor_OL_Ctrl_P.AnalogInput1_SampleTime;
  }

  obj = &DCmotor_OL_Ctrl_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (DCmotor_OL_Ctrl_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* Gain: '<Root>/Multiply' incorporates:
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  DCmotor_OL_Ctrl_B.Multiply = (uint32_T)DCmotor_OL_Ctrl_P.Multiply_Gain *
    b_varargout_1;

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  DCmotor_OL_Ctrl_B.Divide2 = DCmotor_OL_Ctrl_B.Merge1 *
    DCmotor_OL_Ctrl_P.Constant4_Value;

  /* Switch: '<Root>/Switch' */
  if (DCmotor_OL_Ctrl_B.RateTransition2) {
    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    Merge2 = floor(DCmotor_OL_Ctrl_B.Divide2);
    if (rtIsNaN(Merge2) || rtIsInf(Merge2)) {
      Merge2 = 0.0;
    } else {
      Merge2 = fmod(Merge2, 256.0);
    }

    /* DataTypeConversion: '<Root>/Data Type Conversion5' */
    DCmotor_OL_Ctrl_B.DataTypeConversion5 = (uint8_T)(Merge2 < 0.0 ? (int16_T)
      (uint8_T)-(int8_T)(uint8_T)-Merge2 : (int16_T)(uint8_T)Merge2);
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
     *  Gain: '<Root>/Multiply'
     */
    DCmotor_OL_Ctrl_B.DataTypeConversion5 = (uint8_T)(DCmotor_OL_Ctrl_B.Multiply
      >> 17);
  }

  /* End of Switch: '<Root>/Switch' */

  /* If: '<Root>/If2' */
  if ((DCmotor_OL_Ctrl_B.Merge1 >= 0.2) && (DCmotor_OL_Ctrl_B.Merge1 < 0.6)) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&Merge2, &DCmotor_OL_Ctrl_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    DCmotor__IfActionSubsystem1(&Merge2, &DCmotor_OL_Ctrl_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem2' */
  }

  /* End of If: '<Root>/If2' */

  /* MATLABSystem: '<Root>/PWM3' incorporates:
   *  Gain: '<Root>/Gain'
   *  Logic: '<Root>/AND'
   */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_g;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      -((real_T)(DCmotor_OL_Ctrl_B.RateTransition2 && (Merge2 !=
    0.0) ? (int16_T)((uint16_T)DCmotor_OL_Ctrl_P.Gain_Gain >> 5) : 0) * 12121.0 /
                        255.0));

  /* MATLABSystem: '<Root>/PWM4' */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_a;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)DCmotor_OL_Ctrl_B.DataTypeConversion5);

  /* RateTransition: '<Root>/Rate Transition1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  DCmotor_OL_Ctrl_B.RateTransition1 = DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_o;

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
  DCmotor_OL_Ctrl_M->Sizes.checksums[0] = (741365241U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[1] = (3520265478U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[2] = (1125493747U);
  DCmotor_OL_Ctrl_M->Sizes.checksums[3] = (2296132499U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    DCmotor_OL_Ctrl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[4] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem2.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[9] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem10.IfActionSubsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem11.IfActionSubsystem1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem6.IfActionSubsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem7.IfActionSubsystem1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem8.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &DCmotor_OL_Ctrl_DW.IfActionSubsystem9.IfActionSubsystem1_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DCmotor_OL_Ctrl_M->extModeInfo,
      &DCmotor_OL_Ctrl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DCmotor_OL_Ctrl_M->extModeInfo,
                        DCmotor_OL_Ctrl_M->Sizes.checksums);
    rteiSetTPtr(DCmotor_OL_Ctrl_M->extModeInfo, rtmGetTPtr(DCmotor_OL_Ctrl_M));
  }

  {
    codertarget_arduinobase_int_k_T *obj_0;
    codertarget_arduinobase_inter_T *obj;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf2 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf2 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr2 = 0;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt1' incorporates:
     *  SubSystem: '<S4>/Function-Call Subsystem1'
     */

    /* System initialize for function-call system: '<S4>/Function-Call Subsystem1' */

    /* Asynchronous task (with no priority assigned)
     * reads absolute time */
    switch (DCmotor_OL_Ctrl_M->Timing.rtmDbBufWriteBuf3) {
     case 0:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 1;
      break;

     case 1:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 0;
      break;

     default:
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 =
        DCmotor_OL_Ctrl_M->Timing.rtmDbBufLastBufWr3;
      break;
    }

    DCmotor_OL_Ctrl_M->Timing.clockTick3 =
      DCmotor_OL_Ctrl_M->Timing.rtmDbBufClockTick3
      [DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3];
    DCmotor_OL_Ctrl_M->Timing.rtmDbBufReadBuf3 = 0xFF;

    /* SystemInitialize for Outport: '<S6>/Out1' incorporates:
     *  Logic: '<S6>/XOR'
     *  UnitDelay: '<S6>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = DCmotor_OL_Ctrl_P.Out1_Y0_p;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(3), &MW_ISR_3, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<S4>/External Interrupt1' */

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
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_o = DCmotor_OL_Ctrl_P.Out1_Y0;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Start for MATLABSystem: '<S5>/Ultrasonic Sensor2' */
    DCmotor_OL_Ctrl_DW.obj_l.isInitialized = 1L;
    MW_UltrasonicSetup(50, 51);
    DCmotor_OL_Ctrl_DW.obj_l.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj.SampleTime =
      DCmotor_OL_Ctrl_P.AnalogInput1_SampleTime;
    obj = &DCmotor_OL_Ctrl_DW.obj;
    DCmotor_OL_Ctrl_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    DCmotor_OL_Ctrl_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM3' */
    DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &DCmotor_OL_Ctrl_DW.obj_g;
    DCmotor_OL_Ctrl_DW.obj_g.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 1.0, 12121.0);
    DCmotor_OL_Ctrl_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM4' */
    DCmotor_OL_Ctrl_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &DCmotor_OL_Ctrl_DW.obj_a;
    DCmotor_OL_Ctrl_DW.obj_a.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    DCmotor_OL_Ctrl_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    DCmotor_OL_Ctrl_DW.obj_j.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(13, 1);
    DCmotor_OL_Ctrl_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void DCmotor_OL_Ctrl_terminate(void)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  obj = &DCmotor_OL_Ctrl_DW.obj;
  if (!DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted = true;
    if ((DCmotor_OL_Ctrl_DW.obj.isInitialized == 1L) &&
        DCmotor_OL_Ctrl_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (DCmotor_OL_Ctrl_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */

  /* Terminate for MATLABSystem: '<Root>/PWM3' */
  if (!DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_g.matlabCodegenIsDeleted = true;
    DCmotor_OL_C_SystemCore_release(&DCmotor_OL_Ctrl_DW.obj_g);
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM3' */

  /* Terminate for MATLABSystem: '<Root>/PWM4' */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_a;
  if (!DCmotor_OL_Ctrl_DW.obj_a.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((DCmotor_OL_Ctrl_DW.obj_a.isInitialized == 1L) &&
        DCmotor_OL_Ctrl_DW.obj_a.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(DCmotor_OL_Ctrl_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM4' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!DCmotor_OL_Ctrl_DW.obj_j.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
