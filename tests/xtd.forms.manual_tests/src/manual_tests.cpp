#include <xtd/xtd.forms>
#include <xtd/forms/native/wxwidgets/wx_list_box.hpp>
#include "address_book_new_32x32.xpm"
#include "appointment_new_32x32.xpm"
#include "gammasoft_32x32.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  form form_main;
  form_main.text("Manual tests");

  list_box lb;
  lb.parent(form_main);
  lb.dock(dock_style::fill);

  cdebug << format("before create handle = 0x{:X}", lb.handle()) << std::endl;
  form_main.show();
  cdebug << format("after create handle = 0x{:X}", lb.handle()) << std::endl;

  lb.sorted(true);
  lb.items().push_back("A");
  lb.selected_index(0);
  //lb.items().insert_at(0, "Z");
  //lb.items().insert_at(0, "B");
  lb.items().push_back_range({"G", "F", "D"});
  
  cdebug << format("handle = 0x{:X}", lb.handle()) << std::endl;
  for (size_t index = 0; index < static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(lb.handle())->control())->GetCount(); index++)
    cdebug << format("  {} - {}", index, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(lb.handle())->control())->GetString(index)) << std::endl;

  lb.items().erase_at(0);
  lb.selected_index(0);

  cdebug << format("handle = 0x{:X}", lb.handle()) << std::endl;
  for (size_t index = 0; index < static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(lb.handle())->control())->GetCount(); index++)
    cdebug << format("  {} - {}", index, static_cast<wxListBox*>(reinterpret_cast<xtd::forms::native::control_handler*>(lb.handle())->control())->GetString(index)) << std::endl;

  for (auto& item : lb.items())
    cdebug << item << std::endl;
  
  application::run(form_main);
}
