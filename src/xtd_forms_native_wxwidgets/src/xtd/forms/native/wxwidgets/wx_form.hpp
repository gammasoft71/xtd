#pragma once
#include <xtd/xtd.diagnostics.hpp>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/class_styles.hpp>
#include <xtd/forms/native/window_styles.hpp>
#include <wx/app.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/button.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_form : public control_handler {
      public:
        wx_form(const forms::create_params& create_params) {
          wxPoint location = wxPoint(create_params.x(), create_params.y());
          wxSize size = wxSize(create_params.width(), create_params.height());
          if (size.GetWidth() > -1 && size.GetWidth() < 75) size.SetWidth(75);
          if (size.GetHeight() > -1 && size.GetHeight() < 23) size.SetHeight(23);
          this->modal_ = (create_params.ex_style() & WS_EX_MODALWINDOW) == WS_EX_MODALWINDOW;
          if (this->modal_)
            this->control_handler::create<wxDialog>(create_params.parent() ? ((control_handler*)create_params.parent())->control() : nullptr, wxID_ANY, create_params.caption().wstr(), location, size, style_to_wx_style(create_params.style(), create_params.ex_style(), create_params.class_style()));
          else
            this->control_handler::create<wxFrame>(create_params.parent() ? ((control_handler*)create_params.parent())->control() : nullptr, wxID_ANY, create_params.caption().wstr(), location, size, style_to_wx_style(create_params.style(), create_params.ex_style(), create_params.class_style()));
          this->button_ = new wxButton(this->control(), wxID_ANY);
          this->control()->SetBackgroundColour(this->button_->GetBackgroundColour());
          this->control()->SetForegroundColour(this->button_->GetForegroundColour());
          this->button_->Hide();
        }

        static long style_to_wx_style(size_t style, size_t ex_style, size_t class_style) {
          long wx_style = 0;

          if ((style & WS_MAXIMIZEBOX) == WS_MAXIMIZEBOX) wx_style |= wxMAXIMIZE_BOX;
          if ((style & WS_MINIMIZEBOX) == WS_MINIMIZEBOX) wx_style |= wxMINIMIZE_BOX;
          if ((style & WS_SYSMENU) == WS_SYSMENU) wx_style |= wxSYSTEM_MENU;
          if ((style & WS_THICKFRAME) == WS_THICKFRAME) wx_style |= wxRESIZE_BORDER;
          if ((style & WS_CAPTION) == WS_CAPTION) wx_style |= wxCAPTION;
          if ((style & WS_CLIPCHILDREN) == WS_CLIPCHILDREN) wx_style |= wxCLIP_CHILDREN;

          //if ((style & WS_MAXIMIZE) == WS_MAXIMIZE) wx_style |= wxMAXIMIZE;
          //if ((style & WS_MINIMIZE) == WS_MINIMIZE) wx_style |= wxMINIMIZE;

          if ((ex_style & WS_EX_APPWINDOW) != WS_EX_APPWINDOW) wx_style |= wxFRAME_NO_TASKBAR;
          if ((ex_style & WS_EX_TOOLWINDOW) == WS_EX_TOOLWINDOW) wx_style |= wxFRAME_TOOL_WINDOW;
          if ((ex_style & WS_EX_DLGMODALFRAME) == WS_EX_DLGMODALFRAME) wx_style &= ~(wxRESIZE_BORDER|wxSYSTEM_MENU);
          
          if ((class_style & CS_NOCLOSE) != CS_NOCLOSE) wx_style |= wxCLOSE_BOX;

          cdebug << format("wx_style = 0x{:X}", wx_style) << std::endl;
          
          return wx_style;
        }

        void SetSize(int32_t width, int32_t height) override {
#if defined(__WXOSX__)
          if (width < 75) width = 75;
          if (height < 23) height = 23;
#endif
          this->control_handler::SetSize(width, height);
        }

        bool modal() const {return this->modal_;}
        
      private:
        wxButton* button_;
        bool modal_ = false;
      };
    }
  }
}
