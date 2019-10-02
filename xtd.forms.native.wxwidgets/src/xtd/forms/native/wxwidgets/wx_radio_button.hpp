#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/window_button.hpp>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/tglbtn.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_radio_button : public control_handler {        
      public:
        wx_radio_button(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE)
            this->control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else
            this->control_handler::create<wxRadioButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(),wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          this->hiden_radio_button = new wxRadioButton(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          this->hiden_radio_button->Show(false);
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxRB_GROUP;
                    
          if ((style & BS_RIGHTBUTTON) == BS_RIGHTBUTTON) wx_style |= wxALIGN_RIGHT;

          return wx_style | common_window_style_to_wx_style(style, ex_style);
        }

        wxRadioButton* hiden_radio_button = nullptr;
      };
    }
  }
}
