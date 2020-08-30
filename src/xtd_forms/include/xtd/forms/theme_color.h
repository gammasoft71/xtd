#pragma once
#include "theme.h"
#include "known_themed_color.h"
#include <string>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/drawing/color.h>
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme_color : public theme {
    public:
      using theme_color_collection = std::vector<theme_color>;
      using theme_color_name_collection = std::vector<std::string>;

      theme_color() = default;
      theme_color(const std::string& name, xtd::forms::theme_style theme_style, delegate<xtd::drawing::color(xtd::forms::known_themed_color)> kown_themed_color_to_color) : theme(name, theme_style), kown_themed_color_to_color_(kown_themed_color_to_color) {}
      /// @cond
      theme_color(const theme_color&) = default;
      theme_color& operator=(const theme_color&) = default;
      bool operator==(const theme_color& value) const {return theme::operator==(value);}
      bool operator!=(const theme_color& value) const {return !operator==(value);}
      bool operator<(const theme_color& value) const {return theme::operator<(value);}
      virtual ~theme_color() = default;
      /// @endcond

      static const theme_color empty;
      
      static xtd::drawing::color accent() {return from_known_themed_color(xtd::forms::known_themed_color::accent);}
      static xtd::drawing::color accent_text() {return from_known_themed_color(xtd::forms::known_themed_color::accent_text);}
      static xtd::drawing::color active_border() {return from_known_themed_color(xtd::forms::known_themed_color::active_border);}
      static xtd::drawing::color active_caption() {return from_known_themed_color(xtd::forms::known_themed_color::active_caption);}
      static xtd::drawing::color active_caption_text() {return from_known_themed_color(xtd::forms::known_themed_color::active_caption_text);}
      static xtd::drawing::color app_workspace() {return from_known_themed_color(xtd::forms::known_themed_color::app_workspace);}
      static xtd::drawing::color button_face() {return from_known_themed_color(xtd::forms::known_themed_color::button_face);}
      static xtd::drawing::color button_highlight() {return from_known_themed_color(xtd::forms::known_themed_color::button_highlight);}
      static xtd::drawing::color button_shadow() {return from_known_themed_color(xtd::forms::known_themed_color::button_shadow);}
      static xtd::drawing::color control() {return from_known_themed_color(xtd::forms::known_themed_color::control);}
      static xtd::drawing::color control_dark() {return from_known_themed_color(xtd::forms::known_themed_color::control_dark);}
      static xtd::drawing::color control_dark_dark() {return from_known_themed_color(xtd::forms::known_themed_color::control_dark_dark);}
      static xtd::drawing::color control_light() {return from_known_themed_color(xtd::forms::known_themed_color::control_light);}
      static xtd::drawing::color control_light_light() {return from_known_themed_color(xtd::forms::known_themed_color::control_light_light);}
      static xtd::drawing::color control_text() {return from_known_themed_color(xtd::forms::known_themed_color::control_text);}
      static xtd::drawing::color desktop() {return from_known_themed_color(xtd::forms::known_themed_color::desktop);}
      static xtd::drawing::color gradient_active_caption() {return from_known_themed_color(xtd::forms::known_themed_color::gradient_active_caption);}
      static xtd::drawing::color gradient_inactive_caption() {return from_known_themed_color(xtd::forms::known_themed_color::gradient_inactive_caption);}
      static xtd::drawing::color gray_text() {return from_known_themed_color(xtd::forms::known_themed_color::gray_text);}
      static xtd::drawing::color highlight() {return from_known_themed_color(xtd::forms::known_themed_color::highlight);}
      static xtd::drawing::color highlight_text() {return from_known_themed_color(xtd::forms::known_themed_color::highlight_text);}
      static xtd::drawing::color hot_track() {return from_known_themed_color(xtd::forms::known_themed_color::hot_track);}
      static xtd::drawing::color inactive_border() {return from_known_themed_color(xtd::forms::known_themed_color::inactive_border);}
      static xtd::drawing::color inactive_caption() {return from_known_themed_color(xtd::forms::known_themed_color::inactive_caption);}
      static xtd::drawing::color inactive_caption_text() {return from_known_themed_color(xtd::forms::known_themed_color::inactive_caption_text);}
      static xtd::drawing::color info() {return from_known_themed_color(xtd::forms::known_themed_color::info);}
      static xtd::drawing::color info_text() {return from_known_themed_color(xtd::forms::known_themed_color::info_text);}
      static xtd::drawing::color menu() {return from_known_themed_color(xtd::forms::known_themed_color::menu);}
      static xtd::drawing::color menu_bar() {return from_known_themed_color(xtd::forms::known_themed_color::menu_bar);}
      static xtd::drawing::color menu_highlight() {return from_known_themed_color(xtd::forms::known_themed_color::menu_highlight);}
      static xtd::drawing::color menu_text() {return from_known_themed_color(xtd::forms::known_themed_color::menu_text);}
      static xtd::drawing::color scroll_bar() {return from_known_themed_color(xtd::forms::known_themed_color::scroll_bar);}
      static xtd::drawing::color text_box() {return from_known_themed_color(xtd::forms::known_themed_color::text_box);}
      static xtd::drawing::color text_box_text() {return from_known_themed_color(xtd::forms::known_themed_color::text_box_text);}
      static xtd::drawing::color window() {return from_known_themed_color(xtd::forms::known_themed_color::window);}
      static xtd::drawing::color window_frame() {return from_known_themed_color(xtd::forms::known_themed_color::window_frame);}
      static xtd::drawing::color window_text() {return from_known_themed_color(xtd::forms::known_themed_color::window_text);}
      
      static theme_color current_theme_color();
      static void current_theme_color(const theme_color& theme_color);
      static void current_theme_color(const std::string& theme_color_name);
      static theme_color default_theme_color();
      static xtd::drawing::color from_known_themed_color(xtd::forms::known_themed_color known_themed_color);
      static const theme_color_collection& theme_colors();
      static theme_color_name_collection theme_color_names();

    protected:
      theme_color(const std::string& name, xtd::forms::theme_style theme_style, delegate<xtd::drawing::color(xtd::forms::known_themed_color)> kown_themed_color_to_color, bool is_default) : theme(name, theme_style, is_default), kown_themed_color_to_color_(kown_themed_color_to_color) {}

    private:
      static theme_color current_theme_color_;
      delegate<xtd::drawing::color(xtd::forms::known_themed_color)> kown_themed_color_to_color_;
    };
  }
}
