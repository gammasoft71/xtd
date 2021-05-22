#include <filesystem>
#include <xtd/xtd.core>

using namespace xtd;

class xtd_core_manual_test {
public:
  static void main() {
    console::write_line("Hello, World!");
    console::write_line("temp = {}", io::path::get_temp_path());
    console::write_line("temp = {}", std::filesystem::temp_directory_path().string());
  }
};

startup_(xtd_core_manual_test);
