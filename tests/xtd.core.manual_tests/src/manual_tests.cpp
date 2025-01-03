#include <xtd/xtd>

auto main() -> int {
  const auto& squares = enumerable::range(1, 10).select([](auto x) {return x * x;});
  
  for (auto num : squares)
    console::write_line(num);

  /*
  try {
    throw exception {};
  } catch(const exception& e) {
    console::write_line("type              = {}", e.get_type());
    console::write_line("help_link         = {}", e.help_link());
    console::write_line("h_result          = 0x{0:X8} ({0})", static_cast<uint>(e.h_result()));
    console::write_line("inner_exception   = {}", e.inner_exception());
    console::write_line("message           = {}", e.message());
    console::write_line("source            = {}", e.source());
    console::write_line("stack_trace       = {}", e.stack_trace());
  }
   */
}

// This code can produces the following output:
//
// Hello, World!
