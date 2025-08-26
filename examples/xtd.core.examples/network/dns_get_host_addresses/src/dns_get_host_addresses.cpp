#include <xtd/xtd>

auto main() -> int {
  auto addresses = net::dns::get_host_addresses("www.google.com");
  console::write_line("www.google.com addresses:");
  for (auto address : addresses)
    console::write_line("  * {}", address);
}

// This code produces the following output :
//
// www.google.com addresses:
//   * 216.58.208.100
