#include <xtd/xtd>

namespace static_object_example {
  class program : public static_object {
  public:
    static string to_string() {return "program";}
  };
}

auto main() -> int {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //auto program = static_object_example::program {};
  
  console::write_line(static_object_example::program::to_string());
}

// This code produces the following output :
//
// program
