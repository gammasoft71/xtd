/// @file
/// @brief Contains xtd::threading::thread_start exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../delegate.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents the method that executes on a xtd::threading::thread.
    /// ```cpp
    /// using thread_start = xtd::action<>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/thread_start>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    using thread_start = delegate<void()>;
  }
}
