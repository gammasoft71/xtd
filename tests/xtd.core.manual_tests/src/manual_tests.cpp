#include <xtd/xtd>

namespace xtd {
  template <class type_t>
  using params = std::initializer_list<type_t>;
}

using namespace xtd;

auto main(int argc, char* argv[]) -> int {
  //console::write_line("Hello, World!");
  u32string s = "مرحباً أيها العالم!";
  for (auto c : s)
    console::write("\\u{:x4}", int32(c));
  console::write_line();
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
