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
#include <stddef.h>

/*
 * i2c_bus_t: A structure representing an I2C bus interface.
 */
typedef struct i2c_bus{
  int (*i2c_write)(const uint8_t *buf, size_t len);
  int (*i2c_write_read)(uint8_t reg, uint8_t *out, size_t out_len);
} i2c_bus_t;

/*
 * i2c_write_reg: Helper function to write a single byte to an I2C register.
 */
static inline int i2c_write_reg(const i2c_bus_t *bus, uint8_t reg, uint8_t data)
{
	uint8_t buf[2] = { reg, data };
	return bus->i2c_write(buf, sizeof(buf));
}

/*
 * i2c_read_reg: Helper function to read a single byte from an I2C register.
 */
static inline int i2c_read_reg(const i2c_bus_t *bus, uint8_t reg, uint8_t *out)
{    
  return bus->i2c_write_read(reg, out, 1);
}

/*
 * u16_to_le: Helper function to convert a 16-bit unsigned integer to little-endian byte order.
 */
static inline void u16_to_le(uint16_t v, uint8_t *low, uint8_t *high)
{
	*low  = (uint8_t)(v & 0xFF);
	*high = (uint8_t)((v >> 8) & 0xFF);
}

/*
 * le_to_u16: Helper function to convert little-endian bytes to a 16-bit unsigned integer.
 */
static inline uint16_t le_to_u16(uint8_t low, uint8_t high)
{
	return ((uint16_t)high << 8) | low;
}

/*
 * u16_to_be: Helper function to convert a 16-bit unsigned integer to big-endian byte order.
 */
static inline void u16_to_be(uint16_t v, uint8_t *high, uint8_t *low)
{
	*high = (uint8_t)((v >> 8) & 0xFF);
	*low  = (uint8_t)(v & 0xFF);
}

/*
 * be_to_u16: Helper function to convert big-endian bytes to a 16-bit unsigned integer.
 */
static inline uint16_t be_to_u16(uint8_t high, uint8_t low)
{
	return ((uint16_t)high << 8) | low;
}


#endif /* I2C_BUS_H */