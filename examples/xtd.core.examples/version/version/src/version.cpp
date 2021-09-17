#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program : public object {
  public:
    // The main entry point for the application.
    static void main() {
      ustring fmt_std = "Standard version:\n"
      "  major.minor.build.revision = {0}.{1}.{2}.{3}";
      ustring fmt_int = "Interim version:\n"
      "  major.minor.build.maj_rev/min_rev = {0}.{1}.{2}.{3}/{4}";
      
      version std(2, 4, 1128, 2);
      version interim(2, 4, 1128, (100 << 16) + 2);
      
      console::write_line(fmt_std, std.major(), std.minor(), std.build(), std.revision());
      console::write_line(fmt_int, interim.major(), interim.minor(), interim.build(), interim.major_revision(), interim.minor_revision());
    }
  };
}

startup_(examples::program);

// This code can produce the following output:
//
// Standard version:
//   major.minor.build.revision = 2.4.1128.2
// Interim version:
//   major.minor.build.maj_rev/min_rev = 2.4.1128.100/2

