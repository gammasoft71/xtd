#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t named_mutex::create(bool initially_owned, const std::string& name) {
  auto handle = CreateMutex(nullptr, initially_owned, win32::strings::to_wstring(name).c_str());
  if (handle != INVALID_HANDLE_VALUE && GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(handle);
    return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
  }
  return reinterpret_cast<intmax_t>(handle);
}

void named_mutex::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

size_t named_mutex::max_name_size() {
  return MAX_PATH;
}

intmax_t named_mutex::open(const std::string& name) {
  auto handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  if (handle == nullptr) handle = INVALID_HANDLE_VALUE;
  return reinterpret_cast<intmax_t>(handle);
}

bool named_mutex::signal(intmax_t handle, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  io_error = ReleaseMutex(reinterpret_cast<HANDLE>(handle)) == FALSE;
  return !io_error;
}

uint_least32_t named_mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint_least32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
