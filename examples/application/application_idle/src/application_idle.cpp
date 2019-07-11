#include <xtd/strings>
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      application::idle += {*this, &form1::on_application_idle};
    }
    
  private:
    void on_application_idle(const event_args& e) {
      this->text(strings::format("{}", ++this->counter));
    }
    
    int counter = 0;
  };
}

// The main entry point for the application.
int main() {
  application::run(examples::form1());
}
