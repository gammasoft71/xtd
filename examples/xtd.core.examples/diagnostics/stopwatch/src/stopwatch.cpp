#include <xtd/diagnostics/stopwatch>
#include <xtd/console>
#include <limits>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class operations_timer {
public:
  static void display_timer_properties() {
    // Display the timer frequency and resolution.
    if (stopwatch::is_high_resolution())
      console::write_line("Operations timed using the system's high-resolution performance counter.");
    else
      console::write_line("Operations timed using the standard date time.");
      
    auto frequency = stopwatch::frequency();
    console::write_line("  Timer frequency in ticks per second = {0}", frequency);
    auto nanosec_per_tick = (1000l * 1000l * 1000l) / frequency;
    console::write_line("  Timer is accurate within {0} nanoseconds", nanosec_per_tick);
  }
  
  static void time_operations() {
    auto nanosec_per_tick = (1000l * 1000l * 1000l) / stopwatch::frequency();
    constexpr auto num_iterations = 10000;
    
    // Define the operation title names.
    auto operation_names = vector {"Operation: parse<int>(\"0\")", "Operation: try_parse<int>(\"0\")", "Operation: parse<int>(\"a\")", "Operation: try_parse<int>(\"a\")"};
    
    // Time four different implementations for parsing
    // an integer from a string.
    
    for (auto operation = 0; operation <= 3; operation++) {
      // Define variables for operation statistics.
      auto num_ticks = 0l;
      [[maybe_unused]] auto num_rollovers = 0l;
      auto max_ticks = 0l;
      auto min_ticks = numeric_limits<long>::max();
      auto index_fastest = -1;
      auto index_slowest = -1;
      auto milli_sec = 0l;
      
      auto time_10k_operations = stopwatch::start_new();
      
      // Run the current operation 10001 times.
      // The first execution time will be tossed out, since it can skew the average time.
      
      for (auto i = 0; i <= num_iterations; i++) {
        auto ticks_this_time = 0l;
        auto input_num = 0;
        auto time_per_parse = stopwatch {};
        
        switch (operation) {
          case 0:
            // Parse a valid integer using a try-catch statement.
            
            // Start a new stopwatch timer.
            time_per_parse = stopwatch::start_new();
            
            try {
              input_num = parse<int>("0");
            } catch (const system_exception&) {
              input_num = 0;
            }
            
            // Stop the timer, and save the elapsed ticks for the operation.
            time_per_parse.stop();
            ticks_this_time = time_per_parse.elapsed_ticks();
            break;
            
          case 1:
            // Parse a valid integer using the try_parse statement.
            
            // Start a new stopwatch timer.
            time_per_parse = stopwatch::start_new();
            
            if (!try_parse<int>("0", input_num))
              input_num = 0;
              
            // Stop the timer, and save the elapsed ticks for the operation.
            time_per_parse.stop();
            ticks_this_time = time_per_parse.elapsed_ticks();
            break;
            
          case 2:
            // Parse an invalid value using a try-catch statement.
            
            // Start a new stopwatch timer.
            time_per_parse = stopwatch::start_new();
            
            try {
              input_num = parse<int>("a");
            } catch (const system_exception&) {
              input_num = 0;
            }
            
            // Stop the timer, and save the elapsed ticks for the operation.
            time_per_parse.stop();
            ticks_this_time = time_per_parse.elapsed_ticks();
            break;
            
          case 3:
            // Parse an invalid value using the try_parse statement.
            
            // Start a new stopwatch timer.
            time_per_parse = stopwatch::start_new();
            
            if (!try_parse("a", input_num))
              input_num = 0;
              
            // Stop the timer, and save the elapsed ticks for the operation.
            time_per_parse.stop();
            ticks_this_time = time_per_parse.elapsed_ticks();
            break;
            
          default:
            break;
        }
        
        // Skip over the time for the first operation, just in case it caused a one-time performance hit.
        if (i == 0) {
          time_10k_operations.reset();
          time_10k_operations.start();
        } else  {
        
          // Update operation statistics for iterations 1-10000.
          if (max_ticks < ticks_this_time) {
            index_slowest = i;
            max_ticks = ticks_this_time;
          }
          if (min_ticks > ticks_this_time) {
            index_fastest = i;
            min_ticks = ticks_this_time;
          }
          num_ticks += ticks_this_time;
          if (num_ticks < ticks_this_time) {
            // Keep track of rollovers.
            num_rollovers ++;
          }
        }
      }
      
      // Display the statistics for 10000 iterations.
      
      time_10k_operations.stop();
      milli_sec = time_10k_operations.elapsed_milliseconds();
      
      console::write_line();
      console::write_line("{0} Summary:", operation_names[operation]);
      console::write_line("  Slowest time:  #{0}/{1} = {2} ticks", index_slowest, num_iterations, max_ticks);
      console::write_line("  Fastest time:  #{0}/{1} = {2} ticks", index_fastest, num_iterations, min_ticks);
      console::write_line("  Average time:  {0} ticks = {1} nanoseconds", num_ticks / num_iterations, (num_ticks * nanosec_per_tick) / num_iterations);
      console::write_line("  Total time looping through {0} operations: {1} milliseconds", num_iterations, milli_sec);
    }
  }
};

auto main() -> int {
  operations_timer::display_timer_properties();
  
  console::write_line();
  console::write_line("Press the Enter key to begin:");
  console::read_line();
  console::write_line();
  
  operations_timer::time_operations();
}

// This code can produces the following output :
//
// Operations timed using the system's high-resolution performance counter.
//   Timer frequency in ticks per second = 1000000000
//   Timer is accurate within 1 nanoseconds
//
// Press the Enter key to begin:
//
//
// Operation: parse<int>("0") Summary:
//   Slowest time:  #7232/10000 = 505 ticks
//   Fastest time:  #1278/10000 = 20 ticks
//   Average time:  26 ticks = 26 nanoseconds
//   Total time looping through 10000 operations: 28 milliseconds
//
// Operation: try_parse<int>("0") Summary:
//   Slowest time:  #2910/10000 = 312 ticks
//   Fastest time:  #5105/10000 = 19 ticks
//   Average time:  20 ticks = 20 nanoseconds
//   Total time looping through 10000 operations: 22 milliseconds
//
// Operation: parse<int>("a") Summary:
//   Slowest time:  #7001/10000 = 19279 ticks
//   Fastest time:  #3392/10000 = 4881 ticks
//   Average time:  5878 ticks = 5878 nanoseconds
//   Total time looping through 10000 operations: 5882 milliseconds
//
// Operation: try_parse<int>("a") Summary:
//   Slowest time:  #3157/10000 = 14341 ticks
//   Fastest time:  #20/10000 = 5809 ticks
//   Average time:  6532 ticks = 6532 nanoseconds
//   Total time looping through 10000 operations: 6536 milliseconds
