#include "stm32f4xx.h"
#define LED1 GPIO_Pin_12;
#define LED2 GPIO_Pin_13;
#define LED3 GPIO_Pin_14;
#define LED4 GPIO_Pin_15;

void delay (volatile int n)
{
while (n < 200000)
{
++n;
}
}

int main (void) 
	{	
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
//RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
GPIOD->MODER = 0x55000000;
GPIOD->OTYPER = 0; //GPIO_MODE_OUTPUT_PP;
GPIOD->OSPEEDR = 0;//GPIO_SPEED_FREQ_LOW;

//0x00002000;

		
while (1)
{
GPIOD->ODR = LED1;
delay(0);
GPIOD->ODR = LED2;
delay(0);
GPIOD->ODR = LED3;
delay(0);
GPIOD->ODR = LED4;
delay(0);

}
		return 0;
}