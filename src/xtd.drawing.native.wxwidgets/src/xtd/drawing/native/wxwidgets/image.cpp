#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image.h>
#include <xtd/drawing/native/compositing_modes.h>
#include <xtd/drawing/native/compositing_qualities.h>
#include <xtd/drawing/native/frame_dimension.h>
#include <xtd/drawing/native/image_flags.h>
#include <xtd/drawing/native/image_formats.h>
#include <xtd/drawing/native/rotate_flip_types.h>
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <atomic>
#include <wx/display.h>
#include <wx/image.h>
#include <wx/palette.h>
#include <wx/stream.h>

using namespace xtd;
using namespace xtd::drawing::native;

namespace {
  class StdInputStreamAdapter : public wxInputStream {
  public:
    explicit StdInputStreamAdapter(std::istream& stream): stream_{stream} {}
    
  protected:
    bool IsSeekable()  const override {return true;}
    
    size_t OnSysRead(void* buffer, size_t size) override {
      stream_.peek();
      if (stream_.fail() || stream_.bad()) m_lasterror = wxSTREAM_READ_ERROR;
      else if (stream_.eof()) m_lasterror = wxSTREAM_EOF;
      return stream_.readsome(static_cast<std::istream::char_type*>(buffer), size);
    }
    
    wxFileOffset OnSysSeek(wxFileOffset pos, wxSeekMode mode) override {
      switch (mode) {
        case wxFromStart: stream_.seekg(pos, std::ios::beg); break;
        case wxFromEnd: stream_.seekg(pos, std::ios::end); break;
        case wxFromCurrent: stream_.seekg(pos, std::ios::cur); break;
      }
      return stream_.tellg();
    }
    
    wxFileOffset OnSysTell() const override {return stream_.tellg();}
    
  private:
    std::istream& stream_;
  };
  
  class StdOutputStreamAdapter : public wxOutputStream {
  public:
    explicit StdOutputStreamAdapter(std::ostream& stream): stream_{stream} {}
    
  protected:
    bool IsSeekable()  const override {return false;}
    
    size_t OnSysWrite(const void* buffer, size_t size) override {
      if (stream_.fail() || stream_.bad()) m_lasterror = wxSTREAM_WRITE_ERROR;
      stream_.write(static_cast<const std::ostream::char_type*>(buffer), size);
      return size;
    }
    
  private:
    std::ostream& stream_;
  };
  
  wxBitmapType to_bitmap_type(size_t raw_format) {
    static std::map<size_t, wxBitmapType> raw_formats {{IFM_BMP, wxBITMAP_TYPE_BMP}, {IFM_MEMORY_BMP, wxBITMAP_TYPE_BMP_RESOURCE}, {IFM_ICO, wxBITMAP_TYPE_ICO}, {IFM_MEMORY_ICO, wxBITMAP_TYPE_ICO_RESOURCE}, {IFM_CUR, wxBITMAP_TYPE_CUR}, {IFM_MEMORY_CUR, wxBITMAP_TYPE_CUR_RESOURCE}, {IFM_XBM, wxBITMAP_TYPE_XBM}, {IFM_MEMORY_XBM, wxBITMAP_TYPE_XBM_DATA}, {IFM_XPM, wxBITMAP_TYPE_XPM}, {IFM_MEMORY_XPM, wxBITMAP_TYPE_XPM_DATA}, {IFM_TIFF, wxBITMAP_TYPE_TIFF}, {IFM_MEMORY_TIFF, wxBITMAP_TYPE_TIFF_RESOURCE}, {IFM_GIF, wxBITMAP_TYPE_GIF}, {IFM_MEMORY_GIF, wxBITMAP_TYPE_GIF_RESOURCE}, {IFM_PNG, wxBITMAP_TYPE_PNG}, {IFM_MEMORY_PNG, wxBITMAP_TYPE_PNG_RESOURCE}, {IFM_JPEG, wxBITMAP_TYPE_JPEG}, {IFM_MEMORY_JPEG, wxBITMAP_TYPE_JPEG_RESOURCE}, {IFM_PNM, wxBITMAP_TYPE_PNM}, {IFM_MEMORY_PNM, wxBITMAP_TYPE_PNM_RESOURCE}, {IFM_PCX, wxBITMAP_TYPE_PCX}, {IFM_MEMORY_PCX, wxBITMAP_TYPE_PCX_RESOURCE}, {IFM_PICT, wxBITMAP_TYPE_PICT}, {IFM_MEMORY_PICT, wxBITMAP_TYPE_PICT_RESOURCE}, {IFM_ICON, wxBITMAP_TYPE_ICON}, {IFM_MEMORY_ICON, wxBITMAP_TYPE_ICON_RESOURCE}, {IFM_ANI, wxBITMAP_TYPE_ANI}, {IFM_IIF, wxBITMAP_TYPE_IFF}, {IFM_TGA, wxBITMAP_TYPE_TGA}, {IFM_MACCUR, wxBITMAP_TYPE_MACCURSOR}, {IFM_MEMORY_MACCUR, wxBITMAP_TYPE_MACCURSOR_RESOURCE}};
    auto it = raw_formats.find(raw_format);
    return it == raw_formats.end() ? wxBitmapType::wxBITMAP_TYPE_ANY : it->second;
  }
  
