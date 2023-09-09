#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section.h>
#include "../../../../include/xtd/native/unix/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

intmax_t critical_section::create() {
  auto mutex = new pthread_mutex_t {};
  if (pthread_mutex_init(mutex, nullptr) != 0) {
    delete mutex;
    return reinterpret_cast<intmax_t>(MUTEX_FAILED);
  }
  return reinterpret_cast<intmax_t>(mutex);
}

void critical_section::destroy(intmax_t handle) {
  pthread_mutex_destroy(reinterpret_cast<pthread_mutex_t*>(handle));
}

bool critical_section::enter(intmax_t handle) {
  if (reinterpret_cast<pthread_mutex_t*>(handle) == MUTEX_FAILED) return false;
  return pthread_mutex_unlock(reinterpret_cast<pthread_mutex_t*>(handle)) == 0;
}

bool critical_section::leave(intmax_t handle) {
  if (reinterpret_cast<pthread_mutex_t*>(handle) == MUTEX_FAILED) return false;
  if (pthread_mutex_lock(reinterpret_cast<pthread_mutex_t*>(handle)) != 0) return false;
  return true;
}
