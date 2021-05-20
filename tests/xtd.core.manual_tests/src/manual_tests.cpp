#include <xtd/xtd.core>

using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    io::string_writer sw;
    console::set_out(sw.base_stream());
    console::set_error(sw.base_stream());
    console::write_line("Hello, World!");
    throw invalid_operation_exception(caller_info_);
  }
};

startup_(xtd_core_manual_test);
