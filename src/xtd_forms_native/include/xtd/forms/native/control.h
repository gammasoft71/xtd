#pragma once
#include <any>
#include <map>
#include <shared_mutex>
#include <list>
#include <vector>
#include <xtd/delegate.h>
#include <xtd/event_args.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/strings.h>
#include "../create_params.h"
#include "../window_messages.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control static_ {
      public:
        static drawing::color back_color(intptr_t control);
        static void back_color(intptr_t control, const drawing::color& color);
        static intptr_t create(const create_params& create_params);
        static intptr_t create_graphics(intptr_t control);
        static intptr_t create_paint_graphics(intptr_t control);
        static intptr_t create_double_buffered_paint_graphics(intptr_t control);
        static intptr_t def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle);
        static drawing::font default_font();
        static void destroy(intptr_t control);
        static void init();
        static drawing::rectangle client_rectangle(intptr_t control);
        static drawing::size client_size(intptr_t control);
        static void client_size(intptr_t control, const drawing::size& size);
        static void cursor(intptr_t control, intptr_t cursor);
        static bool enabled(intptr_t control);
        static void enabled(intptr_t control, bool enabled);
        static void focus(intptr_t control);
        static bool focused(intptr_t control);
        static drawing::color fore_color(intptr_t control);
        static void fore_color(intptr_t control, const drawing::color& color);
        static drawing::font font(intptr_t control);
        static void font(intptr_t control, const drawing::font& font);
        static void invoke_in_control_thread(intptr_t control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<std::shared_mutex> invoked);
        static drawing::point location(intptr_t control);
        static void location(intptr_t control, const drawing::point& location);
        static drawing::size size(intptr_t control);
        static void size(intptr_t control, const drawing::size& size);
        static std::string text(intptr_t control);
        static void text(intptr_t control, const std::string& text);
        static bool visible(intptr_t control);
        static void visible(intptr_t control, bool visible);
        static drawing::point point_to_client(intptr_t control, const drawing::point& p);
        static drawing::point point_to_screen(intptr_t control, const drawing::point& p);
        static void invalidate(intptr_t control, const drawing::rectangle& rect, bool invalidate_children);
        static void register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        static void unregister_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        static void register_client_size_changed(intptr_t control, delegate<void(const event_args&)> callback);
        static void refresh(intptr_t control);
        static void update(intptr_t control);
        static intptr_t send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wParam, intptr_t lParam);
        
        // For debug...
        static std::string message_to_string(int32_t id) {
          static std::map<int32_t, std::string> ids = {{ WM_NULL, "WM_NULL" }, { WM_CREATE, "WM_CREATE" }, { WM_DESTROY, "WM_DESTROY" }, { WM_MOVE, "WM_MOVE" }, { WM_SIZE, "WM_SIZE" }, { WM_ACTIVATE, "WM_ACTIVATE" }, { WM_SETFOCUS, "WM_SETFOCUS" }, { WM_KILLFOCUS, "WM_KILLFOCUS" }, { WM_ENABLE, "WM_ENABLE" }, { WM_SETREDRAW, "WM_SETREDRAW" }, { WM_SETTEXT, "WM_SETTEXT" }, { WM_GETTEXT, "WM_GETTEXT" }, { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" }, { WM_PAINT, "WM_PAINT" }, { WM_CLOSE, "WM_CLOSE" }, { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" }, { WM_QUIT, "WM_QUIT" }, { WM_QUERYOPEN, "WM_QUERYOPEN" }, { WM_ERASEBKGND, "WM_ERASEBKGND" }, { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" }, { WM_ENDSESSION, "WM_ENDSESSION" }, { WM_SHOWWINDOW, "WM_SHOWWINDOW" }, { WM_WININICHANGE, "WM_WININICHANGE" }, { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" }, { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" }, { WM_FONTCHANGE, "WM_FONTCHANGE" }, { WM_TIMECHANGE, "WM_TIMECHANGE" }, { WM_CANCELMODE, "WM_CANCELMODE" }, { WM_SETCURSOR, "WM_SETCURSOR" }, { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" }, { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" }, { WM_QUEUESYNC, "WM_QUEUESYNC" }, { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" }, { WM_PAINTICON, "WM_PAINTICON" }, { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" }, { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" }, { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" }, { WM_DRAWITEM, "WM_DRAWITEM" }, { WM_MEASUREITEM, "WM_MEASUREITEM" }, { WM_DELETEITEM, "WM_DELETEITEM" }, { WM_VKEYTOITEM, "WM_VKEYTOITEM" }, { WM_CHARTOITEM, "WM_CHARTOITEM" }, { WM_SETFONT, "WM_SETFONT" }, { WM_GETFONT, "WM_GETFONT" }, { WM_SETHOTKEY, "WM_SETHOTKEY" }, { WM_GETHOTKEY, "WM_GETHOTKEY" }, { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" }, { WM_COMPAREITEM, "WM_COMPAREITEM" }, { WM_GETOBJECT, "WM_GETOBJECT" }, { WM_COMPACTING, "WM_COMPACTING" }, { WM_COMMNOTIFY, "WM_COMMNOTIFY" }, { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" }, { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" }, { WM_POWER, "WM_POWER" }, { WM_COPYDATA, "WM_COPYDATA" }, { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" }, { WM_NOTIFY, "WM_NOTIFY" }, { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" }, { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" }, { WM_TCARD, "WM_TCARD" }, { WM_HELP, "WM_HELP" }, { WM_USERCHANGED, "WM_USERCHANGED" }, { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" }, { WM_CONTEXTMENU, "WM_CONTEXTMENU" }, { WM_STYLECHANGING, "WM_STYLECHANGING" }, { WM_STYLECHANGED, "WM_STYLECHANGED" }, { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" }, { WM_GETICON, "WM_GETICON" }, { WM_SETICON, "WM_SETICON" }, { WM_NCCREATE, "WM_NCCREATE" }, { WM_NCDESTROY, "WM_NCDESTROY" }, { WM_NCCALCSIZE, "WM_NCCALCSIZE" }, { WM_NCHITTEST, "WM_NCHITTEST" }, { WM_NCPAINT, "WM_NCPAINT" }, { WM_NCACTIVATE, "WM_NCACTIVATE" }, { WM_GETDLGCODE, "WM_GETDLGCODE" }, { WM_SYNCPAINT, "WM_SYNCPAINT" }, { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" }, { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" }, { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" }, { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" }, { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" }, { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" }, { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" }, { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" }, { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" }, { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" }, { WM_NCXBUTTONDOWN, "WM_NCXBUTTONDOWN" }, { WM_NCXBUTTONUP, "WM_NCXBUTTONUP" }, { WM_NCXBUTTONDBLCLK, "WM_NCXBUTTONDBLCLK" }, { WM_INPUT_DEVICE_CHANGE, "WM_INPUT_DEVICE_CHANGE" }, { WM_INPUT, "WM_INPUT" }, { WM_KEYDOWN, "WM_KEYDOWN" }, { WM_KEYUP, "WM_KEYUP" }, { WM_CHAR, "WM_CHAR" }, { WM_DEADCHAR, "WM_DEADCHAR" }, { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" }, { WM_SYSKEYUP, "WM_SYSKEYUP" }, { WM_SYSCHAR, "WM_SYSCHAR" }, { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" }, { WM_KEYLAST, "WM_KEYLAST" }, { WM_INITDIALOG, "WM_INITDIALOG" }, { WM_COMMAND, "WM_COMMAND" }, { WM_SYSCOMMAND, "WM_SYSCOMMAND" }, { WM_TIMER, "WM_TIMER" }, { WM_HSCROLL, "WM_HSCROLL" }, { WM_VSCROLL, "WM_VSCROLL" }, { WM_INITMENU, "WM_INITMENU" }, { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" }, { WM_GESTURE, "WM_GESTURE" }, { WM_GESTURENOTIFY, "WM_GESTURENOTIFY" }, { WM_MENUSELECT, "WM_MENUSELECT" }, { WM_MENUCHAR, "WM_MENUCHAR" }, { WM_ENTERIDLE, "WM_ENTERIDLE" }, { WM_MENURBUTTONUP, "WM_MENURBUTTONUP" }, { WM_MENUDRAG, "WM_MENUDRAG" }, { WM_MENUGETOBJECT, "WM_MENUGETOBJECT" }, { WM_UNINITMENUPOPUP, "WM_UNINITMENUPOPUP" }, { WM_MENUCOMMAND, "WM_MENUCOMMAND" }, { WM_CHANGEUISTATE, "WM_CHANGEUISTATE" }, { WM_UPDATEUISTATE, "WM_UPDATEUISTATE" }, { WM_QUERYUISTATE, "WM_QUERYUISTATE" }, { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" }, { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" }, { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" }, { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" }, { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" }, { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" }, { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" }, { MN_GETHMENU, "MN_GETHMENU" }, { WM_MOUSEMOVE, "WM_MOUSEMOVE" }, { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" }, { WM_LBUTTONUP, "WM_LBUTTONUP" }, { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" }, { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" }, { WM_RBUTTONUP, "WM_RBUTTONUP" }, { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" }, { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" }, { WM_MBUTTONUP, "WM_MBUTTONUP" }, { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" }, { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" }, { WM_XBUTTONDOWN, "WM_XBUTTONDOWN" }, { WM_XBUTTONUP, "WM_XBUTTONUP" }, { WM_XBUTTONDBLCLK, "WM_XBUTTONDBLCLK" }, { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" }, { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" }, { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" }, { WM_EXITMENULOOP, "WM_EXITMENULOOP" }, { WM_NEXTMENU, "WM_NEXTMENU" }, { WM_SIZING, "WM_SIZING" }, { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" }, { WM_MOVING, "WM_MOVING" }, { WM_POWERBROADCAST, "WM_POWERBROADCAST" }, { WM_DEVICECHANGE, "WM_DEVICECHANGE" }, { WM_MDICREATE, "WM_MDICREATE" }, { WM_MDIDESTROY, "WM_MDIDESTROY" }, { WM_MDIACTIVATE, "WM_MDIACTIVATE" }, { WM_MDIRESTORE, "WM_MDIRESTORE" }, { WM_MDINEXT, "WM_MDINEXT" }, { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" }, { WM_MDITILE, "WM_MDITILE" }, { WM_MDICASCADE, "WM_MDICASCADE" }, { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" }, { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" }, { WM_MDISETMENU, "WM_MDISETMENU" }, { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" }, { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" }, { WM_DROPFILES, "WM_DROPFILES" }, { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" }, { WM_POINTERDEVICECHANGE, "WM_POINTERDEVICECHANGE" }, { WM_POINTERDEVICEINRANGE, "WM_POINTERDEVICEINRANGE" }, { WM_POINTERDEVICEOUTOFRANGE, "WM_POINTERDEVICEOUTOFRANGE" }, { WM_TOUCH, "WM_TOUCH" }, { WM_NCPOINTERUPDATE, "WM_NCPOINTERUPDATE" }, { WM_NCPOINTERDOWN, "WM_NCPOINTERDOWN" }, { WM_NCPOINTERUP, "WM_NCPOINTERUP" }, { WM_POINTERUPDATE, "WM_POINTERUPDATE" }, { WM_POINTERDOWN, "WM_POINTERDOWN" }, { WM_POINTERUP, "WM_POINTERUP" }, { WM_POINTERENTER, "WM_POINTERENTER" }, { WM_POINTERLEAVE, "WM_POINTERLEAVE" }, { WM_POINTERACTIVATE, "WM_POINTERACTIVATE" }, { WM_POINTERCAPTURECHANGED, "WM_POINTERCAPTURECHANGED" }, { WM_TOUCHHITTESTING, "WM_TOUCHHITTESTING" }, { WM_POINTERWHEEL, "WM_POINTERWHEEL" }, { WM_POINTERHWHEEL, "WM_POINTERHWHEEL" }, { DM_POINTERHITTEST, "DM_POINTERHITTEST" }, { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" }, { WM_IME_NOTIFY, "WM_IME_NOTIFY" }, { WM_IME_CONTROL, "WM_IME_CONTROL" }, { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" }, { WM_IME_SELECT, "WM_IME_SELECT" }, { WM_IME_CHAR, "WM_IME_CHAR" }, { WM_IME_REQUEST, "WM_IME_REQUEST" }, { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" }, { WM_IME_KEYUP, "WM_IME_KEYUP" }, { WM_MOUSEENTER, "WM_MOUSEENTER" }, { WM_MOUSEHOVER, "WM_MOUSEHOVER" }, { WM_MOUSELEAVE, "WM_MOUSELEAVE" }, { WM_NCMOUSEHOVER, "WM_NCMOUSEHOVER" }, { WM_NCMOUSELEAVE, "WM_NCMOUSELEAVE" }, { WM_WTSSESSION_CHANGE, "WM_WTSSESSION_CHANGE" }, { WM_TABLET_FIRST, "WM_TABLET_FIRST" }, { WM_TABLET_LAST, "WM_TABLET_LAST" }, { WM_DPICHANGED, "WM_DPICHANGED" }, { WM_CUT, "WM_CUT" }, { WM_COPY, "WM_COPY" }, { WM_PASTE, "WM_PASTE" }, { WM_CLEAR, "WM_CLEAR" }, { WM_UNDO, "WM_UNDO" }, { WM_RENDERFORMAT, "WM_RENDERFORMAT" }, { WM_RENDERALLFORMATS, "WM_RENDERALLFORMATS" }, { WM_DESTROYCLIPBOARD, "WM_DESTROYCLIPBOARD" }, { WM_DRAWCLIPBOARD, "WM_DRAWCLIPBOARD" }, { WM_PAINTCLIPBOARD, "WM_PAINTCLIPBOARD" }, { WM_VSCROLLCLIPBOARD, "WM_VSCROLLCLIPBOARD" }, { WM_SIZECLIPBOARD, "WM_SIZECLIPBOARD" }, { WM_ASKCBFORMATNAME, "WM_ASKCBFORMATNAME" }, { WM_CHANGECBCHAIN, "WM_CHANGECBCHAIN" }, { WM_HSCROLLCLIPBOARD, "WM_HSCROLLCLIPBOARD" }, { WM_QUERYNEWPALETTE, "WM_QUERYNEWPALETTE" }, { WM_PALETTEISCHANGING, "WM_PALETTEISCHANGING" }, { WM_PALETTECHANGED, "WM_PALETTECHANGED" }, { WM_HOTKEY, "WM_HOTKEY" }, { WM_PRINT, "WM_PRINT" }, { WM_PRINTCLIENT, "WM_PRINTCLIENT" }, { WM_APPCOMMAND, "WM_APPCOMMAND" }, { WM_THEMECHANGED, "WM_THEMECHANGED" }, { WM_CLIPBOARDUPDATE, "WM_CLIPBOARDUPDATE" }, { WM_DWMCOMPOSITIONCHANGED, "WM_DWMCOMPOSITIONCHANGED" }, { WM_DWMNCRENDERINGCHANGED, "WM_DWMNCRENDERINGCHANGED" }, { WM_DWMCOLORIZATIONCOLORCHANGED, "WM_DWMCOLORIZATIONCOLORCHANGED" }, { WM_DWMWINDOWMAXIMIZEDCHANGE, "WM_DWMWINDOWMAXIMIZEDCHANGE" }, { WM_DWMSENDICONICTHUMBNAIL, "WM_DWMSENDICONICTHUMBNAIL" }, { WM_DWMSENDICONICLIVEPREVIEWBITMAP, "WM_DWMSENDICONICLIVEPREVIEWBITMAP" }, { WM_GETTITLEBARINFOEX, "WM_GETTITLEBARINFOEX" }, { WM_HANDHELDFIRST, "WM_HANDHELDFIRST" }, { WM_HANDHELDLAST, "WM_HANDHELDLAST" }, { WM_AFXFIRST, "WM_AFXFIRST" }, { WM_AFXLAST, "WM_AFXLAST" }, { WM_PENWINFIRST, "WM_PENWINFIRST" }, { WM_PENWINLAST, "WM_PENWINLAST" }, { WM_USER, "WM_USER" }, { WM_APP, "WM_APP" }};
          if (ids.find(id) != ids.end())
            return ids[id];
          return strings::format("{}", id);
        }
      };
    }
  }
}
