/// @file
/// @brief Contains xtd::forms::tool_bar_button_ref alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ref>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tool_bar_button;
    /// @endcond
    
    /// @brief Represents a xtd::forms::tool_bar_item reference.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/tool_bar_button_ref>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using tool_bar_button_ref = std::reference_wrapper<tool_bar_button>;
  }
}
