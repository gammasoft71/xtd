#pragma once

#include <cstdint>
#include <memory>
#include <set>
#include <thread>
#include <xtd/xtd.delegates>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/window_messages.hpp>
#include <xtd/forms/native/window_message_keys.hpp>
#include <wx/frame.h>
#include <wx/textctrl.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler;
      
      template<typename TControl>
      class control_wrapper : public TControl {
      public:
        control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, pos, size, style), event_handler_(event_handler) {}
        control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, label, pos, size, style), event_handler_(event_handler) {}
        
        intptr_t def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
          wxEvent* event = reinterpret_cast<wxEvent*>(handle);
          event->Skip(!presult);
          this->process_result_ = this->TControl::ProcessEvent(*event);
          return this->process_result_;
        }
        
      private:
        void def_process_event(wxEvent& event) {
          this->process_result_ = this->def_wnd_proc(0, 0, 0, 0, 0, reinterpret_cast<intptr_t>(&event));
        }
        
        bool is_clipboard_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_TEXT_COPY, wxEVT_TEXT_CUT, wxEVT_TEXT_PASTE};
          return event_types.find(event_type) != event_types.end();
        }
        
        bool is_command_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_BUTTON, wxEVT_CHECKBOX, wxEVT_CHOICE, wxEVT_LISTBOX, wxEVT_LISTBOX_DCLICK, wxEVT_CHECKLISTBOX, wxEVT_MENU, wxEVT_SLIDER, wxEVT_RADIOBOX, wxEVT_RADIOBUTTON, wxEVT_SCROLLBAR, wxEVT_VLBOX, wxEVT_COMBOBOX, wxEVT_TOOL_RCLICKED, wxEVT_TOOL_DROPDOWN, wxEVT_TOOL_ENTER, wxEVT_COMBOBOX_DROPDOWN, wxEVT_COMBOBOX_CLOSEUP};
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
        
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
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
          static std::set<wxEventType> event_types = {wxEVT_CHAR, wxEVT_CHAR_HOOK, wxEVT_NAVIGATION_KEY, wxEVT_KEY_DOWN, wxEVT_KEY_UP,
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
            wxEVT_HOTKEY,
#endif
            wxEVT_AFTER_CHAR};
          return event_types.find(event_type) != event_types.end();
        }
        
        bool is_mouse_event(wxEventType event_type) const {
          static std::set<wxEventType> event_types = {wxEVT_LEFT_DOWN, wxEVT_LEFT_UP, wxEVT_MIDDLE_DOWN, wxEVT_MIDDLE_UP, wxEVT_RIGHT_DOWN, wxEVT_RIGHT_UP, wxEVT_MOTION, wxEVT_ENTER_WINDOW, wxEVT_LEAVE_WINDOW, wxEVT_LEFT_DCLICK, wxEVT_MIDDLE_DCLICK, wxEVT_RIGHT_DCLICK, wxEVT_SET_FOCUS, wxEVT_KILL_FOCUS, wxEVT_CHILD_FOCUS, wxEVT_MOUSEWHEEL, wxEVT_AUX1_DOWN, wxEVT_AUX1_UP, wxEVT_AUX1_DCLICK, wxEVT_AUX2_DOWN, wxEVT_AUX2_UP, wxEVT_AUX2_DCLICK /*, wxEVT_MAGNIFY*/};
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
              case WXK_START: key_data = VK_LAUNCH_APP1; break;
              case WXK_LBUTTON: key_data = VK_LBUTTON; break;
              case WXK_RBUTTON: key_data = VK_RBUTTON; break;
              case WXK_CANCEL: key_data = VK_CANCEL; break;
              case WXK_MBUTTON: key_data = VK_MBUTTON; break;
              case WXK_CLEAR: key_data = VK_CLEAR; break;
              case WXK_SHIFT: key_data = VK_SHIFT; break;
              case WXK_ALT: key_data = VK_MENU; break;
              case WXK_CONTROL: key_data = VK_CONTROL; break;
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
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
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
          
          if (key_event.AltDown()) key_data += VK_ALT_MODIFIER;
          if (key_event.CmdDown()) key_data += VK_CONTROL_MODIFIER;
          if (key_event.MetaDown()) key_data += VK_COMMAND_MODIFIER;
          if (key_event.ShiftDown()) key_data += VK_SHIFT_MODIFIER;
          
          return key_data;
        }
        
        bool ProcessEvent(wxEvent &event) override;
        void process_clipboard_event(wxEvent &event, intptr_t hwnd);
        void process_command_event(wxEvent &event, intptr_t hwnd);
        void process_cursor_event(wxEvent &event, intptr_t hwnd);
        void process_generic_command_event(wxEvent &event, intptr_t hwnd);
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
        void process_gesture_event(wxEvent &event, intptr_t hwnd);
