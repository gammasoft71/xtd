#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/list_box_styles.h>
#include <wx/checklst.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_checked_list_box : public control_handler {
      public:
        wx_checked_list_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxCheckListBox>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(0, 0), 0, nullptr, style_to_wx_style(create_params.style(), create_params.ex_style()));
          /// workaround to fix alignment error on osx...
          static_cast<wxCheckListBox*>(control())->SetSize(create_params.width(), create_params.height());
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          if ((style & LBS_EXTENDEDSEL) == LBS_EXTENDEDSEL) wx_style |= wxLB_EXTENDED;
          else if ((style & LBS_MULTIPLESEL) == LBS_MULTIPLESEL) wx_style |= wxLB_MULTIPLE;
          else if ((style & LBS_HASSTRINGS) == LBS_HASSTRINGS) wx_style |= wxLB_SINGLE;
          
           // Do not use wxwidgets sort
           //if ((style & LBS_SORT) == LBS_SORT) wx_style |= wxLB_SORT;
          
          return wx_style | common_window_style_to_wx_style(style, ex_style);
        }
      };
    }
  }
}
