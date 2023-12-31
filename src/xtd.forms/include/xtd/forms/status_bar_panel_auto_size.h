/// @file
/// @brief Contains xtd::forms::status_bar_panel_auto_size enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a xtd::forms::status_bar_panel on a xtd::forms::status_bar content behaves when the content resizes.
    /// @par Header
    /// @code #include <xtd/forms/status_bar_panel_auto_size> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::status_bar_panel::auto_size property. The xtd::forms::status_bar_panel::auto_size property specifies how a xtd::forms::status_bar_panel is autosized on a xtd::forms::status_bar content.
    enum class status_bar_panel_auto_size {
      /// @brief The xtd::forms::status_bar_panel does not change size when the xtd::forms::status_bar control resizes.
      none = 1,
      /// @brief The xtd::forms::status_bar_panel shares the available space on the xtd::forms::status_bar (the space not taken up by other panels whose xtd::forms::status_bar_panel::auto_size property is set to None or xtd::forms::status_bar_panel_auto_size::contents) with other panels that have their xtd::forms::status_bar_panel::auto_size property set to xtd::forms::status_bar_panel_auto_size::spring.
      spring = 2,
      /// @brief The width of the xtd::forms::status_bar_panel is determined by its contents.
      contents = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::status_bar_panel_auto_size> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::status_bar_panel_auto_size> {{xtd::forms::status_bar_panel_auto_size::none, "none"}, {xtd::forms::status_bar_panel_auto_size::spring, "spring"}, {xtd::forms::status_bar_panel_auto_size::contents, "contents"}};}
};
/// @endcond
