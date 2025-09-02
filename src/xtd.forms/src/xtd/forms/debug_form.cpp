#include "../../../include/xtd/forms/debug_form.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace xtd::helpers;

debug_form::~debug_form() {
  debug::listeners().remove(listener_);
}

const trace_listener& debug_form::trace_listener() const noexcept {
  return *listener_;
}

trace_listener& debug_form::trace_listener() {
  return *listener_;
}

void debug_form::flush() {
}

xtd::uptr<xtd::object> debug_form::clone() const {
  auto result = xtd::new_uptr<debug_form>(*this);
  if (typeof_(*result) != typeof_(*this)) throw_helper::throws(exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}
