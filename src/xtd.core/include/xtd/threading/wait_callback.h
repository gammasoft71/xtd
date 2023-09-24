/// @file
/// @brief Contains xtd::threading::wait_callback exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../action"
#include <any>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a callback method to be executed by a thread pool thread.
    /// @code
    /// using wait_callback = xtd::action<std::any>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/wait_callback> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @param state An object containing information to be used by the callback method.
    /// @remarks xtd::threading::wait_callback represents a callback method that you want to execute on a xtd::threading::thread_pool thread. Create the delegate by passing your callback method to the xtd::threading::wait_callback constructor. Your method must have the signature shown here.
    /// @remarks Queue the method for execution by passing the xtd::threading::wait_callback delegate to xtd::threading::thread_pool::queue_user_work_item. The callback method executes when a thread pool thread becomes available.
    /// @remarks If you want to pass information to the callback method, create an object that contains the necessary information and pass it to the xtd::threading::thread_pool::queue_user_work_item(xtd::threading::wait_callback, xtd::object&) method as the second argument. Each time the callback method executes, the state parameter contains this object.
    /// @remarks For examples that use the xtd::threading::wait_callback delegate, see the xtd::threading::thread_pool::queue_user_work_item method.
    using wait_callback = action<std::any>;
  }
}
