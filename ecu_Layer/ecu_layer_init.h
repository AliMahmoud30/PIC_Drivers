/* 
 * File:   ecu_layer_init.h
 * Author: alimo
 *
 * Created on February 9, 2024, 6:10 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H

/* Section: Includes */
#include "Led/ecu_led.h"
#include "button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "DC_Motor/ecu_dc_motor.h"
#include "7_Segment/ecu_seven_segment.h"
#include "Keypad/ecu_keypad.h"


/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
extern keypad_t keypad_1;
extern led_t led_1;

/* Section: Function Declarations */
void ecu_layer_initialize(void);


#endif	/* ECU_LAYER_INIT_H */

