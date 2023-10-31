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

#include "sht4x_i2c.h"
#include "sensirion_common.h"
#include "sensirion_i2c.h"
#include "sensirion_i2c_hal.h"

#define sensirion_hal_sleep_us sensirion_i2c_hal_sleep_usec

static uint8_t communication_buffer[6] = {0};

static uint8_t _i2c_address;

void sht4x_init(uint8_t i2c_address) {
    _i2c_address = i2c_address;
}

int16_t sht4x_measure_high_precision_ticks(uint16_t* temperature_ticks,
                                           uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0xfd);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(10 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t sht4x_measure_medium_precision_ticks(uint16_t* temperature_ticks,
                                             uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0xf6);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(5 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t sht4x_measure_lowest_precision_ticks(uint16_t* temperature_ticks,
                                             uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0xe0);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(2 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_highest_heater_power_long_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x39);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(1100 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_highest_heater_power_short_ticks(uint16_t* temperature_ticks,
                                                uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x32);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(110 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_medium_heater_power_long_ticks(uint16_t* temperature_ticks,
                                              uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x2f);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(1100 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_medium_heater_power_short_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x24);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(110 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_lowest_heater_power_long_ticks(uint16_t* temperature_ticks,
                                              uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x1e);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(1100 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t
sht4x_activate_lowest_heater_power_short_ticks(uint16_t* temperature_ticks,
                                               uint16_t* humidity_ticks) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x15);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(110 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *temperature_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[0]);
    *humidity_ticks = sensirion_common_bytes_to_uint16_t(&buffer_ptr[2]);
    return local_error;
}

int16_t sht4x_serial_number(uint32_t* serial_number) {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x89);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(10 * 1000);
    local_error = sensirion_i2c_read_data_inplace(_i2c_address, buffer_ptr, 4);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    *serial_number = sensirion_common_bytes_to_uint32_t(&buffer_ptr[0]);
    return local_error;
}

int16_t sht4x_soft_reset() {
    int16_t local_error = NO_ERROR;
    uint8_t* buffer_ptr = communication_buffer;
    uint16_t local_offset = 0;
    local_offset =
        sensirion_i2c_add_command8_to_buffer(buffer_ptr, local_offset, 0x94);
    local_error =
        sensirion_i2c_write_data(_i2c_address, buffer_ptr, local_offset);
    if (local_error != NO_ERROR) {
        return local_error;
    }
    sensirion_i2c_hal_sleep_usec(10 * 1000);
    return local_error;
}
