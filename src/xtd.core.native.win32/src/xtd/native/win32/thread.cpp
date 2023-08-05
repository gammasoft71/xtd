#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return TerminateThread(reinterpret_cast<HANDLE>(handle), -1) != FALSE;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(GetCurrentThread());
}
