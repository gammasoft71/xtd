#include <xtd/diagnostics/stopwatch>
#include <xtd/console>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd;

auto main()->int {
  auto stopwatch = xtd::diagnostics::stopwatch {};
  stopwatch.start();
  sleep_for(10000_ms);
  stopwatch.stop();
  // Get the elapsed time as a duration value.
  auto ns = stopwatch.elapsed();
  
  // Format and display the duration value.
  auto elapsed_time = ustring::format("{0:H}:{0:M}:{0:S}.{1:D2}", ns, duration_cast<milliseconds>(ns).count() % 1000 / 10);
  console::write_line("RunTime " + elapsed_time);
}

// This code produces the following output :
//
// RunTime 00:00:10.00
