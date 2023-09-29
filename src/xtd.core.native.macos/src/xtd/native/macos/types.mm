#include <cxxabi.h>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#include "../../../../include/xtd/native/macos/semaphore.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace abi;
using namespace std;
using namespace xtd::native;

string types::demangle(const string& name) {
  class auto_delete_char_pointer {
  public:
    explicit auto_delete_char_pointer(char* value) : value_(value) {}
    ~auto_delete_char_pointer() {free(value_);}
    char* operator()() const {return value_;}
  private:
    char* value_;
  };
  auto status = 0;
  auto result = __cxa_demangle(name.c_str(), 0, 0, &status);
  if (result == nullptr) return name;
  return auto_delete_char_pointer(result)();
}

intmax_t types::invalid_handle() noexcept {
  return reinterpret_cast<intmax_t>(SEM_FAILED);
}
