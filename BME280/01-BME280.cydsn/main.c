/*
*   \file main.c
*   \brief Main source file for the BME280 Example Project.
*
*   This file represents the main source file used for the 01-BME280
*   PSoC Creator project. It shows how to interact with the BME280
*   APIs and sends data over UART.
*
*   \author Davide Marzorati
*   \date October 25, 2019
*/

#include "BME280.h"
#include "BME280_I2C_Interface.h"
#include "BME280_RegMap.h"
#include "project.h"
#include "stdio.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    I2C_Master_Start();
    UART_Debug_Start();
    
    UART_Debug_PutString("************************\r\n");
    UART_Debug_PutString("          BME280        \r\n");
    UART_Debug_PutString("************************\r\n");
    
    char message[50];
    
    for (int i = 0; i < 128; i++)
    {
        if (BME280_I2C_Interface_IsDeviceConnected(i) == BME280_CONNECTED)
        {
            sprintf(message, "Device 0x%02X connected\r\n", i);
            UART_Debug_PutString(message);
        }
        
    }
    
    if (BME280_Start() == BME280_OK)
    {
        UART_Debug_PutString("Sensor was initialized properly\r\n");
        
    }
    
    
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
