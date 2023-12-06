#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <errno.h>
#include <unistd.h>
#include <semaphore.h>

inline static constexpr size_t PSEMNAMLEN = 31;

static inline int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout) {
  while (sem_trywait(sem) == -1) {
    if (errno == EAGAIN) {
      struct timespec current_time;
      clock_gettime(CLOCK_REALTIME, &current_time);
      if (current_time.tv_sec > abs_timeout->tv_sec || (current_time.tv_sec == abs_timeout->tv_sec && current_time.tv_nsec >= abs_timeout->tv_nsec)) {
        errno = ETIMEDOUT;
        return -1;
      }
      usleep(20000);
    } else return -1;
  }
  return 0;
}

static inline int sem_milliseconds_timedwait(sem_t *sem, int_least32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  return sem_timedwait(sem, &timeout);
}
