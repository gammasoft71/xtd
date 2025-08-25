#include <xtd/xtd>

namespace other_namespace {
  class program : public form {
  public:
    static auto main() {
      application::run(program {});
    }
    
    program() {
      text("Application default namespace");
    }
  };
}

startup_(other_namespace::program::main);
