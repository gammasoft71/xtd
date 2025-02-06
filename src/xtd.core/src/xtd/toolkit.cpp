#include "../../include/xtd/toolkit.hpp"

using namespace xtd;

toolkit::toolkit(const string& name, const xtd::version& version, const string& description) : description_(description), name_(name), version_(version) {
}

const string& toolkit::description() const noexcept {
  return description_;
}

const string& toolkit::name() const noexcept {
  return name_;
}

const xtd::version& toolkit::version() const noexcept {
  return version_;
}

bool toolkit::equals(const object& obj) const noexcept {
  return is<toolkit>(obj) && equals(static_cast<const toolkit&>(obj));
}

bool toolkit::equals(const toolkit& other) const noexcept {
  return name_ == other.name_ && version_ == other.version_;
}

size toolkit::get_hash_code() const noexcept {
  return hash_code::combine(description_, name_, version_);
}

xtd::string xtd::toolkit::to_string() const noexcept {
  return string::format("{} {}", name_, version_);
}
