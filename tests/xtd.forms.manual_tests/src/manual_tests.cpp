#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;
  form1.text("Manual tests");
  form1.client_size({300, 300});

  panel panel1;
  panel1.auto_scroll(true);
  //panel1.auto_scroll_margin({10, 10});
  panel1.parent(form1);
  panel1.dock(dock_style::fill);

  panel panel2;
  panel2.parent(panel1);
  panel2.back_color(drawing::color::spring_green);
  panel2.location({350, 350});
  
  cdebug << format("display_rectangle = {}", panel1.display_rectangle()) << std::endl;
  
  application::run(form1);
}
