#include "../../../include/xtd/threading/lock_guard.h"

using namespace xtd;
using namespace xtd::threading;

lock_guard::~lock_guard() {
  monitor::exit_ptr(lock_);
}

void lock_guard::pulse() {
  monitor::pulse_ptr(lock_);
}

void lock_guard::pulse_all() {
  monitor::pulse_all_ptr(lock_);
}
