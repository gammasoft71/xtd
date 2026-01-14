#include <xtd/helpers/exception_case.hpp>
#include <xtd/enum_set_attribute.hpp>
#include <xtd/tunit/constraints/assert_that.hpp>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::helpers;

namespace xtd::helpers::tests {
  class test_class_(exception_case_tests) {
    auto test_method_(abandoned_mutex) {
      assert_that(enum_object<>::to_int32(exception_case::abandoned_mutex)).is().equal_to(0);
      assert_that(enum_object<>::to_string(exception_case::abandoned_mutex)).is().equal_to("abandoned_mutex");
      assert_that(enum_object<>::parse<exception_case>("abandoned_mutex")).is().equal_to(exception_case::abandoned_mutex);
    }
    
    auto test_method_(access_violation) {
      assert_that(enum_object<>::to_int32(exception_case::access_violation)).is().equal_to(1);
      assert_that(enum_object<>::to_string(exception_case::access_violation)).is().equal_to("access_violation");
      assert_that(enum_object<>::parse<exception_case>("access_violation")).is().equal_to(exception_case::access_violation);
    }
    
    auto test_method_(argument) {
      assert_that(enum_object<>::to_int32(exception_case::argument)).is().equal_to(2);
      assert_that(enum_object<>::to_string(exception_case::argument)).is().equal_to("argument");
      assert_that(enum_object<>::parse<exception_case>("argument")).is().equal_to(exception_case::argument);
    }
    
    auto test_method_(argument_null) {
      assert_that(enum_object<>::to_int32(exception_case::argument_null)).is().equal_to(3);
      assert_that(enum_object<>::to_string(exception_case::argument_null)).is().equal_to("argument_null");
      assert_that(enum_object<>::parse<exception_case>("argument_null")).is().equal_to(exception_case::argument_null);
    }
    
    auto test_method_(argument_out_of_range) {
      assert_that(enum_object<>::to_int32(exception_case::argument_out_of_range)).is().equal_to(4);
      assert_that(enum_object<>::to_string(exception_case::argument_out_of_range)).is().equal_to("argument_out_of_range");
      assert_that(enum_object<>::parse<exception_case>("argument_out_of_range")).is().equal_to(exception_case::argument_out_of_range);
    }
    
    auto test_method_(arithmetic) {
      assert_that(enum_object<>::to_int32(exception_case::arithmetic)).is().equal_to(5);
      assert_that(enum_object<>::to_string(exception_case::arithmetic)).is().equal_to("arithmetic");
      assert_that(enum_object<>::parse<exception_case>("arithmetic")).is().equal_to(exception_case::arithmetic);
    }
    
    auto test_method_(barrier_post_phase) {
      assert_that(enum_object<>::to_int32(exception_case::barrier_post_phase)).is().equal_to(6);
      assert_that(enum_object<>::to_string(exception_case::barrier_post_phase)).is().equal_to("barrier_post_phase");
      assert_that(enum_object<>::parse<exception_case>("barrier_post_phase")).is().equal_to(exception_case::barrier_post_phase);
    }
    
    auto test_method_(culture_not_found) {
      assert_that(enum_object<>::to_int32(exception_case::culture_not_found)).is().equal_to(7);
      assert_that(enum_object<>::to_string(exception_case::culture_not_found)).is().equal_to("culture_not_found");
      assert_that(enum_object<>::parse<exception_case>("culture_not_found")).is().equal_to(exception_case::culture_not_found);
    }
    
    auto test_method_(directory_not_found) {
      assert_that(enum_object<>::to_int32(exception_case::directory_not_found)).is().equal_to(8);
      assert_that(enum_object<>::to_string(exception_case::directory_not_found)).is().equal_to("directory_not_found");
      assert_that(enum_object<>::parse<exception_case>("directory_not_found")).is().equal_to(exception_case::directory_not_found);
    }
    
    auto test_method_(divided_by_zero) {
      assert_that(enum_object<>::to_int32(exception_case::divided_by_zero)).is().equal_to(9);
      assert_that(enum_object<>::to_string(exception_case::divided_by_zero)).is().equal_to("divided_by_zero");
      assert_that(enum_object<>::parse<exception_case>("divided_by_zero")).is().equal_to(exception_case::divided_by_zero);
    }
    
