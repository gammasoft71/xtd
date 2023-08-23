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
    /// @par Examples
    /// The following example instantiates a xtd::timers::timer object that fires its xtd::timers::timer::elapsed event every two seconds (2,000 milliseconds), sets up an event handler for the event, and starts the timer. The event handler displays the value of the xtd::timers::elapsed_event_args::signal_time property each time it is raised.
    /// @include timers_timer.cpp
    class core_export_ timer : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the Timer class, and sets all the properties to their initial values.
      timer();
      explicit timer(double interval);
      explicit timer(const xtd::time_span& interval);
      /// @}

      /// @cond
      timer(const timer& timer);
      timer& operator=(const timer& timer);
      ~timer();
      /// @endcond
      
      /// @name Properties
      
      /// @{
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
