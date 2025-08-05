#ifndef DIO_H
#define DIO_H

#include "../../csvlib/csv_io.h"
#include <stdint.h>

/********************************************************
 * @file        Dio.h
 * @brief       Declarations of digital I/O functions
 * @details     This file provides 2 declared functions that
 *              simulate control digital signal
 *              
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 * 
 *********************************************************/

/***************************************************************************
 * @brief   Declare channels
 * @details Declare channels that control digital (print out log)
 * @param   void
 * @return  void
 ***************************************************************************/
void Dio_Init(void);

/***************************************************************************
 * @brief   Write digital into channel (channel 0)
 * @details This function writes digital value (0 or 1) into channel 0
 * @param   channelId
 * @param   level
 * @return  void
 ***************************************************************************/
void Dio_WriteChannel(uint8_t channelId, int level);

#endif