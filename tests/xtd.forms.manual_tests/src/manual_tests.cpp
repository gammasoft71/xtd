#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  form form;
  form.text("Manual tests");
  form.client_size({300, 300});

  panel panel;
  panel.parent(form);
  panel.dock(dock_style::fill);
  panel.auto_scroll(true);
  
  button button;
  button.parent(panel);
  button.text("Click me");
  button.location({350, 350});
  
  application::run(form);
}
