#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/interlocked.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../../include/xtd/threading/interlocked.h"
#include "../../../include/xtd/as.h"

using namespace xtd;
using namespace xtd::threading;

std::mutex interlocked::guard;

int32_t interlocked::add(int32_t& location, int32_t value) noexcept {
  return native::interlocked::add(location, value);
}

int64_t interlocked::add(int64_t& location, int64_t value) noexcept {
  return native::interlocked::add(location, value);
}

double interlocked::compare_exchange(double& location, double value, double comparand) noexcept {
  double result = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return result;
}

int32_t interlocked::compare_exchange(int32_t& location, int32_t value, int32_t comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

int64_t interlocked::compare_exchange(int64_t& location, int64_t value, int64_t comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

intptr_t interlocked::compare_exchange(intptr_t& location, intptr_t value, intptr_t comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

float interlocked::compare_exchange(float& location, float value, float comparand) noexcept {
  float result = location;
  std::lock_guard<std::mutex> lock(guard);
  if (location == comparand)
    location = value;
  return result;
}

int32_t interlocked::decrement(int32_t& location) noexcept {
  return native::interlocked::decrement(location);
}

int64_t interlocked::decrement(int64_t& location) noexcept {
  return native::interlocked::decrement(location);
}

double interlocked::exchange(double& location, double value) noexcept {
  double original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32_t interlocked::exchange(int32_t& location, int32_t value) noexcept {
  return native::interlocked::exchange(location, value);
}

int64_t interlocked::exchange(int64_t& location, int64_t value) noexcept {
  return native::interlocked::exchange(location, value);
}

intptr_t interlocked::exchange(intptr_t& location, intptr_t value) noexcept {
  return native::interlocked::exchange(location, value);
}

float interlocked::exchange(float& location, float value) noexcept {
  float original = location;
  std::lock_guard<std::mutex> lock(guard);
  location = value;
  return original;
}

int32_t interlocked::increment(int32_t& location) noexcept {
  return native::interlocked::increment(location);
}

int64_t interlocked::increment(int64_t& location) noexcept {
  return native::interlocked::increment(location);
}

void interlocked::memory_barrier() noexcept {
  std::atomic_thread_fence(std::memory_order_acquire);
}

int64_t interlocked::read(int64_t& location) noexcept {
  std::atomic<int64_t> atomic(location);
  return std::atomic_load(&atomic);
}
