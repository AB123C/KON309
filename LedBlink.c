#include "stm32f10x.h"
#include "delay.h"
GPIO_InitTypeDef GPIO_InitStructure;
int main(void)
{
	int started = 0, state = 0;
	int b1_pressed = 0,
	
	// Enable clock for PortC and PortA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// Configure PC13 as desired
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	// Configure button as pull down connected to PA4
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    Config_EXTI();
    Config_NVIC();
	delayInit();

	while(1)
	{
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delayMs(5000);
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delayMs(5000);
    }	
}
