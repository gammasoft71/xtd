#if defined(__linux__) || defined(__APPLE__)

#include <cxxabi.h>
#include "../include/xtd/__demangle.h"

std::string __tunit_demangle(const std::string& name) {
  class auto_delete_char_pointer {
  public:
    auto_delete_char_pointer(char* value) : value(value) {}
    ~auto_delete_char_pointer() {free(value);}
    char* operator()() const {return this->value;}
  private:
    char* value;
  };
  int status = 0;
  return auto_delete_char_pointer(abi::__cxa_demangle(name.c_str(), 0, 0, &status))();
}

#endif
