#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/gauge.h>
#include <wx/timer.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_progress_bar : public control_handler {
      public:
        wx_progress_bar(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxGauge>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, 100, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::progress_bar_to_wx_style(create_params.style(), create_params.ex_style()));
          
          this->timer_marquee.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
            if (event.GetTimer().GetId() == this->timer_marquee.GetId() && !static_cast<wxGauge*>(this->control())->IsBeingDeleted())
              static_cast<wxGauge*>(this->control())->Pulse();
          });
        }
        
        ~wx_progress_bar() {
          this->timer_marquee.Stop();
        }

        void marquee(bool marquee, size_t animation_speed) {
          if (marquee) this->timer_marquee.Start(animation_speed);
          else this->timer_marquee.Stop();
        }
        
        int32_t minimum_ = 0;
        int32_t maximum_ = 100;
        wxTimer timer_marquee;
      };
    }
  }
}