#endif
        void process_help_event(wxEvent &event, intptr_t hwnd);
        void process_key_event(wxEvent &event, intptr_t hwnd);
        void process_mouse_event(wxEvent &event, intptr_t hwnd);
        void process_scroll_event(wxEvent &event, intptr_t hwnd);
        void process_scrollbar_event(wxEvent &event, intptr_t hwnd);
        void process_spin_event(wxEvent &event, intptr_t hwnd);
        void process_system_event(wxEvent &event, intptr_t hwnd);
        void process_text_event(wxEvent &event, intptr_t hwnd);
        void process_thread_event(wxEvent &event, intptr_t hwnd);
        
        control_handler* event_handler_;
        bool process_result_ = true;
      };
      
      class control_handler {
      public:
        control_handler() = default;
        
        template<typename control>
        void create(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
          this->control_ = new control_wrapper<control>(this, parent, id, pos, size, style);
          this->def_wnd_proc += {static_cast<control_wrapper<control>&>(*this->control_), &control_wrapper<control>::def_wnd_proc};
        }
        
        template<typename control>
        void create(wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
          this->control_ = new control_wrapper<control>(this, parent, id, label, pos, size, style);
          this->def_wnd_proc += {static_cast<control_wrapper<control>&>(*this->control_), &control_wrapper<control>::def_wnd_proc};
        }
        
        intptr_t send_message(intptr_t hwnd, intptr_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          return this->wnd_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        wxWindow* control() const {return this->control_;}
        void clear_control() {this->control_ = nullptr;}
        
        intptr_t call_def_wnd_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t result, intptr_t handle) {return this->def_wnd_proc(hwnd, msg, wparam, lparam, result, handle);}
        
        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
        event<control_handler, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t, intptr_t)>> def_wnd_proc;
        
      private:
        wxWindow* control_;
      };
      
      template<typename TControl>
      inline bool control_wrapper<TControl>::ProcessEvent(wxEvent& event) {
        if (event.GetEventType() == wxEVT_DESTROY) {
          this->def_process_event(event);
          return this->process_result_;
        }
        wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
        if (!window) {
          this->def_process_event(event);
          return this->process_result_;
        }
        intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());
        
        if (is_clipboard_event(event.GetEventType())) this->process_clipboard_event(event, hwnd);
        else if (is_command_event(event.GetEventType())) this->process_command_event(event, hwnd);
        else if (is_cursor_event(event.GetEventType())) this->process_cursor_event(event, hwnd);
        else if (is_generic_command_event(event.GetEventType())) this->process_generic_command_event(event, hwnd);
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
        else if (is_gesture_event(event.GetEventType())) this->process_gesture_event(event, hwnd);
