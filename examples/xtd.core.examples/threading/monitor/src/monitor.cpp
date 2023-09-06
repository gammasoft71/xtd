#include <xtd/threading/interlocked>
#include <xtd/threading/monitor>
#include <xtd/threading/thread>
#include <xtd/console>
#include <xtd/literals>
#include <xtd/random>
#include <xtd/startup>
#include <array>
#include <vector>

using namespace xtd;
using namespace xtd::threading;

namespace monitor_example {
  class program {
  public:
    static void main() {
      auto threads = std::vector<thread> {};
      auto rnd = xtd::random {};
      auto total = 0_s64;
      auto n = 0;
      
      for (auto thread_ctr = 0; thread_ctr < 10; ++thread_ctr)
        threads.push_back(thread::start_new([&] {
          auto values = std::array<int, 10000> {};
          auto thread_total = 0;
          auto thread_n = 0;
          auto ctr = 0;
          monitor::enter(rnd);
          // Generate 10,000 random integers
          for (ctr = 0; ctr < 10000; ++ctr)
            values[ctr] = rnd.next(0, 1001);
          monitor::exit(rnd);
          thread_n = ctr;
          for (auto value : values)
            thread_total += value;
          
          console::write_line("Mean for task {0,2}: {1:N2} (N={2:N0})",
                              thread::current_thread().managed_thread_id(),
                              (thread_total * 1.0) / thread_n, thread_n);
          interlocked::add(n, thread_n);
          interlocked::add(total, thread_total);
        }));
      try {
        for (auto& thread : threads)
          thread.join();
        console::write_line("\nMean for all tasks: {0:N2} (N={1:N0})",
                            (total * 1.0)/n, n);
      }
      catch (const system_exception& e) {
        console::write_line("{0}: {1}", e.get_type().name(), e.message());
      }
    }
  };
}

startup_(monitor_example::program::main);

// This example produces output similar to the following:
//
// Mean for task  4: 498.90 (N=10000)
// Mean for task  2: 499.92 (N=10000)
// Mean for task  7: 503.12 (N=10000)
// Mean for task  5: 499.41 (N=10000)
// Mean for task  3: 498.58 (N=10000)
// Mean for task  8: 496.71 (N=10000)
// Mean for task 10: 501.49 (N=10000)
// Mean for task  6: 498.84 (N=10000)
// Mean for task  9: 502.72 (N=10000)
// Mean for task 11: 498.69 (N=10000)
//
// Mean for all tasks: 499.84 (N=100000)
