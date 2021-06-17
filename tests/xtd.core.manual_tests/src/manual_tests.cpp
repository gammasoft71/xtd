#include <filesystem>
#include <xtd/xtd.core>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test {
public:
  static void main() {
    stack_trace st;
    
    for (auto i = 0u; i < st.frame_count(); ++i) {
      // Display the stack frame properties.
      stack_frame sf = st.get_frame(i);
      console::write_line(" File: {}", sf.get_file_name());
      console::write_line(" Line Number: {}", sf.get_file_line_number());
      // Note that the column number defaults to zero when not initialized.
      console::write_line(" Column Number: {}", sf.get_file_column_number());
      console::write_line(" Method: {}", sf.get_method());
      if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
        console::write_line(" Offset: {}", sf.get_offset());
    }
  }
};

startup_(xtd_core_manual_test);
