/* 
 * File:   ecu_dc_motor.h
 * Author: ali morsy
 *
 * Created on November 24, 2023, 5:12 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section: Includes */
#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_dc_motor_cfg.h"

/* Section: Macro Declarations */

#define MOTOR_PIN_1     0x00U
#define MOTOR_PIN_2     0x01U
/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
typedef enum
{
    DC_MOTOR_OFF,
    DC_MOTOR_ON
}dc_motor_status_t;

typedef struct
{
   pin_config_t dc_motor_pin[2]; 
}dc_motor_t;

/* Section: Function Declarations */
Std_ReturnType dc_motor_initialize(const dc_motor_t* _dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t* _dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t* _dc_motor);
Std_ReturnType dc_motor_stop(const dc_motor_t* _dc_motor);

#endif	/* ECU_DC_MOTOR_H */

