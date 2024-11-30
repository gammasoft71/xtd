#include "../../include/xtd/toolkit.hpp"

using namespace xtd;

xtd::toolkit::toolkit(const xtd::string& name, const xtd::version& version, const xtd::string& description) : description_(description), name_(name), version_(version) {
}

const xtd::string& xtd::toolkit::description() const noexcept {
  return description_;
}

const xtd::string& xtd::toolkit::name() const noexcept {
  return name_;
}

const xtd::version& xtd::toolkit::version() const noexcept {
  return version_;
}

bool xtd::toolkit::equals(const xtd::toolkit& other) const noexcept {
  return name_ == other.name_ && version_ == other.version_;
}

xtd::string xtd::toolkit::to_string() const noexcept {
  return string::format("{} {}", name_, version_);
}
