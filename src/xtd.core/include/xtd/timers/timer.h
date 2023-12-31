/// @file
/// @brief Contains xtd::timers::timer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "elapsed_event_handler.h"
#include "../core_export.h"
#include "../event.h"
#include "../isynchronize_invoke.h"
#include "../object.h"
#include "../time_span.h"
#include "../types.h"

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
    /// xtd.core
    /// @ingroup xtd_core timers
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
      /// @brief Sets a boolean indicating whether the xtd::timers::timer should raise the xtd::timers::timer::elapsed event only once (false) or repeatedly (true).
      /// @param value true if the xtd::timers::timer should raise the xtd::timers::timer::elapsed event each time the interval elapses; false if it should raise the xtd::timers::timer::elapsed event only once, after the first time the interval elapses. The default is true.
      /// @remarks If the xtd::timers::timer is already enabled when the xtd::timers::timer::start method is called, the interval is reset. If xtd::timers::timer::auto_reset is false, the xtd::timers::timer::start method must be called in order to start the count again.
      /// @remarks Resetting the interval affects when the xtd::timers::timer::elapsed event is raised. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when the count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after the xtd::timers::timer::enabled property was set to true.
      timer& auto_reset(bool value);

      /// @brief Gets a value indicating whether the xtd::timers::timer should raise the xtd::timers::timer::elapsed event.
      /// @return true if the xtd::timers::timer should raise the xtd::timers::timer::elapsed event; otherwise, false. The default is false.
      /// @exception xtd::object_closed_exception This property cannot be set because the timer has been closed.
      /// @exception xtd::argument_exception The xtd::timers::timer::interval property was set to a value greater than xtd::int32_object::max_value before the timer was enabled.
      /// @remarks Setting xtd::timers::timer::enabled to true is the same as calling xtd::timers::timer::start, while setting xtd::timers::timer::enabled to false is the same as calling xtd::timers::timer::stop.
      /// @note The signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a xtd::threading::thread_pool thread. This might result in the xtd::timers::timer::elapsed event being raised after the xtd::timers::timer::enabled property is set to false. The code example for the xtd::timers::timer::stop method shows one way to work around this race condition.
      /// @remarks If xtd::timers::timer::enabled is set to true and xtd::timers::timer::auto_reset is set to false, the xtd::timers::timer raises the xtd::timers::timer::elapsed event only once, the first time the interval elapses.
      /// @remarks If the interval is set after the xtd::timers::timer has started, the count is reset. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after Enabled was set to true.
      bool enabled() const noexcept;
      /// @brief Sets a value indicating whether the xtd::timers::timer should raise the xtd::timers::timer::elapsed event.
      /// @param value true if the xtd::timers::timer should raise the xtd::timers::timer::elapsed event; otherwise, false. The default is false.
      /// @exception xtd::object_closed_exception This property cannot be set because the timer has been closed.
      /// @exception xtd::argument_exception The xtd::timers::timer::interval property was set to a value greater than xtd::int32_object::max_value before the timer was enabled.
      /// @remarks Setting xtd::timers::timer::enabled to true is the same as calling xtd::timers::timer::start, while setting xtd::timers::timer::enabled to false is the same as calling xtd::timers::timer::stop.
      /// @note The signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a xtd::threading::thread_pool thread. This might result in the xtd::timers::timer::elapsed event being raised after the xtd::timers::timer::enabled property is set to false. The code example for the xtd::timers::timer::stop method shows one way to work around this race condition.
      /// @remarks If xtd::timers::timer::enabled is set to true and xtd::timers::timer::auto_reset is set to false, the xtd::timers::timer raises the xtd::timers::timer::elapsed event only once, the first time the interval elapses.
      /// @remarks If the interval is set after the xtd::timers::timer has started, the count is reset. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after Enabled was set to true.
      timer& enabled(bool value);

      /// @brief Gets the interval, expressed in milliseconds, at which to raise the xtd::timers::timer::elapsed event.
      /// @return The time, in milliseconds, between xtd::timers::timer::elapsed events. The value must be greater than zero, and less than or equal to xtd::int32_object::max_value. The default is 100 milliseconds.
      /// @exception xtd::argument_exception The interval is less than or equal to zero.<br>-or<br>The interval is greater than xtd::int32_object::max_value.
      /// @remarks You use the xtd::timers::timer::interval property to determine the frequency at which the xtd::timers::timer::elapsed event is fired. Because the xtd::timers::timer class depends on the system clock, it has the same resolution as the system clock. This means that the xtd::timers::timer::elapsed event will fire at an interval defined by the resolution of the system clock if the xtd::timers::timer::interval property is less than the resolution of the system clock. The following example sets the xtd::timers::timer::interval property to 5 milliseconds. When run on a Windows system whose system clock has a resolution of approximately 15 milliseconds, the event fires approximately every 15 milliseconds rather than every 5 milliseconds.
      /// @note The system clock that is used is the same clock used by GetTickCount, which is not affected by changes made with timeBeginPeriod and timeEndPeriod.
      /// @remarks If the interval is set after the xtd::timers::timer has started, the count is reset. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after xtd::timers::timer::enabled was set to true.
      /// @remarks If xtd::timers::timer::enabled is set to true and xtd::timers::timer::auto_reset is set to false, the xtd::timers::timer raises the xtd::timers::timer::elapsed event only once, the first time the interval elapses. xtd::timers::timer::enabled is then set to false.
      /// @note If xtd::timers::timer::enabled and xtd::timers::timer::auto_reset are both set to false, and the timer has previously been enabled, setting the xtd::timers::timer::interval property causes the xtd::timers::timer::elapsed event to be raised once, as if the xtd::timers::timer::enabled property had been set to true. To set the interval without raising the event, you can temporarily set the xtd::timers::timer::enabled property to true, set the xtd::timers::timer::interval property to the desired time interval, and then immediately set the xtd::timers::timer::enabled property back to false.
      double interval() const noexcept;
      /// @brief Sets the interval, expressed in milliseconds, at which to raise the xtd::timers::timer::elapsed event.
      /// @param value The time, in milliseconds, between xtd::timers::timer::elapsed events. The value must be greater than zero, and less than or equal to xtd::int32_object::max_value. The default is 100 milliseconds.
      /// @exception xtd::argument_exception The interval is less than or equal to zero.<br>-or<br>The interval is greater than xtd::int32_object::max_value.
      /// @remarks You use the xtd::timers::timer::interval property to determine the frequency at which the xtd::timers::timer::elapsed event is fired. Because the xtd::timers::timer class depends on the system clock, it has the same resolution as the system clock. This means that the xtd::timers::timer::elapsed event will fire at an interval defined by the resolution of the system clock if the xtd::timers::timer::interval property is less than the resolution of the system clock. The following example sets the xtd::timers::timer::interval property to 5 milliseconds. When run on a Windows system whose system clock has a resolution of approximately 15 milliseconds, the event fires approximately every 15 milliseconds rather than every 5 milliseconds.
      /// @note The system clock that is used is the same clock used by GetTickCount, which is not affected by changes made with timeBeginPeriod and timeEndPeriod.
      /// @remarks If the interval is set after the xtd::timers::timer has started, the count is reset. For example, if you set the interval to 5 seconds and then set the xtd::timers::timer::enabled property to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after xtd::timers::timer::enabled was set to true.
      /// @remarks If xtd::timers::timer::enabled is set to true and xtd::timers::timer::auto_reset is set to false, the xtd::timers::timer raises the xtd::timers::timer::elapsed event only once, the first time the interval elapses. xtd::timers::timer::enabled is then set to false.
      /// @note If xtd::timers::timer::enabled and xtd::timers::timer::auto_reset are both set to false, and the timer has previously been enabled, setting the xtd::timers::timer::interval property causes the xtd::timers::timer::elapsed event to be raised once, as if the xtd::timers::timer::enabled property had been set to true. To set the interval without raising the event, you can temporarily set the xtd::timers::timer::enabled property to true, set the xtd::timers::timer::interval property to the desired time interval, and then immediately set the xtd::timers::timer::enabled property back to false.
      timer& interval(double value);
      
      /// @brief Gets the object used to marshal event-handler calls that are issued when an interval has elapsed.
      /// @return The xtd::isynchronize_invoke representing the object used to marshal the event-handler calls that are issued when an interval has elapsed. The default is std::nullopt.
      /// @remarks When xtd::timers::timer::synchronizing_object is std::nullopt, the method that handles the xtd::timers::timer::elapsed event is called on a thread from the system-thread pool. For more information on system-thread pools, see xtd::threading::thread_pool.
      /// @remarks When the xtd::timers::timer::elapsed event is handled by a visual Windows Forms component, such as a button, accessing the component through the system-thread pool might result in an exception or just might not work. Avoid this effect by setting xtd::timers::timer::synchronizing_object to a Windows Forms component, which causes the method that handles the xtd::timers::timer::elapsed event to be called on the same thread that the component was created on.
      /// @note Even if the xtd::timers::timer::synchronizing_object property is not std::nullopt, xtd::timers::timer::elapsed events can occur after the xtd::timers::timer::close or xtd::timers::timer::stop method has been called or after the Enabled property has been set to false, because the signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a thread pool thread. One way to resolve this race condition is to set a flag that tells the event handler for the xtd::timers::timer::elapsed event to ignore subsequent events.
      /// @par Examples
      /// The following example is a Windows Forms app that serves as a very simple text file editor. When the text in the text box has not been saved, the app asks the user at one-minute intervals whether they want to save the contents of the text box. To do this, the xtd::timers::timer::interval property is set to one minute (60,000 milliseconds), and the xtd::timers::timer::synchronizing_object property is set to the xtd::forms::form object.
      /// @include timers_timer_synchronizing_object.cpp
      std::optional<std::reference_wrapper<isynchronize_invoke>> synchronizing_object() const noexcept;
      /// @brief Sets the object used to marshal event-handler calls that are issued when an interval has elapsed.
      /// @param value The xtd::isynchronize_invoke representing the object used to marshal the event-handler calls that are issued when an interval has elapsed. The default is std::nullopt.
      /// @remarks When xtd::timers::timer::synchronizing_object is std::nullopt, the method that handles the xtd::timers::timer::elapsed event is called on a thread from the system-thread pool. For more information on system-thread pools, see xtd::threading::thread_pool.
      /// @remarks When the xtd::timers::timer::elapsed event is handled by a visual Windows Forms component, such as a button, accessing the component through the system-thread pool might result in an exception or just might not work. Avoid this effect by setting xtd::timers::timer::synchronizing_object to a Windows Forms component, which causes the method that handles the xtd::timers::timer::elapsed event to be called on the same thread that the component was created on.
      /// @note Even if the xtd::timers::timer::synchronizing_object property is not std::nullopt, xtd::timers::timer::elapsed events can occur after the xtd::timers::timer::close or xtd::timers::timer::stop method has been called or after the Enabled property has been set to false, because the signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a thread pool thread. One way to resolve this race condition is to set a flag that tells the event handler for the xtd::timers::timer::elapsed event to ignore subsequent events.
      /// The following example is a Windows Forms app that serves as a very simple text file editor. When the text in the text box has not been saved, the app asks the user at one-minute intervals whether they want to save the contents of the text box. To do this, the xtd::timers::timer::interval property is set to one minute (60,000 milliseconds), and the xtd::timers::timer::synchronizing_object property is set to the xtd::forms::form object.
      /// @include timers_timer_synchronizing_object.cpp
      timer& synchronizing_object(isynchronize_invoke& value);
      /// @brief Resets the object used to marshal event-handler calls that are issued when an interval has elapsed.
      /// @param value nullptr.
      /// @remarks When xtd::timers::timer::synchronizing_object is std::nullopt, the method that handles the xtd::timers::timer::elapsed event is called on a thread from the system-thread pool. For more information on system-thread pools, see xtd::threading::thread_pool.
      /// @remarks When the xtd::timers::timer::elapsed event is handled by a visual Windows Forms component, such as a button, accessing the component through the system-thread pool might result in an exception or just might not work. Avoid this effect by setting xtd::timers::timer::synchronizing_object to a Windows Forms component, which causes the method that handles the xtd::timers::timer::elapsed event to be called on the same thread that the component was created on.
      /// @note Even if the xtd::timers::timer::synchronizing_object property is not std::nullopt, xtd::timers::timer::elapsed events can occur after the xtd::timers::timer::close or xtd::timers::timer::stop method has been called or after the Enabled property has been set to false, because the signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a thread pool thread. One way to resolve this race condition is to set a flag that tells the event handler for the xtd::timers::timer::elapsed event to ignore subsequent events.
      /// The following example is a Windows Forms app that serves as a very simple text file editor. When the text in the text box has not been saved, the app asks the user at one-minute intervals whether they want to save the contents of the text box. To do this, the xtd::timers::timer::interval property is set to one minute (60,000 milliseconds), and the xtd::timers::timer::synchronizing_object property is set to the xtd::forms::form object.
      /// @include timers_timer_synchronizing_object.cpp
      timer& synchronizing_object(std::nullptr_t value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the interval elapses.
      /// @remarks The xtd::timers::timer::elapsed event is raised if the xtd::timers::timer::enabled property is true and the time interval (in milliseconds) defined by the xtd::timers::timer::interval property elapses. If the xtd::timers::timer::auto_reset property is true, the event is raised repeatedly at an interval defined by the xtd::timers::timer::interval property; otherwise, the event is raised only once, the first time the xtd::timers::timer::interval value elapses.
      /// @remarks If xtd::timers::timer::interval is set after the xtd::timers::timer has started, the count is reset. For example, if you set the interval to 5 seconds and then set xtd::timers::timer::enabled to true, the count starts at the time xtd::timers::timer::enabled is set. If you reset the interval to 10 seconds when count is 3 seconds, the xtd::timers::timer::elapsed event is raised for the first time 13 seconds after xtd::timers::timer::enabled was set to true.
      /// @remarks If the xtd::timers::timer::synchronizing_object property is std::nullopt,the xtd::timers::timer::elapsed event is raised on a xtd::threading::thread_pool thread. If the processing of the xtd::timers::timer::elapsed event lasts longer than xtd::timers::timer::interval, the event might be raised again on another xtd::threading::thread_pool thread. In this situation, the event handler should be reentrant.
      /// @note The event-handling method might run on one thread at the same time that another thread calls the xtd::timers::timer::stop method or sets the xtd::timers::timer::enabled property to false. This might result in the xtd::timers::timer::elapsed event being raised after the timer is stopped. The example code for the Stop method shows one way to avoid this race condition.
      /// @remarks Even if xtd::timers::timer::synchronizing_object is not std::nullopt, xtd::timers::timer::elapsed events can occur after the xtd::timers::timer::close or xtd::timers::timer::stop method has been called or after the xtd::timers::timer:enabled property has been set to false, because the signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a thread pool thread. One way to resolve this race condition is to set a flag that tells the event handler for the xtd::timers::timer::elapsed event to ignore subsequent events.
      event<timer, elapsed_event_handler> elapsed;
      /// @}

      /// @name Methods
      
      /// @{
      /// @brief Releases the resources used by the xtd::timers::timer.
      void close();

      /// @brief Starts raising the xtd::timers::timer::elapsed event by setting xtd::timers::timer::enabled to true.
      /// @remarks If xtd::timers::timer::start is called and xtd::timers::timer::auto_reset is set to false, the xtd::timers::timer raises the xtd::timers::timer::elapsed event only once, the first time the interval elapses. If xtd::timers::timer::start is called and xtd::timers::timer::auto_reset is true, the xtd::timers::timer raises the xtd::timers::timer::elapsed event the first time the interval elapses and continues to raise the event on the specified interval.
      /// @note If xtd::timers::timer::auto_reset is false, the xtd::timers::timer::start method must be called in order to start the count again.
      void start();

      /// @brief Stops raising the xtd::timers::timer::elapsed event by setting xtd::timers::timer::enabled to false.
      /// @remarks You can also stop timing by setting xtd::timers::timer::enabled to false.
      /// @note The signal to raise the xtd::timers::timer::elapsed event is always queued for execution on a xtd::threading::thread_pool thread, so the event-handling method might run on one thread at the same time that a call to the xtd::timers::timer::stop method runs on another thread. This might result in the xtd::timers::timer::elapsed event being raised after the xtd::timers::timer::stop method is called. The second code example in the Examples section shows one way to work around this race condition.
      void stop();
      /// @}

    private:
      void on_elpased(const elapsed_event_args& e);
      std::shared_ptr<data> data_;
    };
  }
}
