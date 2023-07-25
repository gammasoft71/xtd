#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>
#import <Cocoa/Cocoa.h>

using namespace xtd::native;

bool thread::cancel(intptr_t handle) {
  /// @todo Make mplementation for macOS
  return false;
}
