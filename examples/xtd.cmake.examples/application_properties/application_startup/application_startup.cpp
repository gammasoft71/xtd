#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace application_startup {
  class program : public form {
  public:
    static void main() {
      application::run(program());
    }
    
    program() {
      text("Application startup");
    }
  };
}
