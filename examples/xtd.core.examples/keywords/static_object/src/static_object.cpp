#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program static_object_ {
  public:
    static string to_string() {return "program";}
  };
}

int main() {
  // uncomment next line cause build error with call implicitly-deleted default constructor.
  //examples::program program;

  cout << examples::program::to_string() << endl;
}

// This code produces the following output:
//
// program
