#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/culture_info>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdlib>
#include <string>

using namespace xtd::native;

std::string culture_info::current_name() {
  const char* locale_env = std::getenv("LC_ALL");
  if (!locale_env || !*locale_env) locale_env = std::getenv("LANG");
  if (locale_env && *locale_env) return locale_env;
  return "C";
}
