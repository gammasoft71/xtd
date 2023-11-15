/// @file
/// @brief Contains xtd::forms::native::control API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <map>
#include <list>
#include <vector>
#include <xtd/threading/manual_reset_event.h>
#include <xtd/any.h>
#include <xtd/delegate.h>
#include <xtd/event_args.h>
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/region.h>
#include <xtd/ustring.h>
#include <xtd/forms_native_export.h>
#include "../window_messages.h"
#include "create_params.h"

/// @cond
struct __message_sender__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class button;
    class collapsible_panel;
    class command_link_button;
    class control;
    class combo_box;
    class domain_up_down;
    class form;
    class light_button;
    class message;
    class paint_event_args;
    class status_bar;
    class tool_bar;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @cond
      class form;
      /// @endcond
      
      /// @brief Contains control native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ control final static_ {
        friend __message_sender__;
        friend xtd::forms::button;
        friend xtd::forms::collapsible_panel;
        friend xtd::forms::command_link_button;
        friend xtd::forms::combo_box;
        friend xtd::forms::control;
        friend xtd::forms::domain_up_down;
        friend xtd::forms::form;
        friend xtd::forms::light_button;
        friend xtd::forms::message;
        friend xtd::forms::paint_event_args;
        friend xtd::forms::status_bar;
        friend xtd::forms::tool_bar;
        friend xtd::forms::native::form;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Sets the background color for the control.
        /// @param control Control window handle.
        /// @param color A xtd::drawing::color that represents the background color of the control.
        /// @warning Internal use only
        static void back_color(intptr control, const drawing::color& color);
        
        /// @brief Gets the rectangle that represents the client area of the control.
        /// @param control Control window handle.
        /// @return A rectangle that represents the client area of the control.
        /// @warning Internal use only
        static drawing::rectangle client_rectangle(intptr control);
        
        /// @brief Gets the height and width of the client area of the control.
        /// @param control Control window handle.
        /// @return A size that represents the dimensions of the client area of the control.
        /// @warning Internal use only
        /// @todo Check the redundancy with client_rectangle method.
        static drawing::size client_size(intptr control);
        /// @brief Sets the height and width of the client area of the control.
        /// @param control Control window handle.
        /// @param size A size that represents the dimensions of the client area of the control.
        /// @warning Internal use only
        static void client_size(intptr control, const drawing::size& size);
        
        /// @brief Sets the context that is displayed in the control.
        /// @param control Control handle.
        /// @param menu A menu handle that represents the menu to display in the form.
        /// @warning Internal use only
        static void context_menu(intptr control, intptr context_menu, const xtd::drawing::point& pos);
        
        /// @brief Displays the shortcut menu at the specified position.
        /// @param control A control handle that specifies the control with which this shortcut menu is associated.
        /// @param context_menu A context menu handle that specifies the menu is associated.
        /// @param pos A xtd::drawing::point that specifies the coordinates at which to display the menu. These coordinates are specified relative to the client coordinates of the control specified in the control parameter.
        /// @return Id corresponding to menu_item handle selected.
        /// @warning Internal use only
        static intptr user_context_menu(intptr control, intptr context_menu, const xtd::drawing::point& pos);
        
        /// @brief Creates control.
        /// @param create_param A xtd::forms::create_param object that contains needed parameters to create control.
        /// @return The created control window handle.
        /// @remarks For creating controls, some xtd::forms::create_params members are filled in as follow :
        /// | Control                         | xtd::forms::create_params::class_name | xtd::forms::create_params::style                              |
        /// | ------------------------------- | ------------------------------------- | ------------------------------------------------------------- |
        /// | xtd::forms::button              | "button"                              | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::check_box           | "checkbox"                            | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::checked_list_box    | "checkedlistbox"                      | window_styles.h bitwise combination                           |
        /// | xtd::forms::choice              | "choice"                              | window_styles.h bitwise combination                           |
        /// | xtd::forms::collapsible_panel   | "collapsiblepanel"                    | window_styles.h bitwise combination                           |
        /// | xtd::forms::color_picker        | "colorpicker"                         | window_styles.h bitwise combination                           |
        /// | xtd::forms::combo_box           | "combobox"                            | combo_box_styles.h and window_styles.h bitwise combination    |
        /// | xtd::forms::command_link_button | "commandlinkbutton"                   | window_styles.h bitwise combination                           |
        /// | xtd::forms::date_time_picker    | "datetimepicker"                      | window_styles.h bitwise combination                           |
        /// | xtd::forms::domain_up_down      | "domainupdown"                        | window_styles.h bitwise combination                           |
        /// | xtd::forms::font_picker         | "fontpicker"                          | window_styles.h bitwise combination                           |
        /// | xtd::forms::form                | "form"                                | window_styles.h bitwise combination                           |
        /// | xtd::forms::group_box           | "groupbox"                            | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::label               | "label"                               | window_styles.h bitwise combination                           |
        /// | xtd::forms::list_box            | "listbox"                             | list_box_styles.h and window_styles.h bitwise combination     |
        /// | xtd::forms::loading_indicator   | "loadingindicator"                    | window_styles.h bitwise combination                           |
        /// | xtd::forms::numeric_up_down     | "numericupdown"                       | window_styles.h bitwise combination                           |
        /// | xtd::forms::panel               | "panel"                               | window_styles.h bitwise combination                           |
        /// | xtd::forms::picture_box         | "picturebox"                          | window_styles.h bitwise combination                           |
        /// | xtd::forms::progress_bar        | "progressbar"                         | progress_bar_styles.h and window_styles.h bitwise combination |
        /// | xtd::forms::radio_button        | "radiobutton"                         | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::scrollbar           | "scrollbar"                           | scroll_bar_styles.h and window_styles.h bitwise combination   |
        /// | xtd::forms::switch_button       | "switchbutton"                        | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::tab_control         | "tabcontrol"                          | tab_control_styles.h and window_styles.h bitwise combination  |
        /// | xtd::forms::tab_page            | "tabpage"                             | window_styles.h bitwise combination                           |
        /// | xtd::forms::text_box            | "textbox"                             | window_styles.h bitwise combination                           |
        /// | xtd::forms::toggle_button       | "togglebutton"                        | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::track_bar           | "trackbar"                            | track_bar_styles.h and window_styles.h bitwise combination    |
        /// | xtd::forms::up_down_button      | "updownbutton"                        | button_styles.h and window_styles.h bitwise combination       |
        /// | xtd::forms::user_control        | "usercontrol"                         | window_styles.h bitwise combination                           |
        /// @remarks Read xtd::forms::create_params for other members.
        /// @note For more portability and compatibility with underlying toolkits, xtd::forms::create_params::class_name does not contains real Windows names like WC_DIALOG, WC_BUTTON,...
        /// @warning Internal use only
        static intptr create(const create_params& create_params);
        
        /// @brief Creates a graphics for the control.
        /// @param control Control window handle.
        /// @return A graphics handle for the control.
        /// @warning Internal use only
        static intptr create_graphics(intptr control);
        
        /// @brief Creates a graphics for the xtd::forms::control::paint event control.
        /// @param control Control window handle.
        /// @return A graphics handle for the xtd::forms::control::paint event control.
        /// @warning Internal use only
        static intptr create_paint_graphics(intptr control);
        
        /// @brief Creates a graphics for the double buffer xtd::forms::control::paint event control.
        /// @param control Control window handle.
        /// @return A graphics handle for the double buffered xtd::forms::control::paint event control.
        /// @warning Internal use only
        static intptr create_double_buffered_paint_graphics(intptr control);
        
        /// @brief Sets the cursor that is displayed when the mouse pointer is over the control.
        /// @param control Control window handle.
        /// @param cursor A cursor handle that represents the cursor to display when the mouse pointer is over the control.
        /// @warning Internal use only
        static void cursor(intptr control, intptr cursor);
        
        /// @brief Sends the specified message to the default window procedure.
        /// @param control Control window handle.
        /// @param hwnd The window handle of the message.
        /// @param msg The ID number for the message.
        /// @param wparam The wparam field of the message.
        /// @param lparam The lparam field of the message.
        /// @param result The return value of the message.
        /// @param handle The handle on specific operating system data
        /// @return The result of def_wnd_proc message.
        /// @warning Internal use only
        static intptr def_wnd_proc(intptr control, intptr hwnd, uint32 msg, intptr wparam, intptr lparam, intptr result, intptr handle);
        
        /// @brief Gets the default height and default width for the specified class name.
        /// @param class_name The name of the Windows class to derive the control from.
        /// @return The default size that represents the default height and default width of the control in pixels.
        /// @remarks The class name is the same as the one used to create the control with the xtd::forms::create_params class.
        /// @remarks The following table contains the default width and height in pixels for class name :
        /// | class name          | Width  | Height |
        /// | ------------------- | ------ | ------ |
        /// | "button"            | 75     | 25     |
        /// | "checkbox"          | 104    | 25     |
        /// | "checkedlistbox"    | 120    | 90     |
        /// | "choice"            | 130    | 25     |
        /// | "collapsiblepanel"  | 0      | 0      |
        /// | "colorpicker"       | 104    | 25     |
        /// | "combobox"          | 130    | 23 *   |
        /// | "commandlinkbutton" | 200    | 60     |
        /// | "datetimepicker"    | 104    | 25 **  |
        /// | "domainupdown"      | 150    | 23 **  |
        /// | "fontpicker"        | 104    | 25     |
        /// | "form"              | 300    | 300    |
        /// | "groupbox"          | 200    | 100    |
        /// | "label"             | 100    | 23     |
        /// | "lightbutton"       | 75     | 25     |
        /// | "listbox"           | 120    | 96     |
        /// | "loadingindicator"  | 32     | 32     |
        /// | "monthcalendar"     | 240    | 162    |
        /// | "numericupdown"     | 120    | 23 **  |
        /// | "panel"             | 200    | 100    |
        /// | "picturebox"        | 100    | 50     |
        /// | "popup_panel"       | 100    | 150    |
        /// | "progressbar"       | 100    | 23     |
        /// | "radiobutton"       | 104    | 25     |
        /// | "scrollbar"         | 17     | 17     |
        /// | "statusbar"         | 100    | 23     |
        /// | "switchbutton"      | 50     | 25     |
        /// | "tabcontrol"        | 200    | 100    |
        /// | "tabpage"           | 200    | 100    |
        /// | "textbox"           | 100    | 23     |
        /// | "togglebutton"      | 104    | 25     |
        /// | "toolbar"           | 100    | 23     |
        /// | "trackbar"          | 104    | 45     |
        /// | "updownbutton"      | 18 *** | 34     |
        /// | "usercontrol"       | 150    | 150    |
        /// | other               | 0      | 0      |
        ///
        /// ** is 21 on "macos" environment
        /// *** is 34 on "gnome" environment
        /// **** is 71 on "gnome" environment
        /// @warning Internal use only
        
        static xtd::drawing::size default_size(const xtd::ustring& class_name);
        
        /// @brief Destroys context menu.
        /// @param control Control window handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr control);
        
        /// @brief Gets a value indicating whether the control can respond to user interaction.
        /// @param control Control window handle.
        /// @return true if the control can respond to user interaction; otherwise, false.
        /// @warning Internal use only
        static bool enabled(intptr control);
        
        /// @brief Sets a value indicating whether the control can respond to user interaction.
        /// @param control Control window handle.
        /// @param enabled true if the control can respond to user interaction; otherwise, false.
        /// @warning Internal use only
        static void enabled(intptr control, bool enabled);
        
        /// @brief Sets input focus to the control.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void focus(intptr control);
        
        /// @brief Gets a value indicating whether the control has input focus.
        /// @param control Control window handle.
        /// @return true if the control has focus; otherwise, false.
        /// @warning Internal use only
        static bool focused(intptr control);
        
        /// @brief Sets the foreground color of the control.
        /// @param control Control window handle.
        /// @param color The foreground color of the control.
        /// @warning Internal use only
        static void fore_color(intptr control, const drawing::color& color);
        
        /// @brief Sets the font of the text displayed by the control.
        /// @param control Control window handle.
        /// @param font The xtd::drawing::font to apply to the text displayed by the control.
        /// @warning Internal use only
        static void font(intptr control, const drawing::font& font);
        
        /// @brief Gets the native handle of the control.
        /// @param control Control window handle.
        /// @return The native handle.
        /// @warning Internal use only
        static intptr native_handle(intptr control);
        
        /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
        /// @param control Control window handle.
        /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
        /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
        /// @warning Internal use only
        static void invalidate(intptr control, const drawing::rectangle& rec, bool invalidate_children);
        
        /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
        /// @param control Control window handle.
        /// @param region A xtd::drawing::region that represents the region to invalidate.
        /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
        /// @warning Internal use only
        static void invalidate(intptr control, const drawing::region& region, bool invalidate_children);
        
        /// @brief Executes the specified delegate, on the thread that owns the control's underlying window handle, with the specified list of arguments and mutex.
        /// @param control Control window handle.
        /// @param invoker A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
        /// @param args An array of objects to pass as arguments to the specified method. This parameter can be null if the method takes no arguments.
        /// @param invoked A mutex for async invoke.
        /// @remarks Signal mutex when invoke is done.
        /// @warning Internal use only
        static void invoke_in_control_thread(intptr control, delegate<void(std::vector<std::any>)> invoker, const std::vector<std::any>& args, std::shared_ptr<xtd::threading::manual_reset_event> invoked, std::shared_ptr<bool> completed);
        
        /// @brief Gets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
        /// @param control Control window handle.
        /// @return The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
        /// @warning Internal use only
        static drawing::point location(intptr control);
        /// @brief Sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
        /// @param control Control window handle.
        /// @param location
        /// @warning Internal use only
        static void location(intptr control, const drawing::point& location);
        
        /// @brief Sets the maximum height and maximum width of the client area of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void maximum_client_size(intptr control, const drawing::size& size);
        
        /// @brief Sets the maximum height and maximum width of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void maximum_size(intptr control, const drawing::size& size);
        
        /// @brief Sets the minimum height and minimum width of the client area of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void minimum_client_size(intptr control, const drawing::size& size);
        
        /// @brief Sets the minimum height and minimum width of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void minimum_size(intptr control, const drawing::size& size);
        
        /// @brief Computes the location of the specified screen point into client coordinates.
        /// @param control Control window handle.
        /// @param p The screen coordinate xtd::drawing::point to convert.
        /// @return A xtd::drawing::point that represents the converted xtd::drawing::point, p, in client coordinates.
        /// @warning Internal use only
        static drawing::point point_to_client(intptr control, const drawing::point& p);
        
        /// @brief Computes the location of the specified client point into screen coordinates.
        /// @param control Control window handle.
        /// @param p The client coordinate  xtd::drawing::point to convert.
        /// @return A xtd::drawing::point that represents the converted  xtd::drawing::point, p, in screen coordinates.
        /// @warning Internal use only
        static drawing::point point_to_screen(intptr control, const drawing::point& p);
        
        /// @brief Register a specified wnd proc from the message pump of the control.
        /// @param control Control window handle.
        /// @param wnd_proc A wnd proc delegate to register.
        /// @warning Internal use only
        static void register_wnd_proc(intptr control, const delegate<intptr(intptr, int32, intptr, intptr, intptr)>& wnd_proc);
        
        /// @brief Resumes usual layout logic.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void resume_layout(intptr control);
        
        /// @brief Send a message with specified hwnd, message, wparam and lparam.
        /// @param control Control window handle.
        /// @param hwnd The window handle of the message.
        /// @param msg The ID number for the message.
        /// @param wparam The WParam field of the message.
        /// @param lparam The LParam field of the message.
        /// @return The return value of the message.
        /// @warning Internal use only
        static intptr send_message(intptr control, intptr hwnd, int32 msg, intptr wParam, intptr lParam);
        
        /// @brief Gets the height and width of the control.
        /// @param control Control window handle.
        /// @return The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static drawing::size size(intptr control);
        /// @brief Sets the height and width of the control.
        /// @param control Control window handle.
        /// @param size The size that represents the height and width of the control in pixels.
        /// @warning Internal use only
        static void size(intptr control, const drawing::size& size);
        
        /// @brief Temporarily suspends the layout logic for the control.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void suspend_layout(intptr control);
        
        /// @brief Gets the text associated with this control.
        /// @param control Control window handle.
        /// @return The text associated with this control.
        /// @warning Internal use only
        static xtd::ustring text(intptr control);
        /// @brief Sets the text associated with this control.
        /// @param control Control window handle.
        /// @param text The text associated with this control.
        /// @warning Internal use only
        static void text(intptr control, const xtd::ustring& text);
        
        /// @brief Gets the toolkit handle of the control.
        /// @param control Control window handle.
        /// @return The toolkit handle.
        /// @warning Internal use only
        static intptr toolkit_handle(intptr control);
        
        /// @brief Unregister the wnd proc previously registered.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void unregister_wnd_proc(intptr control);
        
        /// @brief Causes the control to redraw the invalidated regions within its client area.
        /// @param control Control window handle.
        /// @warning Internal use only
        static void update(intptr control);
        
        /// @brief Gets a value indicating whether the control and all its child controls are displayed.
        /// @param control Control window handle.
        /// @return true if the control and all its child controls are displayed; otherwise, false.
        /// @warning Internal use only
        static bool visible(intptr control);
        /// @brief Sets a value indicating whether the control and all its child controls are displayed.
        /// @param control Control window handle.
        /// @param visible true if the control and all its child controls are displayed; otherwise, false.
        /// @warning Internal use only
        static void visible(intptr control, bool visible);
        
        /// @brief Convert message identifiers to a string.
        /// @param control Control window handle.
        /// @param id An int32 message id.
        /// @return A string that represent the message id.
        /// @par Notes for xtd developers
        /// This method is not an API. It is needed only for debug.
        /// @warning Internal use only
        static xtd::ustring message_to_string(uint32 id) {
          static std::map<uint32, xtd::ustring> ids = {{ WM_NULL, "WM_NULL" }, { WM_CREATE, "WM_CREATE" }, { WM_DESTROY, "WM_DESTROY" }, { WM_MOVE, "WM_MOVE" }, { WM_SIZE, "WM_SIZE" }, { WM_ACTIVATE, "WM_ACTIVATE" }, { WM_SETFOCUS, "WM_SETFOCUS" }, { WM_KILLFOCUS, "WM_KILLFOCUS" }, { WM_ENABLE, "WM_ENABLE" }, { WM_SETREDRAW, "WM_SETREDRAW" }, { WM_SETTEXT, "WM_SETTEXT" }, { WM_GETTEXT, "WM_GETTEXT" }, { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" }, { WM_PAINT, "WM_PAINT" }, { WM_CLOSE, "WM_CLOSE" }, { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" }, { WM_QUIT, "WM_QUIT" }, { WM_QUERYOPEN, "WM_QUERYOPEN" }, { WM_ERASEBKGND, "WM_ERASEBKGND" }, { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" }, { WM_ENDSESSION, "WM_ENDSESSION" }, { WM_SHOWWINDOW, "WM_SHOWWINDOW" }, { WM_WININICHANGE, "WM_WININICHANGE" }, { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" }, { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" }, { WM_FONTCHANGE, "WM_FONTCHANGE" }, { WM_TIMECHANGE, "WM_TIMECHANGE" }, { WM_CANCELMODE, "WM_CANCELMODE" }, { WM_SETCURSOR, "WM_SETCURSOR" }, { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" }, { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" }, { WM_QUEUESYNC, "WM_QUEUESYNC" }, { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" }, { WM_PAINTICON, "WM_PAINTICON" }, { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" }, { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" }, { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" }, { WM_DRAWITEM, "WM_DRAWITEM" }, { WM_MEASUREITEM, "WM_MEASUREITEM" }, { WM_DELETEITEM, "WM_DELETEITEM" }, { WM_VKEYTOITEM, "WM_VKEYTOITEM" }, { WM_CHARTOITEM, "WM_CHARTOITEM" }, { WM_SETFONT, "WM_SETFONT" }, { WM_GETFONT, "WM_GETFONT" }, { WM_SETHOTKEY, "WM_SETHOTKEY" }, { WM_GETHOTKEY, "WM_GETHOTKEY" }, { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" }, { WM_COMPAREITEM, "WM_COMPAREITEM" }, { WM_GETOBJECT, "WM_GETOBJECT" }, { WM_COMPACTING, "WM_COMPACTING" }, { WM_COMMNOTIFY, "WM_COMMNOTIFY" }, { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" }, { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" }, { WM_POWER, "WM_POWER" }, { WM_COPYDATA, "WM_COPYDATA" }, { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" }, { WM_NOTIFY, "WM_NOTIFY" }, { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" }, { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" }, { WM_TCARD, "WM_TCARD" }, { WM_HELP, "WM_HELP" }, { WM_USERCHANGED, "WM_USERCHANGED" }, { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" }, { WM_CONTEXTMENU, "WM_CONTEXTMENU" }, { WM_STYLECHANGING, "WM_STYLECHANGING" }, { WM_STYLECHANGED, "WM_STYLECHANGED" }, { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" }, { WM_GETICON, "WM_GETICON" }, { WM_SETICON, "WM_SETICON" }, { WM_NCCREATE, "WM_NCCREATE" }, { WM_NCDESTROY, "WM_NCDESTROY" }, { WM_NCCALCSIZE, "WM_NCCALCSIZE" }, { WM_NCHITTEST, "WM_NCHITTEST" }, { WM_NCPAINT, "WM_NCPAINT" }, { WM_NCACTIVATE, "WM_NCACTIVATE" }, { WM_GETDLGCODE, "WM_GETDLGCODE" }, { WM_SYNCPAINT, "WM_SYNCPAINT" }, { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" }, { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" }, { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" }, { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" }, { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" }, { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" }, { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" }, { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" }, { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" }, { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" }, { WM_NCXBUTTONDOWN, "WM_NCXBUTTONDOWN" }, { WM_NCXBUTTONUP, "WM_NCXBUTTONUP" }, { WM_NCXBUTTONDBLCLK, "WM_NCXBUTTONDBLCLK" }, { WM_INPUT_DEVICE_CHANGE, "WM_INPUT_DEVICE_CHANGE" }, { WM_INPUT, "WM_INPUT" }, { WM_KEYDOWN, "WM_KEYDOWN" }, { WM_KEYUP, "WM_KEYUP" }, { WM_CHAR, "WM_CHAR" }, { WM_DEADCHAR, "WM_DEADCHAR" }, { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" }, { WM_SYSKEYUP, "WM_SYSKEYUP" }, { WM_SYSCHAR, "WM_SYSCHAR" }, { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" }, { WM_KEYLAST, "WM_KEYLAST" }, { WM_INITDIALOG, "WM_INITDIALOG" }, { WM_COMMAND, "WM_COMMAND" }, { WM_SYSCOMMAND, "WM_SYSCOMMAND" }, { WM_TIMER, "WM_TIMER" }, { WM_HSCROLL, "WM_HSCROLL" }, { WM_VSCROLL, "WM_VSCROLL" }, { WM_INITMENU, "WM_INITMENU" }, { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" }, { WM_GESTURE, "WM_GESTURE" }, { WM_GESTURENOTIFY, "WM_GESTURENOTIFY" }, { WM_MENUSELECT, "WM_MENUSELECT" }, { WM_MENUCHAR, "WM_MENUCHAR" }, { WM_ENTERIDLE, "WM_ENTERIDLE" }, { WM_MENURBUTTONUP, "WM_MENURBUTTONUP" }, { WM_MENUDRAG, "WM_MENUDRAG" }, { WM_MENUGETOBJECT, "WM_MENUGETOBJECT" }, { WM_UNINITMENUPOPUP, "WM_UNINITMENUPOPUP" }, { WM_MENUCOMMAND, "WM_MENUCOMMAND" }, { WM_CHANGEUISTATE, "WM_CHANGEUISTATE" }, { WM_UPDATEUISTATE, "WM_UPDATEUISTATE" }, { WM_QUERYUISTATE, "WM_QUERYUISTATE" }, { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" }, { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" }, { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" }, { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" }, { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" }, { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" }, { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" }, { MN_GETHMENU, "MN_GETHMENU" }, { WM_MOUSEMOVE, "WM_MOUSEMOVE" }, { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" }, { WM_LBUTTONUP, "WM_LBUTTONUP" }, { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" }, { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" }, { WM_RBUTTONUP, "WM_RBUTTONUP" }, { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" }, { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" }, { WM_MBUTTONUP, "WM_MBUTTONUP" }, { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" }, { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" }, { WM_XBUTTONDOWN, "WM_XBUTTONDOWN" }, { WM_XBUTTONUP, "WM_XBUTTONUP" }, { WM_XBUTTONDBLCLK, "WM_XBUTTONDBLCLK" }, { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" }, { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" }, { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" }, { WM_EXITMENULOOP, "WM_EXITMENULOOP" }, { WM_NEXTMENU, "WM_NEXTMENU" }, { WM_SIZING, "WM_SIZING" }, { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" }, { WM_MOVING, "WM_MOVING" }, { WM_POWERBROADCAST, "WM_POWERBROADCAST" }, { WM_DEVICECHANGE, "WM_DEVICECHANGE" }, { WM_MDICREATE, "WM_MDICREATE" }, { WM_MDIDESTROY, "WM_MDIDESTROY" }, { WM_MDIACTIVATE, "WM_MDIACTIVATE" }, { WM_MDIRESTORE, "WM_MDIRESTORE" }, { WM_MDINEXT, "WM_MDINEXT" }, { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" }, { WM_MDITILE, "WM_MDITILE" }, { WM_MDICASCADE, "WM_MDICASCADE" }, { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" }, { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" }, { WM_MDISETMENU, "WM_MDISETMENU" }, { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" }, { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" }, { WM_DROPFILES, "WM_DROPFILES" }, { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" }, { WM_POINTERDEVICECHANGE, "WM_POINTERDEVICECHANGE" }, { WM_POINTERDEVICEINRANGE, "WM_POINTERDEVICEINRANGE" }, { WM_POINTERDEVICEOUTOFRANGE, "WM_POINTERDEVICEOUTOFRANGE" }, { WM_TOUCH, "WM_TOUCH" }, { WM_NCPOINTERUPDATE, "WM_NCPOINTERUPDATE" }, { WM_NCPOINTERDOWN, "WM_NCPOINTERDOWN" }, { WM_NCPOINTERUP, "WM_NCPOINTERUP" }, { WM_POINTERUPDATE, "WM_POINTERUPDATE" }, { WM_POINTERDOWN, "WM_POINTERDOWN" }, { WM_POINTERUP, "WM_POINTERUP" }, { WM_POINTERENTER, "WM_POINTERENTER" }, { WM_POINTERLEAVE, "WM_POINTERLEAVE" }, { WM_POINTERACTIVATE, "WM_POINTERACTIVATE" }, { WM_POINTERCAPTURECHANGED, "WM_POINTERCAPTURECHANGED" }, { WM_TOUCHHITTESTING, "WM_TOUCHHITTESTING" }, { WM_POINTERWHEEL, "WM_POINTERWHEEL" }, { WM_POINTERHWHEEL, "WM_POINTERHWHEEL" }, { DM_POINTERHITTEST, "DM_POINTERHITTEST" }, { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" }, { WM_IME_NOTIFY, "WM_IME_NOTIFY" }, { WM_IME_CONTROL, "WM_IME_CONTROL" }, { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" }, { WM_IME_SELECT, "WM_IME_SELECT" }, { WM_IME_CHAR, "WM_IME_CHAR" }, { WM_IME_REQUEST, "WM_IME_REQUEST" }, { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" }, { WM_IME_KEYUP, "WM_IME_KEYUP" }, { WM_MOUSEENTER, "WM_MOUSEENTER" }, { WM_MOUSEHOVER, "WM_MOUSEHOVER" }, { WM_MOUSELEAVE, "WM_MOUSELEAVE" }, { WM_NCMOUSEHOVER, "WM_NCMOUSEHOVER" }, { WM_NCMOUSELEAVE, "WM_NCMOUSELEAVE" }, { WM_WTSSESSION_CHANGE, "WM_WTSSESSION_CHANGE" }, { WM_TABLET_FIRST, "WM_TABLET_FIRST" }, { WM_TABLET_LAST, "WM_TABLET_LAST" }, { WM_DPICHANGED, "WM_DPICHANGED" }, { WM_CUT, "WM_CUT" }, { WM_COPY, "WM_COPY" }, { WM_PASTE, "WM_PASTE" }, { WM_CLEAR, "WM_CLEAR" }, { WM_UNDO, "WM_UNDO" }, { WM_RENDERFORMAT, "WM_RENDERFORMAT" }, { WM_RENDERALLFORMATS, "WM_RENDERALLFORMATS" }, { WM_DESTROYCLIPBOARD, "WM_DESTROYCLIPBOARD" }, { WM_DRAWCLIPBOARD, "WM_DRAWCLIPBOARD" }, { WM_PAINTCLIPBOARD, "WM_PAINTCLIPBOARD" }, { WM_VSCROLLCLIPBOARD, "WM_VSCROLLCLIPBOARD" }, { WM_SIZECLIPBOARD, "WM_SIZECLIPBOARD" }, { WM_ASKCBFORMATNAME, "WM_ASKCBFORMATNAME" }, { WM_CHANGECBCHAIN, "WM_CHANGECBCHAIN" }, { WM_HSCROLLCLIPBOARD, "WM_HSCROLLCLIPBOARD" }, { WM_QUERYNEWPALETTE, "WM_QUERYNEWPALETTE" }, { WM_PALETTEISCHANGING, "WM_PALETTEISCHANGING" }, { WM_PALETTECHANGED, "WM_PALETTECHANGED" }, { WM_HOTKEY, "WM_HOTKEY" }, { WM_PRINT, "WM_PRINT" }, { WM_PRINTCLIENT, "WM_PRINTCLIENT" }, { WM_APPCOMMAND, "WM_APPCOMMAND" }, { WM_THEMECHANGED, "WM_THEMECHANGED" }, { WM_CLIPBOARDUPDATE, "WM_CLIPBOARDUPDATE" }, { WM_DWMCOMPOSITIONCHANGED, "WM_DWMCOMPOSITIONCHANGED" }, { WM_DWMNCRENDERINGCHANGED, "WM_DWMNCRENDERINGCHANGED" }, { WM_DWMCOLORIZATIONCOLORCHANGED, "WM_DWMCOLORIZATIONCOLORCHANGED" }, { WM_DWMWINDOWMAXIMIZEDCHANGE, "WM_DWMWINDOWMAXIMIZEDCHANGE" }, { WM_DWMSENDICONICTHUMBNAIL, "WM_DWMSENDICONICTHUMBNAIL" }, { WM_DWMSENDICONICLIVEPREVIEWBITMAP, "WM_DWMSENDICONICLIVEPREVIEWBITMAP" }, { WM_GETTITLEBARINFOEX, "WM_GETTITLEBARINFOEX" }, { WM_HANDHELDFIRST, "WM_HANDHELDFIRST" }, { WM_HANDHELDLAST, "WM_HANDHELDLAST" }, { WM_AFXFIRST, "WM_AFXFIRST" }, { WM_AFXLAST, "WM_AFXLAST" }, { WM_PENWINFIRST, "WM_PENWINFIRST" }, { WM_PENWINLAST, "WM_PENWINLAST" }, { WM_USER, "WM_USER" }, { WM_APP, "WM_APP" }, { WM_APPIDLE, "WM_APPIDLE" }, { WM_STYLE_SHEET_CHANGED, "WM_STYLE_SHEET_CHANGED" }, { WM_MOUSEENTER, "WM_MOUSEENTER" }, { WM_RECREATE, "WM_RECREATE" }, { WM_REFLECT + WM_CTLCOLORDLG, "WM_REFLECT + WM_CTLCOLORDLG"}, { WM_REFLECT + WM_CTLCOLORMSGBOX, "WM_REFLECT + WM_CTLCOLORMSGBOX"}, { WM_REFLECT + WM_CTLCOLOR, "WM_REFLECT + WM_CTLCOLOR"}, { WM_REFLECT + WM_CTLCOLORBTN, "WM_REFLECT + WM_CTLCOLORBTN"}, { WM_REFLECT + WM_CTLCOLORSCROLLBAR, "WM_REFLECT + WM_CTLCOLORSCROLLBAR"}, { WM_REFLECT + WM_CTLCOLOREDIT, "WM_REFLECT + WM_CTLCOLOREDIT"}, { WM_REFLECT + WM_CTLCOLORLISTBOX, "WM_REFLECT + WM_CTLCOLORLISTBOX"}, { WM_REFLECT + WM_CTLCOLORSTATIC, "WM_REFLECT + WM_CTLCOLORSTATIC"}, { WM_REFLECT + WM_COMMAND, "WM_REFLECT + WM_COMMAND"}, { WM_REFLECT + WM_NOTIFY, "WM_REFLECT + WM_NOTIFY"}, { WM_REFLECT + WM_HSCROLL, "WM_REFLECT + WM_HSCROLL"}, { WM_REFLECT + WM_VSCROLL, "WM_REFLECT + WM_VSCROLL"},};
          auto it = ids.find(id);
          if (it != ids.end()) return it->second;
          return ustring::format("{}", id);
        }
        /// @}
      };
    }
  }
}
