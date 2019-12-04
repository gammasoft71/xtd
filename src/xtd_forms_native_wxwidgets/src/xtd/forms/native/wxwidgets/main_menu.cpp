#include <xtd/forms/native/main_menu.hpp>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t main_menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenuBar());
}


void main_menu::destroy(intptr_t main_menu) {
  if (!main_menu) return;
  delete reinterpret_cast<wxMenuBar*>(main_menu);
}
