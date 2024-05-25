#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include <xtd/typeof>
#if defined(__WXOSX__)
#include <Carbon/Carbon.h>
#endif
#if defined(__WXGTK__)
#include <gdk/gdkkeysyms.h>
#endif

namespace xtd::forms::native {
  template<typename control_t>
  template<typename ...args_t>
  inline control_wrapper<control_t>::control_wrapper(control_handler* event_handler, args_t&& ...args) : control_t(args...), event_handler_(event_handler) {
  }
  
  template<typename control_t>
  inline control_wrapper<control_t>::~control_wrapper() {
    if (event_handler_) event_handler_->reset_control();
  }
  
  template<typename control_t>
  inline bool control_wrapper<control_t>::AcceptsFocus() const {
    return acceptsFocus.value_or(control_t::AcceptsFocus());
  }
  
  template<typename control_t>
  inline intptr control_wrapper<control_t>::def_wnd_proc(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle) {
    if (handle != 0 && !control_t::IsBeingDeleted()) {
      wxEvent* event = reinterpret_cast<wxEvent*>(handle);
      event->Skip(!result);
      process_result_ = control_t::ProcessEvent(*event);
    }
    return process_result_;
  }
  
  template<typename control_t>
  inline bool control_wrapper<control_t>::ProcessEvent(wxEvent& event) {
    if (event_handler_ == nullptr || event_handler_->control() == nullptr) return false;
    if (event_handler_->control()->IsBeingDeleted()) return false;
    if (static_cast<xtd::drawing::native::wx_application*>(wxTheApp)->exceptionStored) return  process_result_;

    //diagnostics::debug::write_line_if(event.GetEventType() != wxEVT_UPDATE_UI && event.GetEventType() != wxEVT_IDLE, ustring::format("control_wrapper<{}>::ProcessEvent {}", typeof_<control_t>().full_name(), to_string(event)));
    
    // keyboard events
    if (event.GetEventType() == wxEVT_CHAR) wx_evt_char(event);
    else if (event.GetEventType() == wxEVT_KEY_DOWN) wx_evt_key_down(event);
    else if (event.GetEventType() == wxEVT_KEY_UP) wx_evt_key_up(event);
    // mouse events
    else if (event.GetEventType() == wxEVT_AUX1_DCLICK) wx_evt_aux1_dbclick(event);
    else if (event.GetEventType() == wxEVT_AUX1_DOWN) wx_evt_aux1_down(event);
    else if (event.GetEventType() == wxEVT_AUX1_UP) wx_evt_aux1_up(event);
    else if (event.GetEventType() == wxEVT_AUX2_DCLICK) wx_evt_aux2_dbclick(event);
    else if (event.GetEventType() == wxEVT_AUX2_DOWN) wx_evt_aux2_down(event);
    else if (event.GetEventType() == wxEVT_AUX2_UP) wx_evt_aux2_up(event);
    else if (event.GetEventType() == wxEVT_LEFT_DCLICK) wx_evt_left_dbclick(event);
    else if (event.GetEventType() == wxEVT_LEFT_DOWN) wx_evt_left_down(event);
    else if (event.GetEventType() == wxEVT_LEFT_UP) wx_evt_left_up(event);
    else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) wx_evt_middle_dbclick(event);
    else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) wx_evt_middle_down(event);
    else if (event.GetEventType() == wxEVT_MIDDLE_UP) wx_evt_middle_up(event);
    else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) wx_evt_right_dbclick(event);
    else if (event.GetEventType() == wxEVT_RIGHT_DOWN) wx_evt_right_down(event);
    else if (event.GetEventType() == wxEVT_RIGHT_UP) wx_evt_right_up(event);
    else if (event.GetEventType() == wxEVT_ENTER_WINDOW) wx_evt_enter_window(event);
    else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) wx_evt_leave_window(event);
    else if (event.GetEventType() == wxEVT_MOTION) wx_evt_motion(event);
    else if (event.GetEventType() == wxEVT_MOUSEWHEEL) wx_evt_mousewheel(event);
    // scrolling events
    else if (event.GetEventType() == wxEVT_SCROLL_BOTTOM) wx_evt_scroll_bottom(event);
    else if (event.GetEventType() == wxEVT_SCROLL_LINEDOWN) wx_evt_scroll_linedown(event);
    else if (event.GetEventType() == wxEVT_SCROLL_LINEUP) wx_evt_scroll_lineup(event);
    else if (event.GetEventType() == wxEVT_SCROLL_PAGEDOWN) wx_evt_scroll_pagedown(event);
    else if (event.GetEventType() == wxEVT_SCROLL_PAGEUP) wx_evt_scroll_pageup(event);
    else if (event.GetEventType() == wxEVT_SCROLL_THUMBRELEASE) wx_evt_scroll_thumnbrelease(event);
    else if (event.GetEventType() == wxEVT_SCROLL_THUMBTRACK) wx_evt_scroll_thumbtrack(event);
    else if (event.GetEventType() == wxEVT_SCROLL_TOP) wx_evt_scroll_top(event);
    else if (event.GetEventType() == wxEVT_SPIN_DOWN) wx_evt_spin_down(event);
    else if (event.GetEventType() == wxEVT_SPIN_UP) wx_evt_spin_up(event);
    // command events
    else if (event.GetEventType() == wxEVT_BUTTON) wx_evt_button(event);
    else if (event.GetEventType() == wxEVT_CALENDAR_DOUBLECLICKED) wx_evt_calendar_doubleclicked(event);
    else if (event.GetEventType() == wxEVT_CALENDAR_PAGE_CHANGED) wx_evt_calendar_page_changed(event);
    else if (event.GetEventType() == wxEVT_CALENDAR_SEL_CHANGED) wx_evt_calendar_sel_changed(event);
    else if (event.GetEventType() == wxEVT_CALENDAR_WEEK_CLICKED) wx_evt_calendar_week_clicked(event);
    else if (event.GetEventType() == wxEVT_CALENDAR_WEEKDAY_CLICKED) wx_evt_calendar_weekday_clicked(event);
    else if (event.GetEventType() == wxEVT_CHECKBOX) wx_evt_checkbox(event);
    else if (event.GetEventType() == wxEVT_CHECKLISTBOX) wx_evt_checklistbox(event);
    else if (event.GetEventType() == wxEVT_CHOICE) wx_evt_choice(event);
    else if (event.GetEventType() == wxEVT_COLLAPSIBLEPANE_CHANGED) wx_evt_collapsiblepane_changed(event);
    else if (event.GetEventType() == wxEVT_COLOURPICKER_CHANGED) wx_evt_colourpicker_changed(event);
    else if (event.GetEventType() == wxEVT_COMBOBOX) wx_evt_combobox(event);
    else if (event.GetEventType() == wxEVT_COMBOBOX_DROPDOWN) wx_evt_combobox_dropdown(event);
    else if (event.GetEventType() == wxEVT_COMBOBOX_CLOSEUP) wx_evt_combobox_closeup(event);
    else if (event.GetEventType() == wxEVT_DATE_CHANGED) wx_evt_date_changed(event);
    else if (event.GetEventType() == wxEVT_FONTPICKER_CHANGED) wx_evt_fontpicker_changed(event);
    else if (event.GetEventType() == wxEVT_LISTBOX) wx_evt_listbox(event);
    else if (event.GetEventType() == wxEVT_MENU) wx_evt_menu(event);
    else if (event.GetEventType() == wxEVT_NOTEBOOK_PAGE_CHANGED) wx_evt_notebook_page_changed(event);
    else if (event.GetEventType() == wxEVT_RADIOBUTTON) wx_evt_radiobutton(event);
    else if (event.GetEventType() == wxEVT_SLIDER) wx_evt_slider(event);
    else if (event.GetEventType() == wxEVT_SPINCTRLDOUBLE) wx_evt_spinctrldouble(event);
    else if (event.GetEventType() == wxEVT_TIME_CHANGED) wx_evt_time_changed(event);
    else if (event.GetEventType() == wxEVT_TOGGLEBUTTON) wx_evt_togglebutton(event);
    // system events
    else if (event.GetEventType() == wxEVT_ACTIVATE) wx_evt_activate(event);
    else if (event.GetEventType() == wxEVT_CHILD_FOCUS) wx_evt_child_focus(event);
    else if (event.GetEventType() == wxEVT_CLOSE_WINDOW) wx_evt_close_window(event);
    else if (event.GetEventType() == wxEVT_DESTROY) wx_evt_destroy(event);
    else if (event.GetEventType() == wxEVT_ERASE_BACKGROUND) wx_evt_erase_background(event);
    else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) wx_evt_enter_sizemove(event);
    else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) wx_evt_exit_sizemove(event);
    else if (event.GetEventType() == wxEVT_FULLSCREEN) wx_evt_fullscreen(event);
    else if (event.GetEventType() == wxEVT_HELP) wx_evt_help(event);
    else if (event.GetEventType() == wxEVT_ICONIZE) wx_evt_iconize(event);
    else if (event.GetEventType() == wxEVT_KILL_FOCUS) wx_evt_kill_focus(event);
    else if (event.GetEventType() == wxEVT_MAXIMIZE) wx_evt_maximize(event);
    else if (event.GetEventType() == wxEVT_MOVE) wx_evt_move(event);
    else if (event.GetEventType() == wxEVT_NULL) wx_evt_null(event);
    else if (event.GetEventType() == wxEVT_PAINT) wx_evt_paint(event);
    else if (event.GetEventType() == wxEVT_RECREATE) wx_evt_recreate(event);
    else if (event.GetEventType() == wxEVT_SET_FOCUS) wx_evt_set_focus(event);
    else if (event.GetEventType() == wxEVT_SHOW) wx_evt_show(event);
    else if (event.GetEventType() == wxEVT_SIZE) wx_evt_size(event);
    else if (event.GetEventType() == wxEVT_SYS_COLOUR_CHANGED) wx_evt_sys_color_changed(event);
    else if (event.GetEventType() == wxEVT_TEXT) wx_evt_text(event);
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
  inline void control_wrapper<control_t>::SetAcceptsFocus(bool value) {
    acceptsFocus = value;
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::SetAcceptsFocus(std::nullptr_t) {
    acceptsFocus.reset();
  }
  
  template<typename control_t>
  inline intptr control_wrapper<control_t>::convert_to_virtual_key(const wxKeyEvent& key_event) {
    if (key_event.GetUnicodeKey() != WXK_NONE && key_event.GetUnicodeKey() != WXK_DELETE) return static_cast<intptr>(key_event.GetUnicodeKey());
#if defined(__WXOSX__)
    if (key_event.GetKeyCode() == WXK_NONE && key_event.GetRawKeyCode() == kVK_Function) return VK_FUNCTION;
#endif

    switch (key_event.GetKeyCode()) {
      case WXK_NONE: return VK_NONE;
      case WXK_BACK: return VK_BACK;
      case WXK_TAB: return VK_TAB;
      case WXK_RETURN: return VK_RETURN;
      case WXK_ESCAPE: return VK_ESCAPE;
      case WXK_SPACE: return VK_SPACE;
      case WXK_DELETE: return VK_DELETE;
      case WXK_START: return VK_LAUNCH_APP1;
      case WXK_LBUTTON: return VK_LBUTTON;
      case WXK_RBUTTON: return VK_RBUTTON;
      case WXK_CANCEL: return VK_CANCEL;
      case WXK_MBUTTON: return VK_MBUTTON;
      case WXK_CLEAR: return VK_CLEAR;
      case WXK_SHIFT: return VK_SHIFT;
      case WXK_ALT: return VK_MENU;
#if defined(__WXOSX__)
      case WXK_RAW_CONTROL: return key_event.GetRawKeyCode() == kVK_Control ? VK_LWIN : VK_RWIN;
      case WXK_COMMAND: return VK_CONTROL;
#else
      case WXK_CONTROL: return VK_CONTROL;
#endif
      case WXK_MENU: return VK_MENU;
      case WXK_PAUSE: return VK_PAUSE;
      case WXK_CAPITAL: return VK_CAPITAL;
      case WXK_END: return VK_END;
      case WXK_HOME: return VK_HOME;
      case WXK_LEFT: return VK_LEFT;
      case WXK_UP: return VK_UP;
      case WXK_RIGHT: return VK_RIGHT;
      case WXK_DOWN: return VK_DOWN;
      case WXK_SELECT: return VK_SELECT;
      case WXK_PRINT: return VK_PRINT;
      case WXK_EXECUTE: return VK_EXECUTE;
      case WXK_SNAPSHOT: return VK_SNAPSHOT;
      case WXK_INSERT: return VK_INSERT;
      case WXK_HELP: return VK_HELP;
      case WXK_NUMPAD0: return VK_NUMPAD0;
      case WXK_NUMPAD1: return VK_NUMPAD1;
      case WXK_NUMPAD2: return VK_NUMPAD2;
      case WXK_NUMPAD3: return VK_NUMPAD3;
      case WXK_NUMPAD4: return VK_NUMPAD4;
      case WXK_NUMPAD5: return VK_NUMPAD5;
      case WXK_NUMPAD6: return VK_NUMPAD6;
      case WXK_NUMPAD7: return VK_NUMPAD7;
      case WXK_NUMPAD8: return VK_NUMPAD8;
      case WXK_NUMPAD9: return VK_NUMPAD9;
      case WXK_MULTIPLY: return VK_MULTIPLY;
      case WXK_ADD: return VK_ADD;
      case WXK_SEPARATOR: return VK_SEPARATOR;
      case WXK_DIVIDE: return VK_DIVIDE;
      case WXK_F1: return VK_F1;
      case WXK_F2: return VK_F2;
      case WXK_F3: return VK_F3;
      case WXK_F4: return VK_F4;
      case WXK_F5: return VK_F5;
      case WXK_F6: return VK_F6;
      case WXK_F7: return VK_F7;
      case WXK_F8: return VK_F8;
      case WXK_F9: return VK_F9;
      case WXK_F10: return VK_F10;
      case WXK_F11: return VK_F11;
      case WXK_F12: return VK_F12;
      case WXK_F13: return VK_F13;
      case WXK_F14: return VK_F14;
      case WXK_F15: return VK_F15;
      case WXK_F16: return VK_F16;
      case WXK_F17: return VK_F17;
      case WXK_F18: return VK_F18;
      case WXK_F19: return VK_F19;
      case WXK_F20: return VK_F20;
      case WXK_F21: return VK_F21;
      case WXK_F22: return VK_F22;
      case WXK_F23: return VK_F23;
      case WXK_F24: return VK_F24;
      case WXK_NUMLOCK: return VK_NUMLOCK;
      case WXK_SCROLL: return VK_SCROLL;
      case WXK_PAGEUP: return VK_PAGEUP;
      case WXK_PAGEDOWN: return VK_PAGEDOWN;
        /// --> num pad special keys
      case WXK_NUMPAD_SPACE: return VK_SPACE;
      case WXK_NUMPAD_TAB: return VK_TAB;
      case WXK_NUMPAD_ENTER: return VK_RETURN;
      case WXK_NUMPAD_F1: return VK_F1;
      case WXK_NUMPAD_F2: return VK_F2;
      case WXK_NUMPAD_F3: return VK_F3;
      case WXK_NUMPAD_F4: return VK_F4;
      case WXK_NUMPAD_HOME: return VK_HOME;
      case WXK_NUMPAD_LEFT: return VK_LEFT;
      case WXK_NUMPAD_UP: return VK_UP;
      case WXK_NUMPAD_RIGHT: return VK_RIGHT;
      case WXK_NUMPAD_DOWN: return VK_DOWN;
      case WXK_NUMPAD_PAGEUP: return VK_PAGEUP;
      case WXK_NUMPAD_PAGEDOWN: return VK_PAGEDOWN;
      case WXK_NUMPAD_END: return VK_END;
      case WXK_NUMPAD_BEGIN: return VK_HOME; // ???
      case WXK_NUMPAD_INSERT: return VK_INSERT;
      case WXK_NUMPAD_DELETE: return VK_DELETE;
      case WXK_NUMPAD_EQUAL: return '=';
        /// <-- num pad special keys
      case WXK_NUMPAD_MULTIPLY: return VK_MULTIPLY;
      case WXK_NUMPAD_ADD: return VK_ADD;
      case WXK_NUMPAD_SEPARATOR: return VK_SEPARATOR;
      case WXK_NUMPAD_SUBTRACT: return VK_SUBTRACT;
      case WXK_NUMPAD_DECIMAL: return VK_DECIMAL;
      case WXK_NUMPAD_DIVIDE: return VK_DIVIDE;
      case WXK_WINDOWS_LEFT: return xtd::environment::os_version().is_macos() ? VK_CONTROL : VK_LWIN;
      case WXK_WINDOWS_RIGHT: return xtd::environment::os_version().is_macos() ? VK_CONTROL : VK_RWIN;
      case WXK_WINDOWS_MENU: return VK_APPS;
        //case WXK_RAW_CONTROL: return xtd::forms::keys::control_key;
      case WXK_SPECIAL1: return VK_OEM_1;
      case WXK_SPECIAL2: return VK_OEM_2;
      case WXK_SPECIAL3: return VK_OEM_3;
      case WXK_SPECIAL4: return VK_OEM_4;
      case WXK_SPECIAL5: return VK_OEM_5;
      case WXK_SPECIAL6: return VK_OEM_6;
      case WXK_SPECIAL7: return VK_OEM_7;
      case WXK_SPECIAL8: return VK_OEM_8;
      case WXK_SPECIAL9: return VK_OEM_AX;
      case WXK_SPECIAL10: return VK_OEM_102;
      case WXK_SPECIAL11: return VK_OEM_RESET;
      case WXK_SPECIAL12: return VK_OEM_JUMP;
      case WXK_SPECIAL13: return VK_OEM_PA1;
      case WXK_SPECIAL14: return VK_OEM_PA2;
      case WXK_SPECIAL15: return VK_OEM_PA3;
      case WXK_SPECIAL16: return VK_OEM_WSCTRL;
      case WXK_SPECIAL17: return VK_OEM_CUSEL;
      case WXK_SPECIAL18: return VK_OEM_ATTN;
      case WXK_SPECIAL19: return VK_OEM_FINISH;
      case WXK_SPECIAL20: return VK_OEM_COPY;
      case WXK_BROWSER_BACK: return VK_BROWSER_BACK;
      case WXK_BROWSER_FORWARD: return VK_BROWSER_FORWARD;
      case WXK_BROWSER_REFRESH: return VK_BROWSER_REFRESH;
      case WXK_BROWSER_STOP: return VK_BROWSER_STOP;
      case WXK_BROWSER_SEARCH: return VK_BROWSER_SEARCH;
      case WXK_BROWSER_FAVORITES: return VK_BROWSER_FAVORITES;
      case WXK_BROWSER_HOME: return VK_BROWSER_HOME;
      case WXK_VOLUME_MUTE: return VK_VOLUME_MUTE;
      case WXK_VOLUME_DOWN: return VK_VOLUME_DOWN;
      case WXK_VOLUME_UP: return VK_VOLUME_UP;
      case WXK_MEDIA_NEXT_TRACK: return VK_MEDIA_NEXT_TRACK;
      case WXK_MEDIA_PREV_TRACK: return VK_MEDIA_PREV_TRACK;
      case WXK_MEDIA_STOP: return VK_MEDIA_STOP;
      case WXK_MEDIA_PLAY_PAUSE: return VK_MEDIA_PLAY_PAUSE;
      case WXK_LAUNCH_MAIL: return VK_LAUNCH_MAIL;
      case WXK_LAUNCH_APP1: return VK_LAUNCH_APP1;
      case WXK_LAUNCH_APP2: return VK_LAUNCH_APP2;
      default: return VK_NONE;
    }
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::def_process_event(intptr result, wxEvent& event) {
    process_result_ = def_wnd_proc(0, 0, 0, 0, result, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::def_process_event(wxEvent& event) {
    def_process_event(0, event);
  }
  
  template<typename control_t>
  inline intptr control_wrapper<control_t>::get_control_handle_for_event(wxEvent& event, control_handler* handler) {
    return reinterpret_cast<wxWindow*>(event.GetEventObject())->GetMainWindowOfCompositeControl() != this->GetMainWindowOfCompositeControl() && static_cast<wxWindow*>(event.GetEventObject())->GetMainWindowOfCompositeControl()->GetClientData() != nullptr  ? reinterpret_cast<intptr>(static_cast<wxWindow*>(event.GetEventObject())->GetMainWindowOfCompositeControl()->GetClientData()) : reinterpret_cast<intptr>(handler);
  }
  
  template<typename control_t>
  inline int32 control_wrapper<control_t>::get_virtual_keys(const wxMouseState& mouse_state) {
    int32 virtual_keys = 0;
    
#if defined(__WXOSX__)
    if (mouse_state.RawControlDown()) virtual_keys |= MK_CONTROL;
#else
    if (mouse_state.ControlDown()) virtual_keys |= MK_CONTROL;
#endif
    if (mouse_state.ShiftDown()) virtual_keys |= MK_SHIFT;
    if (mouse_state.LeftIsDown()) virtual_keys |= MK_LBUTTON;
    if (mouse_state.MiddleIsDown()) virtual_keys |= MK_MBUTTON;
    if (mouse_state.RightIsDown()) virtual_keys |= MK_RBUTTON;
    if (mouse_state.Aux1IsDown()) virtual_keys |= MK_XBUTTON1;
    if (mouse_state.Aux2IsDown()) virtual_keys |= MK_XBUTTON2;
    return virtual_keys;
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>:: send_mouse_message(uint32 msg, size_t virtual_key, wxEvent& event) {
    wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
    wxMouseState mouse_state = wxGetMouseState();
    int32 virtual_keys = get_virtual_keys(mouse_state);
    auto x = mouse_state.GetX();
    auto y = mouse_state.GetY();
    reinterpret_cast<wxWindow*>(event.GetEventObject())->ScreenToClient(&x, &y);
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), msg, virtual_key | virtual_keys, mouse_event.GetX() + (mouse_event.GetY() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline std::string control_wrapper<control_t>::to_string(const wxEventType& eventType) {
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
      {wxEVT_SIZE, "wxEVT_SIZE"}, {wxEVT_MOVE, "wxEVT_MOVE"}, {wxEVT_CLOSE_WINDOW, "wxEVT_CLOSE_WINDOW"}, {wxEVT_END_SESSION, "wxEVT_END_SESSION"}, {wxEVT_QUERY_END_SESSION, "wxEVT_QUERY_END_SESSION"}, {wxEVT_ACTIVATE_APP, "wxEVT_ACTIVATE_APP"}, {wxEVT_ACTIVATE, "wxEVT_ACTIVATE"}, {wxEVT_CREATE, "wxEVT_CREATE"}, {wxEVT_DESTROY, "wxEVT_DESTROY"}, {wxEVT_SHOW, "wxEVT_SHOW"}, {wxEVT_FULLSCREEN, "wxEVT_FULLSCREEN"}, {wxEVT_ICONIZE, "wxEVT_ICONIZE"}, {wxEVT_MAXIMIZE, "wxEVT_MAXIMIZE"}, {wxEVT_MOUSE_CAPTURE_CHANGED, "wxEVT_MOUSE_CAPTURE_CHANGED"}, {wxEVT_MOUSE_CAPTURE_LOST, "wxEVT_MOUSE_CAPTURE_LOST"}, {wxEVT_PAINT, "wxEVT_PAINT"}, {wxEVT_ERASE_BACKGROUND, "wxEVT_ERASE_BACKGROUND"}, {wxEVT_NC_PAINT, "wxEVT_NC_PAINT"}, {wxEVT_MENU_OPEN, "wxEVT_MENU_OPEN"}, {wxEVT_MENU_CLOSE, "wxEVT_MENU_CLOSE"}, {wxEVT_MENU_HIGHLIGHT, "wxEVT_MENU_HIGHLIGHT"}, {wxEVT_CONTEXT_MENU, "wxEVT_CONTEXT_MENU"}, {wxEVT_SYS_COLOUR_CHANGED, "wxEVT_SYS_COLOUR_CHANGED"}, {wxEVT_DISPLAY_CHANGED, "wxEVT_DISPLAY_CHANGED"}, {wxEVT_QUERY_NEW_PALETTE, "wxEVT_QUERY_NEW_PALETTE"}, {wxEVT_PALETTE_CHANGED, "wxEVT_PALETTE_CHANGED"}, {wxEVT_JOY_BUTTON_DOWN, "wxEVT_JOY_BUTTON_DOWN"}, {wxEVT_JOY_BUTTON_UP, "wxEVT_JOY_BUTTON_UP"}, {wxEVT_JOY_MOVE, "wxEVT_JOY_MOVE"}, {wxEVT_JOY_ZMOVE, "wxEVT_JOY_ZMOVE"}, {wxEVT_DROP_FILES, "wxEVT_DROP_FILES"}, {wxEVT_INIT_DIALOG, "wxEVT_INIT_DIALOG"}, {wxEVT_IDLE, "wxEVT_IDLE"}, {wxEVT_UPDATE_UI, "wxEVT_UPDATE_UI"}, {wxEVT_SIZING, "wxEVT_SIZING"}, {wxEVT_MOVING, "wxEVT_MOVING"}, {wxEVT_MOVE_START, "wxEVT_MOVE_START"}, {wxEVT_MOVE_END, "wxEVT_MOVE_END"}, {wxEVT_HIBERNATE, "wxEVT_HIBERNATE"},
      {wxEVT_TEXT, "wxEVT_TEXT"}, {wxEVT_TEXT_ENTER, "wxEVT_TEXT_ENTER"}, {wxEVT_TEXT_URL, "wxEVT_TEXT_URL"}, {wxEVT_TEXT_MAXLEN, "wxEVT_TEXT_MAXLEN"},
      {wxEVT_TEXT_COPY, "wxEVT_TEXT_COPY"}, {wxEVT_TEXT_CUT, "wxEVT_TEXT_CUT"}, {wxEVT_TEXT_PASTE, "wxEVT_TEXT_PASTE"},
      {wxEVT_COMMAND_LEFT_CLICK, "wxEVT_COMMAND_LEFT_CLICK"}, {wxEVT_COMMAND_LEFT_DCLICK, "wxEVT_COMMAND_LEFT_DCLICK"}, {wxEVT_COMMAND_RIGHT_CLICK, "wxEVT_COMMAND_RIGHT_CLICK"}, {wxEVT_COMMAND_RIGHT_DCLICK, "wxEVT_COMMAND_RIGHT_DCLICK"}, {wxEVT_COMMAND_SET_FOCUS, "wxEVT_COMMAND_SET_FOCUS"}, {wxEVT_COMMAND_KILL_FOCUS, "wxEVT_COMMAND_KILL_FOCUS"}, {wxEVT_COMMAND_ENTER, "wxEVT_COMMAND_ENTER"},
      {wxEVT_HELP, "wxEVT_HELP"}, {wxEVT_DETAILED_HELP, "wxEVT_DETAILED_HELP"},};
    auto it = eventTypes.find(eventType);
    return ustring::format("{} (0x{:X})", it == eventTypes.end() ? "<Unknown>" : it->second, eventType);
  }
  
  template<typename control_t>
  inline std::string control_wrapper<control_t>::to_string(const wxEvent& event) {
    return ustring::format("{} {{type={}, id={}}}", typeof_<control_t>().full_name(), to_string(event.GetEventType()), event.GetId());
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_activate(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_ACTIVATE, reinterpret_cast<intptr>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()), static_cast<wxActivateEvent&>(event).GetActive() ? (static_cast<wxActivateEvent&>(event).GetActivationReason() == wxActivateEvent::Reason::Reason_Mouse ? WA_CLICKACTIVE : WA_ACTIVE) : WA_INACTIVE, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux1_dbclick(wxEvent& event) {
    send_mouse_message(WM_XBUTTONDBLCLK, MK_XBUTTON1, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux1_down(wxEvent& event) {
    send_mouse_message(WM_XBUTTONDOWN, MK_XBUTTON1, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux1_up(wxEvent& event) {
    send_mouse_message(WM_XBUTTONUP, MK_XBUTTON1, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux2_dbclick(wxEvent& event) {
    send_mouse_message(WM_XBUTTONDBLCLK, MK_XBUTTON2, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux2_down(wxEvent& event) {
    send_mouse_message(WM_XBUTTONDOWN, MK_XBUTTON2, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_aux2_up(wxEvent& event) {
    send_mouse_message(WM_XBUTTONUP, MK_XBUTTON2, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_button(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED),  get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_calendar_doubleclicked(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr>(event.GetId()), MCN_SELECT};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_calendar_sel_changed(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr>(event.GetId()), MCN_SELCHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_calendar_page_changed(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr>(event.GetId()), MCN_VIEWCHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_calendar_week_clicked(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr>(event.GetId()), MCN_VIEWCHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_calendar_weekday_clicked(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(event_handler_), static_cast<uintptr>(event.GetId()), MCN_VIEWCHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_char(wxEvent& event) {
    event.Skip(!event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_CHAR, static_cast<wxKeyEvent&>(event).GetUnicodeKey(), 0, reinterpret_cast<intptr>(&event)));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_checkbox(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_checklistbox(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_child_focus(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_choice(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_close_window(wxEvent& event) {
    if (event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_CLOSE, 0, 0, reinterpret_cast<intptr>(&event)))
      static_cast<wxCloseEvent&>(event).Veto();
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_collapsiblepane_changed(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), NM_CLICK), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_colourpicker_changed(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CPN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_combobox(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_combobox_dropdown(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_DROPDOWN), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_combobox_closeup(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), CBN_CLOSEUP), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_date_changed(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(get_control_handle_for_event(event, event_handler_)), static_cast<uintptr>(event.GetId()), DTN_DATETIMECHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_destroy(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_DESTROY, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_enter_sizemove(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_enter_window(wxEvent& event) {
    if (event.GetId() == control_t::GetId()) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_erase_background(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_ERASEBKGND, reinterpret_cast<intptr>(static_cast<wxWindow*>(event.GetEventObject())->GetClientData()), 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_exit_sizemove(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_fontpicker_changed(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), FPN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_fullscreen(wxEvent& event) {
    wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_help(wxEvent& event) {
    HELPINFO help_info;
    help_info.cbSize = sizeof(HELPINFO);
    help_info.iContextType = static_cast<wxHelpEvent&>(event).GetOrigin() == wxHelpEvent::Origin_HelpButton ? HELPINFO_WINDOW : HELPINFO_MENUITEM;
    help_info.iCtrlId = event.GetId();
    help_info.hItemHandle = reinterpret_cast<HWND>(event_handler_);
    help_info.dwContextId = event.GetId(); /// @todo : To be update with the correct context id...
    help_info.MousePos = POINT{static_cast<wxHelpEvent&>(event).GetPosition().x, static_cast<wxHelpEvent&>(event).GetPosition().y};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_HELP, 0, reinterpret_cast<intptr>(&help_info), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_iconize(wxEvent& event) {
    wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_key_down(wxEvent& event) {
#if defined (__WXMSW__)
    if (static_cast<wxKeyEvent&>(event).GetKeyCode() == WXK_WINDOWS_LEFT || static_cast<wxKeyEvent&>(event).GetKeyCode() == WXK_WINDOWS_RIGHT) return;
#elif defined(__WXGTK__)
  if (static_cast<wxKeyEvent&>(event).GetKeyCode() == WXK_NONE && static_cast<wxKeyEvent&>(event).GetRawKeyCode() == GDK_KEY_ISO_Level3_Shift) {
      static_cast<wxKeyEvent&>(event).m_keyCode = WXK_ALT;
      event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KEYDOWN, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr>(&event));
      return;
  }
#elif defined(__WXOSX__)
    static auto functionKeyModifierIsDown = false;
    if (static_cast<wxKeyEvent&>(event).GetKeyCode() != WXK_NONE || static_cast<wxKeyEvent&>(event).GetRawKeyCode() != kVK_Function) functionKeyModifierIsDown = false;
    else {
      if (!functionKeyModifierIsDown) functionKeyModifierIsDown = true;
      else {
        functionKeyModifierIsDown = false;
        event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KEYUP, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr>(&event));
        return;
      }
    }
#endif
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KEYDOWN, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_key_up(wxEvent& event) {
#if defined(__WXGTK__)
  if (static_cast<wxKeyEvent&>(event).GetKeyCode() == WXK_NONE && static_cast<wxKeyEvent&>(event).GetRawKeyCode() == GDK_KEY_ISO_Level3_Shift) {
      static_cast<wxKeyEvent&>(event).m_keyCode = WXK_ALT;
      event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KEYUP, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr>(&event));
      return;
  }
  #endif
    event.Skip(!event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KEYUP, convert_to_virtual_key(static_cast<wxKeyEvent&>(event)), 0, reinterpret_cast<intptr>(&event)));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_kill_focus(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_leave_window(wxEvent& event) {
    if (event.GetId() == control_t::GetId()) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_left_dbclick(wxEvent& event) {
    send_mouse_message(WM_LBUTTONDBLCLK, MK_LBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_left_down(wxEvent& event) {
    send_mouse_message(WM_LBUTTONDOWN, MK_LBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_left_up(wxEvent& event) {
    send_mouse_message(WM_LBUTTONUP, MK_LBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_listbox(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), LBN_SELCHANGE), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_maximize(wxEvent& event) {
    wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_middle_dbclick(wxEvent& event) {
    send_mouse_message(WM_MBUTTONDBLCLK, MK_MBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_middle_down(wxEvent& event) {
    send_mouse_message(WM_MBUTTONDOWN, MK_MBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_middle_up(wxEvent& event) {
    send_mouse_message(WM_MBUTTONUP, MK_MBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_menu(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_MENUCOMMAND, event.GetId(), reinterpret_cast<intptr>(event.GetEventObject()), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_motion(wxEvent& event) {
    send_mouse_message(WM_MOUSEMOVE, 0, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_mousewheel(wxEvent& event) {
    wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
    wxMouseState mouse_state = wxGetMouseState();
    int32 virtual_keys = get_virtual_keys(mouse_state);
    auto x = mouse_state.GetX();
    auto y = mouse_state.GetY();
    reinterpret_cast<wxWindow*>(event.GetEventObject())->ScreenToClient(&x, &y);
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), mouse_event.GetWheelAxis() == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL ? WM_MOUSEWHEEL : WM_MOUSEHWHEEL, virtual_keys + ((mouse_event.GetWheelRotation() < 0 ? -mouse_event.GetWheelDelta() : mouse_event.GetWheelDelta()) << 16), mouse_event.GetX() + (mouse_event.GetY() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_move(wxEvent& event) {
    wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_notebook_page_changed(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), NM_CLICK), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_null(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NULL, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_paint(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_PAINT, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_radiobutton(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_recreate(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_RECREATE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_right_dbclick(wxEvent& event) {
    send_mouse_message(WM_RBUTTONDBLCLK, MK_RBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_right_down(wxEvent& event) {
    send_mouse_message(WM_RBUTTONDOWN, MK_RBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_right_up(wxEvent& event) {
    send_mouse_message(WM_RBUTTONUP, MK_RBUTTON, event);
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_bottom(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_BOTTOM, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_linedown(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEDOWN, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_lineup(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEUP, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_pagedown(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_PAGEDOWN, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_pageup(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_PAGEUP, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_thumnbrelease(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_ENDSCROLL, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_thumbtrack(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_THUMBTRACK, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_scroll_top(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_TOP, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_set_focus(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SETFOCUS, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_show(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SHOWWINDOW, static_cast<wxShowEvent&>(event).IsShown(), 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_size(wxEvent& event) {
    wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_slider(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSL_VERTICAL) == wxSL_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_THUMBPOSITION, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_spin_down(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEDOWN, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_spin_up(wxEvent& event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), (event_handler_->control()->GetWindowStyle() & wxSP_VERTICAL) == wxSP_VERTICAL ? WM_VSCROLL : WM_HSCROLL, SB_LINEUP, get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_spinctrldouble(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), UDN_DELTAPOS), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_sys_color_changed(wxEvent &event) {
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SYSCOLORCHANGE, 0, 0, reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_text(wxEvent& event) {
    if (event.GetId() == this->GetId())
      event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_SETTEXT, 0, reinterpret_cast<intptr>(static_cast<wxCommandEvent&>(event).GetString().c_str().AsWChar()), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_time_changed(wxEvent& event) {
    NMHDR nmhrd {reinterpret_cast<HWND>(get_control_handle_for_event(event, event_handler_)), static_cast<uintptr>(event.GetId()), DTN_DATETIMECHANGE};
    event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_NOTIFY, static_cast<intptr>(event.GetId()), reinterpret_cast<intptr>(&nmhrd), reinterpret_cast<intptr>(&event));
  }
  
  template<typename control_t>
  inline void control_wrapper<control_t>::wx_evt_togglebutton(wxEvent& event) {
    if (event.GetEventObject() == this) event_handler_->send_message(reinterpret_cast<intptr>(event_handler_), WM_COMMAND, MAKELONG(event.GetId(), BN_CLICKED), get_control_handle_for_event(event, event_handler_), reinterpret_cast<intptr>(&event));
  }
}
