/// @file
/// @brief Contains xtd::threading::event_reset_mode enumeration.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Indicates whether an xtd::threading::event_wait_handle is reset automatically or manually after receiving a signal.
    /// @code
    /// enum class event_reset_mode
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/event_reset_mode> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    enum class event_reset_mode {
      /// @brief When signaled, the xtd::threading::event_wait_handle resets automatically after releasing a single thread. If no threads are waiting, the xtd::threading::event_wait_handle remains signaled until a thread blocks, and resets after releasing the thread.
      auto_reset = 0,
      /// @brief When signaled, the xtd::threading::event_wait_handle releases all waiting threads and remains signaled until it is manually reset.
      manual_reset = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::threading::event_reset_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::threading::event_reset_mode> {{xtd::threading::event_reset_mode::auto_reset, "auto_reset"}, {xtd::threading::event_reset_mode::manual_reset, "manual_reset"}};}
};
/// @endcond
