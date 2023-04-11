#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace static_example {
  class program static_ {
  public:
    static ustring to_string() {return "program";}
  };
}

auto main()->int {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //static_example::program program;
  
  cout << static_example::program::to_string() << endl;
}

// This code produces the following output:
//
// program
