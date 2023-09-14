#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#include "../../../../include/xtd/native/macos/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <pthread.h>

using namespace xtd::native;

intmax_t condition_variable::create() {
  return reinterpret_cast<intmax_t>(MUTEX_FAILED);
}

void condition_variable::destroy(intmax_t handle) {
}

void condition_variable::pulse(intmax_t handle) {
}

void condition_variable::pulse_all(intmax_t handle) {
}

bool condition_variable::wait(intmax_t handle, intmax_t critical_section_handle, int_least32_t milliseconds_timeout) {
  return false;
}
