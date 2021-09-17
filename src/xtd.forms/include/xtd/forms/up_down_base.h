/// @file
/// @brief Contains xtd::forms::up_down_base control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "border_style.h"
#include "container_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality required by a spin box (also known as an up-down control).
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ up_down_base : public container_control {
    public:      
      /// @brief Gets the border style for the spin box (also known as an up-down control).
      /// @return One of the border_style values. The default value is fixed_single.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the border style for the spin box (also known as an up-down control).
      /// @param value One of the border_style values. The default value is fixed_single.
      /// @return Current up_down_base.
      virtual up_down_base& border_style(forms::border_style value);

    protected:
      /// @brief Initialize a new instance of up_down_base class.
      up_down_base();

      forms::create_params create_params() const override;

      /// @cond
      forms::border_style border_style_ = forms::border_style::fixed_single;
      /// @endcond
    };
  }
}
