
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


int csv_getInt(const char* key)
{
    // Input validation
    if (key == NULL || strlen(key) == 0) {
        return -1;
    }

    // Open CSV file for reading
    FILE *file = fopen(CSV_FILE_PATH, "r");
    
    if (file == NULL)
    {
        printf("Can not open data.csv\n");
        printf("Please check the path: %s", CSV_FILE_PATH);
        return -1;
    }

    // Parse each line to find matching key
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


void csv_setInt(const char *key, int value)
{

}   

const char *csv_getString(const char *key)
{
    // Input Validation
    if (key == NULL || strlen(key) == 0)
    {
        return NULL;
    }

    // Cache key length for performance
    int key_len = strlen(key);

    // Open CSV file
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

            // Close file and return pointer to value
            fclose(file);
            return line + key_len + 1;
        }
    }

    // Close file and return in case that key not found
    fclose(file);
    return NULL;
}