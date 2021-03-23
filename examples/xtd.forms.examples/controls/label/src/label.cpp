#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Label example");

      label1.parent(*this);
      label1.text("Label 1");
      label1.location({10, 10});
    }
    
  private:
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
