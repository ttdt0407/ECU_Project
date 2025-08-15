#include "IoHwAb_Dio.h"
#include "MCAL/Dio/Dio.h"
#include <stdio.h>
#include <stdint.h>

Std_ReturnType IoHwAb_SetDirection (uint8_t channelId, int level){
    if (channelId != 0 || (level != 0 && level != 1))
    {
        printf("Set direction is error !\nInvalid parameters !\n");
        return DIO_ERROR;
    }
    Dio_WriteChannel(channelId, level);
    return DIO_OK;
}

Std_ReturnType IoHwAb_ReadDirection (uint8_t channelId, uint8_t *direction_dio)
{
    if (channelId != 0 || direction_dio == NULL)
    {
        printf("Read direction is error !\n Invalid parameters !\n");
        return DIO_ERROR;
    }
    *direction_dio = Dio_ReadChannel(channelId);
    return DIO_OK;
}