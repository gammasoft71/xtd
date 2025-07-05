#include <xtd/diagnostics/process>
#include <xtd/block_scope>
#include <xtd/console>

using namespace xtd;
using namespace xtd::diagnostics;

auto main() -> int {
  try {
    block_scope_(auto my_process = process {}) {
      // You can start any process other guidgen.
      my_process.start_info().file_name("guidgen");
      my_process.start_info().create_no_window(true);
      my_process.start();
      // This code assumes the process you are starting will terminate itself.
      // Given that it is started without a window so you cannot terminate it
      // on the desktop, it must terminate itself or you can do it programmatically
      // from this application using the kill method.
    }
  } catch (const std::exception& e) {
    console::write_line(e.what());
  }
}

// This code can produce the following output :
//
// 1549cf47-b1c9-4333-96e5-4eabffbd9fbd
