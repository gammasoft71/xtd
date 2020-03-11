#pragma once

#include <cstdint>

#if !defined(CF_SCREENFONTS)
constexpr size_t CF_SCREENFONTS = 0x00000001;
constexpr size_t CF_PRINTERFONTS = 0x00000002;
constexpr size_t CF_BOTH = (CF_SCREENFONTS | CF_PRINTERFONTS);
constexpr size_t CF_SHOWHELP = 0x00000004L;
constexpr size_t CF_ENABLEHOOK = 0x00000008L;
constexpr size_t CF_ENABLETEMPLATE = 0x00000010L;
constexpr size_t CF_ENABLETEMPLATEHANDLE = 0x00000020L;
constexpr size_t CF_INITTOLOGFONTSTRUCT = 0x00000040L;
constexpr size_t CF_USESTYLE = 0x00000080L;
constexpr size_t CF_EFFECTS = 0x00000100L;
constexpr size_t CF_APPLY = 0x00000200L;
constexpr size_t CF_ANSIONLY = 0x00000400L;
constexpr size_t CF_SCRIPTSONLY = CF_ANSIONLY;
constexpr size_t CF_NOVECTORFONTS = 0x00000800L;
constexpr size_t CF_NOOEMFONTS = CF_NOVECTORFONTS;
constexpr size_t CF_NOSIMULATIONS = 0x00001000L;
constexpr size_t CF_LIMITSIZE = 0x00002000L;
constexpr size_t CF_FIXEDPITCHONLY = 0x00004000L;
constexpr size_t CF_WYSIWYG = 0x00008000L; // must also have CF_SCREENFONTS & CF_PRINTERFONTS
constexpr size_t CF_FORCEFONTEXIST = 0x00010000L;
constexpr size_t CF_SCALABLEONLY = 0x00020000L;
constexpr size_t CF_TTONLY = 0x00040000L;
constexpr size_t CF_NOFACESEL = 0x00080000L;
constexpr size_t CF_NOSTYLESEL = 0x00100000L;
constexpr size_t CF_NOSIZESEL = 0x00200000L;
constexpr size_t CF_SELECTSCRIPT = 0x00400000L;
constexpr size_t CF_NOSCRIPTSEL = 0x00800000L;
constexpr size_t CF_NOVERTFONTS = 0x01000000L;
constexpr size_t CF_INACTIVEFONTS = 0x02000000L;
#endif
