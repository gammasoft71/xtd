/// @file
/// @brief Contains few windows definitions types and methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../window_messages.hpp"

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

[[nodiscard]] auto MAKEWORD(auto a, auto b) -> xtd::uint16 {
  return static_cast<xtd::uint16>((static_cast<xtd::uint16>((static_cast<xtd::uint32>(a)) & 0xff)) | (static_cast<xtd::uint16>(static_cast <xtd::uint16>((static_cast<xtd::uint32>(b)) & 0xff))) << 8);
}

[[nodiscard]] auto MAKELONG(auto a, auto b) -> xtd::uint32 {
  return static_cast<xtd::uint32>((static_cast<xtd::uint16>((static_cast<xtd::uint32>(a)) & 0xffff)) | (static_cast<xtd::uint32>(static_cast<xtd::uint16>((static_cast<xtd::uint32>(b)) & 0xffff))) << 16);
}

[[nodiscard]] inline auto LOWORD(auto value) -> xtd::uint16 {
  return static_cast<xtd::uint16>(static_cast<xtd::uint32>(value) & 0xFFFF);
}

[[nodiscard]] inline auto HIWORD(auto value) -> xtd::uint16 {
  return static_cast<xtd::uint16>((static_cast<xtd::uint32>(value) >> 16) & 0xFFFF);
}

[[nodiscard]] inline auto LOBYTE(auto value) -> xtd::uint16 {
  return static_cast<xtd::byte>(static_cast<xtd::uint32>(value) & 0xFF);
}

[[nodiscard]] inline auto HIBYTE(auto value) -> xtd::byte {
  return static_cast<xtd::byte>((static_cast<xtd::uint32>(value) >> 8) & 0xFF);
}
#endif
