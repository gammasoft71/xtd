/// @file
/// @brief Contains xtd::forms::month_calendar control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a control that displays a month calendar.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of month_calendar control.
    /// @include month_calendar.cpp
    class forms_export_ month_calendar : public control {
    public:
      /// @name Constructors
      /// @{
      /// @brief Initializes a new instance of the month_calendar class.
      month_calendar() = default;
      /// @}
      /// @name Properties
      /// @{
      drawing::size default_size() const override { return {227, 162}; }

      /// @brief Gets the maximum date that can be selected in the control.
      /// @return The maximum date that can be selected in the control.
      virtual std::chrono::system_clock::time_point max_date() const {return max_date_;}
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param max_date The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(std::chrono::system_clock::time_point max_date);
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param max_date The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(time_t max_date) {return this->max_date(std::chrono::system_clock::from_time_t(max_date));}
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param max_date The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(const std::tm& max_date) {
        std::tm internal_max_date = max_date;
        return this->max_date(mktime(&internal_max_date));
      }
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param max_date The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(int32_t year, int32_t month, int32_t day) {
        std::tm internal_max_date = {};
        internal_max_date.tm_year = year - 1900;
        internal_max_date.tm_mon = month - 1;
        internal_max_date.tm_mday = day;
        return max_date(std::mktime(&internal_max_date));
      }
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param max_date The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
        std::tm internal_max_date = {};
        internal_max_date.tm_year = year - 1900;
        internal_max_date.tm_mon = month - 1;
        internal_max_date.tm_mday = day;
        internal_max_date.tm_hour = hour;
        internal_max_date.tm_min = minute;
        internal_max_date.tm_sec = second;
        return max_date(std::mktime(&internal_max_date));
      }

      /// @brief Gets the minimum date that can be selected in the control.
      /// @return The minimum date that can be selected in the control.
      virtual std::chrono::system_clock::time_point min_date() const {return max_date_;}
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param max_date The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(std::chrono::system_clock::time_point min_date);
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param max_date The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(time_t min_date) {return this->min_date(std::chrono::system_clock::from_time_t(min_date));}
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param max_date The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(const std::tm& min_date) {
        std::tm internal_min_date = min_date;
        return this->min_date(std::mktime(&internal_min_date));
      }
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param max_date The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(int32_t year, int32_t month, int32_t day) {
        std::tm internal_min_date = {};
        internal_min_date.tm_year = year - 1900;
        internal_min_date.tm_mon = month - 1;
        internal_min_date.tm_mday = day;
        return min_date(std::mktime(&internal_min_date));
      }
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param max_date The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
        std::tm internal_min_date = {};
        internal_min_date.tm_year = year - 1900;
        internal_min_date.tm_mon = month - 1;
        internal_min_date.tm_mday = day;
        internal_min_date.tm_hour = hour;
        internal_min_date.tm_min = minute;
        internal_min_date.tm_sec = second;
        return min_date(std::mktime(&internal_min_date));
      }

      /// @brief Gets the date value assigned to the control.
      /// @return The date and time value assign to the control.
      virtual std::chrono::system_clock::time_point value() const {return value_;}
      /// @brief Sets the date value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(std::chrono::system_clock::time_point value);
      /// @brief Sets the date value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(time_t value) {return this->value(std::chrono::system_clock::from_time_t(value));}
      /// @brief Sets the date value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(const std::tm& value) {
        std::tm internal_value = value;
        return this->value(std::mktime(&internal_value));
      }
      /// @brief Sets the date value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(int32_t year, int32_t month, int32_t day) {
        return value(year, month, day, 0, 0, 0);
      }
      /// @brief Sets the date value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second) {
        std::tm internal_value = {};
        internal_value.tm_year = year - 1900;
        internal_value.tm_mon = month - 1;
        internal_value.tm_mday = day;
        internal_value.tm_hour = hour;
        internal_value.tm_min = minute;
        internal_value.tm_sec = second;
        return value(std::mktime(&internal_value));
      }
      /// @}
      
      /// @name Events
      
      /// @{
      event<month_calendar, event_handler> date_changed;
      event<month_calendar, event_handler> date_selected;
      /// @brief Occurs when the value of the value property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<month_calendar, event_handler> value_changed;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      virtual void on_date_changed(const event_args& e);
      virtual void on_date_selected(const event_args& e);
      /// @brief Raises the month_calendar::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);

      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_notify(message& message);
      void wm_date_selected(message& message);
      void wm_date_changed(message& message);
      void wm_view_changed(message& message);

      std::chrono::system_clock::time_point max_date_ = std::chrono::system_clock::time_point::max();
      std::chrono::system_clock::time_point min_date_ = std::chrono::system_clock::time_point::min();
      std::chrono::system_clock::time_point value_ = std::chrono::system_clock::now();
    };
  }
}
