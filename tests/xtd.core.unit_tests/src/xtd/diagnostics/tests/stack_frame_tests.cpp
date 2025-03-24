#include <xtd/diagnostics/stack_frame>
#include <xtd/io/path>
#include <xtd/environment>
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
      assert::are_equal(size_object::max_value, stack_frame::OFFSET_UNKNOWN);
    }
    
    void test_method_(empty) {
      if (!environment::os_version().is_windows()) return; // Works, but can take a long time
      assert::is_zero(stack_frame::empty().get_file_column_number());
      assert::is_zero(stack_frame::empty().get_file_line_number());
      assert::is_empty(stack_frame::empty().get_file_name());
      assert::is_empty(stack_frame::empty().get_method());
      assert::are_equal(stack_frame::OFFSET_UNKNOWN, stack_frame::empty().get_offset());
    }
    
    void test_method_(default_constructor) {
      if (!environment::os_version().is_windows()) return; // Works, but can take a long time
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {});
    }
    
    void test_method_(constructor_with_need_file_info_to_false) {
      if (!environment::os_version().is_windows()) return; // Works, but can take a long time
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {false});
    }
    
    void test_method_(constructor_with_need_file_info_to_true) {
      if (!environment::os_version().is_windows()) return; // Works, but can take a long time
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      assert::are_not_equal(stack_frame::empty(), stack_frame {true});
    }
    
    void test_method_(constructor_with_skip_frames_need_file_info) {
      // Depending on the xtd::native::stack_trace::get_frames method, the result is not the same for every operating system.
      /*
      assert::are_not_equal(stack_frame::empty(), stack_frame {0, false});
      assert::are_equal(stack_frame::empty(), stack_frame {stack_frame::OFFSET_UNKNOWN, false});
      assert::are_not_equal(stack_frame::empty(), stack_frame {0, true});
      assert::are_equal(stack_frame::empty(), stack_frame {stack_frame::OFFSET_UNKNOWN, true});
      */
    }
    
    void test_method_(constructor_with_file_name_and_line_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42}.get_file_name());
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42}.get_file_line_number());
    }
    
    void test_method_(constructor_with_file_name_line_number_and_method_name) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name"}.get_file_name());
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name"}.get_file_line_number());
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name"}.get_method());
    }
    
    void test_method_(constructor_with_file_name_line_number_method_name_and_column_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_name());
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_line_number());
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21}.get_method());
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21}.get_file_column_number());
    }
    
    void test_method_(constructor_with_file_name_line_number_and_column_number) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, 21}.get_file_name());
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, 21}.get_file_line_number());
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, 21}.get_file_column_number());
    }
    
    void test_method_(constructor_with_file_name_line_number_method_name_column_number_and_offset) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_name());
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_line_number());
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_method());
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_column_number());
      assert::are_equal(84_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_offset());
    }
    
    void test_method_(get_file_name) {
      assert::are_equal("file_name.cpp", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_name());
    }
    
    void test_method_(get_file_line_number) {
      assert::are_equal(42_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_line_number());
    }
    
    void test_method_(get_method) {
      assert::are_equal("method_name", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_method());
    }
    
    void test_method_(get_file_column_number) {
      assert::are_equal(21_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_file_column_number());
    }
    
    void test_method_(get_offset) {
      assert::are_equal(84_z, stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.get_offset());
    }
    
    void test_method_(to_string) {
      assert::are_equal("", stack_frame::empty().to_string());
      assert::are_equal("<unknown method> at offset <unknown offset> in file:line:column file_name.cpp:42:0\n", stack_frame {"file_name.cpp", 42}.to_string());
      assert::are_equal("method_name at offset <unknown offset> in file:line:column file_name.cpp:42:0\n", stack_frame {"file_name.cpp", 42, "method_name"}.to_string());
      assert::are_equal("method_name at offset <unknown offset> in file:line:column file_name.cpp:42:21\n", stack_frame {"file_name.cpp", 42, "method_name", 21}.to_string());
      assert::are_equal("<unknown method> at offset <unknown offset> in file:line:column file_name.cpp:42:21\n", stack_frame {"file_name.cpp", 42, 21}.to_string());
      assert::are_equal("method_name at offset 84 in file:line:column file_name.cpp:42:21\n", stack_frame {"file_name.cpp", 42, "method_name", 21, 84}.to_string());
    }
    
    void test_method_(current) {
      assert::are_equal("stack_frame_tests.cpp", path::get_file_name(stack_frame::current().get_file_name()));
      assert::are_equal(119_z, stack_frame::current().get_file_line_number());
      if (environment::compiler_version().compiler_id() == compiler_id::clang || environment::compiler_version().compiler_id() == compiler_id::apple_clang || environment::compiler_version().compiler_id() == compiler_id::gcc) assert::are_equal("void xtd::tests::stack_frame_tests::current()", stack_frame::current().get_method());
      else assert::are_equal("void __cdecl xtd::tests::stack_frame_tests::current(void)", stack_frame::current().get_method());
    }
  };
}
