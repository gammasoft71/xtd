/// @file
/// @brief Contains folder browser dialog flags constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

#if !defined(BIF_RETURNONLYFSDIRS)
/// @brief Only return file system directories. If the user selects folders that are not part of the file system, the OK button is grayed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_RETURNONLYFSDIRS = 0x00000001;
/// @brief Do not include network folders below the domain level in the dialog box's tree view control.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_DONTGOBELOWDOMAIN = 0x00000002;
/// @brief Include a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box. This flag is not supported when BIF_NEWDIALOGSTYLE is specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_STATUSTEXT = 0x00000004;
/// @brief Include a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box. This flag is not supported when BIF_NEWDIALOGSTYLE is specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_RETURNFSANCESTORS = 0x00000008;
/// @brief Include an edit control in the browse dialog box that allows the user to type the name of an item.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_EDITBOX = 0x00000010;
/// @brief If the user types an invalid name into the edit box, the browse dialog box calls the application's BrowseCallbackProc with the BFFM_VALIDATEFAILED message. This flag is ignored if BIF_EDITBOX is not specified.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_VALIDATE = 0x00000020;

/// @brief Use the new user interface. Setting this flag provides the user with a larger dialog box that can be resized. The dialog box has several new capabilities, including: drag-and-drop capability within the dialog box, reordering, shortcut menus, new folders, delete, and other shortcut menu commands.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_NEWDIALOGSTYLE = 0x00000040;

/// @brief Use the new user interface, including an edit box. This flag is equivalent to BIF_EDITBOX | BIF_NEWDIALOGSTYLE.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_USENEWUI = (BIF_NEWDIALOGSTYLE | BIF_EDITBOX);

/// @brief The browse dialog box can display URLs. The BIF_USENEWUI and BIF_BROWSEINCLUDEFILES flags must also be set. If any of these three flags are not set, the browser dialog box rejects URLs. Even when these flags are set, the browse dialog box displays URLs only if the folder that contains the selected item supports URLs. When the folder's IShellFolder::GetAttributesOf method is called to request the selected item's attributes, the folder must set the SFGAO_FOLDER attribute flag. Otherwise, the browse dialog box will not display the URL.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_BROWSEINCLUDEURLS = 0x00000080;
/// @brief When combined with BIF_NEWDIALOGSTYLE, adds a usage hint to the dialog box, in place of the edit box. BIF_EDITBOX overrides this flag.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_UAHINT = 0x00000100;
/// @brief Do not include the New Folder button in the browse dialog box.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_NONEWFOLDERBUTTON = 0x00000200;
/// @brief When the selected item is a shortcut, return the PIDL of the shortcut itself rather than its target.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_NOTRANSLATETARGETS = 0x00000400;

/// @brief Only return computers. If the user selects anything other than a computer, the OK button is grayed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_BROWSEFORCOMPUTER = 0x00001000;
/// @brief Only allow the selection of printers. If the user selects anything other than a printer, the OK button is grayed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_BROWSEFORPRINTER = 0x00002000;
/// @brief The browse dialog box displays files as well as folders.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_BROWSEINCLUDEFILES = 0x00004000;
/// @brief The browse dialog box can display sharable resources on remote systems. This is intended for applications that want to expose remote shares on a local system. The BIF_NEWDIALOGSTYLE flag must also be set.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_SHAREABLE = 0x00008000;
/// @brief Allow folder junctions such as a library or a compressed file with a .zip file name extension to be browsed.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native bif
/// @warning Internal use only
constexpr size_t BIF_BROWSEFILEJUNCTIONS = 0x00010000;
#endif
