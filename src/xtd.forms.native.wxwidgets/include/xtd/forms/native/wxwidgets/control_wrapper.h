#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <functional>
#include <memory>
#include <set>
#include <thread>
#include <xtd/delegate.h>
#include <xtd/object.h>
#include <xtd/diagnostics/debug.h>
#include <xtd/drawing/size.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/wx_application.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/mouse_key.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#include <xtd/forms/native/virtual_keys.h>
#include <xtd/forms/native/window_styles.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/collpane.h>
#include <wx/clrpicker.h>
#include <wx/dateevt.h>
#include <wx/event.h>
#include <wx/fontpicker.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/notebook.h>
#include <wx/radiobut.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
#include <wx/tglbtn.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler;
      
      template<typename control_t>
      class control_wrapper : public control_t {
        friend control_handler;
      protected:
        template<typename ...args_type>
        control_wrapper(control_handler* event_handler, args_type&& ...args) : control_t(args...), event_handler_(event_handler) {}

        ~control_wrapper();

        intptr_t def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {
          if (handle != 0) {
            wxEvent* event = reinterpret_cast<wxEvent*>(handle);
            event->Skip(!result);
            process_result_ = control_t::ProcessEvent(*event);
          }
          return process_result_;
        }

      private:
        static std::string to_string(const wxEventType& eventType) {
          static std::map<wxEventType, std::string> eventTypes{
            {wxEVT_NULL, "EVT_NULL"},
            {wxEVT_BUTTON, "wxEVT_BUTTON"}, {wxEVT_CHECKBOX, "wxEVT_CHECKBOX"}, {wxEVT_CHOICE, "wxEVT_CHOICE"}, {wxEVT_COLLAPSIBLEPANE_CHANGED, "wxEVT_COLLAPSIBLEPANE_CHANGED"}, {wxEVT_LISTBOX, "wxEVT_LISTBOX"}, {wxEVT_LISTBOX_DCLICK, "wxEVT_LISTBOX_DCLICK"}, {wxEVT_CHECKLISTBOX, "wxEVT_CHECKLISTBOX"}, {wxEVT_MENU, "wxEVT_MENU"}, {wxEVT_SLIDER, "wxEVT_SLIDER"}, {wxEVT_RADIOBOX, "wxEVT_RADIOBOX"}, {wxEVT_RADIOBUTTON, "wxEVT_RADIOBUTTON"},
            {wxEVT_SCROLLBAR, "wxEVT_SCROLLBAR"}, {wxEVT_VLBOX, "wxEVT_VLBOX"}, {wxEVT_COMBOBOX, "wxEVT_COMBOBOX"}, {wxEVT_TOOL_RCLICKED, "wxEVT_TOOL_RCLICKED"}, {wxEVT_TOOL_DROPDOWN, "wxEVT_TOOL_DROPDOWN"}, {wxEVT_TOOL_ENTER, "wxEVT_TOOL_ENTER"}, {wxEVT_COMBOBOX_DROPDOWN, "wxEVT_COMBOBOX_DROPDOWN"}, {wxEVT_COMBOBOX_CLOSEUP, "wxEVT_COMBOBOX_CLOSEUP"},
            {wxEVT_THREAD, "wxEVT_THREAD"}, {wxEVT_ASYNC_METHOD_CALL, "wxEVT_ASYNC_METHOD_CALL"},
            {wxEVT_LEFT_DOWN, "wxEVT_LEFT_DOWN"}, {wxEVT_LEFT_UP, "wxEVT_LEFT_UP"}, {wxEVT_MIDDLE_DOWN, "wxEVT_MIDDLE_DOWN"}, {wxEVT_MIDDLE_UP, "wxEVT_MIDDLE_UP"}, {wxEVT_RIGHT_DOWN, "wxEVT_RIGHT_DOWN"}, {wxEVT_RIGHT_UP, "wxEVT_RIGHT_UP"}, {wxEVT_MOTION, "wxEVT_MOTION"}, {wxEVT_ENTER_WINDOW, "wxEVT_ENTER_WINDOW"}, {wxEVT_LEAVE_WINDOW, "wxEVT_LEAVE_WINDOW"}, {wxEVT_LEFT_DCLICK, "wxEVT_LEFT_DCLICK"}, {wxEVT_MIDDLE_DCLICK, "wxEVT_MIDDLE_DCLICK"}, {wxEVT_RIGHT_DCLICK, "wxEVT_RIGHT_DCLICK"}, {wxEVT_SET_FOCUS, "wxEVT_SET_FOCUS"}, {wxEVT_KILL_FOCUS, "wxEVT_KILL_FOCUS"}, {wxEVT_CHILD_FOCUS, "wxEVT_CHILD_FOCUS"}, {wxEVT_MOUSEWHEEL, "wxEVT_MOUSEWHEEL"}, {wxEVT_AUX1_DOWN, "wxEVT_AUX1_DOWN"}, {wxEVT_AUX1_UP, "wxEVT_AUX1_UP"}, {wxEVT_AUX1_DCLICK, "wxEVT_AUX1_DCLICK"}, {wxEVT_AUX2_DOWN, "wxEVT_AUX2_DOWN"}, {wxEVT_AUX2_UP, "wxEVT_AUX2_UP"}, {wxEVT_AUX2_DCLICK, "wxEVT_AUX2_DCLICK"}, {wxEVT_MAGNIFY, "wxEVT_MAGNIFY"},
            {wxEVT_CHAR, "wxEVT_CHAR"}, {wxEVT_CHAR_HOOK, "wxEVT_CHAR_HOOK"}, {wxEVT_NAVIGATION_KEY, "wxEVT_NAVIGATION_KEY"}, {wxEVT_KEY_DOWN, "wxEVT_KEY_DOWN"}, {wxEVT_KEY_UP, "wxEVT_KEY_UP"},
            {wxEVT_AFTER_CHAR, "wxEVT_AFTER_CHAR"},
            {wxEVT_SET_CURSOR, "wxEVT_SET_CURSOR"},
            {wxEVT_SCROLL_TOP, "wxEVT_SCROLL_TOP"}, {wxEVT_SCROLL_BOTTOM, "wxEVT_SCROLL_BOTTOM"}, {wxEVT_SCROLL_LINEUP, "wxEVT_SCROLL_LINEUP"}, {wxEVT_SCROLL_LINEDOWN, "wxEVT_SCROLL_LINEDOWN"}, {wxEVT_SCROLL_PAGEUP, "wxEVT_SCROLL_PAGEUP"}, {wxEVT_SCROLL_PAGEDOWN, "wxEVT_SCROLL_PAGEDOWN"}, {wxEVT_SCROLL_THUMBTRACK, "wxEVT_SCROLL_THUMBTRACK"}, {wxEVT_SCROLL_THUMBRELEASE, "wxEVT_SCROLL_THUMBRELEASE"}, {wxEVT_SCROLL_CHANGED, "wxEVT_SCROLL_CHANGED"}, {wxEVT_SPIN_UP, "wxEVT_SPIN_UP"}, {wxEVT_SPIN_DOWN, "wxEVT_SPIN_DOWN"}, {wxEVT_SPIN, "wxEVT_SPIN"},
            {wxEVT_SCROLLWIN_TOP, "wxEVT_SCROLLWIN_TOP"}, {wxEVT_SCROLLWIN_BOTTOM, "wxEVT_SCROLLWIN_BOTTOM"}, {wxEVT_SCROLLWIN_LINEUP, "wxEVT_SCROLLWIN_LINEUP"}, {wxEVT_SCROLLWIN_LINEDOWN, "wxEVT_SCROLLWIN_LINEDOWN"}, {wxEVT_SCROLLWIN_PAGEUP, "wxEVT_SCROLLWIN_PAGEUP"}, {wxEVT_SCROLLWIN_PAGEDOWN, "wxEVT_SCROLLWIN_PAGEDOWN"}, {wxEVT_SCROLLWIN_THUMBTRACK, "wxEVT_SCROLLWIN_THUMBTRACK"}, {wxEVT_SCROLLWIN_THUMBRELEASE, "wxEVT_SCROLLWIN_THUMBRELEASE"}, {wxEVT_SCROLL_CHANGED, "wxEVT_SCROLL_CHANGED"},
            {wxEVT_GESTURE_PAN, "wxEVT_GESTURE_PAN"}, {wxEVT_GESTURE_ZOOM, "wxEVT_GESTURE_ZOOM"}, {wxEVT_GESTURE_ROTATE, "wxEVT_GESTURE_ROTATE"}, {wxEVT_TWO_FINGER_TAP, "wxEVT_TWO_FINGER_TAP"}, {wxEVT_LONG_PRESS, "wxEVT_LONG_PRESS"}, {wxEVT_PRESS_AND_TAP, "wxEVT_PRESS_AND_TAP"},
            {wxEVT_SIZE, "wxEVT_SIZE"}, {wxEVT_MOVE, "wxEVT_MOVE"}, {wxEVT_CLOSE_WINDOW, "wxEVT_CLOSE_WINDOW"}, {wxEVT_END_SESSION, "wxEVT_END_SESSION"}, {wxEVT_QUERY_END_SESSION, "wxEVT_QUERY_END_SESSION"}, {wxEVT_ACTIVATE_APP, "wxEVT_ACTIVATE_APP"}, {wxEVT_ACTIVATE, "wxEVT_ACTIVATE"}, {wxEVT_CREATE, "wxEVT_CREATE"}, {wxEVT_DESTROY, "wxEVT_DESTROY"}, {wxEVT_SHOW, "wxEVT_SHOW"}, {wxEVT_ICONIZE, "wxEVT_ICONIZE"}, {wxEVT_MAXIMIZE, "wxEVT_MAXIMIZE"}, {wxEVT_MOUSE_CAPTURE_CHANGED, "wxEVT_MOUSE_CAPTURE_CHANGED"}, {wxEVT_MOUSE_CAPTURE_LOST, "wxEVT_MOUSE_CAPTURE_LOST"}, {wxEVT_PAINT, "wxEVT_PAINT"}, {wxEVT_ERASE_BACKGROUND, "wxEVT_ERASE_BACKGROUND"}, {wxEVT_NC_PAINT, "wxEVT_NC_PAINT"}, {wxEVT_MENU_OPEN, "wxEVT_MENU_OPEN"}, {wxEVT_MENU_CLOSE, "wxEVT_MENU_CLOSE"}, {wxEVT_MENU_HIGHLIGHT, "wxEVT_MENU_HIGHLIGHT"}, {wxEVT_CONTEXT_MENU, "wxEVT_CONTEXT_MENU"}, {wxEVT_SYS_COLOUR_CHANGED, "wxEVT_SYS_COLOUR_CHANGED"}, {wxEVT_DISPLAY_CHANGED, "wxEVT_DISPLAY_CHANGED"}, {wxEVT_QUERY_NEW_PALETTE, "wxEVT_QUERY_NEW_PALETTE"}, {wxEVT_PALETTE_CHANGED, "wxEVT_PALETTE_CHANGED"}, {wxEVT_JOY_BUTTON_DOWN, "wxEVT_JOY_BUTTON_DOWN"}, {wxEVT_JOY_BUTTON_UP, "wxEVT_JOY_BUTTON_UP"}, {wxEVT_JOY_MOVE, "wxEVT_JOY_MOVE"}, {wxEVT_JOY_ZMOVE, "wxEVT_JOY_ZMOVE"}, {wxEVT_DROP_FILES, "wxEVT_DROP_FILES"}, {wxEVT_INIT_DIALOG, "wxEVT_INIT_DIALOG"}, {wxEVT_IDLE, "wxEVT_IDLE"}, {wxEVT_UPDATE_UI, "wxEVT_UPDATE_UI"}, {wxEVT_SIZING, "wxEVT_SIZING"}, {wxEVT_MOVING, "wxEVT_MOVING"}, {wxEVT_MOVE_START, "wxEVT_MOVE_START"}, {wxEVT_MOVE_END, "wxEVT_MOVE_END"}, {wxEVT_HIBERNATE, "wxEVT_HIBERNATE"},
            {wxEVT_TEXT_COPY, "wxEVT_TEXT_COPY"}, {wxEVT_TEXT_CUT, "wxEVT_TEXT_CUT"}, {wxEVT_TEXT_PASTE, "wxEVT_TEXT_PASTE"},
            {wxEVT_COMMAND_LEFT_CLICK, "wxEVT_COMMAND_LEFT_CLICK"}, {wxEVT_COMMAND_LEFT_DCLICK, "wxEVT_COMMAND_LEFT_DCLICK"}, {wxEVT_COMMAND_RIGHT_CLICK, "wxEVT_COMMAND_RIGHT_CLICK"}, {wxEVT_COMMAND_RIGHT_DCLICK, "wxEVT_COMMAND_RIGHT_DCLICK"}, {wxEVT_COMMAND_SET_FOCUS, "wxEVT_COMMAND_SET_FOCUS"}, {wxEVT_COMMAND_KILL_FOCUS, "wxEVT_COMMAND_KILL_FOCUS"}, {wxEVT_COMMAND_ENTER, "wxEVT_COMMAND_ENTER"},
            {wxEVT_HELP, "wxEVT_HELP"}, {wxEVT_DETAILED_HELP, "wxEVT_DETAILED_HELP"},};
          auto it = eventTypes.find(eventType);
          return ustring::format("{} (0x{:X})", it == eventTypes.end() ? "<Unknown>" : it->second, eventType);
        }

        static std::string to_string(const wxEvent& event) {
          return ustring::format("{} {{type={}, id={}}}", ustring::full_class_name(event), to_string(event.GetEventType()), event.GetId());
        }

        void def_process_event(intptr_t result, wxEvent& event) {
          process_result_ = def_wnd_proc(0, 0, 0, 0, result, reinterpret_cast<intptr_t>(&event));
        }

        void def_process_event(wxEvent& event) {
          def_process_event(0, event);
        }

        bool is_clipboard_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_TEXT_COPY, wxEVT_TEXT_CUT, wxEVT_TEXT_PASTE};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_command_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_BUTTON, wxEVT_CHECKBOX, wxEVT_CHOICE, wxEVT_COLLAPSIBLEPANE_CHANGED, wxEVT_COLOURPICKER_CHANGED, wxEVT_DATE_CHANGED, wxEVT_FONTPICKER_CHANGED, wxEVT_LISTBOX, wxEVT_NOTEBOOK_PAGE_CHANGED, wxEVT_LISTBOX_DCLICK, wxEVT_CHECKLISTBOX, wxEVT_MENU, wxEVT_SLIDER, wxEVT_SPINCTRLDOUBLE, wxEVT_RADIOBOX, wxEVT_RADIOBUTTON, wxEVT_SCROLLBAR, wxEVT_VLBOX, wxEVT_COMBOBOX, wxEVT_TOOL_RCLICKED, wxEVT_TIME_CHANGED, wxEVT_TOOL_DROPDOWN, wxEVT_TOOL_ENTER, wxEVT_COMBOBOX_DROPDOWN, wxEVT_COMBOBOX_CLOSEUP};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_cursor_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_SET_CURSOR};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_generic_command_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_COMMAND_LEFT_CLICK, wxEVT_COMMAND_LEFT_DCLICK, wxEVT_COMMAND_RIGHT_CLICK, wxEVT_COMMAND_RIGHT_DCLICK, wxEVT_COMMAND_SET_FOCUS, wxEVT_COMMAND_KILL_FOCUS, wxEVT_COMMAND_ENTER};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_gesture_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_GESTURE_PAN, wxEVT_GESTURE_ZOOM, wxEVT_GESTURE_ROTATE, wxEVT_TWO_FINGER_TAP, wxEVT_LONG_PRESS, wxEVT_PRESS_AND_TAP};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_help_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_HELP, wxEVT_DETAILED_HELP};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_key_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_CHAR, wxEVT_CHAR_HOOK, wxEVT_NAVIGATION_KEY, wxEVT_KEY_DOWN, wxEVT_KEY_UP, wxEVT_AFTER_CHAR};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_mouse_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_LEFT_DOWN, wxEVT_LEFT_UP, wxEVT_MIDDLE_DOWN, wxEVT_MIDDLE_UP, wxEVT_RIGHT_DOWN, wxEVT_RIGHT_UP, wxEVT_MOTION, wxEVT_ENTER_WINDOW, wxEVT_LEAVE_WINDOW, wxEVT_LEFT_DCLICK, wxEVT_MIDDLE_DCLICK, wxEVT_RIGHT_DCLICK, wxEVT_SET_FOCUS, wxEVT_KILL_FOCUS, wxEVT_CHILD_FOCUS, wxEVT_MOUSEWHEEL, wxEVT_AUX1_DOWN, wxEVT_AUX1_UP, wxEVT_AUX1_DCLICK, wxEVT_AUX2_DOWN, wxEVT_AUX2_UP, wxEVT_AUX2_DCLICK, wxEVT_MAGNIFY};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_scroll_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_SCROLLWIN_TOP, wxEVT_SCROLLWIN_BOTTOM, wxEVT_SCROLLWIN_LINEUP, wxEVT_SCROLLWIN_LINEDOWN, wxEVT_SCROLLWIN_PAGEUP, wxEVT_SCROLLWIN_PAGEDOWN, wxEVT_SCROLLWIN_THUMBTRACK, wxEVT_SCROLLWIN_THUMBRELEASE};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_scrollbar_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_SCROLL_TOP, wxEVT_SCROLL_BOTTOM, wxEVT_SCROLL_LINEUP, wxEVT_SCROLL_LINEDOWN, wxEVT_SCROLL_PAGEUP, wxEVT_SCROLL_PAGEDOWN, wxEVT_SCROLL_THUMBTRACK, wxEVT_SCROLL_THUMBRELEASE,  wxEVT_SCROLL_CHANGED};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_spin_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_SPIN_UP, wxEVT_SPIN_DOWN, wxEVT_SPIN};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_system_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_SIZE, wxEVT_MOVE, wxEVT_CLOSE_WINDOW, wxEVT_END_SESSION, wxEVT_QUERY_END_SESSION, wxEVT_ACTIVATE_APP, wxEVT_ACTIVATE, wxEVT_CREATE, wxEVT_DESTROY, wxEVT_SHOW, wxEVT_ICONIZE, wxEVT_MAXIMIZE, wxEVT_MOUSE_CAPTURE_CHANGED, wxEVT_MOUSE_CAPTURE_LOST, wxEVT_PAINT, wxEVT_ERASE_BACKGROUND, wxEVT_NC_PAINT, wxEVT_MENU_OPEN, wxEVT_MENU_CLOSE, wxEVT_MENU_HIGHLIGHT, wxEVT_CONTEXT_MENU, wxEVT_SYS_COLOUR_CHANGED, wxEVT_DISPLAY_CHANGED, wxEVT_QUERY_NEW_PALETTE, wxEVT_PALETTE_CHANGED, wxEVT_JOY_BUTTON_DOWN, wxEVT_JOY_BUTTON_UP, wxEVT_JOY_MOVE, wxEVT_JOY_ZMOVE, wxEVT_DROP_FILES, wxEVT_INIT_DIALOG, wxEVT_IDLE, wxEVT_UPDATE_UI, wxEVT_SIZING, wxEVT_MOVING, wxEVT_MOVE_START, wxEVT_MOVE_END, wxEVT_HIBERNATE};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_text_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_TEXT, wxEVT_TEXT_ENTER, wxEVT_TEXT_URL, wxEVT_TEXT_MAXLEN};
          return event_types.find(event_type) != event_types.end();
        }

        bool is_thread_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_THREAD, wxEVT_ASYNC_METHOD_CALL};
          return event_types.find(event_type) != event_types.end();
        }

        intptr_t convert_to_virtual_key(const wxKeyEvent& key_event) {
          intptr_t key_data = VK_NONE;
          if (key_event.GetUnicodeKey() != WXK_NONE && key_event.GetUnicodeKey() != WXK_DELETE)
            key_data = static_cast<intptr_t>(key_event.GetUnicodeKey());
          else {
            switch (key_event.GetKeyCode()) {
            case WXK_NONE:
#if defined(__APPLE__)
              if (key_event.GetRawKeyCode() == functionRawKeyCode) key_data = VK_FUNCTION;
#endif
              break;
            case WXK_BACK: key_data = VK_BACK; break;
            case WXK_TAB: key_data = VK_TAB; break;
            case WXK_RETURN: key_data = VK_RETURN; break;
            case WXK_ESCAPE: key_data = VK_ESCAPE; break;
            case WXK_SPACE: key_data = VK_SPACE; break;
            case WXK_DELETE: key_data = VK_DELETE; break;
            case WXK_START: key_data = VK_LAUNCH_APP1; break;
            case WXK_LBUTTON: key_data = VK_LBUTTON; break;
            case WXK_RBUTTON: key_data = VK_RBUTTON; break;
            case WXK_CANCEL: key_data = VK_CANCEL; break;
            case WXK_MBUTTON: key_data = VK_MBUTTON; break;
            case WXK_CLEAR: key_data = VK_CLEAR; break;
            case WXK_SHIFT: key_data = VK_SHIFT; break;
            case WXK_ALT: key_data = VK_MENU; break;
#if defined(__APPLE__)
            case WXK_RAW_CONTROL: key_data = VK_CONTROL; break;
            case WXK_CONTROL: key_data = VK_COMMAND; break;
#else
            case WXK_CONTROL: key_data = VK_CONTROL; break;
#endif
            case WXK_MENU: key_data = VK_MENU; break;
            case WXK_PAUSE: key_data = VK_PAUSE; break;
            case WXK_CAPITAL: key_data = VK_CAPITAL; break;
            case WXK_END: key_data = VK_END; break;
            case WXK_HOME: key_data = VK_HOME; break;
            case WXK_LEFT: key_data = VK_LEFT; break;
            case WXK_UP: key_data = VK_UP; break;
            case WXK_RIGHT: key_data = VK_RIGHT; break;
            case WXK_DOWN: key_data = VK_DOWN; break;
            case WXK_SELECT: key_data = VK_SELECT; break;
            case WXK_PRINT: key_data = VK_PRINT; break;
            case WXK_EXECUTE: key_data = VK_EXECUTE; break;
            case WXK_SNAPSHOT: key_data = VK_SNAPSHOT; break;
            case WXK_INSERT: key_data = VK_INSERT; break;
            case WXK_HELP: key_data = VK_HELP; break;
            case WXK_NUMPAD0: key_data = VK_NUMPAD0; break;
            case WXK_NUMPAD1: key_data = VK_NUMPAD1; break;
            case WXK_NUMPAD2: key_data = VK_NUMPAD2; break;
            case WXK_NUMPAD3: key_data = VK_NUMPAD3; break;
            case WXK_NUMPAD4: key_data = VK_NUMPAD4; break;
            case WXK_NUMPAD5: key_data = VK_NUMPAD5; break;
            case WXK_NUMPAD6: key_data = VK_NUMPAD6; break;
            case WXK_NUMPAD7: key_data = VK_NUMPAD7; break;
            case WXK_NUMPAD8: key_data = VK_NUMPAD8; break;
            case WXK_NUMPAD9: key_data = VK_NUMPAD9; break;
            case WXK_MULTIPLY: key_data = VK_MULTIPLY; break;
            case WXK_ADD: key_data = VK_ADD; break;
            case WXK_SEPARATOR: key_data = VK_SEPARATOR; break;
            case WXK_DIVIDE: key_data = VK_DIVIDE; break;
            case WXK_F1: key_data = VK_F1; break;
            case WXK_F2: key_data = VK_F2; break;
            case WXK_F3: key_data = VK_F3; break;
            case WXK_F4: key_data = VK_F4; break;
            case WXK_F5: key_data = VK_F5; break;
            case WXK_F6: key_data = VK_F6; break;
            case WXK_F7: key_data = VK_F7; break;
            case WXK_F8: key_data = VK_F8; break;
            case WXK_F9: key_data = VK_F9; break;
            case WXK_F10: key_data = VK_F10; break;
            case WXK_F11: key_data = VK_F11; break;
            case WXK_F12: key_data = VK_F12; break;
            case WXK_F13: key_data = VK_F13; break;
            case WXK_F14: key_data = VK_F14; break;
            case WXK_F15: key_data = VK_F15; break;
            case WXK_F16: key_data = VK_F16; break;
            case WXK_F17: key_data = VK_F17; break;
            case WXK_F18: key_data = VK_F18; break;
            case WXK_F19: key_data = VK_F19; break;
            case WXK_F20: key_data = VK_F20; break;
            case WXK_F21: key_data = VK_F21; break;
            case WXK_F22: key_data = VK_F22; break;
            case WXK_F23: key_data = VK_F23; break;
            case WXK_F24: key_data = VK_F24; break;
            case WXK_NUMLOCK: key_data = VK_NUMLOCK; break;
            case WXK_SCROLL: key_data = VK_SCROLL; break;
            case WXK_PAGEUP: key_data = VK_PAGEUP; break;
            case WXK_PAGEDOWN: key_data = VK_PAGEDOWN; break;
              /// --> num pad special keys
            case WXK_NUMPAD_SPACE: key_data = VK_SPACE; break;
            case WXK_NUMPAD_TAB: key_data = VK_TAB; break;
            case WXK_NUMPAD_ENTER: key_data = VK_RETURN; break;
            case WXK_NUMPAD_F1: key_data = VK_F1; break;
            case WXK_NUMPAD_F2: key_data = VK_F2; break;
            case WXK_NUMPAD_F3: key_data = VK_F3; break;
            case WXK_NUMPAD_F4: key_data = VK_F4; break;
            case WXK_NUMPAD_HOME: key_data = VK_HOME; break;
            case WXK_NUMPAD_LEFT: key_data = VK_LEFT; break;
            case WXK_NUMPAD_UP: key_data = VK_UP; break;
            case WXK_NUMPAD_RIGHT: key_data = VK_RIGHT; break;
            case WXK_NUMPAD_DOWN: key_data = VK_DOWN; break;
            case WXK_NUMPAD_PAGEUP: key_data = VK_PAGEUP; break;
            case WXK_NUMPAD_PAGEDOWN: key_data = VK_PAGEDOWN; break;
            case WXK_NUMPAD_END: key_data = VK_END; break;
            case WXK_NUMPAD_BEGIN: key_data = VK_HOME; break; // ???
            case WXK_NUMPAD_INSERT: key_data = VK_INSERT; break;
            case WXK_NUMPAD_DELETE: key_data = VK_DELETE; break;
            case WXK_NUMPAD_EQUAL: key_data = '='; break;
              /// <-- num pad special keys
            case WXK_NUMPAD_MULTIPLY: key_data = VK_MULTIPLY; break;
            case WXK_NUMPAD_ADD: key_data = VK_ADD; break;
            case WXK_NUMPAD_SEPARATOR: key_data = VK_SEPARATOR; break;
            case WXK_NUMPAD_SUBTRACT: key_data = VK_SUBTRACT; break;
            case WXK_NUMPAD_DECIMAL: key_data = VK_DECIMAL; break;
            case WXK_NUMPAD_DIVIDE: key_data = VK_DIVIDE; break;
            case WXK_WINDOWS_LEFT: key_data = VK_LWIN; break;
            case WXK_WINDOWS_RIGHT: key_data = VK_RWIN; break;
            case WXK_WINDOWS_MENU: key_data = VK_APPS; break;
              //case WXK_RAW_CONTROL: key_data = xtd::forms::keys::control_key; break;
            case WXK_SPECIAL1: key_data = VK_OEM_1; break;
            case WXK_SPECIAL2: key_data = VK_OEM_2; break;
            case WXK_SPECIAL3: key_data = VK_OEM_3; break;
            case WXK_SPECIAL4: key_data = VK_OEM_4; break;
            case WXK_SPECIAL5: key_data = VK_OEM_5; break;
            case WXK_SPECIAL6: key_data = VK_OEM_6; break;
            case WXK_SPECIAL7: key_data = VK_OEM_7; break;
            case WXK_SPECIAL8: key_data = VK_OEM_8; break;
            case WXK_SPECIAL9: key_data = VK_OEM_AX; break;
            case WXK_SPECIAL10: key_data = VK_OEM_102; break;
            case WXK_SPECIAL11: key_data = VK_OEM_RESET; break;
            case WXK_SPECIAL12: key_data = VK_OEM_JUMP; break;
            case WXK_SPECIAL13: key_data = VK_OEM_PA1; break;
            case WXK_SPECIAL14: key_data = VK_OEM_PA2; break;
            case WXK_SPECIAL15: key_data = VK_OEM_PA3; break;
            case WXK_SPECIAL16: key_data = VK_OEM_WSCTRL; break;
            case WXK_SPECIAL17: key_data = VK_OEM_CUSEL; break;
            case WXK_SPECIAL18: key_data = VK_OEM_ATTN; break;
            case WXK_SPECIAL19: key_data = VK_OEM_FINISH; break;
            case WXK_SPECIAL20: key_data = VK_OEM_COPY; break;
            case WXK_BROWSER_BACK: key_data = VK_BROWSER_BACK; break;
            case WXK_BROWSER_FORWARD: key_data = VK_BROWSER_FORWARD; break;
            case WXK_BROWSER_REFRESH: key_data = VK_BROWSER_REFRESH; break;
            case WXK_BROWSER_STOP: key_data = VK_BROWSER_STOP; break;
            case WXK_BROWSER_SEARCH: key_data = VK_BROWSER_SEARCH; break;
            case WXK_BROWSER_FAVORITES: key_data = VK_BROWSER_FAVORITES; break;
            case WXK_BROWSER_HOME: key_data = VK_BROWSER_HOME; break;
            case WXK_VOLUME_MUTE: key_data = VK_VOLUME_MUTE; break;
            case WXK_VOLUME_DOWN: key_data = VK_VOLUME_DOWN; break;
            case WXK_VOLUME_UP: key_data = VK_VOLUME_UP; break;
            case WXK_MEDIA_NEXT_TRACK: key_data = VK_MEDIA_NEXT_TRACK; break;
            case WXK_MEDIA_PREV_TRACK: key_data = VK_MEDIA_PREV_TRACK; break;
            case WXK_MEDIA_STOP: key_data = VK_MEDIA_STOP; break;
            case WXK_MEDIA_PLAY_PAUSE: key_data = VK_MEDIA_PLAY_PAUSE; break;
            case WXK_LAUNCH_MAIL: key_data = VK_LAUNCH_MAIL; break;
            case WXK_LAUNCH_APP1: key_data = VK_LAUNCH_APP1; break;
            case WXK_LAUNCH_APP2: key_data = VK_LAUNCH_APP2; break;
            default: break;
            }
          }

          if ((key_event.GetModifiers() & wxMOD_ALT) == wxMOD_ALT) key_data += VK_ALT_MODIFIER;
#if defined(__APPLE__)
          if ((key_event.GetModifiers() & wxMOD_CONTROL) == wxMOD_CONTROL) key_data += VK_COMMAND_MODIFIER;
          if ((key_event.GetModifiers() & wxMOD_RAW_CONTROL) == wxMOD_RAW_CONTROL) key_data += VK_CONTROL_MODIFIER;
          if (functionKeyModifierIsDown) key_data += VK_FUNCTION_MODIFIER;
#else
          if ((key_event.GetModifiers() & wxMOD_CONTROL) == wxMOD_CONTROL) key_data += VK_CONTROL_MODIFIER;
#endif
          if ((key_event.GetModifiers() & wxMOD_META) == wxMOD_META) key_data += VK_META_MODIFIER;
          if ((key_event.GetModifiers() & wxMOD_SHIFT) == wxMOD_SHIFT) key_data += VK_SHIFT_MODIFIER;

          return key_data;
        }

        bool ProcessEvent(wxEvent& event) override;
        void process_clipboard_event(wxEvent& event);
        void process_command_event(wxEvent& event);
        void process_cursor_event(wxEvent& event);
        void process_generic_command_event(wxEvent& event);
        void process_gesture_event(wxEvent& event);
        void process_help_event(wxEvent& event);
        void process_key_event(wxEvent& event);
        void process_mouse_event(wxEvent& event);
        void process_scroll_event(wxEvent& event);
        void process_scrollbar_event(wxEvent& event);
        void process_spin_event(wxEvent& event);
        void process_system_event(wxEvent& event);
        void process_text_event(wxEvent& event);
        void process_thread_event(wxEvent& event);

        control_handler* event_handler_;
        bool process_result_ = true;
#if defined(__APPLE__)
        static constexpr size_t functionRawKeyCode = 0x0000003F;
#endif
        bool functionKeyModifierIsDown = false;
      };
    }
  }
}
