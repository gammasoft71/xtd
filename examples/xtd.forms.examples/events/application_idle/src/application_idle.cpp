#include <xtd/xtd>

namespace application_idle_example {
  class form1 : public form {
  public:
    form1() {
      application::idle += {self_, &form1::on_application_idle};
    }
    
  private:
    void on_application_idle(object sender, const event_args& e) {
      text(string::format("{}", ++counter));
    }
    
    int counter = 0;
  };
}

auto main() -> int {
  application::run(application_idle_example::form1 {});
}
