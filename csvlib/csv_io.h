#ifndef CSV_IO_H
#define CSV_IO_H

/***************************************************************************
 * @file    csv_io.h
 * @brief   Declaration of CSV read/write functions for MCAL modules
 * @details This file provides interface for CSV key-value API functions used
 *          by all MCAL modules. Acts as a bridge for MCAL to access or update
 *          simulation data.
 * @version 1.0
 * @date    2025-08-03
 * @author  Ta Tran Dinh Tien
 ***************************************************************************/

/***************************************************************************
 * @brief   Get integer value corresponding to the key from CSV file
 * @details This function opens the CSV file, searches for the specified key,
 *          and returns the corresponding integer value. Input validation is
 *          performed to ensure key validity.
 * @param   key     Key values such as duty, direction, or sensor data (temp, 
 * voltage, current, torque, rpm)
 * @return  int     Integer value corresponding to the key, or -1 if not found
 ***************************************************************************/
int csv_getInt(const char *key);

/***************************************************************************
 * @brief   Write integer value to CSV file for the specified key
 * @details This function updates the value of an existing key in the CSV file.
 *          If the key doesn't exist, it will be added to the file.
 * @param   key     Key name to write the value to
 * @param   value   Integer value to be written for the corresponding key
 * @return  void
 ***************************************************************************/
void csv_setInt(const char *key, int value);

/***************************************************************************
 * @brief   Read string value from CSV file (mainly used for CAN frame data)
 * @details This function reads string values from CSV file, particularly designed
 *          for CAN frame data which contains hexadecimal values and spaces.
 * @param   key     Key name to read the string value from
 * @return  const char* Pointer to the string value, or NULL if not found
 ***************************************************************************/
const char *csv_getString(const char *key);

#endif