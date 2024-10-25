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
  auto status = 0;
  auto demangled_name = __cxa_demangle(name.c_str(), nullptr, 0, &status);
  auto result = xtd::native::macos::strings::replace(status == 0 && demangled_name ? demangled_name : name, "std::__1::", "std::");
  free(demangled_name);
  return result;
}

intmax_t types::invalid_handle() noexcept {
  return reinterpret_cast<intmax_t>(SEM_FAILED);
}
