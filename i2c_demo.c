/******************************************************************************
* Basic Example of using lib_i2c on the CH32V003 Microcontroller
*
* Connections:
* 	SDA -> PC1
* 	SCL -> PC2
*
* Demo Version 3.0-p    12 July 2025 
* See GitHub Repo for more information: 
* https://github.com/ADBeta/CH32V003_lib_i2c
*
* Released under the MIT Licence
* Copyright ADBeta (c) 2024 - 2025
******************************************************************************/
#include "ch32fun.h"
#include "lib_i2c.h"

#include <stdio.h>

#define I2C_ADDR 0x68

// I2C Scan Callback example function. Prints the address which responded
void i2c_scan_callback(const uint8_t addr)
{
	printf("Address: 0x%02X Responded.\n", addr);
}

int main() 
{
	SystemInit();

	// NOTE: Please test this multi-byte register stuff
	// Create a Device Struct 
	// Clock Speed in Hz
	// I2C Address type (only 7bit supported currently
	// Use the address defined above
	// The Register/Command portion of comms is 2 bytes
	i2c_device_t dev = {
		.clkr = I2C_CLK_400KHZ,
		.type = I2C_ADDR_7BIT,
		.addr = I2C_ADDR,
		.regb = 2,
	};

	// Initialise the I2C Interface for this device
	if(i2c_init(&dev) != I2C_OK) printf("Failed to init the I2C Bus\n");


	// NOTE: Removed for prototype testing
	/*
	// Initialising I2C causes the pins to transition from LOW to HIGH.
	// Wait 100ms to allow the I2C Device to timeout and ignore the transition.
	// Otherwise, an extra 1-bit will be added to the next transmission
	Delay_Ms(100);

	// Scan the I2C Bus, prints any devices that respond
	printf("----Scanning I2C Bus for Devices---\n");
	i2c_scan(i2c_scan_callback);
	printf("----Done Scanning----\n\n");

	*** Example ***
	// This example is specifically for the DS3231 I2C RTC Module.
	// Use this as an example for generic devices, changing Address, speed etc
	i2c_err_t i2c_stat;

	// Write to the -Seconds- Register (Reg 0x00, 0x00 Seconds, one byte)
	i2c_stat = i2c_write_reg(&dev, 0x00, (uint8_t[]){0x00}, 1);
	if(i2c_stat != I2C_OK) { printf("Error Using the I2C Bus\n"); return -1; }


	// Example of writing an array to a register.
	uint8_t array[3] = {0x00, 0x01, 0x02};
	i2c_stat = i2c_write_reg(&dev, 0x00, array, 3);
	if(i2c_stat != I2C_OK) { printf("Error Using the I2C Bus\n"); return -1; }


	// Example to read from the I2C Device
	uint8_t seconds = 0;    // Just Seconds (Read as Hex instead od Decimal)
	uint8_t time[3] = {0};  // Time in Sec, Min, Hrs (Hex not Decimal)
	while(1)
	{
		// Example reading just one byte
		i2c_stat = i2c_read_reg(&dev, 0x00, &seconds, 1);
		if(i2c_stat != I2C_OK) printf("Error Using the I2C Bus\n");
		// Print Seconds as a single hex byte
		printf("Seconds: %02X\n", seconds);

		
		// Example reading multiple bytes
		i2c_stat = i2c_read_reg(&dev, 0x00, time, 3);
		if(i2c_stat != I2C_OK) printf("Error Using the I2C Bus\n");
		// Print Time as Hrs Min Sec
		printf("Time: %02X:%02X:%02X\n\n", time[2], time[1], time[0]);


		// Wait 1 Second
		Delay_Ms(1000);
	}
	*/
}
