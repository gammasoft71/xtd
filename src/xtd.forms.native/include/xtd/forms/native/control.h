/// @file
/// @brief Contains xtd::forms::native::control API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

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
#include <xtd/ustring.h>
#include <xtd/forms_native_export.h>
#include "../create_params.h"
#include "../window_messages.h"

/// @cond
struct __message_sender__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class button;
    class control;
    class collapsible_panel;
    class command_link_button;
    class domain_up_down;
    class message;
    class paint_event_args;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @cond
      class form;
      /// @endcond

      /// @brief Contains control native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ control final static_ {
        friend __message_sender__;
        friend xtd::forms::button;
        friend xtd::forms::collapsible_panel;
        friend xtd::forms::command_link_button;
        friend xtd::forms::control;
        friend xtd::forms::domain_up_down;
        friend xtd::forms::message;
        friend xtd::forms::paint_event_args;
        friend xtd::forms::native::form;
      protected:
        /// @brief Sets the background color for the control.
        /// @param control Control window handle.
        /// @param color A xtd::drawing::color that represents the background color of the control.
        /// @warning Internal use only
        static void back_color(intptr_t control, const drawing::color& color);
        /// @brief Gets the rectangle that represents the client area of the control.
        /// @param control Control window handle.
        /// @return A rectangle that represents the client area of the control.
        /// @warning Internal use only
        static drawing::rectangle client_rectangle(intptr_t control);
        /// @brief Gets the height and width of the client area of the control.
        /// @param control Control window handle.
        /// @return A size that represents the dimensions of the client area of the control.
        /// @warning Internal use only
        /// @todo Check the redondancy with client_rectangle method.
        static drawing::size client_size(intptr_t control);
        /// @brief Sets the height and width of the client area of the control.
        /// @param control Control window handle.
        /// @param size A size that represents the dimensions of the client area of the control.
        /// @warning Internal use only
        static void client_size(intptr_t control, const drawing::size& size);
        /// @brief Creates control.
        /// @param create_param A xtd::forms::create_param object that contains needed parameters to create control.
        /// @return The created control window handle.
        /// @remarks For creating controls somes xtd::forms::create_params members are filled in as follow :
        /// | Control                         | xtd::forms::create_params::class_name | xtd::forms::create_params::style                              |
        /// |---------------------------------|---------------------------------------|---------------------------------------------------------------|
        /// | xtd::forms::button              | "button"                              | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::check_box           | "checkbox"                            | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::checked_list_box    | "checkedlistbox"                      | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::choice              | "choice"                              | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::collapsible_panel   | "collapsiblepanel"                    | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::color_picker        | "colorpicker"                         | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::combo_box           | "combobox"                            | combo_box_styles.h and window_styles.h bitwise combinaison    |
        /// | xtd::forms::command_link_button | "commandlinkbutton"                   | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::date_time_picker    | "datetimepicker"                      | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::domain_up_down      | "domainupdown"                        | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::font_picker         | "fontpicker"                          | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::form                | "form"                                | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::group_box           | "groupbox"                            | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::label               | "label"                               | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::list_box            | "listbox"                             | list_box_styles.h and window_styles.h bitwise combinaison     |
        /// | xtd::forms::loading_indicator   | "loadingindicator"                    | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::numeric_up_down     | "numericupdown"                       | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::panel               | "panel"                               | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::picture_box         | "picturebox"                          | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::progress_bar        | "progressbar"                         | progress_bar_styles.h and window_styles.h bitwise combinaison |
        /// | xtd::forms::radio_button        | "radiobutton"                         | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::scrollbar           | "scrollbar"                           | scroll_bar_styles.h and window_styles.h bitwise combinaison   |
        /// | xtd::forms::switch_button       | "switchbutton"                        | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::tab_control         | "tabcontrol"                          | tab_control_styles.h and window_styles.h bitwise combinaison  |
        /// | xtd::forms::tab_page            | "tabpage"                             | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::text_box            | "textbox"                             | window_styles.h bitwise combinaison                           |
        /// | xtd::forms::toggle_button       | "togglebutton"                        | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::track_bar           | "trackbar"                            | track_bar_styles.h and window_styles.h bitwise combinaison    |
        /// | xtd::forms::up_down_button      | "updownbutton"                        | button_styles.h and window_styles.h bitwise combinaison       |
        /// | xtd::forms::user_control        | "usercontrol"                         | window_styles.h bitwise combinaison                           |
        /// @remarks Read xtd::forms::create_params for other members.
        /// @note For more portability and compatibility with underlying toolkits, xtd::forms::create_params::class_name does not contains real Windows names like WC_DIALOG, WC_BUTTON,...
        /// @warning Internal use only
        static intptr_t create(const create_params& create_params);
        /// @brief Creates a graphics for the control.
        /// @param control Control window handle.
        /// @return A graphics handle for the control.
        /// @warning Internal use only
        static intptr_t create_graphics(intptr_t control);
        /// @brief Creates a graphics for the paint event control.
        /// @param control Control window handle.
        /// @return A graphics handle for the paint event control.
        /// @warning Internal use only
        static intptr_t create_paint_graphics(intptr_t control);
        /// @brief Creates a raphics for the double buffer paint event control.
        /// @param control Control window handle.
        /// @return A graphics handle for the double buffered paint event control.
        /// @warning Internal use only
        static intptr_t create_double_buffered_paint_graphics(intptr_t control);
        /// @brief Sets the cursor that is displayed when the mouse pointer is over the control.
        /// @param control Control window handle.
        /// @param cursor A cursor handle that represents the cursor to display when the mouse pointer is over the control.
        /// @warning Internal use only
        static void cursor(intptr_t control, intptr_t cursor);
        /// @brief Sends the specified message to the default window procedure.
        /// @param control Control window handle.
        /// @param hwnd The window handle of the message.
        /// @param msg The ID number for the message.
        /// @param wparam The wwparam field of the message.
        /// @param lparam The lparam field of the message.
        /// @param result The return value of the message.
        /// @param handle The handle on specific operating system data
        /// @return The result of def_wnd_proc message.
        /// @warning Internal use only
        static intptr_t def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle);
        /// @brief Destroys context menu.
        /// @param control Control window handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t control);
        /// @brief Gets a value indicating whether the control can respond to user interaction.
        /// @param control Control window handle.
        /// @return true if the control can respond to user interaction; otherwise, false.
        /// @warning Internal use only
        static bool enabled(intptr_t control);
        /// @brief Sets a value indicating whether the control can respond to user interaction.
        /// @param control Control window handle.
        /// @param enabled true if the control can respond to user interaction; otherwise, false.
        /// @warning Internal use only
        static void enabled(intptr_t control, bool enabled);
        /// @brief Sets input focus to the control.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void focus(intptr_t control);
        /// @brief Gets a value indicating whether the control has input focus.
        /// @param control Control window handle.
        /// @return true if the control has focus; otherwise, false.
        /// @warning Internal use only
        static bool focused(intptr_t control);
        /// @brief Sets the foreground color of the control.
        /// @param control Control window handle.
        /// @param color The foreground color of the control.
        /// @warning Internal use only
        static void fore_color(intptr_t control, const drawing::color& color);
        /// @brief Sets the font of the text displayed by the control.
        /// @param control Control window handle.
        /// @param font The xtd::drawing::font to apply to the text displayed by the control.
        /// @warning Internal use only
        static void font(intptr_t control, const drawing::font& font);
        /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
        /// @param control Control window handle.
        /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
        /// @param erase_background true to erase background control; otherwise, false.
        /// @warning Internal use only
        static void invalidate(intptr_t control, const drawing::rectangle& rect, bool erase_background);
        /// @brief Executes the specified delegate, on the thread that owns the control's underlying window handle, with the specified list of arguments and mutex.
        /// @param control Control window handle.
        /// @param invoker A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
        /// @param args An array of objects to pass as arguments to the specified method. This parameter can be null if the method takes no arguments.
        /// @param invoked A mutex for async invoke.
        /// @remarks Signal mutex when invoke is done.
        /// @warning Internal use only
        static void invoke_in_control_thread(intptr_t control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<std::shared_mutex> invoked);
        /// @brief Gets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
        /// @param control Control window handle.
        /// @return The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
        /// @warning Internal use only
        static drawing::point location(intptr_t control);
        /// @brief Sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
        /// @param control Control window handle.
        /// @param location 
        /// @warning Internal use only
        static void location(intptr_t control, const drawing::point& location);
        /// @brief Computes the location of the specified screen point into client coordinates.
        /// @param control Control window handle.
        /// @param p The screen coordinate xtd::drawing::point to convert.
        /// @return A xtd::drawing::point that represents the converted xtd::drawing::point, p, in client coordinates.
        /// @warning Internal use only
        static drawing::point point_to_client(intptr_t control, const drawing::point& p);
        /// @brief Computes the location of the specified client point into screen coordinates.
        /// @param control Control window handle.
        /// @param p The client coordinate  xtd::drawing::point to convert.
        /// @return A xtd::drawing::point that represents the converted  xtd::drawing::point, p, in screen coordinates.
        /// @warning Internal use only
        static drawing::point point_to_screen(intptr_t control, const drawing::point& p);
        /// @brief Forces the control to invalidate its client area and immediately redraw itself and any child controls.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void refresh(intptr_t control);
        /// @brief Register a specified wnd proc from the message pump of the control.
        /// @param control Control window handle.
        /// @param wnd_proc A wnd proc delegate to register.
        /// @warning Internal use only
        static void register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc);
        /// @brief Send a message with specified hwnd, message, wparam and lparam.
        /// @param control Control window handle.
        /// @param hwnd The window handle of the message.
        /// @param msg The ID number for the message.
        /// @param wparam The WParam field of the message.
        /// @param lparam The LParam field of the message.
        /// @return The return value of the message.
        /// @warning Internal use only
        static intptr_t send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wParam, intptr_t lParam);
        /// @brief Gets the height and width of the control.
        /// @param control Control window handle.
        /// @return The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static drawing::size size(intptr_t control);
        /// @brief Sets the height and width of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void size(intptr_t control, const drawing::size& size);
        /// @brief Gets the text associated with this control.
        /// @param control Control window handle.
        /// @return The text associated with this control.
        /// @warning Internal use only
        static std::string text(intptr_t control);
        /// @brief Sets the text associated with this control.
        /// @param control Control window handle.
        /// @param text The text associated with this control.
        /// @warning Internal use only
        static void text(intptr_t control, const std::string& text);
        /// @brief Unregister the wnd proc previously registered.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void unregister_wnd_proc(intptr_t control);
        /// @brief Causes the control to redraw the invalidated regions within its client area.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void update(intptr_t control);
        /// @brief Gets a value indicating whether the control and all its child controls are displayed.
        /// @param control Control window handle.
        /// @return true if the control and all its child controls are displayed; otherwise, false.
        /// @warning Internal use only
        static bool visible(intptr_t control);
        /// @brief Sets a value indicating whether the control and all its child controls are displayed.
        /// @param control Control window handle.
        /// @param visible true if the control and all its child controls are displayed; otherwise, false.
        /// @warning Internal use only
        static void visible(intptr_t control, bool visible);
        
        /// @brief Coomvert message identifiers to a string.
        /// @param control Control window handle.
        /// @param id An int32_t message id.
        /// @return A string that represent the message id.
        /// @par Notes for xtd developers
        /// This method is not an API. It is needed only for debug.
        /// @warning Internal use only
        static std::string message_to_string(int32_t id) {
          static std::map<int32_t, std::string> ids = {{ WM_NULL, "WM_NULL" }, { WM_CREATE, "WM_CREATE" }, { WM_DESTROY, "WM_DESTROY" }, { WM_MOVE, "WM_MOVE" }, { WM_SIZE, "WM_SIZE" }, { WM_ACTIVATE, "WM_ACTIVATE" }, { WM_SETFOCUS, "WM_SETFOCUS" }, { WM_KILLFOCUS, "WM_KILLFOCUS" }, { WM_ENABLE, "WM_ENABLE" }, { WM_SETREDRAW, "WM_SETREDRAW" }, { WM_SETTEXT, "WM_SETTEXT" }, { WM_GETTEXT, "WM_GETTEXT" }, { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" }, { WM_PAINT, "WM_PAINT" }, { WM_CLOSE, "WM_CLOSE" }, { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" }, { WM_QUIT, "WM_QUIT" }, { WM_QUERYOPEN, "WM_QUERYOPEN" }, { WM_ERASEBKGND, "WM_ERASEBKGND" }, { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" }, { WM_ENDSESSION, "WM_ENDSESSION" }, { WM_SHOWWINDOW, "WM_SHOWWINDOW" }, { WM_WININICHANGE, "WM_WININICHANGE" }, { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" }, { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" }, { WM_FONTCHANGE, "WM_FONTCHANGE" }, { WM_TIMECHANGE, "WM_TIMECHANGE" }, { WM_CANCELMODE, "WM_CANCELMODE" }, { WM_SETCURSOR, "WM_SETCURSOR" }, { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" }, { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" }, { WM_QUEUESYNC, "WM_QUEUESYNC" }, { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" }, { WM_PAINTICON, "WM_PAINTICON" }, { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" }, { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" }, { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" }, { WM_DRAWITEM, "WM_DRAWITEM" }, { WM_MEASUREITEM, "WM_MEASUREITEM" }, { WM_DELETEITEM, "WM_DELETEITEM" }, { WM_VKEYTOITEM, "WM_VKEYTOITEM" }, { WM_CHARTOITEM, "WM_CHARTOITEM" }, { WM_SETFONT, "WM_SETFONT" }, { WM_GETFONT, "WM_GETFONT" }, { WM_SETHOTKEY, "WM_SETHOTKEY" }, { WM_GETHOTKEY, "WM_GETHOTKEY" }, { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" }, { WM_COMPAREITEM, "WM_COMPAREITEM" }, { WM_GETOBJECT, "WM_GETOBJECT" }, { WM_COMPACTING, "WM_COMPACTING" }, { WM_COMMNOTIFY, "WM_COMMNOTIFY" }, { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" }, { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" }, { WM_POWER, "WM_POWER" }, { WM_COPYDATA, "WM_COPYDATA" }, { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" }, { WM_NOTIFY, "WM_NOTIFY" }, { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" }, { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" }, { WM_TCARD, "WM_TCARD" }, { WM_HELP, "WM_HELP" }, { WM_USERCHANGED, "WM_USERCHANGED" }, { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" }, { WM_CONTEXTMENU, "WM_CONTEXTMENU" }, { WM_STYLECHANGING, "WM_STYLECHANGING" }, { WM_STYLECHANGED, "WM_STYLECHANGED" }, { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" }, { WM_GETICON, "WM_GETICON" }, { WM_SETICON, "WM_SETICON" }, { WM_NCCREATE, "WM_NCCREATE" }, { WM_NCDESTROY, "WM_NCDESTROY" }, { WM_NCCALCSIZE, "WM_NCCALCSIZE" }, { WM_NCHITTEST, "WM_NCHITTEST" }, { WM_NCPAINT, "WM_NCPAINT" }, { WM_NCACTIVATE, "WM_NCACTIVATE" }, { WM_GETDLGCODE, "WM_GETDLGCODE" }, { WM_SYNCPAINT, "WM_SYNCPAINT" }, { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" }, { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" }, { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" }, { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" }, { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" }, { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" }, { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" }, { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" }, { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" }, { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" }, { WM_NCXBUTTONDOWN, "WM_NCXBUTTONDOWN" }, { WM_NCXBUTTONUP, "WM_NCXBUTTONUP" }, { WM_NCXBUTTONDBLCLK, "WM_NCXBUTTONDBLCLK" }, { WM_INPUT_DEVICE_CHANGE, "WM_INPUT_DEVICE_CHANGE" }, { WM_INPUT, "WM_INPUT" }, { WM_KEYDOWN, "WM_KEYDOWN" }, { WM_KEYUP, "WM_KEYUP" }, { WM_CHAR, "WM_CHAR" }, { WM_DEADCHAR, "WM_DEADCHAR" }, { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" }, { WM_SYSKEYUP, "WM_SYSKEYUP" }, { WM_SYSCHAR, "WM_SYSCHAR" }, { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" }, { WM_KEYLAST, "WM_KEYLAST" }, { WM_INITDIALOG, "WM_INITDIALOG" }, { WM_COMMAND, "WM_COMMAND" }, { WM_SYSCOMMAND, "WM_SYSCOMMAND" }, { WM_TIMER, "WM_TIMER" }, { WM_HSCROLL, "WM_HSCROLL" }, { WM_VSCROLL, "WM_VSCROLL" }, { WM_INITMENU, "WM_INITMENU" }, { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" }, { WM_GESTURE, "WM_GESTURE" }, { WM_GESTURENOTIFY, "WM_GESTURENOTIFY" }, { WM_MENUSELECT, "WM_MENUSELECT" }, { WM_MENUCHAR, "WM_MENUCHAR" }, { WM_ENTERIDLE, "WM_ENTERIDLE" }, { WM_MENURBUTTONUP, "WM_MENURBUTTONUP" }, { WM_MENUDRAG, "WM_MENUDRAG" }, { WM_MENUGETOBJECT, "WM_MENUGETOBJECT" }, { WM_UNINITMENUPOPUP, "WM_UNINITMENUPOPUP" }, { WM_MENUCOMMAND, "WM_MENUCOMMAND" }, { WM_CHANGEUISTATE, "WM_CHANGEUISTATE" }, { WM_UPDATEUISTATE, "WM_UPDATEUISTATE" }, { WM_QUERYUISTATE, "WM_QUERYUISTATE" }, { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" }, { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" }, { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" }, { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" }, { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" }, { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" }, { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" }, { WM_GETHMENU, "WM_GETHMENU" }, { WM_MOUSEMOVE, "WM_MOUSEMOVE" }, { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" }, { WM_LBUTTONUP, "WM_LBUTTONUP" }, { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" }, { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" }, { WM_RBUTTONUP, "WM_RBUTTONUP" }, { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" }, { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" }, { WM_MBUTTONUP, "WM_MBUTTONUP" }, { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" }, { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" }, { WM_XBUTTONDOWN, "WM_XBUTTONDOWN" }, { WM_XBUTTONUP, "WM_XBUTTONUP" }, { WM_XBUTTONDBLCLK, "WM_XBUTTONDBLCLK" }, { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" }, { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" }, { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" }, { WM_EXITMENULOOP, "WM_EXITMENULOOP" }, { WM_NEXTMENU, "WM_NEXTMENU" }, { WM_SIZING, "WM_SIZING" }, { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" }, { WM_MOVING, "WM_MOVING" }, { WM_POWERBROADCAST, "WM_POWERBROADCAST" }, { WM_DEVICECHANGE, "WM_DEVICECHANGE" }, { WM_MDICREATE, "WM_MDICREATE" }, { WM_MDIDESTROY, "WM_MDIDESTROY" }, { WM_MDIACTIVATE, "WM_MDIACTIVATE" }, { WM_MDIRESTORE, "WM_MDIRESTORE" }, { WM_MDINEXT, "WM_MDINEXT" }, { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" }, { WM_MDITILE, "WM_MDITILE" }, { WM_MDICASCADE, "WM_MDICASCADE" }, { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" }, { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" }, { WM_MDISETMENU, "WM_MDISETMENU" }, { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" }, { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" }, { WM_DROPFILES, "WM_DROPFILES" }, { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" }, { WM_POINTERDEVICECHANGE, "WM_POINTERDEVICECHANGE" }, { WM_POINTERDEVICEINRANGE, "WM_POINTERDEVICEINRANGE" }, { WM_POINTERDEVICEOUTOFRANGE, "WM_POINTERDEVICEOUTOFRANGE" }, { WM_TOUCH, "WM_TOUCH" }, { WM_NCPOINTERUPDATE, "WM_NCPOINTERUPDATE" }, { WM_NCPOINTERDOWN, "WM_NCPOINTERDOWN" }, { WM_NCPOINTERUP, "WM_NCPOINTERUP" }, { WM_POINTERUPDATE, "WM_POINTERUPDATE" }, { WM_POINTERDOWN, "WM_POINTERDOWN" }, { WM_POINTERUP, "WM_POINTERUP" }, { WM_POINTERENTER, "WM_POINTERENTER" }, { WM_POINTERLEAVE, "WM_POINTERLEAVE" }, { WM_POINTERACTIVATE, "WM_POINTERACTIVATE" }, { WM_POINTERCAPTURECHANGED, "WM_POINTERCAPTURECHANGED" }, { WM_TOUCHHITTESTING, "WM_TOUCHHITTESTING" }, { WM_POINTERWHEEL, "WM_POINTERWHEEL" }, { WM_POINTERHWHEEL, "WM_POINTERHWHEEL" }, { WM_POINTERHITTEST, "WM_POINTERHITTEST" }, { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" }, { WM_IME_NOTIFY, "WM_IME_NOTIFY" }, { WM_IME_CONTROL, "WM_IME_CONTROL" }, { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" }, { WM_IME_SELECT, "WM_IME_SELECT" }, { WM_IME_CHAR, "WM_IME_CHAR" }, { WM_IME_REQUEST, "WM_IME_REQUEST" }, { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" }, { WM_IME_KEYUP, "WM_IME_KEYUP" }, { WM_MOUSEENTER, "WM_MOUSEENTER" }, { WM_MOUSEHOVER, "WM_MOUSEHOVER" }, { WM_MOUSELEAVE, "WM_MOUSELEAVE" }, { WM_NCMOUSEHOVER, "WM_NCMOUSEHOVER" }, { WM_NCMOUSELEAVE, "WM_NCMOUSELEAVE" }, { WM_WTSSESSION_CHANGE, "WM_WTSSESSION_CHANGE" }, { WM_TABLET_FIRST, "WM_TABLET_FIRST" }, { WM_TABLET_LAST, "WM_TABLET_LAST" }, { WM_DPICHANGED, "WM_DPICHANGED" }, { WM_CUT, "WM_CUT" }, { WM_COPY, "WM_COPY" }, { WM_PASTE, "WM_PASTE" }, { WM_CLEAR, "WM_CLEAR" }, { WM_UNDO, "WM_UNDO" }, { WM_RENDERFORMAT, "WM_RENDERFORMAT" }, { WM_RENDERALLFORMATS, "WM_RENDERALLFORMATS" }, { WM_DESTROYCLIPBOARD, "WM_DESTROYCLIPBOARD" }, { WM_DRAWCLIPBOARD, "WM_DRAWCLIPBOARD" }, { WM_PAINTCLIPBOARD, "WM_PAINTCLIPBOARD" }, { WM_VSCROLLCLIPBOARD, "WM_VSCROLLCLIPBOARD" }, { WM_SIZECLIPBOARD, "WM_SIZECLIPBOARD" }, { WM_ASKCBFORMATNAME, "WM_ASKCBFORMATNAME" }, { WM_CHANGECBCHAIN, "WM_CHANGECBCHAIN" }, { WM_HSCROLLCLIPBOARD, "WM_HSCROLLCLIPBOARD" }, { WM_QUERYNEWPALETTE, "WM_QUERYNEWPALETTE" }, { WM_PALETTEISCHANGING, "WM_PALETTEISCHANGING" }, { WM_PALETTECHANGED, "WM_PALETTECHANGED" }, { WM_HOTKEY, "WM_HOTKEY" }, { WM_PRINT, "WM_PRINT" }, { WM_PRINTCLIENT, "WM_PRINTCLIENT" }, { WM_APPCOMMAND, "WM_APPCOMMAND" }, { WM_THEMECHANGED, "WM_THEMECHANGED" }, { WM_CLIPBOARDUPDATE, "WM_CLIPBOARDUPDATE" }, { WM_DWMCOMPOSITIONCHANGED, "WM_DWMCOMPOSITIONCHANGED" }, { WM_DWMNCRENDERINGCHANGED, "WM_DWMNCRENDERINGCHANGED" }, { WM_DWMCOLORIZATIONCOLORCHANGED, "WM_DWMCOLORIZATIONCOLORCHANGED" }, { WM_DWMWINDOWMAXIMIZEDCHANGE, "WM_DWMWINDOWMAXIMIZEDCHANGE" }, { WM_DWMSENDICONICTHUMBNAIL, "WM_DWMSENDICONICTHUMBNAIL" }, { WM_DWMSENDICONICLIVEPREVIEWBITMAP, "WM_DWMSENDICONICLIVEPREVIEWBITMAP" }, { WM_GETTITLEBARINFOEX, "WM_GETTITLEBARINFOEX" }, { WM_HANDHELDFIRST, "WM_HANDHELDFIRST" }, { WM_HANDHELDLAST, "WM_HANDHELDLAST" }, { WM_AFXFIRST, "WM_AFXFIRST" }, { WM_AFXLAST, "WM_AFXLAST" }, { WM_PENWINFIRST, "WM_PENWINFIRST" }, { WM_PENWINLAST, "WM_PENWINLAST" }, { WM_USER, "WM_USER" }, { WM_APP, "WM_APP" }};
          auto it = ids.find(id);
          if (it != ids.end()) return it->second;
          return ustring::format("{}", id);
        }
      };
    }
  }
}
