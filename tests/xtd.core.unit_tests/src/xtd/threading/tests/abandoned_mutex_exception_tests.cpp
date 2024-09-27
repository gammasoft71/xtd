#include <xtd/threading/abandoned_mutex_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(abandoned_mutex_exception_tests) {
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
      abandoned_mutex_exception e;
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.", e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e(info);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_empty_message) {
      abandoned_mutex_exception e("");
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.to_string(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::is_empty(e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.what(), csf_);
    }
    
    void test_method_(creator_with_message) {
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.");
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.", e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_false(e.inner_exception().has_value(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", inner_exception);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::is_empty(e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(0u, e.line_number(), csf_);
      assert::is_empty(e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::is_empty(e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.", e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", inner_exception, info);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::is_empty(e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", inner_exception, "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(h_results::COR_E_EXCEPTION, e.error_code().value(), csf_);
      assert::are_equal(std::system_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e("The wait completed due to an abandoned mutex.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e = abandoned_mutex_exception("The wait completed due to an abandoned mutex.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      abandoned_mutex_exception e;
      e = abandoned_mutex_exception("The wait completed due to an abandoned mutex.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal(EBUSY, e.error_code().value(), csf_);
      assert::are_equal(std::generic_category(), e.error_code().category(), csf_);
      assert::are_equal(info.get_file_name(), e.file_path(), csf_);
      assert::are_equal("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link(), csf_);
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get(), csf_);
      assert::are_equal(inner_exception.what(), e.inner_exception().value().get().what(), csf_);
      assert::are_equal(info.get_file_line_number(), e.line_number(), csf_);
      assert::are_equal(info.get_method(), e.member_name(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.message(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception", e.name(), csf_);
      assert::are_equal(info.to_string(), e.stack_trace(), csf_);
      assert::are_equal("xtd::threading::abandoned_mutex_exception : The wait completed due to an abandoned mutex.\n" + info.to_string(), e.to_string(), csf_);
      assert::are_equal("The wait completed due to an abandoned mutex.", e.what(), csf_);
    }
  };
}
