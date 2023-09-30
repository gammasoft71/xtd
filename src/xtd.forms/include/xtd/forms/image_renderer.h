/// @file
/// @brief Contains xtd::forms::image_renderer static class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "style_sheets/iimage_model.h"
#include "style_sheets/iimage_model.h"
#include <xtd/drawing/graphics>
#include <xtd/drawing/image>
#include <xtd/drawing/rectangle>
#include <xtd/static>
#include <xtd/ustring>
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides image renderer methods.
    /// @code
    /// class forms_export_ image_renderer static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static → xtd::forms::image_renderer
    /// @par Header
    /// @code #include <xtd/forms/image_renderer> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms renderers
    class forms_export_ image_renderer static_ {
    public:
      /// @name Moethods
      
      /// @{
      /// @brief Draws an image in the specified bounds.
      /// @param graphics The Graphics used to draw an image.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the image.
      /// @param image The xtd::drawing::image that specifies the image to draw.
      /// @param enable If is true the image is drawing normaly; otherwise the image is drawing in disable style.
      /// @param back_color The back color is usedd to draw image disabled.
      /// @param data Contains the informations needed to draw image.
      /// @remarks if image is .xtd::drawing::image::empty, nothing is drawing.
      static void draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, bool enabled, const xtd::drawing::color& back_color, const xtd::forms::style_sheets::iimage_model& data);
      /// @brief Draws an image in the specified bounds.
      /// @param graphics The Graphics used to draw an image.
      /// @param bounds The xtd::drawing::rectangle that specifies the bounds of the image.
      /// @param image The xtd::drawing::image that specifies the image to draw.
      /// @param enable If is true the image is drawing normaly; otherwise the image is drawing in disable style.
      /// @param brightness The brightness is usedd to draw image disabled.
      /// @param data Contains the informations needed to draw image.
      /// @remarks if image is .xtd::drawing::image::empty, nothing is drawing.
      static void draw_image(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& bounds, const xtd::drawing::image& image, bool enabled, float brightness, const xtd::forms::style_sheets::iimage_model& data);
      /// @}
      
    private:
      static xtd::drawing::rectangle compute_image_bounds(const xtd::drawing::rectangle& rectangle, const xtd::drawing::size& image_size, content_alignment align) noexcept;
    };
  }
}
