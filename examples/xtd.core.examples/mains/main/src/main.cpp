#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    static int main(const vector<ustring>& args) {
      int number;
      if (args.size() != 1 || try_parse(args[0], number) == false || number < 0 || number > 20) {
        cout << "Please enter an integer argument betwween 0 and 20." << endl;
        cout << "Usage: factorial <integer>" << endl;
        return -1;
      }

      cout << ustring::format("The factorial of {0} is {1}", number, [&] {
        int64_t result = 1;
        for (int i = 1; i <= number; ++i)
          result *= i;
        return result;
      }()) << endl;
      return 0;
    }
  };
}

startup_(examples::program);

// This code produces the following output if 3 is entered on command line:
//
// The factorial of 3 is 6.
