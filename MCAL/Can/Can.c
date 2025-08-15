#include "Can.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>                                                         

/********************************************************
 * @file        Can.c
 * @brief       Simulate CAN communication protocol
 * @details     This file implements functions for CAN frame
 *              transmission and reception via CSV simulation
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 *********************************************************/

void Can_Init(void)
{
    printf("Can initialized succesfully\n");
}

Std_ReturnType Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc)
{
    if (canId == NULL || data == NULL || dlc == NULL)
    {
        printf("CAN receive parameter is not valid !\n");
        return CAN_ERROR;
    }
    const char *canString = csv_getString("can");
    if (canString == NULL)
    {
        printf("Failed to read CAN data from CSV!\n");
        return CAN_ERROR;
    }

    static char buffer[100];
    strncpy(buffer, canString, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *token = strtok(buffer, " ");
    if (token == NULL)
    {
        printf("Invalid CAN frame format ! - missing CAN ID\n");
        return CAN_ERROR;
    }
    *canId = (uint32_t)strtoul(token, NULL, 16);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        printf("Invalid CAN frame ! - missing CAN DLC\n");
        return CAN_ERROR;
    }
    *dlc = atoi(token);

    for (size_t i = 0; i < *dlc; i++)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            printf("Invalid CAN frame !- missing CAN %d DATA\n", i);
            return CAN_ERROR;
        }
        data[i] = (uint8_t)strtoul(token, NULL, 16);
    }

    // Delete if the data length code is less than 8 byte
    for (int i = *dlc; i < 8; i++)
    {
        data[i] = 0;
    }

    return CAN_OK;
}