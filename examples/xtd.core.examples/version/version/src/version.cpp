#include <xtd/console>
#include <xtd/startup>
#include <xtd/version>

using namespace xtd;

namespace version_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto fmt_std = "Standard version:\n"
        "  major.minor.build.revision = {0}.{1}.{2}.{3}";
      auto fmt_int = "Interim version:\n"
        "  major.minor.build.maj_rev/min_rev = {0}.{1}.{2}.{3}/{4}";
        
      auto std = version {2, 4, 1128, 2};
      auto interim = version {2, 4, 1128, (100 << 16) + 2};
      
      console::write_line(fmt_std, std.major(), std.minor(), std.build(), std.revision());
      console::write_line(fmt_int, interim.major(), interim.minor(), interim.build(), interim.major_revision(), interim.minor_revision());
    }
  };
}

startup_(version_example::program::main);

// This code can produce the following output:
//
// Standard version:
//   major.minor.build.revision = 2.4.1128.2
// Interim version:
//   major.minor.build.maj_rev/min_rev = 2.4.1128.100/2

