/// @file
/// @brief Contains xtd::forms::style_sheets::text_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/forms/content_alignment.h>
#include "color_data.h"
#include "text_decoration.h"
#include "text_transformation.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class text_data : public xtd::object {
      public:
        text_data() = default;
        text_data(const xtd::forms::style_sheets::color_data& color);
        text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment);
        text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font);
        text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font, xtd::forms::style_sheets::text_decoration decoration, xtd::forms::style_sheets::text_transformation transformation);

        /// @cond
        text_data(const text_data&) = default;
        text_data(text_data&&) = default;
        text_data& operator=(const text_data&) = default;
        /// @endcond
        
        xtd::forms::content_alignment alignment() const noexcept;
        const xtd::forms::style_sheets::color_data& color() const noexcept;
        xtd::forms::style_sheets::text_decoration decoration() const noexcept;
        xtd::forms::style_sheets::text_transformation transformation() const noexcept;
        const xtd::drawing::font& font() const noexcept;

        static xtd::drawing::string_format make_string_format(const xtd::forms::style_sheets::text_data& data);

      private:
        xtd::forms::style_sheets::color_data color_;
        xtd::forms::content_alignment alignment_ = xtd::forms::content_alignment::middle_center;
        xtd::drawing::font font_ = xtd::drawing::system_fonts::default_font();
        xtd::forms::style_sheets::text_decoration decoration_ = xtd::forms::style_sheets::text_decoration::none;
        xtd::forms::style_sheets::text_transformation transformation_ = xtd::forms::style_sheets::text_transformation::none;
      };
    }
  }
}
