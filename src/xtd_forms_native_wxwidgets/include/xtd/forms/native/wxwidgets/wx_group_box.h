#pragma once
#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/platform.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
    class wxGroupBox : public wxStaticBox {
    public:
      wxGroupBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxASCII_STR(wxStaticBoxNameStr)) : wxStaticBox(parent, id, label, pos, size, style, name) {
        Bind(wxEVT_SIZE, [&](wxSizeEvent& event) {
          inner_panel->SetPosition(get_inner_box_position());
          inner_panel->SetSize(get_inner_box_size());
        });
      }
      
      wxPoint GetClientAreaOrigin() const override {return {inner_margin, inner_margin + extra_inner_margin_up};}
    
      void DoSetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO) override {wxStaticBox::DoSetSize(x, y, width, height, sizeFlags);}
      
      void DoGetClientSize(int* width, int* height) const override {
        wxStaticBox::DoGetSize(width, height);
        *width = *width - GetClientAreaOrigin().x - inner_margin;
        *height = *height - GetClientAreaOrigin().y - inner_margin;
      }
      
      void DoSetClientSize(int width, int height) override {DoSetSize(GetPosition().x, GetPosition().y, width + GetClientAreaOrigin().x + inner_margin, height + GetClientAreaOrigin().y + inner_margin);}
      
      wxWindow* GetMainWindowOfCompositeControl() override {return inner_panel;}
      
    private:
      wxPoint get_inner_box_position() const {
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {0, inner_margin + extra_inner_margin_up};
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {inner_margin, inner_margin + extra_inner_margin_up};
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {inner_margin, 0};
        return {0, 0};
      }
      
      wxSize get_inner_box_size() const {
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {GetClientSize().GetWidth(), GetClientSize().GetHeight() - GetClientAreaOrigin().y};
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {GetClientSize().GetWidth() - GetClientAreaOrigin().x - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {GetClientSize().GetWidth() - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
        return GetClientSize();
      }
      static constexpr int32_t inner_margin = 3;
      static constexpr int32_t extra_inner_margin_up = 5;
      wxPanel* inner_panel = new wxPanel(this, wxID_ANY,get_inner_box_position(), get_inner_box_size());
    };

    class wxGroupBoxOwnerDraw : public wxPanel {
    public:
      wxGroupBoxOwnerDraw(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxASCII_STR(wxStaticBoxNameStr)) : wxPanel(parent, id, pos, size, style, name) {
        Bind(wxEVT_SIZE, [&](wxSizeEvent&) {
          wxMessageOutputDebug().Output("Size Event:");
          wxMessageOutputDebug().Printf("  Position = {%d, %d} Size = {%d, %d}", GetPosition().x, GetPosition().y, GetSize().GetWidth(), GetSize().GetHeight());
          wxMessageOutputDebug().Printf("  ClientAreaOrigin = {%d, %d} ClientSize = {%d, %d}", GetClientAreaOrigin().x, GetClientAreaOrigin().y, GetClientSize().GetWidth(), GetClientSize().GetHeight());
          wxMessageOutputDebug().Printf("  Rect = {%d, %d, %d, %d}", GetRect().x, GetRect().y, GetRect().width, GetRect().height);
          wxMessageOutputDebug().Printf("  ClientRect = {%d, %d, %d, %d}", GetClientRect().x, GetClientRect().y, GetClientRect().width, GetClientRect().height);
          wxMessageOutputDebug().Output("----------------------------------");
        });
      }
      
      wxPoint GetClientAreaOrigin() const override {
        return {inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0), inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 13 : 5)};
      }
      
      void DoSetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO) override {
        wxPanel::DoSetSize(x, y, width, height, sizeFlags);
        wxMessageOutputDebug().Output("Set Size:");
        wxMessageOutputDebug().Printf("  Position = {%d, %d} Size = {%d, %d}", GetPosition().x, GetPosition().y, GetSize().GetWidth(), GetSize().GetHeight());
        wxMessageOutputDebug().Printf("  ClientAreaOrigin = {%d, %d} ClientSize = {%d, %d}", GetClientAreaOrigin().x, GetClientAreaOrigin().y, GetClientSize().GetWidth(), GetClientSize().GetHeight());
        wxMessageOutputDebug().Printf("  Rect = {%d, %d, %d, %d}", GetRect().x, GetRect().y, GetRect().width, GetRect().height);
        wxMessageOutputDebug().Printf("  ClientRect = {%d, %d, %d, %d}", GetClientRect().x, GetClientRect().y, GetClientRect().width, GetClientRect().height);
        wxMessageOutputDebug().Output("----------------------------------");
      }

      void DoGetClientSize(int* width, int* height) const override {
        wxPanel::DoGetSize(width, height);
        *width = *width - GetClientAreaOrigin().x - inner_margin - (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0);
        *height = *height - GetClientAreaOrigin().y - inner_margin - (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0);
      }
      
      void DoSetClientSize(int width, int height) override {
        DoSetSize(GetPosition().x, GetPosition().y, width + GetClientAreaOrigin().x + inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0), height + GetClientAreaOrigin().y + inner_margin + (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" ? 2 : 0));
      }
      
    private:
      static constexpr int32_t inner_margin = 3;
    };

    class wx_group_box : public control_handler {
      public:
        wx_group_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          owner_draw_ = (create_params.style() & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_)
            this->control_handler::create<wxGroupBoxOwnerDraw>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          else {
            this->control_handler::create<wxGroupBox>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
            if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
              control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
              control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            }
#endif
          }
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          return wx_style | common_window_style_to_wx_style(style, ex_style);
        }

        bool owner_draw_ = false;
      };
    }
  }
}
