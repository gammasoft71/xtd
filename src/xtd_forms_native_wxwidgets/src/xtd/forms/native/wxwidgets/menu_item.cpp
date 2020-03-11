#include <xtd/forms/native/menu_item.h>
#include <wx/menuitem.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t menu_item::create() {
  return reinterpret_cast<intptr_t>(new wxMenuItem());
}


void menu_item::destroy(intptr_t menu_item) {
  if (!menu_item) return;
  delete reinterpret_cast<wxMenuItem*>(menu_item);
}
