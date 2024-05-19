#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/diagnostics/debug>
#include <xtd/diagnostics/console_trace_listener>
#include <xtd/threading/thread>
#include <memory>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

auto main() -> int {
  debug::listeners({make_shared<console_trace_listener>()});
  debug::write_line("Begin");
  debug::indent();
  /// Simulate work...
  for (auto step = 1; step <= 10; step++) {
    debug::write_line("working step {}...", step);
    threading::thread::sleep(300_ms);
  }
  debug::unindent();
  debug::write_line("End");
}

// This code produces the following output :
//
// Begin
//     working step 1...
//     working step 2...
//     working step 3...
//     working step 4...
//     working step 5...
//     working step 6...
//     working step 7...
//     working step 8...
//     working step 9...
//     working step 10...
// End
