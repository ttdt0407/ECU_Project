#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MCAL/Dio/Dio.h"
#include "MCAL/Pwm/Pwm.h"
#include "MCAL/Adc/Adc.h"
#include "MCAL/Can/Can.h"

#include "IOHWAB/IoHwAb_Adc.h"
#include "IOHWAB/IoHwAb_Dio.h"
#include "IOHWAB/IoHwAb_Pwm.h"


/******************______Application for period 1______***********************
******************************************************************************
int main(void)
{
    printf("/==================Initialized MCAL driver==================/\n");
    Dio_Init();
    Pwm_Init();
    Adc_Init();
    Can_Init();
    printf("/===========================================================/\n");
    
    Dio_WriteChannel(0, -1);
    Pwm_SetDutyCycle(0, 99);

    printf("Temp, voltage, current, torque, rpm is respectively:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", Adc_ReadChannel(i));
    }
    printf("\n");
    uint32_t canId;
    uint8_t data[8];
    uint8_t dlc;
    Can_Receive(&canId, data, &dlc);
    printf("CAN ID: %d\n", canId);
    printf("CAN DLC: %d\n", dlc);
    printf("CAN DATA: ");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%d ", data[i]);
    }
}
*******************************************************************************
*******************************************************************************/