  size_t to_raw_format(wxBitmapType bitmap_type) {
    static std::map<wxBitmapType, size_t> bitmap_types {{wxBITMAP_TYPE_BMP, IFM_BMP}, {wxBITMAP_TYPE_BMP_RESOURCE, IFM_MEMORY_BMP}, {wxBITMAP_TYPE_ICO, IFM_ICO}, {wxBITMAP_TYPE_ICO_RESOURCE, IFM_MEMORY_ICO}, {wxBITMAP_TYPE_CUR, IFM_CUR}, {wxBITMAP_TYPE_CUR_RESOURCE, IFM_MEMORY_CUR}, {wxBITMAP_TYPE_XBM, IFM_XBM}, {wxBITMAP_TYPE_XBM_DATA, IFM_MEMORY_XBM}, {wxBITMAP_TYPE_XPM, IFM_XPM}, {wxBITMAP_TYPE_XPM_DATA, IFM_MEMORY_XPM}, {wxBITMAP_TYPE_TIFF, IFM_TIFF}, {wxBITMAP_TYPE_TIFF_RESOURCE, IFM_MEMORY_TIFF}, {wxBITMAP_TYPE_GIF, IFM_GIF}, {wxBITMAP_TYPE_GIF_RESOURCE, IFM_MEMORY_GIF}, {wxBITMAP_TYPE_PNG, IFM_PNG}, {wxBITMAP_TYPE_PNG_RESOURCE, IFM_MEMORY_PNG}, {wxBITMAP_TYPE_JPEG, IFM_JPEG}, {wxBITMAP_TYPE_JPEG_RESOURCE, IFM_MEMORY_JPEG}, {wxBITMAP_TYPE_PNM, IFM_PNM}, {wxBITMAP_TYPE_PNM_RESOURCE, IFM_MEMORY_PNM}, {wxBITMAP_TYPE_PCX, IFM_PCX}, {wxBITMAP_TYPE_PCX_RESOURCE, IFM_MEMORY_PCX}, {wxBITMAP_TYPE_PICT, IFM_PICT}, {wxBITMAP_TYPE_PICT_RESOURCE, IFM_MEMORY_PICT}, {wxBITMAP_TYPE_ICON, IFM_ICON}, {wxBITMAP_TYPE_ICON_RESOURCE, IFM_MEMORY_ICON}, {wxBITMAP_TYPE_ANI, IFM_ANI}, {wxBITMAP_TYPE_IFF, IFM_IIF}, {wxBITMAP_TYPE_TGA, IFM_TGA}, {wxBITMAP_TYPE_MACCURSOR, IFM_MACCUR}, {wxBITMAP_TYPE_MACCURSOR_RESOURCE, IFM_MEMORY_MACCUR}};
    auto it = bitmap_types.find(bitmap_type);
    return it == bitmap_types.end() ? IFM_UNKNOWN : it->second;
  }
  
