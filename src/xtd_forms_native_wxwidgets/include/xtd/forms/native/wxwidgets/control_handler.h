#pragma once

#include <cstdint>
#include <memory>
#include <set>
#include <thread>
#include <xtd/xtd.delegates>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/window_messages.h>
#include <xtd/forms/native/message_keys.h>
#include <xtd/forms/native/scroll_bar_styles.h>
#include <xtd/forms/native/virtual_keys.h>
#include <xtd/forms/native/window_styles.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
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
#include "wx_application.h"
#include "wx_menu.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler;
      
      template<typename control_t>
      class control_wrapper : public control_t {
      public:
       template<typename ...args_type>
        control_wrapper(control_handler* event_handler, args_type&& ...args) : control_t(args...), event_handler_(event_handler) {}

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
          static std::map<wxEventType, std::string> eventTypes {
            {wxEVT_NULL, "EVT_NULL"},
            {wxEVT_BUTTON, "wxEVT_BUTTON"}, {wxEVT_CHECKBOX, "wxEVT_CHECKBOX"}, {wxEVT_CHOICE, "wxEVT_CHOICE"}, {wxEVT_LISTBOX, "wxEVT_LISTBOX"}, {wxEVT_LISTBOX_DCLICK, "wxEVT_LISTBOX_DCLICK"}, {wxEVT_CHECKLISTBOX, "wxEVT_CHECKLISTBOX"}, {wxEVT_MENU, "wxEVT_MENU"}, {wxEVT_SLIDER, "wxEVT_SLIDER"}, {wxEVT_RADIOBOX, "wxEVT_RADIOBOX"}, {wxEVT_RADIOBUTTON, "wxEVT_RADIOBUTTON"},
            {wxEVT_SCROLLBAR, "wxEVT_SCROLLBAR"}, {wxEVT_VLBOX, "wxEVT_VLBOX"}, {wxEVT_COMBOBOX, "wxEVT_COMBOBOX"}, {wxEVT_TOOL_RCLICKED, "wxEVT_TOOL_RCLICKED"}, {wxEVT_TOOL_DROPDOWN, "wxEVT_TOOL_DROPDOWN"}, {wxEVT_TOOL_ENTER, "wxEVT_TOOL_ENTER"}, {wxEVT_COMBOBOX_DROPDOWN, "wxEVT_COMBOBOX_DROPDOWN"}, {wxEVT_COMBOBOX_CLOSEUP, "wxEVT_COMBOBOX_CLOSEUP"},
            {wxEVT_THREAD, "wxEVT_THREAD"}, {wxEVT_ASYNC_METHOD_CALL, "wxEVT_ASYNC_METHOD_CALL"},
            {wxEVT_LEFT_DOWN, "wxEVT_LEFT_DOWN"}, {wxEVT_LEFT_UP, "wxEVT_LEFT_UP"}, {wxEVT_MIDDLE_DOWN, "wxEVT_MIDDLE_DOWN"}, {wxEVT_MIDDLE_UP, "wxEVT_MIDDLE_UP"}, {wxEVT_RIGHT_DOWN, "wxEVT_RIGHT_DOWN"}, {wxEVT_RIGHT_UP, "wxEVT_RIGHT_UP"}, {wxEVT_MOTION, "wxEVT_MOTION"}, {wxEVT_ENTER_WINDOW, "wxEVT_ENTER_WINDOW"}, {wxEVT_LEAVE_WINDOW, "wxEVT_LEAVE_WINDOW"}, {wxEVT_LEFT_DCLICK, "wxEVT_LEFT_DCLICK"}, {wxEVT_MIDDLE_DCLICK, "wxEVT_MIDDLE_DCLICK"}, {wxEVT_RIGHT_DCLICK, "wxEVT_RIGHT_DCLICK"}, {wxEVT_SET_FOCUS, "wxEVT_SET_FOCUS"}, {wxEVT_KILL_FOCUS, "wxEVT_KILL_FOCUS"}, {wxEVT_CHILD_FOCUS, "wxEVT_CHILD_FOCUS"}, {wxEVT_MOUSEWHEEL, "wxEVT_MOUSEWHEEL"}, {wxEVT_AUX1_DOWN, "wxEVT_AUX1_DOWN"}, {wxEVT_AUX1_UP, "wxEVT_AUX1_UP"}, {wxEVT_AUX1_DCLICK, "wxEVT_AUX1_DCLICK"}, {wxEVT_AUX2_DOWN, "wxEVT_AUX2_DOWN"}, {wxEVT_AUX2_UP, "wxEVT_AUX2_UP"}, {wxEVT_AUX2_DCLICK, "wxEVT_AUX2_DCLICK"},
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
            {wxEVT_MAGNIFY, "wxEVT_MAGNIFY"},
#endif
            {wxEVT_CHAR, "wxEVT_CHAR"}, {wxEVT_CHAR_HOOK, "wxEVT_CHAR_HOOK"}, {wxEVT_NAVIGATION_KEY, "wxEVT_NAVIGATION_KEY"}, {wxEVT_KEY_DOWN, "wxEVT_KEY_DOWN"}, {wxEVT_KEY_UP, "wxEVT_KEY_UP"},
            {wxEVT_AFTER_CHAR, "wxEVT_AFTER_CHAR"},
            {wxEVT_SET_CURSOR, "wxEVT_SET_CURSOR"},
            {wxEVT_SCROLL_TOP, "wxEVT_SCROLL_TOP"}, {wxEVT_SCROLL_BOTTOM, "wxEVT_SCROLL_BOTTOM"}, {wxEVT_SCROLL_LINEUP, "wxEVT_SCROLL_LINEUP"}, {wxEVT_SCROLL_LINEDOWN, "wxEVT_SCROLL_LINEDOWN"}, {wxEVT_SCROLL_PAGEUP, "wxEVT_SCROLL_PAGEUP"}, {wxEVT_SCROLL_PAGEDOWN, "wxEVT_SCROLL_PAGEDOWN"}, {wxEVT_SCROLL_THUMBTRACK, "wxEVT_SCROLL_THUMBTRACK"}, {wxEVT_SCROLL_THUMBRELEASE, "wxEVT_SCROLL_THUMBRELEASE"}, {wxEVT_SCROLL_CHANGED, "wxEVT_SCROLL_CHANGED"}, {wxEVT_SPIN_UP, "wxEVT_SPIN_UP"}, {wxEVT_SPIN_DOWN, "wxEVT_SPIN_DOWN"}, {wxEVT_SPIN, "wxEVT_SPIN"},
            {wxEVT_SCROLLWIN_TOP, "wxEVT_SCROLLWIN_TOP"}, {wxEVT_SCROLLWIN_BOTTOM, "wxEVT_SCROLLWIN_BOTTOM"}, {wxEVT_SCROLLWIN_LINEUP, "wxEVT_SCROLLWIN_LINEUP"}, {wxEVT_SCROLLWIN_LINEDOWN, "wxEVT_SCROLLWIN_LINEDOWN"}, {wxEVT_SCROLLWIN_PAGEUP, "wxEVT_SCROLLWIN_PAGEUP"}, {wxEVT_SCROLLWIN_PAGEDOWN, "wxEVT_SCROLLWIN_PAGEDOWN"}, {wxEVT_SCROLLWIN_THUMBTRACK, "wxEVT_SCROLLWIN_THUMBTRACK"}, {wxEVT_SCROLLWIN_THUMBRELEASE, "wxEVT_SCROLLWIN_THUMBRELEASE"}, {wxEVT_SCROLL_CHANGED, "wxEVT_SCROLL_CHANGED"},
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
            {wxEVT_GESTURE_PAN, "wxEVT_GESTURE_PAN"}, {wxEVT_GESTURE_ZOOM, "wxEVT_GESTURE_ZOOM"}, {wxEVT_GESTURE_ROTATE, "wxEVT_GESTURE_ROTATE"}, {wxEVT_TWO_FINGER_TAP, "wxEVT_TWO_FINGER_TAP"}, {wxEVT_LONG_PRESS, "wxEVT_LONG_PRESS"}, {wxEVT_PRESS_AND_TAP, "wxEVT_PRESS_AND_TAP"},
#endif
            {wxEVT_SIZE, "wxEVT_SIZE"}, {wxEVT_MOVE, "wxEVT_MOVE"}, {wxEVT_CLOSE_WINDOW, "wxEVT_CLOSE_WINDOW"}, {wxEVT_END_SESSION, "wxEVT_END_SESSION"}, {wxEVT_QUERY_END_SESSION, "wxEVT_QUERY_END_SESSION"}, {wxEVT_ACTIVATE_APP, "wxEVT_ACTIVATE_APP"}, {wxEVT_ACTIVATE, "wxEVT_ACTIVATE"}, {wxEVT_CREATE, "wxEVT_CREATE"}, {wxEVT_DESTROY, "wxEVT_DESTROY"}, {wxEVT_SHOW, "wxEVT_SHOW"}, {wxEVT_ICONIZE, "wxEVT_ICONIZE"}, {wxEVT_MAXIMIZE, "wxEVT_MAXIMIZE"}, {wxEVT_MOUSE_CAPTURE_CHANGED, "wxEVT_MOUSE_CAPTURE_CHANGED"}, {wxEVT_MOUSE_CAPTURE_LOST, "wxEVT_MOUSE_CAPTURE_LOST"}, {wxEVT_PAINT, "wxEVT_PAINT"}, {wxEVT_ERASE_BACKGROUND, "wxEVT_ERASE_BACKGROUND"}, {wxEVT_NC_PAINT, "wxEVT_NC_PAINT"}, {wxEVT_MENU_OPEN, "wxEVT_MENU_OPEN"}, {wxEVT_MENU_CLOSE, "wxEVT_MENU_CLOSE"}, {wxEVT_MENU_HIGHLIGHT, "wxEVT_MENU_HIGHLIGHT"}, {wxEVT_CONTEXT_MENU, "wxEVT_CONTEXT_MENU"}, {wxEVT_SYS_COLOUR_CHANGED, "wxEVT_SYS_COLOUR_CHANGED"}, {wxEVT_DISPLAY_CHANGED, "wxEVT_DISPLAY_CHANGED"}, {wxEVT_QUERY_NEW_PALETTE, "wxEVT_QUERY_NEW_PALETTE"}, {wxEVT_PALETTE_CHANGED, "wxEVT_PALETTE_CHANGED"}, {wxEVT_JOY_BUTTON_DOWN, "wxEVT_JOY_BUTTON_DOWN"}, {wxEVT_JOY_BUTTON_UP, "wxEVT_JOY_BUTTON_UP"}, {wxEVT_JOY_MOVE, "wxEVT_JOY_MOVE"}, {wxEVT_JOY_ZMOVE, "wxEVT_JOY_ZMOVE"}, {wxEVT_DROP_FILES, "wxEVT_DROP_FILES"}, {wxEVT_INIT_DIALOG, "wxEVT_INIT_DIALOG"}, {wxEVT_IDLE, "wxEVT_IDLE"}, {wxEVT_UPDATE_UI, "wxEVT_UPDATE_UI"}, {wxEVT_SIZING, "wxEVT_SIZING"}, {wxEVT_MOVING, "wxEVT_MOVING"}, {wxEVT_MOVE_START, "wxEVT_MOVE_START"}, {wxEVT_MOVE_END, "wxEVT_MOVE_END"}, {wxEVT_HIBERNATE, "wxEVT_HIBERNATE"},
            {wxEVT_TEXT_COPY, "wxEVT_TEXT_COPY"}, {wxEVT_TEXT_CUT, "wxEVT_TEXT_CUT"}, {wxEVT_TEXT_PASTE, "wxEVT_TEXT_PASTE"},
            {wxEVT_COMMAND_LEFT_CLICK, "wxEVT_COMMAND_LEFT_CLICK"}, {wxEVT_COMMAND_LEFT_DCLICK, "wxEVT_COMMAND_LEFT_DCLICK"}, {wxEVT_COMMAND_RIGHT_CLICK, "wxEVT_COMMAND_RIGHT_CLICK"}, {wxEVT_COMMAND_RIGHT_DCLICK, "wxEVT_COMMAND_RIGHT_DCLICK"}, {wxEVT_COMMAND_SET_FOCUS, "wxEVT_COMMAND_SET_FOCUS"}, {wxEVT_COMMAND_KILL_FOCUS, "wxEVT_COMMAND_KILL_FOCUS"}, {wxEVT_COMMAND_ENTER, "wxEVT_COMMAND_ENTER"},
            {wxEVT_HELP, "wxEVT_HELP"}, {wxEVT_DETAILED_HELP, "wxEVT_DETAILED_HELP"},};
          return strings::format("{} (0x{:X})", eventTypes.find(eventType) == eventTypes.end() ? "<Unknown>" : eventTypes[eventType], eventType);
        }

        static std::string to_string(const wxEvent& event) {
          return strings::format("{} {{type={}, id={}}}", strings::full_class_name(event), to_string(event.GetEventType()), event.GetId());
        }

        void def_process_event(wxEvent& event) {
          process_result_ = def_wnd_proc(0, 0, 0, 0, 0, reinterpret_cast<intptr_t>(&event));
        }
        
        bool is_clipboard_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_TEXT_COPY, wxEVT_TEXT_CUT, wxEVT_TEXT_PASTE};
          return event_types.find(event_type) != event_types.end();
        }
        
        bool is_command_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_BUTTON, wxEVT_CHECKBOX, wxEVT_CHOICE, wxEVT_COLOURPICKER_CHANGED, wxEVT_DATE_CHANGED, wxEVT_FONTPICKER_CHANGED, wxEVT_LISTBOX, wxEVT_NOTEBOOK_PAGE_CHANGED, wxEVT_LISTBOX_DCLICK, wxEVT_CHECKLISTBOX, wxEVT_MENU, wxEVT_SLIDER, wxEVT_SPINCTRLDOUBLE, wxEVT_RADIOBOX, wxEVT_RADIOBUTTON, wxEVT_SCROLLBAR, wxEVT_VLBOX, wxEVT_COMBOBOX, wxEVT_TOOL_RCLICKED, wxEVT_TIME_CHANGED, wxEVT_TOOL_DROPDOWN, wxEVT_TOOL_ENTER, wxEVT_COMBOBOX_DROPDOWN, wxEVT_COMBOBOX_CLOSEUP};
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
        
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
        bool is_gesture_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_GESTURE_PAN, wxEVT_GESTURE_ZOOM, wxEVT_GESTURE_ROTATE, wxEVT_TWO_FINGER_TAP, wxEVT_LONG_PRESS, wxEVT_PRESS_AND_TAP};
          return event_types.find(event_type) != event_types.end();
        }
