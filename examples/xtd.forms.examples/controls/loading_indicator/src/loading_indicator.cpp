#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Loading indicator example");

      loading_indicator.parent(*this);
      loading_indicator.location({10, 10});
      loading_indicator.fore_color(xtd::drawing::system_colors::accent());
      loading_indicator.start();
    }
    
  private:
    loading_indicator loading_indicator;
  };
}

int main() {
  application::run(examples::form1());
}
