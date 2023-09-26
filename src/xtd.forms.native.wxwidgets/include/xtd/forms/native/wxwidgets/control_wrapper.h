#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "iwx_evt"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/wx_application>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/diagnostics/debug>
#include <xtd/drawing/size>
#include <xtd/forms/window_messages>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/mouse_key>
#include <xtd/forms/native/scroll_bar_styles>
#include <xtd/forms/native/virtual_keys>
#include <xtd/forms/native/window_styles>
#include <xtd/delegate>
#include <xtd/object>
#include <xtd/using>
#if defined(__WXMSW__)
#include <Windows.h>
#include <Commctrl.h>
#endif
#include <wx/calctrl.h>
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
#include <cstdint>
#include <functional>
#include <memory>
#include <set>

/// @todo implement in wx_evt_event_size..
// Add wxEVT_ENTER_SIZEMOVE event for send a WM_ENTERSIZEMOVE event to wxControl...
wxDECLARE_EVENT(wxEVT_ENTER_SIZEMOVE, wxCommandEvent);

/// @todo implement in wx_evt_event_size..
// Add wxEVT_EXIT_SIZEMOVE event for send a WM_EXITSIZEMOVE event to wxControl...
wxDECLARE_EVENT(wxEVT_EXIT_SIZEMOVE, wxCommandEvent);

// Add wxEVT_RECREATE event for send a WM_RECREATE event to wxControl...
wxDECLARE_EVENT(wxEVT_RECREATE, wxCommandEvent);

namespace xtd {
  namespace forms {
    namespace native {
      class control_handler;
      
      template<typename control_t>
      class control_wrapper : public control_t, public iwx_evt {
        friend control_handler;
      protected:
        template<typename ...args_t>
        control_wrapper(control_handler* event_handler, args_t&& ...args);
        
        ~control_wrapper();
        
        bool AcceptsFocus() const override;
        
        intptr def_wnd_proc(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle);
        
        bool ProcessEvent(wxEvent& event) override;
        
        void SetAcceptsFocus(bool value);
        
        void SetAcceptsFocus(std::nullptr_t);
        
      private:
        intptr convert_to_virtual_key(const wxKeyEvent& key_event);
        
        void def_process_event(intptr result, wxEvent& event);
        
        void def_process_event(wxEvent& event);
        
        intptr get_control_handle_for_event(wxEvent& event, control_handler* handler);
        int32 get_virtual_keys(const wxMouseState& mouse_state);
        
        void send_mouse_message(uint32 message, size_t virtual_key, wxEvent& event);
        static std::string to_string(const wxEventType& eventType);
        static std::string to_string(const wxEvent& event);
        
