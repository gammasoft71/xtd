/// @file
/// @brief Contains xtd::forms::style_sheets::color_type enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The color_type enum class specifies what kind of color to display.
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class color_type {
        /// @brief Defines solid color.
        solid,
        /// @brief Defines a linear_gradient color.
        linear_gradient,
        /// @brief Defines a radial_gradient color.
        radial_gradient,
        /// @brief Defines a conic_gradient color.
        conic_gradient,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, const color_type value) {return os << to_string(value, {{color_type::solid, "solid,"}, {color_type::linear_gradient, "linear_gradient,"}, {color_type::radial_gradient, "radial_gradient,"}, {color_type::conic_gradient, "conic_gradient,"}});}
      inline std::wostream& operator<<(std::wostream& os, const color_type value) {return os << to_string(value, {{color_type::solid, L"solid,"}, {color_type::linear_gradient, L"linear_gradient,"}, {color_type::radial_gradient, L"radial_gradient,"}, {color_type::conic_gradient, L"conic_gradient,"}});}
      /// @endcond
    }
  }
}
