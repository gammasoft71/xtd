#include "../../../../include/xtd/forms/style_sheets/string_value.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

const string_value string_value::empty;

string_value::string_value(const ustring& text) : text_(text) {
}

const ustring& string_value::text() const noexcept {
  return text_;
}

void string_value::text(const ustring& value) noexcept {
  text_ = value;
}

bool string_value::from_css(const xtd::ustring& css_text, string_value& result)  noexcept {
  auto value = css_text.trim();
  if (!value.starts_with("\"") || !value.ends_with("\"")) return false;
  result = string_value(value.remove(value.size() - 1, 1).replace("\"", ""));
  return true;
}

string_value string_value::from_css(const xtd::ustring& css_text, const string_value& default_value) noexcept {
  string_value result;
  if (from_css(css_text, result)) return result;
  return default_value;
}

xtd::ustring string_value::to_css() const noexcept {
  return ustring::format("\"{}\"", text());
}
