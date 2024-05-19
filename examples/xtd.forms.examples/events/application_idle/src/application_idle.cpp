#include <xtd/forms/application>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

namespace application_idle_example {
  class form1 : public form {
  public:
    form1() {
      application::idle += {*this, &form1::on_application_idle};
    }
    
  private:
    void on_application_idle(const event_args& e) {
      text(ustring::format("{}", ++counter));
    }
    
    int counter = 0;
  };
}

auto main() -> int {
  application::run(application_idle_example::form1 {});
}
