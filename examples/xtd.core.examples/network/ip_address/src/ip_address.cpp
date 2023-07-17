#include <xtd/net/sockets/socket>
#include <xtd/net/dns>
#include <xtd/net/ip_address>
#include <xtd/console>
#include <xtd/startup>
#include <regex>

using namespace std;
using namespace xtd;
using namespace xtd::net;
using namespace xtd::net::sockets;

class test_ip_address {
public:
  static auto main(const vector<ustring>& args) {
    auto server = ustring::empty_string;
    
    // Define a regular expression to parse user's input.
    // This is a security check. It allows only
    // alphanumeric input string between 2 to 40 character long.
    auto rex = regex {R"(^[a-zA-Z]\w{1,39}$)"};
    
    if (args.size() < 1) {
      // If no server name is passed as an argument to this program, use the current
      // server name as default.
      server = dns::get_host_name();
      console::write_line("Using current host: {}", server);
    } else {
      server = args[0];
      if (!regex_match(server, rex)) {
        console::write_line("Input string format not allowed.");
        return;
      }
    }
    
    // Get the list of the addresses associated with the requested server.
    ip_addresses(server);
    
    // Get additional address information.
    ip_address_additional_info();
  }
  
private:
  /**
   * The IPAddresses method obtains the selected server IP address information.
   * It then displays the type of address family supported by the server and its
   * IP address in standard and byte format.
   **/
  static void ip_addresses(auto server) {
    try {
      // Get server related information.
      auto heserver = dns::get_host_entry(server);
      
      // Loop on the AddressList
      for (auto cur_add : heserver.address_list()) {
        // Display the type of address family supported by the server. If the
        // server is IPv6-enabled this value is: InterNetworkV6. If the server
        // is also IPv4-enabled there will be an additional value of InterNetwork.
        console::write_line("address_family: {}", cur_add.address_family());
        
        // Display the ScopeId property in case of IPV6 addresses.
        if (cur_add.address_family() == address_family::inter_network_v6)
          console::write_line("scope id: {}", cur_add.scope_id());
          
          
        // Display the server IP address in the standard format. In
        // IPv4 the format will be dotted-quad notation, in IPv6 it will be
        // in in colon-hexadecimal notation.
        console::write_line("address: {}", cur_add);
        
        // Display the server IP address in byte format.
        console::write("address_bytes: ");
        
        auto bytes = cur_add.get_address_bytes();
        for (size_t i = 0; i < bytes.size(); i++)
          console::write(bytes[i]);
        console::write_line("\r\n");
      }
    } catch (const system_exception& e) {
      console::write_line("[do_resolve] exception: {}", e);
    }
  }
  
  // This IPAddressAdditionalInfo displays additional server address information.
  static void ip_address_additional_info() {
    try {
      // Display the flags that show if the server supports IPv4 or IPv6
      // address schemas.
      console::write_line("\r\nos_supports_ip_v4: {}", socket::os_supports_ip_v4());
      console::write_line("os_supports_ip_v6: {}", socket::os_supports_ip_v6());
      
      if (socket::os_supports_ip_v6()) {
        // Display the server Any address. This IP address indicates that the server
        // should listen for client activity on all network interfaces.
        console::write_line("\r\nip_v6_any: {}", ip_address::ip_v6_any);
        
        // Display the server loopback address.
        console::write_line("ip_v6_loopback: {}", ip_address::ip_v6_loopback);
        
        // Used during autoconfiguration first phase.
        console::write_line("ip_v6_none: {}", ip_address::ip_v6_none);
        
        console::write_line("is_loopback(ip_v6_loopback): {}", ip_address::is_loopback(ip_address::ip_v6_loopback));
      }
      console::write_line("is_loopback(loopback):{}", ip_address::is_loopback(ip_address::loopback));
    } catch (const system_exception& e) {
      console::write_line("[ip_addresses] exception: {}", e);
    }
  }
};

startup_(test_ip_address);

// This code produces the following output if no args:
//
// Using current host: !---OMITTED---!.local
// address_family: inter_network
// address: 192.168.1.37
// address_bytes: 192168137
//
//
// os_supports_ip_v4: true
// os_supports_ip_v6: true
//
// ip_v6_any: ::
// ip_v6_loopback: ::1
// ip_v6_none: ::
// is_loopback(ip_v6_loopback): true
// is_loopback(loopback):true
