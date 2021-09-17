/// @file
/// @brief Contains xtd::forms::image_layout enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the position of the image on the control.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, image_layout value) {return os << to_string(value, {{image_layout::none, "none"}, {image_layout::tile, "tile"}, {image_layout::center, "center"}, {image_layout::stretch, "stretch"}, {image_layout::zoom, "zoom"}});}
    inline std::wostream& operator<<(std::wostream& os, image_layout value) {return os << to_string(value, {{image_layout::none, L"none"}, {image_layout::tile, L"tile"}, {image_layout::center, L"center"}, {image_layout::stretch, L"stretch"}, {image_layout::zoom, L"zoom"}});}
    /// @endcond
  }
}
