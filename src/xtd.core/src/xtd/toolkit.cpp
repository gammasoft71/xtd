#include "../../include/xtd/toolkit.h"

using namespace std;
using namespace xtd;

xtd::toolkit::toolkit(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& description) : description_(description), name_(name), version_(version) {
}

const xtd::ustring& xtd::toolkit::description() const noexcept {
  return description_;
}

const xtd::ustring& xtd::toolkit::name() const noexcept {
  return name_;
}

const xtd::version& xtd::toolkit::version() const noexcept {
  return version_;
}

bool xtd::toolkit::equals(const xtd::toolkit& other) const noexcept {
  return name_ == other.name_ && version_ == other.version_;
}

xtd::ustring xtd::toolkit::to_string() const noexcept {
  return ustring::format("{} {}", name_, version_);
}
