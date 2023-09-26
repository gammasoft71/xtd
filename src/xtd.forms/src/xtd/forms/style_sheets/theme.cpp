#include "../../../../include/xtd/forms/style_sheets/theme"
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::forms::style_sheets;

theme::theme(const ustring& name) : name_(name) {
}

theme::theme(const ustring& name, const ustring& description) : name_(name), description_(description) {
}

theme::theme(const ustring& name, const ustring& description, const ustring& authors) : name_(name), description_(description), authors_(authors) {
}

theme::theme(const ustring& name, const ustring& description, const ustring& authors, const uri& website) : name_(name), description_(description), authors_(authors), website_(website) {
}

const ustring& theme::authors() const noexcept {
  return authors_;
}

void theme::authors(const ustring& value) noexcept {
  authors_ = value;
}

const ustring& theme::description() const noexcept {
  return description_;
}

void theme::description(const ustring& value) noexcept {
  description_ = value;
}

const ustring& theme::name() const noexcept {
  return name_;
}

void theme::name(const ustring& value) noexcept {
  name_ = value;
}

const uri& theme::website() const noexcept {
  return website_;
}

void theme::website(const uri& value) noexcept {
  website_ = value;
}

bool theme::from_css(const xtd::ustring& css_text, theme& result) {
  return try_parse(css_text, result);
}

theme theme::parse(const xtd::ustring& text) {
  auto result = theme {};
  if (!try_parse(text, result))
    throw argument_exception {csf_};
  return result;
}

xtd::ustring theme::to_string() const noexcept {
  return ustring::format("[name={}, description={}, authors={}, website={}, ]", name(), description(), authors(), website());
}

xtd::ustring theme::to_css() const noexcept {
  return ustring::format("  name: \"{}\";\n  description: \"{}\";\n  authors:\"{}\";\n  website=url(\"{}\");\n", name(), description(), authors(), website());
}

bool theme::try_parse(const xtd::ustring& text, theme& result) noexcept {
  return false;
}
