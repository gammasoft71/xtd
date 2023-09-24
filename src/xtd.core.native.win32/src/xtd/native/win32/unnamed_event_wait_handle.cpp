#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_event_wait_handle>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t unnamed_event_wait_handle::create(bool initial_state, bool manual_reset) {
  auto handle = CreateEvent(nullptr, manual_reset, initial_state, nullptr);
  return reinterpret_cast<intmax_t>(handle);
}

void unnamed_event_wait_handle::destroy(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

bool unnamed_event_wait_handle::set(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = SetEvent(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

bool unnamed_event_wait_handle::reset(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = ResetEvent(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

uint_least32_t unnamed_event_wait_handle::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool manual_reset) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint_least32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
