#include "../../../include/xtd/threading/lock.hpp"

using namespace xtd;
using namespace xtd::threading;

lock::~lock() {
  monitor::exit_ptr(obj_);
}

void lock::pulse() {
  monitor::pulse_ptr(obj_);
}

void lock::pulse_all() {
  monitor::pulse_all_ptr(obj_);
}

bool lock::wait(int32 milliseconds_timeout) {
  return monitor::wait_ptr(obj_, milliseconds_timeout);
}

bool lock::wait(const time_span& timeout) {
  return monitor::wait_ptr(obj_, as<int32>(timeout.total_milliseconds()));
}

bool lock::wait() {
  return monitor::wait_ptr(obj_, timeout::infinite);
}
