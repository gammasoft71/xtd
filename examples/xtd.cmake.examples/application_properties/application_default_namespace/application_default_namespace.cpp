#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace other_namespace {
  class program : public form {
  public:
    static void main() {
      application::run(program());
    }
    
    program() {
      text("Application default namespace");
    }
  };
}

startup_(other_namespace::program);
