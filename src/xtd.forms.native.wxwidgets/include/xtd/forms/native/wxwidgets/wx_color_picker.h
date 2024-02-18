#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/choose_color_flags>
#include <xtd/argument_exception>
#include <wx/clrpicker.h>

namespace xtd {
  namespace forms {
    namespace native {
      class color_picker;
      class control;
      class wx_color_picker : public control_handler {
        friend xtd::forms::native::color_picker;
        friend xtd::forms::native::control;
      private:
        explicit wx_color_picker(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxColourPickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxColour(0, 0, 0), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & CC_ALPHACOLOR) == CC_ALPHACOLOR) wx_style |= wxCLRP_SHOW_ALPHA;

          return wx_style;
        }

        void SetBackgroundColour(const wxColour& colour) override {
          control_handler::SetBackgroundColour(colour);
          static_cast<wxColourPickerCtrl*>(control())->GetPickerCtrl()->SetBackgroundColour(colour);
        }
        
        void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32 width, int32 height) override {
          SetSize(width, height);
        }
      };
    }
  }
}
