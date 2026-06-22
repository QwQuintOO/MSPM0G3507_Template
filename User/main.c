#include "main.h"


void REDLED_Task (void *pvParameters) 
{
    for(int i = 100 ; i >= 0 ; i-- )
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


void vApplicationStackOverflowHook (TaskHandle_t xTask, char *pcTaskName)
{
    (void) xTask;
    (void) pcTaskName;
    taskDISABLE_INTERRUPTS();
    for ( ; ; ) {}  
}
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   configSTACK_DEPTH_TYPE *pulIdleTaskStackSize)
{
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,
                                    StackType_t **ppxTimerTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE *pulTimerTaskStackSize)
{
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
