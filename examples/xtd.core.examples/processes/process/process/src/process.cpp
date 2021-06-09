#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

int main() {
  try {
    using_(process my_process) {
      my_process.start_info().use_shell_execute(false);
      // // You can start any process, hello_world is a do-nothing example.
      my_process.start_info().file_name("hello_world");
      my_process.start_info().create_no_window(true);
      my_process.start();
      // This code assumes the process you are starting will terminate itself.
      // Given that it is started without a window so you cannot terminate it
      // on the desktop, it must terminate itself or you can do it programmatically
      // from this application using the kill method.
    }
  } catch(const exception& e) {
    console::write_line(e.what());
  }
}

// This code produces the following output :
//
// Hello, World!
