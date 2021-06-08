#include <xtd/xtd.core>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

class xtd_core_manual_test {
public:
  static void main() {
    stream_reader reader(process::start(process_start_info("xtdc", "--help").use_shell_execute(false).redirect_standard_output(true)).standard_output());
    console::write(reader.read_to_end());
  }
};

startup_(xtd_core_manual_test);
