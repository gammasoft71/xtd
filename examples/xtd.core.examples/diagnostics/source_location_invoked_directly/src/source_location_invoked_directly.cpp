#include <xtd/io/path>
#include <xtd/console>
#include <xtd/diagnostics/source_location>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

void print_this_file_name() {
  auto location = source_location::current();
  console::write_line("File: {}", path::get_file_name(location.file_name()));
}

auto main() -> int {
  print_this_file_name();
}

// This code can produce the following output :
//
// File: source_location_invoked_directly.cpp
