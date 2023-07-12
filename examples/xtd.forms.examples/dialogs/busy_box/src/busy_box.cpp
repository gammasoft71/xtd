#include <xtd/forms/application>
#include <xtd/forms/busy_box>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <thread>

using namespace std::this_thread;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Busy box example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [] {
      busy_box::show("Please wait while do something...", "Application busy");
      for (auto count = 0; count < 500; ++count) {
        application::do_events();
        sleep_for(std::chrono::milliseconds(10));
      }
      busy_box::hide();
    };
  }
  
private:
  button button1;
};

auto main()->int {
  xtd::forms::application::run(form1 {});
}
