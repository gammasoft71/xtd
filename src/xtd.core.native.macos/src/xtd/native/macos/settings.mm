#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/settings>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::literals;
using namespace xtd::native;

string settings::get_path(const string& company_name, const string& product_name) {
  return string {getenv("HOME")} + "/Library/Preferences/"s + company_name + "/"s + product_name + " Preferences"s;
}
