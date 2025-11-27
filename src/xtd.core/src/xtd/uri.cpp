#include "../../include/xtd/uri.hpp"
#include "../../include/xtd/collections/generic/list.hpp"
#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../include/xtd/as.hpp"
#include "../../include/xtd/char_object.hpp"
#include "../../include/xtd/char32_object.hpp"
#include "../../include/xtd/invalid_operation_exception.hpp"
#include "../../include/xtd/uri_format_exception.hpp"
#include "../../include/xtd/uri_template_match_exception.hpp"
#include "../../include/xtd/io/path.hpp"
#include "../../include/xtd/net/ip_address.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::helpers;
using namespace xtd::io;
using namespace xtd::net;

uri::uri(const string& uri_string) {
  set_uri(uri_string, uri_kind::absolute);
}

uri::uri(const string& uri_string, uri_kind kind) {
  set_uri(uri_string, kind);
}

uri::uri(const uri& base_uri, const string& relative_uri) {
  set_uri(base_uri.data_->original_uri + relative_uri, base_uri.data_->kind);
}

uri::uri(const uri& base_uri, const uri& relative_uri) {
  set_uri(base_uri.data_->original_uri + relative_uri.data_->original_uri, base_uri.data_->kind);
}

string uri::absolute_path() const {
  return get_components(uri_components::path, uri_format::uri_escaped);
}

string uri::absolute_uri() {
  return get_components(uri_components::absolute_uri, uri_format::uri_escaped);
}

string uri::authority() const {
  return get_components(uri_components::user_info | uri_components::keep_delimiter, uri_format::uri_escaped) + get_components(uri_components::host | uri_components::keep_delimiter, uri_format::uri_escaped) + get_components(uri_components::port | uri_components::keep_delimiter, uri_format::uri_escaped);
}

string uri::dns_safe_host() const {
  auto str = host();
  if (!xtd::string::is_empty(str)) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == true && address.address_family() == sockets::address_family::inter_network_v6 && str[0] == '[' && str[str.length() - 1] == ']')
      return str.substring(1, str.length() - 2);
  }
  return get_components(uri_components::host, uri_format::safe_unescaped);
}

string uri::fragment() const {
  return get_components(uri_components::fragment | uri_components::keep_delimiter, uri_format::uri_escaped);
}

string uri::host() const {
  return get_components(uri_components::host, uri_format::unescaped);
}

uri_host_name_type uri::host_name_type() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  
  if (!xtd::string::is_empty(host())) {
    auto address = ip_address();
    if (ip_address::try_parse(host(), address) == false) return uri_host_name_type::dns;
    if (address.address_family() == sockets::address_family::inter_network) return uri_host_name_type::ip_v4;
    if (address.address_family() == sockets::address_family::inter_network_v6) return uri_host_name_type::ip_v6;
  }
  
  if (scheme() == uri::uri_scheme_mailto || scheme() == uri::uri_scheme_file) return uri_host_name_type::basic;
  
  return uri_host_name_type::unknown;
}

string uri::idn_host() const {
  auto str = host();
  if (!xtd::string::is_empty(str)) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == true && address.address_family() == sockets::address_family::inter_network_v6 && str[0] == '[' && str[str.length() - 1] == ']')
      return str.substring(1, str.length() - 2);
  }
  return get_components(uri_components::host, uri_format::safe_unescaped);
}

bool uri::is_absolute_uri() const {
  return data_->kind == uri_kind::absolute;
}

bool uri::is_default_port() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  
  auto prt = -1;
  if (string::try_parse<int32>(get_components(uri_components::port, uri_format::uri_escaped), prt) == true) return false;
  return true;
}

bool uri::is_file() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  return scheme() == uri_scheme_file;
}

bool uri::is_loopback() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  if (!xtd::string::is_empty(host())) {
    auto address = ip_address();
    if (ip_address::try_parse(host(), address) == true && ip_address::is_loopback(address)) return true;
  }
  return host() == ip_address::loopback.to_string() || host() == ip_address::ip_v6_loopback.to_string() || host() == "loopback" || host() == "localhost" || xtd::string::is_empty(host());
}

