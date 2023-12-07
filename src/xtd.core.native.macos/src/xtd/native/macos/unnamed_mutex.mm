#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_mutex>
#include "../../../../include/xtd/native/macos/mutex.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <fcntl.h>
#include <sys/stat.h>

using namespace xtd::native;

intmax_t unnamed_mutex::create(bool initially_owned) {
  auto handle = new pthread_mutex_t;
  auto mutex_attribute = pthread_mutexattr_t {};
  if (pthread_mutexattr_init(&mutex_attribute) != 0 ||
      pthread_mutexattr_settype(&mutex_attribute, PTHREAD_MUTEX_RECURSIVE) != 0 ||
      pthread_mutex_init(handle, &mutex_attribute) != 0) {
    delete handle;
    return reinterpret_cast<intmax_t>(MUTEX_FAILED);
  }
  return reinterpret_cast<intmax_t>(handle);
}

void unnamed_mutex::destroy(intmax_t handle) {
  pthread_mutex_destroy(reinterpret_cast<pthread_mutex_t*>(handle));
  delete reinterpret_cast<pthread_mutex_t*>(handle);
}

bool unnamed_mutex::signal(intmax_t handle, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<pthread_mutex_t*>(handle) == MUTEX_FAILED) {
    io_error = true;
    return false;
  }
  if (pthread_mutex_lock(reinterpret_cast<pthread_mutex_t*>(handle)) != 0) io_error = true;
  return !io_error;
}

uint_least32_t unnamed_mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<pthread_mutex_t*>(handle) == MUTEX_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? pthread_mutex_unlock(reinterpret_cast<pthread_mutex_t*>(handle)) : pthread_mutex_milliseconds_timedlock(reinterpret_cast<pthread_mutex_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EDEADLK) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  return 0x00000000;
}
