// trampoline for measure out of range
#include <stdio.h>
#include "tpl_os.h"
#include "feedback_control.h"
#include "rtwtypes.h"

static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_MPtr =
  &feedback_control_M_;                /* Real-time model */
static BlockIO_feedback_control feedback_control_B;/* Observable signals */
static D_Work_feedback_control feedback_control_DWork;/* Observable states */

/* '<Root>/echo' */
static real_T feedback_control_U_echo;
/* '<Root>/level' */
static real_T feedback_control_Y_level;
/* '<Root>/trig' */
static real_T feedback_control_Y_trig;

void setup(){
        /* Pack model data into RTM */
        feedback_control_MPtr->blockIO = &feedback_control_B;
        feedback_control_MPtr->dwork = &feedback_control_DWork;
        /* Initialize model */
        feedback_control_initialize(feedback_control_MPtr, &feedback_control_U_echo,&feedback_control_Y_level, &feedback_control_Y_trig);
}

int main(void){
    setup();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

DeclareAlarm(alarm_10msec);

// Here the following function "reads" an echo corresponding to 5cm
real_T  BSWreadEcho( void ){       
	static uint8_T tmp = 0;
	static int n_activation = 0;
        static int i=0;
	n_activation++;
        i++;
        if (i<=58){
                tmp = 1;        
        }
        else {
                tmp = 0;
        }               
        if (i == 14000) { //after 70ms (slightely more than the trig generation) 
                i = 0;
        }  
        printf( "\nBSWreadEcho (%d): %d\r\n", n_activation,tmp);
	return(tmp);
}

        
void    BSWwriteLevel( uint8_T x ){
	static int n_activation = 0;
	n_activation++;
        if( x != 0 ){
                printf( "BSWwriteLevel(%d): 1\r\n", n_activation );              
        } else {
                printf( "BSWwriteLevel(%d): 0\r\n", n_activation );
        }
}

void    BSWwriteTrig( uint8_T x ){
	static int n_activation = 0;
	n_activation++;
        if( x != 0 ){
                printf("BSWwriteTrig (%d): 1\r\n", n_activation);
        }
        else
        {
                printf("BSWwriteTrig (%d): 0\r\n", n_activation);
        }
}

TASK(my_periodic_task){
        printf( "---\r\n" );
        feedback_control_U_echo = BSWreadEcho();
        feedback_control_step(feedback_control_MPtr, feedback_control_U_echo, &feedback_control_Y_level, &feedback_control_Y_trig);
        BSWwriteLevel(feedback_control_Y_level);
        BSWwriteTrig(feedback_control_Y_trig);
        TerminateTask();
}

 TASK(stop){
        CancelAlarm(alarm_10msec);
        printf("Shutdown\r\n");
        ShutdownOS(E_OK);
        TerminateTask();
 }
