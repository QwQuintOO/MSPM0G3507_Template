#include "main.h"

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;

    taskDISABLE_INTERRUPTS();
    for( ;; );
}


int main (void) 
{
    SYSCFG_DL_init() ; 

    while (1)
    {
       DL_GPIO_togglePins (RED_LED1_PORT , RED_LED1_PIN_0_PIN ) ; 
       DL_Common_delayCycles (32000000) ;
    }
}
