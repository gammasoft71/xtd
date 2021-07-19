/// @file
/// @brief Contains xtd::forms::timer component.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <chrono>
#include <memory>
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include "component.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks A timer is used to raise an event at user-defined intervals. This Windows timer is designed for a single-threaded environment where UI threads are used to perform processing. It requires that the user code have a UI message pump available and always operate from the same thread.
    /// @remarks When you use this timer, use the tick event to perform a polling operation or to display a splash screen for a specified period of time. Whenever the enabled property is set to true and the interval property is greater than zero, the tick event is raised at intervals based on the interval property setting.
    /// @remarks This class provides methods to set the interval, and to start and stop the timer.
    /// @remarks The Windows Forms Timer component is single-threaded, and is limited to an accuracy of 55 milliseconds.
    /// @par Examples
    /// The following code example demonstrate the use of timer component.
    /// @include timer.cpp
    /// @par Windows
    /// @image html timer_w.png
    /// <br>
    /// @image html timer_wd.png
    /// @par macOS
    /// @image html timer_m.png
    /// <br>
    /// @image html timer_md.png
    /// @par Gnome
    /// @image html timer_g.png
    /// <br>
    /// @image html timer_gd.png
    class forms_export_ timer final : public component {
    public:
      /// @brief Initializes a new instance of the timer class.
      /// @remarks When a new timer is created, it is disabled; that is, enabled is set to false. To enable the timer, call the start method or set enabled to true.
      /// @remarks If the timer is disabled and the timer is out of scope, the timer will be destroyed.
      timer() = default;

      /// @cond
      timer(const timer&) = delete;
      ~timer() {stop();}
      /// @endcond
      
      /// @brief Occurs when the specified timer interval has elapsed and the timer is enabled.
      /// @ingroup events
      /// @remarks Calling the Assert method on the xtd::diadnostics::debug class from within the tick event may not behave as expected, as displaying the assertion dialog box may cause Windows to raise the tick event repeatedly. We recommend that you refrain from testing assertions within this event, and use the write, write_if, write_line, or write_line_if methods instead.
      event<timer, event_handler> tick;

      /// @brief Gets whether the timer is running.
      /// @return true if the timer is currently enabled; otherwise, false. The default is false.
      /// @remarks Calling the start method is the same as setting enabled to true. Likewise, calling the stop method is the same as setting enabled to false.
      bool enabled() const {return enabled_;}
      /// @brief Sets whether the timer is running.
      /// @param enabled true if the timer is currently enabled; otherwise, false. The default is false.
      /// @remarks Calling the start method is the same as setting enabled to true. Likewise, calling the stop method is the same as setting enabled to false.
      void enabled(bool enabled);

      /// @brief Gets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @return An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      std::chrono::milliseconds interval() const {return std::chrono::milliseconds(interval_);}
      /// @brief Sets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @param interval An int32_t specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      template<typename rep_t, typename period_t = std::ratio<1>>
      void interval(const std::chrono::duration<rep_t, period_t>& interval) {interval_milliseconds(static_cast<int32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(interval).count()));}

      /// @brief Gets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @return An int32 specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      int32_t interval_milliseconds() const {return interval_;}
      /// @brief Sets the time, in milliseconds, before the tick event is raised relative to the last occurrence of the tick event.
      /// @param interval An int32_t specifying the number of milliseconds before the tick event is raised relative to the last occurrence of the tick event. The value cannot be less than one.
      /// @remarks To get the number of seconds in the interval, divide this number by 1,000.
      void interval_milliseconds(int32_t interval);

      /// @brief Stops the timer.
      /// @remarks You can also stop the timer by setting the enabled property to fallse.
      void start() {enabled(true);}

      /// @brief Starts the timer.
      /// @remarks You can also start the timer by setting the enabled property to true.
      void stop() {enabled(false);}

    protected:
      /// @brief Raises the Tick event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      void on_tick(const event_args& e);
      
    private:
      bool enabled_ = false;
      int32_t interval_ = 100;
      intptr_t handle_ = 0;
    };
  }
}
