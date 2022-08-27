#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

namespace xtd {
  namespace forms {
    namespace native {
      template<typename control_t>
      inline control_wrapper<control_t>::~control_wrapper() {
        if (event_handler_) event_handler_->reset_control();
      }
      
      template<typename control_t>
      inline bool control_wrapper<control_t>::ProcessEvent(wxEvent& event) {
        if (event_handler_ == nullptr || event_handler_->control() == nullptr) return false;
        if (event_handler_->control()->IsBeingDeleted()) return false;
        if (static_cast<xtd::drawing::native::wx_application*>(wxTheApp)->exceptionStored) return  process_result_;
        //diagnostics::debug::write_line_if(event.GetEventType() != wxEVT_UPDATE_UI && event.GetEventType() != wxEVT_IDLE, ustring::format("control_wrapper<{}>::ProcessEvent {}", ustring::full_class_name<control_t>(), to_string(event)));
        if (event.GetEventType() == wxEVT_DESTROY) return process_result_;
        
        if (is_clipboard_event(event.GetEventType())) process_clipboard_event(event);
        else if (is_command_event(event.GetEventType())) process_command_event(event);
        else if (is_cursor_event(event.GetEventType())) process_cursor_event(event);
        else if (is_generic_command_event(event.GetEventType())) process_generic_command_event(event);
        else if (is_gesture_event(event.GetEventType())) process_gesture_event(event);
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
          explicit post_process_event(bool* process_result) : process_result_(process_result) {}
          ~post_process_event() { *process_result_ = true; }
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
        //if (event.GetEventType() == wxEVT_BUTTON && (event.GetEventObject() == event.GetPropagatedFrom() || static_cast<wxWindow*>(event.GetEventObject())->GetParent() == event.GetPropagatedFrom())) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED),  event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        if (event.GetEventType() == wxEVT_CHECKBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHECKLISTBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHOICE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COLLAPSIBLEPANE_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), NM_CLICK), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COMBOBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_SELCHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COMBOBOX_DROPDOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_DROPDOWN), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COMBOBOX_CLOSEUP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_CLOSEUP), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LISTBOX) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_NOTEBOOK_PAGE_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), NM_CLICK), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RADIOBUTTON) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SLIDER) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSL_VERTICAL) == wxSL_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_THUMBPOSITION, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SPINCTRLDOUBLE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), UDN_DELTAPOS), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_TOGGLEBUTTON) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MENU) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MENUCOMMAND, event.GetId(), reinterpret_cast<intptr_t>(event.GetEventObject()), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_COLOURPICKER_CHANGED) {
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
          /// @todo Define Notification like CPN_COLOR_CHANGED and use WM_NOTIFY...
          //NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), CPN_COLOR_CHANGED};
          //event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_FONTPICKER_CHANGED) {
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
          /// @todo Define Notification like FPN_FONT_CHANGED and use WM_NOTIFY...
          //NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), FPN_FONT_CHANGED};
          //event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_DATE_CHANGED) {
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), DTN_DATETIMECHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
          /// @todo Add date info and use WM_NOTIFY
          //NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), DTN_DATETIMECHANGE};
          //event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_TIME_CHANGED) {
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), DTN_DATETIMECHANGE), event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
          /// @todo Add time info and use WM_NOTIFY
          //NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), DTN_DATETIMECHANGE};
          //event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_CALENDAR_DOUBLECLICKED) {
          NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), MCN_SELECT};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_CALENDAR_SEL_CHANGED) {
          NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), MCN_SELCHANGE};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_CALENDAR_PAGE_CHANGED) {
          NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), MCN_VIEWCHANGE};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_CALENDAR_WEEK_CLICKED) {
          NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), MCN_VIEWCHANGE};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_CALENDAR_WEEKDAY_CLICKED) {
          NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr_t>(event.GetId()), MCN_VIEWCHANGE};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NOTIFY, static_cast<intptr_t>(event.GetId()), reinterpret_cast<intptr_t>(&nmhrd), reinterpret_cast<intptr_t>(&event));
        } else def_process_event(event);
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
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_gesture_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_key_event(wxEvent& event) {
        #if defined(__APPLE__)
        if (event.GetEventType() == wxEVT_KEY_DOWN && static_cast<wxKeyEvent&>(event).GetKeyCode() == WXK_NONE && static_cast<wxKeyEvent&>(event).GetRawKeyCode() == functionRawKeyCode) {
          if (!functionKeyModifierIsDown) functionKeyModifierIsDown = true;
          else {
            functionKeyModifierIsDown = false;
            event.SetEventType(wxEVT_KEY_UP);
          }
        }
        #endif
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
        
        #if defined(__APPLE__)
        if (mouse_state.RawControlDown()) virtual_keys |= MK_COMMAND;
        if (mouse_state.ControlDown()) virtual_keys |= MK_CONTROL;
        #else
        if (mouse_state.ControlDown()) virtual_keys |= MK_CONTROL;
        #endif
        if (mouse_state.ShiftDown()) virtual_keys |= MK_SHIFT;
        if (mouse_state.LeftIsDown()) virtual_keys |= MK_LBUTTON;
        if (mouse_state.MiddleIsDown()) virtual_keys |= MK_MBUTTON;
        if (mouse_state.RightIsDown()) virtual_keys |= MK_RBUTTON;
        if (mouse_state.Aux1IsDown()) virtual_keys |= MK_XBUTTON1;
        if (mouse_state.Aux2IsDown()) virtual_keys |= MK_XBUTTON2;
        
        if (event.GetEventType() == wxEVT_LEFT_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONDOWN, MK_LBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONDOWN, MK_MBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONDOWN, MK_RBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONUP, MK_LBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONUP, MK_MBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONUP, MK_RBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOTION) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSEMOVE, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ENTER_WINDOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_LEFT_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_LBUTTONDBLCLK, MK_LBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MBUTTONDBLCLK, MK_MBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RBUTTONDBLCLK, MK_RBUTTON | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SET_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SETFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_KILL_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_CHILD_FOCUS) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MOUSEWHEEL) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), mouse_event.GetWheelAxis() == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL ? WM_MOUSEWHEEL : WM_MOUSEHWHEEL, virtual_keys + ((mouse_event.GetWheelRotation() < 0 ? -mouse_event.GetWheelDelta() : mouse_event.GetWheelDelta()) << 16), mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDOWN, MK_XBUTTON1 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONUP, MK_XBUTTON1 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX2_DOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDOWN, MK_XBUTTON2 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX2_UP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONUP, MK_XBUTTON2 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX1_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDBLCLK, MK_XBUTTON1 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_AUX2_DCLICK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_XBUTTONDBLCLK, MK_XBUTTON2 | virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_scroll_event(wxEvent& event) {
        def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_scrollbar_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_SCROLL_TOP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_TOP, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_BOTTOM) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_BOTTOM, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_LINEUP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEUP, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_LINEDOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEDOWN, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_PAGEUP) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_PAGEUP, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_PAGEDOWN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_PAGEDOWN, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_THUMBTRACK) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_THUMBTRACK, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SCROLL_THUMBRELEASE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_ENDSCROLL, event.GetEventObject() != this ? reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()) : 0, reinterpret_cast<intptr_t>(&event));
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
          if (event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event)))
            static_cast<wxCloseEvent&>(event).Veto();
        } else if (event.GetEventType() == wxEVT_ACTIVATE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_ACTIVATE, reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()), static_cast<wxActivateEvent&>(event).GetActive() ? (static_cast<wxActivateEvent&>(event).GetActivationReason() == wxActivateEvent::Reason::Reason_Mouse ? WA_CLICKACTIVE : WA_ACTIVE) : WA_INACTIVE, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_DESTROY) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ERASE_BACKGROUND) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_ERASEBKGND, reinterpret_cast<intptr_t>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()), 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_HELP) {
          HELPINFO help_info;
          help_info.cbSize = sizeof(HELPINFO);
          help_info.iContextType = static_cast<wxHelpEvent&>(event).GetOrigin() == wxHelpEvent::Origin_HelpButton ? HELPINFO_WINDOW : HELPINFO_MENUITEM;
          help_info.iCtrlId = event.GetId();
          help_info.hItemHandle = reinterpret_cast<HWND>(event_handler_);
          help_info.dwContextId = event.GetId(); /// @todo : To be update with the correct context id...
          help_info.MousePos = POINT{static_cast<wxHelpEvent&>(event).GetPosition().x, static_cast<wxHelpEvent&>(event).GetPosition().y};
          event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_HELP, 0, reinterpret_cast<intptr_t>(&help_info), reinterpret_cast<intptr_t>(&event));
        } else if (event.GetEventType() == wxEVT_MOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_NULL) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_PAINT && event_handler_->enable_send_paint_event()) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_PAINT, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SHOW) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SHOWWINDOW, static_cast<wxShowEvent&>(event).IsShown(), 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_FULLSCREEN) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_ICONIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_MAXIMIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SIZE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_SYS_COLOUR_CHANGED) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SYSCOLORCHANGE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else if (event.GetEventType() == wxEVT_RECREATE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_RECREATE, 0, 0, reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        //else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
        else def_process_event(event);
      }
      
      template<typename control_t>
      inline void control_wrapper<control_t>::process_text_event(wxEvent& event) {
        if (event.GetEventType() == wxEVT_TEXT) {
          if (event.GetId() == this->GetId()) event_handler_->send_message(reinterpret_cast<intptr_t>(event_handler_), WM_SETTEXT, 0, reinterpret_cast<intptr_t>(static_cast<wxCommandEvent&>(event).GetString().c_str().AsWChar()), reinterpret_cast<intptr_t>(&event));
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
