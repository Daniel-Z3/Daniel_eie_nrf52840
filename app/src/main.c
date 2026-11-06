/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 5

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }
  

  while (1) {
    if(BTN_check_clear_pressed(BTN0)){
      LED_toggle(LED0);
      printk("Pressed button 0\n");
    }   
    if(BTN_check_pressed(BTN1)){
      LED_toggle(LED1);
      printk("Pressed button 1\n");
    } 
    if(BTN_check_clear_pressed(BTN2)){
      BTN_clear_pressed(BTN1);
      printk("Cleared BTN 1\n");
    } 
    k_msleep(SLEEP_MS);
  }
  return 0;
}
