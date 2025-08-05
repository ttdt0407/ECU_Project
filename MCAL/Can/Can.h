#ifndef CAN_H
#define CAN_H

#include "../../csvlib/csv_io.h"
#include <stdint.h>

/********************************************************
 * @file        Can.h
 * @brief       Simulate CAN communication protocol
 * @details     This file declares functions for CAN frame
 *              transmission and reception via CSV simulation
 * @version     1.0
 * @date        2025-08-04
 * @author      Ta Tran Dinh Tien
 *********************************************************/

// Standard return type for CAN operations
typedef enum {
    CAN_OK = 0,
    CAN_ERROR = 1
} Std_ReturnType;

/***************************************************************************
 * @brief   Initialize CAN communication
 * @details Initialize CAN controller for frame transmission/reception
 * @param   void
 * @return  void
 ***************************************************************************/
void Can_Init(void);

/***************************************************************************
 * @brief   Receive and parse CAN frame from CSV file
 * @details This function reads CAN frame data from CSV "can" key and
 *          parses it into CAN ID, data bytes, and data length
 * @param   canId   Pointer to store received CAN ID
 * @param   data    Pointer to array for storing data bytes (8 bytes max)
 * @param   dlc     Pointer to store data length code (0-8)
 * @return  Std_ReturnType  CAN_OK if successful, CAN_ERROR if failed
 ***************************************************************************/
Std_ReturnType Can_Receive(uint32_t* canId, uint8_t* data, uint8_t* dlc);

#endif
