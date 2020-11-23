#include <xtd/xtd.core>

using namespace xtd;

void test3() {
  console::write_line("environment::stack_trace:");
  console::write_line(environment::stack_trace());
}

void test2() {
  test3();
}

void test1() {
  test2();
}


int main() {
  test1();
}

// This code produces the following output :
//
// environment::stack_trace:
//    at xtd::environment::stack_trace() [0x00002C20] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
//    at test3() [0x00002B40] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
//    at test2() [0x00002CA0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
//    at test1() [0x00002CB0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
//    at main [0x00002CC0] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/environment/environment_stack_trace/Debug/environment_stack_trace:line 0
