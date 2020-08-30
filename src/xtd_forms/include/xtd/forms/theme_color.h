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
      using kown_themed_color_to_color = delegate<xtd::drawing::color(xtd::forms::known_themed_color)>;
      using theme_color_collection = std::vector<theme_color>;
      using theme_color_name_collection = std::vector<std::string>;

      theme_color() = default;
      theme_color(const std::string& name, const kown_themed_color_to_color& kown_themed_color_to_color) : theme(name), kown_themed_color_to_color_(kown_themed_color_to_color) {}
      theme_color(const std::string& name, xtd::forms::theme_style theme_style, const kown_themed_color_to_color& kown_themed_color_to_color) : theme(name, theme_style), kown_themed_color_to_color_(kown_themed_color_to_color) {}
      /// @cond
      theme_color(const theme_color&) = default;
      theme_color& operator=(const theme_color&) = default;
      bool operator==(const theme_color& value) const {return theme::operator==(value);}
      bool operator!=(const theme_color& value) const {return !operator==(value);}
      bool operator<(const theme_color& value) const {return theme::operator<(value);}
      virtual ~theme_color() = default;
      /// @endcond

      static const theme_color empty;
      
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
      
      static theme_color current_theme_color();
      static void current_theme_color(const theme_color& theme_color);
      static void current_theme_color(const std::string& theme_color_name);
      static theme_color default_theme_color();
      xtd::drawing::color from_known_themed_color(xtd::forms::known_themed_color known_themed_color) const;
      static const theme_color_collection& theme_colors();
      static theme_color_name_collection theme_color_names();

    protected:
      theme_color(const std::string& name, xtd::forms::theme_style theme_style, const kown_themed_color_to_color& kown_themed_color_to_color, bool is_default) : theme(name, theme_style, is_default), kown_themed_color_to_color_(kown_themed_color_to_color) {}

    private:
      static theme_color current_theme_color_;
      delegate<xtd::drawing::color(xtd::forms::known_themed_color)> kown_themed_color_to_color_;
    };
  }
}
