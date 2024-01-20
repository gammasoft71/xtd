#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/up_down_styles>
#include <xtd/argument_exception>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <limits>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      template<typename control_t>
      class control_wrapper;
      class domain_up_down;
      class wx_domain_up_down;
      class wxDomainSpinCtrl : public wxPanel {
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::domain_up_down;
        friend xtd::forms::native::wx_domain_up_down;
      private:
        explicit wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long textBoxStyle = 0, long spinStyle = 0) : wxPanel(parent, winid, pos, size) {
          textBox = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, textBoxStyle);
          upDown = new wxSpinButton(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, spinStyle);
          
          #if defined(__WXMSW__)
          auto window_color = xtd::drawing::system_colors::window();
          auto window_text_color = xtd::drawing::system_colors::window_text();
          textBox->SetBackgroundColour({window_color.r(), window_color.g(), window_color.b(), window_color.a()});
          textBox->SetForegroundColour({window_text_color.r(), window_text_color.g(), window_text_color.b(), window_text_color.a()});
          #endif
          if (size == wxDefaultSize) SetSize(120, textBox->GetSize().GetHeight());
          
          textBox->SetPosition(wxPoint(0, 0));
          textBox->Bind(wxEVT_TEXT, [&](wxCommandEvent & event) {
            wxPostEvent(this, wxCommandEvent(wxEVT_TEXT, GetId()));
          });
          
          #if defined(__WXMSW__)
          textBox->SetSize(GetSize() - wxSize(17, 0));
          upDown->SetPosition(wxPoint(GetSize().GetWidth() - 17, 0));
          upDown->SetSize(17, GetSize().GetHeight());
          #else
          textBox->SetSize(GetSize() - wxSize(upDown->GetSize().GetWidth(), 0));
          upDown->SetPosition(wxPoint(GetSize().GetWidth() - upDown->GetSize().GetWidth(), 0));
          upDown->SetSize(upDown->GetSize().GetWidth(), GetSize().GetHeight());
          #endif
          
          upDown->SetRange(0, static_cast<int32>(items.GetCount()) - 1);
          upDown->Bind(wxEVT_SPIN, [&](wxSpinEvent & event) {
            if (index == std::numeric_limits<size_t>::max())
              upDown->SetValue(static_cast<int32>(items.GetCount() - 1));
            index = items.GetCount() - 1 - upDown->GetValue();
            SetTextWithSelectedIndex();
          });
          
          Bind(wxEVT_SIZE, [&](wxEvent & ev) {
            textBox->SetSize(GetSize() - wxSize(upDown->GetSize().GetWidth(), 0));
            upDown->SetPosition(wxPoint(GetSize().GetWidth() - upDown->GetSize().GetWidth(), (GetSize().GetHeight() - upDown->GetSize().GetHeight()) / 2));
          });
        }
        
        wxArrayString& GetItems() { return items; }
        
        wxString GetValue() const { return textBox->GetValue(); }
        
        void SetValue(const wxString& value) { textBox->SetValue(value); }
        
        size_t GetSelectedIndex() const { return index; }
        
        void SetSelectedIndex(size_t index) {
          this->index = index;
          if (index != std::numeric_limits<size_t>::max()) upDown->SetValue(static_cast<int32>(items.GetCount() - 1 - index));
          else upDown->SetValue(static_cast<int32>(items.GetCount() - 1));
          SetTextWithSelectedIndex();
        }
        
        wxString GetLabel() const override {return textBox->GetValue(); }
        
        void SetLabel(const wxString& value) override {textBox->SetValue(value);}
        
        void updateSpin() {
          upDown->SetRange(0, static_cast<int32>(items.GetCount() - 1));
        }
        
        void SetTextWithSelectedIndex() {
          if (index != std::numeric_limits<size_t>::max()) textBox->SetValue(items[index]);
        }
        
        wxTextCtrl* textBox;
        wxSpinButton* upDown;
        wxArrayString items;
        size_t index = std::numeric_limits<size_t>::max();
      };
      
      class wx_domain_up_down : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::domain_up_down;
      private:
        explicit wx_domain_up_down(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          int32 height = create_params.size.height();
          #if defined(__WXGTK__)
          if (height < 32) height = 32;
          #endif
          control_handler::create<wxDomainSpinCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), height), style_to_wx_text_box_style(create_params.style, create_params.ex_style), style_to_wx_spin_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->GetChildren()[0]->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
            control()->GetChildren()[0]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->GetChildren()[1]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            control()->GetChildren()[1]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_text_box_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        static long style_to_wx_spin_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & UDS_WRAP) == UDS_WRAP) wx_style |= wxSP_WRAP;
          
          return wx_style;
        }
      };
    }
  }
}
