#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_event_wait_handle>
#include "../../../../include/xtd/native/win32/strings"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t named_event_wait_handle::create(bool initial_state, bool manual_reset, const std::string& name) {
  auto handle = CreateEvent(nullptr, manual_reset, initial_state, win32::strings::to_wstring(name).c_str());
  if (handle != INVALID_HANDLE_VALUE && GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(handle);
    return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
  }
  return reinterpret_cast<intmax_t>(handle);
}

void named_event_wait_handle::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

size_t named_event_wait_handle::max_name_size() {
  return MAX_PATH;
}

intmax_t named_event_wait_handle::open(const std::string& name) {
  auto handle = OpenEvent(EVENT_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  if (handle == nullptr) handle = INVALID_HANDLE_VALUE;
  return reinterpret_cast<intmax_t>(handle);
}

bool named_event_wait_handle::set(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = SetEvent(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

bool named_event_wait_handle::reset(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = ResetEvent(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

uint_least32_t named_event_wait_handle::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool manual_reset) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint_least32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
