#include <xtd/xtd>

namespace environment_exit_code_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto args = environment::get_command_line_args();
      auto value = 0;
      if (args.length() == 1) environment::exit_code(ECANCELED);
      else if (!try_parse(args[1], value)) environment::exit_code(EINVAL);
      else if (value <= int32_object::min_value || value >= int32_object::max_value) environment::exit_code(ERANGE);
      else console::write_line("Result: {0}", value * 2);
    }
  };
}

startup_(environment_exit_code_example::program::main);

// This code produces the following output :
//
// >environment_exit_code
// >Program ended with exit code: 89
//
// >environment_exit_code xtd
// >Program ended with exit code: 22
//
// >environment_exit_code 2147483648
// >Program ended with exit code: 34
//
// >environment_exit_code 2142
// Result: 4284
// >Program ended with exit code: 0
