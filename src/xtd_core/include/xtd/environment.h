/// @file
/// @brief Contains xtd::environment class.
#pragma once
#include <map>
#include <cstdlib>
#include <thread>
#include <vector>

//#include <xtd/io>
#include <xtd/xtd.strings>

#include "__opaque_environment.h"
#include "environment_variable_target.h"
#include "guid.h"
#include "operating_system.h"
#include "platform_id.h"
#include "static.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The environment class.
  class environment static_ {
  public:
    /// @enum special_folder
    /// @brief Specifies enumerated constants used to retrieve directory paths to system special folders.
    /// @remarks The system special folders are folders such as Program Files, Programs, System, or Startup, which contain common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    /// @remarks The get_folder_path method returns the locations associated with this enumeration. The locations of these folders can have different values on different operating systems, the user can change some of the locations, and the locations are localized.
    /// @remarks For more information about special folders, see the KNOWNFOLDERID constants in the Windows documentation.
    /// @remarks The list below typically represents special folders by OS :
    /// | Name                     | android                    | iOS                              | Linux                      | macOS                            | Windows                                                                                              |
    /// |--------------------------|----------------------------|----------------------------------|----------------------------|----------------------------------|------------------------------------------------------------------------------------------------------|
    /// | desktop                  | /home/${User}/Desktop      | /Users/${User}/Desktop           | /home/${User}/Desktop      | /Users/${User}/Desktop           | C:\\Users\\${User}\\Desktop                                                                          |
    /// | programs                 |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs                       |
    /// | my_documents             | /home/${User}              | /Users/${User}                   | /home/${User}              | /Users/${User}                   | C:\\Users\\${User}\\Documents                                                                        |
    /// | personal                 | /home/${User}              | /Users/${User}                   | /home/${User}              | /Users/${User}                   | C:\\Users\\${User}\\Documents                                                                        |
    /// | favorites                |                            | /Users/${User}/Library/Favorites |                            | /Users/${User}/Library/Favorites | C:\\Users\\${User}\\Favorites                                                                        |
    /// | startup                  |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup              |
    /// | recent                   |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Recent                                     |
    /// | send_to                  |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\SendTo                                     |
    /// | start_menu               |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu                                 |
    /// | my_music                 | /home/${User}/Music        | /Users/${User}/Music             | /home/${User}/Music        | /Users/${User}/Music             | C:\\Users\\${User}\\Music                                                                            |
    /// | my_videos                | /home/${User}/Videos       | /Users/${User}/Videos            | /home/${User}/Videos       | /Users/${User}/Videos            | C:\\Users\\${User}\\Videos                                                                           |
    /// | desktop_directory        | /home/${User}/Desktop      | /Users/${User}/Desktop           | /home/${User}/Desktop      | /Users/${User}/Desktop           | C:\\Users\\${User}\\Desktop                                                                          |
    /// | my_computer              |                            |                                  |                            |                                  |                                                                                                      |
    /// | network_shortcuts        |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Network Shortcuts                          |
    /// | fonts                    | /home/${User}/.fonts       | /Users/${User}/Library/Fonts     | /home/${User}/.fonts       | /Users/${User}/Library/Fonts     | C:\\Windows\\Fonts                                                                                   |
    /// | templates                | /home/${User}/Templates    | /Users/${User}/Templates         | /home/${User}/Templates    | /Users/${User}/Templates         | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Templates                                  |
    /// | common_start_menu        |                            |                                  |                            |                                  | C:\\ProgramData\\Microsoft\\Windows\\Start Menu                                                      |
    /// | common_programs          |                            |                                  |                            |                                  | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs                                            |
    /// | common_startup           |                            |                                  |                            |                                  | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup                                   |
    /// | common_desktop_directory |                            |                                  |                            |                                  | C:\\Users\\Public\\Desktop                                                                           |
    /// | application_data         | /home/${User}/.config      | /Users/${User}/.config           | /home/${User}/.config      | /Users/${User}/.config           | C:\\Users\\${User}\\AppData\\Roaming                                                                 |
    /// | printer_shortcuts        |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Printer Shortcuts                          |
    /// | local_application_data   | /home/${User}/.local/share | /Users/${User}/.local/share      | /home/${User}/.local/share | /Users/${User}/.local/share      | C:\\Users\\${User}\\AppData\\Local                                                                   |
    /// | internet_cache           |                            | /Users/${User}/Library/Caches    |                            | /Users/${User}/Library/Caches    | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files                     |
    /// | cookies                  |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Cookies                                    |
    /// | history                  |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\History                                      |
    /// | common_application_data  | /usr/share                 | /usr/share                       | /usr/share                 | /usr/share                       | C:\\ProgramData                                                                                      |
    /// | windows                  |                            |                                  |                            |                                  | C:\\Windows                                                                                          |
    /// | system                   |                            |                                  |                            |                                  | C:\\Windows\\system32                                                                                |
    /// | program_files            |                            | /Applications                    |                            | /Applications                    | C:\\Program Files (x86)                                                                              |
    /// | my_pictures              | /home/${User}/Pictures     | /Users/${User}/Pictures          | /home/${User}/Pictures     | /Users/${User}/Pictures          | C:\\Users\\${User}\\Pictures                                                                         |
    /// | user_profile             | /home/${User}              | /Users/${User}                   | /home/${User}              | /Users/${User}                   | C:\\Users\\${User}                                                                                   |
    /// | system_x86               |                            |                                  |                            |                                  | C:\\Windows\\SysWOW64                                                                                |
    /// | program_files_x86        |                            |                                  |                            |                                  | C:\\Program Files (x86)                                                                              |
    /// | common_program_files     |                            |                                  |                            |                                  | C:\\Program Files (x86)\\Common Files                                                                |
    /// | common_program_files_x86 |                            |                                  |                            |                                  | C:\\Program Files (x86)\\Common Files                                                                |
    /// | common_templates         | /usr/share/templates       | /usr/share/templates             | /usr/share/templates       | /usr/share/templates             | C:\\ProgramData\\Microsoft\\Windows\\Templates                                                       |
    /// | common_documents         |                            |                                  |                            |                                  | C:\\Users\\Public\\Documents                                                                         |
    /// | common_admin_tools       |                            |                                  |                            |                                  | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Administrative Tools                      |
    /// | admin_tools              |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Administrative Tools |
    /// | common_music             |                            |                                  |                            |                                  | C:\\Users\\Public\\Music                                                                             |
    /// | common_pictures          |                            |                                  |                            |                                  | C:\\Users\\Public\\Pictures                                                                          |
    /// | common_videos            |                            |                                  |                            |                                  | C:\\Users\\Public\\Videos                                                                            |
    /// | resources                |                            |                                  |                            |                                  | C:\\Windows\\resources                                                                               |
    /// | localized_resources      |                            |                                  |                            |                                  |                                                                                                      |
    /// | common_oem_links         |                            |                                  |                            |                                  |                                                                                                      |
    /// | cd_burning               |                            |                                  |                            |                                  | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\Burn\\Burn                                   |
    /// * ${User} represent the login user name.
    /// @see environment
    enum class special_folder {
      /// @brief The logical Desktop rather than the physical file system location.
      desktop = 0,
      /// @brief The directory that contains the user's program groups.
      programs = 2,
      /// @brief The My Documents folder. This member is equivalent to Personal.
      my_documents = 5,
      /// @brief The directory that serves as a common repository for documents. This member is equivalent to MyDocuments.
      personal = 5,
      /// @brief The directory that serves as a common repository for the user's favorite items.
      favorites = 6,
      /// @brief The directory that corresponds to the user's Startup program group. The system starts these programs whenever a user logs on or starts Windows NT or later, or starts Windows 98.
      startup = 7,
      /// @brief The directory that contains the user's most recently used documents.
      recent = 8,
      /// @brief The directory that contains the Send To menu items.
      send_to = 9,
      /// @brief The directory that contains the Start menu items.
      start_menu = 11,
      /// @brief The My Music folder.
      my_music = 13,
      /// @brief The file system directory that serves as a repository for videos that belong to a user.
      my_videos = 14,
      /// @brief The directory used to physically store file objects on the desktop. Do not confuse this directory with the desktop folder itself, which is a virtual folder.
      desktop_directory = 16,
      /// @brief The My Computer folder. The MyComputer constant always yields the empty string ("") because no path is defined for the My Computer folder.
      my_computer = 17,
      /// @brief A file system directory that contains the link objects that may exist in the My Network Places virtual folder.
      network_shortcuts = 19,
      /// @brief A virtual folder that contains fonts.
      fonts = 20,
      /// @brief The directory that serves as a common repository for document templates.
      templates = 21,
      /// @brief The file system directory that contains the programs and folders that appear on the Start menu for all users. This special folder is valid only for Windows NT systems.
      common_start_menu = 22,
      /// @brief A folder for components that are shared across applications. This special folder is valid only for Windows NT, Windows 2000, and Windows XP systems.
      common_programs = 23,
      /// @brief The file system directory that contains the programs that appear in the Startup folder for all users. This special folder is valid only for Windows NT systems.
      common_startup = 24,
      /// @brief The file system directory that contains files and folders that appear on the desktop for all users. This special folder is valid only for Windows NT systems.
      common_desktop_directory = 25,
      /// @brief The directory that serves as a common repository for application-specific data for the current roaming user. A roaming user works on more than one computer on a network. A roaming user's profile is kept on a server on the network and is loaded onto a system when the user logs on.
      application_data = 26,
      /// @brief The file system directory that contains the link objects that can exist in the Printers virtual folder.
      printer_shortcuts = 27,
      /// @brief The directory that serves as a common repository for application-specific data that is used by the current, non-roaming user.
      local_application_data = 28,
      /// @brief The directory that serves as a common repository for temporary Internet files.
      internet_cache = 32,
      /// @brief The directory that serves as a common repository for Internet cookies.
      cookies = 33,
      /// @brief The directory that serves as a common repository for Internet history items.
      history = 34,
      /// @brief The directory that serves as a common repository for application-specific data that is used by all users.
      common_application_data = 35,
      /// @brief The Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT% environment variables.
      windows = 36,
      /// @brief The System directory.
      system = 37,
      /// @brief The program files directory.On a non-x86 system, passing ProgramFiles to the GetFolderPath method returns the path for non-x86 programs. To get the x86 program files directory on a non-x86 system, use the ProgramFilesX86 member.
      program_files = 38,
      /// @brief The My Pictures folder.
      my_pictures = 39,
      /// @brief The user's profile folder. Applications should not create files or folders at this level; they should put their data under the locations referred to by ApplicationData.
      user_profile = 40,
      /// @brief The Windows System folder.
      system_x86 = 41,
      /// @brief The Program Files folder On an x86 system, passing the ProgramFilesX86 member to the Environment.GetFolderPath method returns string.Empty; use the ProgramFiles member instead. You can determine whether Windows is a 32-bit operating system by calling the Environment.Is64BitOperatingSystem property.
      program_files_x86 = 42,
      /// @brief The directory for components that are shared across applications.To get the x86 common program files directory on a non-x86 system, use the ProgramFilesX86 member.
      common_program_files = 43,
      /// @brief The Program Files folder.
      common_program_files_x86 = 44,
      /// @brief The file system directory that contains the templates that are available to all users. This special folder is valid only for Windows NT systems.
      common_templates = 45,
      /// @brief The file system directory that contains documents that are common to all users. This special folder is valid for Windows NT systems, Windows 95, and Windows 98 systems with Shfolder.dll installed.
      common_documents = 46,
      /// @brief The file system directory that contains administrative tools for all users of the computer.
      common_admin_tools = 47,
      /// @brief The file system directory that is used to store administrative tools for an individual user. The Microsoft Management Console (MMC) will save customized consoles to this directory, and it will roam with the user.
      admin_tools = 48,
      /// @brief The file system directory that serves as a repository for music files common to all users.
      common_music = 53,
      /// @brief The file system directory that serves as a repository for image files common to all users.
      common_pictures = 54,
      /// @brief The file system directory that serves as a repository for video files common to all users.
      common_videos = 55,
      /// @brief The file system directory that contains resource data.
      resources = 56,
      /// @brief The file system directory that contains localized resource data.
      localized_resources = 57,
      /// @brief This value is recognized in Windows Vista for backward compatibility, but the special folder itself is no longer used.
      common_oem_links = 58,
      /// @brief The file system directory that acts as a staging area for files waiting to be written to a CD.
      cd_burning = 59,
      /// @brief
      home = 60
    };

    /// @brief Specifies options to use for getting the path to a special folder.
    /// @remarks The System.Environment.SpecialFolderOption enumeration is used to define the precise behavior of the Environment.GetFolderPath method.
    enum class special_folder_option {
      /// @brief The path to the folder is verified. If the folder exists, the path is returned. If the folder does not exist, an empty string is returned. This is the default behavior.
      none = 0,
      /// @brief The path to the folder is returned without verifying whether the path exists. If the folder is located on a network, specifying this option can reduce lag time.
      do_not_verify = 16384,
      /// @brief The path to the folder is created if it does not already exist.
      create = 32768
    };

    /// @brief Gets the command line for this process.
    /// @return A string containing command-line arguments.
    /// @remarks This method provides access to the program name and any arguments specified on the command line when the current process was started.
    /// @remarks The program name can include path information, but is not required to do so. Use the get_command_line_args method to retrieve the command-line information parsed and stored in an array of strings.
    /// @remarks The maximum size of the command-line buffer is not set to a specific number of characters; it varies depending on the operating system that is running on the computer.
    static std::string command_line() noexcept {return xtd::strings::join(" ", get_command_line_args());}
    
    /// @brief Gets the fully qualified path of the current working directory.
    /// @return std::sgtring A string containing a directory path.
    /// @remarks By definition, if this process starts in the root directory of a local or network drive, the value returned by this method is the drive name followed by a trailing slash (for example, "C:\"). If this process starts in a subdirectory, the value returned by this method is the drive and subdirectory path, without a trailing slash (for example, "C:\mySubDirectory").
    static std::string current_directory() noexcept {return __opaque_environment::get_current_directory();}
    
    /// @brief Sets the fully qualified path of the current working directory.
    /// @param directory_name A string containing a directory path.
    static void current_directory(const std::string& directory_name) {__opaque_environment::set_current_directory(directory_name);}
    
    /// @brief Gets a unique identifier for the current thread.
    /// @return A std::thread::id that represents a unique identifier for this thread.
    static std::thread::id current_thread_id() noexcept {return std::this_thread::get_id();}

    static int exit_code() noexcept;
    
    static void exit_code(int value) noexcept;
    
    /// @brief Returns a string array containing the command-line arguments for the current process.
    /// @return An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
    /// @remarks The first element in the array contains the file name of the executing program. If the file name is not available, the first element is equal to string empty "". The remaining elements contain any additional tokens entered on the command line.
    /// @remarks The program file name can, but is not required to, include path information.
    /// @remarks Command line arguments are delimited by spaces. You can use double quotation marks (") to include spaces within an argument. The single quotation mark ('), however, does not provide this functionality.
    /// @remarks If a double quotation mark follows two or an even number of backslashes, each proceeding backslash pair is replaced with one backslash and the double quotation mark is removed. If a double quotation mark follows an odd number of backslashes, including just one, each preceding pair is replaced with one backslash and the remaining backslash is removed; however, in this case the double quotation mark is not removed.
    /// @remarks The following table shows how command line arguments can be delimited, and assumes MyApp as the current executing application.
    /// | Input at the command line                    | Resulting command line arguments           |
    /// |----------------------------------------------|--------------------------------------------|
    /// | MyApp alpha beta                             | MyApp, alpha, beta                         |
    /// | MyApp "alpha with spaces" "beta with spaces" | MyApp, alpha with spaces, beta with spaces |
    /// | MyApp 'alpha with spaces' beta               | MyApp, 'alpha, with, spaces', beta         |
    /// | MyApp \\\alpha \\\\"beta                     | MyApp, \\\alpha, \\beta                    |
    /// | MyApp \\\\\"alpha \"beta                     | MyApp, \\"alpha, "beta                     |
    /// @remarks To obtain the command line as a single string, use the command_line method.
    static std::vector<std::string> get_command_line_args() noexcept;
    
    /// @brief Retrieves the value of an environment variable from the current process.
    /// @param variable The name of the environment variable.
    /// @return std::string The value of the environment variable specified by variable, or empty "" if the environment variable is not found.
    /// @remarks The get_environment_variable(std::string) method retrieves an environment variable from the environment block of the current process only. It is equivalent to calling the get_environment_variable(std::string, xtd::environment_variable_target) method with a target value of xtd::environment_variable_target.process.
    /// @remarks To retrieve all environment variables along with their values, call the get_environment_variables method.
    /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
    static std::string get_environment_variable(const std::string& variable) noexcept {return get_environment_variable(variable, environment_variable_target::process);}
    
    /// @brief Retrieves the value of an environment variable from the current process or from the Windows operating system registry key for the current user or local machine.
    /// @param variable The name of an environment variable.
    /// @param target One of the EnvironmentVariableTarget values.
    /// @exception std::invaloid_argument target is not a valid environment_variable_target value.
    /// @return std::string The value of the environment variable specified by the variable and target parameters, or empty "" if the environment variable is not found.
    /// @remarks To retrieve all environment variables along with their values, call the get_environment_variables method.
    /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
    /// @todo Add xtd::registry and uncomment lines.
   static std::string get_environment_variable(const std::string& variable, environment_variable_target target) {
      if (target == environment_variable_target::process)
        return __opaque_environment::get_environment_variable(variable);
      if (target == environment_variable_target::user)
        return ""; //return microsoft::win32::registry::get_value("HKEY_CURRENT_USER\\Environment", variable, "").to_string();
      if (target == environment_variable_target::machine)
        return ""; // return microsoft::win32::registry::get_value("HKEY_LOCAL_MACHINE\\System\\CurrentControlSet\\Control\\Session Manager\\Environment", variable, "").to_string();
      throw std::invalid_argument("invalid environment_variable_target value");
    }

    /// @brief Retrieves all environment variable names and their values from the current process.
    /// @return std::map A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
    /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned std::map.
    static std::map<std::string, std::string>& get_environment_variables() noexcept {return get_environment_variables(environment_variable_target::process);}

    /// @brief Retrieves all environment variable names and their values from the current process, or from the Windows operating system registry key for the current user or local machine.
    /// @param target One of the environment_variable_target values.
    /// @return std::map A dictionary that contains all environment variable names and their values from the source specified by the target parameter; otherwise, an empty dictionary if no environment variables are found.
    /// @exception std::invaloid_argument target is not a valid environment_variable_target value.
    /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned std::map.
    /// @todo Add xtd::registry and uncomment lines.
    static std::map<std::string, std::string>& get_environment_variables(environment_variable_target target);

    /// @brief Gets the path to the system special folder that is identified by the specified enumeration.
    /// @param folder One of enumeration values that identifies a system special folder.
    /// @return The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
    /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    static std::string get_folder_path(environment::special_folder folder) noexcept {return get_folder_path(folder, environment::special_folder_option::none);}
    
    /// @brief Gets the path to the system special folder that is identified by the specified enumeration, and uses a specified option for accessing special folders.
    /// @param folder One of the enumeration values that identifies a system special folder.
    /// @param option One of the enumeration values taht specifies options to use for accessing a special folder.
    /// @return The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
    /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    /// @todo Add xtd::io::directory and uncomment lines.
    static std::string get_folder_path(environment::special_folder folder, environment::special_folder_option option) {
      std::string path = __opaque_environment::get_know_folder_path(static_cast<int>(folder));
      
      //if (option == environment::special_folder_option::none)
      //  return !xtd::io::directory::exists(path) ? "" :  path;
      
      //if (!System::IO::Directory::Exists(path))
      //  xtd::io::directory::create_directory(path);
      
      return path;
    }
    
    /// @brief Returns an array of string containing the names of the logical drives on the current computer.
    /// @return An array of strings where each element contains the name of a logical drive. For example, if the computer's hard drive is the first logical drive, the first element returned is "C:\".
    /// @todo Add xtd::io::__opaque_io and uncomment lines.
    static std::vector<std::string> get_logical_drives() noexcept {
      return {}; //__opaque_io::get_drives();
    }
    
    /// @brief Terminates this process and returns an exit code to the operating system.
    /// @param exit_code The exit code to return to the operating system. Use 0 (zero) to indicate that the process completed successfully.
    /// @remarks For the exit_code parameter, use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present, and a value of 2 to indicate that the file is in the wrong format.
    static void exit(int exit_code) noexcept {::_Exit(exit_code);}
    
    /// @brief Replaces the name of each environment variable embedded in the specified string with the string equivalent of the value of the variable, then returns the resulting string.
    /// @param name A string containing the names of zero or more environment variables. Each environment variable is quoted with the percent sign character (%).
    /// @return A string with each environment variable replaced by its value.
    /// @remarks Replacement only occurs for environment variables that are set. For example, suppose name is "MyENV = %MyENV%". If the environment variable, MyENV, is set to 42, this method returns "MyENV = 42". If MyENV is not set, no change occurs; this method returns "MyENV = %MyENV%".
    static std::string expand_environment_variables(const std::string& name) noexcept {
      std::string buffer = name;
      std::string result;
      
      size_t index = xtd::strings::index_of(buffer, '%');
      while (index != std::string::npos && xtd::strings::index_of(buffer, '%', index + 1) != -1) {
        result += xtd::strings::substring(buffer, 0, index);
        buffer = xtd::strings::remove(buffer, 0, index + 1);
        index = xtd::strings::index_of(buffer, '%');
        if (get_environment_variable(xtd::strings::substring(buffer, 0, index)) != "")
          result += get_environment_variable(xtd::strings::substring(buffer, 0, index));
        else
          result += xtd::strings::format("%{0}%", xtd::strings::substring(buffer, 0, index));
        buffer = xtd::strings::remove(buffer, 0, index + 1);
        index = xtd::strings::index_of(buffer, '%');
      }
      result += buffer;
      return result;
    }

    /// @brief Determines whether the current operating system is a 64-bit operating system.
    /// @return true if the operating system is 64-bit; otherwise, false.
    static bool is_64_bit_operating_system() noexcept {return __opaque_environment::is_os_64_bit();}
    
    /// @brief Determines whether the current process is a 64-bit process.
    /// @return true if the process is 64-bit; otherwise, false.
    static bool is_64_bit_process() noexcept {return sizeof(size_t) == 8;}

    /// @brief Gets the NetBIOS name of this local computer.
    /// @return A string containing the name of this computer.
    /// @remarks The name of this computer is established at system startup when the name is read from the registry. If this computer is a node in a cluster, the name of the node is returned.
    static std::string machine_name() noexcept {return __opaque_environment::get_machine_name();}
    
    /// @brief Gets the newline string defined for this environment.
    /// @return A string containing "\r\n" for non-Unix platforms, or a string containing "\n" for Unix platforms.
    static std::string new_line() noexcept {return __opaque_environment::new_line();}

    /// @brief Inserts a new-line character and flushes the stream.
    /// @param os Output stream object affected. Because this function is a manipulator, it is designed to be used alone with no arguments in conjunction with the insertion (<<) operations on output streams (see example below).
    /// @return Argument os.
    template <class Char, class Traits>
    static std::basic_ostream<Char, Traits>& new_line(std::basic_ostream<Char, Traits>& os) {
      os.put(os.widen('\n'));
      os.flush();
      return os;
    }
    
    /// @brief Gets an operating_system object that contains the current platform identifier and version number.
    /// @return An object that contains the platform identifier and version number.
    static xtd::operating_system os_version() noexcept {
      static xtd::operating_system os(xtd::platform_id::unknown, xtd::version());
      if (os.platform() == xtd::platform_id::unknown) {
        int major, minor, build, revision;
        __opaque_environment::get_os_version(major, minor, build, revision);
        xtd::version version;
        version = xtd::version(major, minor, build, revision);
        os = operating_system(__opaque_environment::get_os_platform_id(), version, __opaque_environment::get_service_pack(), __opaque_environment::get_desktop_environment());
      }
      return os;
    }

    /// @brief Gets the number of processors on the current machine.
    /// @return The 32-bit unsigned integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors that are available for use.
    static unsigned int processor_count() noexcept {return __opaque_environment::get_processor_count();}

    /// @brief Creates, modifies, or deletes an environment variable stored in the current process.
    /// @param variable The name of an environment variable.
    /// @param value A value to assign to variable.
    /// @remarks Calling this method is equivalent to calling the set_environment_variable(std::string, std::string, environment_variable_target) overload with a value of environment_variable_target::process for the target argument.
    /// @remarks If the value argument is not empty and the environment variable named by the variable parameter does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified. Because the environment variable is defined in the environment block of the current process only, it does not persist after the process has ended.
    /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. If variable does not exist, no error occurs even though the operation cannot be performed.
    static void set_environment_variable(const std::string& variable, const std::string& value) {
      set_environment_variable(variable, value, environment_variable_target::process);
    }
    
    /// @brief Creates, modifies, or deletes an environment variable stored in the current process or in the Windows operating system registry key reserved for the current user or local machine.
    /// @param variable The name of an environment variable.
    /// @param value A value to assign to variable.
    /// @remarks The set_environment_variable(std::string, std::string, environment_variable_target) method lets you define an environment variable that is available to the current process (the environment_variable_target::process value). Environment variables that are unique to the current process environment block persist only until the process ends.
    /// @remarks In addition, on Windows systems only, the set_environment_variable(std::string, std::string, environment_variable_target) method lets you define an environment variable that is available to all processes that run on a machine (the environment_variable_target::machine value) and to all processes run by a user (the environment_variable_target::user value). Per-machine and per-user environment variables are copied into the environment block of the current process.
    /// @remarks If the value argument is not empty and the environment variable named by the variable argument does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified.
    /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. If variable does not exist, no error occurs even though the operation cannot be performed.
    /// @todo Add xtd::registry and uncomment lines.
    static void set_environment_variable(const std::string& variable, const std::string& value, environment_variable_target target) {
      if (xtd::strings::is_empty(variable)) throw std::invalid_argument("name is empty");
      
      if (target == environment_variable_target::process) {
        if (xtd::strings::is_empty(value)) {
          get_environment_variables().erase(variable);
          if (__opaque_environment::unset_env(variable) != 0) throw std::invalid_argument("can't erase environment variable");
        } else {
          get_environment_variables()[variable] = value;
          if (__opaque_environment::set_env(variable, value) != 0) throw std::invalid_argument("can't set environment variable");
        }
      } else if(target == environment_variable_target::user || target == environment_variable_target::machine) {
        //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
        //if (xtd::strings::is_empty(value))
        //  key.delete_value(variable);
        //else
        //  key.set_value(variable, value);
      } else
        throw std::invalid_argument("invalid environment_variable_target value");
    }

    /// @brief Gets current stack trace information.
    /// @return A string containing stack trace information. This value can be empty "".
    /// @todo Add xtd::diagnostics and uncomment line.
    static std::string stack_trace() noexcept {
      return ""; // return xtd::diagnostics::stack_trace(3, true).to_string();
    }
    
    /// @brief Gets the fully qualified path of the system directory.
    /// @return A string containing a directory path.
    /// @remarks An example of the value returned is the string "C:\Windows".
    static std::string system_directory() noexcept {return get_folder_path(environment::special_folder::system);}

    /// @brief Gets the number of bytes in the operating system's memory page.
    /// @return The number of bytes in the system memory page.
    static size_t system_page_size() noexcept {return __opaque_environment::get_system_page_size();}

    /// @brief Gets the number of milliseconds elapsed since the system started.
    /// @return A 32-bit unsigned integer containing the amount of time in milliseconds that has passed since the last time the computer was started.
    static std::chrono::milliseconds tick_count() noexcept {return std::chrono::milliseconds(__opaque_environment::get_tick_count());}
    
    /// @brief Gets the network domain name associated with the current user.
    /// @return The network domain name associated with the current user.
    static std::string user_domain_name() noexcept {return __opaque_environment::get_user_domain_name();}
    
    /// @brief Gets a value indicating whether the current process is running in user interactive mode.
    /// @return bool true if the current process is running in user interactive mode; otherwise, false.
    /// @remarks The user_interactive method reports false for a Os process or a service like IIS that runs without a user interface. If this property is false, do not display modal dialogs or message boxes because there is no graphical user interface for the user to interact with.
    /// @remarks Return always true for now.
    /// @todo check if process is an operating system process or service process...
    static bool user_interactive() noexcept {return true;}
    
    /// @brief Gets the user name of the person who is currently logged on to the operating system.
    /// @return The user name of the person who is logged on to the operating system.
    static std::string user_name() noexcept {return __opaque_environment::get_user_name();}
  };

  /// @cond
  inline std::ostream& operator<<(std::ostream& os, environment::special_folder value) {return os << to_string(value, {{environment::special_folder::desktop, "desktop"}, {environment::special_folder::programs, "programs"}, {environment::special_folder::my_documents, "my_documents"}, {environment::special_folder::personal, "personal"}, {environment::special_folder::favorites, "favorites"}, {environment::special_folder::startup, "startup"}, {environment::special_folder::recent, "recent"}, {environment::special_folder::send_to, "send_to"}, {environment::special_folder::start_menu, "start_menu"}, {environment::special_folder::personal, "my_music"}, {environment::special_folder::my_videos, "my_videos"}, {environment::special_folder::desktop_directory, "desktop_direcyory"}, {environment::special_folder::my_computer, "my_computer"}, {environment::special_folder::network_shortcuts, "network_shortcuts"}, {environment::special_folder::fonts, "fonts"}, {environment::special_folder::templates, "templates"}, {environment::special_folder::common_start_menu, "common_start_menu"}, {environment::special_folder::common_programs, "common_programs"}, {environment::special_folder::common_startup, "common_startup"}, {environment::special_folder::common_desktop_directory, "common_desktop_directory"}, {environment::special_folder::application_data, "application_data"}, {environment::special_folder::printer_shortcuts, "printer_shortcuts"}, {environment::special_folder::local_application_data, "local_application_data"}, {environment::special_folder::internet_cache, "internet_cahe"}, {environment::special_folder::cookies, "cookies"}, {environment::special_folder::history, "history"}, {environment::special_folder::common_application_data, "common_application_data"}, {environment::special_folder::windows, "windows"}, {environment::special_folder::system, "system"}, {environment::special_folder::program_files, "program_files"}, {environment::special_folder::my_pictures, "my_pictures"}, {environment::special_folder::user_profile, "user_profile"}, {environment::special_folder::system_x86, "system_x86"}, {environment::special_folder::program_files_x86, "program_files_x86"}, {environment::special_folder::common_program_files, "common_program_files"}, {environment::special_folder::common_program_files_x86, "common_program_files_x86"}, {environment::special_folder::common_templates, "common_templates"}, {environment::special_folder::common_documents, "common_documents"}, {environment::special_folder::common_admin_tools, "common_admin_tools"}, {environment::special_folder::admin_tools, "admin_tools"}, {environment::special_folder::common_music, "common_music"}, {environment::special_folder::common_pictures, "common_pictures"}, {environment::special_folder::common_videos, "common_videos"}, {environment::special_folder::resources, "resources"}, {environment::special_folder::localized_resources, "localized_resources"}, {environment::special_folder::common_oem_links, "common_oem_links"}, {environment::special_folder::cd_burning, "cd_burning"}, {environment::special_folder::home, "home"}});}
  inline std::wostream& operator<<(std::wostream& os, environment::special_folder value) {return os << to_string(value, {{environment::special_folder::desktop, L"desktop"}, {environment::special_folder::programs, L"programs"}, {environment::special_folder::my_documents, L"my_documents"}, {environment::special_folder::personal, L"personal"}, {environment::special_folder::favorites, L"favorites"}, {environment::special_folder::startup, L"startup"}, {environment::special_folder::recent, L"recent"}, {environment::special_folder::send_to, L"send_to"}, {environment::special_folder::start_menu, L"start_menu"}, {environment::special_folder::personal, L"my_music"}, {environment::special_folder::my_videos, L"my_videos"}, {environment::special_folder::desktop_directory, L"desktop_directory"}, {environment::special_folder::my_computer, L"my_computer"}, {environment::special_folder::network_shortcuts, L"network_shortcuts"}, {environment::special_folder::fonts, L"fonts"}, {environment::special_folder::templates, L"templates"}, {environment::special_folder::common_start_menu, L"common_start_menu"}, {environment::special_folder::common_programs, L"common_programs"}, {environment::special_folder::common_startup, L"common_startup"}, {environment::special_folder::common_desktop_directory, L"common_desktop_directory"}, {environment::special_folder::application_data, L"application_data"}, {environment::special_folder::printer_shortcuts, L"printer_shortcuts"}, {environment::special_folder::local_application_data, L"local_application_data"}, {environment::special_folder::internet_cache, L"internet_cache"}, {environment::special_folder::cookies, L"cookies"}, {environment::special_folder::history, L"history"}, {environment::special_folder::common_application_data, L"common_application_data"}, {environment::special_folder::windows, L"windows"}, {environment::special_folder::system, L"system"}, {environment::special_folder::program_files, L"program_files"}, {environment::special_folder::my_pictures, L"my_pictures"}, {environment::special_folder::user_profile, L"user_profile"}, {environment::special_folder::system_x86, L"system_x86"}, {environment::special_folder::program_files_x86, L"program_files_x86"}, {environment::special_folder::common_program_files, L"common_program_files"}, {environment::special_folder::common_program_files_x86, L"common_program_files_x86"}, {environment::special_folder::common_templates, L"common_templates"}, {environment::special_folder::common_documents, L"common_documents"}, {environment::special_folder::common_admin_tools, L"common_admin_tools"}, {environment::special_folder::admin_tools, L"admin_tools"}, {environment::special_folder::common_music, L"common_music"}, {environment::special_folder::common_pictures, L"common_pictures"}, {environment::special_folder::common_videos, L"common_videos"}, {environment::special_folder::resources, L"resources"}, {environment::special_folder::localized_resources, L"localized_resources"}, {environment::special_folder::common_oem_links, L"common_oem_links"}, {environment::special_folder::cd_burning, L"cd_burning"}, {environment::special_folder::home, L"home"}});}
  inline std::ostream& operator<<(std::ostream& os, environment::special_folder_option value) {return os << to_string(value, {{environment::special_folder_option::none, "none"}, {environment::special_folder_option::do_not_verify, "do_not_verify"}, {environment::special_folder_option::create, "create"}});}
  inline std::wostream& operator<<(std::wostream& os, environment::special_folder_option value) {return os << to_string(value, {{environment::special_folder_option::none, L"none"}, {environment::special_folder_option::do_not_verify, L"do_not_verify"}, {environment::special_folder_option::create, L"create"}});}
  /// @endcond
}
