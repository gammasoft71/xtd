#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/class_styles>
#include <xtd/forms/native/extended_window_styles>
#include <xtd/forms/native/window_styles>
#include <xtd/cdebug>
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>

bool __toggle_full_screen_frame__(wxTopLevelWindow* control);

namespace xtd {
  namespace forms {
    namespace native {
      template<typename control_t>
      class control_wrapper;
      class wxForm;
      class wxFormDialog;
      class wx_form;
      class wxMainPanel : public wxScrolled<wxPanel> {
        friend xtd::forms::native::wxForm;
        friend xtd::forms::native::wxFormDialog;
      private:
        explicit wxMainPanel(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxScrolledWindowStyle, const wxString& name = wxPanelNameStr) : wxScrolled<wxPanel>(parent, winid, pos, size, style, name) {
        }
        
        bool ProcessEvent(wxEvent& event) override {
          bool result = wxPanel::ProcessEvent(event);
          if (!GetParent()->IsShown() || !wx_evt_) return result;
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
        
        void set_wx_evt(iwx_evt* wx_evt) {
          wx_evt_ = wx_evt;
        }
        
        iwx_evt* wx_evt_ = nullptr;
      };
      
      class iform_control_handler {
      public:
        virtual ~iform_control_handler() {}
        virtual void set_wx_evt(iwx_evt* wx_evt) = 0;
      };
      
      class wxForm : public wxFrame, public iform_control_handler {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::wx_form;
      private:
        wxForm(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = wxASCII_STR(wxFrameNameStr)) : wxFrame(parent, id, title, pos, size, style, name) {
          boxSizer->Add(inner_panel, wxSizerFlags().Proportion(-1).Expand());
          SetSizerAndFit(boxSizer);
          
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            inner_panel->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            inner_panel->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        bool SetBackgroundColour(const wxColour& colour) override {
          #if !defined(__WXOSX__)
          inner_panel->SetBackgroundColour(colour);
          #endif
          return wxFrame::SetBackgroundColour(colour);
        }
        
        bool SetCursor(const wxCursor& cursor) override {
          inner_panel->SetCursor(cursor);
          return wxFrame::SetCursor(cursor);
        }
        
        bool SetForegroundColour(const wxColour& colour) override {
          inner_panel->SetForegroundColour(colour);
          return wxFrame::SetForegroundColour(colour);
        }
        
        void set_wx_evt(iwx_evt* wx_evt) override {
          inner_panel->set_wx_evt(wx_evt);
        }
        
        wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
        wxMainPanel* inner_panel = new wxMainPanel(this);
      };
      
      class wxFormDialog : public wxDialog, public iform_control_handler {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::wx_form;
      private:
        wxFormDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = wxASCII_STR(wxFrameNameStr)) : wxDialog(parent, id, title, pos, size, style, name) {
          boxSizer->Add(inner_panel, wxSizerFlags().Proportion(-1).Expand());
          SetSizerAndFit(boxSizer);
        }
        
        wxWindow* GetMainWindowOfCompositeControl() override {return inner_panel;}
        
        bool SetBackgroundColour(const wxColour& colour) override {
          #if !defined(__WXOSX__)
          inner_panel->SetBackgroundColour(colour);
          #endif
          return wxDialog::SetBackgroundColour(colour);
        }
        
        bool SetCursor(const wxCursor& cursor) override {
          inner_panel->SetCursor(cursor);
          return wxDialog::SetCursor(cursor);
        }
        
        bool SetForegroundColour(const wxColour& colour) override {
          inner_panel->SetForegroundColour(colour);
          return wxDialog::SetForegroundColour(colour);
        }
        
        void set_wx_evt(iwx_evt* wx_evt) override {
          inner_panel->set_wx_evt(wx_evt);
        }
        
        wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
        wxMainPanel* inner_panel = new wxMainPanel(this);
      };
      
      class wx_form : public control_handler {
        #if defined(__WXMSW__)
        static const int32 min_width = 122;
        static const int32 min_height = 32;
        #elif defined(__WXGTK__)
        static const int32 min_width = 107;
        static const int32 min_height = 46;
        #elif defined(__WXOSX__)
        static const int32 min_width = 75;
        static const int32 min_height = 23;
        #else
        static const int32 min_width = 122;
        static const int32 min_height = 32;
        #endif
        