#endif
        else if (is_key_event(event.GetEventType())) this->process_key_event(event, hwnd);
        else if (is_mouse_event(event.GetEventType())) this->process_mouse_event(event, hwnd);
        else if (is_scroll_event(event.GetEventType())) this->process_scroll_event(event, hwnd);
        else if (is_scrollbar_event(event.GetEventType())) this->process_scrollbar_event(event, hwnd);
        else if (is_spin_event(event.GetEventType())) this->process_spin_event(event, hwnd);
        else if (is_system_event(event.GetEventType())) this->process_system_event(event, hwnd);
        else if (is_text_event(event.GetEventType())) this->process_text_event(event, hwnd);
        else if (is_thread_event(event.GetEventType())) this->process_thread_event(event, hwnd);
        else this->def_process_event(event);
        
        struct post_process_event {
          post_process_event(bool* process_result) : process_result_(process_result) {}
          ~post_process_event() {*process_result_ = true;}
          bool* process_result_;
        } post_process_event(&this->process_result_);
        
        return this->process_result_;
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_clipboard_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_command_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_cursor_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_generic_command_event(wxEvent& event, intptr_t hwnd) {
        if (event.GetEventType() == wxEVT_COMMAND_ENTER)
          this->event_handler_->send_message(hwnd, WM_COMMAND, 0, 0, reinterpret_cast<intptr_t>(&event));
        else
          this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_help_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
      template<typename TControl>
      inline void control_wrapper<TControl>::process_gesture_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
#endif
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_key_event(wxEvent& event, intptr_t hwnd) {
        if (event.GetEventType() == wxEVT_KEY_DOWN) event.Skip(!this->event_handler_->send_message(hwnd, WM_KEYDOWN, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr_t>(&event)));
        else if (event.GetEventType() == wxEVT_CHAR) event.Skip(!this->event_handler_->send_message(hwnd, WM_CHAR, static_cast<wxKeyEvent&>(event).GetUnicodeKey(), 0, reinterpret_cast<intptr_t>(&event)));
        else if (event.GetEventType() == wxEVT_KEY_UP) event.Skip(!this->event_handler_->send_message(hwnd, WM_KEYUP, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr_t>(&event)));
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
        else if (event.GetEventType() == wxEVT_HOTKEY) this->def_process_event(event);
#endif
        else this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_mouse_event(wxEvent& event, intptr_t hwnd) {
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
        
        if (event.GetEventType() == wxEVT_LEFT_DOWN) this->event_handler_->send_message(hwnd, WM_LBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) this->event_handler_->send_message(hwnd, WM_MBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DOWN) this->event_handler_->send_message(hwnd, WM_RBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_UP) this->event_handler_->send_message(hwnd, WM_LBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_UP) this->event_handler_->send_message(hwnd, WM_MBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_UP) this->event_handler_->send_message(hwnd, WM_RBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOTION) this->event_handler_->send_message(hwnd, WM_MOUSEMOVE, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ENTER_WINDOW) this->event_handler_->send_message(hwnd, WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) this->event_handler_->send_message(hwnd, WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_DCLICK) this->event_handler_->send_message(hwnd, WM_LBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) this->event_handler_->send_message(hwnd, WM_MBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) this->event_handler_->send_message(hwnd, WM_RBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SET_FOCUS) this->event_handler_->send_message(hwnd, WM_SETFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_KILL_FOCUS) this->event_handler_->send_message(hwnd, WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHILD_FOCUS) this->event_handler_->send_message(hwnd, WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOUSEWHEEL) this->event_handler_->send_message(hwnd, mouse_event.GetWheelAxis() == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL ? WM_MOUSEWHEEL : WM_MOUSEHWHEEL, virtual_keys + ((mouse_event.GetWheelRotation() < 0 ? -mouse_event.GetWheelDelta() : mouse_event.GetWheelDelta()) << 16), mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DOWN || event.GetEventType() == wxEVT_AUX2_DOWN) this->event_handler_->send_message(hwnd, WM_XBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_UP || event.GetEventType() == wxEVT_AUX2_UP) this->event_handler_->send_message(hwnd, WM_XBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DCLICK || event.GetEventType() == wxEVT_AUX2_DCLICK) this->event_handler_->send_message(hwnd, WM_XBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_scroll_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_scrollbar_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_spin_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_system_event(wxEvent& event, intptr_t hwnd) {
        wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
        if (event.GetEventType() == wxEVT_CLOSE_WINDOW) this->event_handler_->send_message(hwnd, WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_DESTROY) this->event_handler_->send_message(hwnd, WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOVE) this->event_handler_->send_message(hwnd, WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_NULL) this->event_handler_->send_message(hwnd, WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SHOW) this->event_handler_->send_message(hwnd, WM_SHOWWINDOW, static_cast<wxShowEvent&>(event).IsShown(), 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SIZE) this->event_handler_->send_message(hwnd, WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) this->event_handler_->send_message(hwnd, WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) this->event_handler_->send_message(hwnd, WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_text_event(wxEvent& event, intptr_t hwnd) {
        if (event.GetEventType() == wxEVT_TEXT) {
          this->event_handler_->send_message(hwnd, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(static_cast<wxCommandEvent&>(event).GetString().c_str().AsChar()), reinterpret_cast<intptr_t>(&event));
        } else
          this->def_process_event(event);
      }
      
      template<typename TControl>
      inline void control_wrapper<TControl>::process_thread_event(wxEvent& event, intptr_t hwnd) {
        this->def_process_event(event);
      }
    }
  }
}

