#include "inc/led.h"

void delay(volatile int time)
{
	while (time--)
	{
	}
}

void main()
{
	led_init();
	while (1)
	{
		delay(0x1FFFFF);
		led_set_value(1, 0);
		delay(0x1FFFFF);
		led_set_value(1, 1);
	}
}
