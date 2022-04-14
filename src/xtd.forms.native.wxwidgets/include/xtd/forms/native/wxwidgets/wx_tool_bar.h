#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/tool_bar_styles.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class label;
      class wx_tool_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::label;
      private:
        explicit wx_tool_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxToolBar>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style(), create_params.ex_style()));
          // On Windows the default size icon of toolbar is 16x16 and not 32x32...
          static_cast<wxToolBar*>(control())->SetToolBitmapSize(wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? wxSize(16, 16) : wxSize(32, 32));
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & TBSTYLE_LEFT) == TBSTYLE_LEFT) wx_style |= wxTB_LEFT;
          else if ((style & TBSTYLE_BOTTOM) == TBSTYLE_BOTTOM) wx_style |= wxTB_BOTTOM;
          else if ((style & TBSTYLE_RIGHT) == TBSTYLE_RIGHT) wx_style |= wxTB_RIGHT;
          else wx_style |= wxTB_TOP;
          
          if ((style & TBSTYLE_NOSHOWICON) == TBSTYLE_NOSHOWICON) wx_style |= wxTB_NOICONS;
          if ((style & TBSTYLE_SHOWTEXT) == TBSTYLE_SHOWTEXT) wx_style |= wxTB_TEXT;
          if ((style & TBSTYLE_FLAT) == TBSTYLE_FLAT) wx_style |= wxTB_FLAT;

          return wx_style;
        }
      };
    }
  }
}
