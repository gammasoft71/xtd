#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form1;
  form1.text("Manual tests");
  form1.client_size({300, 300});

  tab_control tab_control1;
  tab_control1.parent(form1);
  tab_control1.dock(dock_style::fill);

  tab_page page1;
  page1.text("Page 1");
  page1.auto_scroll(true);
  page1.parent(tab_control1);
  
  button button;
  button.parent(page1);
  button.text("Click me");
  button.location({350, 350});
   
  application::run(form1);
}
