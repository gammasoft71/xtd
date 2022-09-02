#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/create_params.h>
#include <xtd/forms/native/static_styles.h>
#include <wx/panel.h>
#include <wx/popupwin.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class popup_panel;
      class wx_popup_panel;
      
      class wxPopup : public wxPopupTransientWindow {
        friend xtd::forms::native::wx_popup_panel;
      public:
        wxPopup(wxWindow* parent, long styles) {
          Create(parent, static_cast<int>(styles));
        }
        
        void Popup(wxWindow* focus = nullptr) override {
          /// Workaround : with wxWidgets version <= 3.1.5 when first using the wxPopupTransientWindow, it does not respond on macOS....
          #if defined(__APPLE__)
          if (first_used) {
            first_used = false;
            Raise();
          }
          #endif
          wxPopupTransientWindow::Popup(focus);
        }
        
        bool IgnoreMouseMessages() const {return ignoreMouseMessages;}
        void IgnoreMouseMessages(bool value) {ignoreMouseMessages = value;}
        
        void Dismiss() override {
          wxPopupTransientWindow::Dismiss();
        }
        
      protected:
        bool ProcessLeftDown(wxMouseEvent& event) override {
          return ignoreMouseMessages;
        }
        
      private:
        #if defined(__APPLE__)
        bool first_used = true;
        #endif
        bool ignoreMouseMessages = false;
      };
      
      class wxPopupPanel : public wxScrolled<wxPanel> {
        friend xtd::forms::native::wx_popup_panel;
      private:
        wxPopupPanel(control_handler* control_handler, wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxScrolledWindowStyle, const wxString& name = wxPanelNameStr) : wxScrolled<wxPanel>(parent, winid, pos, size, style, name), control_handler_(control_handler) {}
        
        bool ProcessEvent(wxEvent& event) override {
          bool result = wxPanel::ProcessEvent(event);
          if (!GetParent()->IsShown()) return result;
          if (event.GetEventType() == wxEVT_LEFT_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_RIGHT_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_LEFT_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MIDDLE_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_RIGHT_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MOTION) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_ENTER_WINDOW) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_LEAVE_WINDOW) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_LEFT_DCLICK) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_RIGHT_DCLICK) wxPostEvent(GetParent(), event);
          //else if (event.GetEventType() == wxEVT_SET_FOCUS) wxPostEvent(GetParent(), event);
          //else if (event.GetEventType() == wxEVT_KILL_FOCUS) wxPostEvent(GetParent(), event);
          //else if (event.GetEventType() == wxEVT_CHILD_FOCUS) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MOUSEWHEEL) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_AUX1_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_AUX1_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_AUX1_DCLICK) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_KEY_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_CHAR) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_KEY_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_PAINT) control_handler_->send_message(reinterpret_cast<intptr_t>(control_handler_), WM_PAINT, 0, 0, reinterpret_cast<intptr_t>(&event));
          return result;
        }
        
        control_handler* control_handler_ = nullptr;
      };
      
      class wx_popup_panel : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::popup_panel;
      private:
        explicit wx_popup_panel(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxPopup>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), popup_panel_style_to_wx_style(create_params.style, create_params.ex_style));
          SetPosition({create_params.location.x(), create_params.location.y()});
          control()->SetSize(create_params.size.width(), create_params.size.height());
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #elif defined(__APPLE__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
            control()->SetForegroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
          }
          #endif
          boxSizer_ = new wxBoxSizer(wxVERTICAL);
          panel_ = new wxPopupPanel(this, control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, panel_style_to_wx_style(create_params.style, create_params.ex_style, create_params.class_style));
          boxSizer_->Add(panel_, wxSizerFlags().Proportion(-1).Expand());
          control()->SetSizerAndFit(boxSizer_);
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            panel_->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            panel_->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long popup_panel_style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxFRAME_SHAPED | wxPU_CONTAINS_CONTROLS;
          
          //if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        static long panel_style_to_wx_style(size_t style, size_t ex_style, size_t class_style) {
          long wx_style = wxNO_BORDER;
          
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;
          
          return wx_style;
        }
        
        wxWindow* main_control() const override {
          return panel_;
        }
        
        wxRect GetClientRect() const override {
          auto rect = control()->GetClientRect();
          rect.x = location_.x;
          rect.y = location_.y;
          return rect;
        }
        
        wxPoint GetPosition() const override {
          return location_;
        }
        
        void SetCursor(const wxCursor& cursor) override {
          control_handler::SetCursor(cursor);
          panel_->SetCursor(cursor);
        }
        
        void SetForegroundColour(const wxColour& colour) override {
          control_handler::SetForegroundColour(colour);
          panel_->SetForegroundColour(colour);
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
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
        wxBoxSizer* boxSizer_;
        wxPopupPanel* panel_;
        wxPoint location_;
      };
    }
  }
}