#endif
        
        bool is_help_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_HELP, wxEVT_DETAILED_HELP};
          return event_types.find(event_type) != event_types.end();
        }
        
        bool is_key_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_CHAR, wxEVT_CHAR_HOOK, wxEVT_NAVIGATION_KEY, wxEVT_KEY_DOWN, wxEVT_KEY_UP, wxEVT_AFTER_CHAR};
          return event_types.find(event_type) != event_types.end();
        }
        
        bool is_mouse_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_LEFT_DOWN, wxEVT_LEFT_UP, wxEVT_MIDDLE_DOWN, wxEVT_MIDDLE_UP, wxEVT_RIGHT_DOWN, wxEVT_RIGHT_UP, wxEVT_MOTION, wxEVT_ENTER_WINDOW, wxEVT_LEAVE_WINDOW, wxEVT_LEFT_DCLICK, wxEVT_MIDDLE_DCLICK, wxEVT_RIGHT_DCLICK, wxEVT_SET_FOCUS, wxEVT_KILL_FOCUS, wxEVT_CHILD_FOCUS, wxEVT_MOUSEWHEEL, wxEVT_AUX1_DOWN, wxEVT_AUX1_UP, wxEVT_AUX1_DCLICK, wxEVT_AUX2_DOWN, wxEVT_AUX2_UP, wxEVT_AUX2_DCLICK,
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
            wxEVT_MAGNIFY
