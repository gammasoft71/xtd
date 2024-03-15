#include <xtd/compiler_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(compiler_tests) {
    void test_method_(create_compiler_with_default_ctor) {
      compiler c;
      assert::are_equal(build_type::debug, c.build_type(), csf_);
      assert::are_equal(compiler_id::unknown, c.compiler_id(), csf_);
      assert::is_false(c.is_64_bit(), csf_);
      assert::is_true(c.is_build_type_debug(), csf_);
      assert::are_equal("<unknown>", c.name(), csf_);
      assert::are_equal(version {}, c.version(), csf_);
      assert::are_equal("<unknown> 0.0", c.version_string(), csf_);
      assert::are_equal("<unknown> 0.0", c.to_string(), csf_);
    }
    
    void test_method_(create_compiler_with_compiler_id_unknown_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::unknown, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::unknown, c.compiler_id(), csf_);
      assert::is_true(c.is_64_bit(), csf_);
      assert::are_equal(build_type::release, c.build_type(), csf_);
      assert::is_false(c.is_build_type_debug(), csf_);
      assert::are_equal("<unknown>", c.name(), csf_);
      assert::are_equal(version {1, 2, 3}, c.version(), csf_);
      assert::are_equal("<unknown> 1.2.3", c.version_string(), csf_);
      assert::are_equal("<unknown> 1.2.3", c.to_string(), csf_);
    }
    
    void test_method_(create_compiler_with_compiler_id_microsoft_visual_studio_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::msvc, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::msvc, c.compiler_id(), csf_);
      assert::is_true(c.is_64_bit(), csf_);
      assert::are_equal(build_type::release, c.build_type(), csf_);
      assert::is_false(c.is_build_type_debug(), csf_);
      assert::are_equal("Visual Studio", c.name(), csf_);
      assert::are_equal(version {1, 2, 3}, c.version(), csf_);
      assert::are_equal("Visual Studio (MSVC 1.2.3)", c.version_string(), csf_);
      assert::are_equal("Visual Studio (MSVC 1.2.3)", c.to_string(), csf_);
    }
    
    void test_method_(create_compiler_with_compiler_id_clang_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::clang, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::clang, c.compiler_id(), csf_);
      assert::is_true(c.is_64_bit(), csf_);
      assert::are_equal(build_type::release, c.build_type(), csf_);
      assert::is_false(c.is_build_type_debug(), csf_);
      assert::are_equal("clang", c.name(), csf_);
      assert::are_equal(version {1, 2, 3}, c.version(), csf_);
      assert::are_equal("clang 1.2.3", c.version_string(), csf_);
      assert::are_equal("clang 1.2.3", c.to_string(), csf_);
    }
    
    void test_method_(create_compiler_with_compiler_id_gcc_version_build_type_release_and_is_64_bit) {
      compiler c {compiler_id::gcc, {1, 2, 3}, build_type::release, true};
      assert::are_equal(compiler_id::gcc, c.compiler_id(), csf_);
      assert::is_true(c.is_64_bit(), csf_);
      assert::are_equal(build_type::release, c.build_type(), csf_);
      assert::is_false(c.is_build_type_debug(), csf_);
      assert::are_equal("gcc", c.name(), csf_);
      assert::are_equal(version {1, 2, 3}, c.version(), csf_);
      assert::are_equal("gcc 1.2.3", c.version_string(), csf_);
      assert::are_equal("gcc 1.2.3", c.to_string(), csf_);
    }
    
    void test_method_(create_compiler_with_compiler_id_invalid_version_build_type_release_and_is_64_bit) {
      assert::throws<argument_exception>([] {compiler {static_cast<compiler_id>(3), {1, 2, 3}, build_type::release, true};}, csf_);
    }
  };
}
