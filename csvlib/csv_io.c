
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
#include <stdbool.h>

#define CSV_FILE_PATH "../UI/data.csv"
#define SIZEOFBUFFER 100

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

    fclose(file);
    return -1;
}

void csv_setInt(const char *key, int value)
{
    // Read file
    if (key == NULL || strlen(key) == 0)
    {
        return;
    }

    FILE *file = fopen(CSV_FILE_PATH, "r");
    if (file == NULL)
    {
        printf("Can not open data.csv !\n");
        return;
    }

    int key_len = strlen(key);

    static char line[20][SIZEOFBUFFER];

    size_t line_count = 0;
    while (fgets(line[line_count], SIZEOFBUFFER, file) != NULL && line_count < 20)
    {
        line_count++;
    }

    fclose(file);

    // Modified copied file
    bool key_found = false;
    for (size_t i = 0; i < line_count; i++)
    {
        if (strncmp(line[i], key, key_len) == 0 && line[key_len] ==',')
        {
            snprintf(line[i], SIZEOFBUFFER, "%s,%d\n", key, value);
            key_found = true;
            break;
        }
    }
    if (!key_found)
    {
        printf("Key is invalid !\n");
        return;
    }


    // Write copied file into file
    file = fopen(CSV_FILE_PATH, "w");
    if (file == NULL)
    {
        printf("Can not open data.csv !\n");
        return;
    }
    for (int i = 0; i < line_count; i++)
    {
        fputs(line[i], file);
    }
    fclose(file);

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