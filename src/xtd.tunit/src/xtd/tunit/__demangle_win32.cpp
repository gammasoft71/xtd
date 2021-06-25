#if defined(_WIN32)

#include "../../../include/xtd/tunit/__demangle.h"
#include <algorithm>
#include <functional>
#include <vector>

namespace {
  void erase_all_sub_str(std::string & main_str, const std::string & to_erase) {
    size_t pos = std::string::npos;
    while ((pos = main_str.find(to_erase)) != std::string::npos)
      main_str.erase(pos, to_erase.length());
  }
}

std::string __tunit_demangle(const std::string& name) {
  std::vector<std::string> types = {"enum ", "class ", "union ", "struct "};
  std::string result = name;
  std::for_each(types.begin(), types.end(), std::bind(erase_all_sub_str, std::ref(result), std::placeholders::_1));
  return result;
}

#endif
