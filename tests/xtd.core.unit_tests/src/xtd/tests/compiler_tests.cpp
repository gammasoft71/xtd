#include <xtd/argument_exception>
#include <xtd/compiler_id>
#include <xtd/compiler>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(compiler_tests) {
    auto test_method_(create_compiler_with_default_ctor) {
      compiler c;
      assert::are_equal(build_type::debug, c.build_type());
      assert::are_equal(compiler_id::unknown, c.compiler_id());
      assert::is_false(c.is_64_bit());
      assert::is_true(c.is_build_type_debug());
      assert::are_equal("<unknown>", c.name());
      assert::are_equal(version {}, c.version());
      assert::are_equal("<unknown> 0.0", c.version_string());
      assert::are_equal("<unknown> 0.0", c.to_string());
    }
    
    auto test_method_(create_compiler_with_compiler_id_unknown_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::unknown, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::unknown, c.compiler_id());
      assert::is_true(c.is_64_bit());
      assert::are_equal(build_type::release, c.build_type());
      assert::is_false(c.is_build_type_debug());
      assert::are_equal("<unknown>", c.name());
      assert::are_equal(version {1, 2, 3}, c.version());
      assert::are_equal("<unknown> 1.2.3", c.version_string());
      assert::are_equal("<unknown> 1.2.3", c.to_string());
    }
    
    auto test_method_(create_compiler_with_compiler_id_msvc_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::msvc, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::msvc, c.compiler_id());
      assert::is_true(c.is_64_bit());
      assert::are_equal(build_type::release, c.build_type());
      assert::is_false(c.is_build_type_debug());
      assert::are_equal("MSVC", c.name());
      assert::are_equal(version {1, 2, 3}, c.version());
      assert::are_equal("MSVC 1.2.3", c.version_string());
      assert::are_equal("MSVC 1.2.3", c.to_string());
    }
    
    auto test_method_(create_compiler_with_compiler_id_clang_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::clang, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::clang, c.compiler_id());
      assert::is_true(c.is_64_bit());
      assert::are_equal(build_type::release, c.build_type());
      assert::is_false(c.is_build_type_debug());
      assert::are_equal("Clang", c.name());
      assert::are_equal(version {1, 2, 3}, c.version());
      // The result cannot be tested as it is the actual version of the command line, which varies according to OS and compiler version.
      //assert::are_equal("Clang 1.2.3", c.version_string());
      //assert::are_equal("Clang 1.2.3", c.to_string());
    }
    
    auto test_method_(create_compiler_with_compiler_id_gcc_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::gcc, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::gcc, c.compiler_id());
      assert::is_true(c.is_64_bit());
      assert::are_equal(build_type::release, c.build_type());
      assert::is_false(c.is_build_type_debug());
      assert::are_equal("GCC", c.name());
      assert::are_equal(version {1, 2, 3}, c.version());
      // The result cannot be tested as it is the actual version of the command line, which varies according to OS and compiler version.
      //assert::are_equal("GCC 1.2.3", c.version_string());
      //assert::are_equal("GCC 1.2.3", c.to_string());
    }
    
    auto test_method_(create_compiler_with_compiler_id_invalid_version_build_type_release_and_is_64_bit) {
      #if !defined (__APPLE__)
      assert::throws<argument_exception>([] {compiler {static_cast<compiler_id>(4), {1, 2, 3}, build_type::release, true};});
      #endif
    }
  };
}
