
/// @file
/// @brief Contains process priority class constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
 
#ifndef NORMAL_PRIORITY_CLASS
/// @brief Process with no special scheduling needs.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t NORMAL_PRIORITY_CLASS = 0x00000020;
/// @brief Process whose threads run only when the system is idle and are preempted by the threads of any process running in a higher priority class. An example is a screen saver. The idle priority class is inherited by child processes.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t IDLE_PRIORITY_CLASS = 0x00000040;
/// @brief Process that performs time-critical tasks that must be executed immediately for it to run correctly. The threads of a high-priority class process preempt the threads of normal or idle priority class processes. An example is the Task List, which must respond quickly when called by the user, regardless of the load on the operating system. Use extreme care when using the high-priority class, because a high-priority class CPU-bound application can use nearly all available cycles.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t HIGH_PRIORITY_CLASS = 0x00000080;
/// @brief Process that has the highest possible priority. The threads of a real-time priority class process preempt the threads of all other processes, including operating system processes performing important tasks. For example, a real-time process that executes for more than a very brief interval can cause disk caches not to flush or cause the mouse to be unresponsive.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t REALTIME_PRIORITY_CLASS = 0x00000100;
/// @brief Process that has priority above IDLE_PRIORITY_CLASS but below NORMAL_PRIORITY_CLASS.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t BELOW_NORMAL_PRIORITY_CLASS = 0x00004000;
/// @brief Process that has priority above NORMAL_PRIORITY_CLASS but below HIGH_PRIORITY_CLASS.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native ppc
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t ABOVE_NORMAL_PRIORITY_CLASS = 0x00008000;
#endif
