#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace main_example {
  class program {
  public:
    static auto main(const vector<ustring>& args) {
      int number;
      if (args.size() != 1 || try_parse(args[0], number) == false || number < 0 || number > 20) {
        cout << "Please enter an integer argument betwween 0 and 20." << endl;
        cout << "Usage: factorial <integer>" << endl;
        return -1;
      }
      
      cout << ustring::format("The factorial of {0} is {1}", number, [&] {
        long long result = 1;
        for (int i = 1; i <= number; ++i)
          result *= i;
        return result;
      }()) << endl;
      return 0;
    }
  };
}

startup_(main_example::program);

// This code produces the following output if 3 is entered on command line:
//
// The factorial of 3 is 6.
