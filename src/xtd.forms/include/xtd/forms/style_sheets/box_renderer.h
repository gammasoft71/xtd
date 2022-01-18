/// @file
/// @brief Contains xtd::forms::style_sheets::box_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "box_data.h"
#include "border_renderer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Provides methods used to render a box with or without style sheets.
      class box_renderer static_ {
      public:
        static void draw_box(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::forms::style_sheets::box_data& data);
      };
    }
  }
}
