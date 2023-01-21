#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto uri = xtd::uri("https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1&q2=v2#FragmentName");
      
      console::write_line("absolute_path: {}", uri.absolute_path());
      console::write_line("absolute_uri: {}", uri.absolute_uri());
      console::write_line("dns_safe_host: {}", uri.dns_safe_host());
      console::write_line("fragment: {}", uri.fragment());
      console::write_line("host: {}", uri.host());
      console::write_line("host_name_type: {}", uri.host_name_type());
      console::write_line("idn_host: {}", uri.idn_host());
      console::write_line("is_absolute_uri: {}", uri.is_absolute_uri());
      console::write_line("is_default_port: {}", uri.is_default_port());
      console::write_line("is_file: {}", uri.is_file());
      console::write_line("is_loopback: {}", uri.is_loopback());
      console::write_line("is_unc: {}", uri.is_unc());
      console::write_line("local_path: {}", uri.local_path());
      console::write_line("original_string: {}", uri.original_string());
      console::write_line("path_and_query: {}", uri.path_and_query());
      console::write_line("port: {}", uri.port());
      console::write_line("query: {}", uri.query());
      console::write_line("scheme: {}", uri.scheme());
      console::write_line("segments: {}", ustring::join(", ", uri.segments()));
      console::write_line("user_info: {}", uri.user_info());
    }
  };
}

startup_(examples::program);

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