bool uri::is_unc() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  return scheme() == uri::uri_scheme_file && !xtd::string::is_empty(host());
}

string uri::local_path() const {
  return get_components(uri_components::path, uri_format::unescaped).replace('/', path::directory_separator_char());
}

const string& uri::original_string() const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  return data_->original_uri;
}

string uri::path_and_query() const {
  return get_components(uri_components::path_and_query, uri_format::uri_escaped);
}

int32 uri::port() const {
  auto port = -1;
  if (string::try_parse<int32>(get_components(uri_components::port, uri_format::uri_escaped), port) == true) return port;
  if (scheme() == uri::uri_scheme_ftp) return 21;
  if (scheme() == uri::uri_scheme_gopher) return 70;
  if (scheme() == uri::uri_scheme_http) return 80;
  if (scheme() == uri::uri_scheme_https) return 443;
  if (scheme() == "ldap") return 389;
  if (scheme() == uri::uri_scheme_mailto) return 25;
  if (scheme() == uri::uri_scheme_nntp) return 119;
  return -1;
}

string uri::query() const {
  return get_components(uri_components::query | uri_components::keep_delimiter, uri_format::uri_escaped);
}

string uri::scheme() const {
  return get_components(uri_components::scheme, uri_format::uri_escaped);
}

array<string> uri::segments() const {
  auto path = this->absolute_path();
  if (xtd::string::is_empty(path)) return {};
  
  auto segments = list<string> {};
  auto start_index = 0_z;
  auto length = 1_z;
  
  if (path[start_index] == '/') {
    segments.add(path.substring(start_index, length));
    start_index += length;
  }
  
  while (start_index < path.length()) {
    length = path.index_of('/', start_index);
    if (length == string::npos) length = path.length() - start_index;
    
    segments.add(path.substring(start_index, length));
    start_index += length;
  }
  return array<string>(segments);
}

string uri::user_info() const {
  return get_components(uri_components::user_info, uri_format::uri_escaped);
}

bool uri::check_scheme_name(const string& scheme) {
  auto first = true;
  for (auto c : as<std::u32string>(scheme)) {
    if (first) {
      first = false;
      if (!char32_object::is_letter(c)) return false;
    } else {
      if (!char32_object::is_letter_or_digit(c) && c != '.' && c != '+' && c != '-') return false;
    }
  }
  
  return !first;
}

string uri::escape_data_string(const string& value) {
  if (value.length() > 32766_z) throw_helper::throws(exception_case::uri_format);
  
  auto escape_needed = false;
  for (auto index = 0_z; !escape_needed && index < value.length(); ++index)
    escape_needed = !is_hex_encoding(value, index) && need_to_escape_data_char(value[index]);
    
  if (escape_needed) {
    auto ret_value = string::empty_string;
    for (auto index = 0_z; index < value.length(); ++index) {
      if (!is_hex_encoding(value, index) && need_to_escape_data_char(value[index])) ret_value += hex_escape(value[index]);
      else ret_value += value[index];
    }
    return ret_value;
  }
  
  return value;
}

string uri::escape_uri_string(const string& value) {
  if (value.length() > 32766_z) throw_helper::throws(exception_case::uri_format);
  
  auto escape_needed = false;
  for (auto index = 0_z; !escape_needed && index < value.length(); ++index)
    escape_needed = !is_hex_encoding(value, index) && need_to_escape_uri_char(value[index]);
    
  if (escape_needed) {
    auto ret_value = string::empty_string;
    for (auto index = 0_z; index < value.length(); ++index) {
      if (!is_hex_encoding(value, index) && need_to_escape_uri_char(value[index])) ret_value += hex_escape(value[index]);
      else ret_value += value[index];
    }
    return ret_value;
  }
  
  return value;
}

int32 uri::from_hex(char digit) {
  if ('0' <= digit && digit <= '9') return digit - '0';
  if ('a' <= digit && digit <= 'f') return 10 + digit - 'a';
  if ('A' <= digit && digit <= 'F') return 10 + digit - 'A';
  throw_helper::throws(exception_case::argument);
}

