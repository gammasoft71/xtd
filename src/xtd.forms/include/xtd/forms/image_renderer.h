/// @file
/// @brief Contains xtd::forms::style_sheets::image_renderer static class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/rectangle.h>
#include "style_sheets/iimage_model.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class image_renderer static_ {
    public:
      static void draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, bool enabled, const xtd::drawing::color& back_color, const xtd::forms::style_sheets::iimage_model& data);
      
    private:
      static xtd::drawing::rectangle compute_image_bounds(const xtd::drawing::rectangle& rectangle, const xtd::drawing::size& image_size, content_alignment align) noexcept;
    };
  }
}
