#include "stm32f10x.h"
#include "delay.h"
#include "config.h"

int state = 0; // 0 -> Red, 1 -> Yellow, 2 -> Green
int prev = 0; // 0 -> Red, 2 -> Green

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
	while(1)
	{
		switch(state)
		{
			case 0:
			
				GPIO_SetBits(GPIOA, GPIO_Pin_6);
				delayMs(5000);
				GPIO_ResetBits(GPIOA, GPIO_Pin_6);
				prev = 0;
				state = 1;
				break ;
			
			case 1:
			
				GPIO_SetBits(GPIOA, GPIO_Pin_5);
				delayMs(2000);
				GPIO_ResetBits(GPIOA, GPIO_Pin_5);
				if(prev)
				state = 0;
				else
				state = 2;
				break ;
			
			case 2:
			
				GPIO_SetBits(GPIOA, GPIO_Pin_4);
				delayMs(5000);
				GPIO_ResetBits(GPIOA, GPIO_Pin_4);
				prev = 2;
				state = 1;
				break ;
			
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
