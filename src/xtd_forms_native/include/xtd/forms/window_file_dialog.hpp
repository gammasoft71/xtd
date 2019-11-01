#pragma once

#include <cstdint>

#if !defined(OFN_READONLY)
constexpr size_t OFN_READONLY = 0x00000001;
constexpr size_t OFN_OVERWRITEPROMPT = 0x00000002;
constexpr size_t OFN_HIDEREADONLY = 0x00000004;
constexpr size_t OFN_NOCHANGEDIR = 0x00000008;
constexpr size_t OFN_SHOWHELP = 0x00000010;
constexpr size_t OFN_ENABLEHOOK = 0x00000020;
constexpr size_t OFN_ENABLETEMPLATE = 0x00000040;
constexpr size_t OFN_ENABLETEMPLATEHANDLE = 0x00000080;
constexpr size_t OFN_NOVALIDATE = 0x00000100;
constexpr size_t OFN_ALLOWMULTISELECT = 0x00000200;
constexpr size_t OFN_EXTENSIONDIFFERENT = 0x00000400;
constexpr size_t OFN_PATHMUSTEXIST = 0x00000800;
constexpr size_t OFN_FILEMUSTEXIST = 0x00001000;
constexpr size_t OFN_CREATEPROMPT = 0x00002000;
constexpr size_t OFN_SHAREAWARE = 0x00004000;
constexpr size_t OFN_NOREADONLYRETURN = 0x00008000;
constexpr size_t OFN_NOTESTFILECREATE = 0x00010000;
constexpr size_t OFN_NONETWORKBUTTON = 0x00020000;
constexpr size_t OFN_NOLONGNAMES = 0x00040000;
constexpr size_t OFN_EXPLORER = 0x00080000;
constexpr size_t OFN_NODEREFERENCELINKS = 0x00100000;
constexpr size_t OFN_LONGNAMES = 0x00200000;
constexpr size_t OFN_ENABLEINCLUDENOTIFY = 0x00400000;
constexpr size_t OFN_ENABLESIZING = 0x00800000;
constexpr size_t OFN_DONTADDTORECENT = 0x02000000;
constexpr size_t OFN_FORCESHOWHIDDEN = 0x10000000;
#endif
constexpr size_t OFN_SHOWPREVIEW = 0x40000000;
constexpr size_t OFN_ADDEXTENSION = 0x80000000;
