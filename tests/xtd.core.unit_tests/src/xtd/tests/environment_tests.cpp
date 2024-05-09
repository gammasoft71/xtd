#include "architecture_name.h"
#include "build_type.h"
#include "compiler_name.h"
#include "compiler_version.h"
#include "get_know_folder_path.h"
#include "platform_name.h"
#include "standard_name.h"
#include <xtd/environment>
#include <xtd/io/path>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_tests) {
    void test_method_(command_line) {
      string_assert::contains("xtd.core.unit_tests", environment::command_line(), csf_);
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
    
    void test_method_(current_managed_thread_id) {
      assert::are_equal(threading::thread::current_thread().managed_thread_id(), environment::current_managed_thread_id(), csf_);
    }
    
    void test_method_(current_thread_id) {
      assert::are_equal(threading::thread::current_thread().thread_id(), environment::current_thread_id(), csf_);
    }

    void test_method_(exit_code) {
      assert::is_zero(environment::exit_code(), csf_);
      environment::exit_code(42);
      assert::are_equal(42, environment::exit_code(), csf_);
      environment::exit_code(0);
      assert::is_zero(environment::exit_code(), csf_);
    }
    
    void test_method_(has_shutdown_started) {
      // Not possible to check in the unit test
      //assert::is_false(environment::has_shutdown_started(), csf_);
    }
    
    void test_method_(is_64_bit_operating_system) {
      // Not possible to check in the unit test
      //assert::is_true(environment::is_64_bit_operating_system(), csf_);
      //assert::is_false(environment::is_64_bit_operating_system(), csf_);
    }
    
    void test_method_(is_64_bit_process) {
      assert::are_equal(sizeof(size_t) == 8_z, environment::is_64_bit_process(), csf_);
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
      assert::are_not_equal(xtd::version{}, os.version(), csf_);
    }
    
    void test_method_(processor_count) {
      assert::is_greater_or_equal(environment::processor_count(), 1u, csf_);
    }
    
    void test_method_(processor_information) {
      processor p = environment::processor_information();
      // There is no unit test possible.
      /*
       assert::are_equal(__architecture_name__, p.architecture_string(), csf_);
       assert::are_equal(ustring(__architecture_name__).ends_with("64"), p.is_64_bit(), csf_);
       */
    }
    
    void test_method_(stack_trace) {
      // There is no unit test possible.
      //assert::is_not_empty(environment::stack_trace(), csf_);
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
      assert::are_equal(xtd::version{}, t.version(), csf_);
    }
    
    void test_method_(user_administrator) {
      // There is no unit test possible.
      //  assert::is_false(environment::user_administrator(), csf_);
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
      assert::are_equal(xtd::version{ 0, 2, 0 }, environment::version(), csf_);
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
    
    void test_method_(get_command_line_args) {
      auto args = environment::get_command_line_args();
      assert::is_greater_or_equal(args.size(), 1_z, csf_);
      string_assert::contains("xtd.core.unit_tests", args[0], csf_);
    }
    
    void test_method_(get_environment_variable) {
      environment::set_environment_variable("xtd_test_core_value1", "First value");
      environment::set_environment_variable("xtd_test_core_value2", "Second value");
      
      assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1"), csf_);
      assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2"), csf_);
      assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3"), csf_);
      
      environment::set_environment_variable("xtd_test_core_value1", "");
      environment::set_environment_variable("xtd_test_core_value2", "");
    }
    
    void test_method_(get_environment_variable_with_environment_variable_target_process) {
      environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::process);
      environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::process);
      
      assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::process), csf_);
      assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::process), csf_);
      assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::process), csf_);
      
      environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::process);
      environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::process);
    }
    
    void test_method_(get_environment_variable_with_environment_variable_target_user) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::user);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::user);
      
       assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::user), csf_);
       assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::user), csf_);
       assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::user), csf_);
      
       environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::user);
       environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::user);
       */
    }
    
    void test_method_(get_environment_variable_with_environment_variable_target_machine) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::machine);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::machine);
      
       assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::machine), csf_);
       assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::machine), csf_);
       assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::machine), csf_);
      
       environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::machine);
       environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::machine);
       */
    }
    
    void test_method_(get_environment_variables) {
      environment::set_environment_variable("xtd_test_core_value1", "First value");
      environment::set_environment_variable("xtd_test_core_value2", "Second value");
      auto envs = environment::get_environment_variables();
      assert::is_greater_or_equal(envs.size(), 2_z, csf_);
      assert::are_equal("First value", envs["xtd_test_core_value1"], csf_);
      assert::are_equal("Second value", envs["xtd_test_core_value2"], csf_);
    }
    
    void test_method_(get_environment_variables_with_environment_variable_target_process) {
      environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::process);
      environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::process);
      auto envs = environment::get_environment_variables(environment_variable_target::process);
      assert::is_greater_or_equal(envs.size(), 2_z, csf_);
      assert::are_equal("First value", envs["xtd_test_core_value1"], csf_);
      assert::are_equal("Second value", envs["xtd_test_core_value2"], csf_);
    }
    
    void test_method_(get_environment_variables_with_environment_variable_target_user) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::user);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::user);
       auto envs = environment::get_environment_variables(environment_variable_target::user);
       assert::is_greater_or_equal(envs.size(), 2_z, csf_);
       assert::are_equal("First value", envs["xtd_test_core_value1"], csf_);
       assert::are_equal("Second value", envs["xtd_test_core_value2"], csf_);
       */
    }
    
    void test_method_(get_environment_variables_with_environment_variable_target_machine) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::machine);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::machine);
       auto envs = environment::get_environment_variables(environment_variable_target::machine);
       assert::is_greater_or_equal(envs.size(), 2_z, csf_);
       assert::are_equal("First value", envs["xtd_test_core_value1"], csf_);
       assert::are_equal("Second value", envs["xtd_test_core_value2"], csf_);
       */
    }
    
    void test_method_(get_folder_path_special_folder_desktop) {
      auto sf = environment::special_folder::desktop;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Desktop"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Desktop"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_programs) {
      auto sf = environment::special_folder::programs;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_my_documents) {
      auto sf = environment::special_folder::my_documents;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(environment::get_folder_path(environment::special_folder::user_profile), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(environment::get_folder_path(environment::special_folder::user_profile), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_personal) {
      auto sf = environment::special_folder::personal;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(environment::get_folder_path(environment::special_folder::user_profile), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(environment::get_folder_path(environment::special_folder::user_profile), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_favorites) {
      auto sf = environment::special_folder::favorites;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Library", "Favorites"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_startup) {
      auto sf = environment::special_folder::startup;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_recent) {
      auto sf = environment::special_folder::recent;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_send_to) {
      auto sf = environment::special_folder::send_to;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_start_menu) {
      auto sf = environment::special_folder::start_menu;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_my_music) {
      auto sf = environment::special_folder::my_music;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Music"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Music"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_my_videos) {
      auto sf = environment::special_folder::my_videos;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Movies"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Videos"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_desktop_directory) {
      auto sf = environment::special_folder::desktop_directory;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Desktop"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Desktop"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_my_computer) {
      auto sf = environment::special_folder::my_computer;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_network_shortcuts) {
      auto sf = environment::special_folder::network_shortcuts;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_fonts) {
      auto sf = environment::special_folder::fonts;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Library", "Fonts"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), ".fonts"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_templates) {
      auto sf = environment::special_folder::templates;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Templates"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Templates"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_start_menu) {
      auto sf = environment::special_folder::common_start_menu;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_programs) {
      auto sf = environment::special_folder::common_programs;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_startup) {
      auto sf = environment::special_folder::common_startup;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_desktop_directory) {
      auto sf = environment::special_folder::common_desktop_directory;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_application_data) {
      auto sf = environment::special_folder::application_data;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine({ environment::get_folder_path(environment::special_folder::user_profile), ".config" }), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine({ environment::get_folder_path(environment::special_folder::user_profile), ".config" }), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_printer_shortcuts) {
      auto sf = environment::special_folder::printer_shortcuts;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_local_application_data) {
      auto sf = environment::special_folder::local_application_data;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), ".local", "share"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), ".local", "share"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_internet_cache) {
      auto sf = environment::special_folder::internet_cache;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Library", "Caches"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_cookies) {
      auto sf = environment::special_folder::cookies;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_history) {
      auto sf = environment::special_folder::history;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_common_application_data) {
      auto sf = environment::special_folder::common_application_data;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine("/", "usr", "share"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine("/", "usr", "share"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_windows) {
      auto sf = environment::special_folder::windows;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_system) {
      auto sf = environment::special_folder::system;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal("/System", environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_program_files) {
      auto sf = environment::special_folder::program_files;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal("/Applications", environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_my_pictures) {
      auto sf = environment::special_folder::my_pictures;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Pictures"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine(environment::get_folder_path(environment::special_folder::user_profile), "Pictures"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_user_profile) {
      auto sf = environment::special_folder::user_profile;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::are_equal(io::path::combine("/", "Users", environment::user_name()), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine("/", "home", environment::user_name()), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_system_x86) {
      auto sf = environment::special_folder::system_x86;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_program_files_x86) {
      auto sf = environment::special_folder::program_files_x86;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_common_program_files) {
      auto sf = environment::special_folder::common_program_files;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_common_program_files_x86) {
      auto sf = environment::special_folder::common_program_files_x86;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_templates) {
      auto sf = environment::special_folder::common_templates;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::are_equal(io::path::combine("/", "usr", "share", "templates"), environment::get_folder_path(sf, environment::special_folder_option::do_not_verify), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_documents) {
      auto sf = environment::special_folder::common_documents;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_admin_tools) {
      auto sf = environment::special_folder::common_admin_tools;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_ccommon_music) {
      auto sf = environment::special_folder::common_music;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_pictures) {
      auto sf = environment::special_folder::common_pictures;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_videos) {
      auto sf = environment::special_folder::common_videos;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_resources) {
      auto sf = environment::special_folder::resources;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_localized_resources) {
      auto sf = environment::special_folder::localized_resources;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_common_oem_links) {
      auto sf = environment::special_folder::common_oem_links;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_cd_burning) {
      auto sf = environment::special_folder::cd_burning;
      if (environment::os_version().is_windows_platform()) assert::are_equal(__get_know_folder_path__(as<int>(sf)), environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_macos_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else if (environment::os_version().is_unix_platform()) assert::is_empty(environment::get_folder_path(sf), csf_);
      else assert::fail("Operating System unknown", csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_install) {
      assert::is_not_empty(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_locale) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "share", "xtd", "locale"), environment::get_folder_path(environment::special_folder::xtd_locale, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_reference_guide) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "share", "xtd", "reference_guide"), environment::get_folder_path(environment::special_folder::xtd_reference_guide, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_themes) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "share", "xtd", "themes"), environment::get_folder_path(environment::special_folder::xtd_themes, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_include) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "include"), environment::get_folder_path(environment::special_folder::xtd_include, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_libraries) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "lib"), environment::get_folder_path(environment::special_folder::xtd_libraries, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_resources) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "share", "xtd", "resources"), environment::get_folder_path(environment::special_folder::xtd_resources, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_console_include) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "include"), environment::get_folder_path(environment::special_folder::xtd_console_include, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_console_libraries) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "lib"), environment::get_folder_path(environment::special_folder::xtd_console_libraries, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_drawing_include) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "include"), environment::get_folder_path(environment::special_folder::xtd_drawing_include, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_drawing_libraries) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "lib"), environment::get_folder_path(environment::special_folder::xtd_drawing_libraries, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_forms_include) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "include"), environment::get_folder_path(environment::special_folder::xtd_forms_include, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_forms_libraries) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "lib"), environment::get_folder_path(environment::special_folder::xtd_forms_libraries, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_forms_resources) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "share", "xtd", "resources"), environment::get_folder_path(environment::special_folder::xtd_forms_resources, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_tunit_include) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "include"), environment::get_folder_path(environment::special_folder::xtd_tunit_include, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_folder_path_special_folder_xtd_tunit_libraries) {
      assert::are_equal(path::combine(environment::get_folder_path(environment::special_folder::xtd_install, environment::special_folder_option::do_not_verify), "lib"), environment::get_folder_path(environment::special_folder::xtd_tunit_libraries, environment::special_folder_option::do_not_verify), csf_);
    }
    
    void test_method_(get_logical_drives) {
      // There is no unit test possible.
      assert::is_not_empty(environment::get_logical_drives(), csf_);
    }
    
    void test_method_(set_environment_variable) {
      environment::set_environment_variable("xtd_test_core_value1", "First value");
      environment::set_environment_variable("xtd_test_core_value2", "Second value");
      
      assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1"), csf_);
      assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2"), csf_);
      assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3"), csf_);
      
      environment::set_environment_variable("xtd_test_core_value1", "");
      environment::set_environment_variable("xtd_test_core_value2", "");
    }
    
    void test_method_(set_environment_variable_with_environment_variable_target_process) {
      environment::set_environment_variable("xtd_test_core_value1", "First value");
      environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::process);
      environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::process);
      
      assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::process), csf_);
      assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::process), csf_);
      assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::process), csf_);
      
      environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::process);
      environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::process);
    }
    
    void test_method_(set_environment_variable_with_environment_variable_target_user) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::user);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::user);
      
       assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::user), csf_);
       assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::user), csf_);
       assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::user), csf_);
      
       environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::user);
       environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::user);
       */
    }
    
    void test_method_(set_environment_variable_with_environment_variable_target_machine) {
      // Not yet implemented.
      /*
       environment::set_environment_variable("xtd_test_core_value1", "First value", environment_variable_target::machine);
       environment::set_environment_variable("xtd_test_core_value2", "Second value", environment_variable_target::machine);
      
       assert::are_equal("First value", environment::get_environment_variable("xtd_test_core_value1", environment_variable_target::machine), csf_);
       assert::are_equal("Second value", environment::get_environment_variable("xtd_test_core_value2", environment_variable_target::machine), csf_);
       assert::are_equal("", environment::get_environment_variable("xtd_test_core_value3", environment_variable_target::machine), csf_);
      
       environment::set_environment_variable("xtd_test_core_value1", "", environment_variable_target::machine);
       environment::set_environment_variable("xtd_test_core_value2", "", environment_variable_target::machine);
       */
    }
  };
}