      public:
        explicit wx_form(const xtd::forms::native::create_params& create_params) {
          wxPoint location = wxPoint(create_params.location.x(), create_params.location.y());
          wxSize size = wxSize(create_params.size.width(), create_params.size.height());
          if (size.GetWidth() > -1 && size.GetWidth() < min_width) size.SetWidth(min_width);
          if (size.GetHeight() > -1 && size.GetHeight() < min_height) size.SetHeight(min_height);
          if ((create_params.ex_style & WS_EX_MODALWINDOW) == WS_EX_MODALWINDOW || (create_params.ex_style & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME) control_handler::create<wxFormDialog>(create_params.parent ? (reinterpret_cast<control_handler*>(create_params.parent)->control()) : nullptr, wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), location, size, form_style_to_wx_style(create_params.style, create_params.ex_style, create_params.class_style, create_params.parent));
          else control_handler::create<wxForm>(create_params.parent && (create_params.ex_style & WS_EX_TOPMOST) != WS_EX_TOPMOST ? (reinterpret_cast<control_handler*>(create_params.parent)->control()) : nullptr, wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), location, wxDefaultSize, form_style_to_wx_style(create_params.style, create_params.ex_style, create_params.class_style, create_params.parent));
          SetSize(size.GetWidth(), size.GetHeight());
          dynamic_cast<iform_control_handler*>(control())->set_wx_evt(dynamic_cast<iwx_evt*>(control()));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #elif defined(__WXOSX__)
          control()->Bind(wxEVT_MAXIMIZE, [this](wxMaximizeEvent & e) {
            if (fixed) {
              wxTopLevelWindow* frame = static_cast<wxTopLevelWindow*>(control());
              is_maximize_or_fullscreen = true;
              auto current_size = frame->GetMinSize();
              if (current_size.GetWidth() > wxDefaultSize.GetWidth() || current_size.GetHeight() > wxDefaultSize.GetHeight()) {
                frame->SetMinSize(wxDefaultSize);
                frame->SetMaxSize(wxDefaultSize);
              } else {
                frame->SetMaxSize(wxDefaultSize);
                frame->SetMinSize(wxDefaultSize);
              }
            }
            e.Skip();
          });
          
          control()->Bind(wxEVT_FULLSCREEN, [this](wxFullScreenEvent & e) {
            if (fixed) {
              wxTopLevelWindow* frame = static_cast<wxTopLevelWindow*>(control());
              is_maximize_or_fullscreen = true;
              auto current_size = frame->GetMinSize();
              if (current_size.GetWidth() > wxDefaultSize.GetWidth() || current_size.GetHeight() > wxDefaultSize.GetHeight()) {
                frame->SetMinSize(wxDefaultSize);
                frame->SetMaxSize(wxDefaultSize);
              } else {
                frame->SetMaxSize(wxDefaultSize);
                frame->SetMinSize(wxDefaultSize);
              }
            }
            e.Skip();
          });
          
          control()->Bind(wxEVT_SIZE, [this](wxSizeEvent & e) {
            if (fixed) {
              wxTopLevelWindow* frame = static_cast<wxTopLevelWindow*>(control());
              if (is_maximize_or_fullscreen) is_maximize_or_fullscreen = false;
              else {
                auto current_size = frame->GetMinSize();
                if (current_size.GetWidth() > previous_size.GetWidth() || current_size.GetHeight() > previous_size.GetHeight()) {
                  frame->SetMinSize(previous_size);
                  frame->SetMaxSize(previous_size);
                } else {
                  frame->SetMaxSize(previous_size);
                  frame->SetMinSize(previous_size);
                }
              }
            }
            e.Skip();
          });
          
          fixed = (create_params.style & WS_THICKFRAME) != WS_THICKFRAME;
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
            control()->SetForegroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNTEXT));
          }
          #endif
          
          #if defined(__WXGTK__)
          control()->Bind(wxEVT_MOVE, [&](wxMoveEvent & event) {
            if (event.GetPosition() == invalid_location) return;
            location_ = event.GetPosition();
          });
          #endif
          
          if ((create_params.ex_style & WS_EX_CONTEXTHELP) == WS_EX_CONTEXTHELP) control()->SetExtraStyle(control()->GetExtraStyle() | wxDIALOG_EX_CONTEXTHELP);
          SetPosition(location);
        }
        
        static long form_style_to_wx_style(size_t style, size_t ex_style, size_t class_style, intptr parent) {
          long wx_style = common_container_style_to_wx_style(style, ex_style);
          
          wx_style |= wxFRAME_SHAPED;
          
          if ((style & WS_CAPTION) == WS_CAPTION) wx_style |= wxCAPTION;
          
          if ((style & WS_THICKFRAME) == WS_THICKFRAME) wx_style |= wxRESIZE_BORDER;
          if ((ex_style & WS_EX_TOOLWINDOW) == WS_EX_TOOLWINDOW) wx_style |= wxFRAME_TOOL_WINDOW;
          
          if ((ex_style & WS_EX_TOPMOST) == WS_EX_TOPMOST) wx_style |= wxSTAY_ON_TOP;
          else if (parent && (style & WS_CHILD) != WS_CHILD) wx_style |= wxFRAME_FLOAT_ON_PARENT;
          if ((ex_style & WS_EX_APPWINDOW) != WS_EX_APPWINDOW) wx_style |= wxFRAME_NO_TASKBAR;
          
          if ((style & WS_SYSMENU) == WS_SYSMENU) {
            if ((style & WS_MAXIMIZEBOX) == WS_MAXIMIZEBOX) wx_style |= wxMAXIMIZE_BOX;
            if ((style & WS_MINIMIZEBOX) == WS_MINIMIZEBOX) wx_style |= wxMINIMIZE_BOX;
            if ((class_style & CS_NOCLOSE) != CS_NOCLOSE) wx_style |= wxCLOSE_BOX;
            if ((ex_style & WS_EX_DLGMODALFRAME) != WS_EX_DLGMODALFRAME) wx_style |= wxSYSTEM_MENU;
          }
          
          //cdebug << ustring::format("style = 0x{:X}, ex_style = 0x{:X}, wx_style = 0x{:X}", style, ex_style, wx_style) << std::endl;
          
          return wx_style;
        }
        
