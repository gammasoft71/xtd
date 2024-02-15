/// @file
/// @brief Contains xtd::forms::date_time_picker picker.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "application.h"
#include "control.h"
#include "date_time_picker_format.h"
#include <xtd/chrono>
#include <xtd/date_time>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available date time along with controls.
    /// @par Header
    /// @code #include <xtd/forms/date_time_picker> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html control_date_time_picker_w.png   |  @image html control_date_time_picker_m.png   |  @image html control_date_time_picker_g.png   |
    /// | Dark  |  @image html control_date_time_picker_wd.png  |  @image html control_date_time_picker_md.png  |  @image html control_date_time_picker_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of date_time_picker picker.
    /// @include date_time_picker.cpp
    class forms_export_ date_time_picker : public control {
      struct data;
      
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
      virtual date_time_picker_format format() const noexcept;
      /// @brief Sets the format of the date and time displayed in the control.
      /// @param format One of the date_time_picker_format values. The default is long_format.
      /// @return Current date_time_picker.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual date_time_picker& format(date_time_picker_format format);
      
      /// @brief Gets the maximum date and time that can be selected in the control.
      /// @return The maximum date and time that can be selected in the control.
      virtual date_time max_date() const noexcept;
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param value The maximum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual date_time_picker& max_date(date_time value);
      
      /// @brief Gets the minimum date and time that can be selected in the control.
      /// @return The minimum date and time that can be selected in the control.
      virtual date_time min_date() const noexcept;
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param value The minimum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual date_time_picker& min_date(date_time value);
      
      /// @brief Gets the date/time value assigned to the control.
      /// @return The date and time value assign to the control.
      virtual date_time value() const noexcept;
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual date_time_picker& value(date_time value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create();
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value.
      /// @param value The date and time value assign to the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, and minimum date.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value, const xtd::date_time& min_date);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, and maximum date.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, and location.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, location, and size.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, location, size, and name.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, and minimum date.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, and maximum date.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, and location.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      static date_time_picker create(const control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the drop-down calendar is dismissed and disappears.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<date_time_picker, event_handler> close_up;
      /// @brief Occurs when the drop-down calendar is shown.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<date_time_picker, event_handler> drop_down;
      /// @brief Occurs when the value of the value property changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<date_time_picker, event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      drawing::color default_back_color() const noexcept override;
      drawing::color default_fore_color() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the date_time_picker::close_up event.
      /// @param e An event_args that contains the event data.
      virtual void on_close_up(const event_args& e);
      /// @brief Raises the date_time_picker::drop_down event.
      /// @param e An event_args that contains the event data.
      virtual void on_drop_down(const event_args& e);
      /// @brief Raises the date_time_picker::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_value_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_nottify_control(message& message);
      void wm_nottify_control_closeup(message& message);
      void wm_nottify_control_dropdown(message& message);
      void wm_nottify_control_datetimechange(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
