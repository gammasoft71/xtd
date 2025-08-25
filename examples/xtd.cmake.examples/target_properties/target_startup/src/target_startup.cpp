#include <xtd/xtd>

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
