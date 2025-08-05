#include "Dio.h"
#include <stdint.h>
#include <stdio.h>
/********************************************************
 * @file        Dio.c
 * @brief       Implementation of digital I/O funtions
 * @details     Implementation 2 functions that
 *              simulate digital signal control
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 *********************************************************/

void Dio_Init(void)
{
    printf("Dio channel initialized successfully\n");
}

void Dio_WriteChannel(uint8_t channelId, int level)
{   
    if (channelId != 0)
    {
        printf("Invalid channel ID !\n");
        return;
    }
    csv_setInt("direction", level);
    printf("Set direction to %d\n", level);
}