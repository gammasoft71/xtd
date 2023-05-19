#include "architecture_name.h"
#include "build_type.h"
#include "compiler_name.h"
#include "compiler_version.h"
#include "platform_name.h"
#include "standard_name.h"
#include <xtd/environment.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_tests) {
  public:
    void test_method_(command_line) {
      assert::is_true(environment::command_line().contains("xtd.core.unit_tests"), csf_);
    }
    
    void test_method_(compiler_version) {
      auto compiler = environment::compiler_version();
      assert::are_equal(__compiler_name__, compiler.name(), csf_);
      assert::are_equal(__compiler_version__, compiler.version(), csf_);
      assert::are_equal(__build_type__, compiler.build_type(), csf_);
      assert::are_equal(__build_type__ == build_type::debug, compiler.is_build_type_debug(), csf_);
      assert::are_equal(sizeof(size_t) == 8, compiler.is_64_bit(), csf_);
    }
    
    void test_method_(cpp_version) {
      cpp_language l = environment::cpp_version();
      assert::are_equal(__standard_name__, l.name(), csf_);
    }
    
    void test_method_(current_directory) {
      auto current_directory = environment::current_directory();
      auto directory = io::path::combine(io::path::get_temp_path(), "xtd_environment_test");
      if (!io::directory::exists(directory)) io::directory::create_directory(directory);
      environment::current_directory(directory);
      assert::are_equal(directory, environment::current_directory(), csf_);
      environment::current_directory(current_directory);
      io::directory::remove(directory);
    }
    
    void test_method_(current_thread_id) {
      assert::are_equal(std::this_thread::get_id(), environment::current_thread_id(), csf_);
    }
    
    void test_method_(exit_code) {
      assert::is_zero(environment::exit_code(), csf_);
      environment::exit_code(42);
      assert::are_equal(42, environment::exit_code(), csf_);
      environment::exit_code(0);
      assert::is_zero(environment::exit_code(), csf_);
    }
    
    void test_method_(has_shutdown_started) {
      assert::is_false(environment::has_shutdown_started(), csf_);
    }
    
    void test_method_(is_64_bit_operating_system) {
      // Not possible to check in the unit test
      //assert::is_true(environment::is_64_bit_operating_system(), csf_);
      //assert::is_false(environment::is_64_bit_operating_system(), csf_);
    }
    
    void test_method_(is_64_bit_process) {
      assert::are_equal(sizeof(size_t) == 8, environment::is_64_bit_process(), csf_);
    }
    
    void test_method_(locale) {
      assert::are_equal(std::locale(), environment::locale(), csf_);
    }
    
    void test_method_(machine_name) {
      // Not possible to check in the unit test
      //assert::is_not_empty(environment::machine_name(), csf_);
    }

    void test_method_(new_line) {
      assert::are_equal("\n", environment::new_line(), csf_);
    }
    
    void test_method_(os_version) {
      operating_system os = environment::os_version();
      assert::are_equal(__platform_name__, os.name(), csf_);
      assert::are_not_equal(platform_id::unknown, os.platform(), csf_);
      assert::are_not_equal(xtd::version {}, os.version(), csf_);
    }
    
    void test_method_(processor_count) {
      assert::is_greater_or_equal(environment::processor_count(), 1U, csf_);
    }
    
    void test_method_(processor_information) {
      processor p = environment::processor_information();
      assert::are_equal(__architecture_name__, p.architecture_string(), csf_);
      assert::are_equal(ustring(__architecture_name__).ends_with("64"), p.is_64_bit(), csf_);
    }
    
    void test_method_(stack_trace) {
      assert::is_not_empty(environment::stack_trace(), csf_);
    }
    
    void test_method_(system_directory) {
      assert::are_equal(environment::get_folder_path(environment::special_folder::system), environment::system_directory(), csf_);
    }
    
    void test_method_(system_page_size) {
      // There is no unit test possible.
      //assert::is_not_zero(environment::system_page_size(), csf_);
    }
    
    void test_method_(target_type) {
      xtd::target_type tt = environment::target_type();
      assert::is_false(tt.is_console_application(), csf_);
      assert::is_false(tt.is_guid_application(), csf_);
      assert::is_false(tt.is_shared_library(), csf_);
      assert::is_false(tt.is_static_library(), csf_);
      assert::is_true(tt.is_test_application(), csf_);
      assert::are_equal("test application", tt.name(), csf_);
      assert::are_equal(target_id::test_application, tt.target_id(), csf_);
      assert::are_equal("test application", tt.to_string(), csf_);
    }
    
    void test_method_(tick_count) {
      // There is no unit test possible.
      assert::is_not_zero(environment::tick_count().count(), csf_);
    }
    
    void test_method_(toolkit) {
      xtd::toolkit t = environment::toolkit_version();
      assert::are_equal("No toolkit defined.", t.description(), csf_);
      assert::are_equal("Unknown", t.name(), csf_);
      assert::are_equal(xtd::version {}, t.version(), csf_);
    }
    
    void test_method_(user_administrator) {
      assert::is_false(environment::user_administrator(), csf_);
    }
    
    void test_method_(user_domain_name) {
      // There is no unit test possible.
      assert::is_not_empty(environment::user_domain_name(), csf_);
    }

    void test_method_(user_interactive) {
      assert::is_true(environment::user_interactive(), csf_);
    }
    
    void test_method_(user_name) {
      // There is no unit test possible.
      assert::is_not_empty(environment::user_name(), csf_);
    }
    
    void test_method_(version) {
      assert::are_equal(xtd::version {0, 2, 0}, environment::version(), csf_);
    }
      
    void test_method_(working_set) {
      // There is no unit test possible.
      //assert::is_not_zero(environment::working_set(), csf_);
    }
    
    void test_method_(exit) {
      // There is no unit test possible.
      //assert::does_not_throw([]{environment::exit(42);}, csf_);
    }
    
    void test_method_(expand_environment_variables) {
      environment::set_environment_variable("xtd_test_core_value1", "First value");
      environment::set_environment_variable("xtd_test_core_value2", "Second value");

      assert::are_equal("value1 = \"First value\" and value2 = \"Second value\"", environment::expand_environment_variables("value1 = \"%xtd_test_core_value1%\" and value2 = \"%xtd_test_core_value2%\""), csf_);
      assert::are_equal("value1 = \"%xtd_test_core_value1\" and value2 = \"xtd_test_core_value2%\"", environment::expand_environment_variables("value1 = \"%xtd_test_core_value1\" and value2 = \"xtd_test_core_value2%\""), csf_);
      assert::are_equal("value1 = \"%xtd_test_core_value1\" and value2 = \"%xtd_test_core_value2%\"", environment::expand_environment_variables("value1 = \"%xtd_test_core_value1\" and value2 = \"%xtd_test_core_value2%\""), csf_);

      environment::set_environment_variable("xtd_test_core_value1", "");
      environment::set_environment_variable("xtd_test_core_value2", "");
    }
  };
}
