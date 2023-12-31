/// @file
/// @brief Contains xtd::forms::date_range_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/date_time>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::month_calendar::date_changed or xtd::forms::month_calendar::date_selected events of the xtd::forms::month_calendar control.
    /// @par Header
    /// @code #include <xtd/forms/date_range_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The xtd::forms::month_calendar::date_changed event occurs when the currently selected date or range of dates changes; for example, when the user explicitly changes a selection within the current month or when the selection is implicitly changed in response to next/previous month navigation. The xtd::forms::month_calendar::date_selected event occurs when the user explicitly changes a selection. The xtd::forms::date_range_event_args constructor specifies the start and end for the new date range that has been selected.
    /// @note If a single date is selected, the xtd::forms::date_range_event_args::start and xtd::forms::date_range_event_args::end property values will be equal.
    /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
    class date_range_event_args : public event_args {
    public:
      /// @cond
      date_range_event_args(const date_range_event_args& date_range_event_args) = default;
      date_range_event_args& operator =(const date_range_event_args& date_range_event_args) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::date_range_event_args class.
      /// @param control The control to store in this event.
      date_range_event_args(const xtd::date_time& start, const xtd::date_time& end) : start_(start), end_(end) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the last date/time value in the range that the user has selected.
      /// @return A xtd::date_time that represents the last date in the date range that the user has selected.
      const xtd::date_time& end() const noexcept {return end_;}
      
      /// @brief Gets the first date/time value in the range that the user has selected.
      /// @return A xtd::date_time that represents the first date in the date range that the user has selected.
      const xtd::date_time& start() const noexcept {return start_;}
      //// @}
      
    private:
      xtd::date_time start_;
      xtd::date_time end_;
    };
  }
}
