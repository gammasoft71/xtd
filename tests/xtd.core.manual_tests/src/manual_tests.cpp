#include <csignal>
#include <xtd/xtd.core>
#include <xtd/xtd.drawing>

using namespace xtd;

class program {
public:
  static void main() {
    auto os = environment::os_version();
    console::write_line("os = {}", os);
    console::write_line("os.distribution.name = {}", os.distribution().name());
    console::write_line("os.distribution.version = {}", os.distribution().version());
    console::write_line("os.distribution.code_name = {}", os.distribution().code_name());
    console::write_line("os.distribution.description = {}", os.distribution().description());
  }
};

startup_(program);
