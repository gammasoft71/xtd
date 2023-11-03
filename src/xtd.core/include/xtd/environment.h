/// @file
/// @brief Contains xtd::environment class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "collections/specialized/string_vector.h"
#include "diagnostics/stack_trace.h"
#include "io/directory.h"
#include "argument_exception.h"
#include "as.h"
#include "compiler.h"
#include "core_export.h"
#include "cpp_language.h"
#include "enum.h"
#include "environment_variable_target.h"
#include "event.h"
#include "exit_status.h"
#include "guid.h"
#include "operating_system.h"
#include "platform_id.h"
#include "processor.h"
#include "program_exit_event_handler.h"
#include "signal_cancel_event_handler.h"
#include "static.h"
#include "target_type.h"
#include "toolkit.h"
#include "ustring.h"
#include "version.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__build_type.h"
#include "internal/__compiler_id.h"
#include "internal/__compiler_version.h"
#include "internal/__cpp_language.h"
#undef __XTD_CORE_INTERNAL__
#include <map>
#include <cstdlib>
#include <vector>

/// @cond
// The following constants are defined in the file xtd_command.cmake.
// If the target project is not built with cmake, each constant must be defined by the build tool like this:
// | Constant                       | Value                                            |
// | ------------------------------ | ------------------------------------------------ |
// | __XTD_INCLUDE_PATH__           | ${XTD_INSTALL_PATH}/include"                     |
// | __XTD_LIB_PATH__               | ${XTD_INSTALL_PATH}/lib"                         |
// | __XTD_CONSOLE_INCLUDE_PATH__   | ${XTD_CONSOLE_INSTALL_PATH}/include"             |
// | __XTD_CONSOLE_LIB_PATH__       | ${XTD_CONSOLE_INSTALL_PATH}/lib"                 |
// | __XTD_DRAWING_INCLUDE_PATH__   | ${XTD_DRAWING_INSTALL_PATH}/include"             |
// | __XTD_DRAWING_LIB_PATH__       | ${XTD_DRAWING_INSTALL_PATH}/lib"                 |
// | __XTD_DRAWING_RESOURCES_PATH__ | ${XTD_DRAWING_INSTALL_PATH}/share/xtd/resources" |
// | __XTD_FORMS_INCLUDE_PATH__     | ${XTD_FORMS_INSTALL_PATH}/include"               |
// | __XTD_FORMS_LIB_PATH__         | ${XTD_FORMS_INSTALL_PATH}/lib"                   |
// | __XTD_FORMS_RESOURCES_PATH__   | ${XTD_FORMS_INSTALL_PATH}/share/xtd/resources"   |
// | __XTD_TUNIT_INCLUDE_PATH__     | ${XTD_TUNIT_INSTALL_PATH}/include"               |
// | __XTD_TUNIT_LIB_PATH__         | ${XTD_TUNIT_INSTALL_PATH}/lib"                   |
#if !defined(__XTD_INCLUDE_PATH__) || !defined(__XTD_LIB_PATH__) || !defined(__XTD_CONSOLE_INCLUDE_PATH__) || !defined(__XTD_CONSOLE_LIB_PATH__) || !defined(__XTD_DRAWING_INCLUDE_PATH__) || !defined(__XTD_DRAWING_LIB_PATH__) || !defined(__XTD_DRAWING_RESOURCES_PATH__) || !defined(__XTD_FORMS_INCLUDE_PATH__) || !defined(__XTD_FORMS_LIB_PATH__) || !defined(__XTD_FORMS_RESOURCES_PATH__) || !defined(__XTD_TUNIT_INCLUDE_PATH__) || !defined(__XTD_TUNIT_LIB_PATH__)
#error "Some variables (like __XTD_INCLUDE_PATH__) are not defined. This is probably because you are not using CMake to generate your project. See the following link for more information: https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.cmake/Overview..."
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The environment class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system system_information
  /// @par Examples
  /// The following example demonstrates displays a list of information about the current environment.
  /// @include examples/xtd.core.examples/environment/environment/src/environment.cpp
  /// @remarks Use the xtd::environment class to retrieve information such as command-line arguments, the exit code, environment variable settings, contents of the call stack, time since last system boot, and the version of the xtd framework.
  class core_export_ environment final static_ {
    class signal_catcher;
  public:
    /// @enum xtd::environment::special_folder
    /// @brief Specifies enumerated constants used to retrieve directory paths to system special folders.
    /// @remarks The system special folders are folders such as Program Files, Programs, System, or Startup, which contain common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    /// @remarks The xtd::environment::get_folder_path method returns the locations associated with this enumeration. The locations of these folders can have different values on different operating systems, the user can change some of the locations, and the locations are localized.
    /// @remarks For more information about special folders, see the KNOWNFOLDERID constants in the Windows documentation.
    /// @remarks The list below typically represents special folders by OS :
    /// | Name                     | android                              | iOS                                  | Linux                                | macOS                                     | Windows                                                                                              |
    /// | ------------------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ | ----------------------------------------- | ---------------------------------------------------------------------------------------------------- |
    /// | desktop                  | /home/${User}/Desktop                | /Users/${User}/Desktop               | /home/${User}/Desktop                | /Users/${User}/Desktop                    | C:\\Users\\${User}\\Desktop                                                                          |
    /// | programs                 |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs                       |
    /// | my_documents             | /home/${User}                        | /Users/${User}                       | /home/${User}                        | /Users/${User}                            | C:\\Users\\${User}\\Documents                                                                        |
    /// | personal                 | /home/${User}                        | /Users/${User}                       | /home/${User}                        | /Users/${User}                            | C:\\Users\\${User}\\Documents                                                                        |
    /// | favorites                |                                      | /Users/${User}/Library/Favorites     |                                      | /Users/${User}/Library/Favorites          | C:\\Users\\${User}\\Favorites                                                                        |
    /// | startup                  |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup              |
    /// | recent                   |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Recent                                     |
    /// | send_to                  |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\SendTo                                     |
    /// | start_menu               |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu                                 |
    /// | my_music                 | /home/${User}/Music                  | /Users/${User}/Music                 | /home/${User}/Music                  | /Users/${User}/Music                      | C:\\Users\\${User}\\Music                                                                            |
    /// | my_videos                | /home/${User}/Movies                 | /Users/${User}/Movies                | /home/${User}/Movies                 | /Users/${User}/Movies                     | C:\\Users\\${User}\\Movies                                                                           |
    /// | desktop_directory        | /home/${User}/Desktop                | /Users/${User}/Desktop               | /home/${User}/Desktop                | /Users/${User}/Desktop                    | C:\\Users\\${User}\\Desktop                                                                          |
    /// | my_computer              |                                      |                                      |                                      |                                           |                                                                                                      |
    /// | network_shortcuts        |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Network Shortcuts                          |
    /// | fonts                    | /home/${User}/.fonts                 | /Users/${User}/Library/Fonts         | /home/${User}/.fonts                 | /Users/${User}/Library/Fonts              | C:\\Windows\\Fonts                                                                                   |
    /// | templates                | /home/${User}/Templates              | /Users/${User}/Templates             | /home/${User}/Templates              | /Users/${User}/Templates                  | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Templates                                  |
    /// | common_start_menu        |                                      |                                      |                                      |                                           | C:\\ProgramData\\Microsoft\\Windows\\Start Menu                                                      |
    /// | common_programs          |                                      |                                      |                                      |                                           | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs                                            |
    /// | common_startup           |                                      |                                      |                                      |                                           | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup                                   |
    /// | common_desktop_directory |                                      |                                      |                                      |                                           | C:\\Users\\Public\\Desktop                                                                           |
    /// | application_data         | /home/${User}/.config                | /Users/${User}/.config               | /home/${User}/.config                | /Users/${User}/.config                    | C:\\Users\\${User}\\AppData\\Roaming                                                                 |
    /// | printer_shortcuts        |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Printer Shortcuts                          |
    /// | local_application_data   | /home/${User}/.local/share           | /Users/${User}/.local/share          | /home/${User}/.local/share           | /Users/${User}/.local/share               | C:\\Users\\${User}\\AppData\\Local                                                                   |
    /// | internet_cache           |                                      | /Users/${User}/Library/Caches        |                                      | /Users/${User}/Library/Caches             | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\Temporary Internet Files                     |
    /// | cookies                  |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Cookies                                    |
    /// | history                  |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\History                                      |
    /// | common_application_data  | /usr/share                           | /usr/share                           | /usr/share                           | /usr/share                                | C:\\ProgramData                                                                                      |
    /// | windows                  |                                      |                                      |                                      |                                           | C:\\Windows                                                                                          |
    /// | system                   |                                      | /System                              |                                      |  /System                                  | C:\\Windows\\system32                                                                                |
    /// | program_files            |                                      | /Applications                        |                                      | /Applications                             | C:\\Program Files (x86)                                                                              |
    /// | my_pictures              | /home/${User}/Pictures               | /Users/${User}/Pictures              | /home/${User}/Pictures               | /Users/${User}/Pictures                   | C:\\Users\\${User}\\Pictures                                                                         |
    /// | user_profile             | /home/${User}                        | /Users/${User}                       | /home/${User}                        | /Users/${User}                            | C:\\Users\\${User}                                                                                   |
    /// | system_x86               |                                      |                                      |                                      |                                           | C:\\Windows\\SysWOW64                                                                                |
    /// | program_files_x86        |                                      |                                      |                                      |                                           | C:\\Program Files (x86)                                                                              |
    /// | common_program_files     |                                      |                                      |                                      |                                           | C:\\Program Files (x86)\\Common Files                                                                |
    /// | common_program_files_x86 |                                      |                                      |                                      |                                           | C:\\Program Files (x86)\\Common Files                                                                |
    /// | common_templates         | /usr/share/templates                 |                                      | /usr/share/templates                 |                                           | C:\\ProgramData\\Microsoft\\Windows\\Templates                                                       |
    /// | common_documents         |                                      |                                      |                                      |                                           | C:\\Users\\Public\\Documents                                                                         |
    /// | common_admin_tools       |                                      |                                      |                                      |                                           | C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Administrative Tools                      |
    /// | admin_tools              |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Administrative Tools |
    /// | common_music             |                                      |                                      |                                      |                                           | C:\\Users\\Public\\Music                                                                             |
    /// | common_pictures          |                                      |                                      |                                      |                                           | C:\\Users\\Public\\Pictures                                                                          |
    /// | common_videos            |                                      |                                      |                                      |                                           | C:\\Users\\Public\\Videos                                                                            |
    /// | resources                |                                      |                                      |                                      |                                           | C:\\Windows\\resources                                                                               |
    /// | localized_resources      |                                      |                                      |                                      |                                           |                                                                                                      |
    /// | common_oem_links         |                                      |                                      |                                      |                                           |                                                                                                      |
    /// | cd_burning               |                                      |                                      |                                      |                                           | C:\\Users\\${User}\\AppData\\Local\\Microsoft\\Windows\\Burn\\Burn                                   |
    /// | xtd_install **           | /usr/local                           | /usr/local                           | /usr/local                           | /usr/local                                | C:\Program Files\xtd                                                                                 |
    /// | xtd_locale  **           | /usr/local/share/xtd/locale          | /usr/local/share/xtd/locale          | /usr/local/share/xtd/locale          | /usr/local/share/xtd/locale               | C:\Program Files\xtd\locale                                                                          |
    /// | xtd_reference_guide **   | /usr/local/share/xtd/reference_guide | /usr/local/share/xtd/reference_guide | /usr/local/share/xtd/reference_guide | /usr/local/share/xtd/reference_guide      | C:\Program Files\xtd\reference_guide                                                                 |
    /// | xtd_themes **            | /usr/local/share/xtd/themes          | /usr/local/share/xtd/themes          | /usr/local/share/xtd/themes          | /usr/local/share/xtd/themes               | C:\Program Files\xtd\themes                                                                          |
    /// | xtd_include **           | /usr/local/include                   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                        | C:\Program Files\xtd\include                                                                         |
    /// | xtd_libraries **         | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                            | C:\Program Files\xtd\lib                                                                             |
    /// | xtd_resources **         | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources            | C:\Program Files\xtd\resources                                                                       |
    /// | xtd_console_include **   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                        | C:\Program Files\xtd\include                                                                         |
    /// | xtd_console_libraries ** | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                            | C:\Program Files\xtd\lib                                                                             |
    /// | xtd_drawing_include **   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                        | C:\Program Files\xtd\include                                                                         |
    /// | xtd_drawing_libraries ** | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                            | C:\Program Files\xtd\lib                                                                             |
    /// | xtd_drawing_resources ** | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources            | C:\Program Files\xtd\resources                                                                       |
    /// | xtd_forms_include **     | /usr/local/include                   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                        | C:\Program Files\xtd\include                                                                         |
    /// | xtd_forms_libraries **   | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                            | C:\Program Files\xtd\lib                                                                             |
    /// | xtd_forms_resources **   | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources       | /usr/local/share/xtd/resources            | C:\Program Files\xtd\resources                                                                       |
    /// | xtd_tunit_include **     | /usr/local/include                   | /usr/local/include                   | /usr/local/include                   | /usr/local/include                        | C:\Program Files\xtd\include                                                                         |
    /// | xtd_tunit_libraries **   | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                       | /usr/local/lib                            | C:\Program Files\xtd\lib                                                                             |
    /// * ${User} represent the login user name.
    /// ** xtd::environment::special_folder_option has no effect with these values.
    ///
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
      /// @brief The file system directory that contains home folder.
      home = 64,
      /// @brief The installation folder of xtd.
      xtd_install = 1000,
      /// @brief The xtd locale folder.
      xtd_locale = 1001,
      /// @brief The xtd reference guide folder.
      xtd_reference_guide = 1002,
      /// @brief The xtd themes folder.
      xtd_themes = 1003,
      /// @brief The xtd inlude folder.
      xtd_include = 1004,
      /// @brief The xtd libraries folder.
      xtd_libraries = 1005,
      /// @brief The xtd resources folder.
      xtd_resources = 1006,
      /// @brief The xtd::console include folder.
      xtd_console_include = 1007,
      /// @brief The xtd::console libraries folder.
      xtd_console_libraries = 1008,
      /// @brief The xtd::drawing include folder.
      xtd_drawing_include = 1009,
      /// @brief The xtd::drawing libraries folder.
      xtd_drawing_libraries = 1010,
      /// @brief The xtd::drawing resources folder.
      xtd_drawing_resources = 1011,
      /// @brief The xtd::forms include folder.
      xtd_forms_include = 1012,
      /// @brief The xtd::forms libraries folder.
      xtd_forms_libraries = 1013,
      /// @brief The xtd::forms resources folder.
      xtd_forms_resources = 1014,
      /// @brief The xtd::tunit include folder.
      xtd_tunit_include = 1015,
      /// @brief The xtd::tunit libraries folder.
      xtd_tunit_libraries = 1016,
    };
    
    /// @brief Specifies options to use for getting the path to a special folder.
    /// @remarks The xtd::environment::special_folder_option enumeration is used to define the precise behavior of the xtd::environment::get_folder_path method.
    enum class special_folder_option {
      /// @brief The path to the folder is verified. If the folder exists, the path is returned. If the folder does not exist, an empty string is returned. This is the default behavior.
      none = 0,
      /// @brief The path to the folder is returned without verifying whether the path exists. If the folder is located on a network, specifying this option can reduce lag time.
      do_not_verify = 16384,
      /// @brief The path to the folder is created if it does not already exist.
      create = 32768
    };
    
    /// @brief Represents a xtd library that contains name, version and paths.
    class xtd_library final : public xtd::object {
    public:
      /// @cond
      xtd_library() = default;
      xtd_library(const xtd_library&) = default;
      xtd_library& operator =(const xtd_library&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets The inlcude path of the library.
      /// @return A string that represents the include path of the library.
      const xtd::ustring& include_path() const noexcept;
      
      /// @brief Gets The library path of the library.
      /// @return A string that represents the library path of the library.
      const xtd::ustring& library_path() const noexcept;
      
      /// @brief Gets The name of the library.
      /// @return A string that represents the name of the library.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets The resource path of the library.
      /// @return A string that represents the resource path of the library.
      const xtd::ustring& resources_path() const noexcept;
      
      /// @brief Gets The version of the library.
      /// @return An xtd::version object that represents the version of the library.
      const xtd::version& version() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      friend class environment;
      xtd_library(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& include_path, const xtd::ustring& library_path, const xtd::ustring& resources_path);
      xtd::ustring name_;
      xtd::version version_;
      xtd::ustring include_path_;
      xtd::ustring library_path_;
      xtd::ustring resources_path_;
    };
    
    /// @brief Represents a xtd libraries collection.
    using xtd_library_collection = std::vector<xtd_library>;
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the command line for this process.
    /// @return A string containing command-line arguments.
    /// @remarks This method provides access to the program name and any arguments specified on the command line when the current process was started.
    /// @remarks The program name can include path information, but is not required to do so. Use the xtd::environment::get_command_line_args method to retrieve the command-line information parsed and stored in an array of strings.
    /// @remarks The maximum size of the command-line buffer is not set to a specific number of characters; it varies depending on the operating system that is running on the computer.
    static xtd::ustring command_line() noexcept;
    
    /// @brief Gets an xtd::compiler object that contains the current compiler identifier and version number.
    /// @return An object that contains the compiler identifier and version number.
    static xtd::compiler compiler_version() noexcept {
      static auto compiler_id = __compiler_id;
      static auto version = __compiler_version;
      static auto build_type = __build_type;
      static xtd::compiler compiler {compiler_id, version, build_type, sizeof(size_t) == 8};
      return compiler;
    }
    
    /// @brief Gets an xtd::cpp_language object that contains the current c++ standard identifier and version number.
    /// @return An object that contains the c++ standard identifier and version number.
    static xtd::cpp_language cpp_version() noexcept {
      static auto cpp_language = __cpp_language;
      return cpp_language;
    }
    
    /// @brief Gets the fully qualified path of the current working directory.
    /// @return xtd::ustring A string containing a directory path.
    /// @remarks By definition, if this process starts in the root directory of a local or network drive, the value returned by this method is the drive name followed by a trailing slash (for example, "C:\"). If this process starts in a subdirectory, the value returned by this method is the drive and subdirectory path, without a trailing slash (for example, "C:\mySubDirectory").
    /// @exception xtd::not_supported_exception The operating system does not have current directory functionality.
    static xtd::ustring current_directory();
    
    /// @brief Sets the fully qualified path of the current working directory.
    /// @param directory_name A string containing a directory path.
    /// @exception xtd::argument_exception Attempted to set to an empty string ("").
    /// @exception xtd::io::io_exception An I/O error occurred.
    /// @exception xtd::io::directory_not_found_exception Attempted to set a local path that cannot be found.
    /// @exception xtd::security::security_exception The caller does not have the appropriate permission.
    static void current_directory(const xtd::ustring& directory_name);
    
    /// @brief Gets a unique identifier for the current managed thread.
    /// @return An id that represents a unique identifier for this thread.
    static int32 current_managed_thread_id() noexcept;

    /// @brief Gets a unique identifier for the current thread.
    /// @return An id that represents a unique identifier for this thread.
    static intptr current_thread_id() noexcept;

    /// @brief Gets the exit code of the process.
    /// @return A 32-bit signed integer containing the exit code. The default value is 0 (zero), which indicates that the process completed successfully.
    /// @remarks If the main method returns void, you can use this property to set the exit code that will be returned to the calling environment. If Main does not return void, this property is ignored. The initial value of this property is zero.
    /// @warning The xtd::environment::exit_code property is a signed 32-bit integer. To prevent the property from returning a negative exit code, you should not use values greater than or equal to 0x80000000.
    /// @remarks Use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present and a value of 2 to indicate that the file is in the wrong format.
    static int32 exit_code() noexcept;
    /// @brief Sets the exit code of the process.
    /// @param value A 32-bit signed integer containing the exit code. The default value is 0 (zero), which indicates that the process completed successfully.
    /// @remarks If the main method returns void, you can use this property to set the exit code that will be returned to the calling environment. If Main does not return void, this property is ignored. The initial value of this property is zero.
    /// @warning The xtd::environment::exit_code property is a signed 32-bit integer. To prevent the property from returning a negative exit code, you should not use values greater than or equal to 0x80000000.
    /// @remarks Use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present and a value of 2 to indicate that the file is in the wrong format.
    static void exit_code(int32 value) noexcept;
    
    /// @brief Gets a value that indicates whether the current application domain is shutting down.
    /// @return bool true if the current application domain is shutting down; otherwise, false.
    /// @remarks At this time the return value is always false for macOS and linux.
    static bool has_shutdown_started();
    
    /// @brief Determines whether the current operating system is a 64-bit operating system.
    /// @return true if the operating system is 64-bit; otherwise, false.
    static bool is_64_bit_operating_system() noexcept;
    
    /// @brief Determines whether the current process is a 64-bit process.
    /// @return true if the process is 64-bit; otherwise, false.
    static bool is_64_bit_process() noexcept;
    
    /// @brief Gets a copy of the global C++ locale, which is the locale most recently used as the argument to See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::global</a> or a copy of See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::classic()</a> if no call to See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::global</a> has been made.
    /// @return A copy of the global C++ locale.
    /// @remarks See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale</a> for more information.
    static std::locale locale() noexcept;
    
    /// @brief Gets the NetBIOS name of this local computer.
    /// @return A string containing the name of this computer.
    /// @remarks The name of this computer is established at system startup when the name is read from the registry. If this computer is a node in a cluster, the name of the node is returned.
    static xtd::ustring machine_name();
    
    /// @brief Gets the newline string defined for this environment.
    /// @return A string containing "\r\n" for non-Unix platforms, or a string containing "\n" for Unix platforms.
    static xtd::ustring new_line() noexcept;
    
    /// @brief Inserts a new-line character and flushes the stream.
    /// @param os Output stream object affected. Because this function is a manipulator, it is designed to be used alone with no arguments in conjunction with the insertion (<<) operations on output streams (see example below).
    /// @return Argument os.
    template <class char_t, class traits_t>
    static std::basic_ostream<char_t, traits_t>& new_line(std::basic_ostream<char_t, traits_t>& os) {
      for (auto c : new_line())
        os.put(os.widen(c));
      os.flush();
      return os;
    }
    
    /// @brief Gets an xtd::operating_system object that contains the current platform identifier and version number.
    /// @return An object that contains the platform identifier and version number.
    static xtd::operating_system os_version() noexcept;
    
    /// @brief Gets the number of processors on the current machine.
    /// @return The 32-bit unsigned integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors that are available for use.
    static uint32 processor_count();
    
    /// @brief Gets an xtd::processor object that contains the processor identifier.
    /// @return An object that contains the procesor identifier.
    static xtd::processor processor_information();
    
    /// @brief Gets current stack trace information.
    /// @return A string containing stack trace information. This value can be empty "".
    static xtd::ustring stack_trace();
    
    /// @brief Gets the fully qualified path of the system directory.
    /// @return A string containing a directory path.
    /// @remarks An example of the value returned is the string "C:\Windows".
    static xtd::ustring system_directory();
    
    /// @brief Gets the number of bytes in the operating system's memory page.
    /// @return The number of bytes in the system memory page.
    static size_t system_page_size();
    
    /// @brief Gets an xtd::target_type object that contains the current target identifier.
    /// @return An object that contains the target identifier.
    static xtd::target_type target_type() noexcept {
      return xtd::target_type(as<xtd::target_id>(__XTD_CURRENT_TARGET_ID__));
    }
    
    /// @brief Gets the number of milliseconds elapsed since the system started.
    /// @return A 32-bit unsigned integer containing the amount of time in milliseconds that has passed since the last time the computer was started.
    static std::chrono::milliseconds tick_count();
    
    /// @brief Gets the current toolkit version.
    /// @return The current toolkit version.
    static xtd::toolkit toolkit_version();
    
    
    /// @brief Gets a value indicating whether the current user is an administrator.
    /// @return bool true if the current user is an administrator; otherwise, false.
    static bool user_administrator();
    
    /// @brief Gets the network domain name associated with the current user.
    /// @return The network domain name associated with the current user.
    static xtd::ustring user_domain_name();
    
    /// @brief Gets a value indicating whether the current process is running in user interactive mode.
    /// @return bool true if the current process is running in user interactive mode; otherwise, false.
    /// @remarks The user_interactive method reports false for a Os process or a service like IIS that runs without a user interface. If this property is false, do not display modal dialogs or message boxes because there is no graphical user interface for the user to interact with.
    /// @remarks Return always true for now.
    /// @todo check if process is an operating system process or service process...
    static bool user_interactive();
    
    /// @brief Gets the user name of the person who is currently logged on to the operating system.
    /// @return The user name of the person who is logged on to the operating system.
    static xtd::ustring user_name();
    
    /// @brief Gets a version consisting of the major, minor, build, and revision numbers of the xtd framework.
    /// @return The version of the xtd framework.
    static xtd::version version() noexcept;
    
    /// @brief Gets the amount of physical memory mapped to the process context.
    /// @return Int64 A 64-bit signed integer containing the number of bytes of physical memory mapped to the process context.
    /// @remarks Windows 98, Windows Millennium Edition, Linux, macOS, Android,... Platform Note: This property always returns zero.
    /// @par Example
    /// The following example displays the size of the working set of the computer that runs the code example.
    /// @include EnvironmentWorkingSet.cpp
    static int64 working_set();
    
    /// @brief Gets an xtd::environment::xtd_library array that represent the xtd libraries name, version and paths.
    /// @return an xtd::environment::xtd_library array.
    static const xtd_library_collection& xtd_libraries() noexcept;
    /// @}
    
    /// @name Events
    
    /// @{
    /// @brief Occurs when a signal is sent to the current process.
    /// @remarks This event is used in conjunction with xtd::signal_cancel_event_handler and xtd::signal_cancel_event_args. The xtd::environment::cancel_signal event enables a xtd::signal so the event handler can decide whether to continue executing or terminate.
    /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
    /// @warning The xtd::signal::interrupt and xtd::console_special_key::control_c use the same signal (<a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGINT</a>).
    /// @warning The xtd::signal::interrupt and xtd::console_special_key::control_c can be cancelled with xtd::environment::cancel_signal event or xtd::console::cancel_key_press event. Both of these events are called when <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGINT</a> is raised.
    static event<environment, signal_cancel_event_handler> cancel_signal;
    
    /// @brief Occurs when the terminates normally (via xtd::environment::exit or returning from the main function).
    /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
    static event<environment, program_exit_event_handler> program_exit;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Causes abnormal program termination unless xtd::signal::abnormal_termination is being caught by a xtd::environment::cancel_signal event.
    static void abort();
    
    /// @brief Terminates this process and returns an exit code to the operating system.
    /// @remarks Use xtd::environment::exit_code method to return to the operating system.
    [[noreturn]] static void exit();
    /// @brief Terminates this process and returns an exit code to the operating system.
    /// @param exit_code The exit code to return to the operating system. Use 0 (zero) to indicate that the process completed successfully.
    /// @remarks For the exit_code parameter, use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present, and a value of 2 to indicate that the file is in the wrong format.
    [[noreturn]] static void exit(int32 exit_code);
    /// @brief Terminates this process and returns an exit status to the operating system.
    /// @param exit_status One of xtd::exit_status values.
    [[noreturn]] static void exit(xtd::exit_status exit_status);
    
    /// @brief Replaces the name of each environment variable embedded in the specified string with the string equivalent of the value of the variable, then returns the resulting string.
    /// @param name A string containing the names of zero or more environment variables. Each environment variable is quoted with the percent sign character (%).
    /// @return A string with each environment variable replaced by its value.
    /// @remarks Replacement only occurs for environment variables that are set. For example, suppose name is "MyENV = %MyENV%". If the environment variable, MyENV, is set to 42, this method returns "MyENV = 42". If MyENV is not set, no change occurs; this method returns "MyENV = %MyENV%".
    static xtd::ustring expand_environment_variables(const xtd::ustring& name);
    
    /// @brief Returns a string array containing the command-line arguments for the current process.
    /// @return An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
    /// @remarks The first element in the array contains the file name of the executing program. If the file name is not available, the first element is equal to string empty "". The remaining elements contain any additional tokens entered on the command line.
    /// @remarks The program file name can, but is not required to, include path information.
    /// @remarks Command line arguments are delimited by spaces. You can use double quotation marks (") to include spaces within an argument. The single quotation mark ('), however, does not provide this functionality.
    /// @remarks If a double quotation mark follows two or an even number of backslashes, each proceeding backslash pair is replaced with one backslash and the double quotation mark is removed. If a double quotation mark follows an odd number of backslashes, including just one, each preceding pair is replaced with one backslash and the remaining backslash is removed; however, in this case the double quotation mark is not removed.
    /// @remarks The following table shows how command line arguments can be delimited, and assumes MyApp as the current executing application.
    /// | Input at the command line                    | Resulting command line arguments           |
    /// | -------------------------------------------- | ------------------------------------------ |
    /// | MyApp alpha beta                             | MyApp, alpha, beta                         |
    /// | MyApp "alpha with spaces" "beta with spaces" | MyApp, alpha with spaces, beta with spaces |
    /// | MyApp 'alpha with spaces' beta               | MyApp, 'alpha, with, spaces', beta         |
    /// | MyApp \\\alpha \\\\"beta                     | MyApp, \\\alpha, \\beta                    |
    /// | MyApp \\\\\"alpha \"beta                     | MyApp, \\"alpha, "beta                     |
    /// @remarks To obtain the command line as a single string, use the xtd::environment::command_line method.
    static xtd::collections::specialized::string_vector get_command_line_args();
    
    /// @brief Retrieves the value of an environment variable from the current process.
    /// @param variable The name of the environment variable.
    /// @return xtd::ustring The value of the environment variable specified by variable, or empty "" if the environment variable is not found.
    /// @remarks The get_environment_variable(xtd::ustring) method retrieves an environment variable from the environment block of the current process only. It is equivalent to calling the xtd::environment::get_environment_variable(xtd::ustring, xtd::environment_variable_target) method with a target value of xtd::environment_variable_target::process.
    /// @remarks To retrieve all environment variables along with their values, call the xtd::environment::get_environment_variables method.
    /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
    static xtd::ustring get_environment_variable(const xtd::ustring& variable);
    
    /// @brief Retrieves the value of an environment variable from the current process or from the Windows operating system registry key for the current user or local machine.
    /// @param variable The name of an environment variable.
    /// @param target One of the EnvironmentVariableTarget values.
    /// @exception std::invalid_argument target is not a valid environment_variable_target value.
    /// @return xtd::ustring The value of the environment variable specified by the variable and target parameters, or empty "" if the environment variable is not found.
    /// @remarks To retrieve all environment variables along with their values, call the xtd::environment::get_environment_variables method.
    /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
    /// @todo Add xtd::registry and uncomment lines.
    static xtd::ustring get_environment_variable(const xtd::ustring& variable, environment_variable_target target);
    
    /// @brief Retrieves all environment variable names and their values from the current process.
    /// @return std::map A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
    /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned std::map.
    static std::map<std::string, std::string>& get_environment_variables();
    
    /// @brief Retrieves all environment variable names and their values from the current process, or from the Windows operating system registry key for the current user or local machine.
    /// @param target One of the environment_variable_target values.
    /// @return std::map A dictionary that contains all environment variable names and their values from the source specified by the target parameter; otherwise, an empty dictionary if no environment variables are found.
    /// @exception std::invalid_argument target is not a valid environment_variable_target value.
    /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned std::map.
    /// @todo Add xtd::registry and uncomment lines.
    static std::map<std::string, std::string>& get_environment_variables(environment_variable_target target);
    
    /// @brief Gets the path to the system special folder that is identified by the specified enumeration.
    /// @param folder One of enumeration values that identifies a system special folder.
    /// @return The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
    /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    static xtd::ustring get_folder_path(environment::special_folder folder);
    
    /// @brief Gets the path to the system special folder that is identified by the specified enumeration, and uses a specified option for accessing special folders.
    /// @param folder One of the enumeration values that identifies a system special folder.
    /// @param option One of the enumeration values that specifies options to use for accessing a special folder.
    /// @return The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
    /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows.
    static xtd::ustring get_folder_path(environment::special_folder folder, environment::special_folder_option option);
    
    /// @brief Returns an array of string containing the names of the logical drives on the current computer.
    /// @return An array of strings where each element contains the name of a logical drive. For example, if the computer's hard drive is the first logical drive, the first element returned is "C:\".
    static xtd::collections::specialized::string_vector get_logical_drives();

    /// @brief Terminates this process and returns an exit code to the operating system without completely cleaning the resources..
    /// @remarks Use xtd::environment::exit_code method to return to the operating system.
    [[noreturn]] static void quick_exit() noexcept;
    /// @brief Terminates this process and returns an exit code to the operating system without completely cleaning the resources..
    /// @param exit_code The exit code to return to the operating system. Use 0 (zero) to indicate that the process completed successfully.
    /// @remarks For the exit_code parameter, use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present, and a value of 2 to indicate that the file is in the wrong format.
    [[noreturn]] static void quick_exit(int32 exit_code) noexcept;
    /// @brief Terminates this process and returns an exit status to the operating system without completely cleaning the resources..
    /// @param exit_status One of xtd::exit_status values.
    [[noreturn]] static void quick_exit(xtd::exit_status exit_status) noexcept;

    /// @brief Sends xtd::signal to the program. The xtd::environment::cancel_signal event is invoked with the specified signal
    /// @param signal One of xtd::signal values that represents the signal sent to the program.
    static void raise(xtd::signal signal);
    
    /// @brief Creates, modifies, or deletes an environment variable stored in the current process.
    /// @param variable The name of an environment variable.
    /// @param value A value to assign to variable.
    /// @remarks Calling this method is equivalent to calling the xtd::environment::set_environment_variable(xtd::ustring, xtd::ustring, environment_variable_target) overload with a value of xtd::environment_variable_target::process for the target argument.
    /// @remarks If the value argument is not empty and the environment variable named by the variable parameter does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified. Because the environment variable is defined in the environment block of the current process only, it does not persist after the process has ended.
    /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. If variable does not exist, no error occurs even though the operation cannot be performed.
    static void set_environment_variable(const xtd::ustring& variable, const xtd::ustring& value);
    
    /// @brief Creates, modifies, or deletes an environment variable stored in the current process or in the Windows operating system registry key reserved for the current user or local machine.
    /// @param variable The name of an environment variable.
    /// @param value A value to assign to variable.
    /// @remarks The xtd::environment::set_environment_variable(xtd::ustring, xtd::ustring, environment_variable_target) method lets you define an environment variable that is available to the current process (the xtd::environment_variable_target::process value). Environment variables that are unique to the current process environment block persist only until the process ends.
    /// @remarks In addition, on Windows systems only, the xtd::environment::set_environment_variable(xtd::ustring, xtd::ustring, environment_variable_target) method lets you define an environment variable that is available to all processes that run on a machine (the xtd::environment_variable_target::machine value) and to all processes run by a user (the xtd::environment_variable_target::user value). Per-machine and per-user environment variables are copied into the environment block of the current process.
    /// @remarks If the value argument is not empty and the environment variable named by the variable argument does not exist, the environment variable is created and assigned the contents of value. If it does exist, its value is modified.
    /// @remarks If value is empty and the environment variable named by variable exists, the environment variable is deleted. If variable does not exist, no error occurs even though the operation cannot be performed.
    /// @todo Add xtd::registry and uncomment lines.
    static void set_environment_variable(const xtd::ustring& variable, const xtd::ustring& value, environment_variable_target target);
    
    /// @cond
    static void __signal_catcher_check__();
    /// @endcond
    
  private:
    static void on_cancel_signal(signal_cancel_event_args& e);
    static void on_program_exit(const program_exit_event_args& e);

    inline static constexpr const char* xtd_include_path = __XTD_INCLUDE_PATH__;
    inline static constexpr const char* xtd_libraries_path = __XTD_LIB_PATH__;
    inline static constexpr const char* xtd_resources_path = __XTD_RESOURCES_PATH__;
    inline static constexpr const char* xtd_console_include_path = __XTD_CONSOLE_INCLUDE_PATH__;
    inline static constexpr const char* xtd_console_libraries_path = __XTD_CONSOLE_LIB_PATH__;
    inline static constexpr const char* xtd_drawing_include_path = __XTD_DRAWING_INCLUDE_PATH__;
    inline static constexpr const char* xtd_drawing_libraries_path = __XTD_DRAWING_LIB_PATH__;
    inline static constexpr const char* xtd_drawing_resources_path = __XTD_DRAWING_RESOURCES_PATH__;
    inline static constexpr const char* xtd_forms_include_path = __XTD_FORMS_INCLUDE_PATH__;
    inline static constexpr const char* xtd_forms_libraries_path = __XTD_FORMS_LIB_PATH__;
    inline static constexpr const char* xtd_forms_resources_path = __XTD_FORMS_RESOURCES_PATH__;
    inline static constexpr const char* xtd_tunit_include_path = __XTD_TUNIT_INCLUDE_PATH__;
    inline static constexpr const char* xtd_tunit_libraries_path = __XTD_TUNIT_LIB_PATH__;
    static signal_catcher signal_catcher_;
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::environment::special_folder> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::environment::special_folder> {{xtd::environment::special_folder::desktop, "desktop"}, {xtd::environment::special_folder::programs, "programs"}, {xtd::environment::special_folder::my_documents, "my_documents"}, {xtd::environment::special_folder::favorites, "favorites"}, {xtd::environment::special_folder::startup, "startup"}, {xtd::environment::special_folder::recent, "recent"}, {xtd::environment::special_folder::send_to, "send_to"}, {xtd::environment::special_folder::start_menu, "start_menu"}, {xtd::environment::special_folder::my_music, "my_music"}, {xtd::environment::special_folder::my_videos, "my_videos"}, {xtd::environment::special_folder::desktop_directory, "desktop_directory"}, {xtd::environment::special_folder::my_computer, "my_computer"}, {xtd::environment::special_folder::network_shortcuts, "network_shortcuts"}, {xtd::environment::special_folder::fonts, "fonts"}, {xtd::environment::special_folder::templates, "templates"}, {xtd::environment::special_folder::common_start_menu, "common_start_menu"}, {xtd::environment::special_folder::common_programs, "common_programs"}, {xtd::environment::special_folder::common_startup, "common_startup"}, {xtd::environment::special_folder::common_desktop_directory, "common_desktop_directory"}, {xtd::environment::special_folder::application_data, "application_data"}, {xtd::environment::special_folder::printer_shortcuts, "printer_shortcuts"}, {xtd::environment::special_folder::local_application_data, "local_application_data"}, {xtd::environment::special_folder::internet_cache, "internet_cache"}, {xtd::environment::special_folder::cookies, "cookies"}, {xtd::environment::special_folder::history, "history"}, {xtd::environment::special_folder::common_application_data, "common_application_data"}, {xtd::environment::special_folder::windows, "windows"}, {xtd::environment::special_folder::system, "system"}, {xtd::environment::special_folder::program_files, "program_files"}, {xtd::environment::special_folder::my_pictures, "my_pictures"}, {xtd::environment::special_folder::user_profile, "user_profile"}, {xtd::environment::special_folder::system_x86, "system_x86"}, {xtd::environment::special_folder::program_files_x86, "program_files_x86"}, {xtd::environment::special_folder::common_program_files, "common_program_files"}, {xtd::environment::special_folder::common_program_files_x86, "common_program_files_x86"}, {xtd::environment::special_folder::common_templates, "common_templates"}, {xtd::environment::special_folder::common_documents, "common_documents"}, {xtd::environment::special_folder::common_admin_tools, "common_admin_tools"}, {xtd::environment::special_folder::admin_tools, "admin_tools"}, {xtd::environment::special_folder::common_music, "common_music"}, {xtd::environment::special_folder::common_pictures, "common_pictures"}, {xtd::environment::special_folder::common_videos, "common_videos"}, {xtd::environment::special_folder::resources, "resources"}, {xtd::environment::special_folder::localized_resources, "localized_resources"}, {xtd::environment::special_folder::common_oem_links, "common_oem_links"}, {xtd::environment::special_folder::cd_burning, "cd_burning"}, {xtd::environment::special_folder::home, "home"}, {xtd::environment::special_folder::xtd_install, "xtd_install"}, {xtd::environment::special_folder::xtd_locale, "xtd_locale"}, {xtd::environment::special_folder::xtd_reference_guide, "xtd_reference_guide"}, {xtd::environment::special_folder::xtd_themes, "xtd_themes"}, {xtd::environment::special_folder::xtd_include, "xtd_include"}, {xtd::environment::special_folder::xtd_libraries, "xtd_libraries"}, {xtd::environment::special_folder::xtd_resources, "xtd_resources"}, {xtd::environment::special_folder::xtd_console_include, "xtd_console_include"}, {xtd::environment::special_folder::xtd_console_libraries, "xtd_console_libraries"}, {xtd::environment::special_folder::xtd_drawing_include, "xtd_drawing_include"}, {xtd::environment::special_folder::xtd_drawing_libraries, "xtd_drawing_libraries"}, {xtd::environment::special_folder::xtd_drawing_resources, "xtd_drawing_resources"}, {xtd::environment::special_folder::xtd_forms_include, "xtd_forms_include"}, {xtd::environment::special_folder::xtd_forms_libraries, "xtd_forms_libraries"}, {xtd::environment::special_folder::xtd_forms_resources, "xtd_forms_resources"}, {xtd::environment::special_folder::xtd_tunit_include, "xtd_tunit_include"}, {xtd::environment::special_folder::xtd_tunit_libraries, "xtd_tunit_libraries"}};}
};

template<> struct xtd::enum_register<xtd::environment::special_folder_option> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::environment::special_folder_option> {{xtd::environment::special_folder_option::none, "none"}, {xtd::environment::special_folder_option::do_not_verify, "do_not_verify"}, {xtd::environment::special_folder_option::create, "create"}};}
};
/// @endcond
