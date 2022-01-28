#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/theme_selector.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

theme_selector::theme_selector(const ustring& name) : name_(name) {
}

theme_selector::theme_selector(const ustring& name, const ustring& description) : name_(name), description_(description) {
}

theme_selector::theme_selector(const ustring& name, const ustring& description, const ustring& authors) : name_(name), description_(description), authors_(authors) {
}

theme_selector::theme_selector(const ustring& name, const ustring& description, const ustring& authors, const uri& website) : name_(name), description_(description), authors_(authors), website_(website) {
}

const ustring& theme_selector::authors() const noexcept {
  return authors_;
}

void theme_selector::authors(const ustring& value) noexcept {
  authors_ = value;
}

const ustring& theme_selector::description() const noexcept {
  return description_;
}

void theme_selector::description(const ustring& value) noexcept {
  description_ = value;
}

const ustring& theme_selector::name() const noexcept {
  return name_;
}

void theme_selector::name(const ustring& value) noexcept {
  name_ = value;
}

const uri& theme_selector::website() const noexcept {
  return website_;
}

void theme_selector::website(const uri& value) noexcept {
  website_ = value;
}

bool theme_selector::from_css(const xtd::ustring& css_text, theme_selector& result) {
  return try_parse(css_text, result);
}

theme_selector theme_selector::parse(const xtd::ustring& text) {
  theme_selector result;
  if (!try_parse(text, result))
    throw argument_exception(csf_);
  return result;
}

xtd::ustring theme_selector::to_string() const noexcept {
  return ustring::format("[name={}, description={}, authors={}, website={}, ]", name(), description(), authors(), website());
}

xtd::ustring theme_selector::to_css() const noexcept {
  return ustring::format("  name: \"{}\";\n  description: \"{}\";\n  authors:\"{}\";\n  website=url(\"{}\");\n", name(), description(), authors(), website());
}

bool theme_selector::try_parse(const xtd::ustring& text, theme_selector& result) {
  return false;
}
