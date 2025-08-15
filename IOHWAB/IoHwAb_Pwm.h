#ifndef IOHWAB_PWM_H
#define IOHWAB_PWM_H

#include <stdint.h>

/********************************************************
 * @file        IoHwAb_Pwm.h
 * @brief       PWM Hardware Abstraction Layer declarations
 * @details     This file provides function declarations for
 *              PWM duty cycle control operations
 * @version     1.0
 * @date        2025-08-15
 * @author      Ta Tran Dinh Tien
 *********************************************************/

typedef enum
{
    PWM_OK = 0,
    PWM_ERROR = 1
} Std_ReturnType;

/***************************************************************************
 * @brief   Read current PWM duty cycle
 * @details This function reads current duty cycle value from PWM channel 0
 * @param   channelId - Channel identifier (only channel 0 supported)
 * @param   duty - Pointer to store current duty cycle value (0-100)
 * @return  Std_ReturnType - PWM_OK if successful, PWM_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadDuty(uint8_t channelId, uint16_t *duty);

/***************************************************************************
 * @brief   Set PWM duty cycle
 * @details This function sets duty cycle value on PWM channel 0
 * @param   channelId - Channel identifier (only channel 0 supported)
 * @param   duty - Duty cycle value to set (0-100)
 * @return  Std_ReturnType - PWM_OK if successful, PWM_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_SetDuty(uint8_t channelId, uint16_t duty);
#endif