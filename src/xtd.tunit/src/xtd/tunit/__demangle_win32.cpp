#if defined(_WIN32)

#include "../../../include/xtd/tunit/__demangle.h"

using namespace std;
using namespace std::literals;

string __tunit_demangle(const string& name) {
  string result = name;
  for (auto& item : {"enum "s, "class "s, "union "s, "struct "s}) {
    size_t index = 0;
    while (true) {
      index = result.find(item, index);
      if (index == std::string::npos) break;
      result.replace(index, item.size(), "");
    }
  }
  return result;
}

#endif
