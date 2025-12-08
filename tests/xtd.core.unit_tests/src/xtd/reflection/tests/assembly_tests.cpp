#include <xtd/console>
#include <xtd/environment>
#include <xtd/io/file>
#include <xtd/reflection/assembly>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::reflection;
using namespace xtd::tunit;

namespace xtd::reflection::tests {
  class test_class_(assembly_tests) {
    auto test_method_(assembly_company) {
      assert::are_equal("Gammasoft", assembly::get_executing_assembly().company());
    }
    
    auto test_method_(assembly_configuration) {
      assert::are_equal("Test", assembly::get_executing_assembly().configuration());
    }
    
    auto test_method_(assembly_copyright) {
      assert::are_equal("Copyright © Gammasoft 2025", assembly::get_executing_assembly().copyright());
    }
    
    auto test_method_(assembly_culture) {
      assert::are_equal("en_US.UTF-8", assembly::get_executing_assembly().culture());
    }
    
    auto test_method_(assembly_description) {
      assert::are_equal("xtd.core.unit_tests contains xtd.core unit tests.", assembly::get_executing_assembly().description());
    }
    
    auto test_method_(assembly_file_version) {
      assert::is_empty(assembly::get_executing_assembly().file_version());
    }
    
    auto test_method_(assembly_guid) {
      assert::are_equal("1965d1b0-680e-4ab6-87ad-96aeae4c7224", assembly::get_executing_assembly().guid());
    }
    
    auto test_method_(assembly_identifier) {
      assert::is_empty(assembly::get_executing_assembly().identifier());
    }
    
    auto test_method_(assembly_name) {
      assert::is_empty(assembly::get_executing_assembly().name());
    }
    
    auto test_method_(assembly_product) {
      assert::are_equal("xtd.core.unit_tests", assembly::get_executing_assembly().product());
    }
    
    auto test_method_(assembly_title) {
      assert::are_equal("xtd.core.unit_tests", assembly::get_executing_assembly().title());
    }
    
    auto test_method_(assembly_trademark) {
      assert::is_empty(assembly::get_executing_assembly().trademarks());
    }
    
    auto test_method_(assembly_version) {
      assert::are_equal(environment::version().to_string(), assembly::get_executing_assembly().version());
    }
  };
}

