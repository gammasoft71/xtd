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
#include <xtd/drawing/native/string_formats.h>
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
          DrawString(handle, text, font, brush, x, y, 0.0f, 0.0f, angle, align, hot_key_prefix, trimming, 0);
        }
        
        static void DrawString(intptr_t handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float width_, float height_, float angle, wxAlignment align, int32_t hot_key_prefix, int32_t trimming, int32_t string_formats) {
          int32_t width = std::floor(width_);
          int32_t height = std::floor(height_);

          bool no_wrap = (string_formats & SF_NO_WRAP) == SF_NO_WRAP;
          bool no_clip = (string_formats & SF_NO_CLIP) == SF_NO_CLIP || (width == 0 && height == 0); // && angle == 0;
          bool line_limit = (string_formats & SF_LINE_LIMIT) == SF_LINE_LIMIT;
          bool direction_vertical = (string_formats & SF_VERTICAL) == SF_VERTICAL;

          if ((string_formats & SF_RIGHT_TO_LEFT) & SF_RIGHT_TO_LEFT) {
            int32_t new_align = static_cast<int32_t>(align);
            if ((new_align & wxALIGN_LEFT) == wxALIGN_LEFT) {
              new_align &= ~wxALIGN_LEFT;
              new_align |= wxALIGN_RIGHT;
            } else if ((align & wxALIGN_RIGHT) == wxALIGN_RIGHT) {
              new_align &= ~wxALIGN_RIGHT;
              new_align |= wxALIGN_LEFT;
            }
            align = static_cast<wxAlignment>(new_align);
          }

          if (width == 0 && height == 0) {
            measure_string(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), text, font, width, height);
          }
          
          if (direction_vertical) {
            x = x + width;
            width = -width;
            angle += 90.0f;
          }

          float max_size = math::max(width, height);
          if (brush.is_solid_brush()) {
            wxDC& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
            if (!no_clip) dc.SetClippingRegion({static_cast<int32_t>(x), static_cast<int32_t>(y)}, {static_cast<int32_t>(width), static_cast<int32_t>(height)});
            dc.SetFont(font);
            dc.SetTextForeground(brush.get_solid_brush().color);
            if (angle == 0) {
              auto hot_key_prefix_location = GetHotKeyPrefixLocations(text);
              auto text_to_draw = FormatString(dc, text, width, align, hot_key_prefix, trimming);
              dc.DrawLabel(no_wrap ? text_to_draw : wrap_text(dc, text_to_draw, font, width, height, line_limit, direction_vertical), wxRect(x, y, width, height), align, hot_key_prefix == HKP_SHOW ? hot_key_prefix_location : -1);
            } else
              dc.DrawRotatedText(no_wrap ? text : wrap_text(dc, text, font, width, height, line_limit, direction_vertical), x, y, -angle);
            if (!no_clip) dc.DestroyClippingRegion();
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
              bitmap_mask_dc.DrawLabel(no_wrap ? text : wrap_text(bitmap_mask_dc, text, font, width, height, line_limit, direction_vertical), wxRect(x, y, width, height), align);
            else
              bitmap_mask_dc.DrawRotatedText(no_wrap ? text : wrap_text(bitmap_mask_dc, text, font, width, height, line_limit, direction_vertical), x, y, -angle);
              
            image.SetMaskFromImage(bitmap_mask.ConvertToImage(), 0, 0, 0);
            wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
            if (!no_clip) graphics.Clip(x, y, width, height);
            graphics.DrawBitmap(wxBitmap(image), 0, 0, max_size + x, max_size + y);
            if (!no_clip) graphics.ResetClip();
          }
        }
        
        static void measure_string(wxDC& dc, const wxString& text, const wxFont& font, int32_t& width, int32_t& height) {
          width = 0;
          height = 0;
          dc.SetFont(font);
          auto strings = wxSplit(text, '\n');
          for (auto string : strings) {
            double line_width = 0.0, line_height = 0.0;
            wxSize line_size = dc.GetTextExtent(string);
            line_width = line_size.GetWidth();
            line_height = line_size.GetHeight();
            width = std::max(width, static_cast<int32_t>(std::ceil(line_width)));
            height += static_cast<int32_t>(std::ceil(line_height));
            
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
        
        static int32_t get_text_width(wxDC& dc, const wxString& str, const wxFont& font) noexcept {
          int32_t width = 0, height = 0;
          measure_string(dc, str, font, width, height);
          return width;
        }
        
        static int32_t get_text_height(wxDC& dc, const wxString& str, const wxFont& font) noexcept {
          int32_t width = 0, height = 0;
          measure_string(dc, str, font, width, height);
          return height;
        }
        
        static wxString wrap_text(wxDC& dc, const wxString& string, const wxFont& font, int32_t width, int32_t height, bool line_limit, bool direction_vertical) noexcept {
          if (direction_vertical) std::swap(width, height);
          auto string_lines = wxSplit(string, '\n');
          wxArrayString result_lines;

          for (auto sentence : string_lines) {
            auto words = wxSplit(sentence, ' ');
            if (words.size() == 0) result_lines.push_back(" ");
            else for (size_t index = 0; index < words.size(); ++index) {
              result_lines.push_back(words[index]);
              while (index + 1 < words.size() && get_text_width(dc, result_lines[result_lines.size() - 1] + " " + words[index + 1], font) <= width)
                result_lines[result_lines.size() - 1] += " " + words[++index];
            }
          }
          
          wxString result;
          if (direction_vertical) height = std::abs(height);
          for (auto& line : result_lines) {
            if (line_limit && get_text_height(dc, result + (line.size() ?  line : wxString(" ")) + "\n", font) > height) break;
            result += (line.size() ?  line : wxString(" ")) + "\n";
          }
          if (result.size() > 0) result.Remove(result.size() - 1);
          
          return result;
        }
      };
    }
  }
}
