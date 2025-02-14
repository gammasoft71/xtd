#include "../../../include/xtd/forms/debug_form.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

debug_form::~debug_form() {
  debug::listeners().erase(std::find(debug::listeners().begin(), debug::listeners().end(), listener_));
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
  if (typeof_(*result) != typeof_(*this)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}
