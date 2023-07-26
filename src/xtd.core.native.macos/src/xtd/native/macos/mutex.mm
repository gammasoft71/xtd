#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/mutex.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>

using namespace xtd::native;

intmax_t mutex::create(const std::string& name, bool& create_new) {
  return 0;
}

void mutex::destroy(intmax_t handle) {
  
}

bool mutex::signal(intmax_t handle) {
  return false;
}

bool mutex::wait(intmax_t handle, int_least32_t milliseconds_timeout) {
  return false;
}
