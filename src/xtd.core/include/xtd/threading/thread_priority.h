/// @file
/// @brief Contains xtd::threading::thread_priority enumeration.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Specifies the scheduling priority of a system::threading::thread.
    /// @code
    /// enum class thread_priority
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/thread_priority> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    enum class thread_priority {
      /// @brief The system::threading::thread can be scheduled after threads with any other priority.
      lowest = 0,
      /// @brief The system::threading::thread can be scheduled after threads with thread_priority::normal priority and before those with thread_priority::lowest priority.
      below_normal = 1,
      /// @brief The system::threading::thread can be scheduled after threads with thread_priority::above_normal priority and before those with thread_priority::below_normal priority. Threads have thread_priority::normal priority by default.
      normal = 2,
      /// @brief The system::threading::thread can be scheduled after threads with thread_priority::highest priority and before those with thread_priority::normal priority.
      above_normal = 3,
      /// @brief The system::threading::thread can be scheduled before threads with any other priority.
      highest = 4,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::threading::thread_priority> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::threading::thread_priority> {{xtd::threading::thread_priority::lowest, "lowest"}, {xtd::threading::thread_priority::below_normal, "below_normal"}, {xtd::threading::thread_priority::normal, "normal"}, {xtd::threading::thread_priority::above_normal, "above_normal"}, {xtd::threading::thread_priority::highest, "highest"}};}
};
/// @endcond
