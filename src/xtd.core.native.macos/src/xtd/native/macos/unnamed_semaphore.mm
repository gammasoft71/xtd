#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_semaphore>
#include "../../../../include/xtd/native/macos/semaphore.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <mach/clock.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace xtd::native;

intmax_t unnamed_semaphore::create(int32_t initial_count, std::int32_t maximum_count) {
  auto semaphore = semaphore_t {};
  if (semaphore_create(current_task(), &semaphore, SYNC_POLICY_FIFO, std::min(initial_count, maximum_count)) != err_none)
    return reinterpret_cast<intmax_t>(SEM_FAILED);
  return static_cast<intmax_t>(semaphore);
}

void unnamed_semaphore::destroy(intmax_t handle) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  semaphore_destroy(current_task(), static_cast<semaphore_t>(handle));
}

bool unnamed_semaphore::signal(intmax_t handle, std::int32_t release_count, std::int32_t& previous_count, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  previous_count = -1;
  
  for (auto count = 0; !io_error && count < release_count; ++count)
    if (semaphore_signal(static_cast<semaphore_t>(handle)) != err_none) io_error = true;
  return !io_error;
}

uint32_t unnamed_semaphore::wait(intmax_t handle, std::int32_t milliseconds_timeout) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return 0xFFFFFFFF;
  auto result = milliseconds_timeout == -1 ? sem_wait(reinterpret_cast<sem_t*>(handle)) : sem_milliseconds_timedwait(reinterpret_cast<sem_t*>(handle), milliseconds_timeout);
  if (result && errno == EAGAIN) return 0xFFFFFFFF;
  if (result && errno == EDEADLK) return 0xFFFFFFFF;
  if (result && errno == EINTR) return 0x00000080;
  if (result && errno == EINVAL) return 0xFFFFFFFF;
  if (result && errno == ETIMEDOUT) return 0x00000102;
  return 0x00000000;
}
