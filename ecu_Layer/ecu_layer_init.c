/* 
 * File:   ecu_layer_init.c
 * Author: alimo
 *
 * Created on February 9, 2024, 6:10 PM
 */

/* Section: Includes */
#include "ecu_layer_init.h"

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

/* Section: Global variables */
keypad_t keypad_1 = 
{
    .keypad_rows_pins[0].port         = PORTC_INDEX,
    .keypad_rows_pins[0].pin          = PIN0,
    .keypad_rows_pins[0].direction    = OUTPUT,
    .keypad_rows_pins[0].logic        = GPIO_LOW,

    .keypad_rows_pins[1].port         = PORTC_INDEX,
    .keypad_rows_pins[1].pin          = PIN1,
    .keypad_rows_pins[1].direction    = OUTPUT,
    .keypad_rows_pins[1].logic        = GPIO_LOW,

    .keypad_rows_pins[2].port         = PORTC_INDEX,
    .keypad_rows_pins[2].pin          = PIN2,
    .keypad_rows_pins[2].direction    = OUTPUT,
    .keypad_rows_pins[2].logic        = GPIO_LOW,

    .keypad_rows_pins[3].port         = PORTC_INDEX,
    .keypad_rows_pins[3].pin          = PIN3,
    .keypad_rows_pins[3].direction    = OUTPUT,
    .keypad_rows_pins[3].logic        = GPIO_LOW,
    
    .keypad_columns_pins[0].port      = PORTC_INDEX,
    .keypad_columns_pins[0].pin       = PIN4,
    .keypad_columns_pins[0].direction = INPUT,
    .keypad_columns_pins[0].logic     = GPIO_LOW,
    
    .keypad_columns_pins[1].port      = PORTC_INDEX,
    .keypad_columns_pins[1].pin       = PIN5,
    .keypad_columns_pins[1].direction = INPUT,
    .keypad_columns_pins[1].logic     = GPIO_LOW,
    
    .keypad_columns_pins[2].port      = PORTC_INDEX,
    .keypad_columns_pins[2].pin       = PIN6,
    .keypad_columns_pins[2].direction = INPUT,
    .keypad_columns_pins[2].logic     = GPIO_LOW,
    
    .keypad_columns_pins[3].port      = PORTC_INDEX,
    .keypad_columns_pins[3].pin       = PIN7,
    .keypad_columns_pins[3].direction = INPUT,
    .keypad_columns_pins[3].logic     = GPIO_LOW
};

led_t led_1 = {.port_name = PORTD_INDEX, .pin = PIN0,.led_status = GPIO_LOW};

void ecu_layer_initialize(void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad_1);
    ret  = led_Initialize(&led_1);
}