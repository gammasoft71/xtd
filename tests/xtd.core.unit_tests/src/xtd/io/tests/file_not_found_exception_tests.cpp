#include <xtd/io/file_not_found_exception>
#include <xtd/argument_exception>
#include <xtd/environment>
#include <xtd/nullopt>
#include <xtd/io/path>
#include <xtd/reflection/assembly>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::reflection;
using namespace xtd::tunit;

namespace xtd::io::tests {
  class test_class_(file_not_found_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = file_not_found_exception::enable_stack_trace();
      file_not_found_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      file_not_found_exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(default_constructor) {
      auto e = file_not_found_exception {};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(default_constructor_with_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message) {
      auto e = file_not_found_exception {nullopt};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }

    void test_method_(constructor_with_empty_message) {
      auto e = file_not_found_exception {""};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.to_string(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_empty_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"", stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception" + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message) {
      auto e = file_not_found_exception {"Test excpetion message."};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"Test excpetion message.", stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_and_nullopt_file_name) {
      auto e = file_not_found_exception {nullopt, nullopt};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_nullopt_file_name_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, nullopt, stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }

    void test_method_(constructor_with_nullopt_message_and_file_name) {
      auto e = file_not_found_exception {nullopt, "my_file.txt"};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Could not load file 'my_file.txt'. The system cannot find the file specified.", e.to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_file_name_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, "my_file.txt", stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Could not load file 'my_file.txt'. The system cannot find the file specified." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.what(), csf_);
    }

    void test_method_(constructor_with_message_and_file_name) {
      auto e = file_not_found_exception {"Test excpetion message.", "my_file.txt"};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_file_name_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"Test excpetion message.", "my_file.txt", stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_null(e.inner_exception(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {nullopt, inner_exception};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, inner_exception, stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }

    void test_method_(constructor_with_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {"Test excpetion message.", inner_exception};
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"Test excpetion message.", inner_exception, stack_frame};
      assert::is_null(e.file_name(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_nullopt_file_name_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {nullopt, nullopt, inner_exception};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file.", e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_nullopt_file_name_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, nullopt, inner_exception, stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Unable to find the specified file." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Unable to find the specified file.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_nullopt_file_name_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {"Test excpetion message.", nullopt, inner_exception};
      assert::is_null(e.file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_nullopt_file_name_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"Test excpetion message.", nullopt, inner_exception, stack_frame};
      assert::is_null(e.file_name(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_file_name_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {nullopt, "my_file.txt", inner_exception};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Could not load file 'my_file.txt'. The system cannot find the file specified.", e.to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_nullopt_message_file_name_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {nullopt, "my_file.txt", inner_exception, stack_frame};
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Could not load file 'my_file.txt'. The system cannot find the file specified." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Could not load file 'my_file.txt'. The system cannot find the file specified.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_file_name_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = file_not_found_exception {"Test excpetion message.", "my_file.txt", inner_exception};
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(constructor_with_message_file_name_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = file_not_found_exception {"Test excpetion message.", "my_file.txt", inner_exception, stack_frame};
      assert::is_not_null(e.file_name(), csf_);
      assert::are_equal("my_file.txt", e.file_name().value(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception", e.get_type().full_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_FILENOTFOUND, e.h_result(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(e.h_result(), e.error_code().value(), csf_);
      assert::is_not_null(e.inner_exception(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("xtd::io::file_not_found_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}