  size_t get_frame_resolution(const wxImage& image) {
    switch (image.GetType()) {
      case wxBITMAP_TYPE_BMP: return FD_PAGE;
      case wxBITMAP_TYPE_BMP_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_ICO: return FD_RESOLUTION;
      case wxBITMAP_TYPE_ICO_RESOURCE: return FD_RESOLUTION;
      case wxBITMAP_TYPE_CUR: return FD_TIME;
      case wxBITMAP_TYPE_CUR_RESOURCE: return FD_TIME;
      case wxBITMAP_TYPE_XBM: return FD_PAGE;
      case wxBITMAP_TYPE_XBM_DATA: return FD_PAGE;
      case wxBITMAP_TYPE_XPM: return FD_PAGE;
      case wxBITMAP_TYPE_XPM_DATA: return FD_PAGE;
      case wxBITMAP_TYPE_TIFF: return FD_PAGE;
      case wxBITMAP_TYPE_TIFF_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_GIF: return FD_TIME;
      case wxBITMAP_TYPE_GIF_RESOURCE: return FD_TIME;
      case wxBITMAP_TYPE_PNG: return FD_PAGE;
      case wxBITMAP_TYPE_PNG_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_JPEG: return FD_PAGE;
      case wxBITMAP_TYPE_JPEG_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_PNM: return FD_PAGE;
      case wxBITMAP_TYPE_PNM_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_PCX: return FD_PAGE;
      case wxBITMAP_TYPE_PCX_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_PICT: return FD_PAGE;
      case wxBITMAP_TYPE_PICT_RESOURCE: return FD_PAGE;
      case wxBITMAP_TYPE_ICON: return FD_RESOLUTION;
      case wxBITMAP_TYPE_ICON_RESOURCE: return FD_RESOLUTION;
      case wxBITMAP_TYPE_ANI: return FD_TIME;
      case wxBITMAP_TYPE_IFF: return FD_PAGE;
      case wxBITMAP_TYPE_TGA: return FD_PAGE;
      case wxBITMAP_TYPE_MACCURSOR: return FD_TIME;
      case wxBITMAP_TYPE_MACCURSOR_RESOURCE: return FD_TIME;
      default: return FD_PAGE;
    }
  }
}

intptr image::blur(intptr handle, int32 radius) {
  toolkit::initialize(); // Must be first
  if (handle == 0) return 0;
  wxImage* result = new wxImage(reinterpret_cast<wxImage*>(handle)->Blur(radius));
  return reinterpret_cast<intptr>(result);
}

void image::color_palette(intptr image, std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>>& entries, int32& flags) {
  wxPalette palette = reinterpret_cast<wxImage*>(image)->GetPalette();
  entries.clear();
  for (int32 index = 0; index < palette.GetColoursCount(); index++) {
    xtd::byte a = 255, r = 0, g = 0, b = 0;
    palette.GetRGB(index, &r, &g, &b);
    entries.push_back({a, r, g, b});
  }
  flags = 0;
}

intptr image::create(const ustring& filename, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  auto img = new wxImage(wxString(convert_string::to_wstring(filename)));
  frame_resolutions[get_frame_resolution(*img)] = img->GetImageCount(filename);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(std::istream& stream, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  StdInputStreamAdapter std_stream(stream);
  auto img = new wxImage(std_stream);
  frame_resolutions[get_frame_resolution(*img)] = img->GetImageCount(std_stream);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(const char* const* bits) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr>(new wxImage(bits));
}

intptr image::create(int32 width, int32 height) {
  toolkit::initialize(); // Must be first
  wxImage* result = new wxImage(width, height);
  result->InitAlpha();
  for (int32 y = 0; y < height; y++)
    for (int32 x = 0; x < width; x++)
      result->SetAlpha(x, y, 0);
  return reinterpret_cast<intptr>(result);
}

intptr image::create(intptr image, int32 width, int32 height) {
  toolkit::initialize(); // Must be first
  if (image == 0) return 0;
  wxImage* result = new wxImage(*reinterpret_cast<wxImage*>(image));
  result->Rescale(width, height, wxIMAGE_QUALITY_HIGH);
  return reinterpret_cast<intptr>(result);
}

intptr image::create(intptr image, int32 left, int32 top, int32 width, int32 height) {
  toolkit::initialize(); // Must be first
  if (image == 0) return 0;
  wxImage* result = new wxImage(reinterpret_cast<wxImage*>(image)->GetSubImage({left, top, width, height}));
  return reinterpret_cast<intptr>(result);
}

void image::destroy(intptr image) {
  reinterpret_cast<wxImage*>(image)->Destroy();
  delete reinterpret_cast<wxImage*>(image);
}

size_t image::flags(intptr image) {
  /// @todo see how to get flags dimension with wxWidgets.
  return IFL_NONE;
}

size_t frame_count(std::istream& stream) {
  StdInputStreamAdapter std_stream(stream);
  return wxImage::GetImageCount(std_stream);
}

size_t frame_count(const xtd::ustring& filename) {
  return wxImage::GetImageCount(wxString(convert_string::to_wstring(filename)));
}

float image::horizontal_resolution(intptr image) {
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONX))
    return 96.0f;
  float horizontal_resolution = xtd::ustring::parse<float>(xtd::convert_string::to_string(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONX).c_str().AsWChar()));
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return horizontal_resolution;
  if (xtd::ustring::parse<int32>(xtd::convert_string::to_string(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).c_str().AsWChar())) == wxIMAGE_RESOLUTION_CM)
    horizontal_resolution *= 2.54f;
  return horizontal_resolution;
}

