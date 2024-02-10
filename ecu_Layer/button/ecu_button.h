/* 
 * File:   ecu_button.h
 * Author: ali.morsy
 *
 * Created on November 9, 2023, 12:45 AM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section: Includes */
#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_button_cfg.h"




/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

typedef enum
{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum 
{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
}button_active_t;

typedef struct
{
    pin_config_t    button_pin;
    button_state_t  button_state;
    button_active_t button_connection;
}button_t;

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
Std_ReturnType button_initialize(const button_t* btn);


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
Std_ReturnType button_read_state(const button_t* btn, button_state_t* ret_state);

#endif	/* ECU_BUTTON_H */

