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
    /// @brief Represents a calendar control that displays a range date.
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
      month_calendar();
      /// @}

      /// @name Properties
      /// @{
      drawing::size default_size() const override {return {150, 120};}

      /// @brief Gets the date range of the calendar.
      /// @return pair of 'from date' and 'to date' value range.
      virtual std::pair<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point> date_range() const;
      /// @brief Sets date range to the calendar.
      /// @param from_date: lower date of the calendar.
      /// @param to_date: upper date of the calendar.
      /// @return Current month_calendar.
      virtual control& date_range(const std::chrono::system_clock::time_point from_date, const std::chrono::system_clock::time_point to_date);

#pragma region questionable
#if 0
      /// @brief Gets the format of the date and time displayed in the control.
      /// @return One of the month_calendar_format values. The default is long_format.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual month_calendar_format format() const {return format_;}
      /// @brief Sets the format of the date and time displayed in the control.
      /// @param format One of the month_calendar_format values. The default is long_format.
      /// @return Current month_calendar.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual control& format(month_calendar_format format);
#endif
#pragma endregion

      /// @brief Gets the maximum date and time that can be selected in the control.
      /// @return The maximum date and time that can be selected in the control.
      virtual std::chrono::system_clock::time_point max_date() const {return max_date_;}
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(std::chrono::system_clock::time_point max_date);
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(time_t max_date) {return this->max_date(std::chrono::system_clock::from_time_t(max_date));}
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(const std::tm& max_date) {
        std::tm internal_max_date = max_date;
        return this->max_date(mktime(&internal_max_date));
      }
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& max_date(int32_t year, int32_t month, int32_t day) {
        std::tm internal_max_date = {};
        internal_max_date.tm_year = year - 1900;
        internal_max_date.tm_mon = month - 1;
        internal_max_date.tm_mday = day;
        return max_date(std::mktime(&internal_max_date));
      }
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
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

      /// @brief Gets the minimum date and time that can be selected in the control.
      /// @return The minimum date and time that can be selected in the control.
      virtual std::chrono::system_clock::time_point min_date() const {return max_date_;}
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param max_date The minimum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(std::chrono::system_clock::time_point min_date);
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param max_date The minimum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(time_t min_date) {return this->min_date(std::chrono::system_clock::from_time_t(min_date));}
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param max_date The minimum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(const std::tm& min_date) {
        std::tm internal_min_date = min_date;
        return this->min_date(std::mktime(&internal_min_date));
      }
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param max_date The minimum date and time that can be selected in the control.
      /// @return Current month_calendar.
      virtual control& min_date(int32_t year, int32_t month, int32_t day) {
        std::tm internal_min_date = {};
        internal_min_date.tm_year = year - 1900;
        internal_min_date.tm_mon = month - 1;
        internal_min_date.tm_mday = day;
        return min_date(std::mktime(&internal_min_date));
      }
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param max_date The minimum date and time that can be selected in the control.
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

      /// @brief Gets the date/time value assigned to the control.
      /// @return The date and time value assign to the control.
      virtual std::chrono::system_clock::time_point value() const {return value_;}
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(std::chrono::system_clock::time_point value);
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(time_t value) {return this->value(std::chrono::system_clock::from_time_t(value));}
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(const std::tm& value) {
        std::tm internal_value = value;
        return this->value(std::mktime(&internal_value));
      }
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(int32_t year, int32_t month, int32_t day) {
        return value(year, month, day, 0, 0, 0);
      }
      /// @brief Sets the date/time value assigned to the control.
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
      
      /// @brief Raises the month_calendar::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_click(message& message);
      //month_calendar_format format_ = month_calendar_format::long_format;
      std::chrono::system_clock::time_point max_date_ = std::chrono::system_clock::time_point::max();
      std::chrono::system_clock::time_point min_date_ = std::chrono::system_clock::time_point::min();
      std::chrono::system_clock::time_point value_ = std::chrono::system_clock::now();
    };
  }
}
