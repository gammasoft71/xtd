#include <xtd/diagnostics/stack_frame>
#include <xtd/io/path>
#include <xtd/size_object>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(stack_frame_tests) {
    void test_method_(OFFSET_UNKNOWN) {
      assert::are_equal(size_object::max_value, stack_frame::OFFSET_UNKNOWN, csf_);
    }

    void test_method_(empty) {
      assert::is_zero(stack_frame::empty().get_file_column_number(), csf_);
      assert::is_zero(stack_frame::empty().get_file_line_number(), csf_);
      assert::is_empty(stack_frame::empty().get_file_name(), csf_);
      assert::is_empty(stack_frame::empty().get_method(), csf_);
      assert::are_equal(stack_frame::OFFSET_UNKNOWN, stack_frame::empty().get_offset(), csf_);
    }
    
    void test_method_(default_constructor) {
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {}, csf_);
    }
    
    void test_method_(constructor_with_need_file_info_to_false) {
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {false}, csf_);
    }
    
    void test_method_(constructor_with_need_file_info_to_true) {
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {true}, csf_);
    }
    
    void test_method_(constructor_with_skip_frames_need_file_info) {
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {0, false}, csf_);
      assert::are_not_equal(stack_frame::empty(), stack_frame {0, true}, csf_);
      assert::are_equal(stack_frame::empty(), stack_frame {stack_frame::OFFSET_UNKNOWN - 1, false}, csf_);
      assert::are_equal(stack_frame::empty(), stack_frame {stack_frame::OFFSET_UNKNOWN - 1, true}, csf_);
    }
    
    void test_method_(constructor_with_file_name_and_line_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42}.get_file_name(), csf_);
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42}.get_file_line_number(), csf_);
    }
    
    void test_method_(constructor_with_file_name_line_number_and_method_name) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name"}.get_file_name(), csf_);
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name"}.get_file_line_number(), csf_);
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name"}.get_method(), csf_);
    }
    
    void test_method_(constructor_with_file_name_line_number_method_name_and_column_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_name(), csf_);
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_line_number(), csf_);
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21}.get_method(), csf_);
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_column_number(), csf_);
    }
    
    void test_method_(constructor_with_file_name_line_number_and_column_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, 21}.get_file_name(), csf_);
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, 21}.get_file_line_number(), csf_);
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, 21}.get_file_column_number(), csf_);
    }
    
    void test_method_(constructor_with_file_name_line_number_method_name_column_number_and_offset) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_name(), csf_);
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_line_number(), csf_);
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_method(), csf_);
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_column_number(), csf_);
      assert::are_equal(84_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_offset(), csf_);
    }
    
    void test_method_(get_file_name) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_name(), csf_);
    }
    
    void test_method_(get_file_line_number) {
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_line_number(), csf_);
    }
    
    void test_method_(get_method) {
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_method(), csf_);
    }
    
    void test_method_(get_file_column_number) {
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_column_number(), csf_);
    }
    
    void test_method_(get_offset) {
      assert::are_equal(84_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_offset(), csf_);
    }
    
    void test_method_(to_string) {
      assert::are_equal("", stack_frame::empty().to_string(), csf_);
      assert::are_equal("<unknown method> at offset <unknown offset> in file:line:column file_name.cpp:42:0", stack_frame {"file_name.cpp", 42}.to_string(), csf_);
      assert::are_equal("method_name at offset <unknown offset> in file:line:column file_name.cpp:42:0", stack_frame {"file_name.cpp", 42, "method_name"}.to_string(), csf_);
      assert::are_equal("method_name at offset <unknown offset> in file:line:column file_name.cpp:42:21", stack_frame {"file_name.cpp", 42, "method_name", 21}.to_string(), csf_);
      assert::are_equal("<unknown method> at offset <unknown offset> in file:line:column file_name.cpp:42:21", stack_frame {"file_name.cpp", 42, 21}.to_string(), csf_);
      assert::are_equal("method_name at offset 84 in file:line:column file_name.cpp:42:21", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.to_string(), csf_);
    }

    void test_method_(csf) {
      assert::are_equal("stack_frame_tests.cpp", path::get_file_name(csf_.get_file_name()), csf_);
      assert::are_equal(112_z, csf_.get_file_line_number(), csf_);
      assert::are_equal("csf", csf_.get_method(), csf_);
    }
  };
}
