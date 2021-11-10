#include "stm32f10x.h"
#include "delay.h"
#include "config.h"

int state = 0; // 0 -> Red, 1 -> Yellow, 2 -> Green

void Setup(void)
{
Config_GPIO();
Config_EXTI();
Config_NVIC();
delayInit();
}
int main(void)
{
Setup();
int prev = 0; // 0 -> Red, 2 -> Green
	while(1)
	{
		switch(state)
		{
			case(0):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
				delayMs(5000);
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
				prev = 0;
				state = 1;
			}
			case(1):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_12);
				delayMs(2000);
				GPIO_ResetBits(GPIOC, GPIO_Pin_12);
				if(prev)
				state = 0;
				else
				state = 2;
			}
			case(2):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_11);
				delayMs(5000);
				GPIO_ResetBits(GPIOC, GPIO_Pin_11);
				prev = 2;
				state = 1;
			}
		}
	} 			
}
/*Interrupt()
{
	if(state == 2)
	{
		state = 1;
		prev = 2;
		break;
	}
}
*/