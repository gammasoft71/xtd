#pragma once
#include <codecvt>
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/static_styles.hpp>
#include <wx/bookctrl.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_tab_page : public control_handler {
      public:
        wx_tab_page(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxNotebookPage>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          return wx_style; // | common_window_style_to_wx_style(style, ex_style);
        }
      };
    }
  }
}
