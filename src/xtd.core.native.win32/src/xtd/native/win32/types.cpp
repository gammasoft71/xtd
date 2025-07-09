#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std::literals;
using namespace xtd::native;

std::string types::demangle(const std::string& name) {
  auto result = name;
  for (auto& item : {"enum "s, "class "s, "union "s, "struct "s}) {
    auto index = size_t {};
    while (true) {
      index = result.find(item, index);
      if (index == std::string::npos) break;
      result.replace(index, item.size(), "");
    }
  }
  return result;
}

intmax_t types::invalid_handle() noexcept {
  return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
}
