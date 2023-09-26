#include "../../../include/xtd/drawing/text/installed_font_collection"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/font_family>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

struct font_family::data {
  intptr handle_ = 0;
  xtd::ustring name_;
};

font_family::font_family(const ustring& name) : data_(std::make_shared<data>()) {
  data_->name_ = name;
  if (data_->name_.empty()) throw xtd::argument_exception("name is an empty string"_t, csf_);
  data_->handle_ = native::font_family::create(name);
  if (data_->handle_ == 0) throw xtd::argument_exception("name specifies a font that is not installed on the computer running the application."_t, csf_);
}

font_family::font_family(text::generic_font_families generic_font_families) : data_(std::make_shared<data>()) {
  switch (generic_font_families) {
    case text::generic_font_families::serif: *this = font_family(native::font_family::generic_serif_name()); break;
    case text::generic_font_families::sans_serif: *this = font_family(native::font_family::generic_sans_serif_name()); break;
    case text::generic_font_families::monospace: *this = font_family(native::font_family::generic_monospace_name()); break;
    default: throw xtd::argument_exception("name specifies a font that is not installed on the computer running the application."_t, csf_);
  }
}

font_family::font_family(const ustring& name, const text::font_collection& font_collection) : data_(std::make_shared<data>()) {
  auto font_families = font_collection.families();
  auto iterator = find_if(font_families.begin(), font_families.end(), [&](const font_family & font_family) {return name == font_family.name();});
  if (iterator == font_families.end()) throw xtd::argument_exception("name specifies a font that is not a part of specified font_collection."_t, csf_);
  *this = *iterator;
}

font_family::font_family(const font_family& value) : data_(std::make_shared<data>()) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
  data_ = value.data_;
}

font_family::font_family() : data_(std::make_shared<data>()) {

}

font_family& font_family::operator =(const font_family& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

font_family::~font_family() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::font_family::destroy(data_->handle_);
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

const xtd::ustring& font_family::name() const noexcept {
  return data_->name_;
}

bool font_family::equals(const font_family& value) const noexcept {
  return data_->name_ == value.data_->name_;
}

int32 font_family::get_cell_ascent(font_style style) const {
  return native::font_family::get_cell_ascent(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32 font_family::get_cell_descent(font_style style) const {
  return native::font_family::get_cell_descent(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

int32 font_family::get_em_height(font_style style) const noexcept {
  return 2048;
}

int32 font_family::get_line_spacing(font_style style) const {
  return native::font_family::get_line_spacing(data_->handle_, get_em_height(style), (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

ustring font_family::get_name(int32 language) const {
  return native::font_family::get_name(data_->handle_, language);
}

bool font_family::is_style_available(font_style style) const {
  return native::font_family::is_style_available(data_->handle_, (style & font_style::bold) == font_style::bold, (style & font_style::italic) == font_style::italic, (style & font_style::underline) == font_style::underline, (style & font_style::strikeout) == font_style::strikeout);
}

xtd::ustring font_family::to_string() const noexcept {
  return ustring::format("[{}: name={}]", get_type().name(), data_->name_);
}
