#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/unnamed_event_wait_handle>
#include "../../../../include/xtd/native/macos/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <mach/clock.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace xtd::native;

intmax_t unnamed_event_wait_handle::create(bool initial_state, bool manual_reset) {
  auto semaphore = semaphore_t {};
  if (semaphore_create(current_task(), &semaphore, SYNC_POLICY_FIFO, initial_state ? 1 : 0) != err_none)
    return reinterpret_cast<intmax_t>(SEM_FAILED);
  return static_cast<intmax_t>(semaphore);
}

void unnamed_event_wait_handle::destroy(intmax_t handle) {
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) return;
  semaphore_destroy(current_task(), static_cast<semaphore_t>(handle));
}

bool unnamed_event_wait_handle::set(intmax_t handle, bool& io_error) {
  io_error = false;
  if (reinterpret_cast<sem_t*>(handle) == SEM_FAILED) {
    io_error = true;
    return false;
  }
  if (semaphore_signal(static_cast<semaphore_t>(handle)) != err_none) io_error = true;
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
