#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void) {
		/**
			STM32: AO口 LED闪烁
		*/
	
		// RCC开启时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
		// GPIO初始化
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		/** 	
			GPIO库函数点灯 
			三种方式
		*/
		
		// A0口熄灭
		// GPIO_SetBits(GPIOA, GPIO_Pin_0);
		// A0口点亮
		//GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		// A0口点亮
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		// A0口熄灭
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	
		while (1) {
				GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
				Delay_ms(300);
				GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
				Delay_ms(300);
		}
}