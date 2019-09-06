#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  form form;
  form.text("Test forms");
  
  check_box().checked(true).parent(form).location({30, 30}).back_color(xtd::drawing::color::red).text("This is a long text for validate auto size.");
  check_box().parent(form).location({30, 70}).back_color(xtd::drawing::color::red).auto_size(true).text("This is a long text for validate auto size.");
  application::run(form);
}
