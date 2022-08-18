/// @file
/// @brief Contains xtd::forms::date_time_picker picker.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <xtd/date_time.h>
#include "application.h"
#include "control.h"
#include "date_time_picker_format.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available date time along with controls.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of date_time_picker picker.
    /// @include date_time_picker.cpp
    class forms_export_ date_time_picker : public control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the date_time_picker class.
      date_time_picker();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the format of the date and time displayed in the control.
      /// @return One of the date_time_picker_format values. The default is long_format.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual date_time_picker_format format() const {return format_;}
      /// @brief Sets the format of the date and time displayed in the control.
      /// @param format One of the date_time_picker_format values. The default is long_format.
      /// @return Current date_time_picker.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual control& format(date_time_picker_format format);
      
      /// @brief Gets the maximum date and time that can be selected in the control.
      /// @return The maximum date and time that can be selected in the control.
      virtual date_time max_date() const;
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param value The maximum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual control& max_date(date_time value);
      
      /// @brief Gets the minimum date and time that can be selected in the control.
      /// @return The minimum date and time that can be selected in the control.
      virtual date_time min_date() const;
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param value The minimum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual control& min_date(date_time value);
      
      /// @brief Gets the date/time value assigned to the control.
      /// @return The date and time value assign to the control.
      virtual date_time value() const;
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual control& value(date_time value);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the value of the value property changes.
      /// @ingroup events
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      event<date_time_picker, event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      forms::create_params create_params() const override;
      drawing::color default_back_color() const override {return application::style_sheet().system_colors().window();}
      drawing::color default_fore_color() const override {return application::style_sheet().system_colors().window_text();}
      
      /// @brief Raises the date_time_picker::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_click(message& message);
      date_time_picker_format format_ = date_time_picker_format::long_format;
      date_time max_date_ = date_time::max_value;
      date_time min_date_ = date_time::min_value;
      date_time value_ = date_time::now();
    };
  }
}
