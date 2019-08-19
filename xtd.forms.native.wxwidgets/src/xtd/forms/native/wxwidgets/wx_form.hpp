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
          this->control_handler::create<wxFrame>(create_params.parent() ? ((control_handler*)create_params.parent())->control() : wxTheApp->GetTopWindow(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::form_to_wx_style(create_params.style(), create_params.ex_style()));
          this->button_ = new wxButton(this->control(), wxID_ANY);
          this->control()->SetBackgroundColour(this->button_->GetBackgroundColour());
          this->control()->SetForegroundColour(this->button_->GetForegroundColour());
          this->button_->Hide();
          this->control()->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {event.Veto();});
        }
        
      private:
        wxButton* button_;
      };
    }
  }
}
