#include "../../../../include/xtd/forms/style_sheets/text_data.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;


text_data::text_data(const drawing::color& color) : color_(color) {
}

text_data::text_data(const drawing::color& color, xtd::forms::content_alignment alignment) : color_(color), alignment_(alignment) {
}

text_data::text_data(const drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) : color_(color), alignment_(alignment), font_(font) {
}

text_data::text_data(const drawing::color& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font, xtd::forms::style_sheets::text_decoration decoration, xtd::forms::style_sheets::text_transformation transformation) : color_(color), alignment_(alignment), font_(font), decoration_(decoration), transformation_(transformation) {
}

content_alignment text_data::alignment() const noexcept {
  return alignment_;
}

void text_data::alignment(content_alignment value) noexcept {
  alignment_ = value;
}

const drawing::color& text_data::color() const noexcept {
  return color_;
}

void text_data::color(const drawing::color& value) noexcept {
  color_ = value;
}

text_decoration text_data::decoration() const noexcept {
  return decoration_;
}

void text_data::decoration(text_decoration value) noexcept {
  decoration_ = value;
}

text_transformation text_data::transformation() const noexcept {
  return transformation_;
}

void text_data::transformation(text_transformation value) noexcept {
  transformation_ = value;
}

const font& text_data::font() const noexcept {
  return font_;
}

void text_data::font(const drawing::font& value) noexcept {
  font_ = value;
}

string_format text_data::text_data::make_string_format(const xtd::forms::style_sheets::text_data& data) {
  string_format format;
  format.line_alignment(xtd::drawing::string_alignment::center);
  format.alignment(xtd::drawing::string_alignment::center);
  
  if (data.alignment() == content_alignment::top_left) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (data.alignment() == content_alignment::top_center) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (data.alignment() == content_alignment::top_right) {
    format.line_alignment(xtd::drawing::string_alignment::near);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (data.alignment() == content_alignment::middle_left) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (data.alignment() == content_alignment::middle_center) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (data.alignment() == content_alignment::middle_right) {
    format.line_alignment(xtd::drawing::string_alignment::center);
    format.alignment(xtd::drawing::string_alignment::far);
  }
  
  if (data.alignment() == content_alignment::bottom_left) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::near);
  }
  
  if (data.alignment() == content_alignment::bottom_center) {
    format.line_alignment(xtd::drawing::string_alignment::far);
    format.alignment(xtd::drawing::string_alignment::center);
  }
  
  if (data.alignment() == content_alignment::bottom_right) {
    format.alignment(xtd::drawing::string_alignment::far);
    format.line_alignment(xtd::drawing::string_alignment::far);
  }

  return format;
}
