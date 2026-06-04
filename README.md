# i2c_wrapper

A wrapper that allows i2c drivers to be controlled by any native micro-controller code or high level framework.

### Usage

Include the header, define the functions and the structure, then pass the structure to the driver.

```C
typedef struct i2c_bus{
  uint8_t (*i2c_read_reg)(uint8_t reg, uint8_t *data);
  uint8_t (*i2c_write_reg)(uint8_t reg, uint8_t data);
} i2c_bus_t;
```

### Example

This example allows zephyr code to control a driver:

```C
/*
 *  I2C read register function.
 */

uint8_t i2c_read_reg(uint8_t reg, uint8_t *data)
{
    return i2c_reg_read_byte(dev_i2c.bus, dev_i2c.addr, reg, data);
}

/*
 * I2C write register function.
 */

uint8_t i2c_write_reg(uint8_t reg, uint8_t data)
{
    return i2c_reg_write_byte(dev_i2c.bus, dev_i2c.addr, reg, data); 
}

/*
 * I2C wrapper struct.
 */

static const i2c_bus_t i2c_bus = {
  .i2c_read_reg = i2c_read_reg,
  .i2c_write_reg = i2c_write_reg,
};
```