    auto test_method_(end_of_stream) {
      assert_that(enum_object<>::to_int32(exception_case::end_of_stream)).is().equal_to(10);
      assert_that(enum_object<>::to_string(exception_case::end_of_stream)).is().equal_to("end_of_stream");
      assert_that(enum_object<>::parse<exception_case>("end_of_stream")).is().equal_to(exception_case::end_of_stream);
    }
    
    auto test_method_(file_not_found) {
      assert_that(enum_object<>::to_int32(exception_case::file_not_found)).is().equal_to(11);
      assert_that(enum_object<>::to_string(exception_case::file_not_found)).is().equal_to("file_not_found");
      assert_that(enum_object<>::parse<exception_case>("file_not_found")).is().equal_to(exception_case::file_not_found);
    }
    
    auto test_method_(format) {
      assert_that(enum_object<>::to_int32(exception_case::format)).is().equal_to(12);
      assert_that(enum_object<>::to_string(exception_case::format)).is().equal_to("format");
      assert_that(enum_object<>::parse<exception_case>("format")).is().equal_to(exception_case::format);
    }
    
    auto test_method_(format_closing_bracket_without_open_bracket) {
      assert_that(enum_object<>::to_int32(exception_case::format_closing_bracket_without_open_bracket)).is().equal_to(13);
      assert_that(enum_object<>::to_string(exception_case::format_closing_bracket_without_open_bracket)).is().equal_to("format_closing_bracket_without_open_bracket");
      assert_that(enum_object<>::parse<exception_case>("format_closing_bracket_without_open_bracket")).is().equal_to(exception_case::format_closing_bracket_without_open_bracket);
    }
    
    auto test_method_(format_opened_bracket_without_end_bracket) {
      assert_that(enum_object<>::to_int32(exception_case::format_opened_bracket_without_end_bracket)).is().equal_to(14);
      assert_that(enum_object<>::to_string(exception_case::format_opened_bracket_without_end_bracket)).is().equal_to("format_opened_bracket_without_end_bracket");
      assert_that(enum_object<>::parse<exception_case>("format_opened_bracket_without_end_bracket")).is().equal_to(exception_case::format_opened_bracket_without_end_bracket);
    }
    
    auto test_method_(format_no_start_colon) {
      assert_that(enum_object<>::to_int32(exception_case::format_no_start_colon)).is().equal_to(15);
      assert_that(enum_object<>::to_string(exception_case::format_no_start_colon)).is().equal_to("format_no_start_colon");
      assert_that(enum_object<>::parse<exception_case>("format_no_start_colon")).is().equal_to(exception_case::format_no_start_colon);
    }
    
    auto test_method_(format_not_iformatable) {
      assert_that(enum_object<>::to_int32(exception_case::format_not_iformatable)).is().equal_to(16);
      assert_that(enum_object<>::to_string(exception_case::format_not_iformatable)).is().equal_to("format_not_iformatable");
      assert_that(enum_object<>::parse<exception_case>("format_not_iformatable")).is().equal_to(exception_case::format_not_iformatable);
    }
    
    auto test_method_(index_out_of_range) {
      assert_that(enum_object<>::to_int32(exception_case::index_out_of_range)).is().equal_to(17);
      assert_that(enum_object<>::to_string(exception_case::index_out_of_range)).is().equal_to("index_out_of_range");
      assert_that(enum_object<>::parse<exception_case>("index_out_of_range")).is().equal_to(exception_case::index_out_of_range);
    }
    
    auto test_method_(invalid_cast) {
      assert_that(enum_object<>::to_int32(exception_case::invalid_cast)).is().equal_to(18);
      assert_that(enum_object<>::to_string(exception_case::invalid_cast)).is().equal_to("invalid_cast");
      assert_that(enum_object<>::parse<exception_case>("invalid_cast")).is().equal_to(exception_case::invalid_cast);
    }
    
    auto test_method_(invalid_operation) {
      assert_that(enum_object<>::to_int32(exception_case::invalid_operation)).is().equal_to(19);
      assert_that(enum_object<>::to_string(exception_case::invalid_operation)).is().equal_to("invalid_operation");
      assert_that(enum_object<>::parse<exception_case>("invalid_operation")).is().equal_to(exception_case::invalid_operation);
    }
    
    auto test_method_(interrupt) {
      assert_that(enum_object<>::to_int32(exception_case::interrupt)).is().equal_to(20);
      assert_that(enum_object<>::to_string(exception_case::interrupt)).is().equal_to("interrupt");
      assert_that(enum_object<>::parse<exception_case>("interrupt")).is().equal_to(exception_case::interrupt);
    }
    
