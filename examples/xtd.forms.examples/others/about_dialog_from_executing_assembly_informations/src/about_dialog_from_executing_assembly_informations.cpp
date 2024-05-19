#include <xtd/forms/about_dialog>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include "../resources/gammasoft_64x64.xpm"

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("About dialog from executng assembly information example");
    controls().push_back(button1);
    
    button1.location({10, 10});
    button1.text("About...");
    button1.click += [&] {
      static auto dialog = about_dialog::from_executing_assembly_informations();
      dialog.icon(xtd::drawing::bitmap {gammasoft_64x64_xpm});
      dialog.show(*this);
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  application::run(form1 {});
}
