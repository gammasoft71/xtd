#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t critical_section::create() {
  auto handle = new CRITICAL_SECTION;
  InitializeCriticalSection(handle);
  return reinterpret_cast<intmax_t>(handle);
}

void critical_section::destroy(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return;
  DeleteCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
  delete reinterpret_cast<CRITICAL_SECTION*>(handle);
}

void critical_section::enter(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return;
  EnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
}

bool critical_section::try_enter(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return false;
  TryEnterCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle)) == TRUE;
}

void critical_section::leave(intmax_t handle) {
  if (reinterpret_cast<CRITICAL_SECTION*>(handle) == nullptr) return;
  LeaveCriticalSection(reinterpret_cast<CRITICAL_SECTION*>(handle));
}
