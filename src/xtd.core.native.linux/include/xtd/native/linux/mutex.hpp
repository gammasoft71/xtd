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
#include <errno.h>

// Define a constant for failed mutex
inline static const pthread_mutex_t* MUTEX_FAILED = reinterpret_cast<pthread_mutex_t*>(-1);

// Check for SerenityOS or if pthread_mutex_timedlock is unavailable
#if defined(__serenity__) || !defined(_POSIX_TIMEOUTS) || (_POSIX_TIMEOUTS < 0)
// Fallback implementation for platforms lacking pthread_mutex_timedlock
static inline int pthread_mutex_milliseconds_timedlock(pthread_mutex_t* mut, int32_t milliseconds_timeout) {
  if (!mut) return EINVAL;
  
  // If timeout is 0 or negative, try a non-blocking lock
  if (milliseconds_timeout <= 0)
    return pthread_mutex_trylock(mut);
    
  // Otherwise, use a polling loop with trylock
  struct timespec start, current;
  clock_gettime(CLOCK_REALTIME, &start);
  long long end_ns = start.tv_sec * 1000000000LL + start.tv_nsec + (long long)milliseconds_timeout * 1000000;
  
  while (true) {
    int ret = pthread_mutex_trylock(mut);
    if (ret != EBUSY) {
      return ret; // Success or error other than busy
    }
    
    clock_gettime(CLOCK_REALTIME, &current);
    long long current_ns = current.tv_sec * 1000000000LL + current.tv_nsec;
    if (current_ns >= end_ns) {
      return ETIMEDOUT; // Timeout reached
    }
    
    // Sleep briefly to avoid busy-waiting
    usleep(1000); // Sleep for 1ms
  }
}
#else
// Standard implementation using pthread_mutex_timedlock
static inline int pthread_mutex_milliseconds_timedlock(pthread_mutex_t* mut, int32_t milliseconds_timeout) {
  struct timespec timeout;
  clock_gettime(CLOCK_REALTIME, &timeout);
  timeout.tv_sec += milliseconds_timeout / 1000;
  timeout.tv_nsec += (milliseconds_timeout % 1000) * 1000000;
  // Normalize nanoseconds
  if (timeout.tv_nsec >= 1000000000) {
    timeout.tv_sec += 1;
    timeout.tv_nsec -= 1000000000;
  }
  return pthread_mutex_timedlock(mut, &timeout);
}
#endif