#endif
          };
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
          if (key_event.GetUnicodeKey() != WXK_NONE)
            key_data = static_cast<intptr_t>(key_event.GetUnicodeKey());
          else {
            switch (key_event.GetKeyCode()) {
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
#if defined(__WXOSX__)
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
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
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
#endif
              default: break;
            }
          }
          /*
          if (key_event.AltDown()) key_data += VK_ALT_MODIFIER;
#if defined(__WXOSX__)
          if (key_event.CmdDown()) key_data += VK_COMMAND_MODIFIER;
          if (key_event.RawControlDown()) key_data += VK_CONTROL_MODIFIER;
#else
          if (key_event.ControlDown()) key_data += VK_CONTROL_MODIFIER;
#endif
          if (key_event.MetaDown()) key_data += VK_META_MODIFIER;
          if (key_event.ShiftDown()) key_data += VK_SHIFT_MODIFIER;
           */

          if ((key_event.GetModifiers() & wxMOD_ALT) == wxMOD_ALT) key_data += VK_ALT_MODIFIER;
 #if defined(__WXOSX__)
          if ((key_event.GetModifiers() & wxMOD_CONTROL) == wxMOD_CONTROL) key_data += VK_COMMAND_MODIFIER;
          if ((key_event.GetModifiers() & wxMOD_RAW_CONTROL) == wxMOD_RAW_CONTROL) key_data += VK_CONTROL_MODIFIER;
