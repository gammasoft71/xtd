#include <csignal>
#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

class program {
public:
  static void main() {
    auto os = environment::os_version();
    console::write_line("os.distribution = {}", os);
    console::write_line("  bug_repport = {}", os.distribution().bug_repport());
    console::write_line("  code_name = {}", os.distribution().code_name());
    console::write_line("  description = {}", os.distribution().description());
    console::write_line("  home = {}", os.distribution().home());
    console::write_line("  id = {}", os.distribution().id());
    console::write_line("  like_ids = {}", os.distribution().like_ids());
    console::write_line("  name = {}", os.distribution().name());
    console::write_line("  version = {}", os.distribution().version());
    console::write_line("  version_string = {}", os.distribution().version_string());
  }
};

startup_(program);
