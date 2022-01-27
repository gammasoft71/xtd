#include "../../../../include/xtd/forms/style_sheets/url_value.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

url_value::url_value(const ustring& url) : url_(url) {
}

const ustring& url_value::url() const noexcept {
  return url_;
}

void url_value::url(const ustring& value) noexcept {
  url_ = value;
}

bool url_value::from_css(const xtd::ustring& css_text, url_value& result)  noexcept {
  auto value = css_text.replace("\n", "").replace("\r", "").replace(";", "").trim();
  if (!value.starts_with("url") || !value.ends_with(")")) return false;
  result = url_value(value.remove(value.size() - 1, 1).replace("url(", ""));
  return true;
}

url_value url_value::from_css(const xtd::ustring& css_text, const url_value& default_value) noexcept {
  url_value result;
  if (from_css(css_text, result)) return result;
  return default_value;
}

xtd::ustring url_value::to_css() const noexcept {
  return ustring::format("url({})", url());
}

xtd::ustring url_value::to_string() const noexcept {
  return ustring::format("url({})", url());
}
