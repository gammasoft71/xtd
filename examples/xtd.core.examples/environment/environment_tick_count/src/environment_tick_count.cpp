#include <xtd/xtd>

using namespace xtd;

int main() {
  auto result = environment::tick_count();
  console::write_line("Time since boot : {0}", result);
}

// This code can be produce the following output :
//
// Time since boot : 8.18:12:02:823000000
