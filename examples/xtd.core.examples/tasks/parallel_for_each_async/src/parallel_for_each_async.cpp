#include <xtd/xtd>

class program {
public:
  static auto main() -> task<> {
    auto worlds = {u8"World"_s, u8"Mundo"_s, u8"Monde"_s, u8"Mondo"_s, u8"モンド"_s, u8"世界"_s, u8"Welt"_s, u8"Мир"_s};
    co_await parallel::for_each_async(worlds, [](auto world) -> task<> {
      co_await task<>::delay(100_ms);
      println("Hello, {}!", world);
    });
  }
};

startup_(program::main);

// This code produces the following output :
//
// Hello, 世界!
// Hello, Мир!
// Hello, World!
// Hello, Welt!
// Hello, Mondo!
// Hello, Monde!
// Hello, モンド!
// Hello, Mundo!
