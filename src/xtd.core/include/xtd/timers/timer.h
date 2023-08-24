/// @file
/// @brief Contains xtd::timers::timer class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.h"
#include "../event.h"
#include "../isynchronize_invoke.h"
#include "../object.h"
#include "../time_span.h"
#include "../types.h"
#include "elapsed_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the xtd::timers::timer component, which allows you to raise an event on a specified interval.
  namespace timers {
    /// @brief Generates an event after a set interval, with an option to generate recurring events.
    /// @code
    /// class core_export_ timer : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::timers::timer
    /// @par Header
    /// @code #include <xtd/threading/timer> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core threading
    /// @ingroup xtd_core threading
    /// @remarks The xtd::timers::timer component is a server-based timer that raises an xtd::timers::timer::elapsed event in your application after the number of milliseconds in the xtd::timers::timer::interval property has elapsed. You can configure the xtd::timers::timer object to raise the event just once or repeatedly using the xtd::timers::timer::auto_reset property. Typically, a xtd::timers::timer object is declared at the class level so that it stays in scope as long as it is needed. You can then handle its xtd::timers::timer::elapsed event to provide regular processing. For example, suppose you have a critical server that must be kept running 24 hours a day, 7 days a week. You could create a service that uses a xtd::timers::timer object to periodically check the server and ensure that the system is up and running. If the system is not responding, the service could attempt to restart the server or notify an administrator.
    /// @remarks The server-based xtd::timers::timer class is designed for use with worker threads in a multithreaded environment. Server timers can move among threads to handle the raised xtd::timers::timer::elapsed event, resulting in more accuracy than Windows timers in raising the event on time.
    /// @remarks The xtd::timers::timer component raises the xtd::timers::timer::elapsed event, based on the value (in milliseconds) of the xtd::timers::timer::interval property. You can handle this event to perform the processing you need. For example, suppose that you have an online sales application that continuously posts sales orders to a database. The service that compiles the instructions for shipping operates on a batch of orders rather than processing each order individually. You could use a xtd::timers::timer to start the batch processing every 30 minutes.
    /// @warning The xtd::timers::timer class has the same resolution as the system clock. This means that the xtd::timers::timer::elapsed event will fire at an interval defined by the resolution of the system clock if the xtd::timers::timer::interval property is less than the resolution of the system clock. For more information, see the xtd::timers::timer::interval property.
    /// @note The system clock that is used is the same clock used by GetTickCount, which is not affected by changes made with timeBeginPeriod and timeEndPeriod.
    /// @remarks When xtd::timers::timer::auto_reset is set to false, a xtd::timers::timer object raises the xtd::timers::timer::elapsed event only once, after the first xtd::timers::timer::iInterval has elapsed. To keep raising the xtd::timers::timer::elapsed event regularly at the interval defined by the xtd::timers::timer::interval, set xtd::timers::timer::auto_reset to true, which is the default value.
    /// @remarks If the xtd::timers::timer::synchronizing_object property is equal to std::nullopt, the xtd::timers::timer::elapsed event is raised on a xtd::threading::thread_pool thread. If processing of the xtd::timers::timer::elapsed event lasts longer than xtd::timers::timer::interval, the event might be raised again on another xtd::threading::thread_pool thread. In this situation, the event handler should be reentrant.
    /// @note The event-handling method might run on one thread at the same time that another thread calls the xtd::timers::timer::stop method or sets the xtd::timers::timer::enabled property to false. This might result in the xtd::timers::timer::elapsed event being raised after the timer is stopped. The example code for the xtd::timers::timerstop method shows one way to avoid this race condition.
    /// @remarks Even if xtd::timers::timer::synchronizing_object is not equal to std::nullopt, xtd::timers::timer::elapsed events can occur after the xtd::timers::timer::close or xtd::timers::timer::stop method has been called or after the xtd::timers::timer::enabled property has been set to false, because the signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a thread pool thread. One way to resolve this race condition is to set a flag that tells the event handler for the xtd::timers::timer::elapsed event to ignore subsequent events.
    /// @remarks If you use the xtd::timers::timer class with a user interface element, such as a form or control, without placing the timer on that user interface element, assign the form or control that contains the xtd::timers::timer to the xtd::timers::timer::synchronizing_object property, so that the event is marshaled to the user interface thread.
    /// @remarks For a list of default property values for an instance of xtd::timers::timer, see the xtd::timers::timer::timer constructor.
    /// @note xtd includes several timer classes, each of which offers different functionality:
    /// * xtd::timers::timer, which fires an event and executes the code in one or more event sinks at regular intervals. The class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::threading::timer, which executes a single callback method on a thread pool thread at regular intervals. The callback method is defined when the timer is instantiated and cannot be changed. Like the xtd::timers::timer class, this class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::forms::timer, a Windows Forms component that fires an event and executes the code in one or more event sinks at regular intervals. The component has no user interface and is designed for use in a single-threaded environment; it executes on the UI thread.
    /// @par Examples
    /// The following example instantiates a xtd::timers::timer object that fires its xtd::timers::timer::elapsed event every two seconds (2,000 milliseconds), sets up an event handler for the event, and starts the timer. The event handler displays the value of the xtd::timers::elapsed_event_args::signal_time property each time it is raised.
    /// @include timers_timer.cpp
    class core_export_ timer : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::timers::timer class, and sets all the properties to their initial values.
      /// @remarks The following table shows initial property values for an instance of xtd::timers::timer.
      /// | Property                                 | Initial alue     |
      /// | ---------------------------------------- | ---------------- |
      /// | xtd::timers::timer::auto_reset           | true             |
      /// | xtd::timers::timer::enabled              | false            |
      /// | xtd::timers::timer::nterval              | 100 milliseconds |
      /// | xtd::timers::timer::synchronizing_object | std::nullopt     |
      timer();
      /// @brief Initializes a new instance of the xtd::timers::timer class, and sets the xtd::timers::timer::interval property to the specified number of milliseconds.
      /// @param interval The time, in milliseconds, between events. The value must be greater than zero and less than or equal to int32_object::max_value.
      /// @exception d::argument_exception The value of the interval parameter is less than or equal to zero, or greater than int32_object::max_value.
      /// @remarks This constructor sets the xtd::timers::timer::interval property of the new timer instance, but does not enable the timer.
      explicit timer(double interval);
      /// @brief Initializes a new instance of the xtd::timers::timer class, setting the xtd::timers::timer::interval property to the specified period.
      /// @param interval The time between events. The value in milliseconds must be greater than zero and less than or equal to int32_object::max_value.
      explicit timer(const xtd::time_span& interval);
      /// @}

      /// @cond
      timer(const timer& timer);
      timer& operator=(const timer& timer);
      ~timer();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a boolean indicating whether the xtd::timers::timer should raise the xtd::timers::timer::elapsed event only once (false) or repeatedly (true).
      /// @return true if the xtd::timers::timer should raise the xtd::timers::timer::elapsed event each time the interval elapses; false if it should raise the xtd::timers::timer::elapsed event only once, after the first time the interval elapses. The default is true.
      /// @remarks If the xtd::timers::timer is already enabled when the xtd::timers::timer::start method is called, the interval is reset. If xtd::timers::timer::auto_reset is false, the xtd::timers::timer::start method must be called in order to start the count again.
      /// @remarks Resetting the interval affects when the xtd::timers::timer::elapsed event is raised. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when the count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after the xtd::timers::timer::enabled property was set to true.
      bool auto_reset() const noexcept;
      timer& auto_reset(bool value);

      bool enabled() const noexcept;
      timer& enabled(bool value);

      double interval() const noexcept;
      timer& interval(double value);
      
      std::optional<std::reference_wrapper<isynchronize_invoke>> synchronizing_object() const noexcept;
      timer& synchronizing_object(isynchronize_invoke& value);
      timer& synchronizing_object(std::nullptr_t value);
      /// @}
      
      /// @name Events
      
      /// @{
      event<timer, elapsed_event_handler> elapsed;
      /// @}

      /// @name Methods
      
      /// @{
      void close();

      void start();

      void stop();
      /// @}

    private:
      void on_elpased(const elapsed_event_args& e);
      std::shared_ptr<data> data_;
    };
  }
}
