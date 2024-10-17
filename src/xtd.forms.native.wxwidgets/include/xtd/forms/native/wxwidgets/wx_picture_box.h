#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include "wx_user_window.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/static_styles>
#include <xtd/argument_exception>
#include <wx/generic/statbmpg.h>
#include <wx/statbmp.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class picture_box;
      class wx_picture_box : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::picture_box;
      private:
        explicit wx_picture_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t);
          owner_draw_ = (create_params.style & SS_OWNERDRAW) == SS_OWNERDRAW;
          if (owner_draw_) control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_user_window_style(create_params.style, create_params.ex_style));
          else if ((create_params.style & SS_BITMAP_CENTER) == SS_BITMAP_CENTER) {
            control_handler::create<wxStaticBitmap>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxNullBitmap, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
            static_cast<wxStaticBitmap*>(control())->SetScaleMode(wxStaticBitmap::Scale_None);
          } else {
            control_handler::create<wxGenericStaticBitmap>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxNullBitmap, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
            if ((create_params.style & SS_BITMAP_STRETCH) == SS_BITMAP_STRETCH)
              static_cast<wxGenericStaticBitmap*>(control())->SetScaleMode(wxGenericStaticBitmap::Scale_Fill);
            else if ((create_params.style & SS_BITMAP_ZOOM) == SS_BITMAP_ZOOM)
              static_cast<wxGenericStaticBitmap*>(control())->SetScaleMode(wxGenericStaticBitmap::Scale_AspectFit);
            else {
              auto_size = (create_params.style & SS_BITMAP_AUTOSIZE) == SS_BITMAP_AUTOSIZE;
              static_cast<wxGenericStaticBitmap*>(control())->SetScaleMode(wxGenericStaticBitmap::Scale_None);
            }
          }
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
          control()->SetSize(create_params.size.width(), create_params.size.height());
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          wx_style |= wxST_NO_AUTORESIZE;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        static long style_to_wx_user_window_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }

        bool auto_size = false;
        bool owner_draw_ = false;
      };
    }
  }
}
