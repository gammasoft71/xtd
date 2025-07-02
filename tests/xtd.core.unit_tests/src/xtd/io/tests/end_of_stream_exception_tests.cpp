#include <xtd/io/end_of_stream_exception>
#include <xtd/argument_exception>
#include <xtd/environment>
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

namespace xtd::io::tests {
  class test_class_(end_of_stream_exception_tests) {
    inline static bool stack_trace_enabled = false;
    inline static std::locale previous_locale;
    static void test_initialize_(test_initialize) {
      previous_locale = std::locale::global(std::locale("en_US.UTF-8"));
      stack_trace_enabled = end_of_stream_exception::enable_stack_trace();
      end_of_stream_exception::enable_stack_trace(false);
    }
    
    static void test_cleanup_(test_cleanup) {
      std::locale::global(previous_locale);
      end_of_stream_exception::enable_stack_trace(stack_trace_enabled);
    }
    
    void test_method_(default_constructor) {
      auto e = end_of_stream_exception {};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream.", e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(default_constructor_with_stack_frame) {
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message) {
      auto e = end_of_stream_exception {nullopt};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream.", e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_and_stack_frame) {
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {nullopt, stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(constructor_with_empty_message) {
      auto e = end_of_stream_exception {""};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::is_empty(e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::io::end_of_stream_exception", e.to_string());
      assert::are_equal("xtd::io::end_of_stream_exception", e.what());
    }
    
    void test_method_(constructor_with_message_empty_and_stack_frame) {
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {"", stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::is_empty(e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::io::end_of_stream_exception" + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("xtd::io::end_of_stream_exception", e.what());
    }
    
    void test_method_(constructor_with_message) {
      auto e = end_of_stream_exception {"Test excpetion message."};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::io::end_of_stream_exception : Test excpetion message.", e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_message_and_stack_frame) {
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {"Test excpetion message.", stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::io::end_of_stream_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = end_of_stream_exception {nullopt, inner_exception};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream.", e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(constructor_with_nullopt_message_and_stack_frame_inner_exception) {
      auto inner_exception = argument_exception {};
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {nullopt, inner_exception, stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_not_null(e.inner_exception());
      assert::is_instance_of<xtd::argument_exception>(e.inner_exception().value().get());
      assert::are_equal("Attempted to read past the end of the stream.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::io::end_of_stream_exception : Attempted to read past the end of the stream." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Attempted to read past the end of the stream.", e.what());
    }
    
    void test_method_(constructor_with_message_and_inner_exception) {
      auto inner_exception = argument_exception {};
      auto e = end_of_stream_exception {"Test excpetion message.", inner_exception};
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
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
      string_assert::starts_with("xtd::io::end_of_stream_exception : Test excpetion message.", e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_message_inner_exception_and_stack_frame) {
      auto inner_exception = argument_exception {};
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = end_of_stream_exception {"Test excpetion message.", inner_exception, stack_frame};
      assert::are_equal("xtd::io::end_of_stream_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::COR_E_ENDOFSTREAM, e.h_result());
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
      assert::are_equal("xtd::io::end_of_stream_exception : Test excpetion message." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("Test excpetion message.", e.what());
    }
  };
}
