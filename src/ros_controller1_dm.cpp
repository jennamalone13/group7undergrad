/*
 * ros_controller1_dm.cpp
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

#include "ros_controller1_dm.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rtwtypes.h"
#include "ros_controller1_dm_private.h"
#include <string.h>

/* Block signals (default storage) */
B_ros_controller1_dm_T ros_controller1_dm_B;

/* Continuous states */
X_ros_controller1_dm_T ros_controller1_dm_X;

/* Disabled State Vector */
XDis_ros_controller1_dm_T ros_controller1_dm_XDis;

/* Block states (default storage) */
DW_ros_controller1_dm_T ros_controller1_dm_DW;

/* Real-time model */
RT_MODEL_ros_controller1_dm_T ros_controller1_dm_M_ =
  RT_MODEL_ros_controller1_dm_T();
RT_MODEL_ros_controller1_dm_T *const ros_controller1_dm_M =
  &ros_controller1_dm_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ros_controller1_dm_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ros_controller1_dm_step();
  ros_controller1_dm_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ros_controller1_dm_step();
  ros_controller1_dm_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ros_controller1_dm_step(void)
{
  real_T distance_to_intersection;
  real_T rtb_Clock;
  real_T rtb_space_gap;
  real_T vel_ego;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(ros_controller1_dm_M)) {
    /* set solver stop time */
    if (!(ros_controller1_dm_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ros_controller1_dm_M->solverInfo,
                            ((ros_controller1_dm_M->Timing.clockTickH0 + 1) *
        ros_controller1_dm_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ros_controller1_dm_M->solverInfo,
                            ((ros_controller1_dm_M->Timing.clockTick0 + 1) *
        ros_controller1_dm_M->Timing.stepSize0 +
        ros_controller1_dm_M->Timing.clockTickH0 *
        ros_controller1_dm_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ros_controller1_dm_M)) {
    ros_controller1_dm_M->Timing.t[0] = rtsiGetT
      (&ros_controller1_dm_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(ros_controller1_dm_M);
  if (tmp) {
    /* Constant: '<Root>/Constant' */
    ros_controller1_dm_B.Constant = ros_controller1_dm_P.Constant_Value;
  }

  /* Integrator: '<S3>/Integrator' */
  if (ros_controller1_dm_DW.Integrator_DWORK1) {
    ros_controller1_dm_X.Integrator_CSTATE = ros_controller1_dm_B.Constant;
  }

  /* Saturate: '<S3>/Saturation' incorporates:
   *  Integrator: '<S3>/Integrator'
   */
  if (ros_controller1_dm_X.Integrator_CSTATE >
      ros_controller1_dm_P.Saturation_UpperSat) {
    /* Saturate: '<S3>/Saturation' */
    ros_controller1_dm_B.Saturation = ros_controller1_dm_P.Saturation_UpperSat;
  } else if (ros_controller1_dm_X.Integrator_CSTATE <
             ros_controller1_dm_P.Saturation_LowerSat) {
    /* Saturate: '<S3>/Saturation' */
    ros_controller1_dm_B.Saturation = ros_controller1_dm_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S3>/Saturation' */
    ros_controller1_dm_B.Saturation = ros_controller1_dm_X.Integrator_CSTATE;
  }

  /* End of Saturate: '<S3>/Saturation' */
  if (tmp) {
    /* Constant: '<Root>/Constant2' */
    ros_controller1_dm_B.Constant2 = ros_controller1_dm_P.Constant2_Value;
  }

  /* Integrator: '<S4>/Integrator' */
  if (ros_controller1_dm_DW.Integrator_DWORK1_p) {
    ros_controller1_dm_X.Integrator_CSTATE_j = ros_controller1_dm_B.Constant2;
  }

  /* Saturate: '<S4>/Saturation' incorporates:
   *  Integrator: '<S4>/Integrator'
   */
  if (ros_controller1_dm_X.Integrator_CSTATE_j >
      ros_controller1_dm_P.Saturation_UpperSat_d) {
    /* Saturate: '<S4>/Saturation' */
    ros_controller1_dm_B.Saturation_b =
      ros_controller1_dm_P.Saturation_UpperSat_d;
  } else if (ros_controller1_dm_X.Integrator_CSTATE_j <
             ros_controller1_dm_P.Saturation_LowerSat_j) {
    /* Saturate: '<S4>/Saturation' */
    ros_controller1_dm_B.Saturation_b =
      ros_controller1_dm_P.Saturation_LowerSat_j;
  } else {
    /* Saturate: '<S4>/Saturation' */
    ros_controller1_dm_B.Saturation_b = ros_controller1_dm_X.Integrator_CSTATE_j;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Sum: '<Root>/relative_vel' */
  ros_controller1_dm_B.relative_vel = ros_controller1_dm_B.Saturation -
    ros_controller1_dm_B.Saturation_b;

  /* Clock: '<Root>/Clock' */
  rtb_Clock = ros_controller1_dm_M->Timing.t[0];
  if (tmp) {
    /* Constant: '<Root>/Constant3' */
    ros_controller1_dm_B.Constant3 = ros_controller1_dm_P.Constant3_Value;
  }

  /* Integrator: '<S4>/Integrator1' */
  if (ros_controller1_dm_DW.Integrator1_DWORK1) {
    ros_controller1_dm_X.Integrator1_CSTATE = ros_controller1_dm_B.Constant3;
  }

  /* Integrator: '<S4>/Integrator1' */
  ros_controller1_dm_B.Integrator1 = ros_controller1_dm_X.Integrator1_CSTATE;
  if (tmp) {
    /* Constant: '<Root>/Constant1' */
    ros_controller1_dm_B.Constant1 = ros_controller1_dm_P.Constant1_Value;
  }

  /* Integrator: '<S3>/Integrator1' */
  if (ros_controller1_dm_DW.Integrator1_DWORK1_b) {
    ros_controller1_dm_X.Integrator1_CSTATE_a = ros_controller1_dm_B.Constant1;
  }

  /* Sum: '<S5>/space_gap' incorporates:
   *  Constant: '<S5>/car_length'
   *  Integrator: '<S3>/Integrator1'
   *  Sum: '<S5>/space_from_centers'
   */
  rtb_space_gap = (ros_controller1_dm_X.Integrator1_CSTATE_a -
                   ros_controller1_dm_B.Integrator1) -
    ros_controller1_dm_P.car_length_Value;

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/initial_space_to_int'
   */
  vel_ego = ros_controller1_dm_B.Saturation_b;
  ros_controller1_dm_B.crash = 0.0;
  if (rtb_space_gap < 0.0) {
    ros_controller1_dm_B.acc_desired = 0.0;
    ros_controller1_dm_B.crash = -10.0;
  } else {
    if ((ros_controller1_dm_B.Saturation_b > -0.01) &&
        (ros_controller1_dm_B.Saturation_b < 0.01)) {
      vel_ego = 0.01;
    }

    distance_to_intersection = ros_controller1_dm_P.initial_space_to_int_Value -
      ros_controller1_dm_B.Integrator1;
    if ((36.0 - rtb_Clock < 1.0) && (36.0 - rtb_Clock > 0.0)) {
      ros_controller1_dm_B.acc_desired = 15.0 - vel_ego;
    } else if ((distance_to_intersection < 100.0) && (distance_to_intersection >
                0.0)) {
      ros_controller1_dm_B.acc_desired = (distance_to_intersection - (36.0 -
        rtb_Clock) * vel_ego) * 2.0 / ((36.0 - rtb_Clock) * (36.0 - rtb_Clock));
      if ((15.0 - vel_ego <= ros_controller1_dm_B.acc_desired) || rtIsNaN
          (ros_controller1_dm_B.acc_desired)) {
        ros_controller1_dm_B.acc_desired = 15.0 - vel_ego;
      }
    } else {
      ros_controller1_dm_B.acc_desired = 15.0 - vel_ego;
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Product: '<Root>/Divide' */
  ros_controller1_dm_B.time_gap = rtb_space_gap /
    ros_controller1_dm_B.Saturation_b;
  if (tmp) {
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/initial_space_to_int'
   */
  ros_controller1_dm_B.x_to_int =
    ros_controller1_dm_P.initial_space_to_int_Value -
    ros_controller1_dm_B.Integrator1;
  if (tmp) {
  }

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<S5>/Constant'
   */
  ros_controller1_dm_B.RelationalOperator = (rtb_space_gap <=
    ros_controller1_dm_P.Constant_Value_o);
  if (tmp) {
    /* Stop: '<S5>/Stop Simulation' */
    if (ros_controller1_dm_B.RelationalOperator) {
      rtmSetStopRequested(ros_controller1_dm_M, 1);
    }

    /* End of Stop: '<S5>/Stop Simulation' */
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/sine_center'
   *  Constant: '<Root>/v_desired'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<Root>/Add'
   */
  if (ros_controller1_dm_P.ManualSwitch_CurrentSetting == 1) {
    rtb_space_gap = ros_controller1_dm_P.v_desired_Value;
  } else {
    rtb_space_gap = (sin(ros_controller1_dm_P.SineWave_Freq *
                         ros_controller1_dm_M->Timing.t[0] +
                         ros_controller1_dm_P.SineWave_Phase) *
                     ros_controller1_dm_P.SineWave_Amp +
                     ros_controller1_dm_P.SineWave_Bias) +
      ros_controller1_dm_P.sine_center_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Sum' */
  ros_controller1_dm_B.Sum = rtb_space_gap - ros_controller1_dm_B.Saturation;

  /* MATLAB Function: '<Root>/Controller' incorporates:
   *  Integrator: '<Root>/Integrator'
   */
  ros_controller1_dm_B.a_desired = 0.3 * ros_controller1_dm_B.Sum + 0.01 *
    ros_controller1_dm_X.Integrator_CSTATE_o;
  if (ros_controller1_dm_B.a_desired >= 1.5) {
    ros_controller1_dm_B.a_desired = 1.5;
  } else if (ros_controller1_dm_B.a_desired <= -3.0) {
    ros_controller1_dm_B.a_desired = -3.0;
  }

  /* End of MATLAB Function: '<Root>/Controller' */

  /* TransferFcn: '<S3>/Transfer Fcn' */
  ros_controller1_dm_B.TransferFcn = ros_controller1_dm_P.TransferFcn_C *
    ros_controller1_dm_X.TransferFcn_CSTATE;

  /* TransferFcn: '<S4>/Transfer Fcn' */
  ros_controller1_dm_B.TransferFcn_o = ros_controller1_dm_P.TransferFcn_C_d *
    ros_controller1_dm_X.TransferFcn_CSTATE_k;
  if (rtmIsMajorTimeStep(ros_controller1_dm_M)) {
    /* Update for Integrator: '<S3>/Integrator' */
    ros_controller1_dm_DW.Integrator_DWORK1 = false;

    /* Update for Integrator: '<S4>/Integrator' */
    ros_controller1_dm_DW.Integrator_DWORK1_p = false;

    /* Update for Integrator: '<S4>/Integrator1' */
    ros_controller1_dm_DW.Integrator1_DWORK1 = false;

    /* Update for Integrator: '<S3>/Integrator1' */
    ros_controller1_dm_DW.Integrator1_DWORK1_b = false;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ros_controller1_dm_M)) {
    rt_ertODEUpdateContinuousStates(&ros_controller1_dm_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ros_controller1_dm_M->Timing.clockTick0)) {
      ++ros_controller1_dm_M->Timing.clockTickH0;
    }

    ros_controller1_dm_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ros_controller1_dm_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      ros_controller1_dm_M->Timing.clockTick1++;
      if (!ros_controller1_dm_M->Timing.clockTick1) {
        ros_controller1_dm_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ros_controller1_dm_derivatives(void)
{
  XDot_ros_controller1_dm_T *_rtXdot;
  _rtXdot = ((XDot_ros_controller1_dm_T *) ros_controller1_dm_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = ros_controller1_dm_B.TransferFcn;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = ros_controller1_dm_B.TransferFcn_o;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ros_controller1_dm_B.Saturation_b;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_a = ros_controller1_dm_B.Saturation;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = ros_controller1_dm_B.Sum;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = ros_controller1_dm_P.TransferFcn_A *
    ros_controller1_dm_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += ros_controller1_dm_B.a_desired;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_k = ros_controller1_dm_P.TransferFcn_A_o *
    ros_controller1_dm_X.TransferFcn_CSTATE_k;
  _rtXdot->TransferFcn_CSTATE_k += ros_controller1_dm_B.acc_desired;
}

/* Model initialize function */
void ros_controller1_dm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ros_controller1_dm_M->solverInfo,
                          &ros_controller1_dm_M->Timing.simTimeStep);
    rtsiSetTPtr(&ros_controller1_dm_M->solverInfo, &rtmGetTPtr
                (ros_controller1_dm_M));
    rtsiSetStepSizePtr(&ros_controller1_dm_M->solverInfo,
                       &ros_controller1_dm_M->Timing.stepSize0);
    rtsiSetdXPtr(&ros_controller1_dm_M->solverInfo,
                 &ros_controller1_dm_M->derivs);
    rtsiSetContStatesPtr(&ros_controller1_dm_M->solverInfo, (real_T **)
                         &ros_controller1_dm_M->contStates);
    rtsiSetNumContStatesPtr(&ros_controller1_dm_M->solverInfo,
      &ros_controller1_dm_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ros_controller1_dm_M->solverInfo,
      &ros_controller1_dm_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ros_controller1_dm_M->solverInfo,
      &ros_controller1_dm_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ros_controller1_dm_M->solverInfo,
      &ros_controller1_dm_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ros_controller1_dm_M->solverInfo, (boolean_T**)
      &ros_controller1_dm_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ros_controller1_dm_M->solverInfo, (&rtmGetErrorStatus
      (ros_controller1_dm_M)));
    rtsiSetRTModelPtr(&ros_controller1_dm_M->solverInfo, ros_controller1_dm_M);
  }

  rtsiSetSimTimeStep(&ros_controller1_dm_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ros_controller1_dm_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ros_controller1_dm_M->solverInfo, false);
  ros_controller1_dm_M->intgData.y = ros_controller1_dm_M->odeY;
  ros_controller1_dm_M->intgData.f[0] = ros_controller1_dm_M->odeF[0];
  ros_controller1_dm_M->intgData.f[1] = ros_controller1_dm_M->odeF[1];
  ros_controller1_dm_M->intgData.f[2] = ros_controller1_dm_M->odeF[2];
  ros_controller1_dm_M->contStates = ((X_ros_controller1_dm_T *)
    &ros_controller1_dm_X);
  ros_controller1_dm_M->contStateDisabled = ((XDis_ros_controller1_dm_T *)
    &ros_controller1_dm_XDis);
  ros_controller1_dm_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ros_controller1_dm_M->solverInfo, static_cast<void *>
                    (&ros_controller1_dm_M->intgData));
  rtsiSetSolverName(&ros_controller1_dm_M->solverInfo,"ode3");
  rtmSetTPtr(ros_controller1_dm_M, &ros_controller1_dm_M->Timing.tArray[0]);
  ros_controller1_dm_M->Timing.stepSize0 = 1.0;
  rtmSetFirstInitCond(ros_controller1_dm_M, 1);

  /* block I/O */
  (void) memset((static_cast<void *>(&ros_controller1_dm_B)), 0,
                sizeof(B_ros_controller1_dm_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&ros_controller1_dm_X), 0,
                  sizeof(X_ros_controller1_dm_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&ros_controller1_dm_XDis), 0,
                  sizeof(XDis_ros_controller1_dm_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&ros_controller1_dm_DW), 0,
                sizeof(DW_ros_controller1_dm_T));

  /* Start for Constant: '<Root>/Constant' */
  ros_controller1_dm_B.Constant = ros_controller1_dm_P.Constant_Value;

  /* Start for Constant: '<Root>/Constant2' */
  ros_controller1_dm_B.Constant2 = ros_controller1_dm_P.Constant2_Value;

  /* Start for Constant: '<Root>/Constant3' */
  ros_controller1_dm_B.Constant3 = ros_controller1_dm_P.Constant3_Value;

  /* Start for Constant: '<Root>/Constant1' */
  ros_controller1_dm_B.Constant1 = ros_controller1_dm_P.Constant1_Value;

  /* InitializeConditions for Integrator: '<S3>/Integrator' incorporates:
   *  Integrator: '<S3>/Integrator1'
   *  Integrator: '<S4>/Integrator'
   *  Integrator: '<S4>/Integrator1'
   */
  if (rtmIsFirstInitCond(ros_controller1_dm_M)) {
    ros_controller1_dm_X.Integrator_CSTATE = 15.0;
    ros_controller1_dm_X.Integrator_CSTATE_j = 15.0;
    ros_controller1_dm_X.Integrator1_CSTATE = 0.0;
    ros_controller1_dm_X.Integrator1_CSTATE_a = 60.0;
  }

  ros_controller1_dm_DW.Integrator_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S3>/Integrator' */

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  ros_controller1_dm_DW.Integrator_DWORK1_p = true;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  ros_controller1_dm_DW.Integrator1_DWORK1 = true;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  ros_controller1_dm_DW.Integrator1_DWORK1_b = true;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  ros_controller1_dm_X.Integrator_CSTATE_o = ros_controller1_dm_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  ros_controller1_dm_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
  ros_controller1_dm_X.TransferFcn_CSTATE_k = 0.0;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ros_controller1_dm_M)) {
    rtmSetFirstInitCond(ros_controller1_dm_M, 0);
  }
}

/* Model terminate function */
void ros_controller1_dm_terminate(void)
{
  /* (no terminate code required) */
}
