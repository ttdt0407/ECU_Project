#include "Adc.h"
#include <stdint.h>
#include <stdio.h>
/********************************************************
 * @file        Adc.c
 * @brief       Simulate reading analog sensor values
 * @details     This file implements functions for reading
 *              sensor data from CSV simulation file
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 *********************************************************/

void Adc_Init(void)
{
    printf("The adc channel is initialized successfully\n");
}



uint16_t Adc_ReadChannel(uint8_t channelId)
{
    static uint16_t arr[5];
    arr[0] = csv_getInt("temp");
    arr[1] = csv_getInt("voltage");
    arr[2] = csv_getInt("current");
    arr[3] = csv_getInt("torque");
    arr[4] = csv_getInt("rpm");

    switch(channelId)
    {
        case 0:
            return arr[0];
        case 1:
            return arr[1];
        case 2:
            return arr[2];
        case 3:
            return arr[3];
        case 4:
            return arr[4];
        default:
            printf("Invalid channel!\nTry again\n");
            return 0;
    }

}