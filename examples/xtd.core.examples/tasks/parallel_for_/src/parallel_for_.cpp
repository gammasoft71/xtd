#include <xtd/xtd>

struct program {
  static auto main() {
    parallel::for_(10, 21, [](auto number) async_ {
      co_await task<>::yield();
      println("number = {}", number);
    });
  }
};

startup_(program::main);

// This code produces the following output :
//
// number = 10
// number = 11
// number = 15
// number = 13
// number = 19
// number = 12
// number = 16
// number = 14
// number = 17
// number = 18
// number = 20
