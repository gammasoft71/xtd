#include <xtd/console>
#include <xtd/environment>

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


auto main() -> int {
  test1();
}

// This code produces the following output :
//
// environment::stack_trace:
//    at xtd::environment::stack_trace() [0x00002C20] in !---OMITTED---!/environment.cpp:line 255
//    at test3() [0x00002B40] in !---OMITTED---!/environment_stack_trace.cpp:line 7
//    at test2() [0x00002CA0] in !---OMITTED---!/environment_stack_trace.cpp:line 11
//    at test1() [0x00002CB0] in !---OMITTED---!/environment_stack_trace.cpp:line 15
//    at main [0x00002CC0] in !---OMITTED---!/environment_stack_trace.cpp:line 20
