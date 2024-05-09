#include <xtd/io/path>
#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>
#include <xtd/ustring>
#include <xtd/chrono>
#if defined(_WIN32)
#define UNICODE
#define NOMINMAX
#include <Windows.h>
#endif

using namespace std;
using namespace xtd;

namespace set_path {
  class program final static_ {
  public:
    static auto main(const vector<ustring>& args) {
      ustring key;
      ustring value;
      bool show_version = false;
      bool show_help = false;
      bool add = false;
      bool remove = false;
      bool environment_variable_system = false;
      if (!process_arguments(args, key, value, add, remove, environment_variable_system, show_version, show_help)) {
        console::write_line(get_error());
        return -1;
      }

      if (ustring::is_empty(key)) show_help = true;

      if (environment_variable_system && environment::os_version().is_windows() && !environment::user_administrator()) {
        console::write_line("ERROR : Launch set_environment_variable in administrator mode.");
        return -1;
      }
      
      if (show_version) console::write_line(get_version());
      else if (show_help) console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
      else {
        /*
        ustring current_value;
        if (environment::os_version().is_windows()) current_value = win32_read_environment_variable_system(key, environment_variable_system);
        else if (environment::os_version().is_macos()) current_value = macos_read_environment_variable_system(key, environment_variable_system);
        else if (environment::os_version().is_linux()) current_value = linux_read_environment_variable_system(key, environment_variable_system);

        if (add && current_value == value) {
          console::write_line("The key \"{}\" already contains value \"{}\". Do nothing.", key, value);
          return 0;
        }
        
        if (remove && ustring::is_empty(current_value)) {
          console::write_line("The key \"{}\" does not exist. Do nothing.", key);
          return 0;
        }*/
                
        auto result = 0;
        if (environment::os_version().is_windows()) result = win32_write_environment_variable_system(environment_variable_system, key, value);
        else if (environment::os_version().is_macos()) result = macos_write_environment_variable_system(environment_variable_system, key, value);
        else if (environment::os_version().is_linux()) result = linux_write_environment_variable_system(environment_variable_system, key, value);
        if (result) return result;
        if (remove) console::write_line("The key \"{}\" is remove from environment variables.", key);
        else console::write_line("The key \"{}\" is added to environment variables with value \"{}\".", key, value);
      }
      return 0;
    }
    
  private:
    static string get_error() {
      return "set_environment_variable : invalid params\n"
        "Try 'set_environment_variable --help' for more information.";
    }
    
    static string get_usage() {
      return "Usage\n"
        "  set_environment_variable [options] key [value]\n"
        "\n"
        "-a, --add           : Add value to key (set by default). (*)\n"
        "-r, --remove        : Remove key.\n"
        "-s, --system        : Use environment variable System. (Environment variable User by default). (**)\n"
        "-v, --version       : Shows version information.\n"
        "-h, --help          : Shows this help page.\n"
        "\n"
        "(*) If the value is empty, then it's identical to the --remove option.\n"
        "(**) System option is valid only on Windows. You must in administrator mode.";
    }
    
    static string get_version() {
      return ustring::format("set_environment_variable version {}, (c) {:L} by Gammasoft", environment::version(), date_time::now());
    }
    
    static bool process_arguments(const vector<ustring>& args, ustring& key, ustring& value, bool& add, bool& remove, bool& system_path, bool& show_version, bool& show_help) {
      for (size_t index = 0; index < args.size(); index += 1) {
        if (args[index] == "-a" || args[index] == "--add") add = true;
        else if (args[index] == "-r" || args[index] == "--remove") remove = true;
        else if (args[index] == "-s" || args[index] == "--system") system_path = true;
        else if (args[index] == "-v" || args[index] == "--version") show_version = true;
        else if (args[index] == "-h" || args[index] == "--help") show_help = true;
        //else if (!ustring::is_empty(key)) return false;
        else {
        key = args[index];
        if (index + 1 < args.size()) value = args[++index];
        }
      }
      
      if (!add && !remove) add = true;
      if (remove) value = ustring::empty_string;
      if (add && ustring::is_empty(value)) {
        remove = true;
        add = false;
      }

      return !ustring::is_empty(key) || show_help || show_version;
    }
    
