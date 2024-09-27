#include <xtd/argument_out_of_range_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(argument_out_of_range_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = system_exception::enable_stack_trace();
      system_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      system_exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(default_creator) {
      argument_out_of_range_exception e;
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Specified argument is out of range of valid values.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Specified argument is out of range of valid values.", e.to_string(), csf_);
      assert::are_equal("Specified argument is out of range of valid values.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e(info);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Specified argument is out of range of valid values.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Specified argument is out of range of valid values.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Specified argument is out of range of valid values.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      argument_out_of_range_exception e("Test excpetion message.");
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      argument_out_of_range_exception e("");
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.to_string(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      argument_out_of_range_exception e("Test excpetion message.", inner_exception);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", inner_exception, "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(h_results::COR_E_SYSTEM, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e = argument_out_of_range_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      argument_out_of_range_exception e;
      e = argument_out_of_range_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::argument_out_of_range_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(throw_if_equal) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_equal(42, 42);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_equal(42, 84);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_equal(42, 21);}, csf_);
    }
    
    void test_method_(throw_if_equal_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_equal(42, 42);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must not be equal to `42`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_equal(42, 42, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must not be equal to `42`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_equal(42, 42, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must not be equal to `42`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }
    
    void test_method_(throw_if_less_than) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_less_than(42, 84);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_less_than(42, 42);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_less_than(42, 21);}, csf_);
    }
    
    void test_method_(throw_if_less_than_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_less_than(42, 84);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than or equal to `84`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_less_than(42, 84, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than or equal to `84`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_less_than(42, 84, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than or equal to `84`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }
    
    void test_method_(throw_if_less_than_or_equal) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_less_than_or_equal(42, 84);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_less_than_or_equal(42, 42);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_less_than_or_equal(42, 21);}, csf_);
    }
    
    void test_method_(throw_if_less_than_or_equal_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_less_than_or_equal(42, 84);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than `84`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_less_than_or_equal(42, 84, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than `84`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_less_than_or_equal(42, 84, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be greater than `84`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }

    void test_method_(throw_if_greater_than) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_greater_than(42, 21);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_greater_than(42, 42);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_greater_than(42, 84);}, csf_);
    }
    
    void test_method_(throw_if_greater_than_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_greater_than(42, 21);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than or equal to `21`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_greater_than(42, 21, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than or equal to `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_greater_than(42, 21, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than or equal to `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }

    void test_method_(throw_if_greater_than_or_equal) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 21);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 42);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 84);}, csf_);
    }
    
    void test_method_(throw_if_greater_than_or_equal_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 21);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than `21`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 21, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_greater_than_or_equal(42, 21, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be less than `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }

    void test_method_(throw_if_negative) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_negative(-1);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_negative(0);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_negative(1);}, csf_);
    }

    void test_method_(throw_if_negative_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_negative(-1);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative value. (Parameter '')\nActual value was -1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_negative(-1, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative value. (Parameter 'my_value')\nActual value was -1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_negative(-1, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative value. (Parameter 'my_value')\nActual value was -1.", exception.message(), csf_);
    }

    void test_method_(throw_if_negative_or_zero) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_negative_or_zero(-1);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_negative_or_zero(0);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_negative(1);}, csf_);
    }
    
    void test_method_(throw_if_negative_or_zero_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_negative_or_zero(-1);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative and non-zero value. (Parameter '')\nActual value was -1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_negative_or_zero(-1, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative and non-zero value. (Parameter 'my_value')\nActual value was -1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_negative_or_zero(-1, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('-1') must be a non-negative and non-zero value. (Parameter 'my_value')\nActual value was -1.", exception.message(), csf_);
    }

    void test_method_(throw_if_not_equal) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_not_equal(42, 84);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_not_equal(42, 21);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_not_equal(42, 42);}, csf_);
    }
    
    void test_method_(throw_if_not_equal_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_not_equal(42, 21);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be equal to `21`. (Parameter '')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_not_equal(42, 21, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be equal to `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_not_equal(42, 21, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('42') must be equal to `21`. (Parameter 'my_value')\nActual value was 42.", exception.message(), csf_);
    }
    
    void test_method_(throw_if_positive) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_positive(1);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_positive(0);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_positive(-1);}, csf_);
    }
    
    void test_method_(throw_if_positive_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_positive(1);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive value. (Parameter '')\nActual value was 1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_positive(1, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive value. (Parameter 'my_value')\nActual value was 1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_positive(1, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive value. (Parameter 'my_value')\nActual value was 1.", exception.message(), csf_);
    }
    
    void test_method_(throw_if_positive_or_zero) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_positive_or_zero(1);}, csf_);
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_positive_or_zero(0);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_positive_or_zero(-1);}, csf_);
    }
    
    void test_method_(throw_if_positive_or_zero_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_positive_or_zero(1);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive and non-zero value. (Parameter '')\nActual value was 1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_positive_or_zero(1, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive and non-zero value. (Parameter 'my_value')\nActual value was 1.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_positive_or_zero(1, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('1') must be a non-positive and non-zero value. (Parameter 'my_value')\nActual value was 1.", exception.message(), csf_);
    }

    void test_method_(throw_if_zero) {
      assert::throws<argument_out_of_range_exception>([]{argument_out_of_range_exception::throw_if_zero(0);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_zero(-1);}, csf_);
      assert::does_not_throw([]{argument_out_of_range_exception::throw_if_zero(1);}, csf_);
    }
    
    void test_method_(throw_if_zero_verify_exception) {
      auto exception = argument_out_of_range_exception {};
      
      try {
        argument_out_of_range_exception::throw_if_zero(0);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('0') must be a non-zero value. (Parameter '')\nActual value was 0.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_zero(0, "my_value");
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('0') must be a non-zero value. (Parameter 'my_value')\nActual value was 0.", exception.message(), csf_);
      
      try {
        argument_out_of_range_exception::throw_if_zero(0, "my_value", csf_);
      } catch(const argument_out_of_range_exception& e) {
        exception = e;
      }
      assert::are_equal("value ('0') must be a non-zero value. (Parameter 'my_value')\nActual value was 0.", exception.message(), csf_);
    }
  };
}
