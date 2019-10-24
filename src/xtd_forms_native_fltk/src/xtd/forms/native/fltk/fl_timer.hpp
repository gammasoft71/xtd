#pragma once
#include <xtd/xtd.delegates>
#include <FL/Fl.H>

namespace xtd {
  namespace forms {
    namespace native {
      class fl_timer {
      public:
        fl_timer(delegate<void(const event_args&)> tick) : tick_(tick) {}
        
        void Start(int32_t interval) {
          enable_timer_ = true;
          interval_ = (double)interval / 1000;
          Fl::add_timeout(interval_, on_timer_tick);
        }
        
        void Stop() {
          enable_timer_ = false;
        }
        
      private:
        static void on_timer_tick(void* timer) {
          try {
            ((fl_timer*)timer)->tick_(event_args::empty);
            if (((fl_timer*)timer)->enable_timer_)
            Fl::add_timeout(((fl_timer*)timer)->interval_, on_timer_tick);
          } catch(...) {
          }
        }

        delegate<void(const event_args&)> tick_;
        bool enable_timer_ = false;
        double interval_ = 1000;
      };
    }
  }
}
