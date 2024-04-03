#include "../../../include/xtd/forms/seven_segment_display.h"
#include <xtd/drawing/color_converter>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct seven_segment_display::data {
  std::optional<drawing::color> back_segment_color;
  double back_segment_opacity = 0.95;
  forms::segment_style segment_style = forms::segment_style::standard;
  bool show_back_segment = true;
  std::optional<int32> thickness;
  forms::segments value = forms::segments::none;
};

seven_segment_display::seven_segment_display() : data_(std::make_shared<data>()) {
  back_color(application::style_sheet().system_colors().control());
  double_buffered(true);
}

drawing::color seven_segment_display::back_segment_color() const noexcept {
  return data_->back_segment_color.value_or(fore_color());
}

seven_segment_display& seven_segment_display::back_segment_color(const drawing::color& value) {
  if (data_->back_segment_color.has_value() && data_->back_segment_color.value() == value) return *this;
  data_->back_segment_color = value;
  invalidate();
  return *this;
}

double seven_segment_display::back_segment_opacity() const noexcept {
  return data_->back_segment_opacity;
}

seven_segment_display& seven_segment_display::back_segment_opacity(double value) {
  if (value < 0.0 || value > 1.0) throw argument_out_of_range_exception("value must be between 0.0 and 1.0."_t, csf_);
  if (data_->back_segment_opacity == value) return *this;
  data_->back_segment_opacity = value;
  invalidate();
  return *this;
}

bool seven_segment_display::show_back_segment() const noexcept {
  return data_->show_back_segment;
}

seven_segment_display& seven_segment_display::show_back_segment(bool value) {
  if (data_->show_back_segment == value) return *this;
  data_->show_back_segment = value;
  invalidate();
  return *this;
}

forms::segment_style seven_segment_display::segment_style() const noexcept {
  return data_->segment_style;
}

seven_segment_display& seven_segment_display::segment_style(forms::segment_style value) {
  if (data_->segment_style == value) return *this;
  data_->segment_style = value;
  invalidate();
  return *this;
}

int32 seven_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 10 ? 1 : (size().height() / 10 + ((size().height() / 10) % 2 ? 0 : 1)));
}

seven_segment_display& seven_segment_display::thickness(int32 value) {
  if (data_->thickness.has_value() && data_->thickness.value() == value) return *this;
  data_->thickness = value;
  invalidate();
  return *this;
}

forms::segments seven_segment_display::value() const noexcept {
  return data_->value;
}

seven_segment_display& seven_segment_display::value(forms::segments value) {
  if (data_->value == value) return *this;
  data_->value = value;
  invalidate();
  return *this;
}

seven_segment_display seven_segment_display::create() {
  return seven_segment_display {};
}

seven_segment_display seven_segment_display::create(const drawing::point& location) {
  auto item = seven_segment_display {};
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments) {
  auto item = seven_segment_display {};
  item.value(segments);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, const drawing::point& location) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, bool show_back_segment) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent) {
  auto item = seven_segment_display {};
  item.parent(parent);
  return item;
}
seven_segment_display seven_segment_display::create(const control& parent, const drawing::point& location) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  return item;
}
seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  return item;
}
seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  return item;
}

seven_segment_display seven_segment_display::create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
  auto item = seven_segment_display {};
  item.parent(parent);
  item.value(segments);
  item.show_back_segment(show_back_segment);
  item.location(location);
  item.size(size);
  item.name(name);
  return item;
}

bool seven_segment_display::get_segments(forms::segments segment) const noexcept {
  return (data_->value & segment) == segment;
}

void seven_segment_display::set_segments(forms::segments segment, bool value) {
  data_->value = value ? (data_->value | segment) : (data_->value & ~segment);
}

drawing::size seven_segment_display::default_size() const noexcept {
  return {25, 50};
}

unique_ptr<xtd::object> seven_segment_display::clone() const {
  auto result = make_unique<seven_segment_display>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

void seven_segment_display::draw_back_digit(drawing::graphics& graphics) {
  auto color = enabled() ? drawing::color_converter::average(back_segment_color(), back_color(), back_segment_opacity()) : back_color();
  draw_segment_a(graphics, color);
  draw_segment_b(graphics, color);
  draw_segment_c(graphics, color);
  draw_segment_d(graphics, color);
  draw_segment_e(graphics, color);
  draw_segment_f(graphics, color);
  draw_segment_g(graphics, color);
}

void seven_segment_display::draw_segment_a(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), 1 + thickness() / 2 + offset);
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() - 3 - offset, 1 + offset);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() - 3 - offset, 1 + offset);
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, 1 + offset, size().width() - 3 - offset, 1 + offset);
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() - 3 - thickness(), 1 + offset);
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), 1 + offset, size().width() - 3 - thickness(), 1 + offset);
  }
}

