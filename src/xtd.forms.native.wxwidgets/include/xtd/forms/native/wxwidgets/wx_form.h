#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/cdebug.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/create_params.h>
#include <xtd/forms/native/class_styles.h>
#include <xtd/forms/native/extended_window_styles.h>
#include <xtd/forms/native/window_styles.h>
#include <wx/app.h>
#include <wx/dialog.h>
#include <wx/event.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/settings.h>
#include "control_handler.h"

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
        wxMainPanel(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxScrolledWindowStyle, const wxString& name = wxPanelNameStr) : wxScrolled<wxPanel>(parent, winid, pos, size, style, name) {
        }
        
        bool ProcessEvent(wxEvent& event) override {
          bool result = wxPanel::ProcessEvent(event);
          if (!GetParent()->IsShown()) return result;
          if (event.GetEventType() == wxEVT_LEFT_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MIDDLE_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_RIGHT_DOWN) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_LEFT_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MIDDLE_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_RIGHT_UP) wxPostEvent(GetParent(), event);
          else if (event.GetEventType() == wxEVT_MOTION) {
            wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
            wxMouseState mouse_state = wxGetMouseState();
            int32_t virtual_keys = get_virtual_keys(mouse_state);
            auto x = mouse_state.GetX();
            auto y = mouse_state.GetY();
            reinterpret_cast<wxWindow*>(event.GetEventObject())->ScreenToClient(&x, &y);
            control_handler_->send_message(reinterpret_cast<intptr_t>(control_handler_), WM_MOUSEMOVE, virtual_keys, mouse_event.GetX() + (mouse_event.GetY() << 16), reinterpret_cast<intptr_t>(&event));
          } else if (event.GetEventType() == wxEVT_ENTER_WINDOW) wxPostEvent(GetParent(), event);
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
        
        void set_control_handler(control_handler* control_handler) {
          control_handler_ = control_handler;
        }
        
        control_handler* control_handler_ = nullptr;
        
        int32_t get_virtual_keys(const wxMouseState& mouse_state) {
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
          return virtual_keys;
        }
      };
      
      class iform_control_handler {
      public:
        virtual void set_control_handler(control_handler* control_handler) = 0;
      };
      
      class wxForm : public wxFrame, public iform_control_handler {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::wx_form;
      private:
        wxForm(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = wxASCII_STR(wxFrameNameStr)) : wxFrame(parent, id, title, pos, size, style, name) {
          boxSizer->Add(inner_panel, wxSizerFlags().Proportion(-1).Expand());
          SetSizerAndFit(boxSizer);
          
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            inner_panel->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            inner_panel->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        wxWindow* GetMainWindowOfCompositeControl() override {return inner_panel;}

        bool SetBackgroundColour(const wxColour& colour) override {
#if !defined(__APPLE__)
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
        
        void set_control_handler(control_handler* control_handler) override {
          inner_panel->set_control_handler(control_handler);
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
#if !defined(__APPLE__)
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
        
        void set_control_handler(control_handler* control_handler) override {
          inner_panel->set_control_handler(control_handler);
        }

        wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
        wxMainPanel* inner_panel = new wxMainPanel(this);
      };

      class wx_form : public control_handler {
#if defined(__WIN32__)
        static const int32_t min_width = 122;
        static const int32_t min_height = 32;
#elif defined(__WXGTK__)
        static const int32_t min_width = 107;
        static const int32_t min_height = 46;
#elif defined(__APPLE__)
        static const int32_t min_width = 75;
        static const int32_t min_height = 23;
#else
        static const int32_t min_width = 122;
        static const int32_t min_height = 32;
#endif
        
      public:
        explicit wx_form(const xtd::forms::native::create_params& create_params) {
          wxPoint location = wxPoint(create_params.location.x(), create_params.location.y());
          wxSize size = wxSize(create_params.size.width(), create_params.size.height());
          if (size.GetWidth() > -1 && size.GetWidth() < min_width) size.SetWidth(min_width);
          if (size.GetHeight() > -1 && size.GetHeight() < min_height) size.SetHeight(min_height);
          if ((create_params.ex_style & WS_EX_MODALWINDOW) == WS_EX_MODALWINDOW || (create_params.ex_style & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME) control_handler::create<wxFormDialog>(create_params.parent ? (reinterpret_cast<control_handler*>(create_params.parent)->control()) : nullptr, wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), location, size, form_style_to_wx_style(create_params.style, create_params.ex_style, create_params.class_style, create_params.parent));
          else control_handler::create<wxForm>(create_params.parent && (create_params.ex_style & WS_EX_TOPMOST) != WS_EX_TOPMOST ? (reinterpret_cast<control_handler*>(create_params.parent)->control()) : nullptr, wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), location, size, form_style_to_wx_style(create_params.style, create_params.ex_style, create_params.class_style, create_params.parent));
          dynamic_cast<iform_control_handler*>(control())->set_control_handler(this);
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #elif defined(__APPLE__)
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
        
        static long form_style_to_wx_style(size_t style, size_t ex_style, size_t class_style, intptr_t parent) {
          long wx_style = wxFRAME_SHAPED;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          
          if ((style & WS_CLIPCHILDREN) == WS_CLIPCHILDREN) wx_style |= wxCLIP_CHILDREN;
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
        
        #if defined(__WXGTK__)
        wxPoint GetPosition() const override {
          return location_;
          return control_handler::GetPosition();
        }
        #endif
        
        void SetClientSize(int32_t width, int32_t height) override {
          if (width < min_width) width = min_width;
          #if defined(__APPLE__)
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
          #if defined(__APPLE__)
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
        
        void SetSize(int32_t width, int32_t height) override {
          if (width < min_width) width = min_width;
          if (height < min_height) height = min_height;
          #if defined(__APPLE__)
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
          #if defined(__APPLE__)
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
        #elif defined(__APPLE__)
        bool fixed = false;
        wxSize previous_size = wxDefaultSize;
        bool is_maximize_or_fullscreen = false;
        #endif
      };
    }
  }
}
