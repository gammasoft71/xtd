#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <wx/dc.h>
#include <wx/dcbuffer.h>
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
          delete bitmap_;
          delete hdc_;
          delete hdc_base_;
        }
        
        wxGraphicsContext* graphics() {
          /// @Workaround : With wxWidgets on Gtk, we need recreate graphics context otherwise only the first operation is taken into account.
          #if defined(__WXGTK__)
          if (bitmap_ && image_) return wxGraphicsContext::Create(wxMemoryDC(*bitmap_));
          #endif
          return graphics_;
        }
        
        wxDC& hdc() {return *hdc_;}
        
        template<typename hdc_t, typename ...args_type>
        void create(args_type&& ...args) {
          hdc_t* handle = new hdc_t(args...);
          hdc_ = handle;
          if (graphics_) delete graphics_;
          graphics_ = create_graphics(*handle);
        }
        
        void create_buffered_hdc(wxDC* hdc_base) {
          auto handle = new wxBufferedDC(hdc_base);
          hdc_ = handle;
          hdc_base_ = hdc_base;
          graphics_ = create_graphics(*handle);
        }
        
        void create_memory_hdc(wxBitmap* bitmap, wxImage* image) {
          auto handle = new wxMemoryDC(*bitmap);
          hdc_ = handle;
          bitmap_ = bitmap;
          image_ = image;
          graphics_ = create_graphics(*handle);
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
        wxDC* hdc_base_ = nullptr;
      };
    }
  }
}

