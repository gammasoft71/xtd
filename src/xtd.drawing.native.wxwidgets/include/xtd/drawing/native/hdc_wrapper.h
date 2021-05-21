#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

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
          if (graphics_) delete graphics_;
          if (bitmap_) delete bitmap_;
          if (hdc_) delete hdc_;
        }
 
        wxGraphicsContext* graphics() {
          /// @Workaround : With wxWidgets on Gtk, we need recreate graphics context otherwise only the first operation is taken into account.
          if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix" && bitmap_ && image_) return wxGraphicsContext::Create(wxMemoryDC(*bitmap_));
          return graphics_;
        }

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

