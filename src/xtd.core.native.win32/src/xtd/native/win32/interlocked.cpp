#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/interlocked>
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

int32_t interlocked::add(int32_t& location, int32_t value) {
  InterlockedExchange((long*)&location, location + value);
  return location;
}

int64_t interlocked::add(int64_t& location, int64_t value) {
  InterlockedExchange64((long long*)&location, location + value);
  return location;
}

int32_t interlocked::compare_exchange(int32_t& location, int32_t value, int32_t comparand) {
  return InterlockedCompareExchange((long*)&location, value, comparand);
}

int64_t interlocked::compare_exchange(int64_t& location, int64_t value, int64_t comparand) {
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
}

__slong__ interlocked::compare_exchange(__slong__& location, __slong__ value, __slong__ comparand) {
  return InterlockedCompareExchange((__slong__*)&location, value, comparand);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* interlocked::compare_exchange(void*& location, void* value, void* comparand) {
  #if !defined(_WIN64)
  return reinterpret_cast<void*>(InterlockedCompareExchange(reinterpret_cast<long*>(&location), reinterpret_cast<long>(value), reinterpret_cast<long>(comparand)));
  #else
  return reinterpret_cast<void*>(InterlockedCompareExchange64(reinterpret_cast<long long*>(&location), reinterpret_cast<long long>(value), reinterpret_cast<long long>(comparand)));
  #endif
}
#pragma warning(pop)

int32_t interlocked::decrement(int32_t& location) {
  return InterlockedDecrement((long*)&location);
}

int64_t interlocked::decrement(int64_t& location) {
  return InterlockedDecrement64((long long*)&location);
}

int32_t interlocked::exchange(int32_t& location, int32_t value) {
  return InterlockedExchange((long*)&location, value);
}

int64_t interlocked::exchange(int64_t& location, int64_t value) {
  return InterlockedExchange64((long long*)&location, value);
}

__slong__ interlocked::exchange(__slong__& location, __slong__ value) {
  return InterlockedExchange((__slong__*)&location, value);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* interlocked::exchange(void*& location, void* value) {
  #if !defined(_WIN64)
  return reinterpret_cast<void*>(InterlockedExchange(reinterpret_cast<long*>(&location), reinterpret_cast<long>(value)));
  #else
  return reinterpret_cast<void*>(InterlockedExchange64(reinterpret_cast<long long*>(&location), reinterpret_cast<long long>(value)));
  #endif
}
#pragma warning(pop)

int32_t interlocked::increment(int32_t& location) {
  return InterlockedIncrement((long*)&location);
}

int64_t interlocked::increment(int64_t& location) {
  return InterlockedIncrement64((long long*)&location);
}
