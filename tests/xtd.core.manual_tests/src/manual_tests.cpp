#include <filesystem>
#include <xtd/xtd.core>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

class xtd_core_manual_test {
public:
  static void main() {
    using_(process process) {
      process.start_info().file_name("ipconfig");
      process.start_info().use_shell_execute(false);
      process.start_info().redirect_standard_output(true);
      process.start();
      
      // Synchronously read the standard output of the spawned process.
      stream_reader reader(process.standard_output());
      string output = reader.read_to_end();
      
      // Write the redirected output to this application's window.
      console::write_line(output);
      
      process.wait_for_exit();
    }
    
    console::write_line("\n\nPress any key to exit.");
    console::read_line();

    /*
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
     */
  }
};

startup_(xtd_core_manual_test);
