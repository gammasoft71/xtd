#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/date_time_picker_styles>
#include <xtd/argument_exception>
#include <wx/datectrl.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class date_time_picker;
      class wx_date_time_picker : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::date_time_picker;
      private:
        explicit wx_date_time_picker(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          if ((create_params.style & DTS_TIMEFORMAT) == DTS_TIMEFORMAT)
            control_handler::create<wxTimePickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxDefaultDateTime, wxPoint(create_params.location.x(), create_params.location.y()), wxDefaultSize, style_to_wx_style_time_picker(create_params.style, create_params.ex_style));
          else
            control_handler::create<wxDatePickerCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxDefaultDateTime, wxPoint(create_params.location.x(), create_params.location.y()), wxDefaultSize, style_to_wx_style_date_picker(create_params.style, create_params.ex_style));
          SetSize(create_params.size.width(), create_params.size.height());
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style_date_picker(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & DTS_UPDOWN) == DTS_UPDOWN) wx_style |= wxDP_SPIN;
          else wx_style |= wxDP_DROPDOWN;
          if ((style & DTS_SHOWNONE) == DTS_SHOWNONE) wx_style |= wxDP_ALLOWNONE;
          if ((style & DTS_SHORTDATECENTURYFORMAT) == DTS_SHORTDATECENTURYFORMAT) wx_style |= wxDP_SHOWCENTURY;
          if ((style & DTS_LONGDATEFORMAT) == DTS_LONGDATEFORMAT) wx_style |= wxDP_SHOWCENTURY;
          
          return wx_style;
        }
        
        static long style_to_wx_style_time_picker(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          return wx_style;
        }
        
        virtual void SetPosition(const wxPoint& pt) override {
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