void seven_segment_display::draw_segment_b(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, 2 + thickness() / 2 + abs(offset), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - offset, 2 + offset, size().width() - 2 - offset, size().height() / 2 - 1 - offset / 2);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size().width() - 2 - thickness() / 2 - offset, size().height() / 2 - 1 - abs(offset));
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, 2 + offset + thickness() / 2, size().width() - 2 - thickness() / 2 - offset, size().height() / 2 - 1 - (offset > 0 ? offset : 0));
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, 1, size().width() - 2 - thickness() / 2 - offset, size().height() / 2 - 1 - (offset > 0 ? offset : 0));
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, 1, size().width() - 2 - thickness() / 2 - offset, size().height() / 2 - 1);
  }
}

void seven_segment_display::draw_segment_c(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() - 2 - thickness() / 2 - offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - offset, size().height() / 2 + 1 + offset / 2,  size().width() - 2 - offset, size().height() - 3 - offset);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() - 2 - thickness() / 2 - offset, size().height() - 3 - thickness() / 2 - offset);
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size().width() - 2 - thickness() / 2 - offset, size().height() - 3 - thickness() / 2 - offset);
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), size().width() - 2 - thickness() / 2 - offset, size().height() - 2);
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() - 2 - thickness() / 2 - offset, size().height() / 2 + 1, size().width() - 2 - thickness() / 2 - offset, size().height() - 2);
  }
}

void seven_segment_display::draw_segment_d(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() - 2 - thickness() / 2 - offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() - 2 - thickness() / 2 - offset);
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + offset, size().height() - 2 - offset, size().width() - 3 - offset, size().height() - 2 - offset);
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() - 2 - offset, size().width() - 3 - thickness(), size().height() - 2 - offset);
  }
}

void seven_segment_display::draw_segment_e(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().height() - 3 - thickness() / 2 - abs(offset));
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 1 + offset, size().height() / 2 + 1 + offset / 2, 1 + offset, size().height() - 3 - offset);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().height() - 3 - thickness() / 2 - offset);
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size().height() - 3 - thickness() / 2 - offset);
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + (offset > 0 ? offset : 0), 1 + thickness() / 2 + offset, size().height() - 2);
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, size().height() / 2 + 1, 1 + thickness() / 2 + offset, size().height() - 2);
  }
}

void seven_segment_display::draw_segment_f(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + abs(offset), 1 + thickness() / 2 + offset, size().height() / 2 - 1 - abs(offset));
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), 1 + offset, 2 + offset, 1 + offset, size().height() / 2 - 1 - offset / 2);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size().height() / 2 - 1 - abs(offset));
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 2 + thickness() / 2 + offset, 1 + thickness() / 2 + offset, size().height() / 2 - 1 - (offset > 0 ? offset : 0));
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size().height() / 2 - 1 - (offset > 0 ? offset : 0));
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 1 + thickness() / 2 + offset, 1, 1 + thickness() / 2 + offset, size().height() / 2 - 1);
  }
}

void seven_segment_display::draw_segment_g(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size().height() / 2 + offset, size().width() - 3 - abs(2 * offset), size().height() / 2 + offset);
  } else if (data_->segment_style == segment_style::mixed) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (data_->segment_style == segment_style::expanded) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (data_->segment_style == segment_style::design) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() / 2 + offset, size().width() - 3 - thickness(), size().height() / 2 + offset);
  }
}

void seven_segment_display::draw_dp(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard)
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() - 1 - thickness(), thickness(), thickness());
  else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() - 2 - offset, size().width() / 2 + thickness() / 2, size().height() - 2 - offset);
  } else if (data_->segment_style == segment_style::mixed)
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() - 1 - thickness(), thickness(), thickness());
  else if (data_->segment_style == segment_style::expanded)
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() - 1 - thickness(), thickness(), thickness());
  else if (data_->segment_style == segment_style::design)
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() - 1 - thickness(), thickness(), thickness());
  else if (data_->segment_style == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() - 2 - offset, size().width() / 2 + thickness() / 2, size().height() - 2 - offset);
  }
}

