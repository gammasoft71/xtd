/// @file
/// @brief Contains xtd::forms::up_down_base control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.hpp"
#include "border_style.hpp"
#include "container_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality required by a spin box (also known as an up-down control).
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/up_down_base>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ up_down_base : public xtd::forms::container_control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      [[nodiscard]] virtual auto border_sides() const noexcept -> xtd::forms::border_sides;
      /// @brief Sets the border sides for the control.
      /// @param value A bitwise combination of the border_sides values. The default is border_style::all.
      virtual auto border_sides(xtd::forms::border_sides value) -> up_down_base&;
      
      /// @brief Gets the border style for the spin box (also known as an up-down control).
      /// @return One of the border_style values. The default value is fixed_single.
      [[nodiscard]] virtual auto border_style() const noexcept -> xtd::forms::border_style;
      /// @brief Sets the border style for the spin box (also known as an up-down control).
      /// @param value One of the border_style values. The default value is fixed_single.
      /// @return Current up_down_base.
      virtual auto border_style(xtd::forms::border_style value) -> up_down_base&;
      /// @brief Resets the border style for the control.
      /// @param xtd::null.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::null_ptr) -> up_down_base&;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of up_down_base class.
      up_down_base();
      /// @}
      
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
