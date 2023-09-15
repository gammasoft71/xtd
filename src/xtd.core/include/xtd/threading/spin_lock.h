/// @file
/// @brief Contains xtd::threading::spin_lock exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "mutex.h"
#include "thread.h"
#include "../func.h"
#include "../invalid_operation_exception.h"
#include "../object.h"
#include "../time_span.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides thread-local storage of data.
    /// @code
    /// class spin_lock : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/spin_lock> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use a xtd::threading::spin_lock:
    /// @include spin_lock.cpp
    /// @remarks All public and protected members of xtd::threading::spin_lock are thread-safe and may be used concurrently from multiple threads. The value returned for the xtd::threading::spin_lock::value and xtd::threading::spin_lock::is_value_created properties is specific for the thread on which the property is accessed.
    /// @remarks The differences between the spin_lock class and the C++ thread_local keyword are :
    /// * It is possible to declare a member variable of a thread local class with the spin_lock class, whereas this is not possible with the thread_local keyword.
    /// * With the spin_lock class, you can consult the various values stored by all threads.
    /// @warning Each thread that has ever accessed the instance will contribute to the values stored in the instance. This includes threads that have since left the instance
    class spin_lock : public object {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      spin_lock();
      spin_lock(bool enable_thread_owner_tracking);
      /// @}

      ///@cond
      spin_lock(spin_lock&&) = default;
      spin_lock(const spin_lock&) = default;
      spin_lock& operator =(const spin_lock& other) = default;
      ///@endcond

      /// @name Properties
      
      /// @{
      bool is_held() const noexcept;
      
      bool is_held_by_current_thread() const noexcept;
      
      bool is_thread_owner_tracking_enabled() const noexcept;
      /// @}

      /// @name Methods
      
      /// @{
      void enter(bool& lock_taken);
      bool enter(const time_span& timeout);
      bool enter(int32 milliseconds_timeout);
      
      void exit();
      void exit(bool memory_barrier);
      /// @}

    private:
      mutable std::shared_ptr<data> data_;
    };
  }
}
