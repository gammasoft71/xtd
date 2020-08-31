#pragma once
#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/button.h>
#include <wx/panel.h>
#include "control_handler.h"

#if defined(__APPLE__)
void __set_button_bezel_style__(wxButton* control, int32_t x, int32_t y, int32_t width, int32_t height);
#endif

namespace xtd {
  namespace forms {
    namespace native {
      class wx_button : public control_handler {
      public:
        wx_button(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          owner_draw_ = (create_params.style() & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_)
            this->control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else {
            this->control_handler::create<wxButton>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
            #if defined(__APPLE__)
            __set_button_bezel_style__((wxButton*)this->control(), create_params.location().x(), create_params.location().y(), create_params.size().width(), create_params.size().height());
            #endif
          }
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & BS_VCENTER) != BS_VCENTER) {
            if ((style & BS_TOP) == BS_TOP) wx_style |= wxBU_TOP;
            else if ((style & BS_BOTTOM) == BS_BOTTOM) wx_style |= wxBU_BOTTOM;
          }
          if ((style & BS_CENTER) != BS_CENTER) {
            if ((style & BS_LEFT) == BS_LEFT) wx_style |= wxBU_LEFT;
            else if ((style & BS_RIGHT) == BS_RIGHT) wx_style |= wxBU_RIGHT;
          }
          
          return wx_style;
        }
        
        virtual void SetPosition(const wxPoint& pt) override {
          control_handler::SetPosition(pt);
          
#if defined(__APPLE__)
          wxSize size = control()->GetSize();
          if (!owner_draw_) __set_button_bezel_style__((wxButton*)control(), pt.x, pt.y, size.GetWidth(), size.GetHeight());
#endif
        }

        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }

        void SetSize(int32_t width, int32_t height) override {
          control_handler::SetSize(width, height);
#if defined(__APPLE__)
          wxPoint location = control()->GetPosition();
          if (!owner_draw_) __set_button_bezel_style__((wxButton*)control(), location.x, location.y, width, height);
#endif
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
