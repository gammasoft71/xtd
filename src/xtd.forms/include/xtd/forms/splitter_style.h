/// @file
/// @brief Contains xtd::forms::splitter_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent splitter style used by splitter control.
    /// @par Header
    /// @code #include <xtd/forms/splitter_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class splitter_style {
      /// @brief Draw line splitter style.
      draw_line = 0,
      /// @brief Update children splitter style.
      update_children = 1
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::splitter_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::splitter_style> {{xtd::forms::splitter_style::draw_line, "draw_line"}, {xtd::forms::splitter_style::update_children, "update_children"}};}
};
/// @endcond
