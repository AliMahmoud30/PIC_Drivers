/* 
 * File:   ecu_keypad.c
 * Author: ali.morsy
 *
 * Created on February, 2024
 */

/* Section: Includes */
#include "ecu_keypad.h"

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

/* Section: variables Declarations */
static const uint8_t btn_values[KEYPAD_ROWS_PINS][KEYPAD_COLUMNS_PINS] = 
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'}
};

/**
 * @brief  This function used to initialize keypad pins.
 * @Author Ali Morsy
 * @version 1.0
 * @param keypad_obj pointer to the keypad configuration @ref keypad_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType keypad_initialize(const keypad_t* keypad_obj)
{
    Std_ReturnType ret = E_OK;
    uint8_t rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
    if(keypad_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(rows_counter = ZERO_INIT; rows_counter < KEYPAD_ROWS_PINS; rows_counter++)
        {
            ret = gpio_pin_initialize(&(keypad_obj->keypad_rows_pins[rows_counter]));
        }
        for(columns_counter = ZERO_INIT; columns_counter < KEYPAD_COLUMNS_PINS; columns_counter++)
        {
            ret = gpio_pin_direction_initialize(&(keypad_obj->keypad_columns_pins[columns_counter]));
        }
    }
    return ret;
}
/**
 * @brief  This function used to get value from keypad pins.
 * @Author Ali Morsy
 * @version 1.0
 * @param keypad_obj pointer to the keypad configuration @ref keypad_t
 * @param value_ptr pointer to return keypad value.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType keypad_get_value(const keypad_t* keypad_obj, uint8_t* value_ptr)
{
    Std_ReturnType ret = E_OK;
    uint8_t l_rows = ZERO_INIT, l_columns = ZERO_INIT, l_counter = ZERO_INIT;
    logic_t ret_pin_val = ZERO_INIT;
    uint8_t l_kepad_value = KEYPAD_DEFAULT_VALUE;
    if((keypad_obj == NULL)||(value_ptr == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(l_rows = ZERO_INIT; l_rows < KEYPAD_ROWS_PINS; l_rows++)
        {
            for(l_counter = ZERO_INIT; l_counter < KEYPAD_ROWS_PINS; l_counter++)
            {
                ret = gpio_pin_write_logic(&(keypad_obj->keypad_rows_pins[l_counter]), GPIO_LOW);
            }
            ret = gpio_pin_write_logic(&(keypad_obj->keypad_rows_pins[l_rows]), GPIO_HIGH);
            
            for(l_columns = ZERO_INIT; l_columns < KEYPAD_COLUMNS_PINS; l_columns++)
            {
                ret  = gpio_pin_read_logic(&(keypad_obj->keypad_columns_pins[l_columns]), &ret_pin_val);
                if(ret_pin_val == GPIO_HIGH)
                {
                    l_kepad_value = btn_values[l_rows][l_columns];
                    break;
                }
            }
            if(l_kepad_value != KEYPAD_DEFAULT_VALUE)
                break;
        }
         *value_ptr = l_kepad_value;
    }
    return ret;    
}

