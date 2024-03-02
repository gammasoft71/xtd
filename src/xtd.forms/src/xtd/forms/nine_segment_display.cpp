#include "../../../include/xtd/forms/nine_segment_display.h"
#include <xtd/drawing/color_converter>

using namespace xtd;
using namespace xtd::forms;

struct nine_segment_display::data {
  std::optional<int32> thickness;
};

nine_segment_display::nine_segment_display() : data_(std::make_shared<data>()) {
}

int32 nine_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));
}

seven_segment_display& nine_segment_display::thickness(int32 value) {
  if (!data_->thickness.has_value() || data_->thickness.value() != value) {
    data_->thickness = value;
    invalidate();
  }
  return *this;
}

nine_segment_display nine_segment_display::create() {
  return nine_segment_display {};
}

nine_segment_display nine_segment_display::create(const drawing::point& location) {
  auto item = nine_segment_display {};
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments) {
  auto item = nine_segment_display {};
  item.value(segments);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, const drawing::point& location) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, bool show_back_segment) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent) {
  auto item = nine_segment_display {};
  item.parent(parent);
  return item;
}
nine_segment_display nine_segment_display::create(const control& parent, const drawing::point& location) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  return item;
}
nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}
nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

nine_segment_display nine_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = nine_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

void nine_segment_display::draw_back_digit(drawing::graphics& graphics) {
  seven_segment_display::draw_back_digit(graphics);
  draw_segment_h(graphics, drawing::color_converter::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_i(graphics, drawing::color_converter::average(back_segment_color(), back_color(), back_segment_opacity()));
}

void nine_segment_display::draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), 2 + thickness(), 2 + thickness(), size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), 2 + thickness() + abs(offset), 2 + thickness() + abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void nine_segment_display::draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), size().height() / 2 + 2 + thickness() / 2, 2 + thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), size().height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size().height() - 3 - thickness());
  }
}

void nine_segment_display::on_paint(paint_event_args& e) {
  seven_segment_display::on_paint(e);
  if ((value() & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
  if ((value() & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
}
