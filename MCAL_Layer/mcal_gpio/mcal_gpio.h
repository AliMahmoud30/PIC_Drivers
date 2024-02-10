/* 
 * File:   mcal_gpio.h
 * Author: alimo
 *
 * Created on June 30, 2023, 5:49 PM
 */

#ifndef MCAL_GPIO_H
#define	MCAL_GPIO_H

/* Section: Includes */
#include "../proc/pic18f4620.h"
#include "../Device_config.h"
#include "../mcal_std_types.h"


/* Section: Macro Declarations */
#define BIT_MASK    (uint8_t)1

#define PORT_PIN_MAX_NUMBER     8
#define PORT_MAX_NUMBER         5

/* Section: Macro Function Declarations */
#define HW_REG(_X)         (*((volatile uint8_t*)(_X)))

#define SET_BIT(REG,BIT_POSN)           (REG |= BIT_MASK << BIT_POSN)
#define CLR_BIT(REG,BIT_POSN)           (REG &= ~(BIT_MASK << BIT_POSN))
#define TOG_BIT(REG,BIT_POSN)           (REG ^= BIT_MASK << BIT_POSN)
#define GET_BIT(REG,BIT_POSN)           ((REG >>BIT_POSN)&BIT_MASK)

/* Section: Data Type Declarations */

typedef enum
{
    GPIO_LOW=0,
    GPIO_HIGH
}logic_t;

typedef enum
{
    OUTPUT=0,
    INPUT
}direction_t;

typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,    
}pin_index_t;

typedef enum
{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct 
{
    uint8_t port      :3; /* @ref  port_index_t*/
    uint8_t pin       :3; /* @ref  pin_index_t*/
    uint8_t direction :1; /* @ref  direction_t*/
    uint8_t logic     :1; /* @ref  logic_t*/
}pin_config_t;

/* Section: Function Declarations */
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config, direction_t* dir_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config, logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config, logic_t* logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config);

Std_ReturnType gpio_port_direction_initialize(port_index_t port, uint8_t direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8_t* dir_status);
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8_t logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8_t* logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);


#endif	/* MCAL_GPIO_H */

