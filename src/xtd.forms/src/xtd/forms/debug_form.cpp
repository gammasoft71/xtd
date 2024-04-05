#include "../../../include/xtd/forms/debug_form.h"

using namespace std;
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

unique_ptr<xtd::object> debug_form::clone() const {
  auto result = make_unique<debug_form>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}
