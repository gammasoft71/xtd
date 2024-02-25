#include "../../../include/xtd/forms/sixteen_segment_display.h"

using namespace xtd;
using namespace xtd::forms;

struct sixteen_segment_display::data {
  std::optional<int32> thickness;
};

sixteen_segment_display::sixteen_segment_display() : data_(std::make_shared<data>()) {
}

int32 sixteen_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));
}

seven_segment_display& sixteen_segment_display::thickness(int32 value) {
  if (data_->thickness.has_value() && data_->thickness.value() == value) return *this;
  data_->thickness = value;
  invalidate();
  return *this;
}

sixteen_segment_display sixteen_segment_display::create() {
  return sixteen_segment_display {};
}

sixteen_segment_display sixteen_segment_display::create(const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  return item;
}
sixteen_segment_display sixteen_segment_display::create(const control& parent, const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  return item;
}
sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}
sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

sixteen_segment_display sixteen_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = sixteen_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

void sixteen_segment_display::draw_back_digit(drawing::graphics& graphics) {
  fourteen_segment_display::draw_back_digit(graphics);
  draw_segment_a1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_a2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_d1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_d2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
}

void sixteen_segment_display::draw_segment_a(drawing::graphics& graphics, const drawing::color& color) {
}

void sixteen_segment_display::draw_segment_a1(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() / 2 - 1 - abs(offset / 2), 1 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset + thickness() / 2, 1 + thickness() / 2 + offset, size().width() / 2 - 1 - abs(offset), 1 + thickness() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() / 2 - 1, 1 + offset);
  }
}

void sixteen_segment_display::draw_segment_a2(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset / 2), 1 + offset, size().width() - 3 - offset, 1 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), 1 + thickness() / 2 + offset, size().width() - 3 - thickness() / 2 - offset, 1 + thickness() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size().width() - 3 - offset, 1 + offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), 1 + offset, size().width() - 3 - thickness(), 1 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1, 1 + offset, size().width() - 3 - thickness(), 1 + offset);
  }
}

void sixteen_segment_display::draw_segment_d(drawing::graphics& graphics, const drawing::color& color) {
}

void sixteen_segment_display::draw_segment_d1(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() / 2 - 1 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() / 2 - 1 - abs(offset / 2), size().height() - 2 - offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + offset, size().height() - 2 - thickness() / 2 - offset, size().width() / 2 - 1 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() / 2 + thickness() / 2 - 1 - (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() / 2 - 1, size().height() - 2 - offset);
  }
}

void sixteen_segment_display::draw_segment_d2(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset / 2), size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() - 3 - thickness() / 2 - offset, size().height() - 2 - thickness() / 2 - offset);
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
  } else if (segment_style() == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 - thickness() / 2 + (offset > thickness() / 2 ? offset : thickness() / 2), size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1, size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
  }
}

void sixteen_segment_display::draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + abs(2 * offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (segment_style() == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness(), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  }
}

void sixteen_segment_display::draw_segment_l(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (segment_style() == segment_style::modern) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - abs(2 * offset));
  } else if (segment_style() == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (segment_style() == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (segment_style() == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (segment_style() == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness());
  }
}

void sixteen_segment_display::on_paint(paint_event_args& e) {
  fourteen_segment_display::on_paint(e);
  if ((value() & forms::segments::a1) == forms::segments::a1) draw_segment_a1(e.graphics(), fore_color());
  if ((value() & forms::segments::a2) == forms::segments::a2) draw_segment_a2(e.graphics(), fore_color());
  if ((value() & forms::segments::d1) == forms::segments::d1) draw_segment_d1(e.graphics(), fore_color());
  if ((value() & forms::segments::d2) == forms::segments::d2) draw_segment_d2(e.graphics(), fore_color());
}
