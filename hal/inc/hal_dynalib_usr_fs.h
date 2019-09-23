/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HAL_DYNALIB_USR_FS_H
#define	HAL_DYNALIB_USR_FS_H

#include "hal_platform.h"
#include "dynalib.h"

#ifdef DYNALIB_EXPORT
#include "usr_fs_hal.h"
#include "device_code.h"
#endif

DYNALIB_BEGIN(hal_usr_fs)

DYNALIB_FN(0, hal_usr_fs, usr_read_app_data, int(uint32_t, void*, size_t))
DYNALIB_FN(1, hal_usr_fs, usr_write_app_data, int(const void*, uint32_t, uint32_t))
DYNALIB_FN(2, hal_usr_fs, usr_clear, int(void))

DYNALIB_END(hal_usr_fs)

#endif
