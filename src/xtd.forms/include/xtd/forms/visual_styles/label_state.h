/// @file
/// @brief Contains xtd::forms::visual_styles::label_state enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "control_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::visual_styles namespace contains classes for rendering controls and other windows user interface (UI) elements with visual styles in operating systems that support them.
    namespace visual_styles {
      /// @brief Specifies the visual state of a label that is drawn with visual styles.
      /// @par Namespace
      /// xtd::forms::visual_style
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The label_state values correspond to the states of the visual_style_element objects exposed by the visual_style_element:label::label class. The label_state values are also used as an argument in the label_renderer.draw_label method.
      using label_state  = control_state;
    }
  }
}
