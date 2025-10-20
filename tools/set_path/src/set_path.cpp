#undef __XTD_ENABLE_IMPLICIT_USING_NAMESPACES__
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>
#include <xtd/string>
#include <xtd/chrono>
#if defined(_WIN32)
#define NOMINMAX
#define UNICODE
#include <Windows.h>
#undef interface
#endif

using namespace xtd;
using namespace xtd::collections::generic;

namespace set_path {
  class program final static_ {
  public:
    static auto main(const argument_collection& args) {
      string folder;
      bool show_version = false;
      bool show_help = false;
      bool add = false;
      bool remove = false;
      bool system_path = false;
      if (!process_arguments(args, folder, add, remove, system_path, show_version, show_help)) {
        console::write_line(get_error());
        return -1;
      }
      
      if (system_path && environment::os_version().is_windows() && !environment::user_administrator()) {
        console::write_line("ERROR : Launch set_path in administrator mode.");
        return -1;
      }
      
      if (show_version) console::write_line(get_version());
      else if (show_help) console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
      else {
        string current_path;
        if (environment::os_version().is_windows()) current_path = win32_read_system_path(system_path);
        else if (environment::os_version().is_macos()) current_path = macos_read_system_path(system_path);
        else if (environment::os_version().is_linux()) current_path = linux_read_system_path(system_path);
        auto paths = list<string> {current_path.split(io::path::path_separator())};
        auto index_folder = paths.npos;
        for (auto index = 0_z; index < paths.count(); ++index) {
          if (paths[index] == folder) {
            index_folder = index;
            break;
          }
        }
        
        if (add && index_folder != paths.npos) {
          console::write_line("The path already contains folder \"{}\". Do nothing.", folder);
          return 0;
        }
        
        if (remove && index_folder == paths.npos) {
          console::write_line("The path does not contain folder \"{}\". Do nothing.", folder);
          return 0;
        }
        
        if (remove) paths.remove_at(index_folder);
        else paths.insert(0, folder);
        
        auto new_path = string::join(string::format("{}", io::path::path_separator()), paths);
        environment::set_environment_variable("PATH", new_path);
        
        auto result = 0;
        if (environment::os_version().is_windows()) result = win32_write_system_path(system_path, new_path);
        else if (environment::os_version().is_macos()) result = macos_write_system_path(system_path, new_path);
        else if (environment::os_version().is_linux()) result = linux_write_system_path(system_path, new_path);
        if (result) return result;
        console::write_line("The folder \"{}\" is {} the path", folder, remove ? "removed from" : "added to");
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
             "-s, --system        : Use Sytem path. (User path by default). (*)\n"
             "-v, --version       : Shows version information.\n"
             "-h, --help          : Shows this help page.\n"
             "\n"
             "(*) System option is valid only on Windows. You must in administrator mode.";
    }
    
    static string get_version() {
      return string::format("set_path version {}, (c) {} by Gammasoft", environment::version(), date_time::now().year());
    }
    
    static bool process_arguments(const list<string>& args, string& folder, bool& add, bool& remove, bool& system_path, bool& show_version, bool& show_help) {
      for (size_t index = 0; index < args.count(); index += 1) {
        if (args[index] == "-a" || args[index] == "--add") add = true;
        else if (args[index] == "-r" || args[index] == "--remove") remove = true;
        else if (args[index] == "-s" || args[index] == "--system") system_path = true;
        else if (args[index] == "-v" || args[index] == "--version") show_version = true;
        else if (args[index] == "-h" || args[index] == "--help") show_help = true;
        else if (!string::is_empty(folder)) return false;
        else folder = args[index];
      }
      
      if (!add && !remove) add = true;
      
      return !string::is_empty(folder) || show_help || show_version;
    }
    
    static string linux_read_system_path(bool system_path) {
      return environment::get_environment_variable("PATH");
    }
    
    static int linux_write_system_path(bool system_path, const string& path) {
      console::write_line("Not yet impelmented...");
      return 1;
    }
    
    static string macos_read_system_path(bool system_path) {
      return environment::get_environment_variable("PATH");
    }
    
    static int macos_write_system_path(bool system_path, const string& path) {
      console::write_line("Not yet impelmented...");
      return 1;
    }
    
    static string win32_read_system_path(bool system_path) {
      /// @todo Replace by xtd::microsoft::registry when xtd::microsoft::registry class is ready...
      wchar current_directory[4097] = L"";
      #if defined(_WIN32)
      DWORD size = 4097;
      auto status = RegGetValue(system_path ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER, system_path ? L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment" : L"Environment", L"Path", RRF_RT_REG_SZ, nullptr, reinterpret_cast<PVOID>(current_directory), &size);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when reading path in registry", status);
        return string::empty_string;
      }
      current_directory[size] = 0;
      #endif
      return convert_string::to_string(current_directory);
    }
    
    static int win32_write_system_path(bool system_path, const string& path) {
      /// @todo Replace by xtd::microsoft::registry when xtd::microsoft::registry class is ready...
      #if defined(_WIN32)
      auto new_path = convert_string::to_wstring(path);
      HKEY environment_key;
      auto status = RegOpenKey(system_path ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER, system_path ? L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment" : L"Environment", &environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when opening registry key", status);
        return 1;
      }
      
      status = RegSetValueEx(environment_key, L"Path", 0, REG_SZ, reinterpret_cast<const BYTE*>(new_path.chars().c_str()), static_cast<DWORD>(new_path.length() + 1));
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when writing path in registry", status);
        return 2;
      }
      
      status = RegFlushKey(environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when flush registry key", status);
        return 3;
      }
      
      status = RegCloseKey(environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occured when close registry key", status);
        return 4;
      }
      #endif
      
      #if defined(_WIN32)
      auto result = SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)L"Environment", SMTO_ABORTIFHUNG, 5000, NULL);
      if (result == 0) {
        console::write_line("An error 0x{:X8} occured when SendMessageTimeout", GetLastError());
        return 5;
      }
      #endif
      return 0;
    }
  };
}

startup_(set_path::program::main);
