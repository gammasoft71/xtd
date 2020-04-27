#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

int main() {
  button button_run;
  button_run.text("Run");
  button_run.location({10, 10});
  button_run.click += [&] {
    
  };

  form form_main;
  form_main.text("Manual tests");
  form_main.controls().push_back(button_run);
  
  application::run(form_main);
}
