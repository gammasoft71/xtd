/// @file
/// @brief Contains xtd::forms::timer component.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "component.hpp"
#include <xtd/chrono>
#include <xtd/event>
#include <xtd/event_handler>
#include <xtd/time_span>
#include <cstdint>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/timer>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks A timer is used to raise an event at user-defined intervals. This Windows timer is designed for a single-threaded environment where UI threads are used to perform processing. It requires that the user code have a UI message pump available and always operate from the same thread.
    /// @remarks When you use this timer, use the tick event to perform a polling operation or to display a splash screen for a specified period of time. Whenever the enabled property is set to true and the interval property is greater than zero, the tick event is raised at intervals based on the interval property setting.
    /// @remarks This class provides methods to set the interval, and to start and stop the timer.
    /// @remarks The Windows Forms Timer component is single-threaded, and is limited to an accuracy of 55 milliseconds.
    /// @note xtd includes several timer classes, each of which offers different functionality:
    /// * xtd::timers::timer, which fires an event and executes the code in one or more event sinks at regular intervals. The class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::threading::timer, which executes a single callback method on a thread pool thread at regular intervals. The callback method is defined when the timer is instantiated and cannot be changed. Like the xtd::timers::timer class, this class is intended for use as a server-based or service component in a multithreaded environment; it has no user interface and is not visible at runtime.
    /// * xtd::forms::timer, a Windows Forms component that fires an event and executes the code in one or more event sinks at regular intervals. The component has no user interface and is designed for use in a single-threaded environment; it executes on the UI thread.
    /// @par Examples
    /// The following code example demonstrates the use of timer component.
    /// @include forms_timer.cpp
    class forms_export_ timer : public component {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the timer class.
      /// @remarks When a new timer is created, it is disabled; that is, enabled is set to false. To enable the timer, call the start method or set enabled to true.
      /// @remarks If the timer is disabled and the timer is out of scope, the timer will be destroyed.
      timer();
      /// @}
      
      /// @cond
      timer(timer&&) = default;
      timer(const timer&) = delete;
      ~timer();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets whether the timer is running.
      /// @return true if the timer is currently enabled; otherwise, false. The default is false.
      /// @remarks Calling the start method is the same as setting enabled to true. Likewise, calling the stop method is the same as setting enabled to false.
      virtual bool enabled() const noexcept;
      /// @brief Sets whether the timer is running.
      /// @param enabled true if the timer is currently enabled; otherwise, false. The default is false.
      /// @remarks Calling the start method is the same as setting enabled to true. Likewise, calling the stop method is the same as setting enabled to false.
      virtual timer& enabled(bool enabled);
      
      /// @brief Gets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @return An xtd::time_span specifying the interval before the tick event is raised relative to the last occurrence of the tick event. The value must be greater than zero.
      virtual time_span interval() const noexcept;
      /// @brief Sets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @param interval An xtd::time_span specifying the interval before the tick event is raised relative to the last occurrence of the tick event. The value must be greater than zero.
      timer& interval(const time_span& interval);

      /// @brief Gets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @return An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      virtual int32 interval_milliseconds() const noexcept;
      /// @brief Sets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @param interval An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      virtual timer& interval_milliseconds(int32 interval);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Stops the timer.
      /// @remarks You can also stop the timer by setting the enabled property to false.
      void start();
      
      /// @brief Starts the timer.
      /// @remarks You can also start the timer by setting the enabled property to true.
      void stop();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::timer.
      /// @return New xtd::forms::timer created.
      static timer create();
      /// @brief A factory to create an xtd::forms::timer with specified interval.
      /// @param interval An xtd::time_span specifying the interval before the tick event is raised relative to the last occurrence of the tick event. The value must be greater than zero.
      /// @return New xtd::forms::timer created.
      static timer create(const time_span& interval);
      /// @brief A factory to create an xtd::forms::timer with specified interval, and enable values.
      /// @param interval An xtd::time_span specifying the interval before the tick event is raised relative to the last occurrence of the tick event. The value must be greater than zero.
      /// @param enabled true if the timer is currently enabled; otherwise, false. The default is false.
      /// @return New xtd::forms::timer created.
      static timer create(const time_span& interval, bool enable);
      /// @brief A factory to create an xtd::forms::timer with specified interval.
      /// @param interval_milliseconds An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @return New xtd::forms::timer created.
      static timer create(int interval_milliseconds);
      /// @brief A factory to create an xtd::forms::timer with specified interval, and enable values.
      /// @param interval_milliseconds An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @param enabled true if the timer is currently enabled; otherwise, false. The default is false.
      /// @return New xtd::forms::timer created.
      static timer create(int interval_milliseconds, bool enable);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the specified timer interval has elapsed and the timer is enabled.
      /// @remarks Calling the Assert method on the xtd::diagnostics::debug class from within the tick event may not behave as expected, as displaying the assertion dialog box may cause Windows to raise the tick event repeatedly. We recommend that you refrain from testing assertions within this event, and use the write, write_if, write_line, or write_line_if methods instead.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<timer, event_handler> tick;
      /// @}
      
    protected:
      /// @name Prootected methods
      
      /// @{
      /// @brief Raises the xtd::forms::timer::tick event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      virtual void on_tick(const event_args& e);
      /// @}
      
    private:
      void restart();
      
      xtd::sptr<data> data_;
    };
  }
}
