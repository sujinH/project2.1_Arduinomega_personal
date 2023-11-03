/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Dcmotor.h
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

#ifndef RTW_HEADER_Dcmotor_h_
#define RTW_HEADER_Dcmotor_h_
#ifndef Dcmotor_COMMON_INCLUDES_
#define Dcmotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* Dcmotor_COMMON_INCLUDES_ */

#include "Dcmotor_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_a_T obj_m;/* '<Root>/PWM' */
} DW_Dcmotor_T;

/* Parameters (default storage) */
struct P_Dcmotor_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant_Value;               /* Expression: 4
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Dcmotor_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Dcmotor_T Dcmotor_P;

/* Block states (default storage) */
extern DW_Dcmotor_T Dcmotor_DW;

/* Model entry point functions */
extern void Dcmotor_initialize(void);
extern void Dcmotor_step(void);
extern void Dcmotor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Dcmotor_T *const Dcmotor_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Dcmotor'
 */
#endif                                 /* RTW_HEADER_Dcmotor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
