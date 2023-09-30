#include "../../../include/xtd/threading/interlocked.h"
#include "../../../include/xtd/as.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/interlocked>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <atomic>

using namespace xtd;
using namespace xtd::threading;

int32 interlocked::add(int32& location, int32 value) noexcept {
  return native::interlocked::add(location, value);
}

int64 interlocked::add(int64& location, int64 value) noexcept {
  return native::interlocked::add(location, value);
}

double interlocked::compare_exchange(double& location, double value, double comparand) noexcept {
  auto result = location;
  lock_(location) {
    if (location == comparand) location = value;
  }
  return result;
}

int32 interlocked::compare_exchange(int32& location, int32 value, int32 comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

int64 interlocked::compare_exchange(int64& location, int64 value, int64 comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

slong interlocked::compare_exchange(slong& location, slong value, slong comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

void* interlocked::compare_exchange(void*& location, void* value, void* comparand) noexcept {
  return native::interlocked::compare_exchange(location, value, comparand);
}

float interlocked::compare_exchange(float& location, float value, float comparand) noexcept {
  auto result = location;
  lock_(location) {
    if (location == comparand) location = value;
  }
  return result;
}

int32 interlocked::decrement(int32& location) noexcept {
  return native::interlocked::decrement(location);
}

int64 interlocked::decrement(int64& location) noexcept {
  return native::interlocked::decrement(location);
}

double interlocked::exchange(double& location, double value) noexcept {
  auto original = location;
  lock_(location) location = value;
  return original;
}

int32 interlocked::exchange(int32& location, int32 value) noexcept {
  return native::interlocked::exchange(location, value);
}

int64 interlocked::exchange(int64& location, int64 value) noexcept {
  return native::interlocked::exchange(location, value);
}

slong interlocked::exchange(slong& location, slong value) noexcept {
  return native::interlocked::exchange(location, value);
}

void* interlocked::exchange(void*& location, void* value) noexcept {
  return native::interlocked::exchange(location, value);
}

float interlocked::exchange(float& location, float value) noexcept {
  auto original = location;
  lock_(location) location = value;
  return original;
}

int32 interlocked::increment(int32& location) noexcept {
  return native::interlocked::increment(location);
}

int64 interlocked::increment(int64& location) noexcept {
  return native::interlocked::increment(location);
}

void interlocked::memory_barrier() noexcept {
  std::atomic_thread_fence(std::memory_order_acquire);
}

int64 interlocked::read(int64& location) noexcept {
  auto atomic = std::atomic<int64> {location};
  return std::atomic_load(&atomic);
}
