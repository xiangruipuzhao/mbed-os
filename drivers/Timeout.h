/* mbed Microcontroller Library
 * Copyright (c) 2006-2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_TIMEOUT_H
#define MBED_TIMEOUT_H

#include "drivers/Ticker.h"
#include "platform/NonCopyable.h"

namespace mbed {
/**
 * \defgroup drivers_Timeout Timeout class
 * \ingroup drivers-public-api-ticker
 * @{
 */

/** A Timeout is used to call a function at a point in the future
 *
 * You can use as many separate Timeout objects as you require.
 *
 * @note Synchronization level: Interrupt safe
 *
 * Example:
 * @code
 * // Blink until timeout.
 *
 * #include "mbed.h"
 *
 * Timeout timeout;
 * DigitalOut led(LED1);
 *
 * int on = 1;
 *
 * void attimeout() {
 *     on = 0;
 * }
 *
 * int main() {
 *     timeout.attach(&attimeout, 5);
 *     while(on) {
 *         led = !led;
 *         thread_sleep_for(200);
 *     }
 * }
 * @endcode
 */
class Timeout : public Ticker, private NonCopyable<Timeout> {

#if !defined(DOXYGEN_ONLY)
protected:
    virtual void handler();
#endif
};

/** @}*/

} // namespace mbed

#endif
