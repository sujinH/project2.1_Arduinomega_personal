/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.c
 *
 * Code generated for Simulink model 'DCmotor_OL_Ctrl'.
 *
 * Model version                  : 3.20
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov  2 13:57:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DCmotor_OL_Ctrl.h"
#include "DCmotor_OL_Ctrl_private.h"
#include "rtwtypes.h"
#include "DCmotor_OL_Ctrl_types.h"
#include "rt_nonfinite.h"

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
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem2' */

    /* Logic: '<S3>/XOR' incorporates:
     *  Constant: '<S3>/Constant'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = (DCmotor_OL_Ctrl_P.Constant_Value !=
      0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE;

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

/* Model step function for TID0 */
void DCmotor_OL_Ctrl_step0(void)       /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void DCmotor_OL_Ctrl_step1(void)       /* Sample time: [0.1s, 0.0s] */
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint32_T duration;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (DCmotor_OL_Ctrl_DW.obj.SampleTime !=
      DCmotor_OL_Ctrl_P.AnalogInput_SampleTime) {
    DCmotor_OL_Ctrl_DW.obj.SampleTime = DCmotor_OL_Ctrl_P.AnalogInput_SampleTime;
  }

  obj = &DCmotor_OL_Ctrl_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (DCmotor_OL_Ctrl_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_m;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  u0 = (int32_T)DCmotor_OL_Ctrl_P.Gain_Gain * b_varargout_1;
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* End of MATLABSystem: '<Root>/PWM' */
  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE);

  /* MATLABSystem: '<Root>/Ultrasonic Sensor1' */
  if (DCmotor_OL_Ctrl_DW.obj_n.TunablePropsChanged) {
    DCmotor_OL_Ctrl_DW.obj_n.TunablePropsChanged = false;
  }

  MW_UltrasonicRead(&duration, 1, 50, 51, 10);

  /* End of MATLABSystem: '<Root>/Ultrasonic Sensor1' */
}

/* Model initialize function */
void DCmotor_OL_Ctrl_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_int_k_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem2'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem2' */

    /* SystemInitialize for Outport: '<S3>/Out1' incorporates:
     *  Logic: '<S3>/XOR'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE = DCmotor_OL_Ctrl_P.Out1_Y0;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    DCmotor_OL_Ctrl_DW.obj.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj.SampleTime = DCmotor_OL_Ctrl_P.AnalogInput_SampleTime;
    obj = &DCmotor_OL_Ctrl_DW.obj;
    DCmotor_OL_Ctrl_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    DCmotor_OL_Ctrl_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &DCmotor_OL_Ctrl_DW.obj_m;
    DCmotor_OL_Ctrl_DW.obj_m.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    DCmotor_OL_Ctrl_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    DCmotor_OL_Ctrl_DW.obj_l.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(13, 1);
    DCmotor_OL_Ctrl_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Ultrasonic Sensor1' */
    DCmotor_OL_Ctrl_DW.obj_n.isInitialized = 1L;
    MW_UltrasonicSetup(50, 51);
    DCmotor_OL_Ctrl_DW.obj_n.TunablePropsChanged = false;
  }
}

/* Model terminate function */
void DCmotor_OL_Ctrl_terminate(void)
{
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
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

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_m;
  if (!DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((DCmotor_OL_Ctrl_DW.obj_m.isInitialized == 1L) &&
        DCmotor_OL_Ctrl_DW.obj_m.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!DCmotor_OL_Ctrl_DW.obj_l.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
