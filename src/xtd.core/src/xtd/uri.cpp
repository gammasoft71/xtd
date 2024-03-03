#include "../../include/xtd/uri.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/argument_out_of_range_exception.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/char_object.h"
#include "../../include/xtd/char32_object.h"
#include "../../include/xtd/invalid_operation_exception.h"
#include "../../include/xtd/uri_format_exception.h"
#include "../../include/xtd/uri_template_match_exception.h"
#include "../../include/xtd/io/path.h"
#include "../../include/xtd/net/ip_address.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::net;

uri::uri(const ustring& uri_string) {
  set_uri(uri_string, uri_kind::absolute);
}

uri::uri(const ustring& uri_string, uri_kind kind) {
  set_uri(uri_string, kind);
}

uri::uri(const uri& base_uri, const ustring& relative_uri) {
  set_uri(base_uri.original_uri_ + relative_uri, base_uri.kind_);
}

uri::uri(const uri& base_uri, const uri& relative_uri) {
  set_uri(base_uri.original_uri_ + relative_uri.original_uri_, base_uri.kind_);
}

ustring uri::absolute_path() const {
  return get_components(uri_components::path, uri_format::uri_escaped);
}

ustring uri::absolute_uri() {
  return get_components(uri_components::absolute_uri, uri_format::uri_escaped);
}

ustring uri::authority() const {
  return get_components(uri_components::user_info | uri_components::keep_delimiter, uri_format::uri_escaped) + get_components(uri_components::host | uri_components::keep_delimiter, uri_format::uri_escaped) + get_components(uri_components::port | uri_components::keep_delimiter, uri_format::uri_escaped);
}

ustring uri::dns_safe_host() const {
  auto str = host();
  if (!str.empty()) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == true && address.address_family() == sockets::address_family::inter_network_v6 && str[0] == '[' && str[str.size() - 1] == ']')
      return str.substring(1, str.size() - 2);
  }
  return get_components(uri_components::host, uri_format::safe_unescaped);
}

ustring uri::fragment() const {
  return get_components(uri_components::fragment | uri_components::keep_delimiter, uri_format::uri_escaped);
}

ustring uri::host() const {
  return get_components(uri_components::host, uri_format::unescaped);
}

uri_host_name_type uri::host_name_type() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  
  if (!host().empty()) {
    auto address = ip_address();
    if (ip_address::try_parse(host(), address) == false) return uri_host_name_type::dns;
    if (address.address_family() == sockets::address_family::inter_network) return uri_host_name_type::ip_v4;
    if (address.address_family() == sockets::address_family::inter_network_v6) return uri_host_name_type::ip_v6;
  }
  
  if (scheme() == uri::uri_scheme_mailto || scheme() == uri::uri_scheme_file) return uri_host_name_type::basic;
  
  return uri_host_name_type::unknown;
}

ustring uri::idn_host() const {
  auto str = host();
  if (!str.empty()) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == true && address.address_family() == sockets::address_family::inter_network_v6 && str[0] == '[' && str[str.size() - 1] == ']')
      return str.substring(1, str.size() - 2);
  }
  return get_components(uri_components::host, uri_format::safe_unescaped);
}

bool uri::is_absolute_uri() const {
  return kind_ == uri_kind::absolute;
}

bool uri::is_default_port() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  
  auto prt = -1;
  if (try_parse<int32>(get_components(uri_components::port, uri_format::uri_escaped), prt) == true) return false;
  return true;
}

bool uri::is_file() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  return scheme() == uri_scheme_file;
}

bool uri::is_loopback() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  if (!host().empty()) {
    auto address = ip_address();
    if (ip_address::try_parse(host(), address) == true && ip_address::is_loopback(address)) return true;
  }
  return host() == ip_address::loopback.to_string() || host() == ip_address::ip_v6_loopback.to_string() || host() == "loopback" || host() == "localhost" || host().empty();
}

bool uri::is_unc() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  return scheme() == uri::uri_scheme_file && !host().empty();
}

ustring uri::local_path() const {
  return get_components(uri_components::path, uri_format::unescaped).replace('/', path::directory_separator_char());
}

const ustring& uri::original_string() const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  return original_uri_;
}

ustring uri::path_and_query() const {
  return get_components(uri_components::path_and_query, uri_format::uri_escaped);
}

int32 uri::port() const {
  auto port = -1;
  if (try_parse<int32>(get_components(uri_components::port, uri_format::uri_escaped), port) == true) return port;
  if (scheme() == uri::uri_scheme_ftp) return 21;
  if (scheme() == uri::uri_scheme_gopher) return 70;
  if (scheme() == uri::uri_scheme_http) return 80;
  if (scheme() == uri::uri_scheme_https) return 443;
  if (scheme() == "ldap") return 389;
  if (scheme() == uri::uri_scheme_mailto) return 25;
  if (scheme() == uri::uri_scheme_nntp) return 119;
  return -1;
}

