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
#include <xtd/drawing/native/string_trimmings.h>
#include <xtd/convert_string.h>
#include <wx/control.h>
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
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float angle, wxAlignment align, int32_t hot_key_prefix, int32_t trimming) {
          float width = 0.0f, height = 0.0f;
          measure_string(handle, text, font, width, height);
          DrawString(handle, text, font, brush, x, y, width, height, angle, align, hot_key_prefix, trimming);
        }
        
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float width, float height, float angle, wxAlignment align, int32_t hot_key_prefix, int32_t trimming) {
          float max_size = math::max(width, height);
          if (brush.is_solid_brush()) {
            wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
            if (angle == 0) dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(width), static_cast<int32_t>(height)});
            dc.SetFont(font);
            dc.SetTextForeground(brush.get_solid_brush().color);
            if (angle == 0) {
              auto hot_key_prefix_location = GetHotKeyPrefixLocations(text);
              auto text_to_draw = FormatString(dc, text, width, align, hot_key_prefix, trimming);
              dc.DrawLabel(wrap_text(dc, text_to_draw, width), wxRect(x, y, width, height), align, hot_key_prefix == HKP_SHOW ? hot_key_prefix_location : -1);
            } else
              dc.DrawRotatedText(text, x, y, -angle);
            if (angle == 0) dc.DestroyClippingRegion();
          } else {
            wxImage image(x + max_size, y + max_size);
            if (brush.is_conical_gradiant_brush())
              image = wxConicalGradient::CreateBitmap(wxSize(max_size, max_size), brush.get_conical_gradiant_brush().colors, brush.get_conical_gradiant_brush().center_point, brush.get_conical_gradiant_brush().angle).ConvertToImage();
            else {
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
              bitmap_mask_dc.DrawLabel(wrap_text(bitmap_mask_dc, text, width), wxRect(x, y, width, height), align);
            else
              bitmap_mask_dc.DrawRotatedText(text, x, y, -angle);
              
            image.SetMaskFromImage(bitmap_mask.ConvertToImage(), 0, 0, 0);
            wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
            if (angle == 0) graphics.Clip(x, y, width, height);
            graphics.DrawBitmap(wxBitmap(image), 0, 0, max_size + x, max_size + y);
            if (angle == 0) graphics.ResetClip();
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
        
        static wxString FormatString(wxDC& dc, const wxString& string, float width, wxAlignment align, int32_t hot_key_prefix, int32_t trimming) {
          auto result = string;
          auto hot_key_prefix_location = GetHotKeyPrefixLocations(result);
          if (hot_key_prefix != HKP_NONE && hot_key_prefix_location != -1)
            result = result.Remove(hot_key_prefix_location, 1);
          switch (trimming) {
            case ST_NONE: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_NONE); break;
            case ST_CHARACTER: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_WORD: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_NONE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_CHARACTER: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_END, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_WORD: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_END, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            case ST_ELLIPSIS_PATH: result = wxControl::Ellipsize(result, dc, wxEllipsizeMode::wxELLIPSIZE_MIDDLE, width, wxEllipsizeFlags::wxELLIPSIZE_FLAGS_DEFAULT); break;
            default: break;
          }
          return result;
        }
        
        static int32_t GetHotKeyPrefixLocations(const wxString& str) {
          if (str.IsEmpty()) return -1;
          for (auto index = 0U; index < str.size() - 1; index++)
            if (str[index] == '&' && str[index + 1] != '&') return static_cast<int32_t>(index);
          return -1;
        }
        
        static int32_t get_text_width(wxDC& dc, const wxString& str) noexcept {
          int32_t text_width = 0, text_height = 0;
          dc.GetTextExtent(str, &text_width, &text_height);
          return text_width;
        }
        
        static wxString wrap_text(wxDC& dc, const wxString& string, int32_t width) noexcept {
          std::vector<xtd::ustring> words = xtd::convert_string::to_ustring(string.c_str().AsWChar()).split({' '});
          std::vector<xtd::ustring> lines;
          
          for (size_t index = 0; index < words.size(); ++index) {
            lines.push_back(words[index]);
            while (index + 1 < words.size() && get_text_width(dc, convert_string::to_wstring(lines[lines.size() - 1] + " " + words[index + 1])) <= width)
              lines[lines.size() - 1] += " " + words[++index];
          }
          
          return convert_string::to_wstring(xtd::ustring::join("\n", lines));
        }
      };
    }
  }
}
