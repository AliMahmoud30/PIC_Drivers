/* 
 * File:   led.c
 * Author: alimo
 *
 * Created on June 30, 2023, 10:08 PM
 */

#include "ecu_led.h"

/**
 * @brief  This function used to initialize a pin as output with default logic state 
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType led_Initialize(const led_t* led)
{
   Std_ReturnType ret = E_OK; 
   pin_config_t pin_obj = {.port = led->port_name, .pin  = led->pin,
                           .direction = OUTPUT, .logic = led->led_status};
   if (led != NULL)
   {
       ret = gpio_pin_initialize(&pin_obj);
   }
   else
   {
       ret = E_NOT_OK;
   }  
   return ret;
}

/**
 * @brief  This function used to turn on a led 
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done  not successfully 
 */
Std_ReturnType led_turn_on(const led_t* led)
{
   Std_ReturnType ret = E_OK; 
   pin_config_t pin_obj = {.port = led->port_name, .pin  = led->pin,
                           .direction = OUTPUT, .logic = led->led_status};
   if (led != NULL)
   {
       ret = gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
   }
   else
   {
       ret = E_NOT_OK;
   }
   return ret;    
}

/**
 * @brief  This function used to turn off a led 
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType led_turn_off(const led_t* led)
{
   Std_ReturnType ret = E_OK; 
   pin_config_t pin_obj = {.port = led->port_name, .pin  = led->pin,
                           .direction = OUTPUT, .logic = led->led_status};
   if (led != NULL)
   {
       ret = gpio_pin_write_logic(&pin_obj, GPIO_LOW);
   }
   else
   {
       ret = E_NOT_OK;
   }
   
   return ret;    
}

/**
 * @brief  This function used to turn toggle a led 
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType led_toggle(const led_t* led)
{
   Std_ReturnType ret = E_OK; 
   pin_config_t pin_obj = {.port = led->port_name, .pin  = led->pin,
                           .direction = OUTPUT, .logic = led->led_status};    
   if (led != NULL)
   {
       ret = gpio_pin_toggle_logic(&pin_obj);
   }
   else
   {
       ret = E_NOT_OK;
   }
   
   return ret;    
}

