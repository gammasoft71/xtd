#include <xtd/forms/native/main_menu.h>
#include <wx/app.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t main_menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenuBar());
}

void main_menu::destroy(intptr_t main_menu) {
  if (!main_menu) return;
  if (wxTheApp) reinterpret_cast<wxMenuBar*>(main_menu)->Destroy();
}
