#include "../../../../include/xtd/forms/style_sheets/url_data.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

url_data::url_data(const ustring& url) : url_(url) {
}

const ustring& url_data::url() const noexcept {
  return url_;
}

void url_data::url(const ustring& value) noexcept {
  url_ = value;
}

bool url_data::from_css(const xtd::ustring& css_text, url_data& result)  noexcept {
  auto value = css_text.replace("\n", "").replace("\r", "").replace(";", "").trim();
  if (!value.starts_with("url") || !value.ends_with(")")) return false;
  result = url_data(value.remove(value.size() - 1, 1).replace("url(", ""));
  return true;
}

url_data url_data::from_css(const xtd::ustring& css_text, const url_data& default_value) noexcept {
  url_data result;
  if (from_css(css_text, result)) return result;
  return default_value;
}

xtd::ustring url_data::to_css() const noexcept {
  return ustring::format("url({})", url());
}

xtd::ustring url_data::to_string() const noexcept {
  return ustring::format("url({})", url());
}
