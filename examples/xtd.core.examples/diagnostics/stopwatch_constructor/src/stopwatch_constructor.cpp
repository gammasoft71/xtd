#include <xtd/xtd>

auto main() -> int {
  auto stopwatch = diagnostics::stopwatch {};
  stopwatch.start();
  thread::sleep(10000_ms);
  stopwatch.stop();
  // Get the elapsed time as a duration value.
  auto ts = stopwatch.elapsed();
  
  // Format and display the duration value.
  auto elapsed_time = string::format("{0:H}:{0:M}:{0:S}.{1:D2}", ts, ts.milliseconds() / 10);
  console::write_line("RunTime " + elapsed_time);
}

// This code produces the following output :
//
// RunTime 00:00:10.00
