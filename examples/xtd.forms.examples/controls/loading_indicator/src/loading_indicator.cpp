#include <xtd/drawing/system_colors>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/loading_indicator>

using namespace xtd::forms;

namespace loading_indicator_example {
  class form1 : public form {
  public:
    form1() {
      text("Loading indicator example");
      
      loading_indicator1.parent(*this);
      loading_indicator1.location({10, 10});
      loading_indicator1.fore_color(xtd::drawing::system_colors::accent());
      loading_indicator1.running(true);
      
      click += loading_indicator1.click += [&] {
        loading_indicator1.running(!loading_indicator1.running());
      };
    }
    
  private:
    loading_indicator loading_indicator1;
  };
}

auto main()->int {
  application::run(loading_indicator_example::form1 {});
}
