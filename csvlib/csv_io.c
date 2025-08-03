
/***************************************************************************
 * @file    csv_io.c
 * @brief   Implementation of CSV read/write functions for MCAL modules
 * @details This file implements CSV key-value API functions used by all 
 *          MCAL modules. Acts as a bridge for MCAL to access or update 
 *          simulation data
 * @version 1.0
 * @date    2025-08-03
 * @author  Ta Tran Dinh Tien
 ***************************************************************************/
#include "csv_io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CSV_FILE_PATH "../UI/data.csv"
#define SIZEOFBUFFER 100


/***************************************************************************
 * @brief   Get integer value corresponding to the key from CSV file
 * @details This function opens the CSV file, searches for the specified key,
 *          and returns the corresponding integer value. Input validation is
 *          performed to ensure key validity.
 * @param   key     Key values such as duty, direction, or sensor data (temp, voltage, current, torque, rpm)
 * @return  int     Integer value corresponding to the key, or -1 if not found
 ***************************************************************************/
int csv_getInt(const char* key)
{
    // Input validation
    if (key == NULL || strlen(key) == 0) {
        return -1;
    }

 
    FILE *file = fopen(CSV_FILE_PATH, "r");
    
    if (file == NULL)
    {
        printf("Can not open data.csv\n");
        printf("Please check the path: %s", CSV_FILE_PATH);
        return -1;
    }

 
    char line[SIZEOFBUFFER];
    while (fgets(line, SIZEOFBUFFER, file)){
        // Check if line starts with the key followed by comma
        if (strncmp(line, key, strlen(key)) == 0 && line[strlen(key)] == ',')
        {
            // Extract value after comma and convert to integer
            int value = atoi(line + strlen(key) + 1);
            fclose(file);
            return value;
        }
    }
    
    // Close file and return not found
    fclose(file);
    return -1;
}


/***************************************************************************
 * @brief   Write integer value to CSV file for the specified key
 * @details This function updates the value of an existing key in the CSV file.
 *          If the key doesn't exist, it will be added to the file.
 * @param   key     Key name to write the value to
 * @param   value   Integer value to be written for the corresponding key
 * @return  void
 ***************************************************************************/
void csv_setInt(const char *key, int value)
{

}   


/***************************************************************************
 * @brief   Read string value from CSV file (mainly used for CAN frame data)
 * @details This function reads string values from CSV file, particularly designed
 *          for CAN frame data which contains hexadecimal values and spaces.
 * @param   key     Key name to read the string value from
 * @return  const char* Pointer to the string value, or NULL if not found
 ***************************************************************************/
const char *csv_getString(const char *key)
{
    // Input Validation
    if (key == NULL || strlen(key) == 0)
    {
        return NULL;
    }

    // Cache key length for performance
    int key_len = strlen(key);

    FILE *file = fopen(CSV_FILE_PATH, "r");
    if (file == NULL)
    {
        printf("Can not open data.csv\n");
        printf("Please check the path: %s", CSV_FILE_PATH);
        return NULL;
    }

    // Static buffer for return value
    static char line[SIZEOFBUFFER];

    // Search for key in each line
    while (fgets(line, SIZEOFBUFFER, file) != NULL)
    {   
        // Check if line starts with key followed by comma
        if (strncmp(line, key, key_len) == 0 && line[key_len] == ',')
        {   
            // Remove trailing newline if present
            char *newline = strchr(line, '\n');
            if (newline)
            {
                *newline = '\0';
            }   

          
            fclose(file);
            return line + key_len + 1;
        }
    }

    fclose(file);
    return NULL;
}