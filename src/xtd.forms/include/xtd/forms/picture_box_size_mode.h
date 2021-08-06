/// @file
/// @brief Contains xtd::forms::picture_box_size_mode enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how an image is positioned within a picture_box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the size_mode property of the picture_box.
    enum class picture_box_size_mode {
      /// @brief The image is placed in the upper-left corner of the picture_box. The image is clipped if it is larger than the picture_box it is contained in.
      normal = 0,
      /// @brief The image within the picture_box is stretched or shrunk to fit the size of the picture_box.
      stretch_image = 1,
      /// @brief The picture_box is sized equal to the size of the image that it contains.
      auto_size = 2,
      /// @brief The image is displayed in the center if the picture_box is larger than the image. If the image is larger than the picture_box, the picture is placed in the center of the picture_box and the outside edges are clipped.
      center_image = 3,
      /// @brief The size of the image is increased or decreased maintaining the size ratio.
      zoom = 4,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, picture_box_size_mode value) {return os << to_string(value, {{picture_box_size_mode::normal, "normal"}, {picture_box_size_mode::stretch_image, "stretch_image"}, {picture_box_size_mode::auto_size, "auto_size"}, {picture_box_size_mode::center_image, "center_image"}, {picture_box_size_mode::zoom, "zoom"}});}
    inline std::wostream& operator<<(std::wostream& os, picture_box_size_mode value) {return os << to_string(value, {{picture_box_size_mode::normal, L"normal"}, {picture_box_size_mode::stretch_image, L"stretch_image"}, {picture_box_size_mode::auto_size, L"auto_size"}, {picture_box_size_mode::center_image, L"center_image"}, {picture_box_size_mode::zoom, L"zoom"}});}
    /// @endcond
  }
}
