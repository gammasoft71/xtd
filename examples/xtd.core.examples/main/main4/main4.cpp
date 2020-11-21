#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
        static int main(const vector<string>& args) {
      // Write arguments to the console output
      for (string arg : args)
        cout << arg << endl;

      return 42;
    }
  };
}

startup_(examples::program);
// startup_(examples::program); is same as :
//
// int main(int argc, char* argv[]) {
//   return examples::program::main({argv + 1, argv + argc});
// }


// This code produces the following output if one two "three four" five are entered on command line:
//
// one
// two
// three four
// five
