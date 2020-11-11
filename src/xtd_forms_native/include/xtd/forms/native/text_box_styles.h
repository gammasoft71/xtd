#pragma once
#include <cstddef>

#ifndef ES_LEFT
constexpr size_t ES_LEFT = 0x00000000L;
constexpr size_t ES_CENTER = 0x00000001L;
constexpr size_t ES_RIGHT = 0x00000002L;
constexpr size_t ES_MULTILINE = 0x00000004L;
constexpr size_t ES_UPPERCASE = 0x00000008L;
constexpr size_t ES_LOWERCASE = 0x00000010L;
constexpr size_t ES_PASSWORD = 0x00000020L;
constexpr size_t ES_AUTOVSCROLL = 0x00000040L;
constexpr size_t ES_AUTOHSCROLL = 0x00000080L;
constexpr size_t ES_NOHIDESEL = 0x00000100L;
constexpr size_t ES_OEMCONVERT = 0x00000400L;
constexpr size_t ES_READONLY = 0x00000800L;
constexpr size_t ES_WANTRETURN = 0x00001000L;
constexpr size_t ES_NUMBER = 0x00002000L;
#endif
constexpr size_t ES_WANTTAB = 0x00004000L;
