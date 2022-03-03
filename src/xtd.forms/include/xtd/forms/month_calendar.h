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
    class forms_export_ month_calendar : public control {
    public:
      /// @name Constructors
      /// @{
      /// @brief Initializes a new instance of the month_calendar class.
      month_calendar();
      /// @}
      
      /// @name Properties
      /// @{
      drawing::size default_size() const override {return {227, 162};}
      
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
        date_time min_date = date_time::min_value;
        date_time max_date = date_time::max_value;
        date_time selection_start = date_time::now();
        date_time selection_end = date_time::now();
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
