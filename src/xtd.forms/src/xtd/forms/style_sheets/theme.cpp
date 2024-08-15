#include "../../../../include/xtd/forms/style_sheets/theme.h"
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::forms::style_sheets;

theme::theme(const string& name) : name_(name) {
}

theme::theme(const string& name, const string& description) : name_(name), description_(description) {
}

theme::theme(const string& name, const string& description, const string& authors) : name_(name), description_(description), authors_(authors) {
}

theme::theme(const string& name, const string& description, const string& authors, const uri& website) : name_(name), description_(description), authors_(authors), website_(website) {
}

const string& theme::authors() const noexcept {
  return authors_;
}

void theme::authors(const string& value) noexcept {
  authors_ = value;
}

const string& theme::description() const noexcept {
  return description_;
}

void theme::description(const string& value) noexcept {
  description_ = value;
}

const string& theme::name() const noexcept {
  return name_;
}

void theme::name(const string& value) noexcept {
  name_ = value;
}

const uri& theme::website() const noexcept {
  return website_;
}

void theme::website(const uri& value) noexcept {
  website_ = value;
}

bool theme::from_css(const xtd::string& css_text, theme& result) {
  return try_parse(css_text, result);
}

theme theme::parse(const xtd::string& text) {
  auto result = theme {};
  if (!try_parse(text, result))
    throw argument_exception {csf_};
  return result;
}

xtd::string theme::to_string() const noexcept {
  return string::format("[name={}, description={}, authors={}, website={}, ]", name(), description(), authors(), website());
}

xtd::string theme::to_css() const noexcept {
  return string::format("  name: \"{}\";\n  description: \"{}\";\n  authors:\"{}\";\n  website=url(\"{}\");\n", name(), description(), authors(), website());
}

bool theme::try_parse(const xtd::string& text, theme& result) noexcept {
  return false;
}
