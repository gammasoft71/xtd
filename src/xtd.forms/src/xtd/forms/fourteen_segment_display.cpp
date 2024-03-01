#include "../../../include/xtd/forms/fourteen_segment_display.h"
#include <xtd/drawing/color_transformer.h>

using namespace xtd;
using namespace xtd::forms;

struct fourteen_segment_display::data {
  std::optional<int32> thickness;
};

fourteen_segment_display::fourteen_segment_display() : data_(std::make_shared<data>()) {
}

int32 fourteen_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));
}

seven_segment_display& fourteen_segment_display::thickness(int32 value) {
  if (!data_->thickness.has_value() || data_->thickness.value() != value) {
    data_->thickness = value;
    invalidate();
  }
  return *this;
}

fourteen_segment_display fourteen_segment_display::create() {
  return fourteen_segment_display {};
}

fourteen_segment_display fourteen_segment_display::create(const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  return item;
}
fourteen_segment_display fourteen_segment_display::create(const control& parent, const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  return item;
}
fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}
fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

fourteen_segment_display fourteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = fourteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

void fourteen_segment_display::draw_back_digit(drawing::graphics& graphics) {
  seven_segment_display::draw_back_digit(graphics);
  draw_segment_g1(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_g2(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_h(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_i(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_j(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_k(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_l(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_m(graphics, drawing::color_transformer::average(back_segment_color(), back_color(), back_segment_opacity()));
}

void fourteen_segment_display::draw_segment_g(drawing::graphics& graphics, const drawing::color& color) {
}

void fourteen_segment_display::draw_segment_g1(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  }
}

void fourteen_segment_display::draw_segment_g2(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - abs(2 * offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness(), size().height() / 2 + offset);
  }
}

void fourteen_segment_display::draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), 2 + thickness() + abs(offset), 2 + thickness(), size().width() / 2 - thickness() / 2 - 2, size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), 2 + thickness(), 2 + thickness() + abs(offset), size().width() / 2 - 2 - thickness() / 2 - abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void fourteen_segment_display::draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
    graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness(), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
}

void fourteen_segment_display::draw_segment_j(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), 2 + thickness(), size().width()  / 2 + 2 + thickness() / 2, size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), 2 + thickness() + abs(offset), size().width() / 2 + 2 + thickness() / 2 + abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void fourteen_segment_display::draw_segment_k(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() / 2 - 2 - thickness() / 2 - abs(offset), size().height() / 2 + 2 + thickness() / 2, 2 + thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() / 2 - 2 - thickness() / 2, size().height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size().height() - 3 - thickness());
  }
}

void fourteen_segment_display::draw_segment_l(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
    graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness());
}

void fourteen_segment_display::draw_segment_m(drawing::graphics& graphics, const drawing::color& color) {
  for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width()  / 2 + 2 + thickness() / 2 + abs(offset), size().height() / 2 + 2 + thickness() / 2, size().width() - 3 - thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width()  / 2 + 2 + thickness() / 2, size().height() / 2 + 2 + thickness() / 2 + abs(offset), size().width() - 3 - thickness() - abs(offset), size().height() - 3 - thickness());
  }
}

void fourteen_segment_display::on_paint(paint_event_args& e) {
  seven_segment_display::on_paint(e);
  if ((value() & forms::segments::g1) == forms::segments::g1) draw_segment_g1(e.graphics(), fore_color());
  if ((value() & forms::segments::g2) == forms::segments::g2) draw_segment_g2(e.graphics(), fore_color());
  if ((value() & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
  if ((value() & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
  if ((value() & forms::segments::j) == forms::segments::j) draw_segment_j(e.graphics(), fore_color());
  if ((value() & forms::segments::k) == forms::segments::k) draw_segment_k(e.graphics(), fore_color());
  if ((value() & forms::segments::l) == forms::segments::l) draw_segment_l(e.graphics(), fore_color());
  if ((value() & forms::segments::m) == forms::segments::m) draw_segment_m(e.graphics(), fore_color());
}
