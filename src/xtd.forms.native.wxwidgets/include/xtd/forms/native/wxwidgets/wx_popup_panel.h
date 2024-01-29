#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/static_styles>
#include <xtd/argument_exception>
#include <wx/panel.h>
#include <wx/popupwin.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class popup_panel;
      class wxPopup;
      class wx_popup_panel;
      
      class wxPopupPanel : public wxScrolled<wxPanel> {
        friend xtd::forms::native::wxPopup;
      private:
        explicit wxPopupPanel(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxScrolledWindowStyle, const wxString& name = wxPanelNameStr) : wxScrolled<wxPanel>(parent, winid, pos, size, style, name) {}
        
        bool ProcessEvent(wxEvent& event) override {
          bool result = wxPanel::ProcessEvent(event);
          if (!GetParent()->IsShown()) return result;
          // key events
          else if (event.GetEventType() == wxEVT_KEY_DOWN) wx_evt_->wx_evt_key_down(event);
          else if (event.GetEventType() == wxEVT_CHAR) wx_evt_->wx_evt_char(event);
          else if (event.GetEventType() == wxEVT_KEY_UP)  wx_evt_->wx_evt_key_up(event);
          // mouse events
          else if (event.GetEventType() == wxEVT_AUX1_DCLICK) wx_evt_->wx_evt_aux1_dbclick(event);
          else if (event.GetEventType() == wxEVT_AUX1_DOWN) wx_evt_->wx_evt_aux1_down(event);
          else if (event.GetEventType() == wxEVT_AUX1_UP) wx_evt_->wx_evt_aux1_up(event);
          else if (event.GetEventType() == wxEVT_AUX2_DCLICK) wx_evt_->wx_evt_aux2_dbclick(event);
          else if (event.GetEventType() == wxEVT_AUX2_DOWN) wx_evt_->wx_evt_aux2_down(event);
          else if (event.GetEventType() == wxEVT_AUX2_UP) wx_evt_->wx_evt_aux2_up(event);
          else if (event.GetEventType() == wxEVT_LEFT_DCLICK) wx_evt_->wx_evt_left_dbclick(event);
          else if (event.GetEventType() == wxEVT_LEFT_DOWN) wx_evt_->wx_evt_left_down(event);
          else if (event.GetEventType() == wxEVT_LEFT_UP) wx_evt_->wx_evt_left_up(event);
          else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) wx_evt_->wx_evt_middle_dbclick(event);
          else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) wx_evt_->wx_evt_middle_down(event);
          else if (event.GetEventType() == wxEVT_MIDDLE_UP) wx_evt_->wx_evt_middle_up(event);
          else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) wx_evt_->wx_evt_right_dbclick(event);
          else if (event.GetEventType() == wxEVT_RIGHT_DOWN) wx_evt_->wx_evt_right_down(event);
          else if (event.GetEventType() == wxEVT_RIGHT_UP) wx_evt_->wx_evt_right_up(event);
          else if (event.GetEventType() == wxEVT_ENTER_WINDOW) wx_evt_->wx_evt_enter_window(event);
          else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) wx_evt_->wx_evt_leave_window(event);
          else if (event.GetEventType() == wxEVT_MOTION) wx_evt_->wx_evt_motion(event);
          else if (event.GetEventType() == wxEVT_MOUSEWHEEL) wx_evt_->wx_evt_mousewheel(event);
          // system events
          else if (event.GetEventType() == wxEVT_SET_FOCUS) wx_evt_->wx_evt_set_focus(event);
          else if (event.GetEventType() == wxEVT_KILL_FOCUS) wx_evt_->wx_evt_kill_focus(event);
          else if (event.GetEventType() == wxEVT_CHILD_FOCUS) wx_evt_->wx_evt_child_focus(event);
          else if (event.GetEventType() == wxEVT_PAINT) wx_evt_->wx_evt_paint(event);
          return result;
        }
        
        wxWindow* GetMainWindowOfCompositeControl() override {return GetParent();}
        
        void set_wx_evt(iwx_evt* wx_evt) {wx_evt_ = wx_evt;}
        
        iwx_evt* wx_evt_ = nullptr;
      };
      
      class wxPopup : public wxPopupTransientWindow {
        friend xtd::forms::native::wx_popup_panel;
      public:
        wxPopup(wxWindow* parent, long styles) {
          Create(parent, static_cast<int32>(styles));
          boxSizer = new wxBoxSizer(wxVERTICAL);
          inner_panel = new wxPopupPanel(this);
          boxSizer->Add(inner_panel, wxSizerFlags().Proportion(-1).Expand());
          SetSizerAndFit(boxSizer);
        }
        
        void Popup(wxWindow* focus = nullptr) override {
          /// Workaround : with wxWidgets version <= 3.1.5 the wxPopupTransientWindow, it does not respond on macOS....
          #if defined(__WXOSX__)
          Raise();
          #endif
          wxPopupTransientWindow::Popup(focus);
        }
        
        bool IgnoreMouseMessages() const {return ignoreMouseMessages;}
        void IgnoreMouseMessages(bool value) {ignoreMouseMessages = value;}
        
        void Dismiss() override {
          wxPopupTransientWindow::Dismiss();
        }
        
        bool SetBackgroundColour(const wxColour& colour) override {
          #if !defined(__WXOSX__)
          inner_panel->SetBackgroundColour(colour);
          #endif
          return wxPopupTransientWindow::SetBackgroundColour(colour);
        }
        
        bool SetCursor(const wxCursor& cursor) override {
          inner_panel->SetCursor(cursor);
          return wxPopupTransientWindow::SetCursor(cursor);
        }
        
        bool SetForegroundColour(const wxColour& colour) override {
          inner_panel->SetForegroundColour(colour);
          return wxPopupTransientWindow::SetForegroundColour(colour);
        }
        
        void set_wx_evt(iwx_evt* wx_evt) {inner_panel->set_wx_evt(wx_evt);}
        
      protected:
        bool ProcessLeftDown(wxMouseEvent& event) override {
          return ignoreMouseMessages;
        }
        
      private:
        bool ignoreMouseMessages = false;
        wxBoxSizer* boxSizer = nullptr;
        wxPopupPanel* inner_panel = nullptr;
      };
      
      class wx_popup_panel : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::popup_panel;
      private:
        explicit wx_popup_panel(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxPopup>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), popup_panel_style_to_wx_style(create_params.style, create_params.ex_style));
          dynamic_cast<wxPopup*>(control())->set_wx_evt(dynamic_cast<iwx_evt*>(control()));
          SetPosition({create_params.location.x(), create_params.location.y()});
          control()->SetSize(create_params.size.width(), create_params.size.height());
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #elif defined(__WXOSX__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
            control()->SetForegroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
          }
          #endif
        }
        
        static long popup_panel_style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_container_style_to_wx_style(style, ex_style);
          
          wx_style |= wxFRAME_SHAPED | wxPU_CONTAINS_CONTROLS;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        static long panel_style_to_wx_style(size_t style, size_t ex_style, size_t class_style) {
          long wx_style = wxBORDER_NONE;
          
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;
          
          return wx_style;
        }
        
        wxWindow* main_control() const override { return control()->GetChildren()[0]; }
        
        wxRect GetClientRect() const override {
          auto rect = control()->GetClientRect();
          rect.x = location_.x;
          rect.y = location_.y;
          return rect;
        }
        
        wxPoint GetPosition() const override {
          return location_;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32 width, int32 height) override {
          SetSize(width, height);
        }
        
        void SetPosition(const wxPoint& pt) override {
          location_ = pt;
          if (control()->GetParent())
            control()->SetPosition(control()->GetParent()->ClientToScreen(location_));
          else if (wxTheApp->GetTopWindow())
            control()->SetPosition(wxTheApp->GetTopWindow()->ClientToScreen(location_));
          else
            control_handler::SetPosition(location_);
        }
        
        void Show(bool visible) override {
          if (!visible) static_cast<wxPopup*>(control())->Dismiss();
          else {
            SetPosition(location_);
            static_cast<wxPopup*>(control())->Popup();
          }
        }
        
      private:
        wxPoint location_;
      };
    }
  }
}
