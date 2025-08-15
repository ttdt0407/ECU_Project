#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include <stdint.h>

/********************************************************
 * @file        IoHwAb_Adc.h
 * @brief       ADC Hardware Abstraction Layer declarations
 * @details     This file provides function declarations for
 *              sensor reading with ADC conversion to physical units
 * @version     1.0
 * @date        2025-08-15
 * @author      Ta Tran Dinh Tien
 *********************************************************/

typedef enum
{
    ADC_OK = 0,
    ADC_ERROR = 1
} Std_ReturnType;

/***************************************************************************
 * @brief   Read temperature sensor
 * @details This function reads temperature from ADC channel 0 and converts to Celsius
 * @param   temp_adc - Pointer to store raw ADC value (0-4095)
 * @param   temp_C - Pointer to store temperature in Celsius (0-200°C)
 * @return  Std_ReturnType - ADC_OK if successful, ADC_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadTemp(uint16_t *temp_adc, float *temp_C);

/***************************************************************************
 * @brief   Read voltage sensor
 * @details This function reads voltage from ADC channel 1 and converts to Volts
 * @param   voltage_adc - Pointer to store raw ADC value (0-4095)
 * @param   voltage_V - Pointer to store voltage in Volts (0-60V)
 * @return  Std_ReturnType - ADC_OK if successful, ADC_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadVoltage(uint16_t *voltage_adc, float *voltage_V);

/***************************************************************************
 * @brief   Read current sensor
 * @details This function reads current from ADC channel 2 and converts to Amperes
 * @param   current_adc - Pointer to store raw ADC value (0-4095)
 * @param   current_A - Pointer to store current in Amperes (0-50A)
 * @return  Std_ReturnType - ADC_OK if successful, ADC_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadCurrent(uint16_t *current_adc, float *current_A);

/***************************************************************************
 * @brief   Read torque sensor
 * @details This function reads torque from ADC channel 3 and converts to Newton-meters
 * @param   torque_adc - Pointer to store raw ADC value (0-4095)
 * @param   torque_Nm - Pointer to store torque in Newton-meters (0-120Nm)
 * @return  Std_ReturnType - ADC_OK if successful, ADC_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadTorque(uint16_t *torque_adc, float *torque_Nm);

/***************************************************************************
 * @brief   Read RPM sensor
 * @details This function reads RPM from ADC channel 4 (returns raw ADC value)
 * @param   rpm - Pointer to store raw ADC value representing RPM
 * @return  Std_ReturnType - ADC_OK if successful, ADC_ERROR if parameter invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadRpm(uint16_t *rpm);
#endif