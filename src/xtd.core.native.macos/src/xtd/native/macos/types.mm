#include <cxxabi.h>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#include "../../../../include/xtd/native/macos/semaphore.h"
#include "../../../../include/xtd/native/macos/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace abi;
using namespace std;
using namespace xtd::native;

string types::demangle(const string& name) {
  auto result = name;
  auto status = 0;
  auto demangled_name = __cxa_demangle(name.c_str(), nullptr, 0, &status);
  if (status == 0 && demangled_name) result = demangled_name;
  result = xtd::native::macos::strings::replace(result, "std::__1::", "std::");
  free(demangled_name);
  return result;
}

intmax_t types::invalid_handle() noexcept {
  return reinterpret_cast<intmax_t>(SEM_FAILED);
}
