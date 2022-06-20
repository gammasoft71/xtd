/// @file
/// @brief Contains xtd::forms::tool_bar_text_align enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the type of toolbar to display.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by members such as xtd::forms::tool_bar.text_align.
    /// @remarks Room is reserved for an image to be displayed on toolbar buttons. The alignment of text is in relation to the image displayed on the toolbar button. If no image is assigned to the button, the reserved space will appear to the left, or above the text displayed.
    enum class tool_bar_text_align {
      /// @brief The text is aligned underneath the toolbar button image.
      underneath = 0,
      /// @brief The text is aligned to the right of the toolbar button image.
      right = 1,
    };
    
    /// @cond
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, tool_bar_text_align value) {return os << to_string(value, {{tool_bar_text_align::underneath, "underneath"}, {tool_bar_text_align::right, "right"}});}
    inline std::wostream& operator<<(std::wostream& os, tool_bar_text_align value) {return os << to_string(value, {{tool_bar_text_align::underneath, L"underneath"}, {tool_bar_text_align::right, L"right"}});}
    /// @endcond
  }
}
