#include <xtd/console>
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
  public:
    void test_method_(assembly_company) {
      assert::are_equal("Gammasoft", assembly::get_executing_assembly().company(), csf_);
    }
    
    void test_method_(assembly_configuration) {
      assert::are_equal("Test", assembly::get_executing_assembly().configuration(), csf_);
    }
    
    void test_method_(assembly_copyright) {
      assert::are_equal("Copyright © Gammasoft 2024", assembly::get_executing_assembly().copyright(), csf_);
    }
    
    void test_method_(assembly_culture) {
      assert::are_equal("en_US.UTF-8", assembly::get_executing_assembly().culture(), csf_);
    }
    
    void test_method_(assembly_description) {
      assert::are_equal("xtd.core.unit_tests contains xtd.core unit tests.", assembly::get_executing_assembly().description(), csf_);
    }
    
    void test_method_(assembly_file_version) {
      assert::is_empty(assembly::get_executing_assembly().file_version(), csf_);
    }
    
    void test_method_(assembly_guid) {
      assert::are_equal("1965d1b0-680e-4ab6-87ad-96aeae4c7224", assembly::get_executing_assembly().guid(), csf_);
    }
    
    void test_method_(assembly_identifier) {
      assert::is_empty(assembly::get_executing_assembly().identifier(), csf_);
    }
    
    void test_method_(assembly_name) {
      assert::is_empty(assembly::get_executing_assembly().name(), csf_);
    }
    
    void test_method_(assembly_product) {
      assert::are_equal("xtd.core.unit_tests", assembly::get_executing_assembly().product(), csf_);
    }
    
    void test_method_(assembly_title) {
      assert::are_equal("xtd.core.unit_tests", assembly::get_executing_assembly().title(), csf_);
    }
    
    void test_method_(assembly_trademark) {
      assert::is_empty(assembly::get_executing_assembly().trademarks(), csf_);
    }
    
    void test_method_(assembly_version) {
      assert::is_empty(assembly::get_executing_assembly().version(), csf_);
    }
  };
}

