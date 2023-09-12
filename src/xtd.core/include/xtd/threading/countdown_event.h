/// @file
/// @brief Contains xtd::threading::countdown_event exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "cancellation_token.h"
#include "wait_handle.h"
#include "../object.h"
#include "../time_span.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a synchronization primitive that is signaled when its count reaches zero.
    /// @par Header
    /// @code #include <xtd/threading/countdown_event> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// @include countdown_event.cpp
    class core_export_ countdown_event : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      explicit countdown_event(int32 initial_count);
      /// @}

      ///@cond
      countdown_event();
      countdown_event(countdown_event&&) = default;
      countdown_event(const countdown_event&) = default;
      countdown_event& operator =(const countdown_event& other);
      ~countdown_event();
      ///@endcond

      /// @name Properties
      
      /// @{
      int32 current_count() const;

      int32 initial_count() const;

      bool is_set() const;
      
      const xtd::threading::wait_handle& wait_handle() const;
      xtd::threading::wait_handle& wait_handle();
      /// @}

      /// @name Methods
      
      /// @{
      void add_count();
      void add_count(int32 count);
      
      /// @brief Close the current instance of the xtd::threading::countdown_event  class.
      void close();

      void reset();
      void reset(int32 count);
      
      void signal();
      void signal(int32 signal_count);
      
      bool try_add_count() noexcept;
      bool try_add_count(int32 count) noexcept;

      void wait();
      bool wait(int32 milliseconds_timeout);
      bool wait(const cancellation_token& cancellation_token);
      bool wait(const time_span& timeout);
      bool wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token);
      bool wait(const time_span& timeout, const cancellation_token& cancellation_token);
/// @}

    private:
      std::shared_ptr<data> data_;
    };
  }
}
