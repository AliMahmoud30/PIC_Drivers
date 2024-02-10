#include "ecu_relay.h"

/* Section: Includes */

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */

/* Section: Function Declarations */

/**
 * @brief  This function used to initialize a pin as output 
 * @Author Ali Morsy
 * @version 1.0
 * @param relay pointer to the pin configuration @ref relay_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType relay_initialization(const relay_t* relay)
{
    Std_ReturnType ret = E_OK;
    pin_config_t pin_obj = {.port = relay->relay_port, .pin = relay->relay_pin,
                            .direction = OUTPUT, .logic = relay->relay_status};
    if(relay == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&pin_obj);
    }
    return ret;
}

/**
 * @brief  This function used to turn on a relay @ref  relay_t
 * @Author Ali Morsy
 * @version 1.0
 * @param relay pointer to the pin configuration @ref relay_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType relay_turn_on(const relay_t* relay)
{
    Std_ReturnType ret = E_OK;
    pin_config_t pin_obj = {.port = relay->relay_port, .pin = relay->relay_pin,
                            .direction = OUTPUT, .logic = relay->relay_status};
    if(relay == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;
}

/**
 * @brief  This function used to turn off a relay @ref  relay_t
 * @Author Ali Morsy
 * @version 1.0
 * @param relay pointer to the pin configuration @ref relay_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType relay_turn_off(const relay_t* relay)
{
    Std_ReturnType ret = E_OK;
    pin_config_t pin_obj ={.port = relay->relay_port, .pin = relay->relay_pin,
                           .direction = OUTPUT, .logic = relay->relay_status};
    if(relay == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}
