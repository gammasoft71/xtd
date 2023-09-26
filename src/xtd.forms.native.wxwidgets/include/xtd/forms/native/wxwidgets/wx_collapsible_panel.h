#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/collpane.h>
#include <wx/scrolwin.h>

namespace xtd {
  namespace forms {
    namespace native {
      class collapsible_panel;
      class control;
      class wx_collapsible_panel : public control_handler {
        friend xtd::forms::native::collapsible_panel;
        friend xtd::forms::native::control;
      private:
        explicit wx_collapsible_panel(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxCollapsiblePane>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            control()->GetChildren()[0]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->GetChildren()[0]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
            control()->GetChildren()[1]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->GetChildren()[1]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
          //static_cast<wxCollapsiblePane*>(control())->Layout();
          static_cast<wxCollapsiblePane*>(control())->Collapse(false);
          static_cast<wxCollapsiblePane*>(control())->Collapse(true);
        }
        
        wxWindow* main_control() const override {
          return static_cast<wxCollapsiblePane*>(control())->GetPane();
        }
        
        void SetClientSize(int32 width, int32 height) override {
        }
        
        void SetSize(int32 width, int32 height) override {
        }
      };
    }
  }
}
