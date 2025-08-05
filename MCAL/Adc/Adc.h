#ifndef ADC_H
#define ADC_H

#include "../../csvlib/csv_io.h"
#include <stdint.h>

/********************************************************
 * @file        Adc.h
 * @brief       Simulate reading analog sensor values
 * @details     This file declares functions for reading
 *              sensor data from CSV simulation file
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 *********************************************************/

/***************************************************************************
 * @brief   Initialize ADC channels
 * @details Initialize ADC channels for sensor reading (print out log)
 * @param   void
 * @return  void
 ***************************************************************************/
void Adc_Init(void);

/***************************************************************************
 * @brief   Read sensor value from specified channel
 * @details This function reads sensor values from CSV file based on channel ID
 * @param   channelId   Channel ID (0=temp, 1=voltage, 2=current, 3=torque, 4=rpm)
 * @return  uint16_t    Sensor value read from CSV file
 ***************************************************************************/
uint16_t Adc_ReadChannel(uint8_t channelId);

#endif