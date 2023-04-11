#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace static_object2_example {
  class program final : public static_object {
  public:
    static ustring to_string() {return "program";}
  };
}

auto main()->int {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //static_object2_example::program program;
  
  cout << static_object2_example::program::to_string() << endl;
}

// This code produces the following output:
//
// program
