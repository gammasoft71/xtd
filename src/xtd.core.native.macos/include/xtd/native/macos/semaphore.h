#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <semaphore.h>
#include <unistd.h>

static inline int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout) {
  while (sem_trywait(sem) == -1) {
    if (errno != EAGAIN) return -1;
    usleep(1000); // 1 millisecond because xtd timeout is never under 1 millisecond.
    struct timespec current_time;
    clock_gettime(CLOCK_REALTIME, &current_time);
    if (current_time.tv_sec > abs_timeout->tv_sec || (current_time.tv_sec == abs_timeout->tv_sec && current_time.tv_nsec >= abs_timeout->tv_nsec)) return ETIMEDOUT;
  }
  return 0;
}
