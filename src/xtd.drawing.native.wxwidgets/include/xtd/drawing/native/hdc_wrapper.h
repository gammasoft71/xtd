#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/types>
#include <wx/dc.h>
#include <wx/dcbuffer.h>
#include <wx/dcmemory.h>
#include <wx/dcscreen.h>
#include <wx/graphics.h>
#include <cstdint>
#include <memory>

namespace xtd {
  namespace drawing {
    namespace native {
      class hdc_wrapper {
      public:
        hdc_wrapper() = default;
        
        wxGraphicsContext* graphics() {
          /// @Workaround : With wxWidgets on Gtk, we need recreate graphics context otherwise only the first operation is taken into account.
          #if defined(__WXGTK__)
          if (bitmap_ && image_) create_memory_hdc(image_);
          #endif
          return graphics_.get();
        }
        
        wxDC& hdc() {return *hdc_;}
        
        template<typename hdc_t, typename ...args_type>
        void create(args_type&& ...args) {
          auto handle = std::make_unique<hdc_t>(args...);
          graphics_.reset();
          graphics_ = create_graphics(*handle);
          hdc_ = std::move(handle);
        }
        
        void create_buffered_hdc(std::unique_ptr<wxDC>&& hdc_base) {
          hdc_base_ = std::move(hdc_base);
          auto handle = std::make_unique<wxBufferedDC>(hdc_base_.get());
          graphics_ = create_graphics(*handle);
          hdc_ = std::move(handle);
        }
        
        void create_memory_hdc(intptr image) {
          image_ = image;
          bitmap_ = std::make_unique<wxBitmap>(*reinterpret_cast<wxImage*>(image_));
          auto handle = std::make_unique<wxMemoryDC>(*bitmap_);
          graphics_ = create_graphics(*handle);
          hdc_ = std::move(handle);
        }
        
        void apply_update() {
          if (bitmap_ && image_) *reinterpret_cast<wxImage*>(image_) = bitmap_->ConvertToImage();
        }
        
      private:
        template<typename hdc_t>
        std::unique_ptr<wxGraphicsContext> create_graphics(const hdc_t& hdc) {return std::unique_ptr<wxGraphicsContext>(wxGraphicsContext::Create(hdc));}
        std::unique_ptr<wxGraphicsContext> create_graphics(const wxScreenDC& hdc) {return std::unique_ptr<wxGraphicsContext>(wxGraphicsContext::Create());}
        std::unique_ptr<wxBitmap> bitmap_;
        std::unique_ptr<wxGraphicsContext> graphics_;
        std::unique_ptr<wxDC> hdc_;
        std::unique_ptr<wxDC> hdc_base_;
        intptr image_ = 0;
      };
    }
  }
}

