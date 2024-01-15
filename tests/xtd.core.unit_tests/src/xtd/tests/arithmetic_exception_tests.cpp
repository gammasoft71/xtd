#include <xtd/arithmetic_exception>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(arithmetic_exception_tests) {
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
      arithmetic_exception e;
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(0u, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Overflow or underflow in the arithmetic operation.", e.to_string());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.what());
    }
    
    void test_method_(default_creator_with_current_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e(info);
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Overflow or underflow in the arithmetic operation.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Overflow or underflow in the arithmetic operation.", e.what());
    }
    
    void test_method_(creator_with_empty_message) {
      arithmetic_exception e("");
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0u, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception", e.to_string());
      assert::are_equal_("xtd::arithmetic_exception", e.what());
    }
    
    void test_method_(creator_with_message_empty_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("", info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception\n" + info.to_string(), e.to_string());
      assert::are_equal_("xtd::arithmetic_exception", e.what());
    }
    
    void test_method_(creator_with_message) {
      arithmetic_exception e("Test excpetion message.");
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0u, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_error_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_error_help_link_and_stack_frame) {
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      arithmetic_exception e("Test excpetion message.", inner_exception);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::is_empty_(e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(0u, e.line_number());
      assert::is_empty_(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::is_empty_(e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error_code().value());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(0, e.error_code().value());
      assert::are_equal_(std::system_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_stack_frame) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e = arithmetic_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = current_stack_frame_;
      arithmetic_exception e;
      e = arithmetic_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://gammasoft71.github.io/xtd/reference_guides/latest/", info);
      assert::are_equal_(EBUSY, e.error_code().value());
      assert::are_equal_(std::generic_category(), e.error_code().category());
      assert::are_equal_(info.get_file_name(), e.file_path());
      assert::are_equal_("https://gammasoft71.github.io/xtd/reference_guides/latest/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.get_file_line_number(), e.line_number());
      assert::are_equal_(info.get_method(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::arithmetic_exception", e.name());
      assert::are_equal_(info.to_string(), e.stack_trace());
      assert::are_equal_("xtd::arithmetic_exception : Test excpetion message.\n" + info.to_string(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
  };
}
