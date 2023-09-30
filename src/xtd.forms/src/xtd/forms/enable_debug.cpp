#include "../../../include/xtd/forms/enable_debug.h"

using namespace xtd::diagnostics;
using namespace xtd::forms;

const enable_debug enable_debug::none {0};
const enable_debug enable_debug::creation {0b1};
const enable_debug enable_debug::events {0b10};
const enable_debug enable_debug::key_events {0b100};
const enable_debug enable_debug::mouse_events {0b1000};
const enable_debug enable_debug::layout {0b10000};
const enable_debug enable_debug::workaround {0b100000};
const enable_debug enable_debug::all {0b1111111111111111111111111111111111111111111111111111111111111111};

enable_debug enable_debug::operator |(const enable_debug& value) const noexcept {
  return enable_debug(value_ | value.value_);
}

enable_debug enable_debug::operator +(const enable_debug& value) const  noexcept {
  return enable_debug(value_ + value.value_);
}

xtd::diagnostics::trace_switch& enable_debug::trace_switch() noexcept {
  return trace_switch_;
}

bool enable_debug::equals(const enable_debug& value) const noexcept {
  return value_ == value.value_;
}

bool enable_debug::get(const enable_debug& flags) {
  return (values_.value_ & flags.value_) == flags.value_;
}

void enable_debug::set(const enable_debug& flags, bool on) {
  values_.value_ = on ? (values_.value_ | flags.value_) : (values_.value_ & ~flags.value_);
}

enable_debug::enable_debug(uint64 value) : value_(value) {
}

trace_switch enable_debug::trace_switch_ {"trace_switch_xtd_forms", "The trace switch for xtd forms library"};
enable_debug enable_debug::values_;
