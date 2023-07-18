#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>

using namespace xtd;

namespace version_os_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      // Get the operating system version.
      auto os = environment::os_version();
      auto ver = os.version();
      console::write_line("Operating System: {0} ({1})", os.version_string(), ver.to_string());
    }
  };
}

startup_(version_os_example::program);

// This code can produce the following output:
//
// Operating System: macOS 11.6.0 (11.6.0.0)
