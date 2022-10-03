#include <xtd/xtd.core>
#include <chrono>
#define UNICODE
/// @todo Remove when xtd::microsoft::registry class is ready...
#ifdef WIN32
#include <Windows.h>
#endif

using namespace std;
using namespace xtd;

namespace path_updater {
  class program final static_ {
  public:
    static int main(const vector<ustring>& args) {
      if (environment::os_version().is_windows() && !environment::user_administrator()) {
        console::write_line("ERROR : Launch set_path in administrator mode.");
        return -1;
      }
      ustring folder;
      bool show_version = false;
      bool show_help = false;
      bool add = false;
      bool remove = false;
      if (!process_arguments(args, folder, add, remove, show_version, show_help)) {
        console::write_line(get_error());
        return -1;
      }

      if (show_version) console::write_line(get_version());
      else if (show_help) console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
      else {
        auto current_path = environment::get_environment_variable("PATH");
        auto paths = current_path.split({ io::path::path_separator() });

        auto it_folder = paths.end();
        for (auto it = paths.begin(); it != paths.end(); ++it) {
          if (*it == folder) {
            it_folder = it;
            break;
          }
        }

        if (add && it_folder != paths.end()) {
          console::write_line("The path already contains folder \"{}\". Do nothing.", folder);
          return 0;
        }

        if (remove && it_folder == paths.end()) {
          console::write_line("The path does not contain folder \"{}\". Do nothing.", folder);
          return 0;
        }

        if (remove) paths.erase(it_folder);
        else paths.insert(paths.begin(), folder);

        auto new_path = ustring::join(ustring::format("{}", io::path::path_separator()), paths);
        environment::set_environment_variable("PATH", new_path);

        auto result = 0;
        if (environment::os_version().is_windows()) result = win32_write_system_path(new_path);
        if (environment::os_version().is_macos()) result = macos_write_system_path(new_path);
        else if (environment::os_version().is_linux()) result = linux_write_system_path(new_path);
        if (result) return result;
        console::write_line("New path \"{}\" written", new_path);
      }
      return 0;
    }

  private:
    static string get_error() {
      return "set_path : invalid params\n"
        "Try 'set_path --help' for more information.";
    }

    static string get_usage() {
      return "Usage\n"
        "  set_path [options] folder\n"
        "\n"
        "-a, --add           : Add folder to path (set by default).\n"
        "-r, --remove        : Remove folder from path.\n"
        "-v, --version       : Shows version information.\n"
        "-h, --help          : Shows this help page.";
    }

    static string get_version() {
      return ustring::format("set_path version {}, (c) {:L} by Gammasoft", environment::version(), date_time::now());
    }

    static bool process_arguments(const vector<ustring>& args, ustring& folder, bool& add, bool& remove, bool& show_version, bool& show_help) {
      for (size_t index = 0; index < args.size(); index += 1) {
        if (args[index] == "-a" || args[index] == "--add") add = true;
        else if (args[index] == "-r" || args[index] == "--remove") remove = true;
        else if (args[index] == "-v" || args[index] == "--version") show_version = true;
        else if (args[index] == "-h" || args[index] == "--help") show_help = true;
        else if (!ustring::is_empty(folder)) return false;
        else folder = args[index];
      }

      if (!add && !remove) add = true;

      return !ustring::is_empty(folder) || show_help || show_version;
    }

    static int linux_write_system_path(const ustring& path) {
      console::write_line("Not yet impelmented...");
      return 1;
    }

    static int macos_write_system_path(const ustring& path) {
      console::write_line("Not yet impelmented...");
      return 1;
    }

    static int win32_write_system_path(const ustring& path) {
      /// @todo Replace by xtd::microsoft::registry when xtd::microsoft::registry class is ready...
#ifdef WIN32
      auto new_path = convert_string::to_wstring(path);
      auto status = RegSetValueEx(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\\Path", 0, REG_SZ, reinterpret_cast<const BYTE*>(new_path.c_str()), static_cast<DWORD>(new_path.size() + 1));
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when writing path in registry", status);
        return 1;
      }
      status = RegFlushKey(HKEY_LOCAL_MACHINE);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when flush registry", status);
        return 2;
      }
      auto result = SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)L"Environment", SMTO_ABORTIFHUNG, 5000, NULL);
      if (result == 0) {
        console::write_line("An error 0x{:X8} occured when SendMessageTimeout", GetLastError());
        return 3;
      }
#endif
      return 0;
    }
  };
}

startup_(path_updater::program);
