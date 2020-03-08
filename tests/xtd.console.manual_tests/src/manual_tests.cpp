#include <xtd/xtd.console>
#include <filesystem>

using namespace std;
using namespace xtd;

bool is_windows_gui_app(const std::filesystem::path& app_path) {
  if (!std::filesystem::exists(app_path)) return false;
  auto bytes = xtd::io::file::read_all_bytes(app_path);
  // read pe format : https://docs.microsoft.com/en-us/windows/win32/debug/pe-format?redirectedfrom=MSDN#machine_type
  if (bytes[0] != 'M' || bytes[1] != 'Z') return false;
  auto subsystem_offset = bit_converter::to_uint16(bytes, 0x3C) + 92;

  return bit_converter::to_uint16(bytes, subsystem_offset) == 2;
}

// The main entry point for the application.
int main() {
  console::write_line("is_windows_gui_app(\"/Users/yves/Projects/console.exe\") = {}", is_windows_gui_app("/Users/yves/Projects/console.exe"));
  console::write_line("is_windows_gui_app(\"/Users/yves/Projects/gui.exe\") = {}", is_windows_gui_app("/Users/yves/Projects/gui.exe"));
}
