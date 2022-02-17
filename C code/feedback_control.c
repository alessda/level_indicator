/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: feedback_control.c
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

#include "feedback_control.h"

/* Named constants for Chart: '<Root>/decide_onTime' */
#define feedback_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define feedback_contro_IN_disconnected ((uint8_T)3U)
#define feedback_control_IN_begin      ((uint8_T)1U)
#define feedback_control_IN_connected  ((uint8_T)2U)
#define feedback_control_IN_first_case ((uint8_T)4U)
#define feedback_control_IN_second_case ((uint8_T)5U)

/* Named constants for Chart: '<Root>/levelBlink' */
#define feedback_control_IN_begin_     ((uint8_T)1U)
#define feedback_control_IN_off        ((uint8_T)2U)
#define feedback_control_IN_on         ((uint8_T)3U)

/* Named constants for Chart: '<Root>/measurements' */
#define feedback_cont_IN_Initialization ((uint8_T)1U)
#define feedback_cont_IN_disconnected_a ((uint8_T)2U)
#define feedback_contr_IN_working_state ((uint8_T)10U)
#define feedback_control_IN_m1         ((uint8_T)3U)
#define feedback_control_IN_m2         ((uint8_T)4U)
#define feedback_control_IN_m3         ((uint8_T)5U)
#define feedback_control_IN_m4         ((uint8_T)6U)
#define feedback_control_IN_wait1      ((uint8_T)7U)
#define feedback_control_IN_wait2      ((uint8_T)8U)
#define feedback_control_IN_wait3      ((uint8_T)9U)

/* Named constants for Chart: '<Root>/pulse_generator' */
#define feedback_contr_IN_generate_trig ((uint8_T)1U)
#define feedback_control_IN_generated  ((uint8_T)2U)

/*===========*
 * Constants *
 *===========*/
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      /* do nothing */
#else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

