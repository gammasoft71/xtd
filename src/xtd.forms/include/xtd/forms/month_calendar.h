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
      virtual std::vector<xtd::date_time> annually_bolded_dates() const;
      /// @brief Sets the array of xtd::date_time objects that determines which annual days are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarksUsing this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      virtual month_calendar& annually_bolded_dates(const std::vector<xtd::date_time>& value);

      /// @brief Gets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @return An array of xtd::date_time objects.
      /// @remarks Using this property, you can assign an array of annual bold dates. When you assign an array of dates, the existing dates are first cleared.
      virtual std::vector<xtd::date_time> bolded_dates() const;
      /// @brief Sets the array of xtd::date_time bjects that determines which nonrecurring dates are displayed in bold.
      /// @param value An array of xtd::date_time objects.
      /// @return Current month_calendar.
      /// @remarks Using this property, you can assign an array of bold dates. When you assign an array of dates, the existing dates are first cleared.
      virtual month_calendar& bolded_dates(const std::vector<xtd::date_time>& value);

      drawing::size default_size() const override {return {240, 162};}
      
      /// @brief Gets the maximum date that can be selected in the control.
      /// @return The maximum date that can be selected in the control.
      virtual date_time max_date() const;
      /// @brief Sets the maximum date that can be selected in the control.
      /// @param value The maximum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual month_calendar& max_date(date_time value);
      
      /// @brief Gets the minimum date that can be selected in the control.
      /// @return The minimum date that can be selected in the control.
      virtual date_time min_date() const;
      /// @brief Sets the minimum date that can be selected in the control.
      /// @param value The minimum date that can be selected in the control.
      /// @return Current month_calendar.
      virtual month_calendar& min_date(date_time value);
      
      virtual date_time selection_end() const;
      virtual month_calendar& selection_end(date_time value);
      
      virtual date_time selection_start() const;
      virtual month_calendar& selection_start(date_time value);
      
      virtual forms::selection_range selection_range() const;
      virtual month_calendar& selection_range(const forms::selection_range& value);
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
        date_time selection_start = date_time::now();
        date_time selection_end = date_time::now();
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
