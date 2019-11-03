#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;
  form1.text("Manual tests");
  form1.client_size({300, 300});

  panel panel1;
  panel1.auto_scroll(true);
  panel1.parent(form1);
  panel1.dock(dock_style::fill);

  label label1;
  label1.border_style(forms::border_style::fixed_single);
  label1.parent(panel1);
  label1.text("text");
  label1.back_color(drawing::color::spring_green);
  label1.location({350, 350});
  
  cdebug << format("display_rectangle = {}", panel1.display_rectangle()) << std::endl;
  
  application::run(form1);
}