/* Model step function */
void feedback_control_step(RT_MODEL_feedback_control *const feedback_control_M,
  real_T feedback_control_U_echo, real_T *feedback_control_Y_level, real_T
  *feedback_control_Y_trig)
{
  BlockIO_feedback_control *feedback_control_B = feedback_control_M->blockIO;
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;

  /* Chart: '<Root>/measurements' incorporates:
   *  Inport: '<Root>/echo'
   */
  if (feedback_control_DWork->temporalCounter_i1 < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i1++;
  }

  /* Gateway: measurements */
  /* During: measurements */
  if (feedback_control_DWork->is_active_c3_feedback_control == 0U) {
    /* Entry: measurements */
    feedback_control_DWork->is_active_c3_feedback_control = 1U;

    /* Entry Internal: measurements */
    /* Transition: '<S3>:2' */
    feedback_control_DWork->is_c3_feedback_control =
      feedback_cont_IN_Initialization;

    /* Entry 'Initialization': '<S3>:1' */
    feedback_control_DWork->m1 = 0.0;
    feedback_control_DWork->m2 = 0.0;
    feedback_control_DWork->m3 = 0.0;
    feedback_control_B->disconnect = 0.0;
    feedback_control_B->avg_ok = 0.0;
  } else {
    switch (feedback_control_DWork->is_c3_feedback_control) {
     case feedback_cont_IN_Initialization:
      feedback_control_B->disconnect = 0.0;

      /* During 'Initialization': '<S3>:1' */
      /* Transition: '<S3>:73' */
      feedback_control_DWork->is_c3_feedback_control =
        feedback_contr_IN_working_state;
      feedback_control_DWork->temporalCounter_i1 = 0U;
      break;

     case feedback_cont_IN_disconnected_a:
      feedback_control_B->disconnect = 1.0;

      /* During 'disconnected': '<S3>:97' */
      if (feedback_control_U_echo == 1.0) {
        /* Transition: '<S3>:100' */
        feedback_control_DWork->is_c3_feedback_control = feedback_control_IN_m1;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Entry 'm1': '<S3>:3' */
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
        feedback_control_B->disconnect = 0.0;
      }
      break;

     case feedback_control_IN_m1:
      feedback_control_B->disconnect = 0.0;

      /* During 'm1': '<S3>:3' */
      if (feedback_control_U_echo == 0.0) {
        /* Transition: '<S3>:76' */
        /* Exit 'm1': '<S3>:3' */
        feedback_control_DWork->m1 = feedback_control_DWork->temp;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_wait1;
        feedback_control_DWork->temporalCounter_i1 = 0U;
      } else {
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      }
      break;

     case feedback_control_IN_m2:
      /* During 'm2': '<S3>:24' */
      if (feedback_control_U_echo == 0.0) {
        /* Transition: '<S3>:34' */
        /* Exit 'm2': '<S3>:24' */
        feedback_control_DWork->m2 = feedback_control_DWork->temp;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_wait2;
        feedback_control_DWork->temporalCounter_i1 = 0U;
      } else {
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      }
      break;

     case feedback_control_IN_m3:
      /* During 'm3': '<S3>:33' */
      if (feedback_control_U_echo == 0.0) {
        /* Transition: '<S3>:39' */
        /* Exit 'm3': '<S3>:33' */
        feedback_control_DWork->m3 = feedback_control_DWork->temp;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_control_IN_wait3;
        feedback_control_DWork->temporalCounter_i1 = 0U;
      } else {
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      }
      break;

     case feedback_control_IN_m4:
      /* During 'm4': '<S3>:35' */
      if (feedback_control_U_echo == 0.0) {
        /* Transition: '<S3>:93' */
        /* Exit 'm4': '<S3>:35' */
        feedback_control_B->average = (((feedback_control_DWork->m1 +
          feedback_control_DWork->m2) + feedback_control_DWork->m3) +
          feedback_control_DWork->temp) / 4.0;
        feedback_control_B->avg_ok = 1.0;
        feedback_control_DWork->is_c3_feedback_control =
          feedback_contr_IN_working_state;
        feedback_control_DWork->temporalCounter_i1 = 0U;
      } else {
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      }
      break;

     case feedback_control_IN_wait1:
      /* During 'wait1': '<S3>:29' */
      if (feedback_control_U_echo == 1.0) {
        /* Transition: '<S3>:82' */
        feedback_control_DWork->is_c3_feedback_control = feedback_control_IN_m2;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Entry 'm2': '<S3>:24' */
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      } else {
        if (feedback_control_DWork->temporalCounter_i1 >= 16000U) {
          /* Transition: '<S3>:84' */
          feedback_control_DWork->is_c3_feedback_control =
            feedback_cont_IN_disconnected_a;

          /* Entry 'disconnected': '<S3>:97' */
          feedback_control_DWork->m1 = 0.0;
          feedback_control_DWork->m2 = 0.0;
          feedback_control_DWork->m3 = 0.0;
          feedback_control_B->disconnect = 1.0;
        }
      }
      break;

     case feedback_control_IN_wait2:
      /* During 'wait2': '<S3>:31' */
      if (feedback_control_U_echo == 1.0) {
        /* Transition: '<S3>:32' */
        feedback_control_DWork->is_c3_feedback_control = feedback_control_IN_m3;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Entry 'm3': '<S3>:33' */
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      } else {
        if (feedback_control_DWork->temporalCounter_i1 >= 16000U) {
          /* Transition: '<S3>:83' */
          feedback_control_DWork->is_c3_feedback_control =
            feedback_cont_IN_disconnected_a;

          /* Entry 'disconnected': '<S3>:97' */
          feedback_control_DWork->m1 = 0.0;
          feedback_control_DWork->m2 = 0.0;
          feedback_control_DWork->m3 = 0.0;
          feedback_control_B->disconnect = 1.0;
        }
      }
      break;

     case feedback_control_IN_wait3:
      /* During 'wait3': '<S3>:36' */
      if (feedback_control_U_echo == 1.0) {
        /* Transition: '<S3>:37' */
        feedback_control_DWork->is_c3_feedback_control = feedback_control_IN_m4;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Entry 'm4': '<S3>:35' */
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
      } else {
        if (feedback_control_DWork->temporalCounter_i1 >= 16000U) {
          /* Transition: '<S3>:66' */
          feedback_control_DWork->is_c3_feedback_control =
            feedback_cont_IN_disconnected_a;

          /* Entry 'disconnected': '<S3>:97' */
          feedback_control_DWork->m1 = 0.0;
          feedback_control_DWork->m2 = 0.0;
          feedback_control_DWork->m3 = 0.0;
          feedback_control_B->disconnect = 1.0;
        }
      }
      break;

     default:
      /* During 'working_state': '<S3>:72' */
      if (feedback_control_U_echo == 1.0) {
        /* Transition: '<S3>:75' */
        feedback_control_DWork->is_c3_feedback_control = feedback_control_IN_m1;
        feedback_control_DWork->temporalCounter_i1 = 0U;

        /* Entry 'm1': '<S3>:3' */
        feedback_control_DWork->temp = (((real_T)
          feedback_control_DWork->temporalCounter_i1) * 5.0) / 58.0;
        feedback_control_B->disconnect = 0.0;
      } else {
        if (feedback_control_DWork->temporalCounter_i1 >= 16000U) {
          /* Transition: '<S3>:90' */
          feedback_control_DWork->is_c3_feedback_control =
            feedback_cont_IN_disconnected_a;

          /* Entry 'disconnected': '<S3>:97' */
          feedback_control_DWork->m1 = 0.0;
          feedback_control_DWork->m2 = 0.0;
          feedback_control_DWork->m3 = 0.0;
          feedback_control_B->disconnect = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/measurements' */

  /* Chart: '<Root>/decide_onTime' */
  /* Gateway: decide_onTime */
  /* During: decide_onTime */
  if (feedback_control_DWork->is_active_c2_feedback_control == 0U) {
    /* Entry: decide_onTime */
    feedback_control_DWork->is_active_c2_feedback_control = 1U;

    /* Entry Internal: decide_onTime */
    /* Transition: '<S1>:3' */
    feedback_control_DWork->is_c2_feedback_control = feedback_control_IN_begin;

    /* Entry 'begin': '<S1>:2' */
  } else {
    switch (feedback_control_DWork->is_c2_feedback_control) {
     case feedback_control_IN_begin:
      /* During 'begin': '<S1>:2' */
      if (feedback_control_B->disconnect == 1.0) {
        /* Transition: '<S1>:10' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_contro_IN_disconnected;

        /* Entry 'disconnected': '<S1>:9' */
        feedback_control_B->on_time = 0.5;
        feedback_control_B->off_time = 0.5;
      } else {
        if (feedback_control_B->avg_ok == 1.0) {
          /* Transition: '<S1>:35' */
          feedback_control_DWork->is_c2_feedback_control =
            feedback_control_IN_connected;

          /* Entry 'connected': '<S1>:34' */
          feedback_control_DWork->avg_temp = feedback_control_B->average;
        }
      }
      break;

     case feedback_control_IN_connected:
      /* During 'connected': '<S1>:34' */
      if ((feedback_control_B->average >= 10.0) && (feedback_control_B->average <=
           100.0)) {
        /* Transition: '<S1>:5' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_control_IN_first_case;

        /* Entry 'first_case': '<S1>:4' */
        feedback_control_B->on_time = (feedback_control_B->average / 100.0) *
          0.1;
        feedback_control_B->off_time = 0.1 - feedback_control_B->on_time;
      } else {
        /* Transition: '<S1>:39' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_control_IN_second_case;

        /* Entry 'second_case': '<S1>:6' */
        feedback_control_B->on_time = 0.25;
        feedback_control_B->off_time = 0.25;
      }
      break;

     case feedback_contro_IN_disconnected:
      /* During 'disconnected': '<S1>:9' */
      if (feedback_control_B->disconnect == 0.0) {
        /* Transition: '<S1>:15' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_control_IN_begin;

        /* Entry 'begin': '<S1>:2' */
      }
      break;

     case feedback_control_IN_first_case:
      /* During 'first_case': '<S1>:4' */
      if ((((feedback_control_B->disconnect == 1.0) ||
            (feedback_control_B->average < 10.0)) ||
           (feedback_control_B->average > 100.0)) ||
          (feedback_control_B->average != feedback_control_DWork->avg_temp)) {
        /* Transition: '<S1>:13' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_control_IN_begin;

        /* Entry 'begin': '<S1>:2' */
      }
      break;

     default:
      /* During 'second_case': '<S1>:6' */
      if (((feedback_control_B->average >= 10.0) && (feedback_control_B->average
            <= 100.0)) || (feedback_control_B->disconnect == 1.0)) {
        /* Transition: '<S1>:26' */
        feedback_control_DWork->is_c2_feedback_control =
          feedback_control_IN_begin;

        /* Entry 'begin': '<S1>:2' */
      }
      break;
    }
  }

  /* End of Chart: '<Root>/decide_onTime' */

  /* Chart: '<Root>/levelBlink' */
  if (feedback_control_DWork->temporalCounter_i1_f < MAX_uint32_T) {
    feedback_control_DWork->temporalCounter_i1_f++;
  }

  /* Gateway: levelBlink */
  /* During: levelBlink */
  if (feedback_control_DWork->is_active_c4_feedback_control == 0U) {
    /* Entry: levelBlink */
    feedback_control_DWork->is_active_c4_feedback_control = 1U;

    /* Entry Internal: levelBlink */
    /* Transition: '<S2>:2' */
    feedback_control_DWork->is_c4_feedback_control = feedback_control_IN_begin_;

    /* Outport: '<Root>/level' */
    /* Entry 'begin_': '<S2>:9' */
    *feedback_control_Y_level = 0.0;
  } else {
    switch (feedback_control_DWork->is_c4_feedback_control) {
     case feedback_control_IN_begin_:
      /* Outport: '<Root>/level' */
      *feedback_control_Y_level = 0.0;

      /* During 'begin_': '<S2>:9' */
      if (feedback_control_B->disconnect != feedback_control_B->avg_ok) {
        /* Transition: '<S2>:10' */
        feedback_control_DWork->is_c4_feedback_control = feedback_control_IN_on;
        feedback_control_DWork->temporalCounter_i1_f = 0U;

        /* Outport: '<Root>/level' */
        /* Entry 'on': '<S2>:1' */
        *feedback_control_Y_level = 1.0;
      }
      break;

     case feedback_control_IN_off:
      /* Outport: '<Root>/level' */
      *feedback_control_Y_level = 0.0;

      /* During 'off': '<S2>:4' */
      if (feedback_control_DWork->temporalCounter_i1_f >= ((uint32_T)ceil
           ((feedback_control_B->off_time / 5.0E-6) - 5.0000000000000008E-14)))
      {
        /* Transition: '<S2>:6' */
        feedback_control_DWork->is_c4_feedback_control = feedback_control_IN_on;
        feedback_control_DWork->temporalCounter_i1_f = 0U;

        /* Outport: '<Root>/level' */
        /* Entry 'on': '<S2>:1' */
        *feedback_control_Y_level = 1.0;
      }
      break;

     default:
      /* Outport: '<Root>/level' */
      *feedback_control_Y_level = 1.0;

      /* During 'on': '<S2>:1' */
      if (feedback_control_DWork->temporalCounter_i1_f >= ((uint32_T)ceil
           ((feedback_control_B->on_time / 5.0E-6) - 5.0000000000000008E-14))) {
        /* Transition: '<S2>:5' */
        feedback_control_DWork->is_c4_feedback_control = feedback_control_IN_off;
        feedback_control_DWork->temporalCounter_i1_f = 0U;

        /* Outport: '<Root>/level' */
        /* Entry 'off': '<S2>:4' */
        *feedback_control_Y_level = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/levelBlink' */

  /* Chart: '<Root>/pulse_generator' */
  if (feedback_control_DWork->temporalCounter_i1_o < 16383U) {
    feedback_control_DWork->temporalCounter_i1_o++;
  }

  /* Gateway: pulse_generator */
  /* During: pulse_generator */
  if (feedback_control_DWork->is_active_c1_feedback_control == 0U) {
    /* Entry: pulse_generator */
    feedback_control_DWork->is_active_c1_feedback_control = 1U;

    /* Entry Internal: pulse_generator */
    /* Transition: '<S4>:7' */
    feedback_control_DWork->is_c1_feedback_control =
      feedback_contr_IN_generate_trig;
    feedback_control_DWork->temporalCounter_i1_o = 0U;

    /* Outport: '<Root>/trig' */
    /* Entry 'generate_trig': '<S4>:6' */
    *feedback_control_Y_trig = 1.0;
  } else if (feedback_control_DWork->is_c1_feedback_control ==
             feedback_contr_IN_generate_trig) {
    /* Outport: '<Root>/trig' */
    *feedback_control_Y_trig = 1.0;

    /* During 'generate_trig': '<S4>:6' */
    if (feedback_control_DWork->temporalCounter_i1_o >= 2U) {
      /* Transition: '<S4>:10' */
      feedback_control_DWork->is_c1_feedback_control =
        feedback_control_IN_generated;
      feedback_control_DWork->temporalCounter_i1_o = 0U;

      /* Outport: '<Root>/trig' */
      /* Entry 'generated': '<S4>:9' */
      *feedback_control_Y_trig = 0.0;
    }
  } else {
    /* Outport: '<Root>/trig' */
    *feedback_control_Y_trig = 0.0;

    /* During 'generated': '<S4>:9' */
    if (feedback_control_DWork->temporalCounter_i1_o >= 12000U) {
      /* Transition: '<S4>:12' */
      feedback_control_DWork->is_c1_feedback_control =
        feedback_contr_IN_generate_trig;
      feedback_control_DWork->temporalCounter_i1_o = 0U;

      /* Outport: '<Root>/trig' */
      /* Entry 'generate_trig': '<S4>:6' */
      *feedback_control_Y_trig = 1.0;
    }
  }

  /* End of Chart: '<Root>/pulse_generator' */
}

/* Model initialize function */
void feedback_control_initialize(RT_MODEL_feedback_control *const
  feedback_control_M, real_T *feedback_control_U_echo, real_T
  *feedback_control_Y_level, real_T *feedback_control_Y_trig)
{
  D_Work_feedback_control *feedback_control_DWork = feedback_control_M->dwork;
  BlockIO_feedback_control *feedback_control_B = feedback_control_M->blockIO;

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) feedback_control_B), 0,
                sizeof(BlockIO_feedback_control));

  /* states (dwork) */
  (void) memset((void *)feedback_control_DWork, 0,
                sizeof(D_Work_feedback_control));

  /* external inputs */
  *feedback_control_U_echo = 0.0;

  /* external outputs */
  (*feedback_control_Y_level) = 0.0;
  (*feedback_control_Y_trig) = 0.0;

  /* SystemInitialize for Chart: '<Root>/measurements' */
  feedback_control_DWork->temporalCounter_i1 = 0U;
  feedback_control_DWork->is_active_c3_feedback_control = 0U;
  feedback_control_DWork->is_c3_feedback_control =
    feedback_con_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/decide_onTime' */
  feedback_control_DWork->is_active_c2_feedback_control = 0U;
  feedback_control_DWork->is_c2_feedback_control =
    feedback_con_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/levelBlink' */
  feedback_control_DWork->temporalCounter_i1_f = 0U;
  feedback_control_DWork->is_active_c4_feedback_control = 0U;
  feedback_control_DWork->is_c4_feedback_control =
    feedback_con_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<Root>/pulse_generator' */
  feedback_control_DWork->temporalCounter_i1_o = 0U;
  feedback_control_DWork->is_active_c1_feedback_control = 0U;
  feedback_control_DWork->is_c1_feedback_control =
    feedback_con_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void feedback_control_terminate(RT_MODEL_feedback_control *const
  feedback_control_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(feedback_control_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