string uri::get_components(uri_components components, uri_format format) const {
  if (data_->kind != uri_kind::absolute) throw_helper::throws(exception_case::invalid_operation);
  
  auto str = string::empty_string;
  if ((components & uri_components::scheme) == uri_components::scheme) str += format_componant(data_->scheme, format);
  if ((components & uri_components::scheme) == uri_components::scheme && (components & ~uri_components::scheme) != uri_components::none) str += format_componant(data_->scheme_delimiter, format);
  if ((components & uri_components::user_info) == uri_components::user_info) str += format_componant(data_->user_info, format);
  if ((components & uri_components::user_info) == uri_components::user_info && data_->user_info.length() && (components & ~uri_components::user_info) != uri_components::none) str += format_componant("@", format);
  if ((components & uri_components::host) == uri_components::host) str += format_host_componant(data_->host, format);
  if ((components & uri_components::port) == uri_components::port && data_->port.length() && (components & ~uri_components::port) != uri_components::none) str += format_componant(":", format);
  if ((components & uri_components::port) == uri_components::port) str += format_componant(data_->port, format);
  if ((components & uri_components::path) == uri_components::path) str += format_componant(data_->path, format);
  if ((components & uri_components::query) == uri_components::query && data_->query.length() && (components & ~uri_components::query) != uri_components::none) str += format_componant("?", format);
  if ((components & uri_components::query) == uri_components::query) str += format_componant(data_->query, format);
  if ((components & uri_components::fragment) == uri_components::fragment && data_->fragment.length() && (components & ~uri_components::fragment) != uri_components::none) str += format_componant("#", format);
  if ((components & uri_components::fragment) == uri_components::fragment) str += format_componant(data_->fragment, format);
  if ((components & uri_components::strong_port) == uri_components::strong_port && (components & ~uri_components::strong_port) != uri_components::none) str += format_componant(":", format);
  if ((components & uri_components::strong_port) == uri_components::strong_port) str += format_componant(string::format("{}", port()), format);
  
  return str;
}

string uri::get_left_part(uri_partial part) const {
  switch (part) {
    case uri_partial::scheme: return get_components(uri_components::scheme | uri_components::keep_delimiter, uri_format::uri_escaped);
    case uri_partial::authority: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port, uri_format::uri_escaped);
    case uri_partial::path: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port | uri_components::path, uri_format::uri_escaped);
    case uri_partial::query: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port | uri_components::path_and_query, uri_format::uri_escaped);
    default: break;
  }
  throw_helper::throws(exception_case::argument);
}

string uri::hex_escape(char character) {
  return string::format("%{:X2}", convert::to_int32(character));
}

char uri::hex_unescape(const string& pattern, size_t& index) {
  index += 3;
  return as<char>(parse<int32>(pattern.substring(index - 2, 2), number_styles::hex_number));
}

bool uri::is_base_of(const uri& uri) const {
  auto path = data_->path.remove(data_->path.length() - 1).last_index_of('/') == string::npos ? data_->path : data_->path.remove(data_->path.remove(data_->path.length() - 1).last_index_of('/'));
  auto uri_path = uri.data_->path.remove(uri.data_->path.length() - 1).last_index_of('/') == string::npos ? uri.data_->path : uri.data_->path.remove(uri.data_->path.remove(uri.data_->path.length() - 1).last_index_of('/'));
  
  return data_->scheme == uri.data_->scheme && data_->scheme_delimiter == uri.data_->scheme_delimiter && data_->host == uri.data_->host && data_->port == uri.data_->port && path == uri_path;
}

bool uri::is_hex_digit(char character) {
  return (character >= '0' && character <= '9') || (character >= 'A' && character <= 'F') || (character >= 'a' && character <= 'f');
}

bool uri::is_hex_encoding(const string& pattern, size_t index) {
  if (pattern.length() < index + 3)  return false;
  
  auto it = pattern.begin() + index;
  if (*it != '%') return false;
  ++it;
  if (!is_hex_digit(*it)) return false;
  ++it;
  if (!is_hex_digit(*it)) return false;
  
  return true;
}

