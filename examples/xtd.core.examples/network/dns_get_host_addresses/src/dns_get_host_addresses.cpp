#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::net;

int main() {
  vector<ip_address> addresses = dns::get_host_addresses("google.com");
  console::write_line("google.com addresses:");
  for(auto address : addresses)
    console::write_line("  * {}", address);
}

// This code produces the following output:
//
// google.com addresses:
//   * 142.251.36.46
