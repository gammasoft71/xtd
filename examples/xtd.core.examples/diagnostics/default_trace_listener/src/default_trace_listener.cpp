#include <xtd/xtd>

class binomial {
public:
  // args(0) is the number of possibilities for binomial coefficients.
  // args(1) is the file specification for the trace log file.
  static auto main(const argument_collection& args) {
    auto possibilities = .0l;
    auto iter = .0l;
    
    // Remove the original default trace listener.
    diagnostics::trace::listeners().erase(diagnostics::trace::listeners().begin());
    
    // Create and add a new default trace listener.
    auto default_listener = new_ptr<diagnostics::default_trace_listener>();
    diagnostics::trace::listeners().add(default_listener);
    
    // Assign the log file specification from the command line, if entered.
    if (args.length() >= 2)
      default_listener->log_file_name(args[1]);
       
    // Validate the number of possibilities argument.
    if (args.length() >= 1) {
      // Verify that the argument is a number within the correct range.
      try {
        const auto MAX_POSSIBILITIES = 99.0l;
        possibilities = parse<decimal>(args[0]);
        if (possibilities < 0 || possibilities > MAX_POSSIBILITIES)
          throw new system_exception(string::format("The number of possibilities must be in the range 0..{}.", MAX_POSSIBILITIES));
      } catch (const system_exception& ex) {
        auto fail_message = string::format("\"{}\" is not a valid number of possibilities.", args[0]);
        default_listener->fail(fail_message, ex.message());
        if (!default_listener->assert_ui_enabled())
          console::write_line(fail_message + "\n" + ex.message());
        return;
      }
    } else {
      // Report that the required argument is not present.
      const auto ENTER_PARAM = "Enter the number of possibilities as a command line argument.";
      default_listener->fail(ENTER_PARAM);
      if (!default_listener->assert_ui_enabled())
        console::write_line(ENTER_PARAM);
      return;
    }
    
    for (iter = 0; iter <= possibilities; iter++) {
      auto result = .0l;
      auto binomial = string::empty_string;
      
      // Compute the next binomial coefficient and handle all exceptions.
      try {
        result = calc_binomial(possibilities, iter);
      } catch (const system_exception& ex) {
        auto fail_message = string::format("An exception was raised when calculating Binomial( {}, {} ).", possibilities, iter);
        default_listener->fail(fail_message, ex.message());
        if (!default_listener->assert_ui_enabled())
          console::write_line(fail_message + "\n" + ex.message());
        return;
      }
      
      // Format the trace and console output.
      binomial = string::format("Binomial( {0}, {1} ) = ", possibilities, iter);
      default_listener->write(binomial);
      default_listener->write_line(string::format("{}", result));
      console::write_line("{0} {1}", binomial, result);
    }
  }
  
  static decimal calc_binomial(decimal possibilities, decimal outcomes) {
    // Calculate a binomial coefficient, and minimize the chance of overflow.
    auto result = 1.0l;
    auto iter = .0l;
    for (iter = 1.0l; iter <= possibilities - outcomes; iter++) {
      result *= outcomes + iter;
      result /= iter;
    }
    return result;
  }
};

startup_(binomial::main);

// This code produces the following output :
//
// Binomial( 20, 0 ) = 1
// Binomial( 20, 1 ) = 20
// Binomial( 20, 2 ) = 190
// Binomial( 20, 3 ) = 1140
// Binomial( 20, 4 ) = 4845
// Binomial( 20, 5 ) = 15504
// Binomial( 20, 6 ) = 38760
// Binomial( 20, 7 ) = 77520
// Binomial( 20, 8 ) = 125970
// Binomial( 20, 9 ) = 167960
// Binomial( 20, 10 ) = 184756
// Binomial( 20, 11 ) = 167960
// Binomial( 20, 12 ) = 125970
// Binomial( 20, 13 ) = 77520
// Binomial( 20, 14 ) = 38760
// Binomial( 20, 15 ) = 15504
// Binomial( 20, 16 ) = 4845
// Binomial( 20, 17 ) = 1140
// Binomial( 20, 18 ) = 190
// Binomial( 20, 19 ) = 20
// Binomial( 20, 20 ) = 1
