#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger.h>
#include <xtd/native/assert_dialog_results.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <libproc.h>
#include <syslog.h>
#import <CoreFoundation/CoreFoundation.h>
//#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>
//#endif
#import <Foundation/Foundation.h>

using namespace xtd::native;

void debugger::debug_break() {
  std::abort();
}

bool debugger::is_attached() {
  auto ppid = getppid();
  auto parent_info = proc_bsdinfo {};
  if (proc_pidinfo(ppid, PROC_PIDTBSDINFO, 0, &parent_info, sizeof(parent_info)) != -1)
    return std::string {parent_info.pbi_name}.find("debugserver") !=std::string::npos;
  return false;
}

bool debugger::is_logging() {
  return true;
}

bool debugger::launch() {
  return true;
}

int_least32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
  //#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
  [NSApplication sharedApplication];
  [NSApp finishLaunching];
  [NSApp activateIgnoringOtherApps:YES];
  NSModalResponse return_code = NSAlertSecondButtonReturn;
  NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
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
  //#else
  /// @todo iOS : Show dialog box...
  //return ADR_RETRY;
  //#endif
}

void debugger::log(int_least32_t level, const std::string& category, const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
}