        void wx_evt_activate(wxEvent& event) override;
        void wx_evt_aux1_dbclick(wxEvent& event) override;
        void wx_evt_aux1_down(wxEvent& event) override;
        void wx_evt_aux1_up(wxEvent& event) override;
        void wx_evt_aux2_dbclick(wxEvent& event) override;
        void wx_evt_aux2_down(wxEvent& event) override;
        void wx_evt_aux2_up(wxEvent& event) override;
        void wx_evt_button(wxEvent& event) override;
        void wx_evt_calendar_doubleclicked(wxEvent& event) override;
        void wx_evt_calendar_sel_changed(wxEvent& event) override;
        void wx_evt_calendar_page_changed(wxEvent& event) override;
        void wx_evt_calendar_week_clicked(wxEvent& event) override;
        void wx_evt_calendar_weekday_clicked(wxEvent& event) override;
        void wx_evt_char(wxEvent& event) override;
        void wx_evt_checkbox(wxEvent& event) override;
        void wx_evt_checklistbox(wxEvent& event) override;
        void wx_evt_child_focus(wxEvent& event) override;
        void wx_evt_choice(wxEvent& event) override;
        void wx_evt_close_window(wxEvent& event) override;
        void wx_evt_collapsiblepane_changed(wxEvent& event) override;
        void wx_evt_colourpicker_changed(wxEvent& event) override;
        void wx_evt_combobox(wxEvent& event) override;
        void wx_evt_combobox_dropdown(wxEvent& event) override;
        void wx_evt_combobox_closeup(wxEvent& event) override;
        void wx_evt_date_changed(wxEvent& event) override;
        void wx_evt_destroy(wxEvent& event) override;
        void wx_evt_enter_sizemove(wxEvent& event) override;
        void wx_evt_enter_window(wxEvent& event) override;
        void wx_evt_erase_background(wxEvent& event) override;
        void wx_evt_exit_sizemove(wxEvent& event) override;
        void wx_evt_fontpicker_changed(wxEvent& event) override;
        void wx_evt_fullscreen(wxEvent& event) override;
        void wx_evt_help(wxEvent& event) override;
        void wx_evt_iconize(wxEvent& event) override;
        void wx_evt_key_down(wxEvent& event) override;
        void wx_evt_key_up(wxEvent& event) override;
        void wx_evt_kill_focus(wxEvent& event) override;
        void wx_evt_leave_window(wxEvent& event) override;
        void wx_evt_left_dbclick(wxEvent& event) override;
        void wx_evt_left_down(wxEvent& event) override;
        void wx_evt_left_up(wxEvent& event) override;
        void wx_evt_listbox(wxEvent& event) override;
        void wx_evt_maximize(wxEvent& event) override;
        void wx_evt_middle_dbclick(wxEvent& event) override;
        void wx_evt_middle_down(wxEvent& event) override;
        void wx_evt_middle_up(wxEvent& event) override;
        void wx_evt_menu(wxEvent& event) override;
        void wx_evt_motion(wxEvent& event) override;
        void wx_evt_mousewheel(wxEvent& event) override;
        void wx_evt_move(wxEvent& event) override;
        void wx_evt_notebook_page_changed(wxEvent& event) override;
        void wx_evt_null(wxEvent& event) override;
        void wx_evt_paint(wxEvent& event) override;
        void wx_evt_radiobutton(wxEvent& event) override;
        void wx_evt_recreate(wxEvent& event) override;
        void wx_evt_right_dbclick(wxEvent& event) override;
        void wx_evt_right_down(wxEvent& event) override;
        void wx_evt_right_up(wxEvent& event) override;
        void wx_evt_scroll_bottom(wxEvent& event) override;
        void wx_evt_scroll_linedown(wxEvent& event) override;
        void wx_evt_scroll_lineup(wxEvent& event) override;
        void wx_evt_scroll_pagedown(wxEvent& event) override;
        void wx_evt_scroll_pageup(wxEvent& event) override;
        void wx_evt_scroll_thumnbrelease(wxEvent& event) override;
        void wx_evt_scroll_thumbtrack(wxEvent& event) override;
        void wx_evt_scroll_top(wxEvent& event) override;
        void wx_evt_show(wxEvent& event) override;
        void wx_evt_set_focus(wxEvent& event) override;
        void wx_evt_size(wxEvent& event) override;
        void wx_evt_slider(wxEvent& event) override;
        void wx_evt_spin_down(wxEvent& event) override;
        void wx_evt_spin_up(wxEvent& event) override;
        void wx_evt_spinctrldouble(wxEvent& event) override;
        void wx_evt_sys_color_changed(wxEvent& event) override;
        void wx_evt_text(wxEvent& event) override;
        void wx_evt_time_changed(wxEvent& event) override;
        void wx_evt_togglebutton(wxEvent& event) override;
        
        control_handler* event_handler_;
        bool process_result_ = true;
        #if defined(__WXOSX__)
        static constexpr size_t functionRawKeyCode = 0x0000003F;
        #endif
        bool functionKeyModifierIsDown = false;
        std::optional<bool> acceptsFocus;
      };
    }
  }
}
