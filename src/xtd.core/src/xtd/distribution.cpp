#include "../../include/xtd/distribution.h"

using namespace xtd;

distribution::distribution(const xtd::ustring& name) : name_(name) {
}

distribution::distribution(const xtd::ustring& name, const xtd::version& version) : name_(name), version_(version) {
}

distribution::distribution(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& code_name) : name_(name), version_(version), code_name_(code_name) {
}

distribution::distribution(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& code_name, const xtd::ustring& description) : name_(name), version_(version), code_name_(code_name), description_(description) {
}

xtd::ustring distribution::code_name() const noexcept {
  return code_name_;
}

xtd::ustring distribution::description() const noexcept {
  return description_;
}

xtd::ustring distribution::name() const noexcept {
  return name_;
}

const xtd::version& distribution::version() const noexcept {
  return version_;
}

xtd::ustring distribution::to_string() const noexcept {
  return description();
}
