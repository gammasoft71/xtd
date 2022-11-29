#include "../../../include/xtd/forms/nine_segment_display.h"

using namespace xtd;
using namespace xtd::forms;

int32_t nine_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));
}

seven_segment_display& nine_segment_display::thickness(int32_t value) {
  if (!data_->thickness.has_value() || data_->thickness.value() != value) {
    data_->thickness = value;
    invalidate();
  }
  return *this;
}

void nine_segment_display::on_paint(paint_event_args& e) {
  seven_segment_display::on_paint(e);
  if ((value() & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
  if ((value() & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
}

void nine_segment_display::draw_back_digit(drawing::graphics& graphics) {
  seven_segment_display::draw_back_digit(graphics);
  draw_segment_h(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_i(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
}

void nine_segment_display::draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), 2 + thickness(), 2 + thickness(), size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), 2 + thickness() + abs(offset), 2 + thickness() + abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void nine_segment_display::draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), size().height() / 2 + 2 + thickness() / 2, 2 + thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), size().height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size().height() - 3 - thickness());
  }
}
