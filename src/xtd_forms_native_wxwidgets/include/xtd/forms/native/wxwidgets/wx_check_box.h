#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/tglbtn.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_check_box : public control_handler {
      public:
        wx_check_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          owner_draw_ = (create_params.style() & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) this->control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          else if ((create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE) this->control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else this->control_handler::create<wxCheckBox>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxCHK_3STATE;
          
          if ((style & BS_AUTO3STATE) == BS_AUTO3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;
          else if ((style & BS_3STATE) == BS_3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;

          if ((style & BS_RIGHTBUTTON) == BS_RIGHTBUTTON) wx_style |= wxALIGN_RIGHT;

          return wx_style;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          control()->SetSize(width, height);
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
