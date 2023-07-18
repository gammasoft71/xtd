#include <xtd/console>
#include <xtd/startup>
#include <xtd/uri>

namespace uri_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto uri = xtd::uri {"https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1&q2=v2#FragmentName"};
      
      xtd::console::write_line("absolute_path: {}", uri.absolute_path());
      xtd::console::write_line("absolute_uri: {}", uri.absolute_uri());
      xtd::console::write_line("dns_safe_host: {}", uri.dns_safe_host());
      xtd::console::write_line("fragment: {}", uri.fragment());
      xtd::console::write_line("host: {}", uri.host());
      xtd::console::write_line("host_name_type: {}", uri.host_name_type());
      xtd::console::write_line("idn_host: {}", uri.idn_host());
      xtd::console::write_line("is_absolute_uri: {}", uri.is_absolute_uri());
      xtd::console::write_line("is_default_port: {}", uri.is_default_port());
      xtd::console::write_line("is_file: {}", uri.is_file());
      xtd::console::write_line("is_loopback: {}", uri.is_loopback());
      xtd::console::write_line("is_unc: {}", uri.is_unc());
      xtd::console::write_line("local_path: {}", uri.local_path());
      xtd::console::write_line("original_string: {}", uri.original_string());
      xtd::console::write_line("path_and_query: {}", uri.path_and_query());
      xtd::console::write_line("port: {}", uri.port());
      xtd::console::write_line("query: {}", uri.query());
      xtd::console::write_line("scheme: {}", uri.scheme());
      xtd::console::write_line("segments: {}", xtd::ustring::join(", ", uri.segments()));
      xtd::console::write_line("user_info: {}", uri.user_info());
    }
  };
}

startup_(uri_example::program);

// This code can produce the following output:
//
// absolute_path: /Home/Index.htm
// absolute_uri: https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1&q2=v2#FragmentName
// dns_safe_host: www.contoso.com
// fragment: #FragmentName
// host: www.contoso.com
// host_name_type: Dns
// idn_host: www.contoso.com
// is_absolute_uri: true
// is_default_port: false
// is_file: false
// is_loopback: false
// is_unc: false
// local_path: /Home/Index.htm
// original_string: https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1&q2=v2#FragmentName
// path_and_query: /Home/Index.htm?q1=v1&q2=v2
// port: 80
// query: ?q1=v1&q2=v2
// scheme: https
// segments: /, Home/, Index.htm
// user_info: user:password
