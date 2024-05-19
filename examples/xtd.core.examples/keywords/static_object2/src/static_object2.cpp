#include <xtd/console>
#include <xtd/static>

using namespace xtd;

namespace static_object2_example {
  class program final : public static_object {
  public:
    static ustring to_string() {return "program";}
  };
}

auto main() -> int {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //auto program = static_object2_example::program {};
  
  console::write_line(static_object2_example::program::to_string());
}

// This code produces the following output:
//
// program
