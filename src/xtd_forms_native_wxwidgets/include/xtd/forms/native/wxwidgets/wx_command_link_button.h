#pragma once
#include <stdexcept>
#include <xtd/drawing/system_images.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/commandlinkbutton.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_command_link_button : public control_handler {
      public:
        wx_command_link_button(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxCommandLinkButton>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxEmptyString, wxEmptyString, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          static_cast<wxCommandLinkButton*>(control())->SetLabel(wxString(create_params.caption().c_str(), wxMBConvUTF8()));
          #if !defined(__WXMSW__)
          static_cast<wxCommandLinkButton*>(control())->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(xtd::drawing::system_images::from_name("go-next", xtd::drawing::size(16, 16)).handle())));
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          return wx_style;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }

        void SetSize(int32_t width, int32_t height) override {
          control_handler::SetSize(width, height);
        }
      };
    }
  }
}
