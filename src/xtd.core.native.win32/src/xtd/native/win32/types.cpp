#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::literals;
using namespace xtd::native;

string types::demangle(const string& name) {
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
