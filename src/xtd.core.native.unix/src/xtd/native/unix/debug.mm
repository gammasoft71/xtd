#if defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#include <xtd/native/assert_dialog_results.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cassert>
#include <iostream>
#include <syslog.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

using namespace xtd::native;

int32_t debug::show_assert_dialog(const std::string& text, const std::string& caption) {
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
}

void debug::write_to_output(const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
}
#endif
