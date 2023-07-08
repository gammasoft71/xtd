#if defined(__linux__) || defined(__APPLE__)

#include <cxxabi.h>
#define __XTD_TUNIT_INTERNAL__
#include "../../../include/xtd/tunit/__demangle.h"
#undef __XTD_TUNIT_INTERNAL__
#include <xtd/types.h>

using namespace xtd;

std::string __tunit_demangle(const std::string& name) {
  class auto_delete_char_pointer {
  public:
    explicit auto_delete_char_pointer(char* value) : value_(value) {}
    ~auto_delete_char_pointer() {free(value_);}
    char* operator()() const {return value_;}
  private:
    char* value_;
  };
  int32 status = 0;
  auto result = abi::__cxa_demangle(name.c_str(), 0, 0, &status);
  if (result == nullptr) return name;
  return auto_delete_char_pointer(result)();
}

#endif
