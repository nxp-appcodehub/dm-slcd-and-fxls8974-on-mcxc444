/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file fxlS8974 driver header file
 * @brief The fxls8974.h file describes the FXLS8974 driver interface and structures.
 */
#ifndef FXLS8974_DRV_H
#define FXLS8974_DRV_H

uint8_t FXLS8974_Init(fxls_handle_t *fxlsHandle);


float FXLS8974_get_data(fxls_handle_t *fxlsHandle,  uint8_t dataScale, int count);

void BOARD_I2C_ReleaseBus(void);






#endif
