#include <xtd/xtd>

auto main_async() async_ {
  println("(main) start");
  co_await task<>::factory().start_new([] async_ {
    println("(task 1) start");
    co_await task<>::delay(200_ms);
    println("(task 1) end");
  }).continue_with([] async_ {
    println("(task 2) start");
    co_await task<>::delay(200_ms);
    println("(task 2) end");
  });
  println("(main) end");
};

auto main() -> int {
  startup::run(main_async);
}

// This code produces the following output :
//
// Hello, World!
