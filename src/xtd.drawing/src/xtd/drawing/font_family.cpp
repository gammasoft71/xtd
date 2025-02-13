#include "../../../include/xtd/drawing/text/installed_font_collection.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::drawing;

struct font_family::data {
  intptr handle = 0;
  xtd::string name;
};

font_family::font_family(const string& name) : data_(xtd::new_sptr<data>()) {
  data_->name = name;
  if (data_->name.empty()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "name is an empty string"_t);
  data_->handle = native::font_family::create(name);
  if (data_->handle == 0) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "name specifies a font that is not installed on the computer running the application."_t);
}

font_family::font_family(text::generic_font_families generic_font_families) : data_(xtd::new_sptr<data>()) {
  switch (generic_font_families) {
    case text::generic_font_families::serif: *this = font_family(native::font_family::generic_serif_name()); break;
    case text::generic_font_families::sans_serif: *this = font_family(native::font_family::generic_sans_serif_name()); break;
    case text::generic_font_families::monospace: *this = font_family(native::font_family::generic_monospace_name()); break;
    default: xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "name specifies a font that is not installed on the computer running the application."_t);
  }
}

font_family::font_family(const string& name, const text::font_collection& font_collection) : data_(xtd::new_sptr<data>()) {
  auto font_families = font_collection.families();
  auto iterator = std::find_if(font_families.begin(), font_families.end(), [&](const font_family & font_family) {return name == font_family.name();});
  if (iterator == font_families.end()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "name specifies a font that is not a part of specified font_collection."_t);
  *this = *iterator;
}

font_family::font_family(const font_family& value) : data_(xtd::new_sptr<data>()) {
  if (data_.use_count() == 1 && data_->handle != 0) native::font_family::destroy(data_->handle);
  data_ = value.data_;
}

font_family::font_family() : data_(xtd::new_sptr<data>()) {

}

font_family& font_family::operator =(const font_family& value) {
  if (data_.use_count() == 1 && data_->handle != 0) native::font_family::destroy(data_->handle);
  data_ = value.data_;
  return *this;
}

font_family::~font_family() {
  if (data_.use_count() == 1 && data_->handle != 0) native::font_family::destroy(data_->handle);
}

std::vector<font_family> font_family::families() noexcept {
  return text::installed_font_collection().families();
}

font_family font_family::generic_monospace() noexcept {
  return font_family(text::generic_font_families::monospace);
}

font_family font_family::generic_sans_serif() noexcept {
  return font_family(text::generic_font_families::sans_serif);
}

font_family font_family::generic_serif() noexcept {
  return font_family(text::generic_font_families::serif);
}

const xtd::string& font_family::name() const noexcept {
  return data_->name;
}

bool font_family::equals(const object& obj) const noexcept {
  return is<font_family>(obj) && equals(static_cast<const font_family&>(obj));
}

bool font_family::equals(const font_family& other) const noexcept {
  return data_->name == other.data_->name;
}

int32 font_family::get_cell_ascent(font_style style) const {
  return native::font_family::get_cell_ascent(data_->handle, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32 font_family::get_cell_descent(font_style style) const {
  return native::font_family::get_cell_descent(data_->handle, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32 font_family::get_em_height(font_style style) const noexcept {
  return 2048;
}

size font_family::get_hash_code() const noexcept {
  return hash_code::combine(data_->name);
}

int32 font_family::get_line_spacing(font_style style) const {
  return native::font_family::get_line_spacing(data_->handle, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

string font_family::get_name(int32 language) const {
  return native::font_family::get_name(data_->handle, language);
}

bool font_family::is_style_available(font_style style) const {
  return native::font_family::is_style_available(data_->handle, (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

xtd::string font_family::to_string() const noexcept {
  return string::format("[{}: name={}]", get_type().name(), data_->name);
}
