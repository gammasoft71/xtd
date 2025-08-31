#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <errno.h>
#include <unistd.h>
// Hacking to remove deprecated warning.
#undef __deprecated
#define __deprecated
// end hacking
#include <semaphore.h>

inline static constexpr size_t PSEMNAMLEN = 31;

inline bool has_timed_out(const struct timespec& now, const struct timespec& timeout) {
  return now.tv_sec > timeout.tv_sec || (now.tv_sec == timeout.tv_sec && now.tv_nsec >= timeout.tv_nsec);
}

static inline int sem_timedwait(sem_t* sem, const struct timespec* abs_timeout) {
  int delay_us = 1000; // 1 ms initial
  while (sem_trywait(sem) == -1) {
    if (errno == EAGAIN) {
      struct timespec now;
      clock_gettime(CLOCK_REALTIME, &now);
      if (has_timed_out(now, *abs_timeout)) {
        errno = ETIMEDOUT;
        return -1;
      }
      usleep(delay_us);
      delay_us = std::min(delay_us * 2, 20000); // exponential backoff up to 20ms max
    } else {
      return -1; // EINTR, EINVAL, etc.
    }
  }
  return 0;
}

static inline int sem_milliseconds_timedwait(sem_t *sem, std::int32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  
  timeout.tv_sec += timeout.tv_nsec / 1000000000;
  timeout.tv_nsec %= 1000000000;
  
  return sem_timedwait(sem, &timeout);
}