void seven_segment_display::draw_pc(drawing::graphics& graphics, const drawing::color& color) {
  if (data_->segment_style == segment_style::standard) {
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2, thickness(), thickness());
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2, thickness(), thickness());
  } else if (data_->segment_style == segment_style::modern) {
    for (auto offset = 0; offset < thickness(); offset++) {
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2 + offset, size().width() / 2 + thickness() / 2, size().height() / 3 - thickness() / 2 + offset);
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2 + offset, size().width() / 2 + thickness() / 2, size().height() / 3 * 2 - thickness() / 2 + offset);
    }
  } else if (data_->segment_style == segment_style::mixed) {
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2, thickness(), thickness());
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2, thickness(), thickness());
  } else if (data_->segment_style == segment_style::expanded) {
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2, thickness(), thickness());
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2, thickness(), thickness());
  } else if (data_->segment_style == segment_style::design) {
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2, thickness(), thickness());
    graphics.fill_ellipse(drawing::solid_brush(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2, thickness(), thickness());
  } else if (data_->segment_style == segment_style::stick) {
    for (auto offset = 0; offset < thickness(); offset++) {
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() / 3 - thickness() / 2 + offset, size().width() / 2 + thickness() / 2, size().height() / 3 - thickness() / 2 + offset);
      graphics.draw_line(drawing::pen(color), size().width() / 2 - thickness() / 2, size().height() / 3 * 2 - thickness() / 2 + offset, size().width() / 2 + thickness() / 2, size().height() / 3 * 2 - thickness() / 2 + offset);
    }
  }
}

void seven_segment_display::on_back_color_changed(const event_args& e) {
  control::on_back_color_changed(e);
  invalidate();
}

void seven_segment_display::on_enabled_changed(const event_args& e) {
  control::on_enabled_changed(e);
  invalidate();
}

void seven_segment_display::on_fore_color_changed(const event_args& e) {
  control::on_fore_color_changed(e);
  invalidate();
}

void seven_segment_display::on_paint(paint_event_args& e) {
  control::on_paint(e);
  e.graphics().clear(back_color());
  if (data_->show_back_segment) draw_back_digit(e.graphics());
  auto color = enabled() ? fore_color() : application::style_sheet().system_colors().gray_text();
  if ((data_->value & forms::segments::dp) == forms::segments::dp) draw_dp(e.graphics(), color);
  if ((data_->value & forms::segments::pc) == forms::segments::pc) draw_pc(e.graphics(), color);
  if ((data_->value & forms::segments::a) == forms::segments::a) draw_segment_a(e.graphics(), color);
  if ((data_->value & forms::segments::b) == forms::segments::b) draw_segment_b(e.graphics(), color);
  if ((data_->value & forms::segments::c) == forms::segments::c) draw_segment_c(e.graphics(), color);
  if ((data_->value & forms::segments::d) == forms::segments::d) draw_segment_d(e.graphics(), color);
  if ((data_->value & forms::segments::e) == forms::segments::e) draw_segment_e(e.graphics(), color);
  if ((data_->value & forms::segments::f) == forms::segments::f) draw_segment_f(e.graphics(), color);
  if ((data_->value & forms::segments::g) == forms::segments::g) draw_segment_g(e.graphics(), color);
}

void seven_segment_display::on_parent_enabled_changed(const event_args& e) {
  control::on_parent_enabled_changed(e);
  invalidate();
}

drawing::size seven_segment_display::measure_control() const noexcept {
  return drawing::size((height() - 3) / 2 + 2, height());
}

void seven_segment_display::set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) {
  if ((specified & bounds_specified::width) == forms::bounds_specified::width && (specified & bounds_specified::height) != forms::bounds_specified::height) {
    height = (width - 2) * 2 + 3;
    specified |= bounds_specified::height;
  }
  if ((specified & bounds_specified::height) == forms::bounds_specified::height) {
    width = (height - 3) / 2 + 2;
    specified |= bounds_specified::width;
  }
  control::set_bounds_core(x, y, width, height, specified);
}

void seven_segment_display::set_client_size_core(int32 width, int32 height) {
  if (client_size().height() != height)
    width = (height - 3) / 2 + 2;
  if (client_size().width() != width)
    height = (width - 2) * 2 + 3;
  control::set_client_size_core(width, height);
}