ustring uri::query() const {
  return get_components(uri_components::query | uri_components::keep_delimiter, uri_format::uri_escaped);
}

ustring uri::scheme() const {
  return get_components(uri_components::scheme, uri_format::uri_escaped);
}

vector<ustring> uri::segments() const {
  auto path = this->absolute_path();
  if (path.empty()) return {};
  
  auto segments = vector<ustring> {};
  auto start_index = 0_sz;
  auto length = 1_sz;
  
  if (path[start_index] == '/') {
    segments.push_back(path.substring(start_index, length));
    start_index += length;
  }
  
  while (start_index < path.size()) {
    length = path.index_of('/', start_index);
    if (length == ustring::npos) length = path.size() - start_index;
    
    segments.push_back(path.substring(start_index, length));
    start_index += length;
  }
  return segments;
}

ustring uri::user_info() const {
  return get_components(uri_components::user_info, uri_format::uri_escaped);
}

bool uri::check_scheme_name(const ustring& scheme) {
  auto first = true;
  for (auto c : as<u32string>(scheme)) {
    if (first) {
      first = false;
      if (!char32_object::is_letter(c)) return false;
    } else {
      if (!char32_object::is_letter_or_digit(c) && c != '.' && c != '+' && c != '-') return false;
    }
  }
  
  return !first;
}

ustring uri::escape_data_string(const ustring& value) {
  if (value.size() > 32766_sz) throw uri_format_exception {csf_};
  
  auto escape_needed = false;
  for (auto index = 0_sz; !escape_needed && index < value.size(); ++index)
    escape_needed = !is_hex_encoding(value, index) && need_to_escape_data_char(value[index]);
    
  if (escape_needed) {
    auto ret_value = ustring::empty_string;
    for (auto index = 0_sz; index < value.size(); ++index) {
      if (!is_hex_encoding(value, index) && need_to_escape_data_char(value[index])) ret_value += hex_escape(value[index]);
      else ret_value += value[index];
    }
    return ret_value;
  }
  
  return value;
}

ustring uri::escape_uri_string(const ustring& value) {
  if (value.size() > 32766_sz) throw uri_format_exception {csf_};
  
  auto escape_needed = false;
  for (auto index = 0_sz; !escape_needed && index < value.size(); ++index)
    escape_needed = !is_hex_encoding(value, index) && need_to_escape_uri_char(value[index]);
    
  if (escape_needed) {
    auto ret_value = ustring::empty_string;
    for (auto index = 0_sz; index < value.size(); ++index) {
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
  throw argument_exception {csf_};
}

ustring uri::get_components(uri_components components, uri_format format) const {
  if (kind_ != uri_kind::absolute) throw invalid_operation_exception {csf_};
  
  auto str = ustring::empty_string;
  if ((components & uri_components::scheme) == uri_components::scheme) str += format_componant(scheme_, format);
  if ((components & uri_components::scheme) == uri_components::scheme && (components & ~uri_components::scheme) != uri_components::none) str += format_componant(scheme_delimiter_, format);
  if ((components & uri_components::user_info) == uri_components::user_info) str += format_componant(user_info_, format);
  if ((components & uri_components::user_info) == uri_components::user_info && user_info_.size() && (components & ~uri_components::user_info) != uri_components::none) str += format_componant("@", format);
  if ((components & uri_components::host) == uri_components::host) str += format_host_componant(host_, format);
  if ((components & uri_components::port) == uri_components::port && port_.size() && (components & ~uri_components::port) != uri_components::none) str += format_componant(":", format);
  if ((components & uri_components::port) == uri_components::port) str += format_componant(port_, format);
  if ((components & uri_components::path) == uri_components::path) str += format_componant(path_, format);
  if ((components & uri_components::query) == uri_components::query && query_.size() && (components & ~uri_components::query) != uri_components::none) str += format_componant("?", format);
  if ((components & uri_components::query) == uri_components::query) str += format_componant(query_, format);
  if ((components & uri_components::fragment) == uri_components::fragment && fragment_.size() && (components & ~uri_components::fragment) != uri_components::none) str += format_componant("#", format);
  if ((components & uri_components::fragment) == uri_components::fragment) str += format_componant(fragment_, format);
  if ((components & uri_components::strong_port) == uri_components::strong_port && (components & ~uri_components::strong_port) != uri_components::none) str += format_componant(":", format);
  if ((components & uri_components::strong_port) == uri_components::strong_port) str += format_componant(ustring::format("{}", port()), format);
  
  return str;
}

ustring uri::get_left_part(uri_partial part) const {
  switch (part) {
    case uri_partial::scheme: return get_components(uri_components::scheme | uri_components::keep_delimiter, uri_format::uri_escaped);
    case uri_partial::authority: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port, uri_format::uri_escaped);
    case uri_partial::path: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port | uri_components::path, uri_format::uri_escaped);
    case uri_partial::query: return get_components(uri_components::scheme | uri_components::user_info | uri_components::host | uri_components::port | uri_components::path_and_query, uri_format::uri_escaped);
    default: break;
  }
  throw argument_exception {csf_};
}

