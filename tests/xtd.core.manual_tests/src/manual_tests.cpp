#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;

void test3() {
  stack_trace st {"test3"};
  console::write_line("{}", st);
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
