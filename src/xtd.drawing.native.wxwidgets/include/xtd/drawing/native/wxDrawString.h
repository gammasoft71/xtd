#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "wx_brush.h"
#include "wxConicalGradient.h"
#include "hdc_wrapper.h"
#include <cmath>
#include <xtd/drawing/native/hot_key_prefixes.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/dcgraph.h>
#include <wx/graphics.h>
#include <wx/string.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wxDrawString {
      public:
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float width, float height, float angle, wxAlignment align, int32_t hot_key_prefix) {
          wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
          dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(width), static_cast<int32_t>(height)});
          DrawString(handle, text, font, brush, x, y, angle, align, hot_key_prefix);
          dc.DestroyClippingRegion();
        }
        
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float angle, wxAlignment align, int32_t hot_key_prefix) {
          float width = 0.0f, height = 0.0f;
          measure_string(handle, text, font, width, height);
          float max_size = math::max(width, height);
          if (brush.is_solid_brush()) {
            wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
            dc.SetFont(font);
            dc.SetTextForeground(brush.get_solid_brush().color);
            if (angle == 0) {
              auto text_to_show = text;
              auto hot_key_prefix_location = GetHotKeyPrefixLocations(text_to_show);
              if (hot_key_prefix != HKP_NONE && hot_key_prefix_location != -1)
                text_to_show = text_to_show.Remove(hot_key_prefix_location, 1);
              dc.DrawLabel(text_to_show, wxRect(x, y, width, height), align, hot_key_prefix == HKP_SHOW ? hot_key_prefix_location : -1);
            }
            else
              dc.DrawRotatedText(text, x, y, -angle);
          } else {
            wxImage image(x + max_size, y + max_size);
            if (brush.is_conical_gradiant_brush()) {
              image = wxConicalGradient::CreateBitmap(wxSize(max_size, max_size), brush.get_conical_gradiant_brush().colors, brush.get_conical_gradiant_brush().center_point, brush.get_conical_gradiant_brush().angle).ConvertToImage();
            } else {
              image.InitAlpha();
              for (int y1 = 0; y1 < static_cast<int32_t>(max_size + y); y1++)
                for (int x1 = 0; x1 < static_cast<int32_t>(max_size + x); x1++)
                  image.SetAlpha(x1, y1, 0);
              wxBitmap bitmap(image);
              auto bitmap_graphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
              bitmap_graphics->SetBrush(wx_brush::to_graphics_brush(*reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics(), brush));
              bitmap_graphics->DrawRectangle(0, 0, max_size + x, max_size + y);
              image = bitmap.ConvertToImage();
            }
            
            wxBitmap bitmap_mask(x + max_size, y + max_size);
            wxMemoryDC bitmap_mask_dc(bitmap_mask);
            bitmap_mask_dc.SetFont(font);
            bitmap_mask_dc.SetTextForeground(wxColour(255, 255, 255));
            if (angle == 0)
              bitmap_mask_dc.DrawLabel(text, wxRect(x, y, width, height), align);
            else
              bitmap_mask_dc.DrawRotatedText(text, x, y, -angle);
            
            image.SetMaskFromImage(bitmap_mask.ConvertToImage(), 0, 0, 0);
            wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
            graphics.DrawBitmap(wxBitmap(image), 0, 0, max_size + x, max_size + y);
          }
        }
        
        static void measure_string(intptr_t handle, const wxString& text, const wxFont& font, float& width, float& height) {
          width = 0;
          height = 0;
          wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
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
              wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
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
        static int32_t GetHotKeyPrefixLocations(const wxString& str) {
          if (str.IsEmpty()) return -1;
          for (auto index = 0U; index < str.size() - 1; index++)
            if (str[index] == '&' && str[index + 1] != '&') return static_cast<int32_t>(index);
          return -1;
        }
      };
    }
  }
}
