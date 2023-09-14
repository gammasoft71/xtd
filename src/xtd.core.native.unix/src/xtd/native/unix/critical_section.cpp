#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/critical_section.h>
#include "../../../../include/xtd/native/unix/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <pthread.h>

using namespace xtd::native;

intmax_t critical_section::create() {
  auto handle = new pthread_mutex_t;
  pthread_mutexattr_t mutex_attribute;
  if (pthread_mutexattr_init(&mutex_attribute) != 0 ||
      pthread_mutexattr_settype(&mutex_attribute, PTHREAD_MUTEX_RECURSIVE) != 0 ||
      pthread_mutex_init(handle, &mutex_attribute) != 0) {
    delete handle;
    return reinterpret_cast<intmax_t>(MUTEX_FAILED);
  }
  return reinterpret_cast<intmax_t>(handle);
}

void critical_section::destroy(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_mutex_destroy(reinterpret_cast<pthread_mutex_t*>(handle));
  delete reinterpret_cast<pthread_mutex_t*>(handle);
}

void critical_section::enter(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_mutex_lock(reinterpret_cast<pthread_mutex_t*>(handle));
}

bool critical_section::try_enter(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return false;
  return pthread_mutex_trylock(reinterpret_cast<pthread_mutex_t*>(handle)) == 0;
}

void critical_section::leave(intmax_t handle) {
  if (handle == reinterpret_cast<intmax_t>(MUTEX_FAILED)) return;
  pthread_mutex_unlock(reinterpret_cast<pthread_mutex_t*>(handle));
}
