#include "../../../include/xtd/forms/renderer.h"
#include "../../../include/xtd/forms/button_renderer.h"
#include "../../../include/xtd/forms/check_box_renderer.h"
#include "../../../include/xtd/forms/radio_button_renderer.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

void renderer::default_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::button_renderer::draw_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::default_check_box_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::check_box_renderer::draw_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::default_radio_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::radio_button_renderer::draw_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}
