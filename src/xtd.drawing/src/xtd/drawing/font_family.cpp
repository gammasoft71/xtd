#include "../../../include/xtd/drawing/text/installed_font_collection.h"
#include <xtd/argument_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

font_family::font_family(const ustring& name) {
  data_->name_ = name;
  if (data_->name_.empty()) throw xtd::argument_exception("name is an empty string"_t, current_stack_frame_);
  data_->handle_ = native::font_family::create(name);
  if (data_->handle_ == 0) throw xtd::argument_exception("name specifies a font that is not installed on the computer running the application."_t, current_stack_frame_);
}

font_family::font_family(text::generic_font_families generic_font_families) {
  switch (generic_font_families) {
    case text::generic_font_families::serif: *this = font_family(native::font_family::generic_serif_name()); break;
    case text::generic_font_families::sans_serif: *this = font_family(native::font_family::generic_sans_serif_name()); break;
    case text::generic_font_families::monospace: *this = font_family(native::font_family::generic_monospace_name()); break;
    default: throw xtd::argument_exception("name specifies a font that is not installed on the computer running the application."_t, current_stack_frame_);
  }
}

font_family::font_family(const ustring& name, const text::font_collection& font_collection) {
  for (const font_family& font_family : font_collection.families())
    if (name == font_family.name()) {
      *this = font_family;
      return;
    }

  throw xtd::argument_exception("name specifies a font that is not a part of specified font_collection."_t, current_stack_frame_);
}

font_family::font_family(const font_family& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
  data_ = value.data_;
}

font_family& font_family::operator=(const font_family& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

font_family::~font_family() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
}

std::vector<font_family> font_family::families() {
  return text::installed_font_collection().families();
}

int32_t font_family::get_cell_ascent(font_style style) const {
  return native::font_family::get_cell_ascent(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32_t font_family::get_cell_descent(font_style style) const {
  return native::font_family::get_cell_descent(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32_t font_family::get_em_height(font_style style) const {
  return 2048;
}

int32_t font_family::get_line_spacing(font_style style) const {
  return native::font_family::get_line_spacing(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

ustring font_family::get_name(int32_t language) const {
  return native::font_family::get_name(data_->handle_, language);
}

bool font_family::is_style_avaible(font_style style) const {
  return native::font_family::is_style_avaible(data_->handle_, (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}
