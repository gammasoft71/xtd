#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#include <xtd/native/environment>
#include "../../../../include/xtd/native/macos/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>

#import <Cocoa/Cocoa.h>

using namespace xtd::native;

std::string translator::get_system_language() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return macos::strings::to_lower(macos::strings::substring(environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS), 0, 2));
  auto cflocale = CFLocaleCopyCurrent();
  auto language = std::string {[(NSString*)CFLocaleGetValue(cflocale, kCFLocaleLanguageCode) UTF8String]};
  CFRelease(cflocale);
  return language;
}
