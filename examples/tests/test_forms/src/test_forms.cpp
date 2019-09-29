#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  form form;
  form.text("Test forms");
  form.show();
  application::run(form);
}
