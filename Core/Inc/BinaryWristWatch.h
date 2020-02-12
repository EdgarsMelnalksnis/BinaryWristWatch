#ifndef __BINARYWRISTWATCH_H
#define __BINARYWRISTWATCH_H

#ifdef __cplusplus
 extern "C" {
#endif

#define LED_BLINK_DELAY 1



void set_LED(uint32_t, uint32_t); //set LEDs (Anode,Cathode)
void reset_LED(void); //all leds off (sets all GPIO ports as inputs)
void blink_LED(uint32_t, uint32_t, uint32_t); //blink led (anode,cathode,delay)

void set_lower_seconds(uint8_t);
void set_upper_seconds(uint8_t);
#ifdef __cplusplus
}
#endif

#endif /* __BINARYWRISTWATCH_H*/
