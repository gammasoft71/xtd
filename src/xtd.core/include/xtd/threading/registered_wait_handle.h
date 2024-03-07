/// @file
/// @brief Contains xtd::threading::registered_wait_handle exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "wait_handle.h"
#include "../object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class thread_pool;
    /// @endcond
    
    /// @brief A synchronization primitive that can also be used for interprocess synchronization.
    /// @code
    /// class core_export_ registered_wait_handle final : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/registered_wait_handle> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    class core_export_ registered_wait_handle final : public object {
      friend class thread_pool;
    public:
      /// @name Public Methods
      
      /// @{
      /// @brief Cancels a registered wait operation issued by the xtd::threading::thread_pool::register_wait_for_single_object method.
      /// @return bool true if the function succeeds; otherwise, false
      /// @remarks If wait_object is specified, it is signaled only if the xtd::threading::registered_wait_handle is successfully unregistered. If a callback method is in progress when Unregister executes, wait_object is not signaled until the callback method completes. In particular, if a callback method executes Unregister, waitObject is not signaled until that callback method completes.
      /// @see xtd::threading::thread_pool
      bool unregister();
      /// @brief Cancels a registered wait operation issued by the xtd::threading::thread_pool::register_wait_for_single_object method.
      /// @param wait_object The xtd::threading::wait_handle to be signaled.
      /// @return bool true if the function succeeds; otherwise, false
      /// @remarks If wait_object is specified, it is signaled only if the xtd::threading::registered_wait_handle is successfully unregistered. If a callback method is in progress when Unregister executes, wait_object is not signaled until the callback method completes. In particular, if a callback method executes Unregister, waitObject is not signaled until that callback method completes.
      /// @see xtd::threading::thread_pool
      bool unregister(wait_handle& wait_obbject);
      /// @}
      
    private:
      intptr item_ = 0;
    };
  }
}
