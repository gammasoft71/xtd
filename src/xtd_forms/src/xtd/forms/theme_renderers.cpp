#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/check_box_renderer.h"
#include "../../../include/xtd/forms/radio_button_renderer.h"
#include "../../../include/xtd/forms/theme_renderers.h"
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_colors.h>

using namespace xtd::forms;

namespace {
  renderer system_renderer_getter() {
    renderer renderer(theme_renderers::default_theme_name());
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer gnome_dark_renderer_getter() {
    renderer renderer("gnome (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("gnome (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("gnome (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("gnome (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer gnome_light_renderer_getter() {
    renderer renderer("gnome (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("gnome (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("gnome (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("gnome (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer gnome_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? gnome_dark_renderer_getter() : gnome_light_renderer_getter();
  }

  renderer kde_dark_renderer_getter() {
    renderer renderer("kde (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("kde (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("kde (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("kde (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer kde_light_renderer_getter() {
    renderer renderer("kde (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("kde (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("kde (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("kde (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer kde_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? kde_dark_renderer_getter() : kde_light_renderer_getter();
  }

  renderer macos_dark_renderer_getter() {
    renderer renderer("macos (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("macos (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("macos (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("macos (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer macos_light_renderer_getter() {
    renderer renderer("macos (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("macos (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("macos (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("macos (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer macos_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? macos_dark_renderer_getter() : macos_light_renderer_getter();
  }

  renderer symbolic_dark_renderer_getter() {
    renderer renderer("symbolic (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("symbolic (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("symbolic (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("symbolic (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer symbolic_light_renderer_getter() {
    renderer renderer("symbolic (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("symbolic (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("symbolic (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("symbolic (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer symbolic_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? symbolic_dark_renderer_getter() : symbolic_light_renderer_getter();
  }

  renderer windows_dark_renderer_getter() {
    renderer renderer("windows (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("windows (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("windows (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("windows (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer windows_light_renderer_getter() {
    renderer renderer("windows (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("windows (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("windows (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("windows (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer windows_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? windows_dark_renderer_getter() : windows_light_renderer_getter();
  }

  renderer xtd_dark_renderer_getter() {
    renderer renderer("xtd (dark)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("xtd (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("xtd (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("xtd (dark)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer xtd_light_renderer_getter() {
    renderer renderer("xtd (light)");
    renderer.button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      button_renderer::draw_button("xtd (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.check_box_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      check_box_renderer::draw_check_box("xtd (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    renderer.radio_button_render({[](xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const std::string& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
      radio_button_renderer::draw_radio_button("xtd (light)", g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
    }});
    return renderer;
  }

  renderer xtd_renderer_getter() {
    return xtd::drawing::system_colors::window().get_lightness() < 0.5 ? xtd_dark_renderer_getter() : xtd_light_renderer_getter();
  }
}

const theme_renderers theme_renderers::empty {};
theme_renderers theme_renderers::current_theme_;

theme_renderers theme_renderers::theme_from_name(const std::string& name) {
  if (name == default_theme_name()) return theme_renderers(default_theme_name(), theme_style::system_auto, {system_renderer_getter}, true);
  if (name == "gnome") return theme_renderers("gnome", theme_style::system_auto, {gnome_renderer_getter});
  if (name == "gnome (dark)") return theme_renderers("gnome (dark)", theme_style::dark, {gnome_dark_renderer_getter});
  if (name == "gnome (light)") return theme_renderers("gnome (light)", theme_style::light, {gnome_light_renderer_getter});
  if (name == "kde") return theme_renderers("kde", theme_style::system_auto, {kde_renderer_getter});
  if (name == "kde (dark)") return theme_renderers("kde (dark)", theme_style::dark, {kde_dark_renderer_getter});
  if (name == "kde (light)") return theme_renderers("kde (light)", theme_style::light, {kde_light_renderer_getter});
  if (name == "macos") return theme_renderers("macos", theme_style::system_auto, {macos_renderer_getter});
  if (name == "macos (dark)") return theme_renderers("macos (dark)", theme_style::dark, {macos_dark_renderer_getter});
  if (name == "macos (light)") return theme_renderers("macos (light)", theme_style::light, {macos_light_renderer_getter});
  if (name == "symbolic") return theme_renderers("symbolic", theme_style::system_auto, {symbolic_renderer_getter});
  if (name == "symbolic (dark)") return theme_renderers("symbolic (dark)", theme_style::dark, {symbolic_dark_renderer_getter});
  if (name == "symbolic (light)") return theme_renderers("symbolic (light)", theme_style::light, {symbolic_light_renderer_getter});
  if (name == "windows") return theme_renderers("windows", theme_style::system_auto, {windows_renderer_getter});
  if (name == "windows (dark)") return theme_renderers("windows (dark)", theme_style::dark, {windows_dark_renderer_getter});
  if (name == "windows (light)") return theme_renderers("windows (light)", theme_style::light, {windows_light_renderer_getter});
  if (name == "xtd") return theme_renderers("xtd", theme_style::system_auto, {xtd_renderer_getter});
  if (name == "xtd (dark)") return theme_renderers("xtd (dark)", theme_style::dark, {xtd_dark_renderer_getter});
  if (name == "xtd (light)") return theme_renderers("xtd (light)", theme_style::light, {xtd_light_renderer_getter});
  return current_theme_;
}
