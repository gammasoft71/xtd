#pragma once
#include <cstddef>

#ifndef SS_LEFT
constexpr size_t SS_LEFT = 0x00000000;
constexpr size_t SS_CENTER = 0x00000001;
constexpr size_t SS_RIGHT = 0x00000002;
constexpr size_t SS_ICON = 0x00000003;
constexpr size_t SS_BLACKRECT = 0x00000004;
constexpr size_t SS_GRAYRECT = 0x00000005;
constexpr size_t SS_WHITERECT = 0x00000006;
constexpr size_t SS_BLACKFRAME = 0x00000007;
constexpr size_t SS_GRAYFRAME = 0x00000008;
constexpr size_t SS_WHITEFRAME = 0x00000009;
constexpr size_t SS_USERITEM = 0x0000000A;
constexpr size_t SS_SIMPLE = 0x0000000B;
constexpr size_t SS_LEFTNOWORDWRAP = 0x0000000C;
constexpr size_t SS_OWNERDRAW = 0x0000000D;
constexpr size_t SS_BITMAP = 0x0000000E;
constexpr size_t SS_ENHMETAFILE = 0x0000000F;
constexpr size_t SS_ETCHEDHORZ = 0x00000010;
constexpr size_t SS_ETCHEDVERT = 0x00000011;
constexpr size_t SS_ETCHEDFRAME = 0x00000012;
constexpr size_t SS_TYPEMASK = 0x0000001F;
constexpr size_t SS_REALSIZECONTROL = 0x00000040;
constexpr size_t SS_NOPREFIX = 0x00000080; // Don't do "&" character translation
constexpr size_t SS_NOTIFY = 0x00000100;
constexpr size_t SS_CENTERIMAGE = 0x00000200;
constexpr size_t SS_RIGHTJUST = 0x00000400;
constexpr size_t SS_REALSIZEIMAGE = 0x00000800;
constexpr size_t SS_SUNKEN = 0x00001000;
constexpr size_t SS_EDITCONTROL = 0x00002000;
constexpr size_t SS_ENDELLIPSIS = 0x00004000;
constexpr size_t SS_PATHELLIPSIS = 0x00008000;
constexpr size_t SS_WORDELLIPSIS = 0x0000C000;
constexpr size_t SS_ELLIPSISMASK = 0x0000C000;
#endif
constexpr size_t SS_TOP = 0x00000000;
constexpr size_t SS_VCENTER = 0x00010000;
constexpr size_t SS_BOTTOM = 0x00020000;
constexpr size_t SS_BITMAP_NORMAL = 0x00000000;
constexpr size_t SS_BITMAP_STRETCH = 0x00040000;
constexpr size_t SS_BITMAP_AUTOSIZE = 0x00080000;
constexpr size_t SS_BITMAP_CENTER = 0x000C0000;
constexpr size_t SS_BITMAP_ZOOM = 0x00100000;
