/// @file
/// @brief Contains xtd::forms::theme_colors class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "theme_base.h"
#include "known_themed_color.h"
#include <string>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/drawing/color.h>
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ theme_colors final : public theme_base {
    public:
      using color_getter = xtd::delegate<xtd::drawing::color(xtd::forms::known_themed_color)>;

      theme_colors() = default;
      theme_colors(const xtd::ustring& name, const color_getter& kown_themed_color_to_color) : theme_base(name), color_getter_(kown_themed_color_to_color) {}
      theme_colors(const xtd::ustring& name, xtd::forms::theme_style theme_style, const color_getter& color_getter) : theme_base(name, theme_style), color_getter_(color_getter) {}
      /// @cond
      theme_colors(const theme_colors&) = default;
      theme_colors& operator=(const theme_colors&) = default;
      bool operator==(const theme_colors& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme_colors& value) const {return !operator==(value);}
      /// @endcond

      static const theme_colors empty;
      
      xtd::drawing::color accent() const {return from_known_themed_color(xtd::forms::known_themed_color::accent);}
      xtd::drawing::color accent_text() const {return from_known_themed_color(xtd::forms::known_themed_color::accent_text);}
      xtd::drawing::color active_border() const {return from_known_themed_color(xtd::forms::known_themed_color::active_border);}
      xtd::drawing::color active_caption() const {return from_known_themed_color(xtd::forms::known_themed_color::active_caption);}
      xtd::drawing::color active_caption_text() const {return from_known_themed_color(xtd::forms::known_themed_color::active_caption_text);}
      xtd::drawing::color app_workspace() const {return from_known_themed_color(xtd::forms::known_themed_color::app_workspace);}
      xtd::drawing::color button_face() const {return from_known_themed_color(xtd::forms::known_themed_color::button_face);}
      xtd::drawing::color button_highlight() const {return from_known_themed_color(xtd::forms::known_themed_color::button_highlight);}
      xtd::drawing::color button_shadow() const {return from_known_themed_color(xtd::forms::known_themed_color::button_shadow);}
      xtd::drawing::color control() const {return from_known_themed_color(xtd::forms::known_themed_color::control);}
      xtd::drawing::color control_dark() const {return from_known_themed_color(xtd::forms::known_themed_color::control_dark);}
      xtd::drawing::color control_dark_dark() const {return from_known_themed_color(xtd::forms::known_themed_color::control_dark_dark);}
      xtd::drawing::color control_light() const {return from_known_themed_color(xtd::forms::known_themed_color::control_light);}
      xtd::drawing::color control_light_light() const {return from_known_themed_color(xtd::forms::known_themed_color::control_light_light);}
      xtd::drawing::color control_text() const {return from_known_themed_color(xtd::forms::known_themed_color::control_text);}
      xtd::drawing::color desktop() const {return from_known_themed_color(xtd::forms::known_themed_color::desktop);}
      xtd::drawing::color gradient_active_caption() const {return from_known_themed_color(xtd::forms::known_themed_color::gradient_active_caption);}
      xtd::drawing::color gradient_inactive_caption() const {return from_known_themed_color(xtd::forms::known_themed_color::gradient_inactive_caption);}
      xtd::drawing::color gray_text() const {return from_known_themed_color(xtd::forms::known_themed_color::gray_text);}
      xtd::drawing::color highlight() const {return from_known_themed_color(xtd::forms::known_themed_color::highlight);}
      xtd::drawing::color highlight_text() const {return from_known_themed_color(xtd::forms::known_themed_color::highlight_text);}
      xtd::drawing::color hot_track() const {return from_known_themed_color(xtd::forms::known_themed_color::hot_track);}
      xtd::drawing::color inactive_border() const {return from_known_themed_color(xtd::forms::known_themed_color::inactive_border);}
      xtd::drawing::color inactive_caption() const {return from_known_themed_color(xtd::forms::known_themed_color::inactive_caption);}
      xtd::drawing::color inactive_caption_text() const {return from_known_themed_color(xtd::forms::known_themed_color::inactive_caption_text);}
      xtd::drawing::color info() const {return from_known_themed_color(xtd::forms::known_themed_color::info);}
      xtd::drawing::color info_text() const {return from_known_themed_color(xtd::forms::known_themed_color::info_text);}
      xtd::drawing::color menu() const {return from_known_themed_color(xtd::forms::known_themed_color::menu);}
      xtd::drawing::color menu_bar() const {return from_known_themed_color(xtd::forms::known_themed_color::menu_bar);}
      xtd::drawing::color menu_highlight() const {return from_known_themed_color(xtd::forms::known_themed_color::menu_highlight);}
      xtd::drawing::color menu_text() const {return from_known_themed_color(xtd::forms::known_themed_color::menu_text);}
      xtd::drawing::color scroll_bar() const {return from_known_themed_color(xtd::forms::known_themed_color::scroll_bar);}
      xtd::drawing::color text_box() const {return from_known_themed_color(xtd::forms::known_themed_color::text_box);}
      xtd::drawing::color text_box_text() const {return from_known_themed_color(xtd::forms::known_themed_color::text_box_text);}
      xtd::drawing::color window() const {return from_known_themed_color(xtd::forms::known_themed_color::window);}
      xtd::drawing::color window_frame() const {return from_known_themed_color(xtd::forms::known_themed_color::window_frame);}
      xtd::drawing::color window_text() const {return from_known_themed_color(xtd::forms::known_themed_color::window_text);}

      xtd::drawing::color from_known_themed_color(xtd::forms::known_themed_color known_themed_color) const {return color_getter_(known_themed_color);}

      static theme_colors current_theme() {
        if (current_theme_ == theme_colors::empty) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme_colors& theme_color) {current_theme_ = theme_color;}
      static void current_theme(const xtd::ustring& name) {current_theme(theme_from_name(name));}

      static theme_colors default_theme() {return theme_from_name(default_theme_name());}
      
      static theme_colors theme_from_name(const xtd::ustring& theme_color_name);

    private:
      theme_colors(const xtd::ustring& name, xtd::forms::theme_style theme_style, const color_getter& color_getter, bool is_default) : theme_base(name, theme_style, is_default), color_getter_(color_getter) {}
      color_getter color_getter_;
      static theme_colors current_theme_;
    };
  }
}
