#if defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger.h>
#include <xtd/native/assert_dialog_results.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <cstdlib>
#include <syslog.h>
#import <CoreFoundation/CoreFoundation.h>
#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>
#endif
#import <Foundation/Foundation.h>

using namespace xtd::native;

void debugger::debug_break() {
  std::abort();
}

bool debugger::is_attached() {
  return false;
}

bool debugger::is_logging() {
  return true;
}

bool debugger::launch() {
  return true;
}

int32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
  NSModalResponse return_code = NSAlertSecondButtonReturn;
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  @autoreleasepool {
    NSAlert* alert = [[NSAlert alloc] init];
    [alert addButtonWithTitle:@"Abort"];
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Ignore"];
    [alert setAlertStyle:NSAlertStyleCritical];
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:text.c_str()]];
    return_code = [alert runModal];
  }
  [pool release];
  return return_code == NSAlertFirstButtonReturn ? ADR_ABORT : (return_code == NSAlertSecondButtonReturn ? ADR_RETRY : ADR_IGNORE);
#else
  /// @todo iOS : Show dialog box...
  return ADR_RETRY;
#endif
}

void debugger::log(int32_t level, const std::string& category, const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
}
#endif
