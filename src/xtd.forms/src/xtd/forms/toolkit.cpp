#include "../../../include/xtd/forms/toolkit.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;

xtd::forms::toolkit::toolkit(const xtd::ustring& name, const xtd::version& version) : name_(name), version_(version) {
}

const xtd::ustring& xtd::forms::toolkit::name() const noexcept {
  return name_;
}

xtd::forms::toolkit& xtd::forms::toolkit::name(const xtd::ustring& value) {
  name_ = value;
  return *this;
}

xtd::forms::toolkit xtd::forms::toolkit::toolkit_version() {
  return toolkit {drawing::native::toolkit::name(), drawing::native::toolkit::version()};
}

const xtd::version& xtd::forms::toolkit::version() const noexcept {
  return version_;
}

xtd::forms::toolkit& xtd::forms::toolkit::version(const xtd::version& value) {
  version_ = value;
  return *this;
}

bool xtd::forms::toolkit::equals(const xtd::forms::toolkit& other) const noexcept {
  return name_ == other.name_ && version_ == other.version_;
}

xtd::ustring xtd::forms::toolkit::to_string() const noexcept {
  return ustring::format("{} {}", name_, version_);
}
