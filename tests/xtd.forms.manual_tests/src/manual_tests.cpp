#include <xtd/forms/application>
#include <xtd/forms/busy_box>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/threading/thread>

using namespace xtd::forms;
using namespace xtd::threading;

class form1 : public form {
public:
  form1() {
    text("Busy box example with thread");
        
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [this] {
      button1.enabled(false);
      busy_box::show("Please wait while do something...", "Application busy");
      thread1 = thread {[this] {
        // Call your control (business) class here.
        // the following line simulates a time-consuming process
        thread::sleep(5000);
        
        invoke([this] {
          busy_box::hide();
          button1.enabled(true);
        });
      }};
      thread1.start();
    };
    
    form_closing += [this](object& sender, form_closing_event_args& e) {
      e.cancel(thread1.is_alive());
    };
  }
  
private:
  button button1;
  thread thread1;
};

auto main()->int {
  xtd::forms::application::run(form1 {});
}
