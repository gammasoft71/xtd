/// @file
/// @brief Contains xtd::forms::horizontal_control_layout_style_collection typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "horizontal_control_layout_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief A collection that stores horizontal_control_layout_style objects.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using horizontal_control_layout_style_collection = std::map<const_control_ref, horizontal_control_layout_style>;  }
}
