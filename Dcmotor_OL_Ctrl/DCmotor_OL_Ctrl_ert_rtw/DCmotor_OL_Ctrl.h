/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: DCmotor_OL_Ctrl.h
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

#ifndef RTW_HEADER_DCmotor_OL_Ctrl_h_
#define RTW_HEADER_DCmotor_OL_Ctrl_h_
#ifndef DCmotor_OL_Ctrl_COMMON_INCLUDES_
#define DCmotor_OL_Ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduinoextint.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_Ultrasonic.h"
#endif                                 /* DCmotor_OL_Ctrl_COMMON_INCLUDES_ */

#include "DCmotor_OL_Ctrl_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<Root>/If Action Subsystem6' */
} DW_IfActionSubsystem6_DCmotor_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain3;                        /* '<S4>/Gain3' */
  real_T Merge1;                       /* '<S4>/Merge1' */
  real_T Divide;                       /* '<Root>/Divide' */
  uint8_T DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  boolean_T RateTransition1;           /* '<Root>/Rate Transition1' */
} B_DCmotor_OL_Ctrl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/PWM1' */
  codertarget_arduinobase_inter_T obj_m;/* '<Root>/PWM' */
  codertarget_arduinobase_int_k_T obj_o;/* '<S4>/Ultrasonic Sensor2' */
  boolean_T UnitDelay_DSTATE;          /* '<S1>/Unit Delay' */
  int8_T FunctionCallSubsystem2_SubsysRa;/* '<Root>/Function-Call Subsystem2' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem11;/* '<S4>/If Action Subsystem11' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem10;/* '<S4>/If Action Subsystem10' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem9;/* '<S4>/If Action Subsystem9' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem8;/* '<S4>/If Action Subsystem8' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem7_n;/* '<S4>/If Action Subsystem7' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem6_j;/* '<S4>/If Action Subsystem6' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem7;/* '<Root>/If Action Subsystem7' */
  DW_IfActionSubsystem6_DCmotor_T IfActionSubsystem6;/* '<Root>/If Action Subsystem6' */
} DW_DCmotor_OL_Ctrl_T;

/* Parameters for system: '<Root>/If Action Subsystem6' */
struct P_IfActionSubsystem6_DCmotor__T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_DCmotor_OL_Ctrl_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 100
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T Constant_Value_d;             /* Expression: 255
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Merge1_InitialOutput;         /* Expression: [0]
                                        * Referenced by: '<Root>/Merge1'
                                        */
  boolean_T Out1_Y0;                   /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S1>/Unit Delay'
                                */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem11;/* '<S4>/If Action Subsystem11' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem10;/* '<S4>/If Action Subsystem10' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem9;/* '<S4>/If Action Subsystem9' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem8;/* '<S4>/If Action Subsystem8' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem7_n;/* '<S4>/If Action Subsystem7' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem6_j;/* '<S4>/If Action Subsystem6' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem7;/* '<Root>/If Action Subsystem7' */
  P_IfActionSubsystem6_DCmotor__T IfActionSubsystem6;/* '<Root>/If Action Subsystem6' */
};

/* Real-time Model Data Structure */
struct tag_RTM_DCmotor_OL_Ctrl_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint8_T rtmDbBufReadBuf2;
    uint8_T rtmDbBufWriteBuf2;
    boolean_T rtmDbBufLastBufWr2;
    uint32_T rtmDbBufClockTick2[2];
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_P;

/* Block signals (default storage) */
extern B_DCmotor_OL_Ctrl_T DCmotor_OL_Ctrl_B;

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
 * '<S1>'   : 'DCmotor_OL_Ctrl/Function-Call Subsystem2'
 * '<S2>'   : 'DCmotor_OL_Ctrl/If Action Subsystem6'
 * '<S3>'   : 'DCmotor_OL_Ctrl/If Action Subsystem7'
 * '<S4>'   : 'DCmotor_OL_Ctrl/Subsystem'
 * '<S5>'   : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem10'
 * '<S6>'   : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem11'
 * '<S7>'   : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem6'
 * '<S8>'   : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem7'
 * '<S9>'   : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem8'
 * '<S10>'  : 'DCmotor_OL_Ctrl/Subsystem/If Action Subsystem9'
 */
#endif                                 /* RTW_HEADER_DCmotor_OL_Ctrl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
