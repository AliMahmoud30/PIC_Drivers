/* 
 * File:   led.h
 * Author: alimo
 *
 * Created on June 30, 2023, 10:08 PM
 */

#ifndef LED_H
#define	LED_H

/* Section: Includes */
#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_led_cfg.h"

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
typedef enum
{
    LED_OFF,
    LED_ON
}led_status_t;

typedef struct
{
  uint8_t   port_name  : 3;
  uint8_t   pin        : 3;
  uint8_t   led_status : 1;
  uint8_t   reserved   : 1; 
}led_t;

/* Section: Function Declarations */

Std_ReturnType led_Initialize(const led_t* led);
Std_ReturnType led_turn_on(const led_t* led);
Std_ReturnType led_turn_off(const led_t* led);
Std_ReturnType led_toggle(const led_t* led);

#endif	/* LED_H */

