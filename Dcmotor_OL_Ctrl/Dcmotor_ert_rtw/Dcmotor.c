/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Dcmotor.c
 *
 * Code generated for Simulink model 'Dcmotor'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov  1 17:52:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Dcmotor.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Dcmotor_types.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_Dcmotor_T Dcmotor_DW;

/* Real-time model */
static RT_MODEL_Dcmotor_T Dcmotor_M_;
RT_MODEL_Dcmotor_T *const Dcmotor_M = &Dcmotor_M_;

/* Model step function */
void Dcmotor_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T tmp;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (Dcmotor_DW.obj.SampleTime != Dcmotor_P.AnalogInput_SampleTime) {
    Dcmotor_DW.obj.SampleTime = Dcmotor_P.AnalogInput_SampleTime;
  }

  obj = &Dcmotor_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (Dcmotor_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &Dcmotor_DW.obj_m;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/Analog Input'
   *  Product: '<Root>/Divide'
   */
  tmp = floor((real_T)b_varargout_1 / Dcmotor_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  MW_PWM_SetDutyCycle(Dcmotor_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)(tmp <
    0.0 ? (int16_T)(uint8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(uint8_T)tmp));

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(9, 0);
}

/* Model initialize function */
void Dcmotor_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    codertarget_arduinobase_int_a_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    Dcmotor_DW.obj.matlabCodegenIsDeleted = false;
    Dcmotor_DW.obj.SampleTime = Dcmotor_P.AnalogInput_SampleTime;
    obj = &Dcmotor_DW.obj;
    Dcmotor_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    Dcmotor_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    Dcmotor_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Dcmotor_DW.obj_m;
    Dcmotor_DW.obj_m.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    Dcmotor_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    Dcmotor_DW.obj_n.matlabCodegenIsDeleted = false;
    Dcmotor_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(9, 1);
    Dcmotor_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void Dcmotor_terminate(void)
{
  codertarget_arduinobase_int_a_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &Dcmotor_DW.obj;
  if (!Dcmotor_DW.obj.matlabCodegenIsDeleted) {
    Dcmotor_DW.obj.matlabCodegenIsDeleted = true;
    if ((Dcmotor_DW.obj.isInitialized == 1L) && Dcmotor_DW.obj.isSetupComplete)
    {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(Dcmotor_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &Dcmotor_DW.obj_m;
  if (!Dcmotor_DW.obj_m.matlabCodegenIsDeleted) {
    Dcmotor_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Dcmotor_DW.obj_m.isInitialized == 1L) &&
        Dcmotor_DW.obj_m.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(Dcmotor_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Dcmotor_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!Dcmotor_DW.obj_n.matlabCodegenIsDeleted) {
    Dcmotor_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
