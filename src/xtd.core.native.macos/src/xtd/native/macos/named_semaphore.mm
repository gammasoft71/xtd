// Hacking to remove deprecated warning.
#include <sys/cdefs.h>
#undef __deprecated
#define __deprecated
// end hacking
#include <semaphore.h>

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/named_semaphore.h>
#include "../../../../include/xtd/native/macos/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace xtd::native;

intmax_t named_semaphore::create(int_least32_t initial_count, int_least32_t max_count, const std::string& name) {
  sem_t* semaphore = sem_open(name.c_str(), O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, max_count);
  if (semaphore != SEM_FAILED && initial_count) {
    bool io_error = false;
    for (auto index = 0; !io_error && index < initial_count; ++index)
      wait(reinterpret_cast<intmax_t>(semaphore), -1, io_error);
  }
  return reinterpret_cast<intmax_t>(semaphore);
}

void named_semaphore::destroy(intmax_t handle, const std::string& name) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  if (sem_close(reinterpret_cast<sem_t*>(handle)) == 0) sem_unlink(name.c_str());
}

intmax_t named_semaphore::open(const std::string& name) {
  sem_t* semaphore = nullptr;
  semaphore = sem_open(name.c_str(), O_CREAT, S_IRUSR | S_IWUSR);
  return reinterpret_cast<intmax_t>(semaphore);
}

bool named_semaphore::signal(intmax_t handle, int_least32_t& previous_count, bool& io_error) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return !(io_error = true);
  sem_getvalue(reinterpret_cast<sem_t*>(handle), &previous_count);
  io_error = false;
  if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1&& errno == EINVAL) io_error = true;
  return !io_error;
}

bool named_semaphore::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool& io_error) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return !(io_error = true);
  io_error = false;
  if (milliseconds_timeout == -1) {
    if (sem_wait(reinterpret_cast<sem_t*>(handle)) == -1) {
      if (errno == EAGAIN) return true;;
      if (errno == EINVAL) io_error = true;
    }
    return !io_error;
  }
  
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec = milliseconds_timeout / 1000;
  timeout.tv_nsec = (milliseconds_timeout % 1000) * 1000000;
  if (sem_timedwait(reinterpret_cast<sem_t*>(handle), &timeout) == -1) {
    if (errno == EAGAIN) return true;
    if (errno != ETIMEDOUT) io_error = true;
  }
  return !io_error;
}
