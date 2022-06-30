#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Status bar without panels example");
      client_size({820, 500});
      
      status_bar1.parent(*this);
      status_bar1.text("Shows status information without panels...");
    }
    
  private:
    forms::status_bar status_bar1;
  };
}

int main() {
  application::run(examples::form1());
}
