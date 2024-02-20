#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	GPIO_InitTypeDef GPIO_Initstructure2;
	GPIO_Initstructure2.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstructure2.GPIO_Pin=GPIO_Pin_14;
	GPIO_Initstructure2.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure2);
	
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)== 1)
		{
		GPIO_SetBits(GPIOA,GPIO_Pin_12);
		Delay_ms(1000);
		GPIO_ResetBits(GPIOA,GPIO_Pin_12);
		Delay_ms(1000);
		}
		else
		{
		GPIO_SetBits(GPIOA,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_ResetBits(GPIOA,GPIO_Pin_12);
		Delay_ms(100);
		}
	}
}
