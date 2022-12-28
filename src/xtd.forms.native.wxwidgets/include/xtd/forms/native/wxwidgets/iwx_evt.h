#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <wx/event.h>

namespace xtd {
  namespace forms {
    namespace native {
      class iwx_evt {
      public:
        virtual ~iwx_evt() {};
        virtual void wx_evt_activate(wxEvent& event) = 0;
        virtual void wx_evt_aux1_dbclick(wxEvent& event) = 0;
        virtual void wx_evt_aux1_down(wxEvent& event) = 0;
        virtual void wx_evt_aux1_up(wxEvent& event) = 0;
        virtual void wx_evt_aux2_dbclick(wxEvent& event) = 0;
        virtual void wx_evt_aux2_down(wxEvent& event) = 0;
        virtual void wx_evt_aux2_up(wxEvent& event) = 0;
        virtual void wx_evt_button(wxEvent& event) = 0;
        virtual void wx_evt_calendar_doubleclicked(wxEvent& event) = 0;
        virtual void wx_evt_calendar_sel_changed(wxEvent& event) = 0;
        virtual void wx_evt_calendar_page_changed(wxEvent& event) = 0;
        virtual void wx_evt_calendar_week_clicked(wxEvent& event) = 0;
        virtual void wx_evt_calendar_weekday_clicked(wxEvent& event) = 0;
        virtual void wx_evt_char(wxEvent& event) = 0;
        virtual void wx_evt_checkbox(wxEvent& event) = 0;
        virtual void wx_evt_checklistbox(wxEvent& event) = 0;
        virtual void wx_evt_child_focus(wxEvent& event) = 0;
        virtual void wx_evt_choice(wxEvent& event) = 0;
        virtual void wx_evt_close_window(wxEvent& event) = 0;
        virtual void wx_evt_collapsiblepane_changed(wxEvent& event) = 0;
        virtual void wx_evt_colourpicker_changed(wxEvent& event) = 0;
        virtual void wx_evt_combobox(wxEvent& event) = 0;
        virtual void wx_evt_combobox_dropdown(wxEvent& event) = 0;
        virtual void wx_evt_combobox_closeup(wxEvent& event) = 0;
        virtual void wx_evt_date_changed(wxEvent& event) = 0;
        virtual void wx_evt_destroy(wxEvent& event) = 0;
        virtual void wx_evt_enter_sizemove(wxEvent& event) = 0;
        virtual void wx_evt_enter_window(wxEvent& event) = 0;
        virtual void wx_evt_erase_background(wxEvent& event) = 0;
        virtual void wx_evt_exit_sizemove(wxEvent& event) = 0;
        virtual void wx_evt_fontpicker_changed(wxEvent& event) = 0;
        virtual void wx_evt_fullscreen(wxEvent& event) = 0;
        virtual void wx_evt_help(wxEvent& event) = 0;
        virtual void wx_evt_iconize(wxEvent& event) = 0;
        virtual void wx_evt_key_down(wxEvent& event) = 0;
        virtual void wx_evt_key_up(wxEvent& event) = 0;
        virtual void wx_evt_kill_focus(wxEvent& event) = 0;
        virtual void wx_evt_leave_window(wxEvent& event) = 0;
        virtual void wx_evt_left_dbclick(wxEvent& event) = 0;
        virtual void wx_evt_left_down(wxEvent& event) = 0;
        virtual void wx_evt_left_up(wxEvent& event) = 0;
        virtual void wx_evt_listbox(wxEvent& event) = 0;
        virtual void wx_evt_maximize(wxEvent& event) = 0;
        virtual void wx_evt_middle_dbclick(wxEvent& event) = 0;
        virtual void wx_evt_middle_down(wxEvent& event) = 0;
        virtual void wx_evt_middle_up(wxEvent& event) = 0;
        virtual void wx_evt_menu(wxEvent& event) = 0;
        virtual void wx_evt_motion(wxEvent& event) = 0;
        virtual void wx_evt_mousewheel(wxEvent& event) = 0;
        virtual void wx_evt_move(wxEvent& event) = 0;
        virtual void wx_evt_notebook_page_changed(wxEvent& event) = 0;
        virtual void wx_evt_null(wxEvent& event) = 0;
        virtual void wx_evt_paint(wxEvent& event) = 0;
        virtual void wx_evt_radiobutton(wxEvent& event) = 0;
        virtual void wx_evt_recreate(wxEvent& event) = 0;
        virtual void wx_evt_right_dbclick(wxEvent& event) = 0;
        virtual void wx_evt_right_down(wxEvent& event) = 0;
        virtual void wx_evt_right_up(wxEvent& event) = 0;
        virtual void wx_evt_scroll_bottom(wxEvent& event) = 0;
        virtual void wx_evt_scroll_linedown(wxEvent& event) = 0;
        virtual void wx_evt_scroll_lineup(wxEvent& event) = 0;
        virtual void wx_evt_scroll_pagedown(wxEvent& event) = 0;
        virtual void wx_evt_scroll_pageup(wxEvent& event) = 0;
        virtual void wx_evt_scroll_thumnbrelease(wxEvent& event) = 0;
        virtual void wx_evt_scroll_thumbtrack(wxEvent& event) = 0;
        virtual void wx_evt_scroll_top(wxEvent& event) = 0;
        virtual void wx_evt_show(wxEvent& event) = 0;
        virtual void wx_evt_set_focus(wxEvent& event) = 0;
        virtual void wx_evt_size(wxEvent& event) = 0;
        virtual void wx_evt_slider(wxEvent& event) = 0;
        virtual void wx_evt_spin_down(wxEvent& event) = 0;
        virtual void wx_evt_spin_up(wxEvent& event) = 0;
        virtual void wx_evt_spinctrldouble(wxEvent& event) = 0;
        virtual void wx_evt_sys_color_changed(wxEvent& event) = 0;
        virtual void wx_evt_text(wxEvent& event) = 0;
        virtual void wx_evt_time_changed(wxEvent& event) = 0;
        virtual void wx_evt_togglebutton(wxEvent& event) = 0;
      };
    }
  }
}
