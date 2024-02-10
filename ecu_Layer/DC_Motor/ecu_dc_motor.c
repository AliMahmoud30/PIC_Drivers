/* 
 * File:   ecu_dc_motor.c
 * Author: ali morsy
 *
 * Created on November 24, 2023, 5:12 PM
 */

/* Section: Includes */

#include "ecu_dc_motor.h"

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

/**
 * @brief  This function used to initialize a pin as output to use motor
 * @Author Ali Morsy
 * @version 1.0
 * @param _dc_motor pointer to the pin configuration @ref _dc_motor
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType dc_motor_initialize(const dc_motor_t* _dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    { 
         ret = gpio_pin_initialize(&(_dc_motor->dc_motor_pin[MOTOR_PIN_1]));
         ret = gpio_pin_initialize(&(_dc_motor->dc_motor_pin[MOTOR_PIN_2]));
    }
    return ret;
}

/**
 * @brief  This function used to move motor right
 * @Author Ali Morsy
 * @version 1.0
 * @param _dc_motor pointer to the pin configuration @ref _dc_motor
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_1]), GPIO_HIGH);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_2]), GPIO_LOW);
    }
    
    return ret;
}

/**
 * @brief  This function used to move motor left
 * @Author Ali Morsy
 * @version 1.0
 * @param _dc_motor pointer to the pin configuration @ref _dc_motor
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_1]), GPIO_LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_2]), GPIO_HIGH);  
    }
    
    return ret;
}

/**
 * @brief  This function used to stop motor
 * @Author Ali Morsy
 * @version 1.0
 * @param _dc_motor pointer to the pin configuration @ref _dc_motor
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType dc_motor_stop(const dc_motor_t* _dc_motor)
{
    Std_ReturnType ret = E_OK;
    
    if(_dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_1]), GPIO_LOW);
        ret = gpio_pin_write_logic(&(_dc_motor->dc_motor_pin[MOTOR_PIN_2]), GPIO_LOW);          
    }

    return ret;
}
