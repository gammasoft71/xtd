#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

bool thread::cancel(intmax_t handle) {
  /// @todo Make mplementation for unix
  return false;
}
