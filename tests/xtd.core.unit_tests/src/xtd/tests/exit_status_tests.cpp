#include <xtd/exit_status>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(exit_status_tests) {
    auto test_method_(success) {
      assert::are_equal(0, enum_object<>::to_int32(exit_status::success));
      assert::are_equal("success", enum_object<>::to_string(exit_status::success));
      assert::are_equal(exit_status::success, enum_object<>::parse<exit_status>("success"));
    }
    
    auto test_method_(failure) {
      assert::are_equal(1, enum_object<>::to_int32(exit_status::failure));
      assert::are_equal("failure", enum_object<>::to_string(exit_status::failure));
      assert::are_equal(exit_status::failure, enum_object<>::parse<exit_status>("failure"));
    }
    
    auto test_method_(usage) {
      assert::are_equal(64, enum_object<>::to_int32(exit_status::usage));
      assert::are_equal("usage", enum_object<>::to_string(exit_status::usage));
      assert::are_equal(exit_status::usage, enum_object<>::parse<exit_status>("usage"));
    }
    
    auto test_method_(data_err) {
      assert::are_equal(65, enum_object<>::to_int32(exit_status::data_err));
      assert::are_equal("data_err", enum_object<>::to_string(exit_status::data_err));
      assert::are_equal(exit_status::data_err, enum_object<>::parse<exit_status>("data_err"));
    }
    
    auto test_method_(no_input) {
      assert::are_equal(66, enum_object<>::to_int32(exit_status::no_input));
      assert::are_equal("no_input", enum_object<>::to_string(exit_status::no_input));
      assert::are_equal(exit_status::no_input, enum_object<>::parse<exit_status>("no_input"));
    }
    
    auto test_method_(no_user) {
      assert::are_equal(67, enum_object<>::to_int32(exit_status::no_user));
      assert::are_equal("no_user", enum_object<>::to_string(exit_status::no_user));
      assert::are_equal(exit_status::no_user, enum_object<>::parse<exit_status>("no_user"));
    }
    
    auto test_method_(no_host) {
      assert::are_equal(68, enum_object<>::to_int32(exit_status::no_host));
      assert::are_equal("no_host", enum_object<>::to_string(exit_status::no_host));
      assert::are_equal(exit_status::no_host, enum_object<>::parse<exit_status>("no_host"));
    }
    
    auto test_method_(unavailable) {
      assert::are_equal(69, enum_object<>::to_int32(exit_status::unavailable));
      assert::are_equal("unavailable", enum_object<>::to_string(exit_status::unavailable));
      assert::are_equal(exit_status::unavailable, enum_object<>::parse<exit_status>("unavailable"));
    }
    
    auto test_method_(software) {
      assert::are_equal(70, enum_object<>::to_int32(exit_status::software));
      assert::are_equal("software", enum_object<>::to_string(exit_status::software));
      assert::are_equal(exit_status::software, enum_object<>::parse<exit_status>("software"));
    }
    
    auto test_method_(os_err) {
      assert::are_equal(71, enum_object<>::to_int32(exit_status::os_err));
      assert::are_equal("os_err", enum_object<>::to_string(exit_status::os_err));
      assert::are_equal(exit_status::os_err, enum_object<>::parse<exit_status>("os_err"));
    }
    
    auto test_method_(os_file) {
      assert::are_equal(72, enum_object<>::to_int32(exit_status::os_file));
      assert::are_equal("os_file", enum_object<>::to_string(exit_status::os_file));
      assert::are_equal(exit_status::os_file, enum_object<>::parse<exit_status>("os_file"));
    }
    
    auto test_method_(cant_create) {
      assert::are_equal(73, enum_object<>::to_int32(exit_status::cant_create));
      assert::are_equal("cant_create", enum_object<>::to_string(exit_status::cant_create));
      assert::are_equal(exit_status::cant_create, enum_object<>::parse<exit_status>("cant_create"));
    }
    
    auto test_method_(io_err) {
      assert::are_equal(74, enum_object<>::to_int32(exit_status::io_err));
      assert::are_equal("io_err", enum_object<>::to_string(exit_status::io_err));
      assert::are_equal(exit_status::io_err, enum_object<>::parse<exit_status>("io_err"));
    }
    
    auto test_method_(temp_fail) {
      assert::are_equal(75, enum_object<>::to_int32(exit_status::temp_fail));
      assert::are_equal("temp_fail", enum_object<>::to_string(exit_status::temp_fail));
      assert::are_equal(exit_status::temp_fail, enum_object<>::parse<exit_status>("temp_fail"));
    }
    
    auto test_method_(protocol) {
      assert::are_equal(76, enum_object<>::to_int32(exit_status::protocol));
      assert::are_equal("protocol", enum_object<>::to_string(exit_status::protocol));
      assert::are_equal(exit_status::protocol, enum_object<>::parse<exit_status>("protocol"));
    }
    
    auto test_method_(noperm) {
      assert::are_equal(77, enum_object<>::to_int32(exit_status::noperm));
      assert::are_equal("noperm", enum_object<>::to_string(exit_status::noperm));
      assert::are_equal(exit_status::noperm, enum_object<>::parse<exit_status>("noperm"));
    }
    
    auto test_method_(config) {
      assert::are_equal(78, enum_object<>::to_int32(exit_status::config));
      assert::are_equal("config", enum_object<>::to_string(exit_status::config));
      assert::are_equal(exit_status::config, enum_object<>::parse<exit_status>("config"));
    }
    
    auto test_method_(unknown_fatal) {
      assert::are_equal(125, enum_object<>::to_int32(exit_status::unknown_fatal));
      assert::are_equal("unknown_fatal", enum_object<>::to_string(exit_status::unknown_fatal));
      assert::are_equal(exit_status::unknown_fatal, enum_object<>::parse<exit_status>("unknown_fatal"));
    }
  };
}
