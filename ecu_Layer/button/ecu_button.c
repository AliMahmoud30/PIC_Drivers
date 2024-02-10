/* 
 * File:   ecu_button.c
 * Author: ali.morsy
 *
 * Created on November 9, 2023, 12:45 AM
 */



/* Section: Includes */
#include "ecu_button.h"


/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

/**
 * @brief  This function used to initialize a pin as input.
 * @Author Ali Morsy
 * @version 1.0
 * @param btn pointer to the button configuration @ref button_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType button_initialize(const button_t* btn)
{
    Std_ReturnType ret = E_OK;
    
    if (btn == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret  = gpio_pin_direction_initialize(&(btn->button_pin));
    }
    return ret;
}
/**
 * @brief  This function used to read a button status.
 * @Author Ali Morsy
 * @version 1.0
 * @param btn pointer to the button configuration @ref button_t
 * @param ret_state pointer to return button state @ref button_state_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType button_read_state(const button_t* btn, button_state_t* ret_state)
{
    Std_ReturnType ret = E_OK;
    logic_t read_logic = GPIO_LOW;
    
    if ( (btn == NULL) || ( ret_state == NULL) )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_read_logic(&(btn->button_pin), &read_logic);
        if( (btn->button_connection) == BUTTON_ACTIVE_HIGH )
        {
            if(read_logic == GPIO_HIGH)
            {
                *ret_state = BUTTON_PRESSED;
            }
            else
            {
                *(ret_state) = BUTTON_RELEASED;
            }
        }
        else if( (btn->button_connection) == BUTTON_ACTIVE_LOW )
        {
            if(read_logic == GPIO_LOW)
            {
                *ret_state = BUTTON_PRESSED;
            }
            else
            {
                *ret_state = BUTTON_RELEASED;
            }  
        }
        else
        {
            /* nothing */
        }
    }
    return ret;    
}