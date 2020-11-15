#include <xtd/xtd.core>

using namespace xtd;

int main() {
  console::write_line("environment::stack_trace:");
  console::write_line(environment::stack_trace());
}

// This code produces the following output :
//
// environment::stack_trace:
//    at xtd::environment::stack_trace() [0x000021F0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment_stack_trace/Debug/environment_stack_trace:line 0
//    at main [0x00002110] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment_stack_trace/Debug/environment_stack_trace:line 0
