#ifndef PWM_H
#define PWM_H

#include "../../csvlib/csv_io.h"
#include <stdint.h>

/********************************************************
 * @file        Pwm.h
 * @brief       Simulate changing speed of motor (duty cycle)    
 * @details     This file declares 2 functions about changing
 *              the speed of motor by changing duty cycle              
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 * 
 *********************************************************/

/***************************************************************************
 * @brief   Initialize pwm
 * @details Initialize channels that control pwm (print out log)
 * @param   void
 * @return  void
 ***************************************************************************/
void Pwm_Init(void);

/***************************************************************************
 * @brief   Changes "duty" value
 * @details This function changes the value of "duty" in csv file
 * @param   channelId
 * @param   duty
 * @return  void
 ***************************************************************************/
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty);

#endif