/// @file
/// @brief Contains xtd::forms::date_time_picker picker.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "control.hpp"
#include "date_time_picker_format.hpp"
#include <xtd/chrono>
#include <xtd/date_time>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a picker control that displays available date time along with controls.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/date_time_picker>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html control_date_time_picker_w.png   |  @image html control_date_time_picker_m.png   |  @image html control_date_time_picker_g.png   |
    /// | Dark  |  @image html control_date_time_picker_wd.png  |  @image html control_date_time_picker_md.png  |  @image html control_date_time_picker_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of date_time_picker picker.
    /// @include date_time_picker.cpp
    class forms_export_ date_time_picker : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the date_time_picker class.
      date_time_picker();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the format of the date and time displayed in the control.
      /// @return One of the date_time_picker_format values. The default is long_format.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      [[nodiscard]] virtual auto format() const noexcept -> xtd::forms::date_time_picker_format;
      /// @brief Sets the format of the date and time displayed in the control.
      /// @param value One of the date_time_picker_format values. The default is long_format.
      /// @return Current date_time_picker.
      /// @remarks This property determines the date/time format the date is displayed in. The date/time format is based on the user's regional settings in their operating system.
      virtual auto format(xtd::forms::date_time_picker_format value) -> date_time_picker&;
      
      /// @brief Gets the maximum date and time that can be selected in the control.
      /// @return The maximum date and time that can be selected in the control.
      [[nodiscard]] virtual auto max_date() const noexcept -> xtd::date_time;
      /// @brief Sets the maximum date and time that can be selected in the control.
      /// @param value The maximum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual auto max_date(xtd::date_time value) -> date_time_picker&;
      
      /// @brief Gets the minimum date and time that can be selected in the control.
      /// @return The minimum date and time that can be selected in the control.
      [[nodiscard]] virtual auto min_date() const noexcept -> xtd::date_time;
      /// @brief Sets the minimum date and time that can be selected in the control.
      /// @param value The minimum date and time that can be selected in the control.
      /// @return Current date_time_picker.
      virtual auto min_date(xtd::date_time value) -> date_time_picker&;
      
      /// @brief Gets the date/time value assigned to the control.
      /// @return The date and time value assign to the control.
      [[nodiscard]] virtual auto value() const noexcept -> xtd::date_time;
      /// @brief Sets the date/time value assigned to the control.
      /// @param value The date and time value assign to the control.
      virtual auto value(xtd::date_time value) -> date_time_picker&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create() -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value.
      /// @param value The date and time value assign to the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, and location.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, location, and size.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, location, size, and name.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, and minimum date.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& max_date) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, maximum date, and location.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, maximum date, location, and size.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, maximum date, location, size, and name.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, and maximum date.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, and location.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, location, and size.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified value, minimum date, maximum date, location, size, and name.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, and value.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, and location.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, and maximum date.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& max_date) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, maximum date, and location.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, maximum date, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, maximum date, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, and maximum date.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, and location.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size) -> date_time_picker;
      /// @brief A factory to create an xtd::forms::date_time_picker with specified parent, value, minimum date, maximum date, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::date_time_picker.
      /// @param value The date and time value assign to the control.
      /// @param min_date The minimum date and time that can be selected in the control.
      /// @param max_date The maximum date and time that can be selected in the control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::date_time_picker.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::date_time_picker.
      /// @param name The name of the xtd::forms::date_time_picker.
      /// @return New xtd::forms::date_time_picker created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::date_time& value, const xtd::date_time& min_date, const xtd::date_time& max_date, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> date_time_picker;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the drop-down calendar is dismissed and disappears.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<date_time_picker, xtd::event_handler> close_up;
      /// @brief Occurs when the drop-down calendar is shown.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<date_time_picker, xtd::event_handler> drop_down;
      /// @brief Occurs when the value of the value property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<date_time_picker, xtd::event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      [[nodiscard]] auto default_back_color() const noexcept -> xtd::drawing::color override;
      [[nodiscard]] auto default_fore_color() const noexcept -> xtd::drawing::color override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Raises the date_time_picker::close_up event.
      /// @param e An event_args that contains the event data.
      virtual auto on_close_up(const xtd::event_args& e) -> void;
      /// @brief Raises the date_time_picker::drop_down event.
      /// @param e An event_args that contains the event data.
      virtual auto on_drop_down(const xtd::event_args& e) -> void;
      /// @brief Raises the date_time_picker::value_changed event.
      /// @param e An event_args that contains the event data.
      virtual auto on_value_changed(const xtd::event_args& e) -> void;
      
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
    private:
      auto wm_nottify_control(xtd::forms::message& message) -> void;
      auto wm_nottify_control_closeup(xtd::forms::message& message) -> void;
      auto wm_nottify_control_dropdown(xtd::forms::message& message) -> void;
      auto wm_nottify_control_datetimechange(xtd::forms::message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