    auto test_method_(io) {
      assert_that(enum_object<>::to_int32(exception_case::io)).is().equal_to(21);
      assert_that(enum_object<>::to_string(exception_case::io)).is().equal_to("io");
      assert_that(enum_object<>::parse<exception_case>("io")).is().equal_to(exception_case::io);
    }
    
    auto test_method_(key_not_found) {
      assert_that(enum_object<>::to_int32(exception_case::key_not_found)).is().equal_to(22);
      assert_that(enum_object<>::to_string(exception_case::key_not_found)).is().equal_to("key_not_found");
      assert_that(enum_object<>::parse<exception_case>("key_not_found")).is().equal_to(exception_case::key_not_found);
    }
    
    auto test_method_(lock_recursion) {
      assert_that(enum_object<>::to_int32(exception_case::lock_recursion)).is().equal_to(23);
      assert_that(enum_object<>::to_string(exception_case::lock_recursion)).is().equal_to("lock_recursion");
      assert_that(enum_object<>::parse<exception_case>("lock_recursion")).is().equal_to(exception_case::lock_recursion);
    }
    
    auto test_method_(not_implemented) {
      assert_that(enum_object<>::to_int32(exception_case::not_implemented)).is().equal_to(24);
      assert_that(enum_object<>::to_string(exception_case::not_implemented)).is().equal_to("not_implemented");
      assert_that(enum_object<>::parse<exception_case>("not_implemented")).is().equal_to(exception_case::not_implemented);
    }
    
    auto test_method_(not_supported) {
      assert_that(enum_object<>::to_int32(exception_case::not_supported)).is().equal_to(25);
      assert_that(enum_object<>::to_string(exception_case::not_supported)).is().equal_to("not_supported");
      assert_that(enum_object<>::parse<exception_case>("not_supported")).is().equal_to(exception_case::not_supported);
    }
    
    auto test_method_(null_pointer) {
      assert_that(enum_object<>::to_int32(exception_case::null_pointer)).is().equal_to(26);
      assert_that(enum_object<>::to_string(exception_case::null_pointer)).is().equal_to("null_pointer");
      assert_that(enum_object<>::parse<exception_case>("null_pointer")).is().equal_to(exception_case::null_pointer);
    }
    
    auto test_method_(object_closed) {
      assert_that(enum_object<>::to_int32(exception_case::object_closed)).is().equal_to(27);
      assert_that(enum_object<>::to_string(exception_case::object_closed)).is().equal_to("object_closed");
      assert_that(enum_object<>::parse<exception_case>("object_closed")).is().equal_to(exception_case::object_closed);
    }
    
    auto test_method_(operation_canceled) {
      assert_that(enum_object<>::to_int32(exception_case::operation_canceled)).is().equal_to(28);
      assert_that(enum_object<>::to_string(exception_case::operation_canceled)).is().equal_to("operation_canceled");
      assert_that(enum_object<>::parse<exception_case>("operation_canceled")).is().equal_to(exception_case::operation_canceled);
    }
    
    auto test_method_(overflow) {
      assert_that(enum_object<>::to_int32(exception_case::overflow)).is().equal_to(29);
      assert_that(enum_object<>::to_string(exception_case::overflow)).is().equal_to("overflow");
      assert_that(enum_object<>::parse<exception_case>("overflow")).is().equal_to(exception_case::overflow);
    }
    
    auto test_method_(out_of_memory) {
      assert_that(enum_object<>::to_int32(exception_case::out_of_memory)).is().equal_to(30);
      assert_that(enum_object<>::to_string(exception_case::out_of_memory)).is().equal_to("out_of_memory");
      assert_that(enum_object<>::parse<exception_case>("out_of_memory")).is().equal_to(exception_case::out_of_memory);
    }
    
    auto test_method_(path_too_long) {
      assert_that(enum_object<>::to_int32(exception_case::path_too_long)).is().equal_to(31);
      assert_that(enum_object<>::to_string(exception_case::path_too_long)).is().equal_to("path_too_long");
      assert_that(enum_object<>::parse<exception_case>("path_too_long")).is().equal_to(exception_case::path_too_long);
    }
    
    auto test_method_(platform_not_supported) {
      assert_that(enum_object<>::to_int32(exception_case::platform_not_supported)).is().equal_to(32);
      assert_that(enum_object<>::to_string(exception_case::platform_not_supported)).is().equal_to("platform_not_supported");
      assert_that(enum_object<>::parse<exception_case>("platform_not_supported")).is().equal_to(exception_case::platform_not_supported);
    }
    
