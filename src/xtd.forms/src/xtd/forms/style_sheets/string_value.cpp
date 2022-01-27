#include "../../../../include/xtd/forms/style_sheets/string_value.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

string_data::string_data(const ustring& text) : text_(text) {
}

const ustring& string_data::text() const noexcept {
  return text_;
}

void string_data::text(const ustring& value) noexcept {
  text_ = value;
}

bool string_data::from_css(const xtd::ustring& css_text, string_data& result)  noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return false;
  result = string_data(value.remove(value.size() - 1, 1).replace("\"", ""));
  return true;
}

string_data string_data::from_css(const xtd::ustring& css_text, const string_data& default_value) noexcept {
  string_data result;
  if (from_css(css_text, result)) return result;
  return default_value;
}

xtd::ustring string_data::to_css() const noexcept {
  return ustring::format("\"{}\"", text());
}
