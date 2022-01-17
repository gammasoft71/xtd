/// @file
/// @brief Contains xtd::forms::style_sheets::button_data class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/forms/text_format_flags.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class text_renderer static_ {
      public:
        static void draw_text(xtd::drawing::graphics& g, const xtd::ustring& text, const xtd::drawing::rectangle_f& bounds, const std::optional<xtd::drawing::font>& font, const std::optional<xtd::drawing::color>& color) {
          //std::vector<size_t> hotkey_prefix_locations;
          //xtd::ustring text_without_hotkey_prefix = get_hotkey_prefix_locations(text, hotkey_prefix_locations);
          //if ((text_format & xtd::forms::text_format_flags::prefix_only) == xtd::forms::text_format_flags::prefix_only && hotkey_prefix_locations.size()) g.draw_string(text_without_hotkey_prefix.substring(hotkey_prefix_locations[0], 1), xtd::drawing::font(font, xtd::drawing::font_style::underline), xtd::drawing::solid_brush(text_color), button_rect, control_paint::string_format(text_format));
          //else g.draw_string(text, font, xtd::drawing::solid_brush(text_color), button_rect, xtd::forms::control_paint::string_format(text_format));
        }
        
      private:
        static xtd::ustring get_hotkey_prefix_locations(const xtd::ustring& str, std::vector<size_t>& locations) {
          auto offset = 0U;
          for (auto index = 0U; index < str.size(); index++) {
            if (str[index] == '&' && str[index + 1] != '&')
              locations.push_back(index + offset);
            else if (str[index] == '&' && str[index + 1] == '&') {
              offset -= 2;
              ++index;
            }
          }
          auto new_str = str.replace("&&", "&");
          for (auto index = 0U; index < locations.size(); ++index)
            new_str = new_str.remove(locations[index], 1);
          return new_str;
        }
      };
    }
  }
}
