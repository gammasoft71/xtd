#include <xtd/forms/native/menu.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenu());
}


void menu::destroy(intptr_t menu) {
  if (!menu) return;
  delete reinterpret_cast<wxMenu*>(menu);
}
