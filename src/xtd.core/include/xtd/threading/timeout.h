/// @file
/// @brief Contains xtd::threading::timeout class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.h"
#include "../static.h"
#include "../time_span.h"
#include "../types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming.
  /// In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::timeout, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Contains a constant used to specify an infinite amount of time. This class cannot be inherited.
    /// @code
    /// class core_export_ timeout static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::threading::timeout
    /// @par Header
    /// @code #include <xtd/threading/timeout> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core threading
    /// @ingroup xtd_core threading
    class core_export_ timeout static_ {
    public:
      /// @name Fields

      /// @{
      /// @brief A constant used to specify an infinite waiting period. This field is constant.
      /// @remarks The value of this constant is -1. For threading methods that accept a timeout parameter, such as Thread::Sleep(int32_t) and Thread::Join(int32_t), this value is used to suppress timeout behavior.
      /// @remarks The value of this field is -1 (0xFFFFFFFF).
      static constexpr int32_t infinite = -1;
      
      /// @brief A constant used to specify an infinite waiting period, for methods that accept a TimeSpan parameter.
      /// @remarks For threading methods that accept a timeout parameter of type TimeSpan, such as Thread.Sleep(TimeSpan) and Thread.Join(TimeSpan), this value is used to suspend the thread indefinitely. However, in most cases, we recommend that you use other System.Threading classes such as Mutex, Monitor, EventWaitHandle, or Semaphore instead to sychronize threads or manage resources.
      /// @remarks The value of this field is -00:00:00.0010000, or -1 millisecond.
      static const time_span infinite_time_span;
      /// @}
    };
  }
}
