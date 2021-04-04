#define DEBUG // Force debug mode even if example is builded in release.
#include <memory>
#include <thread>
#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace std::this_thread;
using namespace xtd::diagnostics;

int main() {
  debug::listeners({make_shared<console_trace_listener>()});
  debug::write_line("Begin");
  debug::indent();
  /// Simulate work...
  for (auto step = 1; step <= 10; step++) {
    debug::write_line("working step {}...", step);
    sleep_for(300ms);
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
