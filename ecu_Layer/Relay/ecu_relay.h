/* 
 * File:   ecu_relay.h
 * Author: alimo
 *
 * Created on November 18, 2023, 1:32 AM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H
#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_relay_cfg.h"



/* Section: Includes */

/* Section: Macro Declarations */

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
typedef enum
{
    RELAY_OFF,
    RELAY_ON
}relay_state_t;

typedef struct
{
    uint8_t      relay_port : 3;
    uint8_t      relay_pin  : 3;
    uint8_t      relay_status: 1;
    uint8_t      reserved   : 1;
}relay_t;

/* Section: Function Declarations */

Std_ReturnType relay_initialization(const relay_t* relay);
Std_ReturnType relay_turn_on(const relay_t* relay);
Std_ReturnType relay_turn_off(const relay_t* relay);

#endif	/* ECU_RELAY_H */

