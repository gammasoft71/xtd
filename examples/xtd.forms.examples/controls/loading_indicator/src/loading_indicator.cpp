#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Loading indicator example");

      loading_indicator1.parent(*this);
      loading_indicator1.location({10, 10});
      loading_indicator1.fore_color(xtd::drawing::system_colors::accent());
      loading_indicator1.start();
    }
    
  private:
    loading_indicator loading_indicator1;
  };
}

int main() {
  application::run(examples::form1());
}
