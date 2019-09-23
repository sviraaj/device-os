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

#include "usr_fs_hal.h"
#include "interrupts_hal.h"
#include "static_recursive_mutex.h"

namespace {

#ifdef DEBUG_BUILD
#define USR_LOCK_TIMEOUT 30000
int usrLockCounter = 0;
#else
#define USR_LOCK_TIMEOUT 0 // Wait indefinitely
#endif

StaticRecursiveMutex usrLock;

} // namespace

int usr_lock(int write) {
    SPARK_ASSERT(!HAL_IsISR());
    const bool ok = usrLock.lock(USR_LOCK_TIMEOUT);
    SPARK_ASSERT(ok);
#ifdef DEBUG_BUILD
    ++usrLockCounter;
    SPARK_ASSERT(usrLockCounter == 1 || !write);
#endif
    return !ok;
}

int usr_unlock(int write) {
    SPARK_ASSERT(!HAL_IsISR());
    const bool ok = usrLock.unlock();
    SPARK_ASSERT(ok);
#ifdef DEBUG_BUILD
    --usrLockCounter;
    SPARK_ASSERT(usrLockCounter == 0 || !write);
#endif
    return !ok;
}
