/*
 * ros_controller1_dm.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ros_controller1_dm".
 *
 * Model version              : 1.28
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Tue Nov 12 09:50:04 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ros_controller1_dm_h_
#define ros_controller1_dm_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ros_controller1_dm_types.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
struct B_ros_controller1_dm_T {
  real_T Constant;                     /* '<Root>/Constant' */
  real_T Saturation;                   /* '<S3>/Saturation' */
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T Saturation_b;                 /* '<S4>/Saturation' */
  real_T relative_vel;                 /* '<Root>/relative_vel' */
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Integrator1;                  /* '<S4>/Integrator1' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T time_gap;                     /* '<Root>/Divide' */
  real_T x_to_int;                     /* '<Root>/Sum1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T TransferFcn;                  /* '<S3>/Transfer Fcn' */
  real_T TransferFcn_o;                /* '<S4>/Transfer Fcn' */
  real_T acc_desired;                  /* '<Root>/MATLAB Function1' */
  real_T crash;                        /* '<Root>/MATLAB Function1' */
  real_T a_desired;                    /* '<Root>/Controller' */
  boolean_T RelationalOperator;        /* '<S5>/Relational Operator' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_ros_controller1_dm_T {
  boolean_T Integrator_DWORK1;         /* '<S3>/Integrator' */
  boolean_T Integrator_DWORK1_p;       /* '<S4>/Integrator' */
  boolean_T Integrator1_DWORK1;        /* '<S4>/Integrator1' */
  boolean_T Integrator1_DWORK1_b;      /* '<S3>/Integrator1' */
};

/* Continuous states (default storage) */
struct X_ros_controller1_dm_T {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_o;          /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S4>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_ros_controller1_dm_T {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S3>/Integrator1' */
  real_T Integrator_CSTATE_o;          /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<S3>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S4>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_ros_controller1_dm_T {
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S4>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S3>/Integrator1' */
  boolean_T Integrator_CSTATE_o;       /* '<Root>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<S3>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_k;      /* '<S4>/Transfer Fcn' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_ros_controller1_dm_T_ {
  real_T Constant_Value;               /* Expression: 15
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 80
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 15
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 80
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T car_length_Value;             /* Expression: 7
                                        * Referenced by: '<S5>/car_length'
                                        */
  real_T Constant1_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T initial_space_to_int_Value;   /* Expression: 500
                                        * Referenced by: '<Root>/initial_space_to_int'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T sine_center_Value;            /* Expression: 20
                                        * Referenced by: '<Root>/sine_center'
                                        */
  real_T v_desired_Value;              /* Expression: 15
                                        * Referenced by: '<Root>/v_desired'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_A_o;              /* Computed Parameter: TransferFcn_A_o
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_d;              /* Computed Parameter: TransferFcn_C_d
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_ros_controller1_dm_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ros_controller1_dm_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ros_controller1_dm_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[7];
  real_T odeF[3][7];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_ros_controller1_dm_T ros_controller1_dm_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_ros_controller1_dm_T ros_controller1_dm_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_ros_controller1_dm_T ros_controller1_dm_X;

/* Disabled states (default storage) */
extern XDis_ros_controller1_dm_T ros_controller1_dm_XDis;

/* Block states (default storage) */
extern struct DW_ros_controller1_dm_T ros_controller1_dm_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void ros_controller1_dm_initialize(void);
  extern void ros_controller1_dm_step(void);
  extern void ros_controller1_dm_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_ros_controller1_dm_T *const ros_controller1_dm_M;

#ifdef __cplusplus

}

#endif

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
 * '<Root>' : 'ros_controller1_dm'
 * '<S1>'   : 'ros_controller1_dm/Controller'
 * '<S2>'   : 'ros_controller1_dm/MATLAB Function1'
 * '<S3>'   : 'ros_controller1_dm/car'
 * '<S4>'   : 'ros_controller1_dm/ego_car'
 * '<S5>'   : 'ros_controller1_dm/space_gap'
 */
#endif                                 /* ros_controller1_dm_h_ */
