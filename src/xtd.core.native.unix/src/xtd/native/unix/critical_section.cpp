#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section.h>
#include "../../../../include/xtd/native/unix/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mutex>

using namespace xtd::native;

intmax_t critical_section::create() {
  auto handle = new std::recursive_mutex {};
  if (!handle) return reinterpret_cast<intmax_t>(MUTEX_FAILED);
  return reinterpret_cast<intmax_t>(handle);
}

void critical_section::destroy(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  delete reinterpret_cast<std::recursive_mutex*>(handle);
}

void critical_section::enter(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  reinterpret_cast<std::recursive_mutex*>(handle)->lock();
}

bool critical_section::try_enter(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return false;
  return reinterpret_cast<std::recursive_mutex*>(handle)->try_lock();
}

void critical_section::leave(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  reinterpret_cast<std::recursive_mutex*>(handle)->unlock();
}