    auto test_method_(rank) {
      assert_that(enum_object<>::to_int32(exception_case::rank)).is().equal_to(33);
      assert_that(enum_object<>::to_string(exception_case::rank)).is().equal_to("rank");
      assert_that(enum_object<>::parse<exception_case>("rank")).is().equal_to(exception_case::rank);
    }
    
    auto test_method_(semaphore_full) {
      assert_that(enum_object<>::to_int32(exception_case::semaphore_full)).is().equal_to(34);
      assert_that(enum_object<>::to_string(exception_case::semaphore_full)).is().equal_to("semaphore_full");
      assert_that(enum_object<>::parse<exception_case>("semaphore_full")).is().equal_to(exception_case::semaphore_full);
    }
    
    auto test_method_(socket) {
      assert_that(enum_object<>::to_int32(exception_case::socket)).is().equal_to(35);
      assert_that(enum_object<>::to_string(exception_case::socket)).is().equal_to("socket");
      assert_that(enum_object<>::parse<exception_case>("socket")).is().equal_to(exception_case::socket);
    }
    
    auto test_method_(software_termination) {
      assert_that(enum_object<>::to_int32(exception_case::software_termination)).is().equal_to(36);
      assert_that(enum_object<>::to_string(exception_case::software_termination)).is().equal_to("software_termination");
      assert_that(enum_object<>::parse<exception_case>("software_termination")).is().equal_to(exception_case::software_termination);
    }
    
    auto test_method_(synchronization_lock) {
      assert_that(enum_object<>::to_int32(exception_case::synchronization_lock)).is().equal_to(37);
      assert_that(enum_object<>::to_string(exception_case::synchronization_lock)).is().equal_to("synchronization_lock");
      assert_that(enum_object<>::parse<exception_case>("synchronization_lock")).is().equal_to(exception_case::synchronization_lock);
    }
    
    auto test_method_(thread_abort) {
      assert_that(enum_object<>::to_int32(exception_case::thread_abort)).is().equal_to(38);
      assert_that(enum_object<>::to_string(exception_case::thread_abort)).is().equal_to("thread_abort");
      assert_that(enum_object<>::parse<exception_case>("thread_abort")).is().equal_to(exception_case::thread_abort);
    }
    
    auto test_method_(thread_interrupted) {
      assert_that(enum_object<>::to_int32(exception_case::thread_interrupted)).is().equal_to(39);
      assert_that(enum_object<>::to_string(exception_case::thread_interrupted)).is().equal_to("thread_interrupted");
      assert_that(enum_object<>::parse<exception_case>("thread_interrupted")).is().equal_to(exception_case::thread_interrupted);
    }
    
    auto test_method_(thread_state) {
      assert_that(enum_object<>::to_int32(exception_case::thread_state)).is().equal_to(40);
      assert_that(enum_object<>::to_string(exception_case::thread_state)).is().equal_to("thread_state");
      assert_that(enum_object<>::parse<exception_case>("thread_state")).is().equal_to(exception_case::thread_state);
    }
    
    auto test_method_(time_zone_not_found) {
      assert_that(enum_object<>::to_int32(exception_case::time_zone_not_found)).is().equal_to(41);
      assert_that(enum_object<>::to_string(exception_case::time_zone_not_found)).is().equal_to("time_zone_not_found");
      assert_that(enum_object<>::parse<exception_case>("time_zone_not_found")).is().equal_to(exception_case::time_zone_not_found);
    }
    
    auto test_method_(unauthorized_access) {
      assert_that(enum_object<>::to_int32(exception_case::unauthorized_access)).is().equal_to(42);
      assert_that(enum_object<>::to_string(exception_case::unauthorized_access)).is().equal_to("unauthorized_access");
      assert_that(enum_object<>::parse<exception_case>("unauthorized_access")).is().equal_to(exception_case::unauthorized_access);
    }
    
    auto test_method_(uri_format) {
      assert_that(enum_object<>::to_int32(exception_case::uri_format)).is().equal_to(43);
      assert_that(enum_object<>::to_string(exception_case::uri_format)).is().equal_to("uri_format");
      assert_that(enum_object<>::parse<exception_case>("uri_format")).is().equal_to(exception_case::uri_format);
    }
  };
}
