#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

bool thread::cancel(intptr_t handle) {
  /// @todo Make mplementation for Windows
  return false;
}
