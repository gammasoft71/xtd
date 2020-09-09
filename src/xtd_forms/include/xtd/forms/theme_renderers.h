#pragma once
#include <xtd/delegate.h>
#include <xtd/drawing/image.h>
#include "renderer.h"
#include "theme_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme_renderers final : public theme_base {
    public:
      using renderer_getter = xtd::delegate<xtd::forms::renderer()>;

      theme_renderers() = default;
      explicit theme_renderers(const std::string& name) : theme_base(name) {}
      theme_renderers(const std::string& name, xtd::forms::theme_style theme_style, const renderer_getter& renderer_getter) : theme_base(name, theme_style), renderer_getter_(renderer_getter) {}
      /// @cond
      theme_renderers(const theme_renderers&) = default;
      theme_renderers& operator=(const theme_renderers&) = default;
      bool operator==(const theme_renderers& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme_renderers& value) const {return !operator==(value);}
      /// @endcond

      static const theme_renderers empty;

      static xtd::drawing::size default_size() {return {32, 32};}

      xtd::forms::renderer renderer() const {return renderer_getter_();}
      xtd::forms::renderer::button_renderer button_renderer() const {return renderer_getter_().button_render();}
      xtd::forms::renderer::check_box_renderer check_box_renderer() const {return renderer_getter_().check_box_render();}
      xtd::forms::renderer::radio_button_renderer radio_button_renderer() const {return renderer_getter_().radio_button_render();}

      void draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {button_renderer()(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      void draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {check_box_renderer()(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}
      void draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {radio_button_renderer()(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);}

      static theme_renderers current_theme() {
        if (current_theme_ == theme_renderers::empty) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme_renderers& theme) {
        current_theme_ = theme;
      }
      static void current_theme(const std::string& name) {current_theme(theme_from_name(name));}

      static theme_renderers default_theme() {return theme_from_name(default_theme_name());}

      static theme_renderers theme_from_name(const std::string& theme_name);
      
    private:
      theme_renderers(const std::string& name, xtd::forms::theme_style theme_style, const renderer_getter& renderer_getter, bool is_default) : theme_base(name, theme_style, is_default), renderer_getter_(renderer_getter) {}
      renderer_getter renderer_getter_;
      static theme_renderers current_theme_;
    };
  }
}
