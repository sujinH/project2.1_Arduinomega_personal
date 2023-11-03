/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.h
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

#ifndef RTW_HEADER_DCmotor_OL_Ctrl_h_
#define RTW_HEADER_DCmotor_OL_Ctrl_h_
#ifndef DCmotor_OL_Ctrl_COMMON_INCLUDES_
#define DCmotor_OL_Ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                                 /* DCmotor_OL_Ctrl_COMMON_INCLUDES_ */

#include "DCmotor_OL_Ctrl_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Output' */
  codertarget_arduinobase_int_k_T obj_m;/* '<Root>/PWM' */
  codertarget_arduinobase_in_k5_T obj_n;/* '<Root>/Ultrasonic Sensor1' */
  boolean_T UnitDelay_DSTATE;          /* '<S3>/Unit Delay' */
} DW_DCmotor_OL_Ctrl_T;

/* Parameters (default storage) */
struct P_DCmotor_OL_Ctrl_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S3>/Unit Delay'
                                */
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DCmotor_OL_Ctrl_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_P;

/* Block states (default storage) */
extern DW_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_DW;

/* External function called from main */
extern void DCmotor_OL_Ctrl_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void DCmotor_OL_Ctrl_initialize(void);
extern void DCmotor_OL_Ctrl_step0(void);
extern void DCmotor_OL_Ctrl_step1(void);
extern void DCmotor_OL_Ctrl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DCmotor_OL_Ctrl_T *const DCmotor_OL_Ctrl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/AND1' : Unused code path elimination
 * Block '<S1>/Compare' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S2>/Compare' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<Root>/Constant3' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display Status1' : Unused code path elimination
 * Block '<Root>/Display Status2' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Gain2' : Unused code path elimination
 * Block '<Root>/Relational Operator3' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'DCmotor_OL_Ctrl'
 * '<S1>'   : 'DCmotor_OL_Ctrl/Compare To Constant'
 * '<S2>'   : 'DCmotor_OL_Ctrl/Compare To Constant1'
 * '<S3>'   : 'DCmotor_OL_Ctrl/Function-Call Subsystem2'
 */
#endif                                 /* RTW_HEADER_DCmotor_OL_Ctrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
