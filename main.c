#include "stm32f10x.h"
#include "delay.h"

void gpio_ports_enable(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
// Configure PC13 as desired
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; //Red
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //Yellow
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //Green
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_Init(GPIOC, &GPIO_InitStructure);
}
int main(void)
{
gpio_ports_enable();
int state = 0; // 0 -> Red, 1 -> Yellow, 2 -> Green
int prev = 0;
	while(1)
	{
		switch(state)
		{
			case(0):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_13);
				delay(5000);
				GPIO_ResetBits(GPIOC, GPIO_Pin_13);
				prev = 0;
				state = 1;
			}
			case(1):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_12);
				delay(2000);
				GPIO_ResetBits(GPIOC, GPIO_Pin_12);
				if(prev)
				state = 0;
				else
				state = 2;
			}
			case(2):
			{
				GPIO_SetBits(GPIOC, GPIO_Pin_11);
				delay(5000);
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