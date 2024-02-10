/* 
 * File:   ecu_seven_segment.h
 * Author: ali.morsy
 *
 * Created on January 29, 2024, 11:55 PM
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H


/* Section: Includes */

#include "../../MCAL_Layer/mcal_gpio/mcal_gpio.h"
#include "ecu_seven_segment_cfg.h"


/* Section: Macro Declarations */

#define SEGMENT_PIN0    (uint8_t)0
#define SEGMENT_PIN1    (uint8_t)1
#define SEGMENT_PIN2    (uint8_t)2
#define SEGMENT_PIN3    (uint8_t)3

/* Section: Macro Function Declarations */

/* Section: Data Type Declarations */
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE,
}segment_type_t;

typedef struct
{
    pin_config_t      segment_pins[4];
    segment_type_t    segment_type;
}seven_segment_t;

/* Section: Function Declarations */
Std_ReturnType seven_segment_initialization(const seven_segment_t* seven_segment_ptr);
Std_ReturnType seven_segment_display(const seven_segment_t* seven_segment_ptr, uint8_t number);




#endif	/* ECU_SEVEN_SEGMENT_H */

