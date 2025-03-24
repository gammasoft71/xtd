#include <xtd/net/sockets/socket_exception>
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
using namespace xtd::net;
using namespace xtd::reflection;
using namespace xtd::tunit;

namespace xtd::net::sockets::tests {
  class test_class_(socket_exception_tests) {
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
    
    void test_method_(default_constructor) {
      auto e = socket_exception {};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      string_assert::starts_with("xtd::net::sockets::socket_exception : The operation completed successfully.", e.to_string());
      assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(default_constructor_with_stack_frame) {
      auto stack_frame = xtd::diagnostics::stack_frame::current();
      auto e = socket_exception {stack_frame};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(stack_frame.to_string(), e.stack_trace());
      assert::are_equal(stack_frame.get_file_name(), e.get_last_stack_frame().get_file_name());
      assert::are_equal(stack_frame.get_file_line_number(), e.get_last_stack_frame().get_file_line_number());
      assert::are_equal(stack_frame.get_method(), e.get_last_stack_frame().get_method());
      assert::are_equal("xtd::net::sockets::socket_exception : The operation completed successfully." + environment::new_line() + stack_frame.to_string(), e.to_string());
      assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error) {
      auto e = socket_exception {socket_error::sock_error};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: -1", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success) {
      auto e = socket_exception {socket_error::success};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : The operation completed successfully.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted) {
      auto e = socket_exception {socket_error::operation_aborted};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 995", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending) {
      auto e = socket_exception {socket_error::io_pending};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 997", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted) {
      auto e = socket_exception {socket_error::interrupted};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Interrupted system call", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied) {
      auto e = socket_exception {socket_error::access_denied};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Permission denied", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault) {
      auto e = socket_exception {socket_error::fault};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Bad address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument) {
      auto e = socket_exception {socket_error::invalid_argument};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Invalid argument", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets) {
      auto e = socket_exception {socket_error::too_many_open_sockets};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many open files", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block) {
      auto e = socket_exception {socket_error::would_block};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Resource temporarily unavailable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress) {
      auto e = socket_exception {socket_error::in_progress};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation now in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress) {
      auto e = socket_exception {socket_error::already_in_progress};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation already in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket) {
      auto e = socket_exception {socket_error::not_socket};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket operation on non-socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required) {
      auto e = socket_exception {socket_error::destination_address_required};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Destination address required", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size) {
      auto e = socket_exception {socket_error::message_size};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Message too long", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type) {
      auto e = socket_exception {socket_error::protocol_type};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol wrong type for socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option) {
      auto e = socket_exception {socket_error::protocol_option};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported) {
      auto e = socket_exception {socket_error::protocol_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported) {
      auto e = socket_exception {socket_error::socket_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket type not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported) {
      auto e = socket_exception {socket_error::operation_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported) {
      auto e = socket_exception {socket_error::protocol_family_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol family not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported) {
      auto e = socket_exception {socket_error::address_family_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address family not supported by protocol family", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use) {
      auto e = socket_exception {socket_error::address_already_in_use};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address already in use", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available) {
      auto e = socket_exception {socket_error::address_not_available};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't assign requested address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down) {
      auto e = socket_exception {socket_error::network_down};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable) {
      auto e = socket_exception {socket_error::network_unreachable};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is unreachable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset) {
      auto e = socket_exception {socket_error::network_reset};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network dropped connection on reset", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted) {
      auto e = socket_exception {socket_error::connection_aborted};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Software caused connection abort", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset) {
      auto e = socket_exception {socket_error::connection_reset};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection reset by peer", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available) {
      auto e = socket_exception {socket_error::no_buffer_space_available};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No buffer space available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected) {
      auto e = socket_exception {socket_error::is_connected};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is already connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected) {
      auto e = socket_exception {socket_error::not_connected};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is not connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown) {
      auto e = socket_exception {socket_error::shutdown};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't send after socket shutdown", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out) {
      auto e = socket_exception {socket_error::timed_out};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation timed out", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused) {
      auto e = socket_exception {socket_error::connection_refused};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection refused", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down) {
      auto e = socket_exception {socket_error::host_down};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Host is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable) {
      auto e = socket_exception {socket_error::host_unreachable};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No route to host", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit) {
      auto e = socket_exception {socket_error::process_limit};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many processes", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready) {
      auto e = socket_exception {socket_error::system_not_ready};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10091", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported) {
      auto e = socket_exception {socket_error::version_not_supported};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : RPC version wrong", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized) {
      auto e = socket_exception {socket_error::not_initialized};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10093", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting) {
      auto e = socket_exception {socket_error::disconnecting};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10101", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found) {
      auto e = socket_exception {socket_error::type_not_found};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10109", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found) {
      auto e = socket_exception {socket_error::host_not_found};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11001", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again) {
      auto e = socket_exception {socket_error::try_again};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11002", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery) {
      auto e = socket_exception {socket_error::no_recovery};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11003", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data) {
      auto e = socket_exception {socket_error::no_data};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11004", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.what());
    }
    
    void test_method_(constructor_with_undefined_socket_error) {
      auto e = socket_exception {static_cast<socket_error>(486)};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 486", e.message());
      assert::are_equal(static_cast<socket_error>(486), e.socket_error());
      assert::are_equal(486, e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 486", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 486", e.what());
    }

    void test_method_(constructor_with_socket_error_sock_error_as_int) {
      auto e = socket_exception {enum_object {socket_error::sock_error}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: -1", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_as_int) {
      auto e = socket_exception {enum_object {socket_error::success}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : The operation completed successfully.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_as_int) {
      auto e = socket_exception {enum_object {socket_error::operation_aborted}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 995", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_as_int) {
      auto e = socket_exception {enum_object {socket_error::io_pending}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 997", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_as_int) {
      auto e = socket_exception {enum_object {socket_error::interrupted}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Interrupted system call", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_as_int) {
      auto e = socket_exception {enum_object {socket_error::access_denied}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Permission denied", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_as_int) {
      auto e = socket_exception {enum_object {socket_error::fault}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Bad address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_as_int) {
      auto e = socket_exception {enum_object {socket_error::invalid_argument}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Invalid argument", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_as_int) {
      auto e = socket_exception {enum_object {socket_error::too_many_open_sockets}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many open files", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_as_int) {
      auto e = socket_exception {enum_object {socket_error::would_block}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Resource temporarily unavailable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_as_int) {
      auto e = socket_exception {enum_object {socket_error::in_progress}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation now in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_as_int) {
      auto e = socket_exception {enum_object {socket_error::already_in_progress}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation already in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_as_int) {
      auto e = socket_exception {enum_object {socket_error::not_socket}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket operation on non-socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_as_int) {
      auto e = socket_exception {enum_object {socket_error::destination_address_required}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Destination address required", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_as_int) {
      auto e = socket_exception {enum_object {socket_error::message_size}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Message too long", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_as_int) {
      auto e = socket_exception {enum_object {socket_error::protocol_type}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol wrong type for socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_as_int) {
      auto e = socket_exception {enum_object {socket_error::protocol_option}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::protocol_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::socket_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket type not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::operation_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::protocol_family_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol family not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::address_family_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address family not supported by protocol family", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_as_int) {
      auto e = socket_exception {enum_object {socket_error::address_already_in_use}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address already in use", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_as_int) {
      auto e = socket_exception {enum_object {socket_error::address_not_available}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't assign requested address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_as_int) {
      auto e = socket_exception {enum_object {socket_error::network_down}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_as_int) {
      auto e = socket_exception {enum_object {socket_error::network_unreachable}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is unreachable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_as_int) {
      auto e = socket_exception {enum_object {socket_error::network_reset}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network dropped connection on reset", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_as_int) {
      auto e = socket_exception {enum_object {socket_error::connection_aborted}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Software caused connection abort", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_as_int) {
      auto e = socket_exception {enum_object {socket_error::connection_reset}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection reset by peer", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_as_int) {
      auto e = socket_exception {enum_object {socket_error::no_buffer_space_available}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No buffer space available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_as_int) {
      auto e = socket_exception {enum_object {socket_error::is_connected}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is already connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_as_int) {
      auto e = socket_exception {enum_object {socket_error::not_connected}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is not connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_as_int) {
      auto e = socket_exception {enum_object {socket_error::shutdown}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't send after socket shutdown", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_as_int) {
      auto e = socket_exception {enum_object {socket_error::timed_out}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation timed out", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_as_int) {
      auto e = socket_exception {enum_object {socket_error::connection_refused}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection refused", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_as_int) {
      auto e = socket_exception {enum_object {socket_error::host_down}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Host is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_as_int) {
      auto e = socket_exception {enum_object {socket_error::host_unreachable}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No route to host", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_as_int) {
      auto e = socket_exception {enum_object {socket_error::process_limit}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many processes", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_as_int) {
      auto e = socket_exception {enum_object {socket_error::system_not_ready}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10091", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_as_int) {
      auto e = socket_exception {enum_object {socket_error::version_not_supported}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : RPC version wrong", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_as_int) {
      auto e = socket_exception {enum_object {socket_error::not_initialized}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10093", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_as_int) {
      auto e = socket_exception {enum_object {socket_error::disconnecting}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10101", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_as_int) {
      auto e = socket_exception {enum_object {socket_error::type_not_found}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10109", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_as_int) {
      auto e = socket_exception {enum_object {socket_error::host_not_found}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11001", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_as_int) {
      auto e = socket_exception {enum_object {socket_error::try_again}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11002", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_as_int) {
      auto e = socket_exception {enum_object {socket_error::no_recovery}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11003", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_as_int) {
      auto e = socket_exception {enum_object {socket_error::no_data}.to_int32()};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11004", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_and_nullopt) {
      auto e = socket_exception {socket_error::sock_error, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: -1", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_and_nullopt) {
      auto e = socket_exception {socket_error::success, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : The operation completed successfully.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_and_nullopt) {
      auto e = socket_exception {socket_error::operation_aborted, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 995", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_and_nullopt) {
      auto e = socket_exception {socket_error::io_pending, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 997", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_and_nullopt) {
      auto e = socket_exception {socket_error::interrupted, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Interrupted system call", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_and_nullopt) {
      auto e = socket_exception {socket_error::access_denied, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Permission denied", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_and_nullopt) {
      auto e = socket_exception {socket_error::fault, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Bad address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_and_nullopt) {
      auto e = socket_exception {socket_error::invalid_argument, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Invalid argument", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_and_nullopt) {
      auto e = socket_exception {socket_error::too_many_open_sockets, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many open files", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_and_nullopt) {
      auto e = socket_exception {socket_error::would_block, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Resource temporarily unavailable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_and_nullopt) {
      auto e = socket_exception {socket_error::in_progress, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation now in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_and_nullopt) {
      auto e = socket_exception {socket_error::already_in_progress, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation already in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_and_nullopt) {
      auto e = socket_exception {socket_error::not_socket, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket operation on non-socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_and_nullopt) {
      auto e = socket_exception {socket_error::destination_address_required, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Destination address required", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_and_nullopt) {
      auto e = socket_exception {socket_error::message_size, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Message too long", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_and_nullopt) {
      auto e = socket_exception {socket_error::protocol_type, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol wrong type for socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_and_nullopt) {
      auto e = socket_exception {socket_error::protocol_option, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::protocol_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::socket_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket type not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::operation_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::protocol_family_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol family not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::address_family_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address family not supported by protocol family", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_and_nullopt) {
      auto e = socket_exception {socket_error::address_already_in_use, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address already in use", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_and_nullopt) {
      auto e = socket_exception {socket_error::address_not_available, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't assign requested address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_and_nullopt) {
      auto e = socket_exception {socket_error::network_down, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_and_nullopt) {
      auto e = socket_exception {socket_error::network_unreachable, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is unreachable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_and_nullopt) {
      auto e = socket_exception {socket_error::network_reset, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network dropped connection on reset", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_and_nullopt) {
      auto e = socket_exception {socket_error::connection_aborted, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Software caused connection abort", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_and_nullopt) {
      auto e = socket_exception {socket_error::connection_reset, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection reset by peer", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_and_nullopt) {
      auto e = socket_exception {socket_error::no_buffer_space_available, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No buffer space available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_and_nullopt) {
      auto e = socket_exception {socket_error::is_connected, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is already connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_and_nullopt) {
      auto e = socket_exception {socket_error::not_connected, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is not connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_and_nullopt) {
      auto e = socket_exception {socket_error::shutdown, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't send after socket shutdown", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_and_nullopt) {
      auto e = socket_exception {socket_error::timed_out, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation timed out", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_and_nullopt) {
      auto e = socket_exception {socket_error::connection_refused, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection refused", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_and_nullopt) {
      auto e = socket_exception {socket_error::host_down, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Host is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_and_nullopt) {
      auto e = socket_exception {socket_error::host_unreachable, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No route to host", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_and_nullopt) {
      auto e = socket_exception {socket_error::process_limit, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many processes", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_and_nullopt) {
      auto e = socket_exception {socket_error::system_not_ready, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10091", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_and_nullopt) {
      auto e = socket_exception {socket_error::version_not_supported, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : RPC version wrong", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_and_nullopt) {
      auto e = socket_exception {socket_error::not_initialized, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10093", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_and_nullopt) {
      auto e = socket_exception {socket_error::disconnecting, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10101", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_and_nullopt) {
      auto e = socket_exception {socket_error::type_not_found, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10109", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_and_nullopt) {
      auto e = socket_exception {socket_error::host_not_found, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11001", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_and_nullopt) {
      auto e = socket_exception {socket_error::try_again, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11002", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_and_nullopt) {
      auto e = socket_exception {socket_error::no_recovery, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11003", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_and_nullopt) {
      auto e = socket_exception {socket_error::no_data, nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11004", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::sock_error}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: -1", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: -1", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::success}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : The operation completed successfully.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("The operation completed successfully.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::operation_aborted}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 995", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 995", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::io_pending}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 997", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 997", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::interrupted}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Interrupted system call", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Interrupted system call", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::access_denied}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Permission denied", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Permission denied", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::fault}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Bad address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Bad address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::invalid_argument}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Invalid argument", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Invalid argument", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::too_many_open_sockets}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many open files", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many open files", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::would_block}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Resource temporarily unavailable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Resource temporarily unavailable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::in_progress}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation now in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation now in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::already_in_progress}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation already in progress", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation already in progress", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::not_socket}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket operation on non-socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket operation on non-socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::destination_address_required}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Destination address required", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Destination address required", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::message_size}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Message too long", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Message too long", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::protocol_type}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol wrong type for socket", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol wrong type for socket", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::protocol_option}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::protocol_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::socket_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket type not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket type not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::operation_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::protocol_family_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Protocol family not supported", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Protocol family not supported", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::address_family_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address family not supported by protocol family", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address family not supported by protocol family", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::address_already_in_use}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Address already in use", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Address already in use", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::address_not_available}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't assign requested address", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't assign requested address", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::network_down}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::network_unreachable}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network is unreachable", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network is unreachable", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::network_reset}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Network dropped connection on reset", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Network dropped connection on reset", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::connection_aborted}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Software caused connection abort", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Software caused connection abort", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::connection_reset}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection reset by peer", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection reset by peer", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::no_buffer_space_available}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No buffer space available", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No buffer space available", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::is_connected}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is already connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is already connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::not_connected}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Socket is not connected", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Socket is not connected", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::shutdown}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Can't send after socket shutdown", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Can't send after socket shutdown", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::timed_out}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Operation timed out", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Operation timed out", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::connection_refused}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Connection refused", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Connection refused", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::host_down}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Host is down", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Host is down", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::host_unreachable}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : No route to host", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("No route to host", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::process_limit}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Too many processes", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Too many processes", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::system_not_ready}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10091", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10091", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::version_not_supported}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : RPC version wrong", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("RPC version wrong", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::not_initialized}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10093", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10093", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::disconnecting}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10101", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10101", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::type_not_found}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 10109", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 10109", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::host_not_found}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11001", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11001", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::try_again}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11002", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11002", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::no_recovery}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11003", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11003", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_as_int_and_nullopt) {
      auto e = socket_exception {enum_object {socket_error::no_data}.to_int32(), nullopt};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Unknown error: 11004", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Unknown error: 11004", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_and_empty_message) {
      auto e = socket_exception {socket_error::sock_error, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_and_empty_message) {
      auto e = socket_exception {socket_error::success, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_and_empty_message) {
      auto e = socket_exception {socket_error::operation_aborted, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_and_empty_message) {
      auto e = socket_exception {socket_error::io_pending, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_and_empty_message) {
      auto e = socket_exception {socket_error::interrupted, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_and_empty_message) {
      auto e = socket_exception {socket_error::access_denied, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_and_empty_message) {
      auto e = socket_exception {socket_error::fault, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_and_empty_message) {
      auto e = socket_exception {socket_error::invalid_argument, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_and_empty_message) {
      auto e = socket_exception {socket_error::too_many_open_sockets, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_and_empty_message) {
      auto e = socket_exception {socket_error::would_block, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_and_empty_message) {
      auto e = socket_exception {socket_error::in_progress, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_and_empty_message) {
      auto e = socket_exception {socket_error::already_in_progress, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_and_empty_message) {
      auto e = socket_exception {socket_error::not_socket, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_and_empty_message) {
      auto e = socket_exception {socket_error::destination_address_required, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_and_empty_message) {
      auto e = socket_exception {socket_error::message_size, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_and_empty_message) {
      auto e = socket_exception {socket_error::protocol_type, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_and_empty_message) {
      auto e = socket_exception {socket_error::protocol_option, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::protocol_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::socket_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::operation_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::protocol_family_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::address_family_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_and_empty_message) {
      auto e = socket_exception {socket_error::address_already_in_use, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_and_empty_message) {
      auto e = socket_exception {socket_error::address_not_available, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_and_empty_message) {
      auto e = socket_exception {socket_error::network_down, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_and_empty_message) {
      auto e = socket_exception {socket_error::network_unreachable, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_and_empty_message) {
      auto e = socket_exception {socket_error::network_reset, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_and_empty_message) {
      auto e = socket_exception {socket_error::connection_aborted, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_and_empty_message) {
      auto e = socket_exception {socket_error::connection_reset, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_and_empty_message) {
      auto e = socket_exception {socket_error::no_buffer_space_available, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_and_empty_message) {
      auto e = socket_exception {socket_error::is_connected, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_and_empty_message) {
      auto e = socket_exception {socket_error::not_connected, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_and_empty_message) {
      auto e = socket_exception {socket_error::shutdown, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_and_empty_message) {
      auto e = socket_exception {socket_error::timed_out, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_and_empty_message) {
      auto e = socket_exception {socket_error::connection_refused, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_and_empty_message) {
      auto e = socket_exception {socket_error::host_down, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_and_empty_message) {
      auto e = socket_exception {socket_error::host_unreachable, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_and_empty_message) {
      auto e = socket_exception {socket_error::process_limit, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_and_empty_message) {
      auto e = socket_exception {socket_error::system_not_ready, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_and_empty_message) {
      auto e = socket_exception {socket_error::version_not_supported, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_and_empty_message) {
      auto e = socket_exception {socket_error::not_initialized, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_and_empty_message) {
      auto e = socket_exception {socket_error::disconnecting, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_and_empty_message) {
      auto e = socket_exception {socket_error::type_not_found, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_and_empty_message) {
      auto e = socket_exception {socket_error::host_not_found, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_and_empty_message) {
      auto e = socket_exception {socket_error::try_again, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_and_empty_message) {
      auto e = socket_exception {socket_error::no_recovery, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_and_empty_message) {
      auto e = socket_exception {socket_error::no_data, ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::sock_error}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::success}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::operation_aborted}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::io_pending}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::interrupted}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::access_denied}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::fault}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::invalid_argument}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::too_many_open_sockets}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::would_block}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::in_progress}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::already_in_progress}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::not_socket}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::destination_address_required}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::message_size}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_type}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_option}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::socket_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::operation_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_family_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::address_family_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::address_already_in_use}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::address_not_available}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::network_down}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::network_unreachable}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::network_reset}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::connection_aborted}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::connection_reset}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::no_buffer_space_available}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::is_connected}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::not_connected}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::shutdown}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::timed_out}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::connection_refused}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::host_down}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::host_unreachable}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::process_limit}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::system_not_ready}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::version_not_supported}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::not_initialized}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::disconnecting}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::type_not_found}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::host_not_found}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::try_again}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::no_recovery}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_as_int_and_empty_message) {
      auto e = socket_exception {enum_object {socket_error::no_data}.to_int32(), ""};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("xtd::net::sockets::socket_exception", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_and_message) {
      auto e = socket_exception {socket_error::sock_error, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_and_message) {
      auto e = socket_exception {socket_error::success, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_and_message) {
      auto e = socket_exception {socket_error::operation_aborted, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_and_message) {
      auto e = socket_exception {socket_error::io_pending, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_and_message) {
      auto e = socket_exception {socket_error::interrupted, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_and_message) {
      auto e = socket_exception {socket_error::access_denied, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_and_message) {
      auto e = socket_exception {socket_error::fault, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_and_message) {
      auto e = socket_exception {socket_error::invalid_argument, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_and_message) {
      auto e = socket_exception {socket_error::too_many_open_sockets, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_and_message) {
      auto e = socket_exception {socket_error::would_block, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_and_message) {
      auto e = socket_exception {socket_error::in_progress, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_and_message) {
      auto e = socket_exception {socket_error::already_in_progress, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_and_message) {
      auto e = socket_exception {socket_error::not_socket, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_and_message) {
      auto e = socket_exception {socket_error::destination_address_required, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_and_message) {
      auto e = socket_exception {socket_error::message_size, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_and_message) {
      auto e = socket_exception {socket_error::protocol_type, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_and_message) {
      auto e = socket_exception {socket_error::protocol_option, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_and_message) {
      auto e = socket_exception {socket_error::protocol_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_and_message) {
      auto e = socket_exception {socket_error::socket_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_and_message) {
      auto e = socket_exception {socket_error::operation_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_and_message) {
      auto e = socket_exception {socket_error::protocol_family_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_and_message) {
      auto e = socket_exception {socket_error::address_family_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_and_message) {
      auto e = socket_exception {socket_error::address_already_in_use, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_and_message) {
      auto e = socket_exception {socket_error::address_not_available, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_and_message) {
      auto e = socket_exception {socket_error::network_down, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_and_message) {
      auto e = socket_exception {socket_error::network_unreachable, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_and_message) {
      auto e = socket_exception {socket_error::network_reset, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_and_message) {
      auto e = socket_exception {socket_error::connection_aborted, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_and_message) {
      auto e = socket_exception {socket_error::connection_reset, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_and_message) {
      auto e = socket_exception {socket_error::no_buffer_space_available, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_and_message) {
      auto e = socket_exception {socket_error::is_connected, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_and_message) {
      auto e = socket_exception {socket_error::not_connected, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_and_message) {
      auto e = socket_exception {socket_error::shutdown, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_and_message) {
      auto e = socket_exception {socket_error::timed_out, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_and_message) {
      auto e = socket_exception {socket_error::connection_refused, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_and_message) {
      auto e = socket_exception {socket_error::host_down, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_and_message) {
      auto e = socket_exception {socket_error::host_unreachable, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_and_message) {
      auto e = socket_exception {socket_error::process_limit, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_and_message) {
      auto e = socket_exception {socket_error::system_not_ready, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_and_message) {
      auto e = socket_exception {socket_error::version_not_supported, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_and_message) {
      auto e = socket_exception {socket_error::not_initialized, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_and_message) {
      auto e = socket_exception {socket_error::disconnecting, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_and_message) {
      auto e = socket_exception {socket_error::type_not_found, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_and_message) {
      auto e = socket_exception {socket_error::host_not_found, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_and_message) {
      auto e = socket_exception {socket_error::try_again, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_and_message) {
      auto e = socket_exception {socket_error::no_recovery, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_and_message) {
      auto e = socket_exception {socket_error::no_data, "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_sock_error_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::sock_error}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::sock_error, e.socket_error());
      assert::are_equal(enum_object {socket_error::sock_error}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_success_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::success}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::success, e.socket_error());
      assert::are_equal(enum_object {socket_error::success}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_aborted_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::operation_aborted}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::operation_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_io_pending_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::io_pending}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::io_pending, e.socket_error());
      assert::are_equal(enum_object {socket_error::io_pending}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_interrupted_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::interrupted}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::interrupted, e.socket_error());
      assert::are_equal(enum_object {socket_error::interrupted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_access_denied_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::access_denied}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::access_denied, e.socket_error());
      assert::are_equal(enum_object {socket_error::access_denied}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_fault_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::fault}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::fault, e.socket_error());
      assert::are_equal(enum_object {socket_error::fault}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_invalid_argument_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::invalid_argument}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::invalid_argument, e.socket_error());
      assert::are_equal(enum_object {socket_error::invalid_argument}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_too_many_open_sockets_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::too_many_open_sockets}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::too_many_open_sockets, e.socket_error());
      assert::are_equal(enum_object {socket_error::too_many_open_sockets}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_would_block_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::would_block}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::would_block, e.socket_error());
      assert::are_equal(enum_object {socket_error::would_block}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_in_progress_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::in_progress}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_already_in_progress_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::already_in_progress}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::already_in_progress, e.socket_error());
      assert::are_equal(enum_object {socket_error::already_in_progress}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_socket_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::not_socket}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_socket, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_socket}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_destination_address_required_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::destination_address_required}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::destination_address_required, e.socket_error());
      assert::are_equal(enum_object {socket_error::destination_address_required}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_message_size_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::message_size}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::message_size, e.socket_error());
      assert::are_equal(enum_object {socket_error::message_size}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_type_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_type}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_type, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_type}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_option_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_option}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_option, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_option}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_socket_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::socket_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::socket_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::socket_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_operation_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::operation_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::operation_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::operation_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_protocol_family_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::protocol_family_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::protocol_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::protocol_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_family_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::address_family_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_family_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_family_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_already_in_use_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::address_already_in_use}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_already_in_use, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_already_in_use}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_address_not_available_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::address_not_available}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::address_not_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::address_not_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_down_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::network_down}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_unreachable_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::network_unreachable}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_network_reset_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::network_reset}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::network_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::network_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_aborted_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::connection_aborted}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_aborted, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_aborted}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_reset_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::connection_reset}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_reset, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_reset}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_buffer_space_available_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::no_buffer_space_available}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_buffer_space_available, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_buffer_space_available}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_is_connected_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::is_connected}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::is_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::is_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_connected_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::not_connected}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_connected, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_connected}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_shutdown_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::shutdown}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::shutdown, e.socket_error());
      assert::are_equal(enum_object {socket_error::shutdown}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_timed_out_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::timed_out}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::timed_out, e.socket_error());
      assert::are_equal(enum_object {socket_error::timed_out}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_connection_refused_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::connection_refused}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::connection_refused, e.socket_error());
      assert::are_equal(enum_object {socket_error::connection_refused}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_down_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::host_down}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_down, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_down}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_unreachable_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::host_unreachable}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_unreachable, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_unreachable}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_process_limit_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::process_limit}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::process_limit, e.socket_error());
      assert::are_equal(enum_object {socket_error::process_limit}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_system_not_ready_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::system_not_ready}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::system_not_ready, e.socket_error());
      assert::are_equal(enum_object {socket_error::system_not_ready}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_version_not_supported_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::version_not_supported}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::version_not_supported, e.socket_error());
      assert::are_equal(enum_object {socket_error::version_not_supported}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_not_initialized_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::not_initialized}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::not_initialized, e.socket_error());
      assert::are_equal(enum_object {socket_error::not_initialized}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_disconnecting_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::disconnecting}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::disconnecting, e.socket_error());
      assert::are_equal(enum_object {socket_error::disconnecting}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_type_not_found_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::type_not_found}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::type_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::type_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_host_not_found_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::host_not_found}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::host_not_found, e.socket_error());
      assert::are_equal(enum_object {socket_error::host_not_found}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_try_again_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::try_again}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::try_again, e.socket_error());
      assert::are_equal(enum_object {socket_error::try_again}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_recovery_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::no_recovery}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_recovery, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_recovery}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
    void test_method_(constructor_with_socket_error_no_data_as_int_and_message) {
      auto e = socket_exception {enum_object {socket_error::no_data}.to_int32(), "Test excpetion message."};
      assert::are_equal("xtd::net::sockets::socket_exception", e.get_type().full_name());
      assert::is_empty(e.help_link());
      assert::are_equal(h_result::E_FAIL, e.h_result());
      assert::are_equal(h_result::h_result_category(), e.error_code().category());
      assert::are_equal(e.h_result(), e.error_code().value());
      assert::is_null(e.inner_exception());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.message());
      assert::are_equal(socket_error::no_data, e.socket_error());
      assert::are_equal(enum_object {socket_error::no_data}.to_int32(), e.socket_error_code());
      assert::are_equal(path::get_file_name(assembly::get_executing_assembly().location()), e.source());
      assert::is_not_empty(e.stack_trace());
      assert::is_not_empty(e.get_last_stack_frame().get_file_name());
      assert::is_not_zero(e.get_last_stack_frame().get_file_line_number());
      assert::is_not_empty(e.get_last_stack_frame().get_method());
      if (environment::os_version().is_macos()) string_assert::starts_with("xtd::net::sockets::socket_exception : Test excpetion message.", e.to_string());
      if (environment::os_version().is_macos()) assert::are_equal("Test excpetion message.", e.what());
    }
    
  };
}
