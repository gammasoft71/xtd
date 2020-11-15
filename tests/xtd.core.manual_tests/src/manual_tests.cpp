#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;

void test3() {
  console::write_line(stack_trace());
}

void test2() {
  test3();
}

void test1() {
  test2();
}

int main() {
  //console::write_line("Hello, World!");
  test1();
}
