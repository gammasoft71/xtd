#include <xtd/xtd.core>
#include <call_stack.h>

using namespace xtd;

void test3() {
  stacktrace::call_stack cs(1);
  for (auto item : cs.stack)
    console::write_line(item.to_string());
}

void test2() {
  test3();
}

void test1() {
  test2();
}

int main() {
  console::write_line("Hello, World!");
  test1();
}
