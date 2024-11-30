#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/translator>
#include <xtd/native/environment>
#include "../../../../include/xtd/native/macos/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#import <CoreFoundation/CoreFoundation.h>
#include <TargetConditionals.h>

#import <Cocoa/Cocoa.h>

using namespace xtd::native;

std::string translator::get_system_locale() {
  if (!environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS).empty()) return environment::get_environment_variable("LANG", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  auto cflocale = CFLocaleCopyCurrent();
  auto locale = macos::strings::to_lower(std::string {[(NSString*)CFLocaleGetValue(cflocale, kCFLocaleLanguageCode) UTF8String]}) + "_" + macos::strings::to_upper(std::string {[(NSString*)CFLocaleGetValue(cflocale, kCFLocaleCountryCode) UTF8String]});
  CFRelease(cflocale);
  return locale;
}
