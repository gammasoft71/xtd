#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>
#include <pthread.h>

using namespace xtd::native;

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<pthread_t>(handle)) return false;
  return pthread_cancel(reinterpret_cast<pthread_t>(handle)) == 0;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(pthread_self());
}
