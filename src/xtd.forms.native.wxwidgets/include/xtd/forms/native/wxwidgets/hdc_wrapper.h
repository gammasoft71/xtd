#pragma once

#include <cstdint>
#include <wx/dc.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class hdc_wrapper {
        hdc_wrapper() = default;
        template<typename hdc_t, typename ...args_type>
        void create(args_type&& ...args) {hdc_ = new hdc_t(args...);}
        ~hdc_wrapper() {delete hdc_;}
        wxDC* hdc() const {return hdc_;}
      private:
        wxDC* hdc_ = nullptr;
      };
    }
  }
}

