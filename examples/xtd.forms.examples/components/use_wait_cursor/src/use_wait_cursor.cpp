#include <thread>
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Use wait cursor example");
    
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Do something...");
    button1.click += [] {
      use_wait_cursor wait;
      for (auto count = 0; count < 500; ++count) {
        application::yield();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
    };
  }
  
private:
  button button1;
};

int main() {
  xtd::forms::application::run(form1());
}
