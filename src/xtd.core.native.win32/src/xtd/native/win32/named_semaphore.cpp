#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t named_semaphore::create(int_least32_t initial_count, int_least32_t max_count, const std::string& name) {
  auto handle = CreateSemaphore(nullptr, initial_count, max_count, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intmax_t>(handle);
}

void named_semaphore::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

intmax_t named_semaphore::open(const std::string& name) {
  auto handle = OpenSemaphore(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intmax_t>(handle);
}

bool named_semaphore::signal(intmax_t handle, int_least32_t& previous_count, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return !(io_error = true);
  io_error = ReleaseSemaphore(reinterpret_cast<HANDLE>(handle), 1, reinterpret_cast<LPLONG>(&previous_count)) == FALSE;
  return !io_error;
}

bool named_semaphore::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return !(io_error = true);
  io_error = WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout) == FALSE;
  return !io_error;
}
