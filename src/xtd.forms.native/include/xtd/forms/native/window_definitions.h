/// @file
/// @brief Contains few windows definitions types and methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../window_messages.h"

#if !defined(HFILE_ERROR)
struct HWND__ {};
typedef struct HWND__* HWND;

struct NMHDR {
  HWND hwndFrom;
  xtd::uintptr idFrom;
  xtd::uint32 code;
};

struct POINT {
  xtd::int32 x;
  xtd::int32 y;
};

struct HELPINFO {
  xtd::uint32 cbSize;
  xtd::int32 iContextType;
  xtd::int32 iCtrlId;
  HWND hItemHandle;
  xtd::uintptr dwContextId;
  POINT MousePos;
};

template<typename type1_t, typename type2_t>
xtd::uint16 MAKEWORD(type1_t a, type2_t b) {
  return static_cast<xtd::uint16>((static_cast<xtd::uint16>((static_cast<xtd::uint32>(a)) & 0xff)) | (static_cast<xtd::uint16>(static_cast<xtd::uint16>((static_cast<xtd::uint32>(b)) & 0xff))) << 8);
}

template<typename type1_t, typename type2_t>
xtd::uint32 MAKELONG(type1_t a, type2_t b) {
  return static_cast<xtd::uint32>((static_cast<xtd::uint16>((static_cast<xtd::uint32>(a)) & 0xffff)) | (static_cast<xtd::uint32>(static_cast<xtd::uint16>((static_cast<xtd::uint32>(b)) & 0xffff))) << 16);
}

template<typename type_t>
inline xtd::uint16 LOWORD(type_t value) {
  return static_cast<xtd::uint16>(static_cast<xtd::uint32>(value) & 0xFFFF);
}

template<typename type_t>
inline xtd::uint16 HIWORD(type_t value) {
  return static_cast<xtd::uint16>((static_cast<xtd::uint32>(value) >> 16) & 0xFFFF);
}

template<typename type_t>
inline xtd::uint16 LOBYTE(type_t value) {
  return static_cast<xtd::byte>(static_cast<xtd::uint32>(value) & 0xFF);
}

template<typename type_t>
inline xtd::byte HIBYTE(type_t value) {
  return static_cast<xtd::byte>((static_cast<xtd::uint32>(value) >> 8) & 0xFF);
}
#endif
