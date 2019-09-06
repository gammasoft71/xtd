#pragma once
#include <xtd/forms/create_params.hpp>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/button.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_form : public control_handler {
      public:
        wx_form(const forms::create_params& create_params) {
          forms::create_params params = create_params;
          if (params.width() < 75) params.width(75);
          if (params.height() < 23) params.height(23);
          this->control_handler::create<wxFrame>(params.parent() ? ((control_handler*)params.parent())->control() : wxTheApp->GetTopWindow(), wxID_ANY, params.caption(), wxPoint(params.x(), params.y()), wxSize(params.width(), params.height()), control_handler::form_to_wx_style(params.style(), params.ex_style()));
          this->button_ = new wxButton(this->control(), wxID_ANY);
          this->control()->SetBackgroundColour(this->button_->GetBackgroundColour());
          this->control()->SetForegroundColour(this->button_->GetForegroundColour());
          this->button_->Hide();
          this->control()->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {event.Veto();});
        }
        
        void SetSize(int32_t width, int32_t height) override {
#if defined(__WXOSX__)
          if (width < 75) width = 75;
          if (height < 23) height = 23;
#endif
          this->control()->SetSize(width, height);
        }
        
      private:
        wxButton* button_;
      };
    }
  }
}
