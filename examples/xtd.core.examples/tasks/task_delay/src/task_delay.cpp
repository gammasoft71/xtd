#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    auto t = task<int>::run(delegate_ {
      task<>::delay(time_span::from_seconds(1.5)).wait();
      return 42;
    });
    co_await t;
    console::write_line("Task t status: {}, result: {}", t.status(), t.result());
  }
};

startup_(example::main);

// This code produces the following output :
//
// Task t status: ran_to_completion, result: 42
