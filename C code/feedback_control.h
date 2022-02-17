/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.h
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.346
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Mon Jun 14 18:24:54 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#include <math.h>
#include <string.h>
#ifndef feedback_control_COMMON_INCLUDES_
#define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

/* Block signals (default storage) */
typedef struct {
  real_T disconnect;                   /* '<Root>/measurements' */
  real_T average;                      /* '<Root>/measurements' */
  real_T avg_ok;                       /* '<Root>/measurements' */
  real_T on_time;                      /* '<Root>/decide_onTime' */
  real_T off_time;                     /* '<Root>/decide_onTime' */
} BlockIO_feedback_control;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T temp;                         /* '<Root>/measurements' */
  real_T m1;                           /* '<Root>/measurements' */
  real_T m2;                           /* '<Root>/measurements' */
  real_T m3;                           /* '<Root>/measurements' */
  real_T avg_temp;                     /* '<Root>/decide_onTime' */
  uint32_T temporalCounter_i1;         /* '<Root>/measurements' */
  uint32_T temporalCounter_i1_f;       /* '<Root>/levelBlink' */
  uint16_T temporalCounter_i1_o;       /* '<Root>/pulse_generator' */
  uint8_T is_active_c1_feedback_control;/* '<Root>/pulse_generator' */
  uint8_T is_c1_feedback_control;      /* '<Root>/pulse_generator' */
  uint8_T is_active_c3_feedback_control;/* '<Root>/measurements' */
  uint8_T is_c3_feedback_control;      /* '<Root>/measurements' */
  uint8_T is_active_c4_feedback_control;/* '<Root>/levelBlink' */
  uint8_T is_c4_feedback_control;      /* '<Root>/levelBlink' */
  uint8_T is_active_c2_feedback_control;/* '<Root>/decide_onTime' */
  uint8_T is_c2_feedback_control;      /* '<Root>/decide_onTime' */
} D_Work_feedback_control;

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T * volatile errorStatus;
  BlockIO_feedback_control *blockIO;
  D_Work_feedback_control *dwork;
};

/* Model entry point functions */
extern void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, real_T *feedback_control_U_echo, real_T
  *feedback_control_Y_level, real_T *feedback_control_Y_trig);
extern void feedback_control_step(RT_MODEL_feedback_control *const
  feedback_control_M, real_T feedback_control_U_echo, real_T
  *feedback_control_Y_level, real_T *feedback_control_Y_trig);
extern void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M);

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
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/decide_onTime'
 * '<S2>'   : 'feedback_control/levelBlink'
 * '<S3>'   : 'feedback_control/measurements'
 * '<S4>'   : 'feedback_control/pulse_generator'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
