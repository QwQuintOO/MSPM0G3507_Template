#include "main.h"


void REDLED_Task (void *pvParameters) 
{
    while (1)
    {
    DL_GPIO_togglePins (RED_LED1_PORT , RED_LED1_PIN_0_PIN ) ; 
    DL_Common_delayCycles (32000000) ;
    }
}



int main (void) 
{
    SYSCFG_DL_init() ; 

    xTaskCreate (REDLED_Task , "REDLED_Task" , 128 , NULL , 1 , NULL) ;
   
    vTaskStartScheduler () ;

    while (1)
    {}
}
