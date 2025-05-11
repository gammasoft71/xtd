#include <xtd/xtd>

auto main() -> int {
  auto sl = diagnostics::source_location::current();
  console::write_line("source_location :");
  console::write_line("  file_name     = {}", sl.file_name());
  console::write_line("  function_name = {}", sl.function_name());
  console::write_line("  line          = {}", sl.line());
  console::write_line("  column        = {}", sl.column());
}

// This code can produces the following output:
//
// Hello, World!
