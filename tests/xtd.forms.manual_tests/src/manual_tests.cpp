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

  panel panel;
  panel.parent(form_main);
  panel.location({299 - (2 * system_information::border_3d_size().width()), 0});
  panel.size({1, 300});
  panel.back_color(color::spring_green);
  
  application::run(form_main);
}
