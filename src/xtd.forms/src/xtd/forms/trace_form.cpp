#include "../../../include/xtd/forms/trace_form.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

trace_form::~trace_form() {
  trace::listeners().erase(find(trace::listeners().begin(), trace::listeners().end(), listener_));
}

const trace_listener& trace_form::trace_listener() const noexcept {
  return *listener_;
}

trace_listener& trace_form::trace_listener() {
  return *listener_;
}

void trace_form::flush() {
}

xtd::uptr<xtd::object> trace_form::clone() const {
  auto result = xtd::new_uptr<trace_form>(*this);
  if (typeof_(*result) != typeof_(*this)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).c_str());
  return result;
}
