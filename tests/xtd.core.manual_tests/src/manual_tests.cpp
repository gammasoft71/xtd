#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;

void test3() {
  stack_trace st(1);
  for (auto item : st.frames())
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
