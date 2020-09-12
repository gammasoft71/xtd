#pragma once

#include <cstdint>
#include <wx/dc.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class hdc_wrapper {
      public:
        hdc_wrapper() = default;
        ~hdc_wrapper() {
          delete graphics_;
          delete hdc_;
        }
        const wxDC& hdc() const {return *hdc_;}
        wxDC& hdc() {return *hdc_;}
        
        template<typename hdc_t, typename ...args_type>
        void create(args_type&& ...args) {
          hdc_t* hdc = new hdc_t(args...);
          hdc_ = hdc;
          graphics_ = create_graphics(*hdc);
        }
        
        void create_memory_hdc(wxBitmap* bitmap, wxImage* image) {
          auto hdc = new wxMemoryDC(*bitmap);
          hdc_ = hdc;
          bitmap_ = bitmap;
          image_ = image;
          graphics_ = create_graphics(*hdc);
        }

        const wxGraphicsContext& graphics() const {return *graphics_;}
        wxGraphicsContext& graphics() {return *graphics_;}
        
        void apply_update() {
          if (bitmap_ && image_) *image_ = bitmap_->ConvertToImage();
        }

      private:
        template<typename hdc_t>
        wxGraphicsContext* create_graphics(const hdc_t& hdc) {return wxGraphicsContext::Create(hdc);}
        wxGraphicsContext* create_graphics(const wxScreenDC& hdc) {return wxGraphicsContext::Create();}
        wxDC* hdc_ = nullptr;
        wxBitmap* bitmap_ = nullptr;
        wxImage* image_ = nullptr;
        wxGraphicsContext* graphics_ = nullptr;
      };
    }
  }
}

