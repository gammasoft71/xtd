/// @file
/// @brief Contains xtd::forms::size_type enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how rows or columns of user interface (UI) elements should be sized relative to their container.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the size_mode property of the picture_box.
    enum class size_type {
      /// @brief The control should be automatically sized to share space with its peers.
      auto_size = 0,
      /// @brief The image within the picture_box is stretched or shrunk to fit the size of the picture_box.
      absolute = 1,
      /// @brief The picture_box is sized equal to the size of the image that it contains.
      percent = 2,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, size_type value) {return os << to_string(value, {{size_type::auto_size, "auto_size"}, {size_type::absolute, "absolute"}, {size_type::percent, "percent"}});}
    inline std::wostream& operator<<(std::wostream& os, size_type value) {return os << to_string(value, {{size_type::auto_size, L"auto_size"}, {size_type::absolute, L"absolute"}, {size_type::percent, L"percent"}});}
    /// @endcond
  }
}