#else
          if ((key_event.GetModifiers() & wxMOD_CONTROL) == wxMOD_CONTROL) key_data += VK_CONTROL_MODIFIER;
#endif
          if ((key_event.GetModifiers() & wxMOD_META) == wxMOD_META) key_data += VK_META_MODIFIER;
          if ((key_event.GetModifiers() & wxMOD_SHIFT) == wxMOD_SHIFT) key_data += VK_SHIFT_MODIFIER;

          return key_data;
        }
        
        bool ProcessEvent(wxEvent &event) override;
        void process_clipboard_event(wxEvent &event);
        void process_command_event(wxEvent &event);
        void process_cursor_event(wxEvent &event);
        void process_generic_command_event(wxEvent &event);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
        void process_gesture_event(wxEvent &event);
#endif
        void process_help_event(wxEvent &event);
        void process_key_event(wxEvent &event);
        void process_mouse_event(wxEvent &event);
        void process_scroll_event(wxEvent &event);
        void process_scrollbar_event(wxEvent &event);
        void process_spin_event(wxEvent &event);
        void process_system_event(wxEvent &event);
        void process_text_event(wxEvent &event);
        void process_thread_event(wxEvent &event);
        
        control_handler* event_handler_;
        bool process_result_ = true;
      };
      
      class control_handler {
      public:
        control_handler() = default;
        virtual ~control_handler() {}

        template<typename control_type, typename ...args_type>
        void create(args_type&& ...args) {
          control_ = new control_wrapper<control_type>(this, args...);
          control_->SetClientData(this);
          destroyed_ = false;
          def_wnd_proc += {static_cast<control_wrapper<control_type>&>(*control_), &control_wrapper<control_type>::def_wnd_proc};
        }
        
        void destroy() {
          destroyed_ = true;
          control_->Destroy();
          //def_wnd_proc -= {static_cast<control_wrapper<control_type>&>(*control_), &control_wrapper<control_type>::def_wnd_proc};
        }

        intptr_t send_message(intptr_t hwnd, intptr_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          if (destroyed_) return 0;
          if (wx_application::message_filter(hwnd, msg, wparam, lparam, handle)) return call_def_wnd_proc(hwnd, msg, wparam, lparam, 1, handle);
          if (wnd_proc.is_empty()) return call_def_wnd_proc(hwnd, msg, wparam, lparam, 0, handle);

          //return wnd_proc(hwnd, msg, wparam, lparam, handle);
          intptr_t result = 0;
          for (auto& fct : wnd_proc.functions())
            if (!destroyed_ && fct != nullptr) result = fct(hwnd, msg, wparam, lparam, handle);
          return result;
        }
        
        virtual void SetBackgroundColour(const wxColour &colour) {
          control_->SetBackgroundColour(colour);
        }
        
        virtual void SetCursor(const wxCursor &cursor) {
          control_->SetCursor(cursor);
        }
        
        virtual void SetForegroundColour(const wxColour &colour) {
          control_->SetForegroundColour(colour);
        }

        virtual void SetPosition(const wxPoint& pt) {
          control_->SetPosition(pt);
        }

        virtual wxSize GetClientSize() const {
          return control_->GetClientSize();
        }
        
        virtual void SetClientSize(int32_t width, int32_t height) {
          control_->SetClientSize(width, height);
        }
        
        virtual void SetSize(int32_t width, int32_t height) {
          control_->SetSize(width, height);
        }

        static long common_window_style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_SUNKEN;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }

        virtual wxWindow* container() const {return control_;}

        wxWindow* control() const {return control_;}
        void clear_control() {control_ = nullptr;}
        
        virtual wxWindow* graphic_control() const {return control_;}

        intptr_t call_def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return def_wnd_proc(hwnd, msg, wparam, lparam, result, handle);}
        
        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t, intptr_t)>> def_wnd_proc;
        
      private:
        wxWindow* control_;
        bool destroyed_ = false;
      };
      
      template<typename control_t>
      inline bool control_wrapper<control_t>::ProcessEvent(wxEvent& event) {
        //diagnostics::debug::write_line_if(event.GetEventType() != wxEVT_UPDATE_UI && event.GetEventType() != wxEVT_IDLE, strings::format("control_wrapper<{}>::ProcessEvent {}", strings::full_class_name<control_t>(), to_string(event)));
        if (event.GetEventType() == wxEVT_DESTROY) {
          def_process_event(event);
          return process_result_;
        }
        
        if (is_clipboard_event(event.GetEventType())) process_clipboard_event(event);
        else if (is_command_event(event.GetEventType())) process_command_event(event);
        else if (is_cursor_event(event.GetEventType())) process_cursor_event(event);
        else if (is_generic_command_event(event.GetEventType())) process_generic_command_event(event);
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
        else if (is_gesture_event(event.GetEventType())) process_gesture_event(event);
#endif
        else if (is_key_event(event.GetEventType())) process_key_event(event);
        else if (is_mouse_event(event.GetEventType())) process_mouse_event(event);
        else if (is_scroll_event(event.GetEventType())) process_scroll_event(event);
        else if (is_scrollbar_event(event.GetEventType())) process_scrollbar_event(event);
        else if (is_spin_event(event.GetEventType())) process_spin_event(event);
        else if (is_system_event(event.GetEventType())) process_system_event(event);
        else if (is_text_event(event.GetEventType())) process_text_event(event);
        else if (is_thread_event(event.GetEventType())) process_thread_event(event);
        else def_process_event(event);
        
        class post_process_event {
        public:
          post_process_event(bool* process_result) : process_result_(process_result) {}
          ~post_process_event() {*process_result_ = true;}
          bool* process_result_;
        } post_process_event(&process_result_);
        
        return process_result_;
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_clipboard_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_command_event(wxEvent& event) {
        //if (event.GetEventType() == wxEVT_BUTTON && (event.GetEventObject() == event.GetPropagatedFrom() || static_cast<wxWindow*>(event.GetEventObject())->GetParent() == event.GetPropagatedFrom())) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED,  event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        if (event.GetEventType() == wxEVT_CHECKBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHECKLISTBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHOICE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COMBOBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COLOURPICKER_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_DATE_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_FONTPICKER_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LISTBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_NOTEBOOK_PAGE_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RADIOBUTTON) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SLIDER) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSL_VERTICAL) == wxSL_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_THUMBPOSITION, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SPINCTRLDOUBLE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, UDN_DELTAPOS, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_TIME_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_TOGGLEBUTTON) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, BN_CLICKED, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MENU) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MENUCOMMAND, wx_menu_bar::find_index_from_id(event.GetId()), reinterpret_cast<intptr_t>(wx_menu_bar::find_menu_from_id(event.GetId())), reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
    
      template<typename control_t>
      inline void control_wrapper<control_t>::process_cursor_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_generic_command_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_help_event(wxEvent& event) {
        def_process_event(event);
      }
      
#if wxMAJOR_VERSION > 3 || (wxMAJOR_VERSION == 3 && wxMINOR_VERSION >= 1)
      template<typename control_t>
      inline void control_wrapper<control_t>::process_gesture_event(wxEvent& event) {
        def_process_event(event);
      }
#endif
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_key_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_KEY_DOWN) event.Skip(!event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_KEYDOWN, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr_t>(&event)));
        else if (event.GetEventType() == wxEVT_CHAR) event.Skip(!event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_CHAR, static_cast<wxKeyEvent&>(event).GetUnicodeKey(), 0, reinterpret_cast<intptr_t>(&event)));
        else if (event.GetEventType() == wxEVT_KEY_UP) event.Skip(!event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_KEYUP, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr_t>(&event)));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_mouse_event(wxEvent& event) {
        wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
        wxMouseState mouse_state = wxGetMouseState();
        int32_t virtual_keys = 0;
        if (mouse_state.ControlDown()) virtual_keys += MK_CONTROL;
        if (mouse_state.ShiftDown()) virtual_keys += MK_SHIFT;
        if (mouse_state.LeftIsDown()) virtual_keys += MK_LBUTTON;
        if (mouse_state.MiddleIsDown()) virtual_keys += MK_MBUTTON;
        if (mouse_state.RightIsDown()) virtual_keys += MK_RBUTTON;
        if (mouse_state.Aux1IsDown()) virtual_keys += MK_XBUTTON1;
        if (mouse_state.Aux2IsDown()) virtual_keys += MK_XBUTTON2;
        
        if (event.GetEventType() == wxEVT_LEFT_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOTION) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSEMOVE, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ENTER_WINDOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SET_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SETFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_KILL_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHILD_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOUSEWHEEL) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), mouse_event.GetWheelAxis() == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL ? WM_MOUSEWHEEL : WM_MOUSEHWHEEL, virtual_keys + ((mouse_event.GetWheelRotation() < 0 ? -mouse_event.GetWheelDelta() : mouse_event.GetWheelDelta()) << 16), mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DOWN || event.GetEventType() == wxEVT_AUX2_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_UP || event.GetEventType() == wxEVT_AUX2_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DCLICK || event.GetEventType() == wxEVT_AUX2_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_scroll_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_scrollbar_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_SCROLL_LINEDOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEDOWN, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_LINEUP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEUP, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_spin_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_SPIN_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEDOWN, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SPIN_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEUP, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_system_event(wxEvent& event) {
        wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
        if (event.GetEventType() == wxEVT_CLOSE_WINDOW) {
          bool can_close = event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event));
          if (!can_close) static_cast<wxCloseEvent&>(event).Veto(!can_close); // this redendent test is needed on macos when right click on app desktop and choose quit.
        }
        else if (event.GetEventType() == wxEVT_ACTIVATE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_ACTIVATE, reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()), static_cast<wxActivateEvent&>(event).GetActive() ? (static_cast<wxActivateEvent&>(event).GetActivationReason() == wxActivateEvent::Reason::Reason_Mouse ? WA_CLICKACTIVE : WA_ACTIVE) : WA_INACTIVE, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_DESTROY) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_NULL) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_PAINT) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_PAINT, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SHOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SHOWWINDOW, static_cast<wxShowEvent&>(event).IsShown(), 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ICONIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MAXIMIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_text_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_TEXT) {
          if (event.GetId() == this->GetId()) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SETTEXT, 0, reinterpret_cast<intptr_t>(static_cast<wxCommandEvent&>(event).GetString().c_str().AsChar()), reinterpret_cast<intptr_t>(&event));
        } else
          def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_thread_event(wxEvent& event) {
        def_process_event(event);
      }
    }
  }
}

