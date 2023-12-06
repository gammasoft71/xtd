#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/interlocked>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <chrono>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;
using namespace xtd::native;

int_least32_t interlocked::add(int_least32_t& location, int_least32_t value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int_least64_t interlocked::add(int_least64_t& location, int_least64_t value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int_least32_t interlocked::compare_exchange(int_least32_t& location, int_least32_t value, int_least32_t comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int_least64_t interlocked::compare_exchange(int_least64_t& location, int_least64_t value, int_least64_t comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

__slong__ interlocked::compare_exchange(__slong__& location, __slong__ value, __slong__ comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

void* interlocked::compare_exchange(void*& location, void* value, void* comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int_least32_t interlocked::decrement(int_least32_t& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int_least64_t interlocked::decrement(int_least64_t& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int_least32_t interlocked::exchange(int_least32_t& location, int_least32_t value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int_least64_t interlocked::exchange(int_least64_t& location, int_least64_t value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

__slong__ interlocked::exchange(__slong__& location, __slong__ value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

void* interlocked::exchange(void*& location, void* value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int_least32_t interlocked::increment(int_least32_t& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}

int_least64_t interlocked::increment(int_least64_t& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}
