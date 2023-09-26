/// @file
/// @brief Contains xtd::forms::style_sheets::image_type enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The image_type enum class specifies what kind of image to display.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/image_type> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class image_type {
        /// @brief Defines no image.
        none,
        /// @brief Defines url image.
        url,
        /// @brief Defines a linear_gradient image.
        linear_gradient,
        /// @brief Defines a radial_gradient image.
        radial_gradient,
        /// @brief Defines a conic_gradient image.
        conic_gradient,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::style_sheets::image_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::image_type> {{xtd::forms::style_sheets::image_type::none, "none"}, {xtd::forms::style_sheets::image_type::url, "url"}, {xtd::forms::style_sheets::image_type::linear_gradient, "linear_gradient"}, {xtd::forms::style_sheets::image_type::radial_gradient, "radial_gradient"}, {xtd::forms::style_sheets::image_type::conic_gradient, "conic_gradient"}};}
};
/// @endcond
