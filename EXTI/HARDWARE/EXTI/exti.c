# include "exti.h"
# include "led.h"
# include "key.h"
# include "delay.h"
# include "usart.h"

//外部中断0服务程序
void EXTI0_IRQHandler(void)
{
	delay_ms(10);
	if(KEY3==1) 
	{
		LED0=!LED0;
		delay_ms(50);
		LED0=!LED0;
	}
	EXTI->PR=1<<0;// 清除中断标志位
}
//外部中断2服务程序
void EXTI2_IRQHandler(void)
{
	delay_ms(10);
	if(KEY2==1) 
	{
		LED0=!LED0;
		delay_ms(100);
		LED0=!LED0;
	}
	EXTI->PR=1<<2;// 清除中断标志位
}
//外部中断3服务程序
void EXTI3_IRQHandler(void)
{
	delay_ms(10);
	if(KEY1==1) 
	{
		LED0=!LED0;
		delay_ms(150);
		LED0=!LED0;
	}
	EXTI->PR=1<<3;// 清除中断标志位
}
//外部中断4服务程序
void EXTI4_IRQHandler(void)
{
	delay_ms(10);
	if(KEY0==1) 
	{
		LED0=!LED0;
		delay_ms(150);
		LED0=!LED0;
	}
	EXTI->PR=1<<4;// 清除中断标志位
}

//外部中断初始化程序
//初始化PA0、PE2、PE3、PE4为中断输入
void EXTIX_Init(void)
{
	KEY_Init();
	Ex_NVIC_Config(GPIO_A,0,RTIR);
	Ex_NVIC_Config(GPIO_E,2,FTIR);
   	Ex_NVIC_Config(GPIO_E,3,FTIR);
	Ex_NVIC_Config(GPIO_E,4,FTIR);
	MY_NVIC_Init(2,3,EXTI0_IRQChannel,2);
	MY_NVIC_Init(2,2,EXTI2_IRQChannel,2);
	MY_NVIC_Init(2,1,EXTI3_IRQChannel,2);
	MY_NVIC_Init(2,0,EXTI4_IRQChannel,2);
}
