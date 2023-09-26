#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/tool_bar_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/artprov.h>
#include <wx/toolbar.h>

void __reset_tool_bar_tools_styles__(wxToolBar* toolBar);

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class label;
      class wx_tool_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::label;
      private:
        explicit wx_tool_bar(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxToolBar>(reinterpret_cast<control_handler*>(create_params.parent)->control(), wxID_ANY, wxDefaultPosition, wxDefaultSize, style_to_wx_style(create_params.style, create_params.ex_style));
          // On Windows the default size icon of toolbar is 16x16, on macOS is 32x32 and on gtk is 24x24...
          #if defined(__WXMSW__)
          static_cast<wxToolBar*>(control())->SetToolBitmapSize({16, 16});
          #elif defined(__WXOSX__)
          static_cast<wxToolBar*>(control())->SetToolBitmapSize({32, 32});
          #elif defined(__WXGTK__)
          static_cast<wxToolBar*>(control())->SetToolBitmapSize({24, 24});
          #else
          static_cast<wxToolBar*>(control())->SetToolBitmapSize({16, 16});
          #endif
          #if defined(__WXMSW__)
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
          
          if ((style & TBSTYLE_NODIVIDER) == TBSTYLE_NODIVIDER) wx_style |= wxTB_NODIVIDER;
          if ((style & TBSTYLE_NOSHOWICON) == TBSTYLE_NOSHOWICON) wx_style |= wxTB_NOICONS;
          if ((style & TBSTYLE_SHOWTEXT) == TBSTYLE_SHOWTEXT) wx_style |= wxTB_TEXT;
          if ((style & TBSTYLE_TEXTRIGHTALIGN) == TBSTYLE_TEXTRIGHTALIGN) wx_style |= wxTB_HORZ_LAYOUT;
          if ((style & TBSTYLE_FLAT) == TBSTYLE_FLAT) wx_style |= wxTB_FLAT;
          if ((style & TBSTYLE_TOOLTIPS) != TBSTYLE_TOOLTIPS) wx_style |= wxTB_NO_TOOLTIPS;
          
          return wx_style;
        }
        
        bool Destroy() override {
          // Workaround : When wxWidgets destroy the tool bar tool with a control or drop down menu, it destroy the control and the drop down menu. But with xtd, the control and the drop down menu are managed by xtd and they can be destroyed.
          // To prevent destroy control and drop down menu change the tool bar tool style to wxTOOL_STYLE_BUTTON et set drop down menu to null...
          __reset_tool_bar_tools_styles__(static_cast<wxToolBar*>(control()));
          /// end Workaround
          
          return control()->Destroy();
        }
        
        void SetClientSize(int32 width, int32 height) override {
        }
        
        void SetPosition(const wxPoint& location) override {
        }
        
        void SetSize(int32 width, int32 height) override {
        }
      };
    }
  }
}
