#include "IoHwAb_Adc.h"
#include "MCAL/Adc/Adc.h"
#include <stdio.h>
#include <stdint.h>

#define ADC_MAX 4095.0f
#define TEMP_MAX 200.0f
#define VOLT_MAX 60.0f
#define CURR_MAX 50.0f
#define TOR_MAX 120.0f

Std_ReturnType IoHwAb_ReadTemp(uint16_t *temp_adc, float *temp_C) {
    if (temp_adc == NULL || temp_C == NULL){
        printf("Temperature value is invalid !\n");
        return ADC_ERROR;
    }
    *temp_adc = Adc_ReadChannel(0);
    *temp_C = ((float)*temp_adc / ADC_MAX) * TEMP_MAX;
    return ADC_OK;
}

Std_ReturnType IoHwAb_ReadVoltage(uint16_t *voltage_adc, float *voltage_V) {
    if (voltage_adc == NULL || voltage_V == NULL)
    {
        printf("Voltage value is invalid !\n");
        return ADC_ERROR;
    }
    *voltage_adc = Adc_ReadChannel(1);
    *voltage_V = (*voltage_adc / ADC_MAX) * VOLT_MAX;
    return ADC_OK;
}

Std_ReturnType IoHwAb_ReadCurrent(uint16_t *current_adc, float *current_A) {
    if (current_adc == NULL || current_A == NULL)
    {
        printf("Current value is invalid !\n");
        return ADC_ERROR;
    }
    *current_adc = Adc_ReadChannel(2);
    *current_A = (*current_adc / ADC_MAX) * CURR_MAX;
    return ADC_OK;
}

Std_ReturnType IoHwAb_ReadTorque(uint16_t *torque_adc, float *torque_Nm) {
    if (torque_adc == NULL || torque_Nm == NULL)
    {
        printf("Torque value is invalid !\n");
        return ADC_ERROR;
    }
    *torque_adc = Adc_ReadChannel(3);
    *torque_Nm = (*torque_adc / ADC_MAX) * TOR_MAX;
    return ADC_OK;
}

Std_ReturnType IoHwAb_ReadRpm(uint16_t *rpm_adc) {
    if (rpm_adc == NULL)
    {
        printf("RPM is invalid !\n");
        return ADC_ERROR;
    }
    *rpm_adc = Adc_ReadChannel(4);
    return ADC_OK;
}
