#include "../../../../include/xtd/forms/style_sheets/text_data.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;


text_data::text_data(const color_data& color) : color_(color) {
}

text_data::text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment) : color_(color), alignment_(alignment) {
}

text_data::text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font) : color_(color), alignment_(alignment), font_(font) {
}

text_data::text_data(const xtd::forms::style_sheets::color_data& color, xtd::forms::content_alignment alignment, const xtd::drawing::font& font, xtd::forms::style_sheets::text_decoration decoration, xtd::forms::style_sheets::text_transformation transformation) : color_(color), alignment_(alignment), font_(font), decoration_(decoration), transformation_(transformation) {
}

content_alignment text_data::alignment() const noexcept {
  return alignment_;
}

const color_data& text_data::color() const noexcept {
  return color_;
}

text_decoration text_data::decoration() const noexcept {
  return decoration_;
}

text_transformation text_data::transformation() const noexcept {
  return transformation_;
}

const font& text_data::font() const noexcept {
  return font_;
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
