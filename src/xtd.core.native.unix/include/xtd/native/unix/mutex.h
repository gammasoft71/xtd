#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <errno.h>
#include <pthread.h>
#include <unistd.h>

inline static const pthread_mutex_t* MUTEX_FAILED = reinterpret_cast<pthread_mutex_t *>(-1);

static inline int pthread_mutex_timedlock(pthread_mutex_t* mut, const struct timespec *abs_timeout) {
  while (pthread_mutex_trylock(mut) != 0) {
    if (errno == EBUSY) {
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

static inline int pthread_mutex_milliseconds_timedlock(pthread_mutex_t* mut, int_least32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  return pthread_mutex_timedlock(mut, &timeout);
}
