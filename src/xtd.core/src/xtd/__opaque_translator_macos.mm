#if defined(__APPLE__)
#include "../../include/xtd/environment.h"
#import <CoreFoundation/CoreFoundation.h>
#import <Cocoa/Cocoa.h>

using namespace std;
using namespace xtd;

string __translator_get_system_language__() {
  if (!environment::get_environment_variable("LANG").empty()) return strings::to_lower(strings::substring(environment::get_environment_variable("LANG"), 0, 2));
  CFLocaleRef cflocale = CFLocaleCopyCurrent();
  std::string language = [(NSString*)CFLocaleGetValue(cflocale, kCFLocaleLanguageCode) UTF8String];
  CFRelease(cflocale);
  return language;
}

#endif
