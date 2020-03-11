#include <xtd/forms/native/context_menu.h>
#include <wx/menu.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t context_menu::create() {
  return reinterpret_cast<intptr_t>(new wxMenu());
}

void context_menu::destroy(intptr_t context_menu) {
  if (!context_menu) return;
  delete reinterpret_cast<wxMenu*>(context_menu);
}
