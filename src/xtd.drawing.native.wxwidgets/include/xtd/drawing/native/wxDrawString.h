#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "hdc_wrapper.h"
#include "wx_brush.h"
#include "wxConicalGradient.h"
#include <xtd/drawing/native/hot_key_prefixes>
#include <xtd/drawing/native/string_formats>
#include <xtd/drawing/native/string_trimmings>
#include <xtd/io/path>
#include <xtd/convert_string>
#include <xtd/math>
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
        static void DrawString(intptr handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float angle, wxAlignment align, int32 hotKeyPrefix, int32 trimming) {
          DrawString(handle, text, font, brush, x, y, 0.0f, 0.0f, angle, align, hotKeyPrefix, trimming, 0);
        }
        
        static void DrawString(intptr handle, const wxString& text, const wxFont& font, const wx_brush& brush, float x, float y, float widthF, float heightF, float angle, wxAlignment align, int32 hotKeyPrefix, int32 trimming, int32 stringFormats) {
          auto width = static_cast<int32>(std::floor(widthF));
          auto height = static_cast<int32>(std::floor(heightF));
          auto noClip = (stringFormats & SF_NO_CLIP) == SF_NO_CLIP || (width == 0 && height == 0); // && angle == 0;
          auto directionVertical = (stringFormats & SF_VERTICAL) == SF_VERTICAL;
          auto measureTrailingSpaces = (stringFormats & SF_MEASURE_TRAILING_SPACES) == SF_MEASURE_TRAILING_SPACES;
          auto rightToLeft = (stringFormats & SF_RIGHT_TO_LEFT) == SF_RIGHT_TO_LEFT;
          
          if (rightToLeft) {
            auto newAlign = static_cast<int32>(align);
            if ((align & wxALIGN_RIGHT) == wxALIGN_RIGHT) {
              newAlign &= ~wxALIGN_RIGHT;
              newAlign |= wxALIGN_LEFT;
            } else if ((newAlign & wxALIGN_CENTER_HORIZONTAL) != wxALIGN_CENTER_HORIZONTAL) {
              newAlign &= ~wxALIGN_LEFT;
              newAlign |= wxALIGN_RIGHT;
            }
            align = static_cast<wxAlignment>(newAlign);
          }
          
          if (width == 0 && height == 0) MeasureString(reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc(), text, font, width, height, measureTrailingSpaces);
          
          if (directionVertical) {
            x = x + width;
            width = -width;
            angle += 90.0f;
          }
          
          auto& dc = reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->hdc();
          dc.SetFont(font);
          
          wxArrayString strings;
          if ((stringFormats & SF_NO_WRAP) != SF_NO_WRAP) strings = WrapText(dc, text, font, width, height, directionVertical, measureTrailingSpaces);
          else strings.push_back(text);
          auto string = ToString(dc, FormatString(dc, strings, width, height, hotKeyPrefix, trimming, directionVertical), font, width, height, (stringFormats & SF_LINE_LIMIT) == SF_LINE_LIMIT, directionVertical);
          
          if (brush.is_solid_brush()) DrawStringWithSolidBrush(dc, string, font, brush, x, y, width, height, angle, align, hotKeyPrefix, noClip);
          else DrawStringWithGradientBrush(handle, string, font, brush, x, y, width, height, angle, align, hotKeyPrefix, noClip);
        }
        
        static void MeasureString(wxDC& dc, const wxString& text, const wxFont& font, float& width, float& height, bool measureTrailingSpaces) {
          width = 0.0f;
          height = 0.0f;
          dc.SetFont(font);
          auto strings = wxSplit(text, '\n');
          for (auto string : strings) {
            auto lineWidth = 0.0;
            auto lineHeight = 0.0;
            auto lineSize = dc.GetTextExtent(measureTrailingSpaces ? string : string.Trim());
            lineWidth = lineSize.GetWidth();
            lineHeight = lineSize.GetHeight();
            width = std::max(width, static_cast<float>(lineWidth));
            height += static_cast<float>(lineHeight);
            
            // Workaround : with wxWidgets version <= 3.1.5 width size text is too small on macOS and linux.
            #if !defined(__WXMSW__)
            if (font.GetStyle() > wxFontStyle::wxFONTSTYLE_NORMAL) width += std::ceil(dc.GetFontMetrics().averageWidth / 2.3f);
            #endif
            // Workaround : with wxWidgets version <= 3.3 height size text is too small on macOS.
            #if defined(__WXOSX__)
            height += dc.GetFontMetrics().height / 4.0f;
            #endif
          }
        }
        
        static void MeasureString(wxDC& dc, const wxString& text, const wxFont& font, int32& width, int32& height, bool measureTrailingSpaces) {
          auto widthF = 0.0f;
          auto heightF = 0.0f;
          MeasureString(dc, text, font, widthF, heightF, measureTrailingSpaces);
          width = static_cast<float>(std::ceil(widthF));
          height = static_cast<float>(std::ceil(heightF));
        }
        
        static wxString FormatString(wxDC& dc, const wxString& string, float width, int32 hotKeyPrefix, int32 trimming) {
          return TrimString(dc, hotKeyPrefix != HKP_NONE ? RemoveHotKeyPrefixLocations(string) : string, dc.GetFont(), width, trimming);
        }
        
        static wxString TrimString(wxDC& dc, const wxString& string, const wxFont& font, float width, int32 trimming) {
          dc.SetFont(font);
          auto strings = wxSplit(string, '\n');
          for (auto& line : strings) {
            switch (trimming) {
              case ST_NONE: break;
              case ST_CHARACTER: line = TrimmingCharacter(dc, line, font, width, ustring::empty_string); break;
              case ST_WORD: line = TrimmingWord(dc, line, font, width, ustring::empty_string); break;
              case ST_ELLIPSIS_CHARACTER:  line = TrimmingCharacter(dc, line, font, width, "..."); break;
              case ST_ELLIPSIS_WORD: line = TrimmingWord(dc, line, font, width, "..."); break;
              case ST_ELLIPSIS_PATH: line = TrimmingPath(dc, line, font, width, "..."); break;
              default: break;
            }
          }
          return wxJoin(strings, '\n');
        }
        
      private:
        static wxString TrimmingCharacter(wxDC& dc, const wxString& string, const wxFont& font, float width, const wxString& ellips) {
          if (GetTextWidth(dc, string, font, true) < width)  return string;
          
          wxString result;
          for (auto index = 0_z; index < string.size(); ++index) {
            if (GetTextWidth(dc, (result + string[index]).Trim() + ellips, font, true) > width) return result + ellips;
            result += string[index];
          }
          
          return result;
        }
        
        static wxString TrimmingWord(wxDC& dc, const wxString& string, const wxFont& font, float width, const wxString& ellips) {
          if (GetTextWidth(dc, string, font, false) < width) return string;
          
          wxString result;
          auto words = wxSplit(string, ' ');
          for (auto index = 0_z; index < words.size(); ++index) {
            auto space = index ? " " : "";
            if (GetTextWidth(dc, (result + space + words[index]).Trim() + ellips, font, true) > width)  return result + ellips;
            result += space + words[index];
          }
          
          return result;
        }
        
        static wxString TrimmingPath(wxDC& dc, const wxString& string, const wxFont& font, float width, const wxString& ellips) {
          if (GetTextWidth(dc, string, font, true) < width)  return string;
          
          wxString result;
          auto paths = wxSplit(string, xtd::io::path::directory_separator_char());
          if (GetTextWidth(dc, paths[paths.size() - 1], font, true) > width)  return paths[paths.size() - 1];
          for (auto index = 0_z; index < paths.size() - 1; ++index) {
            auto separator = index ? wxString(xtd::io::path::directory_separator_char()) : wxString();
            if (GetTextWidth(dc, result + separator + ellips + xtd::io::path::directory_separator_char() + paths[index] + xtd::io::path::directory_separator_char() + paths[paths.size() - 1], font, true) > width)  return result + xtd::io::path::directory_separator_char() + ellips + xtd::io::path::directory_separator_char() + paths[paths.size() - 1];
            result += separator + paths[index];
          }
          
          return result + xtd::io::path::directory_separator_char() + paths[paths.size() - 1];
        }
        
        static void DrawStringWithSolidBrush(wxDC& dc, const wxString& string, const wxFont& font, const wx_brush& brush, int32 x, int32 y, int32 width, int32 height, float angle, wxAlignment align, int32 hotKeyPrefix, bool noClip) {
          if (!noClip) dc.SetClippingRegion({static_cast<int32>(x), static_cast<int32>(y)}, {static_cast<int32>(width), static_cast<int32>(height)});
          dc.SetTextForeground(brush.get_solid_brush().color);
          auto hotKeyPrefixLocation = GetFirstHotKeyPrefixLocations(string);
          if (angle == 0) dc.DrawLabel(string, wxRect(x, y, width, height), align, hotKeyPrefix == HKP_SHOW ? hotKeyPrefixLocation : -1);
          else dc.DrawRotatedText(string, x, y, -angle);
          if (!noClip) dc.DestroyClippingRegion();
        }
        
        static void DrawStringWithGradientBrush(intptr handle, const wxString& string, const wxFont& font, const wx_brush& brush, int32 x, int32 y, int32 width, int32 height, float angle, wxAlignment align, int32 hotKeyPrefix, bool noClip) {
          auto maxSize = math::max(width, height);
          wxImage image(x + maxSize, y + maxSize);
          if (brush.is_conical_gradiant_brush())
            image = wxConicalGradient::CreateBitmap(wxSize(maxSize, maxSize), brush.get_conical_gradiant_brush().colors, brush.get_conical_gradiant_brush().center_point, brush.get_conical_gradiant_brush().angle).ConvertToImage();
          else {
            image.InitAlpha();
            for (auto y1 = 0; y1 < static_cast<int32>(maxSize + y); y1++)
              for (auto x1 = 0; x1 < static_cast<int32>(maxSize + x); x1++)
                image.SetAlpha(x1, y1, 0);
            wxBitmap bitmap(image);
            auto bitmapGraphics = wxGraphicsContext::Create(wxMemoryDC(bitmap));
            bitmapGraphics->SetBrush(wx_brush::to_graphics_brush(*reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics(), brush));
            bitmapGraphics->DrawRectangle(0, 0, maxSize + x, maxSize + y);
            image = bitmap.ConvertToImage();
          }
          
          wxBitmap bitmapMask(x + maxSize, y + maxSize);
          wxMemoryDC bitmapMaskDc(bitmapMask);
          bitmapMaskDc.SetFont(font);
          bitmapMaskDc.SetTextForeground(wxColour(255, 255, 255));
          auto hotKeyPrefixLocation = GetFirstHotKeyPrefixLocations(string);
          if (angle == 0) bitmapMaskDc.DrawLabel(string, wxRect(x, y, width, height), align, hotKeyPrefix == HKP_SHOW ? hotKeyPrefixLocation : -1);
          else bitmapMaskDc.DrawRotatedText(string, x, y, -angle);
          
          image.SetMaskFromImage(bitmapMask.ConvertToImage(), 0, 0, 0);
          wxGraphicsContext& graphics = *reinterpret_cast<xtd::drawing::native::hdc_wrapper*>(handle)->graphics();
          if (!noClip) graphics.Clip(x, y, width, height);
          graphics.DrawBitmap(wxBitmap(image), 0, 0, maxSize + x, maxSize + y);
          if (!noClip) graphics.ResetClip();
        }
        
        static wxArrayString FormatString(wxDC& dc, const wxArrayString& strings, int32 width, int32 height, int32 hotKeyPrefix, int32 trimming, bool directionVertical) {
          if (directionVertical) {
            std::swap(width, height);
            height = std::abs(height);
          }
          auto results = strings;
          std::transform(results.begin(), results.end(), results.begin(), [&](auto string) {return FormatString(dc, string, width, hotKeyPrefix, trimming);});
          return results;
        }
        
        static int32 GetFirstHotKeyPrefixLocations(const wxString& str) {
          if (str.IsEmpty()) return -1;
          for (auto index = 0_z; index < str.size() - 1; index++)
            if (str[index] == '&' && str[index + 1] != '&') return static_cast<int32>(index);
          return -1;
        }
        
        static int32 GetTextHeight(wxDC& dc, const wxString& str, const wxFont& font) noexcept {
          auto width = 0;
          auto height = 0;
          MeasureString(dc, str, font, width, height, true);
          return height;
        }
        
        static int32 GetTextWidth(wxDC& dc, const wxString& str, const wxFont& font, bool measureTrailingSpaces) noexcept {
          auto width = 0;
          auto height = 0;
          MeasureString(dc, str, font, width, height, measureTrailingSpaces);
          return width;
        }
        
        static wxString RemoveHotKeyPrefixLocations(const wxString& str) {
          wxString result;
          if (str.IsEmpty() && GetFirstHotKeyPrefixLocations(str) == -1) return str;
          for (auto index = 0_z; index < str.size() - 1; index++)
            if (str[index] != '&' || str[index + 1] == '&') result += str[index];
          result += str[str.size() - 1];
          return result;
        }
        
        static wxString ToString(wxDC& dc, const wxArrayString& strings, const wxFont& font, int32 width, int32 height, bool lineLimit, bool directionVertical) {
          wxString result;
          if (directionVertical) {
            std::swap(width, height);
            height = std::abs(height);
          }
          for (auto& string : strings) {
            if (lineLimit && GetTextHeight(dc, result + (string.size() ?  string : wxString(" ")) + "\n", font) > height) break;
            result += (string.size() ?  string : wxString(" ")) + "\n";
          }
          if (result.size() > 0) result.Remove(result.size() - 1);
          return result;
        }
        
        static wxArrayString WrapText(wxDC& dc, const wxString& string, const wxFont& font, int32 width, int32 height, bool directionVertical, bool measureTrailingSpaces) noexcept {
          if (directionVertical) std::swap(width, height);
          auto strings = wxSplit(string, '\n');
          wxArrayString results;
          
          for (auto sentence : strings) {
            auto words = wxSplit(sentence, ' ');
            if (words.size() == 0) results.push_back(" ");
            else for (auto index = 0_z; index < words.size(); ++index) {
                results.push_back(words[index]);
                while (index + 1 < words.size() && GetTextWidth(dc, results[results.size() - 1] + " " + words[index + 1], font, measureTrailingSpaces) <= width)
                  results[results.size() - 1] += " " + words[++index];
              }
          }
          return results;
        }
      };
    }
  }
}
