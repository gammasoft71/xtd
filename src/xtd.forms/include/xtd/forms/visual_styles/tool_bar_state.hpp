/// @file
/// @brief Contains xtd::forms::visual_styles::tool_bar_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control_state.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a tool_bar that is drawn with visual styles.
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The xtd::forms::visual_styles::tool_bar_state values correspond to the states of the visual style element objects exposed by the xtd::forms::tool_bar class. The xtd::forms::visual_styles::tool_bar_state values are also used as an argument in the xtd::forms::tool_bar_renderer::draw_tool_bar method.
      using tool_bar_state  = control_state;
    }
  }
}
