#include <xtd/net/dns>
#include <xtd/console>

using namespace xtd;
using namespace xtd::net;

auto main() -> int {
  auto addresses = dns::get_host_addresses("www.google.com");
  console::write_line("www.google.com addresses:");
  for (auto address : addresses)
    console::write_line("  * {}", address);
}

// This code produces the following output:
//
// www.google.com addresses:
//   * 216.58.208.100
