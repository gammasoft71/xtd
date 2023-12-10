#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_semaphore>
#include "../../../../include/xtd/native/linux/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd::native;

intmax_t unnamed_semaphore::create(int_least32_t initial_count, int_least32_t max_count) {
  auto semaphore = new sem_t;
  if (sem_init(semaphore, 0, std::min(initial_count, max_count)) == -1) return reinterpret_cast<intmax_t>(SEM_FAILED);
  return reinterpret_cast<intmax_t>(semaphore);
}

void unnamed_semaphore::destroy(intmax_t handle) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  sem_destroy(reinterpret_cast<sem_t*>(handle));
  delete reinterpret_cast<sem_t*>(handle);
}

bool unnamed_semaphore::signal(intmax_t handle, int_least32_t release_count, int_least32_t& previous_count, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  previous_count = -1;
  sem_getvalue(reinterpret_cast<sem_t*>(handle), &previous_count);
  for (auto count = 0; !io_error && count < release_count; ++count)
    if (sem_post(reinterpret_cast<sem_t*>(handle)) == -1 && errno == EINVAL) io_error = true;
  return !io_error;
}

uint_least32_t unnamed_semaphore::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? sem_wait(reinterpret_cast<sem_t*>(handle)) : sem_milliseconds_timedwait(reinterpret_cast<sem_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  return 0x00000000;
}
