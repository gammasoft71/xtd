#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;

void method3() {
  console::write_line("stack_trace:");
  console::write_line(stack_trace());
}

void method2() {
  method3();
}

void method1() {
  method2();
}

int main() {
  method1();
}

// This code produces the following output :
//
// stack_trace:
//    at method3()
//    at method2()
//    at method1()
//    at main
