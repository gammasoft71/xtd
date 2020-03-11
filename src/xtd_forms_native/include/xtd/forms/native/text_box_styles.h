#pragma once
#include <cstddef>

#ifndef ES_LEFT
constexpr size_t ES_LEFT = 0x0000L;
constexpr size_t ES_CENTER = 0x0001L;
constexpr size_t ES_RIGHT = 0x0002L;
constexpr size_t ES_MULTILINE = 0x0004L;
constexpr size_t ES_UPPERCASE = 0x0008L;
constexpr size_t ES_LOWERCASE = 0x0010L;
constexpr size_t ES_PASSWORD = 0x0020L;
constexpr size_t ES_AUTOVSCROLL = 0x0040L;
constexpr size_t ES_AUTOHSCROLL = 0x0080L;
constexpr size_t ES_NOHIDESEL = 0x0100L;
constexpr size_t ES_OEMCONVERT = 0x0400L;
constexpr size_t ES_READONLY = 0x0800L;
constexpr size_t ES_WANTRETURN = 0x1000L;
constexpr size_t ES_NUMBER = 0x2000L;
#endif
