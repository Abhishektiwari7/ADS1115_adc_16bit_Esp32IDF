/**\
 * Copyright (c) 2021 Bosch Sensortec GmbH. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

/******************************************************************************/
#ifndef _COMMON_H
#define _COMMON_H

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif


/***************************************************************************/
#include <stdint.h> //int types
#include <stdlib.h>
#include <stdio.h>

#include "driver/gpio.h" //gpio
#include "driver/i2c.h" //i2c library
#include "esp_err.h" //error
#include "esp_log.h" //log

#define TAG_ADS1115 "I2C"
#define I2C_ADDR_PRIM 0x48 //address of i2c
#define SDA_GPIO 21
#define SCL_GPIO 22
/*!                 User function prototypes
 ****************************************************************************/
void i2c_master_init();
void i2cInit ();
void _delay_us(uint32_t period);
void i2c_deinit(void);
//-i2c---------
int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* _COMMON_H */
