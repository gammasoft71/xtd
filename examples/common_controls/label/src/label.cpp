#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Label example");

      this->label1.parent(*this);
      this->label1.text("Label 1");
      this->label1.location({10, 10});
    }
    
  private:
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
