#include "Pwm.h"
#include <stdint.h>
#include <stdio.h>
/********************************************************
 * @file        Pwm.c
 * @brief       Simulate changing speed of motor (duty cycle)    
 * @details     This file implements 2 functions about changing
 *              the speed of motor by changing duty cycle              
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 * 
 *********************************************************/

void Pwm_Init(void)
{
    printf("The pwm channel is initialized successfully\n");
}



void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty)
{   
    if (channelId != 0)
    {
        printf("Invalid channel ID !\n");
        return;
    }
    if (duty > 100)
    {
        printf("Invalid duty value !\n");
        return;
    }
    csv_setInt("duty", duty);
    printf("Set duty cycle to %d\n", duty);
}
uint8_t Pwm_GetDutyCycle(uint8_t channelId){
    if (channelId != 0)
    {
        printf("Channel ID is invalid !");
        return 0;
    }
    return csv_getInt("duty");
}
