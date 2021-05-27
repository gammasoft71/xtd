/// @file
/// @brief Contains xtd::forms::vertical_control_layout_style_collection typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "vertical_control_layout_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief A collection that stores vertical_control_layout_style objects.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using vertical_control_layout_style_collection = std::map<const_control_ref, vertical_control_layout_style>;  }
}
