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
  form_main.auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  form_main.auto_size(true);

  checked_list_box lb;
  lb.parent(form_main);
  lb.auto_size(true);
  lb.items().push_back_range({"1", "2", "3"});

  application::run(form_main);
}
