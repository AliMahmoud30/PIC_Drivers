/* 
 * File:   mcal_gpio.c
 * Author: alimo
 *
 * Created on June 30, 2023, 5:42 PM
 */

#include "mcal_gpio.h"

/*! Reference to the data direction control register*/
volatile uint8_t *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*! Reference to the latch control register (Read And Write)*/
volatile uint8_t *lat_registers[]  = {&LATA, &LATB, &LATC, &LATD, &LATE};
/*! Reference to the Port status register*/
volatile uint8_t *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 * @brief  This function used to initialize a pin 
 * @Author Ali Morsy
 * @version 1.0
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if ((_pin_config == NULL) || (_pin_config->pin > PORT_PIN_MAX_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(_pin_config -> direction)
        {
            case OUTPUT:
                CLR_BIT(*(tris_registers[_pin_config->port]), _pin_config->pin);
                break;
            case INPUT:
                SET_BIT(*(tris_registers[_pin_config->port]), _pin_config->pin);
                break;
            default:  ret = E_NOT_OK;
        }
    }  
    return ret;
}

/**
 * @brief  This function used to return direction status
 * @Author Ali Morsy
 * @version 1.0
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @param dir_status pointer to return direction status for pin.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config, direction_t* dir_status)
{
    Std_ReturnType ret = E_OK;
    
    if ((_pin_config == NULL) || (dir_status == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dir_status = GET_BIT(*(tris_registers[_pin_config->port]), _pin_config->pin);
    }
    
    return ret;
}

/**
 * @brief  This function used to write High/low on a specific pin 
 * @Author Ali Morsy
 * @version 1.0
 * @param _pin_config pointer to the pin configuration @ref pin_config_t.
 * @param logic status witch write on pin @ref logic_t.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config, logic_t logic)
{
    Std_ReturnType ret = E_OK;
    if (_pin_config == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(logic)
        {
            case GPIO_HIGH:
                SET_BIT(*(lat_registers[_pin_config->port]),_pin_config->pin);
                break;
            case GPIO_LOW:
                CLR_BIT(*(lat_registers[_pin_config->port]),_pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * @brief  This function used to read pin status.
 * @Author Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t.
 * @param logic pointer to return pin status @ref logic_t.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config, logic_t* logic)
{
    Std_ReturnType ret = E_OK;
    if ((_pin_config == NULL) || (logic == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = GET_BIT(*(port_registers[_pin_config->port]), _pin_config->pin);
    }
    return ret;   
}

/**
 * @brief  This function used to toggle pin status.
 * @Author Ali Morsy
 * @version 1.0 
 * @param _pin_config pointer to the pin configuration @ref pin_config_t.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_OK;
    if (_pin_config == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOG_BIT(*(lat_registers[_pin_config->port]),_pin_config->pin);
    }
    return ret;    
}


/**
 * @brief  This function used to initialize a pin with default logic 
 * @Author Ali Morsy
 * @version 1.0
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully 
 *                         (E_NOT_OK) : the function done not successfully 
 */
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if ((_pin_config == NULL) || (_pin_config->pin > PORT_PIN_MAX_NUMBER-1))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_initialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config, _pin_config->logic);
        
    }  
    return ret;
}

/**
 * @brief  This function used to initialize the direction for all pins in a specific port.
 * @Author Ali Morsy.
 * @version 1.0.
 * @param  port index @ref  port_index_t.
 * @param  direction status OUTPUT/INPUT.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8_t direction)
{
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NUMBER - 1)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *(tris_registers[port]) = direction;    
    }
    
    return ret;    
}

/**
 * @brief  This function used to get port direction.
 * @Author Ali Morsy.
 * @version 1.0.
 * @param  port index @ref  port_index_t.
 * @param  dir_status pointer to return PORT status.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8_t* dir_status)
{
    Std_ReturnType ret = E_OK;
    if (dir_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *dir_status = *(tris_registers[port]);
    }
    return ret;   
}

/**
 * @brief  This function used to toggle the logic for all pins in a specific port.
 * @Author Ali Morsy
 * @version 1.0 
 * @param port index @ref  port_index_t.
 * @param logic to apply this value on a port.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8_t logic)
{
    Std_ReturnType ret = E_OK;
    
    *(lat_registers[port]) = logic;
    
    return ret;   
}

/**
 * @brief  This function used to read logic on a port.
 * @Author Ali Morsy
 * @version 1.0
 * @param port index @ref  port_index_t.
 * @param logic pointer to return the port logic
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8_t* logic)
{
    Std_ReturnType ret = E_OK;
    if(logic == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *(lat_registers[port]);
    }
    return ret;   
}

/**
 * @brief  This function used to toggle the port logic.
 * @Author Ali Morsy.
 * @version 1.0.
 * @param port index @ref  port_index_t.
 * @return Std_ReturnType status of the function 
 *                         (E_OK) : the function done successfully.
 *                         (E_NOT_OK) : the function done not successfully.
 */
Std_ReturnType gpio_port_toggle_logic(port_index_t port)
{
     Std_ReturnType ret = E_OK;
    *(lat_registers[port]) = (*(lat_registers[port])) ^ 0xFF;
    return ret;   
}

