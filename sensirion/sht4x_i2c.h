/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.33.0
 * Product:       sht4x
 * Model-Version: 2.0.1
 */
/*
 * Copyright (c) 2023, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SHT4X_I2C_H
#define SHT4X_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"
#define SHT40_I2C_ADDR_44 0x44
#define SHT40_I2C_ADDR_45 0x45
#define SHT41_I2C_ADDR_44 0x44
#define SHT41_I2C_ADDR_45 0x45
#define SHT45_I2C_ADDR_44 0x44
#define SHT45_I2C_ADDR_45 0x45

typedef enum {
    MEASURE_HIGH_PRECISION_TICKS_CMD_ID = 0xfd,
    MEASURE_MEDIUM_PRECISION_TICKS_CMD_ID = 0xf6,
    MEASURE_LOWEST_PRECISION_TICKS_CMD_ID = 0xe0,
    ACTIVATE_HIGHEST_HEATER_POWER_LONG_TICKS_CMD_ID = 0x39,
    ACTIVATE_HIGHEST_HEATER_POWER_SHORT_TICKS_CMD_ID = 0x32,
    ACTIVATE_MEDIUM_HEATER_POWER_LONG_TICKS_CMD_ID = 0x2f,
    ACTIVATE_MEDIUM_HEATER_POWER_SHORT_TICKS_CMD_ID = 0x24,
    ACTIVATE_LOWEST_HEATER_POWER_LONG_TICKS_CMD_ID = 0x1e,
    ACTIVATE_LOWEST_HEATER_POWER_SHORT_TICKS_CMD_ID = 0x15,
    SERIAL_NUMBER_CMD_ID = 0x89,
    SOFT_RESET_CMD_ID = 0x94,
} cmd_id_t;

/**
 * @brief Initialize i2c address of driver
 *
 * @param[in] i2c_address Used i2c address
 *
 */
void sht4x_init(uint8_t i2c_address);

/**
 * @brief sht4x_measure_high_precision_ticks
 *
 * SHT4x command for a single shot measurement with high repeatability.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sht4x_measure_high_precision_ticks(uint16_t* temperature_ticks,
                                           uint16_t* humidity_ticks);

/**
 * @brief sht4x_measure_medium_precision_ticks
 *
 * SHT4x command for a single shot measurement with medium repeatability.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sht4x_measure_medium_precision_ticks(uint16_t* temperature_ticks,
                                             uint16_t* humidity_ticks);

/**
 * @brief sht4x_measure_lowest_precision_ticks
 *
 * SHT4x command for a single shot measurement with lowest repeatability.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sht4x_measure_lowest_precision_ticks(uint16_t* temperature_ticks,
                                             uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_highest_heater_power_long_ticks
 *
 * SHT4x command to activate highest heater power and perform a single shot high
 * precision measurement for 1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_highest_heater_power_long_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_highest_heater_power_short_ticks
 *
 * SHT4x command to activate highest heater power and perform a single shot high
 * precision measurement for 0.1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_highest_heater_power_short_ticks(uint16_t* temperature_ticks,
                                                uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_medium_heater_power_long_ticks
 *
 * SHT4x command to activate medium heater power and perform a single shot high
 * precision measurement for 1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_medium_heater_power_long_ticks(uint16_t* temperature_ticks,
                                              uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_medium_heater_power_short_ticks
 *
 * SHT4x command to activate medium heater power and perform a single shot high
 * precision measurement for 0.1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_medium_heater_power_short_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_lowest_heater_power_long_ticks
 *
 * SHT4x command to activate lowest heater power and perform a single shot high
 * precision measurement for 1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_lowest_heater_power_long_ticks(uint16_t* temperature_ticks,
                                              uint16_t* humidity_ticks);

/**
 * @brief sht4x_activate_lowest_heater_power_short_ticks
 *
 * SHT4x command to activate lowest heater power and perform a single shot high
 * precision measurement for 0.1s.
 *
 * @param[out] temperature_ticks Temperature ticks. Convert to degrees celsius
 * by (175 * value / 65535) - 45
 * @param[out] humidity_ticks Humidity ticks. Convert to degrees celsius by (125
 * * value / 65535) - 6
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t
sht4x_activate_lowest_heater_power_short_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks);

/**
 * @brief sht4x_serial_number
 *
 * Read out the serial number
 *
 * @param[out] serial_number Unique serial number
 *
 * @note Each sensor has a unique serial number that is assigned by Sensirion
 * during production.It is stored in the one-time-programmable memory and cannot
 * be manipulated after production.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sht4x_serial_number(uint32_t* serial_number);

/**
 * @brief sht4x_soft_reset
 *
 * Perform a soft reset.
 *
 * @note A reset of the sensor can be achieved in three ways: • Soft reset: use
 * this function • I2C general call: all devices on the I2C bus are reset by
 * sending the command 0x06 to the I2C address 0x00. • Power down (incl.pulling
 * SCL and SDA low)
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sht4x_soft_reset();

#ifdef __cplusplus
}
#endif
#endif  // SHT4X_I2C_H
