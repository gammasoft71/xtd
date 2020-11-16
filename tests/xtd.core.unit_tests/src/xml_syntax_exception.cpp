#include <xtd/xml_syntax_exception.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_xml_syntax_exception) {
  public:
    static void class_initialize_(class_initialize) {
      system_exception::enable_stack_trace(false);
    }
    
    static void class_cleanup_(class_cleanup) {
      system_exception::enable_stack_trace(true);
    }
    
    void test_method_(default_creator) {
      xml_syntax_exception e;
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Syntax error in XML.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Syntax error in XML.", e.to_string());
      assert::are_equal_("Syntax error in XML.", e.what());
    }

    void test_method_(default_creator_with_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e(info);
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Syntax error in XML.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Syntax error in XML.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Syntax error in XML.", e.what());
    }
    
    void test_method_(creator_with_empty_message) {
      xml_syntax_exception e("");
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception", e.to_string());
      assert::are_equal_("xtd::xml_syntax_exception", e.what());
    }
    
    void test_method_(creator_with_message_empty_and_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e("", info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception\n" + info.to_trace(), e.to_string());
      assert::are_equal_("xtd::xml_syntax_exception", e.what());
    }

    void test_method_(creator_with_message) {
      xml_syntax_exception e("Test excpetion message.");
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_and_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_error_and_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_help_link_and_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_error_help_link_and_caller_info) {
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_false_(e.inner_exception().has_value());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(creator_with_message_and_inner_exception) {
      system_exception inner_exception;
      xml_syntax_exception e("Test excpetion message.", inner_exception);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::is_empty(e.file_path());
      assert::is_empty(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(0U, e.line_numer());
      assert::is_empty(e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::is_empty(e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.", e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", inner_exception, info);
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::are_equal_(0, e.error().value());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::is_empty_(e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_help_link_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", inner_exception, "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(0, e.error().value());
      assert::are_equal_(std::system_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(creator_with_message_inner_exception_error_help_link_and_caller_info) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
    
    void test_method_(copy_constructor) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e = xml_syntax_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }

    void test_method_(copy_operator) {
      system_exception inner_exception;
      auto info = caller_info_;
      xml_syntax_exception e;
      e = xml_syntax_exception("Test excpetion message.", inner_exception, std::error_code(EBUSY, std::generic_category()), "https://codedocs.xyz/gammasoft71/xtd_core/", info);
      assert::are_equal_(EBUSY, e.error().value());
      assert::are_equal_(std::generic_category(), e.error().category());
      assert::are_equal_(info.file_path(), e.file_path());
      assert::are_equal_("https://codedocs.xyz/gammasoft71/xtd_core/", e.help_link());
      assert::is_instance_of<xtd::system_exception>(e.inner_exception().value().get());
      assert::are_equal_(inner_exception.what(), e.inner_exception().value().get().what());
      assert::are_equal_(info.line_number(), e.line_numer());
      assert::are_equal_(info.member_name(), e.member_name());
      assert::are_equal_("Test excpetion message.", e.message());
      assert::are_equal_("xtd::xml_syntax_exception", e.name());
      assert::are_equal_(info.to_trace(), e.stack_trace());
      assert::are_equal_("xtd::xml_syntax_exception : Test excpetion message.\n" + info.to_trace(), e.to_string());
      assert::are_equal_("Test excpetion message.", e.what());
    }
  };
}
