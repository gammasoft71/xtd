/// @file
/// @brief Contains xtd::forms::image_layout enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the position of the image on the control.
    /// @par Header
    /// @code #include <xtd/forms/image_layout> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class image_layout {
      /// @brief The image is left-aligned at the top across the control's client rectangle.
      none = 0,
      /// @brief The image is tiled across the control's client rectangle.
      tile = 1,
      /// @brief The image is centered within the control's client rectangle.
      center = 2,
      /// @brief The image is stretched across the control's client rectangle.
      stretch = 3,
      /// @brief The image is enlarged within the control's client rectangle.
      zoom = 4,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::image_layout> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::image_layout> {{xtd::forms::image_layout::none, "none"}, {xtd::forms::image_layout::tile, "tile"}, {xtd::forms::image_layout::center, "center"}, {xtd::forms::image_layout::stretch, "stretch"}, {xtd::forms::image_layout::zoom, "zoom"}};}
};
/// @endcond
