#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_mutex.h>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

intptr_t named_mutex::create(bool initially_owned, const std::string& name, bool& create_new) {
  auto handle = CreateMutex(nullptr, initially_owned, win32::strings::to_wstring(name).c_str());
  create_new = handle != INVALID_HANDLE_VALUE;
  if (!handle && GetLastError() == ERROR_ALREADY_EXISTS) handle = OpenMutex(MUTEX_ALL_ACCESS, FALSE, win32::strings::to_wstring(name).c_str());
  return reinterpret_cast<intptr_t>(handle);
}

void named_mutex::destroy(intptr_t handle, const std::string& name) {
  CloseHandle(reinterpret_cast<HANDLE>(handle));
}

bool named_mutex::signal(intptr_t handle, bool& io_error) {
  auto result = ReleaseMutex(reinterpret_cast<HANDLE>(handle)) == TRUE;
  io_error = !result;
  return result;
}

bool named_mutex::wait(intptr_t handle, int32_t milliseconds_timeout, bool& io_error) {
  auto result = WaitForSingleObject(reinterpret_cast<HANDLE>(handle), milliseconds_timeout) == TRUE;
  io_error = !result;
  return result;
}
