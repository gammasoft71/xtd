/// @file
/// @brief Contains xtd::threading::countdown_event exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
    /// @code
    /// class countdown_event : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/countdown_event> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use a xtd::threading::countdown_event:
    /// @include countdown_event.cpp
    class core_export_ countdown_event : public object {
      struct data;
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of xtd::threading::countdown_event class with the specified count.
      /// @param initial_count he number of signals initially required to set the xtd::threading::countdown_event.
      /// @exception xtd::argument_out_of_range_exception initial_count is less than 0.
      /// @remarks If initial_count is 0, the event is created in a signaled state.
      explicit countdown_event(int32 initial_count);
      /// @}

      ///@cond
      countdown_event();
      countdown_event(countdown_event&&) = default;
      countdown_event(const countdown_event&) = default;
      countdown_event& operator =(const countdown_event& other);
      ~countdown_event();
      ///@endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets the number of remaining signals required to set the event.
      /// @return The number of remaining signals required to set the event.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      int32 current_count() const;

      /// @brief Gets the numbers of signals initially required to set the event.
      /// @return The number of signals initially required to set the event.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      int32 initial_count() const;

      /// @brief ndicates whether the xtd::threading::countdown_event object's current count has reached zero.
      /// @return true if the current count is zero; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @remarks The xtd::threading::countdown_event does not raise an event when the countdown has reached zero. Instead, the xtd::threading::countdown_event::current_count property equals zero, and the xtd::threading::countdown_event::is_set property equals true.
      bool is_set() const;
      
      /// @brief Gets a xtd::threading::wait_handle that is used to wait for the event to be set.
      /// @return A xtd::threading::wait_handle that is used to wait for the event to be set.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      const xtd::threading::wait_handle& wait_handle() const;
      /// @brief Gets a xtd::threading::wait_handle that is used to wait for the event to be set.
      /// @return A xtd::threading::wait_handle that is used to wait for the event to be set.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      xtd::threading::wait_handle& wait_handle();
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Increments the xtd::threading::countdown_event's current count by one.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::invalid_operation_exception The current instance is already set.
      void add_count();
      /// @brief Increments the xtd::threading::countdown_event's current count by one.
      /// @param count The value by which to increase xtd::threading::countdown_event::current_count.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::invalid_operation_exception The current instance is already set.
      /// @exception xtd::argument_out_of_range_exception count is less than 0.
      void add_count(int32 count);
      
      /// @brief Close the current instance of the xtd::threading::countdown_event  class.
      void close();

      /// @brief Resets the xtd::threading::countdown_event to the value of xtd::threading::countdown_event::initial_count.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @remarks This method resets xtd::threading::countdown_event::initial_count for all subsequent accesses of the property on the current instance.
      void reset();
      /// @brief Resets the xtd::threading::countdown_event::initial_count property to a specified value.
      /// @param count he number of signals required to set the xtd::threading::countdown_event.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::argument_out_of_range_exception count is less than 0.
      /// @remarks This method resets xtd::threading::countdown_event::initial_count for all subsequent accesses of the property on the current instance.
      void reset(int32 count);
      
      /// @brief Registers a signal with the xtd::threading::countdown_event, decrementing the value of xtd::threading::countdown_event::current_count.
      /// @return true if the signal caused the count to reach zero and the event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::nvalid_operation_exception The current instance is already set.
      bool signal();
      /// @brief Registers multiple signals with the xtd::threading::countdown_event, decrementing the value of xtd::threading::countdown_event::current_count by the specified amount.
      /// @param signal_count The number of signals to register.
      /// @return true if the signal caused the count to reach zero and the event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::argument_out_of_range_exception signal_count is less than 0.
      /// @exception xtd::nvalid_operation_exception The current instance is already set.
      bool signal(int32 signal_count);
      
      /// @brief Attempts to increment xtd::threading::countdown_event::current_count by one.
      /// @return true if the increment succeeded; otherwise, false. If CurrentCount is already at zero, this method will return false.
      bool try_add_count() noexcept;
      /// @brief Attempts to increment xtd::threading::countdown_event::current_count by by a specified value.
      /// @param count The value by which to increase xtd::threading::countdown_event::current_count.
      /// @return true if the increment succeeded; otherwise, false. If CurrentCount is already at zero, this method will return false.
      bool try_add_count(int32 count) noexcept;

      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @remarks The caller of this method blocks indefinitely until the current instance is set. The caller will return immediately if the event is currently in a set state.
      void wait();
      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set, using a 32-bit signed integer to measure the timeout.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::ifinite (-1) to wait indefinitely.
      /// @return true if the xtd::threading::countdown_event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out..
      bool wait(int32 milliseconds_timeout);
      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set, while observing a xtd::threading::cancellation_token.
      /// @param cancellation_toker The xtd::threading::cancellation_token to observe.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @remarks The caller of this method blocks indefinitely until the current instance is set. The caller will return immediately if the event is currently in a set state. If the xtd::threading::cancellation_token being observed is canceled during the wait operation, an xtd::operation_canceled_exception will be thrown.
      void wait(const cancellation_token& cancellation_token);
      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set, using a xtd::time_span to measure the timeout.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @return true if the xtd::threading::countdown_event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out..
      bool wait(const time_span& timeout);
      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set, using a 32-bit signed integer to measure the timeout, while observing a xtd::threading::cancellation_token.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::ifinite (-1) to wait indefinitely.
      /// @param cancellation_toker The xtd::threading::cancellation_token to observe.
      /// @return true if the xtd::threading::countdown_event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out..
      bool wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token);
      /// @brief Blocks the current thread until the xtd::threading::countdown_event is set, using a xtd::time_span to measure the timeout, while observing a xtd::threading::cancellation_token.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @param cancellation_toker The xtd::threading::cancellation_token to observe.
      /// @return true if the xtd::threading::countdown_event was set; otherwise, false.
      /// @exception xtd::object_closed_exception The current instance has already been closed.
      /// @exception xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out..
      bool wait(const time_span& timeout, const cancellation_token& cancellation_token);
      /// @}

    private:
      std::shared_ptr<data> data_;
      bool wait_wtih_cancellation_token();
      bool wait_wtih_cancellation_token(int32 milliseconds_timeout);
    };
  }
}