    static ustring linux_read_environment_variable_system(const ustring& key, bool environment_variable_system) {
      return environment::get_environment_variable(key, environment_variable_system ? environment_variable_target::machine : environment_variable_target::user);
    }
    
    static int linux_write_environment_variable_system(bool environment_variable_system, const ustring& key, const ustring& value) {
      console::write_line("Not yet implemented...");
      return 1;
    }
    
    static ustring macos_read_environment_variable_system(const ustring& key, bool environment_variable_system) {
      return environment::get_environment_variable(key, environment_variable_system ? environment_variable_target::machine : environment_variable_target::user);
    }
    
    static int macos_write_environment_variable_system(bool environment_variable_system, const ustring& key, const ustring& value) {
      console::write_line("Not yet implemented...");
      return 1;
    }
    
    static ustring win32_read_environment_variable_system(const ustring& key, bool environment_variable_system) {
      /// @todo Replace by xtd::microsoft::registry when xtd::microsoft::registry class is ready...
      wchar value[4097] = L"";
      #if defined(_WIN32)
      DWORD size = 4097;
      auto status = RegGetValue(environment_variable_system ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER, environment_variable_system ? L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment" : L"Environment", convert_string::to_wstring(key).c_str(), RRF_RT_REG_SZ, nullptr, reinterpret_cast<PVOID>(value), &size);
      if (status != ERROR_SUCCESS && status != ERROR_FILE_NOT_FOUND) {
        console::write_line("An error 0x{:X8} occurred when reading path in registry", status);
        return ustring::empty_string;
      }
      if (status == ERROR_SUCCESS) value[size] = 0;
      #endif
      return convert_string::to_ustring(value);
    }
    
    static int win32_write_environment_variable_system(bool environment_variable_system, const ustring& key, const ustring& value) {
      /// @todo Replace by xtd::microsoft::registry when xtd::microsoft::registry class is ready...
      #if defined(_WIN32)
      HKEY environment_key;
      auto status = RegOpenKeyEx(environment_variable_system ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER, environment_variable_system ? L"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment" : L"Environment", 0, KEY_ALL_ACCESS, &environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occurred when opening registry key", status);
        return 1;
      }
      
      if (ustring::is_empty(value)) {
        status = RegDeleteKey(environment_key, convert_string::to_wstring(key).c_str());
        if (status != ERROR_SUCCESS) {
          console::write_line("An error 0x{:X8} occurred when erase key \"{}\" from registry", status, key);
          return 5;
        }
        return 0;
      }
   
      auto new_value = convert_string::to_wstring(value);
      status = RegSetValueEx(environment_key, convert_string::to_wstring(key).c_str(), 0, REG_SZ, reinterpret_cast<const BYTE*>(convert_string::to_wstring(new_value).c_str()), static_cast<DWORD>((new_value.size() + 1) * sizeof(wchar_t)));
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occurred when writing key \"{}\" with value \"{}\" in registry", status, key, value);
        return 2;
      }
      
      status = RegFlushKey(environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occurred when flush registry key", status);
        return 3;
      }
      
      status = RegCloseKey(environment_key);
      if (status != ERROR_SUCCESS) {
        console::write_line("An error 0x{:X8} occurred when close registry key", status);
        return 4;
      }

      auto result = SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)L"Environment", SMTO_ABORTIFHUNG, 5000, NULL);
      if (result == 0) {
        console::write_line("An error 0x{:X8} occurred when SendMessageTimeout", GetLastError());
        return 5;
      }
      #endif
      return 0;
    }
  };
}

startup_(set_path::program::main);
