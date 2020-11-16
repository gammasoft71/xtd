#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;

void test3() {
  //console::write_line(stack_trace());
  throw argument_out_of_range_exception(caller_info_);
}

void test2() {
  test3();
}

void test1() {
  test2();
}

int main() {
  //console::write_line("Hello, World!");
  system_exception::enable_stack_trace(false);
  try {
    test1();
  } catch(const system_exception& e) {
    console::write_line(e);
  }
}
