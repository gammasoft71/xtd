#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::net;

int main() {
  ip_host_entry host_entry = dns::get_host_entry("www.github.com");
  console::write_line("ip host entry for : www.github.com");
  console::write_line("  - host_name : {}", host_entry.host_name());
  console::write_line("  - address list :");
  for(auto address : host_entry.address_list())
    console::write_line("    * {}", address);
  console::write_line("  - aliases :");
  for(auto alias : host_entry.aliases())
    console::write_line("    * {}", alias);
}

// This code produces the following output:
//
// ip host entry for : www.github.com
//   - host_name : github.com
//   - address list :
//     * 140.82.121.3
//   - aliases :
//     * www.github.com
