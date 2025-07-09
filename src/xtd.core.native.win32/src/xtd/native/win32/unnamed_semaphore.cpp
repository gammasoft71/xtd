#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_semaphore>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace xtd::native;

intmax_t unnamed_semaphore::create(int32_t initial_count, int32_t max_count) {
  auto handle = CreateSemaphore(nullptr, initial_count, max_count, nullptr);
  return reinterpret_cast<intmax_t>(handle);
}

void unnamed_semaphore::destroy(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return;
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

bool unnamed_semaphore::signal(intmax_t handle, int32_t release_count, int32_t& previous_count, bool& io_error) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) {
    io_error = true;
    return false;
  }
  previous_count = -1;
  io_error = ReleaseSemaphore(reinterpret_cast<HANDLE>(handle), static_cast<LONG>(release_count), reinterpret_cast<LPLONG>(&previous_count)) == FALSE;
  return !io_error;
}


uint32_t unnamed_semaphore::wait(intmax_t handle, int32_t milliseconds_timeout) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return WAIT_FAILED;
  return static_cast<uint32_t>(WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout == -1 ? INFINITE : milliseconds_timeout));
}
