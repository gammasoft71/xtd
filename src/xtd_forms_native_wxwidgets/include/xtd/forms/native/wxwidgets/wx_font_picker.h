#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <wx/fontpicker.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_font_picker : public control_handler {
      public:
        wx_font_picker(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxFontPickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxFont(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()));
        }
        
        virtual void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
        }

        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
