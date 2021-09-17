#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <wx/collpane.h>
#include <wx/scrolwin.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class collapsible_panel;
      class control;
      class wx_collapsible_panel : public control_handler {
        friend xtd::forms::native::collapsible_panel;
        friend xtd::forms::native::control;
      private:
        wx_collapsible_panel(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxCollapsiblePane>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption())), wxPoint(create_params.x(), create_params.y()));
#if defined(__WIN32__)
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

        void SetClientSize(int32_t width, int32_t height) override {
        }
        
        void SetSize(int32_t width, int32_t height) override {
        }
      };
    }
  }
}
