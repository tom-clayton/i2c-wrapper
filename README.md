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

Some useful helper functions are provided for common i2c tasks:

```C
static inline int i2c_write_reg(const i2c_bus_t *bus, uint8_t reg, uint8_t data)
static inline int i2c_read_reg(const i2c_bus_t *bus, uint8_t reg, uint8_t *out)
static inline void u16_to_le(uint16_t v, uint8_t *low, uint8_t *high)
static inline uint16_t le_to_u16(uint8_t low, uint8_t high)
static inline void u16_to_be(uint16_t v, uint8_t *high, uint8_t *low)
static inline uint16_t be_to_u16(uint8_t high, uint8_t low)
```
