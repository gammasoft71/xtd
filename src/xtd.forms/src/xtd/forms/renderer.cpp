#include "../../../include/xtd/forms/button_renderer.hpp"
#include "../../../include/xtd/forms/check_box_renderer.hpp"
#include "../../../include/xtd/forms/radio_button_renderer.hpp"
#include "../../../include/xtd/forms/renderer.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::visual_styles;

struct renderer::data {
  string name;
  renderer::button_renderer button_renderer = renderer::button_renderer(default_button_renderer);
  renderer::check_box_renderer check_box_renderer = renderer::check_box_renderer(default_check_box_renderer);
  renderer::radio_button_renderer radio_button_renderer = renderer::radio_button_renderer(default_radio_button_renderer);
};

renderer::renderer() : data_(new_sptr<data>()) {
}

renderer::renderer(const string& name) : renderer() {
  data_->name = name;
}

renderer::renderer(const renderer& value) : renderer() {
  *data_ = *value.data_;
}

auto renderer::operator =(const renderer& value) -> renderer& {
  *data_ = *value.data_;
  return *this;
}

auto renderer::name() const -> const string& {
  return data_->name;
}

auto renderer::name(const string& value) -> renderer& {
  data_->name = value;
  return *this;
}

auto renderer::button_render() const noexcept -> const button_renderer& {
  return data_->button_renderer;
}

auto renderer::button_render(button_renderer value) -> renderer& {
  data_->button_renderer = value;
  return *this;
}

auto renderer::check_box_render() const noexcept -> const check_box_renderer& {
  return data_->check_box_renderer;
}

auto renderer::check_box_render(check_box_renderer value) -> renderer& {
  data_->check_box_renderer = value;
  return *this;
}

auto renderer::radio_button_render() const noexcept -> const radio_button_renderer& {
  return data_->radio_button_renderer;
}

auto renderer::radio_button_render(radio_button_renderer value) -> renderer& {
  data_->radio_button_renderer = value;
  return *this;
}

auto renderer::draw_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, push_button_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  data_->button_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

auto renderer::draw_check_box(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused,check_box_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  data_->check_box_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

auto renderer::draw_radio_button(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, radio_button_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  data_->radio_button_renderer(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

auto renderer::equals(const object& obj) const noexcept -> bool {
  return is<renderer>(obj) && equals(static_cast<const renderer&>(obj));
}

auto renderer::equals(const renderer& other) const noexcept -> bool {
  return data_->name == other.data_->name;
}

auto renderer::get_hash_code() const noexcept -> usize {
  return hash_code::combine(data_->name);
}

auto renderer::to_string() const noexcept -> string {
  if (!string::is_empty(data_->name)) return string::format("{}, name: {}", get_type().full_name(), data_->name);
  return string::format(get_type().full_name());
}

auto renderer::default_button_renderer(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, visual_styles::push_button_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  xtd::forms::button_renderer::draw_button(g, bounds, state, false, back_color, text, std::optional<content_alignment>(), fore_color, font, image, std::optional<content_alignment>());
  //xtd::forms::button_renderer::draw_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

auto renderer::default_check_box_renderer(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, visual_styles::check_box_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  xtd::forms::check_box_renderer::draw_check_box(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}

auto renderer::default_radio_button_renderer(graphics g, const rectangle& bounds, const string& text, const font& font, text_format_flags flags, const image& image, const rectangle& image_bounds, bool focused, visual_styles::radio_button_state state, const std::optional<color>& back_color, const std::optional<color>& fore_color) -> void {
  xtd::forms::radio_button_renderer::draw_radio_button(g, bounds, text, font, flags, image, image_bounds, focused, state, back_color, fore_color);
}
