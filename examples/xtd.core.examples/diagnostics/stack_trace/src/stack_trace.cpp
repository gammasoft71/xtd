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
  test1();
}

// This code produces the following output :
//
//    at test3()
//    at test2()
//    at test1()
//    at main
