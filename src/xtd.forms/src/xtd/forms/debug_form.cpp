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

trace_listener& debug_form::trace_listener() noexcept {
  return *listener_;
}

void debug_form::flush() {
}
