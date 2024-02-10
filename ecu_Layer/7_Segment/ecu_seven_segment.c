/* 
 * File:   ecu_seven_segment.c
 * Author: ali.morsy
 *
 * Created on November 9, 2023, 12:45 AM
 */



/* Section: Includes */
#include "ecu_seven_segment.h"


/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */


/**
 * @brief  This function used to initialize seven segment pins.
 * @Author Ali Morsy
 * @version 1.0
 * @param btn pointer to the seven segment configuration @ref seven_segment_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType seven_segment_initialization(const seven_segment_t* seven_segment_ptr)
{
    Std_ReturnType ret = E_OK;
    
    if(seven_segment_ptr  == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
       ret = gpio_pin_direction_initialize(&(seven_segment_ptr->segment_pins[SEGMENT_PIN0]));
       ret = gpio_pin_direction_initialize(&(seven_segment_ptr->segment_pins[SEGMENT_PIN1]));  
       ret = gpio_pin_direction_initialize(&(seven_segment_ptr->segment_pins[SEGMENT_PIN2]));  
       ret = gpio_pin_direction_initialize(&(seven_segment_ptr->segment_pins[SEGMENT_PIN3]));
    }
    return ret;
}

/**
 * @brief  This function used to display a number on seven segment.
 * @Author Ali Morsy
 * @version 1.0
 * @param  seven_segment_ptr pointer to the seven segment configuration @ref seven_segment_t.
 * @param number display it on seven segment.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType seven_segment_display(const seven_segment_t* seven_segment_ptr, uint8_t number)
{
    Std_ReturnType ret = E_OK;
    
    if(seven_segment_ptr  == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
       if(seven_segment_ptr->segment_type == SEGMENT_COMMON_ANODE)
       {
           number = ~number;
       }
       ret = gpio_pin_write_logic(&(seven_segment_ptr->segment_pins[SEGMENT_PIN0]), ( number     & 0x01) );
       ret = gpio_pin_write_logic(&(seven_segment_ptr->segment_pins[SEGMENT_PIN1]), ((number>>1) & 0x01) );  
       ret = gpio_pin_write_logic(&(seven_segment_ptr->segment_pins[SEGMENT_PIN2]), ((number>>2) & 0x01) );  
       ret = gpio_pin_write_logic(&(seven_segment_ptr->segment_pins[SEGMENT_PIN3]), ((number>>3) & 0x01) );
    }
    return ret;    
}