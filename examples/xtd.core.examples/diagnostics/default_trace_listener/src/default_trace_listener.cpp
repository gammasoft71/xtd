#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class binomial {
public:
  // args(0) is the number of possibilities for binomial coefficients.
  // args(1) is the file specification for the trace log file.
  static void main(const vector<ustring>& args) {
    decimal possibilities;
    decimal iter;
    
    // Remove the original default trace listener.
    trace::listeners().erase(trace::listeners().begin());
    
    // Create and add a new default trace listener.
    shared_ptr<default_trace_listener> default_listener = make_shared<default_trace_listener>();
    trace::listeners().push_back(default_listener);
    
    // Assign the log file specification from the command line, if entered.
    if (args.size() >= 2)
      default_listener->log_file_name(args[1]);
    
    // Validate the number of possibilities argument.
    if (args.size() >= 1) {
      // Verify that the argument is a number within the correct range.
      try {
        const decimal MAX_POSSIBILITIES = 99;
        possibilities = parse<decimal>(args[0]);
        if (possibilities < 0 || possibilities > MAX_POSSIBILITIES)
          throw new system_exception(ustring::format("The number of possibilities must be in the range 0..{}.", MAX_POSSIBILITIES));
      } catch (const system_exception& ex) {
        string fail_message = ustring::format("\"{}\" is not a valid number of possibilities.", args[0]);
        default_listener->fail(fail_message, ex.message());
        if (!default_listener->assert_ui_enabled())
          console::write_line(fail_message + "\n" + ex.message());
        return;
      }
    } else {
      // Report that the required argument is not present.
      const string ENTER_PARAM = "Enter the number of possibilities as a command line argument.";
      default_listener->fail(ENTER_PARAM);
      if (!default_listener->assert_ui_enabled())
        console::write_line(ENTER_PARAM);
      return;
    }
    
    for (iter = 0; iter <= possibilities; iter++) {
      decimal result;
      string binomial;
      
      // Compute the next binomial coefficient and handle all exceptions.
      try {
        result = calc_binomial(possibilities, iter);
      } catch (const system_exception& ex) {
        string fail_message = ustring::format("An exception was raised when calculating Binomial( {}, {} ).", possibilities, iter);
        default_listener->fail(fail_message, ex.message());
        if (!default_listener->assert_ui_enabled())
          console::write_line(fail_message + "\n" + ex.message());
        return;
      }
      
      // Format the trace and console output.
      binomial = ustring::format("Binomial( {0}, {1} ) = ", possibilities, iter);
      default_listener->write(binomial);
      default_listener->write_line(ustring::format("{}", result));
      console::write_line("{0} {1}", binomial, result);
    }
  }

  static decimal calc_binomial(xtd::decimal possibilities, decimal outcomes) {
    // Calculate a binomial coefficient, and minimize the chance of overflow.
    decimal result = 1;
    decimal iter;
    for (iter = 1; iter <= possibilities - outcomes; iter++) {
      result *= outcomes + iter;
      result /= iter;
    }
    return result;
  }
};

startup_(binomial);

// This code can produces the following output :
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