ustring uri::hex_escape(char character) {
  return ustring::format("%{:X2}", convert::to_int32(character));
}

char uri::hex_unescape(const ustring& pattern, size_t& index) {
  index += 3;
  return as<char>(parse<int32>(pattern.substring(index - 2, 2), number_styles::hex_number));
}

bool uri::is_base_of(const uri& uri) const {
  auto path = path_.remove(path_.size() - 1).last_index_of('/') == ustring::npos ? path_ : path_.remove(path_.remove(path_.size() - 1).last_index_of('/'));
  auto uri_path = uri.path_.remove(uri.path_.size() - 1).last_index_of('/') == ustring::npos ? uri.path_ : uri.path_.remove(uri.path_.remove(uri.path_.size() - 1).last_index_of('/'));
  
  return scheme_ == uri.scheme_ && scheme_delimiter_ == uri.scheme_delimiter_ && host_ == uri.host_ && port_ == uri.port_ && path == uri_path;
}

bool uri::is_hex_digit(char character) {
  return (character >= '0' && character <= '9') || (character >= 'A' && character <= 'F') || (character >= 'a' && character <= 'f');
}

bool uri::is_hex_encoding(const ustring& pattern, size_t index) {
  if (pattern.size() < index + 3)  return false;
  
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
  
  for (auto index = 0_sz; !well_formated_original_string && index < original_uri_.size(); ++index)
    well_formated_original_string = !(is_hex_encoding(original_uri_, index) || need_to_escape_uri_char(original_uri_[index]));
    
  if (well_formated_original_string == true) well_formated_original_string = path::is_path_rooted(original_uri_);
  if (well_formated_original_string == true) well_formated_original_string = original_uri_.index_of('\\') != ustring::npos;
  if (well_formated_original_string == true) well_formated_original_string = !(scheme_delimiter_.size() == 0 && host_.size() != 0);
  if (well_formated_original_string == true) well_formated_original_string = check_scheme_name(scheme_);
  
  return well_formated_original_string;
}

bool uri::is_well_formed_uri_string(const ustring& uri_string, uri_kind uri_kind) {
  auto well_formed_uri_string = true;
  
  try {
    auto uri_value = uri(uri_string, uri_kind);
    well_formed_uri_string = uri_value.is_well_formed_original_string();
  } catch (...) {
    well_formed_uri_string = false;
  }
  
  return well_formed_uri_string;
}

ustring uri::unescape_data_string(const ustring& value) {
  // See http://www.geekhideout.com/urlcode.shtml
  auto unescape_needed = false;
  for (auto index = 0_sz; !unescape_needed && index < value.size(); ++index)
    unescape_needed = is_hex_encoding(value, index);
    
  if (!unescape_needed) return value;
  
  auto ret_value = ustring::empty_string;
  auto index = 0_sz;
  while (index < value.size()) {
    if (is_hex_encoding(value, index))
      ret_value += ustring::format("{}", hex_unescape(value, index));
    else
      ret_value += value[index++];
  }
  return ret_value;
}

bool uri::equals(const uri& uri) const noexcept {
  return scheme_ == uri.scheme_ && scheme_delimiter_ == uri.scheme_delimiter_ && host_ == uri.host_ && port_ == uri.port_ && path_ == uri.path_ && query_ == uri.query_ && kind_ == uri.kind_;
}

ustring uri::to_string() const noexcept {
  try {
    return get_components(uri_components::absolute_uri, uri_format::unescaped);
  } catch (...) {
    return "";
  }
}

ustring uri::format_componant(const ustring& str, uri_format format) {
  if (format == uri_format::safe_unescaped) return unescape_data_string(str);
  if (format == uri_format::unescaped) return unescape_data_string(str);
  return escape_uri_string(str);
}

ustring uri::format_host_componant(const ustring& str, uri_format format) {
  if (!str.empty()) {
    auto address = ip_address();
    if (ip_address::try_parse(str, address) == false) return format_componant(str, format);
    if (address.address_family() == sockets::address_family::inter_network) return str;
    if (address.address_family() == sockets::address_family::inter_network_v6) return str;
  }
  return format_componant(str, format);
}

bool uri::need_to_escape_data_char(char character) {
  return !(char_object::is_letter_or_digit(character) || "!-_.~"_s.index_of(character) != ustring::npos);
}

