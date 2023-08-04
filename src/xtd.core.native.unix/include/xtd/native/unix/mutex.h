#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <ctime>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>

inline static const pthread_mutex_t* MUTEX_FAILED = reinterpret_cast<pthread_mutex_t *>(-1);

static inline int pthread_mutex_milliseconds_timedlock(pthread_mutex_t* mut, int_least32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  return pthread_mutex_timedlock(mut, &timeout);
}
