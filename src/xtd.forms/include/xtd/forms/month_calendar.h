/// @file
/// @brief Contains xtd::forms::month_calendar control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include "control.h"
#include "selection_range.h"

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
    /// The following code example demonstrates the use of month_calendar control.
    /// @include month_calendar.cpp
    /// @remarks The xtd::forms::month_calendar control allows the user to select a date using a visual display. You can limit the date and times that can be selected by setting the xtd::forms::month_calendar::min_date and xtd::forms::month_calendar::max_date properties.
    /// @remarks You can change the look of the calendar portion of the control by setting the xtd::forms::month_calendar::fore_color, xtd::forms::month_calendar::font, xtd::forms::month_calendar::title_back_color, xtd::forms::month_calendar::title_fore_color, xtd::forms::month_calendar::trailing_fore_color, and xtd::forms::month_calendar::back_color properties.
    /// @note The xtd::forms::month_calendar control only supports Gregorian calendars.
    /// @remarks The xtd::forms::month_calendar control is drawn by the operating system, so the xtd::forms::month_calendar::paint event is never raised. If you need to provide a customized look to the xtd::forms::month_calendar control, you should override the xtd::forms::month_calendar::on_print method, call the base implementation of xtd::forms::control::on_print, and then perform custom painting.
    /// @remarks If you need custom date formatting and a selection limited to just one date, you might consider using a xtd::forms::month_calendar::date_time_picker control instead of a xtd::forms::month_calendar. Using the xtd::forms::month_calendar::date_time_picker eliminates much of the need for validating date/time values.
    class forms_export_ month_calendar : public control {
    public:
      /// @name Constructors
      /// @{
      /// @brief Initializes a new instance of the month_calendar class.
      /// @par Examples
      /// The following code example demonstrates the use of month_calendar control.
      /// @include month_calendar.cpp
      /// @remarks The xtd::forms::month_calendar constructor creates a new xtd::forms::month_calendar.
      month_calendar();
      /// @}
      
      /// @name Properties
      /// @{
      /// @brief Gets the array of xtd::date_time objects that determines which annual days are displayed in bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> annually_bolded_dates() const;
      /// @brief Sets the array of xtd::date_time objects that determines which annual days are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& annually_bolded_dates(const std::vector<xtd::date_time>& value);

      /// @brief Gets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> bolded_dates() const;
      /// @brief Sets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& bolded_dates(const std::vector<xtd::date_time>& value);

      drawing::size default_size() const override {return {240, 162};}
      
      /// @brief Gets the maximum date that can be selected in the control.
      /// @return The maximum date that can be selected in the control.
      date_time max_date() const;
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param value The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      month_calendar& max_date(date_time value);
      
      /// @brief Gets the minimum date that can be selected in the control.
      /// @return The minimum date that can be selected in the control.
      date_time min_date() const;
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param value The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      month_calendar& min_date(date_time value);
      
      /// @brief Gets the array of xtd::date_time objects that determine which monthly days to bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      std::vector<xtd::date_time> monthly_bolded_dates() const;
      /// @brief Sets the array of xtd::date_time objects that determine which monthly days to bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      month_calendar& monthly_bolded_dates(const std::vector<xtd::date_time>& value);
      
      /// @brief Gets the end date of the selected range of dates.
      /// @return A xtd::date_time indicating the last date in the selection range.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_end property to a date that is earlier than the current value of the xtd::forms::month_calendar::selection_start property, xtd::forms::month_calendar::selection_start is automatically set equal to xtd::forms::month_calendar::selection_end.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_end that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_start is adjusted; xtd::forms::month_calendar::selection_start is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      date_time selection_end() const;
      /// @brief Sets the end date of the selected range of dates.
      /// @param value A xtd::date_time indicating the last date in the selection range.
      /// @return Current month_calendar.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_end property to a date that is earlier than the current value of the xtd::forms::month_calendar::selection_start property, xtd::forms::month_calendar::selection_start is automatically set equal to xtd::forms::month_calendar::selection_end.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_end that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_start is adjusted; xtd::forms::month_calendar::selection_start is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      month_calendar& selection_end(date_time value);

      /// @brief Gets the selected range of dates for a month calendar control.
      /// @return A xtd::forms::selection_range with the start and end dates of the selected range.
      /// @remarks Setting this property is functionally equivalent to using the xtd::forms::month_calendar::set_selection_range method. You can set the start and end dates separately by setting either the xtd::forms::month_calendar::selection_start or xtd::forms::month_calendar::selection_end properties. You cannot change the start and end dates by setting the xtd::forms::selection_range::start or xtd::forms::selection_range::end property values of the xtd::forms::month_calendar::selection_range property. You should use xtd::forms::month_calendar::selection_start, xtd::forms::month_calendar::selection_end, or xtd::forms::month_calendar::set_selection_range.
      /// @remarks If the Start property value of the xtd::forms::month_calendar::selection_range is greater than its xtd::forms::selection_rande::end property value, the dates are swapped; the xtd::forms::selection_range::end property value becomes the starting date, and xtd::forms::selection_range::start property value becomes the end date.
      forms::selection_range selection_range() const;
      /// @brief Sets the selected range of dates for a month calendar control.
      /// @param value A xtd::forms::selection_range with the start and end dates of the selected range.
      /// @return Current month_calendar.
      /// @remarks Setting this property is functionally equivalent to using the xtd::forms::month_calendar::set_selection_range method. You can set the start and end dates separately by setting either the xtd::forms::month_calendar::selection_start or xtd::forms::month_calendar::selection_end properties. You cannot change the start and end dates by setting the xtd::forms::selection_range::start or xtd::forms::selection_range::end property values of the xtd::forms::month_calendar::selection_range property. You should use xtd::forms::month_calendar::selection_start, xtd::forms::month_calendar::selection_end, or xtd::forms::month_calendar::set_selection_range.
      /// @remarks If the Start property value of the xtd::forms::month_calendar::selection_range is greater than its xtd::forms::selection_rande::end property value, the dates are swapped; the xtd::forms::selection_range::end property value becomes the starting date, and xtd::forms::selection_range::start property value becomes the end date.
      month_calendar& selection_range(const forms::selection_range& value);
      
      /// @brief Gets the start date of the selected range of dates.
      /// @return A xtd::date_time indicating the first date in the selection range.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_start property to a date that is later than the current value of the xtd::forms::month_calendar::selection_end property, xtd::forms::month_calendar::selection_end is automatically set equal to xtd::forms::month_calendar::selection_start.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_start that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_end is adjusted; xtd::forms::month_calendar::selection_end is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      date_time selection_start() const;
      /// @brief Sets the start date of the selected range of dates.
      /// @param value A xtd::date_time indicating the first date in the selection range.
      /// @return Current month_calendar.
      /// @remarks If you set the value of the xtd::forms::month_calendar::selection_start property to a date that is later than the current value of the xtd::forms::month_calendar::selection_end property, xtd::forms::month_calendar::selection_end is automatically set equal to xtd::forms::month_calendar::selection_start.
      /// @remarks If you set a date in xtd::forms::month_calendar::selection_start that causes the selection to exceed the number of days specified by the xtd::forms::month_calendar::max_selection_count property, the value of xtd::forms::month_calendar::selection_end is adjusted; xtd::forms::month_calendar::selection_end is automatically set so that the number of days selected is equal to xtd::forms::month_calendar::max_selection_count.
      /// @note xtd::forms::month_calendar::max_selection_count represents the number of days in the selection, not the difference between xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end. For example, if xtd::forms::month_calendar::max_selection_count is 7 (the default), then xtd::forms::month_calendar::selection_start and xtd::forms::month_calendar::selection_end can be no more than six days apart.
      /// @note Setting the xtd::forms::month_calendar::selection_range for a xtd::forms::month_calendar control that has visual styles enabled will result in the selection range not painting correctly on the control.
      month_calendar& selection_start(date_time value);
      
      /// @brief Gets a value indicating whether the date represented by the xtd::today_date property is displayed at the bottom of the control.
      /// @return true if today's date is displayed; otherwise, false. The default is true.
      /// @remarks The date is displayed in the format specified by the system settings for the short date format.
      bool show_today() const;
      /// @brief Sets a value indicating whether the date represented by the xtd::today_date property is displayed at the bottom of the control.
      /// @param value true if today's date is displayed; otherwise, false. The default is true.
      /// @return Current month_calendar.
      /// @remarks The date is displayed in the format specified by the system settings for the short date format.
      month_calendar& show_today(bool value);

      /// @brief Gets a value indicating whether the month calendar control displays week numbers (1-52) to the left of each row of days.
      /// @return true if the week numbers are displayed; otherwise, false. The default is false.
      bool show_week_numbers() const;
      /// @brief Sets a value indicating whether the month calendar control displays week numbers (1-52) to the left of each row of days.
      /// @param value true if the week numbers are displayed; otherwise, false. The default is false.
      /// @return Current month_calendar.
      month_calendar& show_week_numbers(bool value);
      
      /// @brief Gets the value that is used by MonthCalendar as today's date.
      /// @return A xtd::date_time representing today's date. The default value is the current system date.
      /// @remarks By default, the xtd::forms::month_calendar::today_date property returns the current system date, and the xtd::forms::month_calendar::today_date_set property is false. Setting the TodayDate property sets the xtd::forms::month_calendar::today_date_set property to true and, from that point, the value returned by the xtd::forms::month_calendar::roday_date property is the one the user sets.
      const xtd::date_time& today_date() const;
      /// @brief Sets the value that is used by MonthCalendar as today's date.
      /// @param value A xtd::date_time representing today's date. The default value is the current system date.
      /// @return Current month_calendar.
      /// @remarks By default, the xtd::forms::month_calendar::today_date property returns the current system date, and the xtd::forms::month_calendar::today_date_set property is false. Setting the TodayDate property sets the xtd::forms::month_calendar::today_date_set property to true and, from that point, the value returned by the xtd::forms::month_calendar::roday_date property is the one the user sets.
      month_calendar& today_date(const xtd::date_time& value);

      /// @brief Gets a value indicating whether the xtd::forms::month_calendar::today_date property has been explicitly set.
      /// @return true if the value for the xtd::forms::month_calendar::today_date property has been explicitly set; otherwise, false. The default is false.
      bool today_date_set() const;
      /// @}
      
      /// @name Events
      
      /// @{
      event<month_calendar, event_handler> date_changed;
      event<month_calendar, event_handler> date_selected;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      virtual void on_date_changed(const event_args& e);
      virtual void on_date_selected(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_notify(message& message);
      void wm_date_selected(message& message);
      void wm_date_changed(message& message);
      void wm_view_changed(message& message);
      
      struct data {
        std::vector<xtd::date_time> annually_bolded_dates;
        std::vector<xtd::date_time> bolded_dates;
        date_time min_date = date_time::min_value;
        date_time max_date = date_time::max_value;
        std::vector<xtd::date_time> monthly_bolded_dates;
        date_time selection_start = date_time::now();
        date_time selection_end = date_time::now();
        bool show_today = true;
        bool show_week_numbers = false;
        xtd::date_time today_date = xtd::date_time::now();
        bool today_date_set = false;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
