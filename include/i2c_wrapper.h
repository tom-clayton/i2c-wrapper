/*
 * i2c_wrapper.h: I2C functions wrapper. 
 * 
 * A wrapper for an I2C bus interface, allowing I2C device drivers to work with any I2C implementation.
 * 
 * Tom Clayton 2025
 * 
 */

#ifndef I2C_BUS_H
#define I2C_BUS_H

#include <stdint.h>

/**
 * i2c_bus_t: A structure representing an I2C bus interface.
 */

typedef struct i2c_bus{
  uint8_t (*i2c_read_reg)(uint8_t reg, uint8_t *data);
  uint8_t (*i2c_write_reg)(uint8_t reg, uint8_t data);
} i2c_bus_t;

#endif /* I2C_BUS_H */