bool uri::is_well_formed_original_string() {
  auto well_formated_original_string = true;
  
  for (auto index = 0_z; !well_formated_original_string && index < data_->original_uri.length(); ++index)
    well_formated_original_string = !(is_hex_encoding(data_->original_uri, index) || need_to_escape_uri_char(data_->original_uri[index]));
    
  if (well_formated_original_string == true) well_formated_original_string = path::is_path_rooted(data_->original_uri);
  if (well_formated_original_string == true) well_formated_original_string = data_->original_uri.index_of('\\') != string::npos;
  if (well_formated_original_string == true) well_formated_original_string = !(data_->scheme_delimiter.length() == 0 && data_->host.length() != 0);
  if (well_formated_original_string == true) well_formated_original_string = check_scheme_name(data_->scheme);
  
  return well_formated_original_string;
}

bool uri::is_well_formed_uri_string(const string& uri_string, uri_kind uri_kind) {
  auto well_formed_uri_string = true;
  
  try {
    auto uri_value = uri(uri_string, uri_kind);
    well_formed_uri_string = uri_value.is_well_formed_original_string();
  } catch (...) {
    well_formed_uri_string = false;
  }
  
  return well_formed_uri_string;
}

string uri::unescape_data_string(const string& value) {
  // See http://www.geekhideout.com/urlcode.shtml
  auto unescape_needed = false;
  for (auto index = 0_z; !unescape_needed && index < value.length(); ++index)
    unescape_needed = is_hex_encoding(value, index);
    
  if (!unescape_needed) return value;
  
  auto ret_value = string::empty_string;
  auto index = 0_z;
  while (index < value.length()) {
    if (is_hex_encoding(value, index))
      ret_value += string::format("{}", hex_unescape(value, index));
    else
      ret_value += value[index++];
  }
  return ret_value;
}

bool uri::equals(const object& obj) const noexcept {
  return is<uri>(obj) && equals(static_cast<const uri&>(obj));
}

bool uri::equals(const uri& uri) const noexcept {
  return data_->scheme == uri.data_->scheme && data_->scheme_delimiter == uri.data_->scheme_delimiter && data_->host == uri.data_->host && data_->port == uri.data_->port && data_->path == uri.data_->path && data_->query == uri.data_->query && data_->kind == uri.data_->kind;
}

size uri::get_hash_code() const noexcept {
  return hash_code::combine(data_->original_uri, data_->scheme, data_->scheme_delimiter, data_->user_info, data_->host, data_->port, data_->path, data_->query, data_->fragment, data_->kind);
}

string uri::to_string() const noexcept {
  try {
    return get_components(uri_components::absolute_uri, uri_format::unescaped);
  } catch (...) {
    return "";
  }
}

string uri::format_componant(const string& str, uri_format format) {
  if (format == uri_format::safe_unescaped) return unescape_data_string(str);
  if (format == uri_format::unescaped) return unescape_data_string(str);
  return escape_uri_string(str);
}

string uri::format_host_componant(const string& str, uri_format format) {
  if (!xtd::string::is_empty(str)) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == false) return format_componant(str, format);
    if (address.address_family() == sockets::address_family::inter_network) return str;
    if (address.address_family() == sockets::address_family::inter_network_v6) return str;
  }
  return format_componant(str, format);
}

bool uri::need_to_escape_data_char(char character) {
  return !(char_object::is_letter_or_digit(character) || "!-_.~"_s.index_of(character) != string::npos);
}

bool uri::need_to_escape_uri_char(char character) {
  return !(char_object::is_letter_or_digit(character) || "!@#=?/:-_.~"_s.index_of(character) != string::npos);
}

void uri::set_fragment(string& escape_uri) {
  auto index_start = escape_uri.index_of('#') + 1;
  if (index_start == 0) index_start = escape_uri.length();
  if (index_start == string::npos) return;
  
  data_->fragment = escape_uri.substring(index_start, escape_uri.length() - index_start);
  if (index_start != escape_uri.length())
    escape_uri = escape_uri.remove(index_start - 1, escape_uri.length() - index_start + 1);
}

