/* 
 * File:   ecu_keypad.h
 * Author: alimo
 *
 * Created on February 3, 2024, 5:01 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H
#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_keypad_cfg.h"

/* Section: Includes */

/* Section: Macro Declarations */
#define KEYPAD_ROWS_PINS       4
#define KEYPAD_COLUMNS_PINS    4

#define KEYPAD_DEFAULT_VALUE    (uint8_t)0xFF
/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
typedef struct
{
    pin_config_t keypad_rows_pins[KEYPAD_ROWS_PINS];
    pin_config_t keypad_columns_pins[KEYPAD_COLUMNS_PINS];
}keypad_t;

/* Section: Function Declarations */
Std_ReturnType keypad_initialize(const keypad_t* keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t* keypad_obj, uint8_t* value_ptr);

#endif	/* ECU_KEYPAD_H */

