#include <xtd/access_violation_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(access_violation_exception_tests) {
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
      access_violation_exception e;
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", e.to_string(), csf_);
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      access_violation_exception e(info);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Attempted to read or write protected memory. This is often an indication that other memory is corrupt.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      access_violation_exception e("");
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.to_string(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      access_violation_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      access_violation_exception e("Test excpetion message.");
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      access_violation_exception e("Test excpetion message.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      access_violation_exception e("Test excpetion message.", inner_exception);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.h_result(), csf_);
      //assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      //assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.", e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      access_violation_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      //assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      //assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      access_violation_exception e = access_violation_exception("Test excpetion message.", inner_exception, info);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("", e.help_link(), csf_);
      //assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      //assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      access_violation_exception e;
      e = access_violation_exception("Test excpetion message.", inner_exception, info);
      assert::are_equal(h_results::E_POINTER, e.error_code().value(), csf_);
      assert::are_equal(h_results::h_results_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("", e.help_link(), csf_);
      //assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      //assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("Test excpetion message.", e.message(), csf_);
      assert::are_equal("xtd::access_violation_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::access_violation_exception : Test excpetion message.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("Test excpetion message.", e.what(), csf_);
    }
  };
}