void uri::set_host(string& escape_uri) {
  if (!xtd::string::is_empty(escape_uri) && escape_uri[0] == '[') {
    auto index_start = escape_uri.index_of(']');
    if (index_start == string::npos) index_start = escape_uri.length();
    if (index_start != string::npos) {
      data_->host = escape_uri.remove(index_start + 1).to_lower();
      escape_uri = escape_uri.substring(index_start + 1);
    }
  } else {
    auto index_start = escape_uri.index_of_any({':', '/', '?', '#'});
    if (index_start == string::npos) index_start = escape_uri.length();
    if (index_start != string::npos) {
      data_->host = escape_uri.remove(index_start).to_lower();
      escape_uri = escape_uri.substring(index_start);
    }
  }
}

void uri::set_path(string& escape_uri) {
  auto index_start = escape_uri.index_of_any({'?', '#'});
  if (index_start != string::npos) {
    data_->path = escape_uri.remove(index_start);
    escape_uri = escape_uri.substring(index_start);
    return;
  }
  
  data_->path = xtd::string::is_empty(escape_uri) ? "/" : escape_uri;
  escape_uri = string::empty_string;
}

void uri::set_port(string& escape_uri) {
  try {
    auto index_start = escape_uri.index_of(':');
    if (index_start == string::npos) return;
    
    escape_uri = escape_uri.substring(1);
    index_start = escape_uri.index_of('/');
    if (index_start == string::npos) index_start = escape_uri.length();
    
    if (index_start == string::npos) return;
    
    data_->port = escape_uri.remove(index_start);
    parse<int32>(data_->port);
    
    escape_uri = escape_uri.substring(index_start);
  } catch (...) {
    throw_helper::throws(exception_case::uri_format);
  }
}

void uri::set_query(string& escape_uri) {
  auto index_start = escape_uri.index_of('?') + 1;
  if (index_start == 0) index_start = escape_uri.length();
  if (index_start == string::npos) return;
  
  data_->query = escape_uri.substring(index_start, escape_uri.length() - index_start);
  if (index_start != escape_uri.length())
    escape_uri = escape_uri.remove(index_start - 1, escape_uri.length() - index_start + 1);
}

void uri::set_scheme(string& escape_uri) {
  auto index_start = escape_uri.index_of(scheme_delimiter);
  if (index_start != string::npos)
    data_->scheme_delimiter = scheme_delimiter;
  else {
    index_start = escape_uri.index_of(':');
    if (index_start != string::npos)
      data_->scheme_delimiter = ":";
  }
  
  if (index_start != string::npos) {
    data_->scheme = escape_uri.remove(index_start).to_lower();
    escape_uri = escape_uri.substring(index_start + data_->scheme_delimiter.length());
  }
}

void uri::set_uri(const string& uri, uri_kind kind) {
  data_->original_uri = uri;
  data_->kind = kind;
  
  auto original_uri = data_->original_uri.trim(' ');
  
  set_scheme(original_uri);
  if (data_->scheme != "news") {
    set_user_info(original_uri);
    set_host(original_uri);
    set_port(original_uri);
  }
  set_path(original_uri);
  set_fragment(original_uri);
  set_query(original_uri);
  
  if (data_->kind == uri_kind::absolute) {
    if (data_->scheme.length() == 0) throw_helper::throws(exception_case::uri_format);
    if (data_->scheme != "news" && data_->host.length() == 0) throw_helper::throws(exception_case::uri_format);
    if (check_scheme_name(data_->scheme) == false) throw_helper::throws(exception_case::uri_format);
  } else if (data_->kind == uri_kind::relative) {
    if (data_->scheme.length() != 0 && data_->host.length() != 0) throw_helper::throws(exception_case::uri_format);
  }
  
  if (original_uri.length() != 0) throw_helper::throws(exception_case::uri_format);
}

void uri::set_user_info(string& escape_uri) {
  auto index_start = escape_uri.index_of('@');
  if (index_start != string::npos && index_start < escape_uri.index_of_any({'/', '?', '#'})) {
    data_->user_info = escape_uri.remove(index_start);
    if (index_start < escape_uri.length()) index_start++;
    escape_uri = escape_uri.substring(index_start);
  }
}
