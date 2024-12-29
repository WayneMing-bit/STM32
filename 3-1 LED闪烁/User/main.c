#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void) {
		/**
			STM32: AO�� LED��˸
		*/
	
		// RCC����ʱ��
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
		// GPIO��ʼ��
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		/** 	
			GPIO�⺯����� 
			���ַ�ʽ
		*/
		
		// A0��Ϩ��
		// GPIO_SetBits(GPIOA, GPIO_Pin_0);
		// A0�ڵ���
		//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		// A0�ڵ���
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		// A0��Ϩ��
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	
		while (1) {
				GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
				Delay_ms(300);
				GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
				Delay_ms(300);
		}
}