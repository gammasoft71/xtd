#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intmax_t mutex::create(const std::string& name, bool& create_new) {
  auto handle = CreateMutex(nullptr, FALSE, win32::strings::to_wstring(name).c_str());
  create_new = handle != 0;
  if (!handle && GetLastError() == ERROR_ALREADY_EXISTS) handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intmax_t>(handle);
}

void mutex::destroy(intmax_t handle) {
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

bool mutex::signal(intmax_t handle, bool& io_error) {
  auto result = ReleaseMutex(reinterpret_cast<HANDLE>(handle)) == TRUE;
  io_error = !result;
  return result;
}

bool mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool& io_error) {
  auto result = WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout) == TRUE;
  io_error = !result;
  return result;
}
