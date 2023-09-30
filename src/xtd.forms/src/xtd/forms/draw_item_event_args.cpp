#include "../../../include/xtd/forms/draw_item_event_args.h"

using namespace xtd;
using namespace xtd::forms;

struct draw_item_event_args::data {
  xtd::drawing::color back_color;
  xtd::drawing::rectangle bounds;
  xtd::drawing::font font = xtd::drawing::system_fonts::default_font();
  xtd::drawing::color fore_color;
  xtd::drawing::graphics* graphics = nullptr;
  size_t index = xtd::forms::control::control_collection::npos;
  xtd::forms::draw_item_state state = xtd::forms::draw_item_state::none;
};

draw_item_event_args::draw_item_event_args(const draw_item_event_args& other) : data_(std::make_shared<data>()) {
  *data_ = *other.data_;
}

draw_item_event_args& draw_item_event_args::operator =(const draw_item_event_args& other) {
  *data_ = *other.data_;
  return *this;
}

draw_item_event_args::draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state) : data_(std::make_shared<data>()) {
  data_->font = font;
  data_->graphics = &graphics;
  data_->index = index;
  data_->state = state;
}

draw_item_event_args::draw_item_event_args(xtd::drawing::graphics& graphics, const xtd::drawing::font& font, const xtd::drawing::rectangle& rect, size_t index, xtd::forms::draw_item_state state, const xtd::drawing::color& back_color, const xtd::drawing::color& fore_core) : data_(std::make_shared<data>()) {
  data_->back_color = back_color;
  data_->font = font;
  data_->fore_color = back_color;
  data_->graphics = &graphics;
  data_->index = index;
  data_->state = state;
}

const xtd::drawing::color& draw_item_event_args::back_color() const noexcept {
  return data_->back_color;
}

const xtd::drawing::rectangle& draw_item_event_args::bounds() const noexcept {
  return data_->bounds;
}

const xtd::drawing::font& draw_item_event_args::font() const noexcept {
  return data_->font;
}

const xtd::drawing::color& draw_item_event_args::fore_color() const noexcept {
  return data_->fore_color;
}

xtd::drawing::graphics& draw_item_event_args::graphics() noexcept {
  return *data_->graphics;
}

size_t draw_item_event_args::index() const noexcept {
  return data_->index;
}

xtd::forms::draw_item_state draw_item_event_args::state() const noexcept {
  return data_->state;
}
