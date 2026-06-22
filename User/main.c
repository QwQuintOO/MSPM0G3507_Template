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
    while (1)
    {
        
    }
}
