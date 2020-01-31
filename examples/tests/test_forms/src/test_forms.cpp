#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  //form form;
  //form.text("Test Gui");
  
  //application::run(form);
  
  form form1;
  form1.text("Test Gui");
  auto form2 = form1;

  application::run(form2);
}
