#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace static_object_example {
  class program static_object_ {
  public:
    static ustring to_string() {return "program";}
  };
}

auto main()->int {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //static_object_example::program program;
  
  cout << static_object_example::program::to_string() << endl;
}

// This code produces the following output:
//
// program
