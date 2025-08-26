#include <xtd/xtd>

namespace environment_exit_code_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto args = environment::get_command_line_args();
      if (args.size() == 1)
        environment::exit_code(ECANCELED);
      else {
        auto value = 0;
        if (try_parse(args[1], value))
          if (value <= int32_object::min_value || value >= int32_object::max_value)
            environment::exit_code(ERANGE);
          else
            console::write_line("Result: {0}", value * 2);
        else
          environment::exit_code(EINVAL);
      }
    }
  };
}

startup_(environment_exit_code_example::program::main);

// This code produces the following output :
//
