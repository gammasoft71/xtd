#include <filesystem>
#include <xtd/xtd.core>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

class xtd_core_manual_test {
public:
  static void main() {
    console::output_code_page(65001);
    //stream_reader reader(process::start(process_start_info("xtdc", "--help").use_shell_execute(false).redirect_standard_output(true)).standard_output());
    //console::write(reader.read_to_end());
    try {
      using_(process process) {
        process.start_info().file_name("xtdc");
        process.start_info().arguments("--help");
        process.start_info().use_shell_execute(false);
        process.start();
        process.wait_for_exit();
        process.start();
        process.wait_for_exit();
      }
    } catch(const invalid_operation_exception& e) {
      console::write_line(e.message());
    }
  }
};

startup_(xtd_core_manual_test);