void image::physical_dimension(intptr image, int32& width, int32& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

size_t image::pixel_format(intptr image) {
  /// @todo see how to get pixel format with wxWidgets.
  return 0;
}

std::vector<int32> image::property_id_list(intptr image) {
  /// @todo see how to get property id list with wxWidgets.
  return {};
}

std::vector<image::property_item> image::property_items(intptr image) {
  /// @todo see how to get property items with wxWidgets.
  return {};
}

size_t image::raw_format(intptr image) {
  return to_raw_format(reinterpret_cast<wxImage*>(image)->GetType());
}

void image::size(intptr image, int32& width, int32& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

float image::vertical_resolution(intptr image) {
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONY))
    return 96.0f;
  float vertical_resolution = xtd::ustring::parse<float>(xtd::convert_string::to_string(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONY).c_str().AsWChar()));
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return vertical_resolution;
  if (xtd::ustring::parse<int32>(xtd::convert_string::to_string(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).c_str().AsWChar())) == wxIMAGE_RESOLUTION_CM)
    vertical_resolution *= 2.54f;
  return vertical_resolution;
}

void image::get_pixel(intptr image, int32 x, int32 y, xtd::byte& a, xtd::byte& r, xtd::byte& g, xtd::byte& b) {
  if (reinterpret_cast<wxImage*>(image)->IsTransparent(x, y, 1)) a = r = g = b = 0;
  else {
    a = reinterpret_cast<wxImage*>(image)->HasAlpha() ? reinterpret_cast<wxImage*>(image)->GetAlpha(x, y) : 255;
    r = reinterpret_cast<wxImage*>(image)->GetRed(x, y);
    g = reinterpret_cast<wxImage*>(image)->GetGreen(x, y);
    b = reinterpret_cast<wxImage*>(image)->GetBlue(x, y);
  }
}

void image::rotate_flip(intptr image, int32 rotate_flip_type) {
  auto wx_image = reinterpret_cast<wxImage*>(image);
  switch (rotate_flip_type) {
    case RFT_ROTATE_NONE_FLIP_NONE: break;
    case RFT_ROTATE_90_FLIP_NONE: *wx_image = wx_image->Rotate90(); break;
    case RFT_ROTATE_180_FLIP_NONE: *wx_image = wx_image->Rotate180(); break;
    case RFT_ROTATE_270_FLIP_NONE: *wx_image = wx_image->Rotate180(); *wx_image = wx_image->Rotate90(); break;
    case RFT_ROTATE_NONE_FLIP_X: *wx_image = wx_image->Mirror(); break;
    case RFT_ROTATE_90_FLIP_X: *wx_image = wx_image->Rotate90(); *wx_image = wx_image->Mirror(); break;
    case RFT_ROTATE_180_FLIP_X: *wx_image = wx_image->Rotate180(); *wx_image = wx_image->Mirror(); break;
    case RFT_ROTATE_270_FLIP_X: *wx_image = wx_image->Rotate180(); *wx_image = wx_image->Rotate90(); *wx_image = wx_image->Mirror(); break;
    default: break;
  }
}

void image::set_pixel(intptr image, int32 x, int32 y, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b) {
  if (reinterpret_cast<wxImage*>(image)->HasAlpha()) reinterpret_cast<wxImage*>(image)->SetAlpha(x, y, a);
  reinterpret_cast<wxImage*>(image)->SetRGB(x, y, r, g, b);
}

void image::save(intptr image, const ustring& filename) {
  reinterpret_cast<wxImage*>(image)->SaveFile(wxString(convert_string::to_wstring(filename)));
}

void image::save(intptr image, const ustring& filename, size_t raw_format) {
  reinterpret_cast<wxImage*>(image)->SaveFile(wxString(convert_string::to_wstring(filename)), to_bitmap_type(raw_format));
}

void image::save(intptr image, std::ostream& stream, size_t raw_format) {
  StdOutputStreamAdapter output_stream(stream);
  reinterpret_cast<wxImage*>(image)->SaveFile(output_stream, to_bitmap_type(raw_format));
}

float image::screen_dpi() {
  return static_cast<float>(wxDisplay::GetStdPPIValue());
}
