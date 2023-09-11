#include "../../../include/xtd/threading/lock_guard.h"

using namespace xtd;
using namespace xtd::threading;

lock_guard::~lock_guard() {
  monitor::exit_ptr(obj_);
}

void lock_guard::pulse() {
  monitor::pulse_ptr(obj_);
}

void lock_guard::pulse_all() {
  monitor::pulse_all_ptr(obj_);
}

bool lock_guard::wait(int32 milliseconds_timeout) {
  return monitor::wait_ptr(obj_, milliseconds_timeout);
}

bool lock_guard::wait(const time_span& timeout) {
  return monitor::wait_ptr(obj_, as<int32>(timeout.total_milliseconds()));
}

bool lock_guard::wait() {
  return monitor::wait_ptr(obj_, timeout::infinite);
}
