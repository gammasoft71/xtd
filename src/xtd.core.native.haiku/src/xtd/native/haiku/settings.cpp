#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/settings>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::literals;
using namespace xtd::native;

std::string settings::get_file_extension() {
  return ".conf";
}