        static long panel_style_to_wx_style(size_t style, size_t ex_style, size_t class_style) {
          long wx_style = wxTAB_TRAVERSAL | wxNO_BORDER;
          
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;
          
          return wx_style;
        }
        
        wxWindow* main_control() const override { return control()->GetChildren()[0]; }
        
        #if defined(__WXGTK__)
        wxPoint GetPosition() const override {
          return location_;
        }
        #endif
        
        void SetClientSize(int32 width, int32 height) override {
          if (width < min_width) width = min_width;
          #if defined(__WXOSX__)
          if (fixed) {
            auto current_size = control()->GetMinClientSize();
            if (current_size.GetWidth() > wxDefaultSize.GetWidth() || current_size.GetHeight() > wxDefaultSize.GetHeight()) {
              control()->SetMinClientSize(wxDefaultSize);
              control()->SetMaxClientSize(wxDefaultSize);
            } else {
              control()->SetMaxClientSize(wxDefaultSize);
              control()->SetMinClientSize(wxDefaultSize);
            }
          }
          #endif
          control()->SetClientSize(wxSize(width, height));
          #if defined(__WXOSX__)
          if (fixed) {
            auto current_size = control()->GetMinClientSize();
            if (current_size.GetWidth() > width || current_size.GetHeight() > height) {
              control()->SetMinClientSize(wxSize(width, height));
              control()->SetMaxClientSize(wxSize(width, height));
            } else {
              control()->SetMaxClientSize(wxSize(width, height));
              control()->SetMinClientSize(wxSize(width, height));
            }
            previous_size = GetSize();
          }
          #endif
        }
        
        void SetMinClientSize(const wxSize& size) override {
          wxSize min_size(size.GetWidth() < min_width ? min_width : size.GetWidth(), size.GetHeight());
          control_handler::SetMinClientSize(min_size);
        }
        
        void SetMinSize(const wxSize& size) override {
          wxSize min_size(size.GetWidth() < min_width ? min_width : size.GetWidth(), size.GetHeight() < min_height ? min_height : size.GetHeight());
          control_handler::SetMinSize(min_size);
        }
        
        #if defined(__WXGTK__)
        void SetPosition(const wxPoint& location) override {
          location_ = location;
          control_handler::SetPosition(location);
        }
        #endif
        
        void SetSize(int32 width, int32 height) override {
          if (width < min_width) width = min_width;
          if (height < min_height) height = min_height;
          #if defined(__WXOSX__)
          if (fixed) {
            auto current_size = control()->GetMinSize();
            if (current_size.GetWidth() > wxDefaultSize.GetWidth() || current_size.GetHeight() > wxDefaultSize.GetHeight()) {
              control()->SetMinSize(wxDefaultSize);
              control()->SetMaxSize(wxDefaultSize);
            } else {
              control()->SetMaxSize(wxDefaultSize);
              control()->SetMinSize(wxDefaultSize);
            }
          }
          #endif
          control_handler::SetSize(width, height);
          #if defined(__WXOSX__)
          if (fixed) {
            auto current_size = control()->GetMinSize();
            if (current_size.GetWidth() > width || current_size.GetHeight() > height) {
              control()->SetMinSize(wxSize(width, height));
              control()->SetMaxSize(wxSize(width, height));
            } else {
              control()->SetMaxSize(wxSize(width, height));
              control()->SetMinSize(wxSize(width, height));
            }
            previous_size = wxSize(width, height);
          }
          #endif
        }
        
        #if defined(__WXGTK__)
        void Show(bool visible) override {
          /// Workaround : With wxWidgets on Gtk, sometimes the location of the form is not valid. So you have to force the location to the right value...
          if (!visible) control_handler::Show(visible);
          else {
            control_handler::SetPosition(invalid_location);
            control_handler::Show(visible);
            control_handler::SetPosition(location_);
            control_handler::Show(visible);
          }
        }
        #endif
        
      private:
        #if defined(__WXGTK__)
        wxPoint location_;
        inline static const wxPoint invalid_location {-100000, -100000};
        #elif defined(__WXOSX__)
        bool fixed = false;
        wxSize previous_size = wxDefaultSize;
        bool is_maximize_or_fullscreen = false;
        #endif
      };
    }
  }
}
