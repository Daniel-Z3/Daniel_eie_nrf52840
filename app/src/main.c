/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  uint8_t counter=0;
  while (1) {
    if(BTN_check_clear_pressed(BTN0)){
      counter++;
      if(counter==16){
        counter=0;
        LED_set(LED0,LED_OFF);
        LED_set(LED1,LED_OFF);
        LED_set(LED2,LED_OFF);
        LED_set(LED3,LED_OFF);
      }
    }
    //LED0
      if(counter&(0b1<<3))LED_set(LED0,LED_ON);
      else LED_set(LED0,LED_OFF); 
      if(counter&(0b1<<2))LED_set(LED1,LED_ON); 
      else LED_set(LED1,LED_OFF); 
      if(counter&(0b1<<1))LED_set(LED2,LED_ON); 
      else LED_set(LED2,LED_OFF); 
      if(counter&(0b1))LED_set(LED3,LED_ON);
      else LED_set(LED3,LED_OFF);  
      
    
    k_msleep(SLEEP_MS);
  }
  return 0;
}
