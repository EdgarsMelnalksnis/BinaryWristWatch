#include "main.h"
#include "BinaryWristWatch.h"

uint32_t cycle_counter = 0;

void set_LED(uint32_t LED_anode, uint32_t LED_cathode) //function to set LED
{
	//maybe start with reset?
	reset_LED();
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */

	/**/
	//LL_GPIO_ResetOutputPin(GPIOA, LED_anode);
	/**/
	//LL_GPIO_ResetOutputPin(GPIOA, LED_cathode);
	GPIO_InitStruct.Pin = LED_anode | LED_cathode; //GPIO pins as outputs
	GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	LL_GPIO_SetOutputPin(GPIOA, LED_anode);
	LL_GPIO_ResetOutputPin(GPIOA, LED_cathode);

}
void reset_LED(void) //all leds off (sets all GPIO ports as inputs)
{
	LL_GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.Pin = LL_GPIO_PIN_7 | LL_GPIO_PIN_8 | LL_GPIO_PIN_9
			| LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | LL_GPIO_PIN_12 | LL_GPIO_PIN_15; //GPIO pins as outputs
	GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
	//GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
	//GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void blink_LED(uint32_t Anode, uint32_t Cathode, uint32_t delay)//blink led (anode,cathode,delay) !or add PWM?
{
	set_LED(Anode, Cathode);
	LL_mDelay(delay);
	reset_LED();
}
void set_lower_seconds(uint8_t lower_seconds)//sets lower part of seconds (0 to 9)
{
cycle_counter++;
	if (lower_seconds == 1 && cycle_counter % 3 == 0) {
		set_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7);
	} else if (lower_seconds == 2 && cycle_counter % 3 == 0 ) {
		set_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8);
	} else if (lower_seconds == 3) {
		if(cycle_counter%2==0){
		set_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7);
		}
		else{
		set_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8);
		}
	} else if (lower_seconds == 4) {
		set_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7);
	} else if (lower_seconds == 5) {
		set_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7);
		set_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7);
	} else if (lower_seconds == 6) {
		set_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8);
		set_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7);
	} else if (lower_seconds == 7) {
		set_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7);
		set_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8);
		set_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7);
	} else if (lower_seconds == 8) {
		set_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_7);
	} else if (lower_seconds == 9) {
		set_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7);
		set_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_7);
	}

	/*
	 if (lower_seconds == 1) {

	 blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);//adjust brightnes by delay/2
	 } else if (lower_seconds == 2) {
	 blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8, LED_BLINK_DELAY);
	 } else if (lower_seconds == 3) {
	 blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8, LED_BLINK_DELAY);
	 } else if (lower_seconds == 4) {
	 blink_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 } else if (lower_seconds == 5) {
	 blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 } else if (lower_seconds == 6) {
	 blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 } else if (lower_seconds == 7) {
	 blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_9, LL_GPIO_PIN_8, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_12, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 } else if (lower_seconds == 8) {
	 blink_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 } else if (lower_seconds == 9) {
	 blink_LED(LL_GPIO_PIN_10, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 blink_LED(LL_GPIO_PIN_11, LL_GPIO_PIN_7, LED_BLINK_DELAY);
	 }
	 */
}
