#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/theme_data.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

theme_data::theme_data(const string_data& name) : name_(name) {
}

theme_data::theme_data(const string_data& name, const string_data& description) : name_(name), description_(description) {
}

theme_data::theme_data(const string_data& name, const string_data& description, const string_data& authors) : name_(name), description_(description), authors_(authors) {
}

theme_data::theme_data(const string_data& name, const string_data& description, const string_data& authors, const url_data& website) : name_(name), description_(description), authors_(authors), website_(website) {
}

const string_data& theme_data::authors() const noexcept {
  return authors_;
}

void theme_data::authors(const string_data& value) noexcept {
  authors_ = value;
}

const string_data& theme_data::description() const noexcept {
  return description_;
}

void theme_data::description(const string_data& value) noexcept {
  description_ = value;
}

const string_data& theme_data::name() const noexcept {
  return name_;
}

void theme_data::name(const string_data& value) noexcept {
  name_ = value;
}

const url_data& theme_data::website() const noexcept {
  return website_;
}

void theme_data::website(const url_data& value) noexcept {
  website_ = value;
}

bool theme_data::from_css(const xtd::ustring& css_text, theme_data& result) {
  return try_parse(css_text, result);
}

theme_data theme_data::parse(const xtd::ustring& text) {
  theme_data result;
  if (!try_parse(text, result))
    throw argument_exception(csf_);
  return result;
}

xtd::ustring theme_data::to_string() const noexcept {
  return ustring::format("[name={}, description={}, authors={}, website={}, ]", name().text(), description().text(), authors().text(), website().url());
}

xtd::ustring theme_data::to_css() const noexcept {
  return ustring::format("  name: \"{}\";\n  description: \"{}\";\n  authors:\"{}\";\n  website=url(\"{}\");\n", name().text(), description().text(), authors().text(), website().url());
}

bool theme_data::try_parse(const xtd::ustring& text, theme_data& result) {
  return false;
}
