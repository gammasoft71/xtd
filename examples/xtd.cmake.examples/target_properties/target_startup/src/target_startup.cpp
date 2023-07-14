#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/startup>

using namespace xtd::forms;

namespace target_startup {
  class program : public form {
  public:
    static auto main() {
      application::run(program {});
    }
    
    program() {
      text("Target startup");
    }
  };
}
