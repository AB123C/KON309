#include "config.h"

void Config_GPIO()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; //Red
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //Yellow
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //Green
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void Config_EXTI()
{
	
}