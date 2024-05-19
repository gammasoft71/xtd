#include <xtd/diagnostics/process>
#include <xtd/console>
#include <xtd/using>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

auto main() -> int {
  try {
    using_(auto my_process = process {}) {
      my_process.start_info().use_shell_execute(false);
      // You can start any process other guidgen.
      my_process.start_info().file_name("guidgen");
      my_process.start_info().create_no_window(true);
      my_process.start();
      // This code assumes the process you are starting will terminate itself.
      // Given that it is started without a window so you cannot terminate it
      // on the desktop, it must terminate itself or you can do it programmatically
      // from this application using the kill method.
    }
  } catch (const exception& e) {
    console::write_line(e.what());
  }
}

// This code can produces the following output :
//
// 1549cf47-b1c9-4333-96e5-4eabffbd9fbd
