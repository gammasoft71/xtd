#include <xtd/exception>
#include <xtd/argument_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
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
    
    void test_method_(default_creator) {
      auto e = exception {};
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Exception of type 'xtd::exception' was thrown.", e.to_string(), csf_);
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto stack_frame = current_stack_frame_;
      exception e = exception(stack_frame);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Exception of type 'xtd::exception' was thrown.\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      exception e = exception("");
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::exception", e.to_string(), csf_);
      assert::are_equal("xtd::exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      exception e = exception("", stack_frame);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      exception e = exception("Test excpetion message.");
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      //assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto stack_frame = current_stack_frame_;
      exception e = exception("Test excpetion message.", stack_frame);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      exception e = exception("Test excpetion message.", inner_exception);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0u, e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::is_empty(e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception("Test excpetion message.", inner_exception, stack_frame);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception("Test excpetion message.", inner_exception, stack_frame);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      auto inner_exception = argument_exception {};
      auto stack_frame = current_stack_frame_;
      auto e = exception {};
      e = exception("Test excpetion message.", inner_exception, stack_frame);
      assert::are_equal(h_result::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(h_result::h_result_category(), e.error_code().category(), csf_);
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number(), csf_);
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::exception", typeof_(e).full_name(), csf_);
      assert::are_equal(stack_frame.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::exception : Test excpetion message.\n" + stack_frame.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}
