#include "../../../include/xtd/forms/trace_form.h"

using namespace std;
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

unique_ptr<xtd::object> trace_form::clone() const {
  auto result = make_unique<trace_form>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}
