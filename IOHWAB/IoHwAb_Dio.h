#ifndef IOHWAB_DIO_H
#define IOHWAB_DIO_H

#include <stdint.h>

/********************************************************
 * @file        IoHwAb_Dio.h
 * @brief       Digital I/O Hardware Abstraction Layer declarations
 * @details     This file provides function declarations for
 *              digital input/output control operations
 * @version     1.0
 * @date        2025-08-15
 * @author      Ta Tran Dinh Tien
 *********************************************************/

typedef enum {
    DIO_OK = 0,
    DIO_ERROR = 1
} Std_ReturnType;

/***************************************************************************
 * @brief   Read digital direction signal
 * @details This function reads current direction value from digital channel 0
 * @param   channelId - Channel identifier (only channel 0 supported)
 * @param   direction_dio - Pointer to store direction value (0 or 1)
 * @return  Std_ReturnType - DIO_OK if successful, DIO_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_ReadDirection(uint8_t channelId, uint8_t *direction_dio);

/***************************************************************************
 * @brief   Set digital direction signal
 * @details This function sets direction value on digital channel 0
 * @param   channelId - Channel identifier (only channel 0 supported)
 * @param   level - Direction value to set (0 or 1)
 * @return  Std_ReturnType - DIO_OK if successful, DIO_ERROR if parameters invalid
 ***************************************************************************/
Std_ReturnType IoHwAb_SetDirection(uint8_t channelId, int level);

#endif