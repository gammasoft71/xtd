#include <xtd/console>
#include <xtd/environment>

using namespace xtd;

auto main()->int {
  if (environment::os_version().is_64_bit()) console::write_line("64 bit");
  if (environment::os_version().is_posix_platform()) console::write_line("Posix platform");
  if (environment::os_version().is_macos_platform()) console::write_line("macOS platform");
  if (environment::os_version().is_unix_platform()) console::write_line("Unix platform");
  if (environment::os_version().is_windows_platform()) console::write_line("Windows platform");
  if (environment::os_version().is_android()) console::write_line("Android");
  if (environment::os_version().is_free_bsd()) console::write_line("FreeBSD");
  if (environment::os_version().is_ios()) console::write_line("iOS");
  if (environment::os_version().is_linux()) console::write_line("Linux");
  if (environment::os_version().is_macos()) console::write_line("macOS");
  if (environment::os_version().is_mingw()) console::write_line("MINGW");
  if (environment::os_version().is_msys()) console::write_line("MSYS");
  if (environment::os_version().is_posix()) console::write_line("Posix");
  if (environment::os_version().is_tvos()) console::write_line("tvOS");
  if (environment::os_version().is_watchos()) console::write_line("watchOS");
  if (environment::os_version().is_windows()) console::write_line("Windows");
  if (environment::os_version().is_windows_ce()) console::write_line("Windows CE");
  if (environment::os_version().is_xbox()) console::write_line("xbox");
}
