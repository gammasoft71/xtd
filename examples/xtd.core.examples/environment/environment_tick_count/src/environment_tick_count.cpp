#include <xtd/xtd>

using namespace xtd;

int main() {
  auto time_since_boot = environment::tick_count();
  console::write_line("Time since boot : {0:d} days {0:h}:{0:M}", time_since_boot);
}

// This code can be produce the following output :
//
// Time since boot : 8 days 18:20
