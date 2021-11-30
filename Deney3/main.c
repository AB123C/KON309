#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;

TIM_TimeBaseStructure.TIM_Period = 49999;
TIM_TimeBaseStructure.TIM_Prescaler = 143;
TIM_TimeBaseStructure.TIM_ClockDivision = 0;
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; // TIM2_CCMR1
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; // TIM2_CCER
TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; // TIM2_CCER
TIM_OCInitStructure.TIM_Pulse = 3600; // TIM2_CCR1
TIM_OC2Init(TIM2, &TIM_OCInitStructure);


int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	//PWM'li pinler için:
	//https://os.mbed.com/media/uploads/hudakz/stm32f103c8t6_pinout_voltage01.png

	//Red
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//Yellow
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//Green
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//Buton1
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//Buton2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_Cmd(TIM2, ENABLE);

    while(1)
    {
		
	} 			
}
