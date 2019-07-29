#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

// The main entry point for the application.
int main() {
  form form;
  cdebug << format("color = {}", form.back_color()) << endl;
  label label;
  label.auto_size(true);
  label.text("Hello");
  label.parent(form);
  label.location({10, 10});
  
  button button;
  button.parent(form);
  button.location({10, 200});
  button.text("auto...");
  button.click += [&](const control& sender, const event_args& e) {
    label.auto_size(!label.auto_size());
    label.size({100, 23});
  };
  
  forms::button button2;
  button2.parent(form);
  button2.location({150, 200});
  button2.text("text...");
  button2.click += [&](const control& sender, const event_args& e) {
    label.text(label.text() == "Hello" ? "This is a very long long text" : "Hello");
  };

  application::run(form);
}
