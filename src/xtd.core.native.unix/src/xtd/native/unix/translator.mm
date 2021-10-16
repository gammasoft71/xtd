#if defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator.h>
#include <xtd/native/environment.h>
#include "../../../../include/xtd/native/unix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>

#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>
#endif

using namespace xtd::native;

std::string translator::get_system_language() {
  if (!environment::get_environment_variable("LANG").empty()) return unix::strings::to_lower(unix::strings::substring(environment::get_environment_variable("LANG"), 0, 2));
#if !defined(TARGET_IPHONE_SIMULATOR) && !defined(TARGET_OS_MACCATALYST) && !defined(TARGET_OS_IPHONE)
  CFLocaleRef cflocale = CFLocaleCopyCurrent();
  std::string language = [(NSString*)CFLocaleGetValue(cflocale, kCFLocaleLanguageCode) UTF8String];
  CFRelease(cflocale);
  return language;
#else
  /// @todo iOS : Find how to get language...
  return "";
#endif
}
#endif
