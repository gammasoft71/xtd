#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore>
#include "../../../../include/xtd/native/win32/strings"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t named_semaphore::create(int_least32_t initial_count, int_least32_t max_count, const std::string& name) {
  auto handle = CreateSemaphore(nullptr, initial_count, max_count, win32::strings::to_wstring(name).c_str());
  if (handle != INVALID_HANDLE_VALUE && GetLastError() == ERROR_ALREADY_EXISTS) {
    CloseHandle(handle);
    return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
  }
  return reinterpret_cast<intmax_t>(handle);
}

void named_semaphore::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

size_t named_semaphore::max_name_size() {
  return MAX_PATH;
}

intmax_t named_semaphore::open(const std::string& name) {
  auto handle = OpenSemaphore(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  if (handle == nullptr) handle = INVALID_HANDLE_VALUE;
  return reinterpret_cast<intmax_t>(handle);
}

bool named_semaphore::signal(intmax_t handle, int_least32_t release_count, int_least32_t& previous_count, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  previous_count = -1;
  io_error = ReleaseSemaphore(reinterpret_cast<HANDLE>(handle), static_cast<LONG>(release_count), reinterpret_cast<LPLONG>(&previous_count)) == FALSE;
  return !io_error;
}


uint_least32_t named_semaphore::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint_least32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
