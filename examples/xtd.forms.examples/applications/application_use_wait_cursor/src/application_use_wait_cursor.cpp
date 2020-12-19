#include <thread>
#include <xtd/xtd>

using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Application use wait cursor example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [] {
      application::use_wait_cursor(true);
      for (auto count = 0; count < 500; ++count) {
        application::yield();
        sleep_for(milliseconds(10));
      }
      application::use_wait_cursor(false);
    };
  }
  
private:
  button button1;
};

int main() {
  xtd::forms::application::run(form1());
}
