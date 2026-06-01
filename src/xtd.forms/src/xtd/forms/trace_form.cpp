#include "../../../include/xtd/forms/trace_form.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace xtd::helpers;

trace_form::~trace_form() {
  trace::listeners().remove(listener_);
}

const trace_listener& trace_form::trace_listener() const noexcept {
  return *listener_;
}

trace_listener& trace_form::trace_listener() {
  return *listener_;
}

void trace_form::flush() {
}
