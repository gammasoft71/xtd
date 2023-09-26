#include "../../../include/xtd/forms/button_renderer"
#include "../../../include/xtd/forms/check_box_renderer"
#include "../../../include/xtd/forms/radio_button_renderer"
#include "../../../include/xtd/forms/renderer"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

struct renderer::data {
  xtd::ustring name;
  xtd::forms::renderer::button_renderer button_renderer = xtd::forms::renderer::button_renderer(default_button_renderer);
  xtd::forms::renderer::check_box_renderer check_box_renderer = xtd::forms::renderer::check_box_renderer(default_check_box_renderer);
  xtd::forms::renderer::radio_button_renderer radio_button_renderer = xtd::forms::renderer::radio_button_renderer(default_radio_button_renderer);
};

renderer::renderer() : data_(std::make_shared<data>()) {
}

renderer::renderer(const xtd::ustring& name) : data_(std::make_shared<data>()) {
  data_->name = name;
}

renderer::renderer(const renderer& value) : data_(std::make_shared<data>()) {
  *data_ = *value.data_;
}

renderer& renderer::operator =(const renderer& value) {
  *data_ = *value.data_;
  return *this;
}

const xtd::ustring& renderer::name() const {
  return data_->name;
}

renderer& renderer::name(const xtd::ustring& name) {
  data_->name = name;
  return *this;
}

renderer::button_renderer renderer::button_render() const noexcept {
  return data_->button_renderer;
}

void renderer::button_render(button_renderer button_renderer) {
  data_->button_renderer = button_renderer;
}

renderer::check_box_renderer renderer::check_box_render() const noexcept {
  return data_->check_box_renderer;
}

void renderer::check_box_render(check_box_renderer check_box_renderer) {
  data_->check_box_renderer = check_box_renderer;
}

renderer::radio_button_renderer renderer::radio_button_render() const noexcept {
  return data_->radio_button_renderer;
}

void renderer::radio_button_render(radio_button_renderer radio_button_renderer) {
  data_->radio_button_renderer = radio_button_renderer;
}

void renderer::draw_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  data_->button_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::draw_check_box(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  data_->check_box_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::draw_radio_button(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  data_->radio_button_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

bool renderer::equals(const renderer& value) const noexcept {
  return data_->name == value.data_->name;
}

xtd::ustring renderer::to_string() const noexcept {
  if (!data_->name.empty()) return xtd::ustring::format("{}, name: {}", get_type().full_name(), data_->name);
  return xtd::ustring::format(get_type().full_name());
}

void renderer::default_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::push_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::button_renderer::draw_button(g, bounds, state, false, back_color, text, optional<content_alignment>(), fore_color, font, image, optional<xtd::forms::content_alignment>());
  //xtd::forms::button_renderer::draw_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::default_check_box_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::check_box_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::check_box_renderer::draw_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

void renderer::default_radio_button_renderer(xtd::drawing::graphics g, const xtd::drawing::rectangle& bounds, const xtd::ustring& text, const xtd::drawing::font& font, xtd::forms::text_format_flags flags, const xtd::drawing::image& image, const xtd::drawing::rectangle& image_bounds, bool focused, xtd::forms::visual_styles::radio_button_state state, const std::optional<xtd::drawing::color>& back_color, const std::optional<xtd::drawing::color>& fore_color) {
  xtd::forms::radio_button_renderer::draw_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}
