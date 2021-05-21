
/// @file
/// @brief Contains constant special item ID list.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal used only"
#endif
/// @endcond

#include <cstdint>

#if !defined (CSIDL_DESKTOP)
/// @brief The logical Desktop rather than the physical file system location.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_DESKTOP = 0x0000;
/// @brief The directory that contains the Internet Explorer (icon on desktop).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_INTERNET = 0x0001;
/// @brief The directory that contains the user's program groups.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROGRAMS = 0x0002;
/// @brief The directory that contains "My Computer\Control Panel".
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_CONTROLS = 0x0003;
/// @brief The directory that contains "My Computer\Printers".
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PRINTERS = 0x0004;
/// @brief The directory that serves as a common repository for documents. This member is equivalent to MyDocuments.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PERSONAL = 0x0005;
/// @brief The directory that serves as a common repository for the user's favorite items.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_FAVORITES = 0x0006;
/// @brief The directory that corresponds to the user's Startup program group. The system starts these programs whenever a user logs on or starts Windows NT or later, or starts Windows 98.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_STARTUP = 0x0007;
/// @brief The directory that contains the user's most recently used documents.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_RECENT = 0x0008;
/// @brief The directory that contains the Send To menu items.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_SENDTO = 0x0009;
/// @brief The directory that contains the Recycle bin.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_BITBUCKET = 0x000a;
/// @brief The directory that contains the Start menu items.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_STARTMENU = 0x000b;
/// @brief The My Documents folder. This member is equivalent to Personal.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_MYDOCUMENTS = CSIDL_PERSONAL;
/// @brief The My Music folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_MYMUSIC = 0x000d;
/// @brief The file system directory that serves as a repository for videos that belong to a user.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_MYVIDEO = 0x000e;
/// @brief The directory used to physically store file objects on the desktop. Do not confuse this directory with the desktop folder itself, which is a virtual folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_DESKTOPDIRECTORY = 0x0010;
/// @brief The My Computer folder. The MyComputer constant always yields the empty string ("") because no path is defined for the My Computer folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_DRIVES = 0x0011;
/// @brief A file system directory that contains Network Neighborhood (My Network Places).
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_NETWORK = 0x0012;
/// @brief A file system directory that contains the link objects that may exist in the My Network Places virtual folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_NETHOOD = 0x0013;
/// @brief A virtual folder that contains fonts.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_FONTS = 0x0014;
/// @brief The directory that serves as a common repository for document templates.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_TEMPLATES = 0x0015;
/// @brief The file system directory that contains the programs and folders that appear on the Start menu for all users. This special folder is valid only for Windows NT systems.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_STARTMENU = 0x0016;
/// @brief A folder for components that are shared across applications. This special folder is valid only for Windows NT, Windows 2000, and Windows XP systems.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_PROGRAMS = 0X0017;
/// @brief The file system directory that contains the programs that appear in the Startup folder for all users. This special folder is valid only for Windows NT systems.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_STARTUP = 0x0018;
/// @brief The file system directory that contains files and folders that appear on the desktop for all users. This special folder is valid only for Windows NT systems.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_DESKTOPDIRECTORY = 0x0019;
/// @brief The directory that serves as a common repository for application-specific data for the current roaming user. A roaming user works on more than one computer on a network. A roaming user's profile is kept on a server on the network and is loaded onto a system when the user logs on.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_APPDATA = 0x001a;
/// @brief The file system directory that contains the link objects that can exist in the Printers virtual folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PRINTHOOD = 0x001b;
/// @brief The directory that serves as a common repository for application-specific data that is used by the current, non-roaming user.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_LOCAL_APPDATA = 0x001c;
/// @brief The file system directory that contains non localized startup
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_ALTSTARTUP = 0x001d;
/// @brief The file system directory that contains non localized common startup
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_ALTSTARTUP = 0x001e;
/// @brief The file system directory that contains common favorites
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_FAVORITES = 0x001f;
/// @brief The directory that serves as a common repository for temporary Internet files.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_INTERNET_CACHE = 0x0020;
/// @brief The directory that serves as a common repository for Internet cookies.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COOKIES = 0x0021;
/// @brief The directory that serves as a common repository for Internet history items.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_HISTORY = 0x0022;
/// @brief The directory that serves as a common repository for application-specific data that is used by all users.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_APPDATA = 0x0023;
/// @brief The Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT% environment variables.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_WINDOWS = 0x0024;
/// @brief The System directory.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_SYSTEM = 0x0025;
/// @brief The program files directory.On a non-x86 system, passing ProgramFiles to the GetFolderPath method returns the path for non-x86 programs. To get the x86 program files directory on a non-x86 system, use the ProgramFilesX86 member.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROGRAM_FILES = 0x0026;
/// @brief The My Pictures folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_MYPICTURES = 0x0027;
/// @brief The user's profile folder. Applications should not create files or folders at this level; they should put their data under the locations referred to by ApplicationData.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROFILE = 0x0028;
/// @brief The Windows System folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_SYSTEMX86 = 0x0029;
/// @brief The Program Files folder On an x86 system, passing the ProgramFilesX86 member to the Environment.GetFolderPath method returns string.Empty; use the ProgramFiles member instead. You can determine whether Windows is a 32-bit operating system by calling the Environment.Is64BitOperatingSystem property.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROGRAM_FILESX86 = 0x002a;
/// @brief The directory for components that are shared across applications.To get the x86 common program files directory on a non-x86 system, use the ProgramFilesX86 member.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROGRAM_FILES_COMMON = 0x002b;
/// @brief The Program Files folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_PROGRAM_FILES_COMMONX86 = 0x002c;
/// @brief The file system directory that contains the templates that are available to all users. This special folder is valid only for Windows NT systems.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_TEMPLATES = 0x002d;
/// @brief The file system directory that contains documents that are common to all users. This special folder is valid for Windows NT systems, Windows 95, and Windows 98 systems with Shfolder.dll installed.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_DOCUMENTS = 0x002e;
/// @brief The file system directory that contains administrative tools for all users of the computer.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_ADMINTOOLS = 0x002f;
/// @brief The file system directory that is used to store administrative tools for an individual user. The Microsoft Management Console (MMC) will save customized consoles to this directory, and it will roam with the user.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_ADMINTOOLS = 0x0030;
/// @brief The file system directory that contains Network and Dial-up Connections.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_CONNECTIONS = 0x0031;
/// @brief The file system directory that serves as a repository for music files common to all users.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_MUSIC = 0x0035;
/// @brief The file system directory that serves as a repository for image files common to all users.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_PICTURES = 0x0036;
/// @brief The file system directory that serves as a repository for video files common to all users.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_VIDEO = 0x0037;
/// @brief The file system directory that contains resource data.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_RESOURCES = 0x0038;
/// @brief The file system directory that contains localized resource data.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_RESOURCES_LOCALIZED = 0x0039;
/// @brief This value is recognized in Windows Vista for backward compatibility, but the special folder itself is no longer used.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMMON_OEM_LINKS = 0x003a;
/// @brief The file system directory that acts as a staging area for files waiting to be written to a CD.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_CDBURN_AREA = 0x003b;

// unused 0x003c

/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks /// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t CSIDL_COMPUTERSNEARME = 0x003d;
#endif
/// @brief The file system directory that contains home folder.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native csidl
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t CSIDL_HOME = 0x0040;
