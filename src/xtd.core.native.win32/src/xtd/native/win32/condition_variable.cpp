#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/condition_variable.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t condition_variable::create() {
  PCONDITION_VARIABLE handle = new CONDITION_VARIABLE;
  if (handle == nullptr) return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
  InitializeConditionVariable(handle);
  return reinterpret_cast<intmax_t>(handle);
}

void condition_variable::destroy(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE)) return;
  delete reinterpret_cast<PCONDITION_VARIABLE>(handle);
}

void condition_variable::pulse(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE)) return;
  WakeConditionVariable(reinterpret_cast<PCONDITION_VARIABLE>(handle));
}

void condition_variable::pulse_all(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE)) return;
  WakeAllConditionVariable(reinterpret_cast<PCONDITION_VARIABLE>(handle));
}

bool condition_variable::wait(intmax_t handle, intmax_t critical_section_handle, int_least32_t milliseconds_timeout) {
  if (handle == reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE)) return false;
  if (critical_section_handle == reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE)) return false;
  return SleepConditionVariableCS(reinterpret_cast<PCONDITION_VARIABLE>(handle), reinterpret_cast<PCRITICAL_SECTION>(critical_section_handle), milliseconds_timeout) == TRUE;
}
