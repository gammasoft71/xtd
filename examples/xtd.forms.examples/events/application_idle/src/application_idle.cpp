#include <xtd/xtd>

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
      text(ustring::format("{}", ++counter));
    }
    
    int counter = 0;
  };
}

int main() {
  application::run(examples::form1());
}
