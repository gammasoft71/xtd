/// @file
/// @brief Contains xtd::environment class.
#pragma once
#include "__opaque_environment.hpp"
#include "environment_variable_target.hpp"
#include "guid.hpp"
//#include "platform_id.hpp"
#include "version.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The environment class.
  class environment final {
  public:
    /// @cond
    environment() = delete;
    /// @endcond
 
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
      /// @brief The My Documents folder.
      /// This member is equivalent to Personal.
      my_documents = 5,
      /// @brief The directory that serves as a common repository for documents.
      /// This member is equivalent to MyDocuments.
      personal = 5,
      /// @brief The directory that serves as a common repository for the user's favorite items.
      favorites = 6,
      /// @brief The directory that corresponds to the user's Startup program group.
      /// The system starts these programs whenever a user logs on or starts Windows NT or later, or starts Windows 98.
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
      /// @brief The directory used to physically store file objects on the desktop.
      /// Do not confuse this directory with the desktop folder itself, which is a virtual folder.
      desktop_directory = 16,
      /// @brief The My Computer folder.
      /// The MyComputer constant always yields the empty string ("") because no path is defined for the My Computer folder.
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
      /// @brief The directory that serves as a common repository for application-specific data for the current roaming user.
      /// A roaming user works on more than one computer on a network. A roaming user's profile is kept on a server on the network and is loaded onto a system when the user logs on.
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

    static std::string get_environment_variable(const std::string& variable) {
      return get_environment_variable(variable, environment_variable_target::process);
    }
    
    static std::string get_environment_variable(const std::string& variable, environment_variable_target target) {
      if (target == environment_variable_target::process) {
        char* value = getenv(variable.c_str());
        return value == nullptr ? "" : value;
      } else  if (target == environment_variable_target::user)
        return ""; //return microsoft::win32::registry::get_value("HKEY_CURRENT_USER\\Environment", variable, "").to_string();
      return ""; // return microsoft::win32::registry::get_value("HKEY_LOCAL_MACHINE\\System\\CurrentControlSet\\Control\\Session Manager\\Environment", variable, "").to_string();
    }

    static std::string get_folder_path(environment::special_folder folder) {
      return get_folder_path(folder, environment::special_folder_option::none);
    }
    
    static std::string get_folder_path(environment::special_folder folder, environment::special_folder_option option) {
      std::string path = __opaque_environment::get_know_folder_path(static_cast<int>(folder));
      
      //if (option == environment::special_folder_option::none)
      //  return !System::IO::Directory::Exists(path) ? "" :  path;
      
      //if (!System::IO::Directory::Exists(path))
      //  System::IO::Directory::CreateDirectory(path);
      
      return path;
    }

    static std::string expand_environment_variables(const std::string& name) {
      std::string buffer = name;
      std::string result;
      
      int index = xtd::strings::index_of(buffer, '%');
      while (index != -1 && xtd::strings::index_of(buffer, '%', index + 1) != -1) {
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

    static std::string new_line() noexcept {return __opaque_environment::new_line();}

    static std::string user_name() noexcept {return __opaque_environment::get_user_name();}

  };
}
