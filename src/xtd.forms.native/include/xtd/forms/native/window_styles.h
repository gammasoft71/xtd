#pragma once
#include <cstddef>

#ifndef WS_OVERLAPPED
constexpr size_t WS_OVERLAPPED = 0x00000000;
constexpr size_t WS_MAXIMIZEBOX = 0x00010000;
constexpr size_t WS_MINIMIZEBOX = 0x00020000;
constexpr size_t WS_THICKFRAME = 0x00040000;
constexpr size_t WS_SYSMENU = 0x00080000;
constexpr size_t WS_HSCROLL = 0x00100000;
constexpr size_t WS_VSCROLL = 0x00200000;
constexpr size_t WS_DLGFRAME = 0x00400000;
constexpr size_t WS_BORDER = 0x00800000;
constexpr size_t WS_CAPTION = 0x00C00000; // WS_BORDER|WS_DLGFRAME
constexpr size_t WS_MAXIMIZE = 0x01000000;
constexpr size_t WS_CLIPCHILDREN = 0x02000000;
constexpr size_t WS_CLIPSIBLINGS = 0x04000000;
constexpr size_t WS_DISABLED = 0x08000000;
constexpr size_t WS_VISIBLE = 0x10000000;
constexpr size_t WS_MINIMIZE = 0x20000000;
constexpr size_t WS_CHILD = 0x40000000;
constexpr size_t WS_POPUP = 0x80000000;

constexpr size_t WS_GROUP = 0x00020000;
constexpr size_t WS_TABSTOP = 0x00010000;

// Common Window Styles
constexpr size_t WS_OVERLAPPEDWINDOW = WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX;
constexpr size_t WS_POPUPWINDOW = WS_POPUP|WS_BORDER|WS_SYSMENU;
constexpr size_t WS_CHILDWINDOW = WS_CHILD;

// Window Styles (next...)
constexpr size_t WS_TILED = WS_OVERLAPPED;
constexpr size_t WS_ICONIC = WS_MINIMIZE;
constexpr size_t WS_SIZEBOX = WS_THICKFRAME;
constexpr size_t WS_TILEDWINDOW = WS_OVERLAPPEDWINDOW;

// Extended Window Styles
constexpr size_t WS_EX_DLGMODALFRAME = 0x00000001;
constexpr size_t WS_EX_NOPARENTNOTIFY = 0x00000004;
constexpr size_t WS_EX_TOPMOST = 0x00000008;
constexpr size_t WS_EX_ACCEPTFILES = 0x00000010;
constexpr size_t WS_EX_TRANSPARENT = 0x00000020;
constexpr size_t WS_EX_MDICHILD = 0x00000040;
constexpr size_t WS_EX_TOOLWINDOW = 0x00000080;
constexpr size_t WS_EX_WINDOWEDGE = 0x00000100;
constexpr size_t WS_EX_CLIENTEDGE = 0x00000200;
constexpr size_t WS_EX_CONTEXTHELP = 0x00000400;
constexpr size_t WS_EX_RIGHT = 0x00001000;
constexpr size_t WS_EX_LEFT = 0x00000000;
constexpr size_t WS_EX_RTLREADING = 0x00002000;
constexpr size_t WS_EX_LTRREADING = 0x00000000;
constexpr size_t WS_EX_LEFTSCROLLBAR = 0x00004000;
constexpr size_t WS_EX_RIGHTSCROLLBAR = 0x00000000;

constexpr size_t WS_EX_CONTROLPARENT = 0x00010000;
constexpr size_t WS_EX_STATICEDGE = 0x00020000;
constexpr size_t WS_EX_APPWINDOW = 0x00040000;


constexpr size_t WS_EX_OVERLAPPEDWINDOW = WS_EX_WINDOWEDGE|WS_EX_CLIENTEDGE;
constexpr size_t WS_EX_PALETTEWINDOW = WS_EX_WINDOWEDGE|WS_EX_TOOLWINDOW|WS_EX_TOPMOST;

constexpr size_t WS_EX_LAYERED = 0x00080000;

constexpr size_t WS_EX_NOINHERITLAYOUT = 0x00100000; // Disable inheritence of mirroring by children

constexpr size_t WS_EX_NOREDIRECTIONBITMAP = 0x00200000;

constexpr size_t WS_EX_LAYOUTRTL = 0x00400000; // Right to left mirroring

constexpr size_t WS_EX_COMPOSITED = 0x02000000;
constexpr size_t WS_EX_NOACTIVATE = 0x08000000;
#endif
constexpr size_t WS_EX_AUTOSCROLL = 0x40000000;
constexpr size_t WS_EX_MODALWINDOW = 0x80000000;
