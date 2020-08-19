#pragma once
#include <cstddef>

#ifndef BST_UNCHECKED
constexpr size_t BS_PUSHBUTTON = 0x00000000;
constexpr size_t BS_DEFPUSHBUTTON = 0x00000001;
constexpr size_t BS_CHECKBOX = 0x00000002;
constexpr size_t BS_AUTOCHECKBOX = 0x00000003;
constexpr size_t BS_RADIOBUTTON = 0x00000004;
constexpr size_t BS_3STATE = 0x00000005;
constexpr size_t BS_AUTO3STATE = 0x00000006;
constexpr size_t BS_GROUPBOX = 0x00000007;
constexpr size_t BS_USERBUTTON = 0x00000008;
constexpr size_t BS_AUTORADIOBUTTON = 0x00000009;
constexpr size_t BS_PUSHBOX = 0x0000000A;
constexpr size_t BS_OWNERDRAW = 0x0000000B;
constexpr size_t BS_TYPEMASK = 0x0000000F;
constexpr size_t BS_LEFTTEXT = 0x00000020;
constexpr size_t BS_TEXT = 0x00000000;
constexpr size_t BS_ICON = 0x00000040;
constexpr size_t BS_BITMAP = 0x00000080;
constexpr size_t BS_LEFT = 0x00000100;
constexpr size_t BS_RIGHT = 0x00000200;
constexpr size_t BS_CENTER = 0x00000300;
constexpr size_t BS_TOP = 0x00000400;
constexpr size_t BS_BOTTOM = 0x00000800;
constexpr size_t BS_VCENTER = 0x00000C00;
constexpr size_t BS_PUSHLIKE = 0x00001000;
constexpr size_t BS_MULTILINE = 0x00002000;
constexpr size_t BS_NOTIFY = 0x00004000;
constexpr size_t BS_FLAT = 0x00008000;
constexpr size_t BS_RIGHTBUTTON = BS_LEFTTEXT;

constexpr size_t BS_SPLITBUTTON = 0x0000000C;
constexpr size_t BS_DEFSPLITBUTTON = 0x0000000D;
constexpr size_t BS_COMMANDLINK = 0x0000000E;
constexpr size_t BS_DEFCOMMANDLINK = 0x0000000F;
#endif

#ifndef BST_UNCHECKED
constexpr size_t BST_UNCHECKED = 0x0000;
constexpr size_t BST_CHECKED = 0x0001;
constexpr size_t BST_INDETERMINATE = 0x0002;
constexpr size_t BST_PUSHED = 0x0004;
constexpr size_t BST_FOCUS = 0x0008;

constexpr size_t BST_DROPDOWNPUSHED = 0x0400;
#endif
