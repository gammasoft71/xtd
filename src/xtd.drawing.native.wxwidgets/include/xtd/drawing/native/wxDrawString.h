#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "wx_brush.h"
#include <cmath>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcgraph.h>
#include <wx/graphics.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wxDrawString {
      public:
        static void DrawString(wxGraphicsContext& graphics, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float angle, wxAlignment align) {
          float width = 0.0f, height = 0.0f;
          measure_string(graphics, text, font, width, height);
          DrawString(graphics, text, font, brush, x, y, width, height, angle, align);
        }
        
        static void DrawString(wxGraphicsContext& graphics, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float width, float height, float angle, wxAlignment align) {
          if (brush.is_solid_brush()) {
            
          }
          wxBitmap bitmap;
        }
        
        static void measure_string(wxGraphicsContext& graphics, const wxString& text, const wxFont& font, float& width, float& height) {
          width = 0;
          height = 0;
          wxGCDC dc(&graphics);
          dc.SetFont(font);
          auto strings = wxSplit(text, '\n');
          for (auto string : strings) {
            double line_width = 0, line_height = 0;
            // Workaround : with wxWidgets version <= 3.1.4 wxGraphicsContext::GetTextExtent doesn't work with unicode on Windows.
            if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") {
              wxSize line_size = dc.GetTextExtent(string);
              line_width = line_size.GetWidth();
              line_height = line_size.GetHeight();
            } else {
              graphics.SetFont(font, { 0, 0, 0 });
              graphics.GetTextExtent(string, &line_width, &line_height);
            }
            width = std::max(width, static_cast<float>(line_width));
            height += static_cast<float>(line_height);
            
            // Workaround : with wxWidgets version <= 3.1.5 width size text is too small on macOS and linux.
            if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Windows" && font.GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(dc.GetFontMetrics().averageWidth / 2.3f);
          }
        }

      private:
        
      };
    }
  }
}