bool uri::need_to_escape_uri_char(char character) {
  return !(char_object::is_letter_or_digit(character) || "!@#=?/:-_.~"_s.index_of(character) != ustring::npos);
}

void uri::set_fragment(ustring& escape_uri) {
  auto index_start = escape_uri.index_of('#') + 1;
  if (index_start == 0) index_start = escape_uri.size();
  if (index_start == ustring::npos) return;
  
  fragment_ = escape_uri.substring(index_start, escape_uri.size() - index_start);
  if (index_start != escape_uri.size())
    escape_uri = escape_uri.remove(index_start - 1, escape_uri.size() - index_start + 1);
}

void uri::set_host(ustring& escape_uri) {
  if (!escape_uri.empty() && escape_uri[0] == '[') {
    auto index_start = escape_uri.index_of(']');
    if (index_start == ustring::npos) index_start = escape_uri.size();
    if (index_start != ustring::npos) {
      host_ = escape_uri.remove(index_start + 1).to_lower();
      escape_uri = escape_uri.substring(index_start  + 1);
    }
  } else {
    auto index_start = escape_uri.index_of_any({':', '/', '?', '#'});
    if (index_start == ustring::npos) index_start = escape_uri.size();
    if (index_start != ustring::npos) {
      host_ = escape_uri.remove(index_start).to_lower();
      escape_uri = escape_uri.substring(index_start);
    }
  }
}

void uri::set_path(ustring& escape_uri) {
  auto index_start = escape_uri.index_of_any({'?', '#'});
  if (index_start != ustring::npos) {
    path_ = escape_uri.remove(index_start);
    escape_uri = escape_uri.substring(index_start);
    return;
  }
  
  path_ = escape_uri.empty() ? "/" : escape_uri;
  escape_uri = ustring::empty_string;
}

void uri::set_port(ustring& escape_uri) {
  try {
    auto index_start = escape_uri.index_of(':');
    if (index_start == ustring::npos) return;
    
    escape_uri = escape_uri.substring(1);
    index_start = escape_uri.index_of('/');
    if (index_start == ustring::npos) index_start = escape_uri.size();
    
    if (index_start == ustring::npos) return;
    
    port_ = escape_uri.remove(index_start);
    parse<int32>(port_);
    
    escape_uri = escape_uri.substring(index_start);
  } catch (...) {
    throw uri_format_exception {csf_};
  }
}

void uri::set_query(ustring& escape_uri) {
  auto index_start = escape_uri.index_of('?') + 1;
  if (index_start == 0) index_start = escape_uri.size();
  if (index_start == ustring::npos) return;
  
  query_ = escape_uri.substring(index_start, escape_uri.size() - index_start);
  if (index_start != escape_uri.size())
    escape_uri = escape_uri.remove(index_start - 1, escape_uri.size() - index_start + 1);
}

void uri::set_scheme(ustring& escape_uri) {
  auto index_start = escape_uri.index_of(scheme_delimiter);
  if (index_start != ustring::npos)
    scheme_delimiter_ = scheme_delimiter;
  else {
    index_start = escape_uri.index_of(':');
    if (index_start != ustring::npos)
      scheme_delimiter_ = ":";
  }
  
  if (index_start != ustring::npos) {
    scheme_ = escape_uri.remove(index_start).to_lower();
    escape_uri = escape_uri.substring(index_start + scheme_delimiter_.size());
  }
}

void uri::set_uri(const ustring& uri, uri_kind kind) {
  original_uri_ = uri;
  kind_ = kind;
  
  auto original_uri = original_uri_.trim(' ');
  
  set_scheme(original_uri);
  if (scheme_ != "news") {
    set_user_info(original_uri);
    set_host(original_uri);
    set_port(original_uri);
  }
  set_path(original_uri);
  set_fragment(original_uri);
  set_query(original_uri);
  
  if (kind_ == uri_kind::absolute) {
    if (scheme_.size() == 0) throw uri_format_exception {csf_};
    if (scheme_ != "news" && host_.size() == 0) throw uri_format_exception {csf_};
    if (check_scheme_name(scheme_) == false) throw uri_format_exception {csf_};
  } else if (kind_ == uri_kind::relative) {
    if (scheme_.size() != 0 && host_.size() != 0) throw uri_format_exception {csf_};
  }
  
  if (original_uri.size() != 0) throw uri_format_exception {csf_};
}

void uri::set_user_info(ustring& escape_uri) {
  auto index_start = escape_uri.index_of('@');
  if (index_start != ustring::npos && index_start < escape_uri.index_of_any({'/', '?', '#'})) {
    user_info_ = escape_uri.remove(index_start);
    if (index_start < escape_uri.size()) index_start++;
    escape_uri = escape_uri.substring(index_start);
  }
}
