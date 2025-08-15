#include "IoHwAb_Pwm.h"
#include "MCAL/Pwm/Pwm.h"
#include <stdio.h>
#include <stdint.h>


Std_ReturnType IoHwAb_ReadDuty(uint8_t channelId, uint16_t *duty) {
    if (duty == NULL)
    {
        printf("Duty cycle is error !\n Please check\n");
        return PWM_ERROR;
    }
    *duty = Pwm_GetDutyCycle(channelId);
    return PWM_OK;
}

Std_ReturnType IoHwAb_SetDuty(uint8_t channelId, uint16_t duty) {
    if (channelId != 0 || duty < 0)
    {
        printf("Set duty cycle is error !\n");
        return PWM_ERROR;
    }
    Pwm_SetDutyCycle(channelId, duty);
    return PWM_OK;
}
