#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <CoreFoundation/CoreFoundation.h>
#include <string>
#include <regex>

using namespace xtd::native;

std::string culture_info::current_name() {
  auto name = std::string("C");
  CFLocaleRef locale = CFLocaleCopyCurrent();
  if (!locale) return name;
  char buffer[256];
  if (CFStringGetCString((CFStringRef)CFLocaleGetIdentifier(locale), buffer, sizeof(buffer), kCFStringEncodingUTF8))
    name = std::regex_replace(std::string {buffer}, std::regex("@rg=[a-zA-Z]{2}zzzz"), "") + ".utf-8";
  CFRelease(locale);
  return name;
}
