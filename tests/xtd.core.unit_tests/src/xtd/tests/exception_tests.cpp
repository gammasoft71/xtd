#include <xtd/exception>
#include <xtd/argument_exception>
#include <xtd/environment>
#include <xtd/nullopt>
#include <xtd/io/path>
#include <xtd/reflection/assembly>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::reflection;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
    
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = exception::enable_stack_trace();
      exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(exception_ref) {
      assert::are_equal(typeof_<optional<std::reference_wrapper<const exception>>>(), typeof_<exception::exception_ref>());
    }
    
    void test_method_(default_constructor) {
      auto e = exception {};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception : Exception of type 'xtd::exception' was thrown.", e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }
    
    void test_method_(default_constructor_with_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = exception {stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Exception of type 'xtd::exception' was thrown." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message) {
      auto e = exception {nullopt};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception : Exception of type 'xtd::exception' was thrown.", e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = exception {nullopt, stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Exception of type 'xtd::exception' was thrown." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }

    void test_method_(constructor_with_empty_message) {
      auto e = exception {""};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::is_empty(e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception", e.to_string());
      assert::are_equal("xtd::exception", e.what());
    }

    void test_method_(constructor_with_message_empty_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = exception {"", stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::is_empty(e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception" + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("xtd::exception", e.what());
    }
    
    void test_method_(constructor_with_message) {
      auto e = exception {"Test excpetion message."};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception : Test excpetion message.", e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_message_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      auto e = exception {"Test excpetion message.", stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = exception {nullopt, inner_exception};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception : Exception of type 'xtd::exception' was thrown.", e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception {nullopt, inner_exception, stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Exception of type 'xtd::exception' was thrown." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what());
    }

    void test_method_(constructor_with_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = exception {"Test excpetion message.", inner_exception};
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::exception : Test excpetion message.", e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception {"Test excpetion message.", inner_exception, stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_constructor) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception {"Test excpetion message.", inner_exception, stack_frame};
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_operator) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception {};
      e = exception("Test excpetion message.", inner_exception, stack_frame);
      assert::are_equal("xtd::exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal(inner_exception.to_string(), e.inner_exception().value().get().to_string());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(help_link) {
      auto e = exception {};
      e.help_link("https://gammasoft71.github.io/xtd/");
      assert::are_equal("https://gammasoft71.github.io/xtd/", e.help_link());
    }
    
    void test_method_(h_result_with_h_result_value) {
      auto e = exception {};
      e.h_result(h_result::E_HANDLE);
      assert::are_equal(h_result::E_HANDLE, e.h_result());
      assert::are_equal(h_result::E_HANDLE, e.error_code().value());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
    }
    
    void test_method_(h_result_without_h_result_value) {
      auto e = exception {};
      e.h_result(42);
      assert::are_equal(42, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
    }
    
    void test_method_(error_code_with_h_result_make_error_code) {
      auto e = exception {};
      e.error_code(h_result::make_error_code(h_result::E_HANDLE));
      assert::are_equal(h_result::E_HANDLE, e.error_code().value());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(h_result::E_HANDLE, e.h_result());
    }
    
    void test_method_(error_code_with_std_make_error_code) {
      auto e = exception {};
      e.error_code(std::make_error_code(std::errc::invalid_argument));
      assert::are_equal(EINVAL, e.error_code().value());
      assert::are_equal(std::generic_category(), e.error_code().category());
      assert::are_equal(h_result::COR_E_EXCEPTION, e.h_result());
    }
    
    void test_method_(source) {
      auto e = exception {};
      e.source("my_application");
      assert::are_equal("my_application", e.source());
    }
    
    void test_method_(enable_stack_trace) {
      auto e = exception {};
      auto enable_stack_trace = e.enable_stack_trace();
      e.enable_stack_trace(!enable_stack_trace);
      assert::are_equal(!enable_stack_trace, e.enable_stack_trace());
      e.enable_stack_trace(enable_stack_trace);
    }
  };
}
