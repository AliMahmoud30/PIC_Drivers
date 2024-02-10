/* 
 * File:  std_libraries.h
 * Author: ali morsy
 *
 * Created on June 30, 2023, 10:12 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* Section: Includes */
#include "std_libraries.h"
#include "compiler.h"


/* Section: Data Type Declarations */
typedef unsigned char        uint8_t;
typedef unsigned short       uint16_t;
typedef unsigned long        uint32_t;
typedef unsigned long long   uint64_t;

typedef signed char          sint8_t;
typedef signed short         sint16_t;
typedef signed long          sint32_t;
typedef signed long long     sint64_t;

/* Section: Macro Declarations */
#define STD_HIGH            0X01
#define STD_LOW             0X00

#define STD_ON              0X01
#define STD_OFF             0X00

#define STD_ACTIVE          0X01
#define STD_IDLE            0X00
 

typedef uint8_t     Std_ReturnType;

#define E_OK                (Std_ReturnType)0X01
#define E_NOT_OK            (Std_ReturnType)0X00

#define ZERO_INIT       0
/* Section: Macro Function Declarations */


/* Section: Function Declarations */

#endif	/* STD_TYPES_H */

