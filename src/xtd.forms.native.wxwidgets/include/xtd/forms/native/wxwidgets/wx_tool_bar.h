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
#include <xtd/forms/native/static_styles.h>
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
          control_handler::create<wxToolBar>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_DEFAULT_STYLE);
          // On Windows the default size icon of toolbar is 16x16 and not 32x32...
          static_cast<wxToolBar*>(control())->SetToolBitmapSize(wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? wxSize(16, 16) : wxSize(32, 32));
          #if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
      };
    }
  }
}
