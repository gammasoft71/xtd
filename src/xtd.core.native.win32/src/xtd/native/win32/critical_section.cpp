#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t critical_section::create() {
  CRITICAL_SECTION* handle = new CRITICAL_SECTION;
  InitializeCriticalSection(handle);
  return reinterpret_cast<intmax_t>(handle);
}

void critical_section::destroy(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return;
  DeleteCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
  delete reinterpret_cast<CRITICAL_SECTION*>(handle);
}

bool critical_section::enter(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return false;
  EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
  return true,
}

bool critical_section::leave(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return false;
  LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
  return true;
}
