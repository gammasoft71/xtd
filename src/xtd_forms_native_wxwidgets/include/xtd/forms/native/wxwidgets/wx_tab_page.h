#pragma once
#include <codecvt>
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/static_styles.h>
#include <wx/bookctrl.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_tab_page : public control_handler {
      public:
        wx_tab_page(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.ex_style() & WS_EX_AUTOSCROLL) == WS_EX_AUTOSCROLL)
            this->control_handler::create<wxScrolled<wxPanel>>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
          else
            this->control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxTAB_TRAVERSAL;
          
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          return wx_style;
        }
      };
    }
  }
}
