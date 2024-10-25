#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cxxabi.h>

using namespace abi;
using namespace std;
using namespace xtd::native;

string __xtd_abi_demangle(const string& name) {
  auto status = 0;
  auto demangled_name = __cxa_demangle(name.c_str(), nullptr, 0, &status);
  auto result = status == 0 && demangled_name ? demangled_name : name;
  free(demangled_name);
  return result;
}

string types::demangle(const string& name) {
  return __xtd_abi_demangle(name);
}

intmax_t types::invalid_handle() noexcept {
  return 0;
}
