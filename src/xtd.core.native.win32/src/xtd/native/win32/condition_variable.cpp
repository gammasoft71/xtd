#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t condition_variable::create() {
  return reinterpret_cast<intmax_t>(nullptr);
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
