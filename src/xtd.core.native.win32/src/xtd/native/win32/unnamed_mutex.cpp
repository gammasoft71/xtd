#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_mutex>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t unnamed_mutex::create(bool initially_owned) {
  auto handle = CreateMutex(nullptr, initially_owned, nullptr);
  return reinterpret_cast<intmax_t>(handle);
}

void unnamed_mutex::destroy(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

bool unnamed_mutex::signal(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = ReleaseMutex(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

uint_least32_t unnamed_mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint_least32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
