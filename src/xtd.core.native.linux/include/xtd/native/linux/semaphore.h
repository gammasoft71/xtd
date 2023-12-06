#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <ctime>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

inline static constexpr size_t PSEMNAMLEN = 31;

static inline int sem_milliseconds_timedwait(sem_t *sem, int_least32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  return sem_timedwait(sem, &timeout);
}
