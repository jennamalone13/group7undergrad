/*
 * ros_controller1_dm_data.cpp
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

/* Block parameters (default storage) */
P_ros_controller1_dm_T ros_controller1_dm_P = {
  /* Expression: 15
   * Referenced by: '<Root>/Constant'
   */
  15.0,

  /* Expression: 80
   * Referenced by: '<S3>/Saturation'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S3>/Saturation'
   */
  0.0,

  /* Expression: 15
   * Referenced by: '<Root>/Constant2'
   */
  15.0,

  /* Expression: 80
   * Referenced by: '<S4>/Saturation'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 7
   * Referenced by: '<S5>/car_length'
   */
  7.0,

  /* Expression: 60
   * Referenced by: '<Root>/Constant1'
   */
  60.0,

  /* Expression: 500
   * Referenced by: '<Root>/initial_space_to_int'
   */
  500.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<Root>/sine_center'
   */
  20.0,

  /* Expression: 15
   * Referenced by: '<Root>/v_desired'
   */
  15.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S3>/Transfer Fcn'
   */
  0.5,

  /* Computed Parameter: TransferFcn_A_o
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C_d
   * Referenced by: '<S4>/Transfer Fcn'
   */
  0.5,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
