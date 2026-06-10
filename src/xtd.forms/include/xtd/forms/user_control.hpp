/// @file
/// @brief Contains xtd::forms::user_control control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.hpp"
#include "border_style.hpp"
#include "container_control.hpp"
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows user control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/user_control>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of user control.
    /// @include user_control.cpp
    class forms_export_ user_control : public xtd::forms::container_control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialises a new instance of user_control class.
      user_control();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the mode by which the user_control automatically resizes itself.
      /// @return An auto_size_mode enumerated value. The default is grow_only.
      [[nodiscard]] virtual auto auto_size_mode() const noexcept -> xtd::forms::auto_size_mode;
      /// @brief Sets the mode by which the panel automatically resizes itself.
      /// @param value An auto_size_mode enumerated value. The default is grow_only.
      /// @return Current user_control instance.
      virtual auto auto_size_mode(xtd::forms::auto_size_mode value) -> user_control&;
      
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      [[nodiscard]] virtual auto border_sides() const noexcept -> xtd::forms::border_sides;
      /// @brief Sets the border sides for the control.
      /// @param value A bitwise combination of the border_sides values. The default is border_style::all.
      virtual auto border_sides(xtd::forms::border_sides value) -> user_control&;
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      [[nodiscard]] virtual auto border_style() const noexcept -> xtd::forms::border_style;
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current user_control instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::forms::border_style value) -> user_control&;
      /// @brief Resets the border style for the control.
      /// @param xtd::null.
      /// @return Current user_control instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::null_ptr) -> user_control&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create() -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @param name The name of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> user_control;
      /// @brief A factory to create an xtd::forms::user_control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::user_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::user_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::user_control.
      /// @param name The name of the xtd::forms::user_control.
      /// @return New xtd::forms::user_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> user_control;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected methodds
      
      /// @{
      auto on_layout(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
