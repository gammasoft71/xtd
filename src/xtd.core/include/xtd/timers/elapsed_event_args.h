/// @file
/// @brief Contains xtd::timers::elapsed_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../date_time.h"
#include "../event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the xtd::timers::timer component, which allows you to raise an event on a specified interval.
  namespace timers {
    /// @brief Provides data for the xtd::timers::timer::elapsed event.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core events
    class elapsed_event_args : public xtd::event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the elapsed_event_args class.
      elapsed_event_args() = default;
      
      /// @brief Initializes a new instance of the elapsed_event_args class with specified signal time.
      /// @param signal_time The time the xtd::timers::timer::elapsed event was raised.
      explicit elapsed_event_args(const xtd::date_time& signal_time);
      /// @}
      
      /// @cond
      elapsed_event_args(const elapsed_event_args&) = default;
      elapsed_event_args& operator =(const elapsed_event_args&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the date/time when the xtd::timers::timer::elapsed event was raised.
      /// @return The time the xtd::timers::timer::elapsed event was raised.
      const xtd::date_time& signal_time() const noexcept;
      /// @}
      
    private:
      xtd::date_time signal_time_;
    };
  }
}
