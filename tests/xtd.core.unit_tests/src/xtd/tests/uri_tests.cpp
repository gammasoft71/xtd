#include <sstream>
#include <xtd/uri>
#include <xtd/uri_format_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace std;
using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(uri_tests) {
  public:
    void test_method_(constructor_with_absolute_uri) {
      assert::does_not_throw([] {uri("http://www.contoso.com");}, csf_);
    }
    
    void test_method_(constructor_with_absolute_uri_and_uri_kind_relative_or_absolute_specified) {
      assert::does_not_throw([] {uri("http://www.contoso.com", uri_kind::relative_or_absolute);}, csf_);
    }
    
    void test_method_(constructor_with_absolute_uri_and_uri_kind_absolute_specified) {
      assert::does_not_throw([] {uri("http://www.contoso.com", uri_kind::absolute);}, csf_);
    }
    
    void test_method_(constructor_with_absolute_uri_and_uri_kind_relative_specified) {
      assert::throws<uri_format_exception>([] {uri("http://www.contoso.com", uri_kind::relative);}, csf_);
    }
    
    void test_method_(constructor_with_relativeUri) {
      assert::throws<uri_format_exception>([] {uri("www.contoso.com");}, csf_);
    }
    
    void test_method_(constructor_with_relative_uri_and_uri_kind_relative_or_absolute_specified) {
      assert::does_not_throw([] {uri("www.contoso.com", uri_kind::relative_or_absolute);}, csf_);
    }
    
    void test_method_(constructor_with_relative_uri_and_uri_kind_absolute_specified) {
      assert::throws<uri_format_exception>([] {uri("www.contoso.com", uri_kind::absolute);}, csf_);
    }
    
    void test_method_(constructor_with_relative_uri_and_uri_kind_relative_specified) {
      assert::does_not_throw([] {uri("www.contoso.com", uri_kind::relative);}, csf_);
    }
    
    void test_method_(constructor_with_invalid_uri) {
      assert::throws<uri_format_exception>([] {uri("://www.contoso.com");}, csf_);
    }
    
    void test_method_(constructor) {
      assert::is_true(uri("http://www.contoso.com").is_absolute_uri(), csf_);
      assert::is_true(uri("http://www.contoso.com", uri_kind::absolute).is_absolute_uri(), csf_);
      assert::is_false(uri("www.contoso.com", uri_kind::relative).is_absolute_uri(), csf_);
      assert::is_false(uri("www.contoso.com", uri_kind::relative_or_absolute).is_absolute_uri(), csf_);
      assert::is_false(uri("http://www.contoso.com", uri_kind::relative_or_absolute).is_absolute_uri(), csf_);
      assert::is_true(uri(uri("http://www.contoso.com"), "/path/file.ext").is_absolute_uri(), csf_);
      assert::is_true(uri(uri("http://www.contoso.com"), uri("/path/file.ext", uri_kind::relative)).is_absolute_uri(), csf_);
    }
    
    void test_method_(check_scheme_name) {
      assert::is_true(uri::check_scheme_name("http"), csf_);
      assert::is_true(uri::check_scheme_name("news"), csf_);
      assert::is_true(uri::check_scheme_name("file"), csf_);
      assert::is_true(uri::check_scheme_name("f+ile"), csf_);
      assert::is_true(uri::check_scheme_name("fi-le"), csf_);
      assert::is_true(uri::check_scheme_name("fil.e"), csf_);
      
      assert::is_false(uri::check_scheme_name(""), csf_);
      assert::is_false(uri::check_scheme_name("!file"), csf_);
      assert::is_false(uri::check_scheme_name("f=ile"), csf_);
      assert::is_false(uri::check_scheme_name("fi le"), csf_);
      assert::is_false(uri::check_scheme_name("file*"), csf_);
    }
    
    void test_method_(escape_data_string) {
      assert::are_equal("%20abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20%3D%3F%3A%23%40!", uri::escape_data_string("%20abc123XYZ<>%\"{}|\\^`[] =?:#@!"), csf_);
    }
    
    void test_method_(escape_uri_string) {
      assert::are_equal("%20abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20=?:#@!", uri::escape_uri_string("%20abc123XYZ<>%\"{}|\\^`[] =?:#@!"), csf_);
    }
    
    void test_method_(authority) {
      assert::are_equal("yfi:MyPass@www.contoso.com:8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").authority(), "yfi:MyPass@www.contoso.com:8080", csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm?date=today").authority(), csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm#main").authority(), csf_);
      assert::are_equal("user@contoso.com", uri("mailto:user@contoso.com?subject=uri").authority(), csf_);
      assert::are_equal("news.contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").authority(), csf_);
      assert::is_empty(uri("news:123456@contoso.com").authority(), csf_);
      assert::are_equal("server", uri("file://server/filename.ext").authority(), csf_);
    }
    
    void test_method_(absolute_path) {
      assert::are_equal("/C:a%20ta%20log/ShowNew.htm", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").absolute_path(), csf_);
      assert::are_equal("/index.htm", uri("http://www.contoso.com/index.htm?date=today").absolute_path(), csf_);
      assert::are_equal("/index.htm", uri("http://www.contoso.com/index.htm#main").absolute_path(), csf_);
      assert::is_empty(uri("mailto:user@contoso.com?subject=uri").absolute_path(), csf_);
      assert::are_equal("/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").absolute_path(), csf_);
      assert::are_equal("123456@contoso.com", uri("news:123456@contoso.com").absolute_path(), csf_);
      assert::are_equal("/filename.ext", uri("file://server/filename.ext").absolute_path(), csf_);
    }
    
    void test_method_(absolute_uri) {
      assert::are_equal("http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm?Date=ToDay#bOdy", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").absolute_uri(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm?date=today", uri("http://www.contoso.com/index.htm?date=today").absolute_uri(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm#main", uri("http://www.contoso.com/index.htm#main").absolute_uri(), csf_);
      assert::are_equal("mailto:user@contoso.com?subject=uri", uri("mailto:user@contoso.com?subject=uri").absolute_uri(), csf_);
      assert::are_equal("nntp://news.contoso.com/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").absolute_uri(), csf_);
      assert::are_equal("news:123456@contoso.com", uri("news:123456@contoso.com").absolute_uri(), csf_);
      assert::are_equal("file://server/filename.ext", uri("file://server/filename.ext").absolute_uri(), csf_);
    }
    
    void test_method_(get_components) {
      assert::are_equal("www.contoso.com", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_components(uri_components::host, uri_format::safe_unescaped), "www.contoso.com", csf_);
      assert::are_equal("8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_components(uri_components::port, uri_format::safe_unescaped), csf_);
      assert::are_equal(":8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_components(uri_components::port | uri_components::keep_delimiter, uri_format::safe_unescaped), csf_);
      assert::are_equal("www.contoso.com:8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_components(uri_components::host | uri_components::port, uri_format::safe_unescaped), csf_);
      assert::are_equal("www.contoso.com:8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_components(uri_components::host_and_port, uri_format::safe_unescaped), csf_);
    }
    
    void test_method_(dns_safe_host) {
      assert::are_equal("www.contoso.com", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").dns_safe_host(), csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm?date=today").dns_safe_host(), csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm#main").dns_safe_host(), csf_);
      assert::are_equal("contoso.com", uri("mailto:user@contoso.com?subject=uri").dns_safe_host(), csf_);
      assert::are_equal("news.contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").dns_safe_host(), csf_);
      assert::is_empty(uri("news:123456@contoso.com").dns_safe_host(), csf_);
      assert::are_equal("server", uri("file://server/filename.ext").dns_safe_host(), csf_);
    }
    
    void test_method_(fragment) {
      assert::are_equal("#bOdy", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").fragment(), csf_);
      assert::is_empty(uri("http://www.contoso.com/index.htm?date=today").fragment(), csf_);
      assert::are_equal("#main", uri("http://www.contoso.com/index.htm#main").fragment(), csf_);
      assert::is_empty(uri("mailto:user@contoso.com?subject=uri").fragment(), csf_);
      assert::is_empty(uri("nntp://news.contoso.com/123456@contoso.com").fragment(), csf_);
      assert::is_empty(uri("news:123456@contoso.com").fragment(), csf_);
      assert::is_empty(uri("file://server/filename.ext").fragment(), csf_);
    }
    
    void test_method_(host) {
      assert::are_equal("www.contoso.com", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").host(), csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm?date=today").host(), csf_);
      assert::are_equal("www.contoso.com", uri("http://www.contoso.com/index.htm#main").host(), csf_);
      assert::are_equal("contoso.com", uri("mailto:user@contoso.com?subject=uri").host(), csf_);
      assert::are_equal("news.contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").host(), csf_);
      assert::is_empty(uri("news:123456@contoso.com").host(), csf_);
      assert::are_equal("server", uri("file://server/filename.ext").host(), csf_);
      assert::are_equal("172.16.10.30", uri("file://172.16.10.30/filename.ext").host(), csf_);
      assert::are_equal("[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]", uri("file://[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]/filename.ext").host(), csf_);
    }
    
    void test_method_(host_name_type) {
      assert::are_equal(uri_host_name_type::dns, uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::dns, uri("http://www.contoso.com/index.htm?date=today").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::dns, uri("http://www.contoso.com/index.htm#main").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::dns, uri("mailto:user@contoso.com?subject=uri").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::dns, uri("nntp://news.contoso.com/123456@contoso.com").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::unknown, uri("news:123456@contoso.com").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::dns, uri("file://server/filename.ext").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::ip_v4, uri("file://172.16.10.30/filename.ext").host_name_type(), csf_);
      assert::are_equal(uri_host_name_type::ip_v6, uri("file://[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]/filename.ext").host_name_type(), csf_);
    }
    
    void test_method_(get_left_part) {
      assert::are_equal("http://", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("http://yfi:MyPass@www.contoso.com:8080", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_left_part(uri_partial::path), csf_);
      assert::are_equal("http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm?Date=ToDay", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("http://", uri("http://www.contoso.com/index.htm?date=today").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("http://www.contoso.com", uri("http://www.contoso.com/index.htm?date=today").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("http://www.contoso.com/index.htm", uri("http://www.contoso.com/index.htm?date=today").get_left_part(uri_partial::path), csf_);
      assert::are_equal("http://www.contoso.com/index.htm?date=today", uri("http://www.contoso.com/index.htm?date=today").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("http://", uri("http://www.contoso.com/index.htm#main").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("http://www.contoso.com", uri("http://www.contoso.com/index.htm#main").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("http://www.contoso.com/index.htm", uri("http://www.contoso.com/index.htm#main").get_left_part(uri_partial::path), csf_);
      assert::are_equal("http://www.contoso.com/index.htm", uri("http://www.contoso.com/index.htm#main").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("mailto:", uri("mailto:user@contoso.com?subject=uri").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("mailto:user@contoso.com", uri("mailto:user@contoso.com?subject=uri").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("mailto:user@contoso.com", uri("mailto:user@contoso.com?subject=uri").get_left_part(uri_partial::path), csf_);
      assert::are_equal("mailto:user@contoso.com?subject=uri", uri("mailto:user@contoso.com?subject=uri").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("nntp://", uri("nntp://news.contoso.com/123456@contoso.com").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("nntp://news.contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("nntp://news.contoso.com/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").get_left_part(uri_partial::path), csf_);
      assert::are_equal("nntp://news.contoso.com/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("news:", uri("news:123456@contoso.com").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("news:", uri("news:123456@contoso.com").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("news:123456@contoso.com", uri("news:123456@contoso.com").get_left_part(uri_partial::path), csf_);
      assert::are_equal("news:123456@contoso.com", uri("news:123456@contoso.com").get_left_part(uri_partial::query), csf_);
      
      assert::are_equal("file://", uri("file://server/filename.ext").get_left_part(uri_partial::scheme), csf_);
      assert::are_equal("file://server", uri("file://server/filename.ext").get_left_part(uri_partial::authority), csf_);
      assert::are_equal("file://server/filename.ext", uri("file://server/filename.ext").get_left_part(uri_partial::path), csf_);
      assert::are_equal("file://server/filename.ext", uri("file://server/filename.ext").get_left_part(uri_partial::query), csf_);
    }
    
    void test_method_(local_path) {
      assert::are_equal(path::directory_separator_char() + "C:a ta log"_s + io::path::directory_separator_char() + "ShowNew.htm"_s, uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").local_path(), csf_);
      assert::are_equal(path::directory_separator_char() + "index.htm"_s, uri("http://www.contoso.com/index.htm?date=today").local_path(), csf_);
      assert::are_equal(path::directory_separator_char() + "index.htm"_s, uri("http://www.contoso.com/index.htm#main").local_path(), csf_);
      assert::is_empty(uri("mailto:user@contoso.com?subject=uri").local_path(), csf_);
      assert::are_equal(path::directory_separator_char() + "123456@contoso.com"_s, uri("nntp://news.contoso.com/123456@contoso.com").local_path(), csf_);
      assert::are_equal("123456@contoso.com", uri("news:123456@contoso.com").local_path(), csf_);
      assert::are_equal(path::directory_separator_char() + "filename.ext"_s, uri("file://server/filename.ext").local_path(), csf_);
    }
    
    void test_method_(original_string) {
      assert::are_equal("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").original_string(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm?date=today", uri("http://www.contoso.com/index.htm?date=today").original_string(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm#main", uri("http://www.contoso.com/index.htm#main").original_string(), csf_);
      assert::are_equal("mailto:user@contoso.com?subject=uri", uri("mailto:user@contoso.com?subject=uri").original_string(), csf_);
      assert::are_equal("nntp://news.contoso.com/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").original_string(), csf_);
      assert::are_equal("news:123456@contoso.com", uri("news:123456@contoso.com").original_string(), csf_);
      assert::are_equal("file://server/filename.ext", uri("file://server/filename.ext").original_string(), csf_);
    }
    
    void test_method_(path_and_query) {
      assert::are_equal("/C:a%20ta%20log/ShowNew.htm?Date=ToDay", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").path_and_query(), csf_);
      assert::are_equal("/index.htm?date=today", uri("http://www.contoso.com/index.htm?date=today").path_and_query(), csf_);
      assert::are_equal("/index.htm", uri("http://www.contoso.com/index.htm#main").path_and_query(), csf_);
      assert::are_equal("?subject=uri", uri("mailto:user@contoso.com?subject=uri").path_and_query(), csf_);
      assert::are_equal("/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").path_and_query(), csf_);
      assert::are_equal("123456@contoso.com", uri("news:123456@contoso.com").path_and_query(), csf_);
      assert::are_equal("/filename.ext", uri("file://server/filename.ext").path_and_query(), csf_);
    }
    
    void test_method_(port) {
      assert::are_equal(8080, uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").port(), csf_);
      assert::are_equal(80, uri("http://www.contoso.com/index.htm?date=today").port(), csf_);
      assert::are_equal(80, uri("http://www.contoso.com/index.htm#main").port(), csf_);
      assert::are_equal(443, uri("https://www.contoso.com/index.htm#main").port(), csf_);
      assert::are_equal(21, uri("ftp://www.contoso.com/index.htm").port(), csf_);
      assert::are_equal(25, uri("mailto:user@contoso.com?subject=uri").port(), csf_);
      assert::are_equal(119, uri("nntp://news.contoso.com/123456@contoso.com").port(), csf_);
      assert::are_equal(-1, uri("news:123456@contoso.com").port(), csf_);
      assert::are_equal(-1, uri("file://server/filename.ext").port(), csf_);
    }
    
    void test_method_(query) {
      assert::are_equal(uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").query(), "?Date=ToDay", csf_);
      assert::are_equal(uri("http://www.contoso.com/index.htm?date=today").query(), "?date=today", csf_);
      assert::is_empty(uri("http://www.contoso.com/index.htm#main").query(), csf_);
      assert::are_equal(uri("mailto:user@contoso.com?subject=uri").query(), "?subject=uri", csf_);
      assert::is_empty(uri("nntp://news.contoso.com/123456@contoso.com").query(), csf_);
      assert::is_empty(uri("news:123456@contoso.com").query(), csf_);
      assert::is_empty(uri("file://server/filename.ext").query(), csf_);
    }
    
    void test_method_(scheme) {
      assert::are_equal("http", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").scheme(), csf_);
      assert::are_equal("http", uri("http://www.contoso.com/index.htm?date=today").scheme(), csf_);
      assert::are_equal("http", uri("http://www.contoso.com/index.htm#main").scheme(), csf_);
      assert::are_equal("mailto", uri("mailto:user@contoso.com?subject=uri").scheme(), csf_);
      assert::are_equal("nntp", uri("nntp://news.contoso.com/123456@contoso.com").scheme(), csf_);
      assert::are_equal("news", uri("news:123456@contoso.com").scheme(), csf_);
      assert::are_equal("file", uri("file://server/filename.ext").scheme(), csf_);
    }
    
    void test_method_(segments) {
      auto segments = uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").segments();
      assert::are_equal(3_sz, segments.size(), csf_);
      assert::are_equal("/", segments[0], csf_);
      assert::are_equal("C:a%20ta%20log/", segments[1], csf_);
      assert::are_equal("ShowNew.htm", segments[2], csf_);
      
      segments = uri("http://www.contoso.com/index.htm?date=today").segments();
      assert::are_equal(2_sz, segments.size(), csf_);
      assert::are_equal("/", segments[0], csf_);
      assert::are_equal("index.htm", segments[1], csf_);
      
      segments = uri("http://www.contoso.com/index.htm#main").segments();
      assert::are_equal(2_sz, segments.size(), csf_);
      assert::are_equal("/", segments[0], csf_);
      assert::are_equal("index.htm", segments[1], csf_);
      
      segments = uri("mailto:user@contoso.com?subject=uri").segments();
      assert::are_equal(0ul, segments.size(), csf_);
      
      segments = uri("nntp://news.contoso.com/123456@contoso.com").segments();
      assert::are_equal(2_sz, segments.size(), csf_);
      assert::are_equal("/", segments[0], csf_);
      assert::are_equal("123456@contoso.com", segments[1], csf_);
      
      segments = uri("news:123456@contoso.com").segments();
      assert::are_equal(1_sz, segments.size(), csf_);
      assert::are_equal("123456@contoso.com", segments[0], csf_);
      
      segments = uri("file://server/filename.ext").segments();
      assert::are_equal(2_sz, segments.size(), csf_);
      assert::are_equal("/", segments[0], csf_);
      assert::are_equal("filename.ext", segments[1], csf_);
    }
    
    void test_method_(user_info) {
      assert::are_equal("yfi:MyPass", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").user_info(), csf_);
      assert::is_empty(uri("http://www.contoso.com/index.htm?date=today").user_info(), csf_);
      assert::are_equal("1234567890", uri("http://1234567890@www.contoso.com/index.htm?date=today").user_info(), csf_);
    }
    
    void test_method_(hex_unescape) {
      size_t index = 0_sz;
      assert::are_equal('<', uri::hex_unescape("%3c", index), csf_);
      assert::are_equal(3_sz, index, csf_);
    }
    
    void test_method_(is_base_of) {
      assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/file/")), csf_);
      /*
       assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/#fragment")), csf_);
       assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/MoreDir/\"")), csf_);
       assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/OtherFile?Query")), csf_);
       assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/")), csf_);
       assert::is_true(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path/file")), csf_);
      
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path")), csf_);
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path?query")), csf_);
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path#fragment")), csf_);
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path2/")), csf_);
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/path2/MoreDir")), csf_);
       assert::is_false(uri("http://host/path/path/file?query").is_base_of(uri("http://host/path/File")), csf_);
       */
    }
    
    void test_method_(is_default_port) {
      assert::is_false(uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").is_default_port(), csf_);
      assert::is_true(uri("http://www.contoso.com/index.htm?date=today").is_default_port(), csf_);
      assert::is_false(uri("http://www.contoso.com:80/index.htm#main").is_default_port(), csf_);
      assert::is_true(uri("mailto:user@contoso.com?subject=uri").is_default_port(), csf_);
      assert::is_false(uri("nntp://news.contoso.com:119/123456@contoso.com").is_default_port(), csf_);
      assert::is_true(uri("news:123456@contoso.com").is_default_port(), csf_);
      assert::is_true(uri("file://server/filename.ext").is_default_port(), csf_);
    }
    
    void test_method_(is_file) {
      assert::is_false(uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").is_file());
      assert::is_false(uri("http://www.contoso.com/index.htm?date=today").is_file(), csf_);
      assert::is_false(uri("http://www.contoso.com/index.htm#main").is_file(), csf_);
      assert::is_false(uri("mailto:user@contoso.com?subject=uri").is_file(), csf_);
      assert::is_false(uri("nntp://news.contoso.com/123456@contoso.com").is_file(), csf_);
      assert::is_false(uri("news:123456@contoso.com").is_file(), csf_);
      assert::is_true(uri("file://server/filename.ext").is_file());
    }
    
    void test_method_(is_loopback) {
      assert::is_false(uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").is_loopback(), csf_);
      assert::is_false(uri("http://www.contoso.com/index.htm?date=today").is_loopback(), csf_);
      assert::is_false(uri("http://www.contoso.com/index.htm#main").is_loopback(), csf_);
      assert::is_false(uri("mailto:user@contoso.com?subject=uri").is_loopback(), csf_);
      assert::is_false(uri("nntp://news.contoso.com/123456@contoso.com").is_loopback(), csf_);
      assert::is_true(uri("news:123456@contoso.com").is_loopback(), csf_);
      assert::is_false(uri("file://server/filename.ext").is_loopback(), csf_);
      assert::is_true(uri("file://127.0.0.1/filename.ext").is_loopback(), csf_);
      assert::is_true(uri("file://[00:00:00:00:00:00:00:01]/filename.ext").is_loopback(), csf_);
      assert::is_true(uri("file://loopback/filename.ext").is_loopback(), csf_);
      assert::is_true(uri("file://localhost/filename.ext").is_loopback(), csf_);
    }
    
    void test_method_(to_string) {
      assert::are_equal("http://yfi:MyPass@www.contoso.com:8080/C:a ta log/ShowNew.htm?Date=ToDay#bOdy", uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").to_string(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm?date=today", uri("http://www.contoso.com/index.htm?date=today").to_string(), csf_);
      assert::are_equal("http://www.contoso.com/index.htm#main", uri("http://www.contoso.com/index.htm#main").to_string(), csf_);
      assert::are_equal("mailto:user@contoso.com?subject=uri", uri("mailto:user@contoso.com?subject=uri").to_string(), csf_);
      assert::are_equal("nntp://news.contoso.com/123456@contoso.com", uri("nntp://news.contoso.com/123456@contoso.com").to_string(), csf_);
      assert::are_equal("news:123456@contoso.com", uri("news:123456@contoso.com").to_string(), csf_);
      assert::are_equal("file://server/filename.ext", uri("file://server/filename.ext").to_string(), csf_);
    }
    
    void test_method_(unescape_data_string) {
      assert::are_equal("abc123XYZ<>%\"{}|\\^`[] =?:#@!", uri::unescape_data_string("abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20%3D%3F%3A%23%40!"), csf_);
      assert::are_equal("abc123XYZ<>%\"{}|\\^`[] =?:#@!", uri::unescape_data_string("abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20=?:#@!"), csf_);
    }
  };
}
