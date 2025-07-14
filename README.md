# CH32V003_lib_i2c          Ver 5.x Prototype

## Library Description
`lib_i2c` is a fully featured, but lightweight library for the I2C peripheral
on the CH32V003 with the following features:
* Support for All 3 Alternative Pinouts
* Support 7-bit Addresses (7-bit aligned, eg `0bx1101000 - 0x68`)
* Support 8-bit Registers
* Up to 1MHz Bus Frequency has been tested. Can be set higher.
* Easy to use I2C Error Status'
* Funcion to Scan the Interface for devices
* Master Mode Only

Based on [CNLohr's ch32fun](https://github.com/cnlohr/ch32fun)


## Changelog
* `v5.2` - Refactored a few things to be more efficient, added support for 10Bit
           Addresses
* `v5.0` - Added Multi-Byte Register support (up to 4 bytes) with config in i2c_device_t  
           Changed init() to use the device pointer, multiple devices can still be used at once  
           Added read & write raw functions - without use of registers
* `v4.3` - Began refactor to allow 7bit, 10bit and 16bit addresses. Only supports 7bit currently
* `v4.2` - Protected most loops with timeout and error propegation
* `v4.1` - Added i2c_wait to simplify waiting for bus to be free
* `v4.0` - Refactored using inlined functions for expandability (i2c_start(), i2c_stop() etc)
* `v3.5` - Converted from ch32v003fun to ch32fun
* `v3.4` - Fixed an off-by-one error in i2c_read


## TODO
* Add 10bit and 16bit Address Support - need to do lots of research
* Test on other MCU Variants:
	* CH32V003 ✔️


## Thanks
Thank you [niansa](https://github.com/niansa) for continued help refining the library  
Thank you [Johannes JKT](https://github.com/DeadBugEngineering) for fixing an i2c_read off_by_one bug  

If you want to use ANY pins for I2C, see [lib_swi2c](https://github.com/ADBeta/CH32Vxxx_lib_swi2c)

----
Copyright (c) 2024 - 2025 ADBeta
