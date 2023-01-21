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
      loading_indicator1.running(true);
    }
    
  private:
    loading_indicator loading_indicator1;
  };
}

auto main()->int {
  application::run(examples::form1 {});
}
