/// @file
/// @brief Contains xtd::threading::timer class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "timer_callback.h"
#include "../core_export.h"
#include "../object.h"
#include "../time_span.h"
#include "../types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides a mechanism for executing a method on a thread pool thread at specified intervals. This class cannot be inherited.
    /// @code
    /// class core_export_ timer final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::threading::timer
    /// @par Header
    /// @code #include <xtd/threading/timer> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example defines a status_checker class that includes a check_status method whose signature is the same as the xtd::threading::timer_callback delegate. The state argument of the check_status method is an xtd::threading::auto_reset_event object that is used to synchronize the application thread and the thread pool thread that executes the callback delegate. The status_checker class also includes two state variables:
    /// invoke_count
    /// Indicates the number of times the callback method has been invoked.
    /// max_count
    /// Determines the maximum number of times the callback method should be invoked.
    /// The application thread creates the timer, which waits one second and then executes the check_status callback method every 250 milliseconds. The application thread then blocks until the xtd::threading::auto_reset_event object is signaled. When the check_status callback method executes max_count times, it calls the auto_reset_event::set method to set the state of the xtd::threading::auto_reset_event object to signaled. The first time this happens, the application thread calls the xtd::threading::timer::change(int32, int32) method so that the callback method now executes every half second. It once again blocks until the xtd::threading::auto_reset_event object is signaled.
    /// @include timer.cpp
    /// @remarks Use a xtd::threading::timer_callback delegate to specify the method you want the xtd::threading::timer to execute. The signature of the xtd::threading::timer_callback delegate is: @verbatim using timer_callback = action<std::any> @endverbatim.
    /// @remarks The timer delegate is specified when the timer is constructed, and cannot be changed. The method does not execute on the thread that created the timer; it executes on axtd::threading::thread-pool thread supplied by the system.
    /// @note xtd includes several timer classes, each of which offers different functionality:
    /// * xtd::timers::timer, which fires an event and executes the code in one or more event sinks at regular intervals. The class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::threading::timer, which executes a single callback method on a thread pool thread at regular intervals. The callback method is defined when the timer is instantiated and cannot be changed. Like the xtd::timers::timer class, this class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::forms::timer, a Windows Forms component that fires an event and executes the code in one or more event sinks at regular intervals. The component has no user interface and is designed for use in a single-threaded environment; it executes on the UI thread.
    /// @remarks When you create a timer, you can specify an amount of time to wait before the first execution of the method (due time), and an amount of time to wait between subsequent executions (period). The xtd::threading::timer class has the same resolution as the system clock. This means that if the period is less than the resolution of the system clock, the xtd::threading::timer_callback delegate will execute at intervals defined by the resolution of the system clock, which is approximately 15 milliseconds on Windows 7 and Windows 8 systems. You can change the due time and period, or disable the timer, by using the xtd::forms::timer::change method.
    /// @note As long as you are using a xtd::threading::timer, you must keep a reference to it. As with any managed object, a xtd::threading::timer is subject to garbage collection when there are no references to it. The fact that a xtd::threading::timer is still active does not prevent it from being collecte
    /// @note The system clock that is used is the same clock used by GetTickCount, which is not affected by changes made with timeBeginPeriod and timeEndPeriod.
    /// @remarks The callback method executed by the timer should be reentrant, because it is called onxtd::threading::thread-pool threads. The callback can be executed simultaneously on two thread pool threads if the timer interval is less than the time required to execute the callback, or if all thread pool threads are in use and the callback is queued multiple times.
    /// @note xtd::threading::timer is a simple, lightweight timer that uses callback methods and is served by thread pool threads. It is not recommended for use with Windows Forms, because its callbacks do not occur on the user interface thread. xtd::forms::timer is a better choice for use with Windows Forms. For server-based timer functionality, you might consider using xtd::timers::timer, which raises events and has additional features.
    class core_export_ timer final : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the timer class with an infinite period and an infinite due time, using the newly created timer object as the state object.
      /// @param callback the address of a method to be executed
      /// @exception ArgumentNullException The callback is null.
      /// @remarks Call this constructor when you want to use the timer object itself as the state object. After creating the timer, use the change method to set the interval and due time.
      /// @remarks This constructor specifies an infinite due time before the first callback and an infinite interval between callbacks, in order to prevent the first callback from occurring before the timer object is assigned to the state object.
      explicit timer(const timer_callback& callback);
      /// @brief Initializes a new instance of the timer class, using a 32-bit signed integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, int32 due_time, int32 period);
      /// @brief Initializes a new instance of the timer class, using a 64-bit signed integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, int64 due_time, int64 period);
      /// @brief Initializes a new instance of the timer class, using a TimaSpan to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback or due_time or period param is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, const time_span& due_time, const time_span& period);
      /// @brief Initializes a new instance of the timer class, using a 32-bit unsigned integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, uint32 due_time, uint32 period);
      /// @brief Initializes a new instance of the timer class, using a 32-bit signed integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param state An object containing information to be used by the callback method, or null.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, std::any state, int32 due_time, int32 period);
      /// @brief Initializes a new instance of the timer class, using a 64-bit signed integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param state An object containing information to be used by the callback method, or null.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, std::any state, int64 due_time, int64 period);
      /// @brief Initializes a new instance of the timer class, using a TimaSpan to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param state An object containing information to be used by the callback method, or null.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback or due_time or period param is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, std::any state, const time_span& due_time, const time_span& period);
      /// @brief Initializes a new instance of the timer class, using a 32-bit unsigned integer to specify the time interval.
      /// @param callback the address of a method to be executed
      /// @param state An object containing information to be used by the callback method, or null.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The callback is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      /// @remarks The callback parameter is invoked once after due_time elapses, and thereafter each time the period time interval elapses.
      timer(const timer_callback& callback, std::any state, uint32 due_time, uint32 period);
      /// @}

      /// @cond
      template <typename callback_t>
      timer(callback_t callback) : timer(timer_callback {callback}) {}
      template <typename callback_t>
      timer(callback_t callback, int32 due_time, int32 period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, int64 due_time, int64 period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, const time_span& due_time, const time_span& period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, uint32 due_time, uint32 period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, std::any state, int32 due_time, int32 period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, std::any state, int64 due_time, int64 period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, std::any state, const time_span& due_time, const time_span& period) : timer(timer_callback {callback}, due_time, period) {}
      template <typename callback_t>
      timer(callback_t callback, std::any state, uint32 due_time, uint32 period) : timer(timer_callback {callback}, due_time, period) {}
      timer();
      timer(const timer& timer);
      timer& operator=(const timer& timer);
      ~timer();
      /// @endcond
      
      /// @name Methods
      
      /// @{
      /// @brief changes the start time and the interval between method invocations for a timer, using 32-bit signed integers to measure time intervals.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      void change(int32 due_time, int32 period);
      /// @brief changes the start time and the interval between method invocations for a timer, using 64-bit signed integers to measure time intervals.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      void change(int64 due_time, int64 period);
      /// @brief changes the start time and the interval between method invocations for a timer, using time_span values to measure time intervals.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception ArgumentNullException The due_time or period param is null.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      void change(const time_span& due_time, const time_span& period);
      /// @brief changes the start time and the interval between method invocations for a timer, using 32-bit unsigned integers to measure time intervals.
      /// @param due_time The amount of time to delay before callback is invoked, in milliseconds. Specify Timeout::Infinite to prevent the timer from starting. Specify zero (0) to start the timer immediately.
      /// @param period The time interval between invocations of callback, in milliseconds. Specify Timeout::Infinite to disable periodic signaling.
      /// @exception xtd::argument_out_of_range_exception The due_time or period parameter is negative and is not equal to Timeout::Infinite.
      void change(uint32 due_time, uint32 period);
      
      /// @brief Releases all resources used by the current instance of xtd::threading::timer.
      void close();
      /// @}

    private:
      std::shared_ptr<data> data_;
    };
  }
}
