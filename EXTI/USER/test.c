# include "sys.h"
# include "usart.h"
# include "delay.h"
# include "key.h"
# include "led.h"
int main(void)
{
	Stm32_Clock_Init(9);
	uart_init(72,9600);
	delay_init(72);
	LED_Init();
	KEY_Init();
	EXTIX_Init();
	LED0=0;
	while(1)
	{
		printf("OK\r\n");
		delay_ms(10000);
	}
}
