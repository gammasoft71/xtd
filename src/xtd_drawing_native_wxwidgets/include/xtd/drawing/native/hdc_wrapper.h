#pragma once

#include <cstdint>
#include <wx/dc.h>
#include <wx/dcscreen.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class hdc_wrapper {
      public:
        hdc_wrapper() = default;
        template<typename hdc_t, typename ...args_type>
        void create(args_type&& ...args) {
          hdc_t* hdc = new hdc_t(args...);
          hdc_ = hdc;
          graphics_ = wxGraphicsContext::Create(*hdc);
        }
        template<>
        void create<wxScreenDC>() {
          hdc_ = new wxScreenDC();
          graphics_ = wxGraphicsContext::Create();
        }
        ~hdc_wrapper() {
          delete graphics_;
          delete hdc_;
        }
        const wxDC& hdc() const {return *hdc_;}
        wxDC& hdc() {return *hdc_;}
        const wxGraphicsContext& graphics() const {return *graphics_;}
        wxGraphicsContext& graphics() {return *graphics_;}

      private:
        wxDC* hdc_ = nullptr;
        wxGraphicsContext* graphics_ = nullptr;
      };
    }
  }
}

