#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_event_wait_handle>
#include "../../../../include/xtd/native/unix/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <sys/stat.h>
#include <errno.h>

using namespace xtd::native;

intmax_t unnamed_event_wait_handle::create(bool initial_state, bool manual_reset) {
  auto semaphore = new sem_t;
  if (sem_init(semaphore, 0, initial_state ? 1 : 0) != 0) return reinterpret_cast<intmax_t>(SEM_FAILED);
  return reinterpret_cast<intmax_t>(semaphore);
}

void unnamed_event_wait_handle::destroy(intmax_t handle) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  sem_destroy(reinterpret_cast<sem_t*>(handle));
  delete reinterpret_cast<sem_t*>(handle);
}

bool unnamed_event_wait_handle::set(intmax_t handle, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  auto previous_count = -1;
  sem_getvalue(reinterpret_cast<sem_t*>(handle), &previous_count);
  if (previous_count == 1) return true;
  if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1 && errno == EINVAL) io_error = true;
  return !io_error;
}

bool unnamed_event_wait_handle::reset(intmax_t handle, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  // Decrement the semaphore until it's locked (value reaches 0)
  while (sem_trywait(reinterpret_cast<sem_t*>(handle)) == 0);
  return true;
}

uint_least32_t unnamed_event_wait_handle::wait(intmax_t handle, int_least32_t milliseconds_timeout, bool manual_reset) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? sem_wait(reinterpret_cast<sem_t*>(handle)) : sem_milliseconds_timedwait(reinterpret_cast<sem_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EDEADLK) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  if (manual_reset) {
    auto io_error = false;
    set(handle, io_error);
  }
  return 0x00000000;
}
