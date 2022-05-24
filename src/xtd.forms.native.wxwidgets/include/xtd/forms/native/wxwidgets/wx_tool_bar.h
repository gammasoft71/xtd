#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

// Workaround : When wxWidgets destroy the tool bar tool with a control, it destroy the control. But with xtd, the control is managed by xtd and it can be destroyed.
#if !defined (WIN32)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-macro"
#endif
#define protected public
#define private public
// end Workaround
#include <wx/toolbar.h>
// Workaround : When wxWidgets destroy the tool bar tool with a control, it destroy the control. But with xtd, the control is managed by xtd and it can be destroyed.
#undef protected
#undef private
#if !defined (WIN32)
#pragma clang diagnostic pop
#endif
// end Workaround
#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/tool_bar_styles.h>
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
          if ((style & TBSTYLE_TEXTRIGHTALIGN) == TBSTYLE_TEXTRIGHTALIGN) wx_style |= wxTB_HORZ_LAYOUT;
          if ((style & TBSTYLE_FLAT) == TBSTYLE_FLAT) wx_style |= wxTB_FLAT;
          if ((style & TBSTYLE_TOOLTIPS) != TBSTYLE_TOOLTIPS) wx_style |= wxTB_NO_TOOLTIPS;

          return wx_style;
        }

        bool Destroy() override {
          // Workaround : When wxWidgets destroy the tool bar tool with a control or drop down menu, it destroy the control and the drop down menu. But with xtd, the control and the drop down menu are managed by xtd and they can be destroyed.
          // To prevent destroy control and drop down menu change the tool bar tool style to wxTOOL_STYLE_BUTTON et set drop down menu to null...
          for (size_t index = 0; index < static_cast<wxToolBar*>(control())->GetToolsCount(); ++index) {
            static_cast<wxToolBar*>(control())->GetToolByPos(index)->m_dropdownMenu = nullptr;
            static_cast<wxToolBar*>(control())->GetToolByPos(index)->m_toolStyle = wxTOOL_STYLE_BUTTON;
          }
          /// end Workaround

          return control()->Destroy();
        }

        void SetClientSize(int32_t width, int32_t height) override {
        }

        void SetPosition(const wxPoint& location) override {
        }

        void SetSize(int32_t width, int32_t height) override {
        }
      };
    }
  }
}
