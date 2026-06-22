#include    "led.h"

void gpio_init (void)
{
    // 1. 把 PA0 配置成 GPIO 功能
    DL_GPIO_initDigitalOutput(IOMUX_PINCM1);

    // 2. 使能 PA0 输出方向
    DL_GPIO_enableOutput(GPIOA, DL_GPIO_PIN_0);

    // 3. 设置初始电平
    DL_GPIO_clearPins(GPIOA, DL_GPIO_PIN_0);
}
