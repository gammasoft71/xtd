/// @file
/// @brief Contains xtd::forms::up_down_base control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.h"
#include "border_style.h"
#include "container_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality required by a spin box (also known as an up-down control).
    /// @par Header
    /// @code #include <xtd/forms/up_down_base> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ up_down_base : public container_control {
      struct data;
      
    public:
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual up_down_base& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the spin box (also known as an up-down control).
      /// @return One of the border_style values. The default value is fixed_single.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the spin box (also known as an up-down control).
      /// @param value One of the border_style values. The default value is fixed_single.
      /// @return Current up_down_base.
      virtual up_down_base& border_style(forms::border_style value);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual up_down_base& border_style(std::nullptr_t);
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initialize a new instance of up_down_base class.
      up_down_base();
      /// @}
      
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
