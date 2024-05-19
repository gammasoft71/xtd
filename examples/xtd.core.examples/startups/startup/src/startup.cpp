#include <xtd/console>
#include <xtd/startup>

using namespace std;
using namespace xtd;

namespace main_example {
  class program {
  public:
    static auto main(const vector<ustring>& args) {
      auto number = 0;
      if (args.size() != 1 || try_parse(args[0], number) == false || number < 0 || number > 20) {
        console::write_line("Please enter an integer argument betwween 0 and 20.");
        console::write_line("Usage: factorial <integer>");
        return -1;
      }
      
      console::write_line("The factorial of {} is {}", number, [&] {
        auto result = 1l;
        for (auto i = 1; i <= number; ++i)
          result *= i;
        return result;
      }());
      return 0;
    }
  };
}

auto main(int argc, char* argv[]) -> int {
  return startup::safe_run(main_example::program::main, argc, argv);
}

// This code produces the following output if 3 is entered on command line:
//
// The factorial of 3 is 6.
