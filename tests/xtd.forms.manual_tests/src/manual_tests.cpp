#include <xtd/forms/application>
#include <xtd/forms/form>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Forms manual test");
  }
};

auto main()->int {
  xtd::forms::application::run(form1 {});
}
