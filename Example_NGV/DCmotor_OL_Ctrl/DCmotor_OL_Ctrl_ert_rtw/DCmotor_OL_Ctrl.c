/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.c
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
#include "DCmotor_OL_Ctrl_private.h"
#include "rtwtypes.h"
#include "DCmotor_OL_Ctrl_types.h"
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_DW;

/* Real-time model */
static RT_MODEL_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_M_;
RT_MODEL_DCmotor_OL_Ctrl_T *const DCmotor_OL_Ctrl_M = &DCmotor_OL_Ctrl_M_;

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
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_m = (DCmotor_OL_Ctrl_P.Constant_Value !=
      0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_m;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */
  }
}

/* Callback for Hardware Interrupt Block: '<Root>/External Interrupt1' */
void MW_ISR_3(void)
{
  /* Call the system: <Root>/Function-Call Subsystem1 */
  {
    /* S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */

    /* Logic: '<S2>/XOR' incorporates:
     *  Constant: '<S2>/Constant'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_e = (DCmotor_OL_Ctrl_P.Constant_Value_i
      != 0.0) ^ DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_e;

    /* End of Outputs for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */
  }
}

/* Model step function */
void DCmotor_OL_Ctrl_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_k_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
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
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<Root>/Analog Input'
   */
  obj_0 = &DCmotor_OL_Ctrl_DW.obj_m;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
  MW_PWM_SetDutyCycle(DCmotor_OL_Ctrl_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)(uint8_T)(((uint32_T)DCmotor_OL_Ctrl_P.Gain_Gain *
    b_varargout_1) >> 17));

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(13, (uint8_T)DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_m);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(8, (uint8_T)DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_e);
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
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_m = DCmotor_OL_Ctrl_P.Out1_Y0_a;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(2), &MW_ISR_2, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt' */

    /* SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem1'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */

    /* SystemInitialize for Outport: '<S2>/Out1' incorporates:
     *  Logic: '<S2>/XOR'
     *  UnitDelay: '<S2>/Unit Delay'
     */
    DCmotor_OL_Ctrl_DW.UnitDelay_DSTATE_e = DCmotor_OL_Ctrl_P.Out1_Y0_c;

    /* Attach callback function */
    /* Changes made wrt g2141701, this change was needed to make the
     * architecture simpler for adding new boards.
     */
    attachInterrupt(digitalPinToInterrupt(3), &MW_ISR_3, FALLING);

    /* End of SystemInitialize for S-Function (arduinoextint_sfcn): '<Root>/External Interrupt1' */

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

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    DCmotor_OL_Ctrl_DW.obj_e.matlabCodegenIsDeleted = false;
    DCmotor_OL_Ctrl_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(8, 1);
    DCmotor_OL_Ctrl_DW.obj_e.isSetupComplete = true;
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
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!DCmotor_OL_Ctrl_DW.obj_e.matlabCodegenIsDeleted) {
    DCmotor_OL_Ctrl_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
