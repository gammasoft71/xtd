#pragma once

#include <cstdint>

#if !defined(BIF_RETURNONLYFSDIRS)
constexpr size_t BIF_RETURNONLYFSDIRS = 0x00000001; // For finding a folder to start document searching
constexpr size_t BIF_DONTGOBELOWDOMAIN = 0x00000002; // For starting the Find Computer
constexpr size_t BIF_STATUSTEXT = 0x00000004; // Top of the dialog has 2 lines of text for BROWSEINFO.lpszTitle and one line if this flag is set.  Passing the message BFFM_SETSTATUSTEXTA to the hwnd can set the rest of the text.  This is not used with BIF_USENEWUI and BROWSEINFO.lpszTitle gets all three lines of text.
constexpr size_t BIF_RETURNFSANCESTORS = 0x00000008;
constexpr size_t BIF_EDITBOX = 0x00000010; // Add an editbox to the dialog
constexpr size_t BIF_VALIDATE = 0x00000020; // insist on valid result (or CANCEL)

constexpr size_t BIF_NEWDIALOGSTYLE = 0x00000040; // Use the new dialog layout with the ability to resize Caller needs to call OleInitialize() before using this API

constexpr size_t BIF_USENEWUI = (BIF_NEWDIALOGSTYLE | BIF_EDITBOX);

constexpr size_t BIF_BROWSEINCLUDEURLS = 0x00000080; // Allow URLs to be displayed or entered. (Requires BIF_USENEWUI)
constexpr size_t BIF_UAHINT = 0x00000100; // Add a UA hint to the dialog, in place of the edit box. May not be combined with BIF_EDITBOX
constexpr size_t BIF_NONEWFOLDERBUTTON = 0x00000200; // Do not add the "New Folder" button to the dialog.  Only applicable with BIF_NEWDIALOGSTYLE.
constexpr size_t BIF_NOTRANSLATETARGETS = 0x00000400; // don't traverse target as shortcut

constexpr size_t BIF_BROWSEFORCOMPUTER = 0x00001000; // Browsing for Computers.
constexpr size_t BIF_BROWSEFORPRINTER = 0x00002000; // Browsing for Printers
constexpr size_t BIF_BROWSEINCLUDEFILES = 0x00004000; // Browsing for Everything
constexpr size_t BIF_SHAREABLE = 0x00008000; // sharable resources displayed (remote shares, requires BIF_USENEWUI)
constexpr size_t BIF_BROWSEFILEJUNCTIONS = 0x00010000; // allow folder junctions like zip files and libraries to be browsed
#endif
