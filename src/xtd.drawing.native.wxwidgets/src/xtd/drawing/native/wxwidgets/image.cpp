#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/image>
#include <xtd/drawing/native/compositing_modes>
#include <xtd/drawing/native/compositing_qualities>
#include <xtd/drawing/native/frame_dimension>
#include <xtd/drawing/native/image_flags>
#include <xtd/drawing/native/image_formats>
#include <xtd/drawing/native/toolkit>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <xtd/io/path>
#include <wx/bitmap.h>
#include <wx/display.h>
#include <wx/icon.h>
#include <wx/iconbndl.h>
#include <wx/image.h>
#include <wx/palette.h>
#include <wx/stream.h>

using namespace xtd;
using namespace xtd::drawing::native;
using namespace xtd::helpers;

namespace {
  static wxBitmapType wxBITMAP_TYPE_EXIF = static_cast<wxBitmapType>(wxBITMAP_TYPE_MAX + 1);
  class StdInputStreamAdapter : public wxInputStream {
  public:
    explicit StdInputStreamAdapter(std::istream& stream): stream_{stream} {}
    
  protected:
    bool IsSeekable()  const override {return true;}
    
    size_t OnSysRead(void* buffer, size_t size) override {
      stream_.peek();
      if (stream_.fail() || stream_.bad()) m_lasterror = wxStreamError::wxSTREAM_READ_ERROR;
      else if (stream_.eof()) m_lasterror = wxStreamError::wxSTREAM_EOF;
      return stream_.readsome(static_cast<std::istream::char_type*>(buffer), size);
    }
    
    wxFileOffset OnSysSeek(wxFileOffset pos, wxSeekMode mode) override {
      switch (mode) {
        case wxSeekMode::wxFromStart: stream_.seekg(pos, std::ios::beg); break;
        case wxSeekMode::wxFromEnd: stream_.seekg(pos, std::ios::end); break;
        case wxSeekMode::wxFromCurrent: stream_.seekg(pos, std::ios::cur); break;
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
      if (stream_.fail() || stream_.bad()) m_lasterror = wxStreamError::wxSTREAM_WRITE_ERROR;
      stream_.write(static_cast<const std::ostream::char_type*>(buffer), size);
      return size;
    }
    
  private:
    std::ostream& stream_;
  };
  
  /*
  size_t frame_count(std::istream& stream) {
    StdInputStreamAdapter std_stream(stream);
    return wxImage::GetImageCount(std_stream);
  }
  
  size_t frame_count(const xtd::string& filename) {
    return wxImage::GetImageCount(wxString(convert_string::to_wstring(filename)));
  }
   */
  
  wxBitmapType to_bitmap_type(size_t raw_format) {
    switch (raw_format) {
      case IFM_BMP: return wxBitmapType::wxBITMAP_TYPE_BMP;
      case IFM_MEMORY_BMP: return wxBitmapType::wxBITMAP_TYPE_BMP_RESOURCE;
      case IFM_ICO: return wxBitmapType::wxBITMAP_TYPE_ICO;
      case IFM_MEMORY_ICO: return wxBitmapType::wxBITMAP_TYPE_ICO_RESOURCE;
      case IFM_CUR: return wxBitmapType::wxBITMAP_TYPE_CUR;
      case IFM_MEMORY_CUR: return wxBitmapType::wxBITMAP_TYPE_CUR_RESOURCE;
      case IFM_XBM: return wxBitmapType::wxBITMAP_TYPE_XBM;
      case IFM_MEMORY_XBM: return wxBitmapType::wxBITMAP_TYPE_XBM_DATA;
      case IFM_XPM: return wxBitmapType::wxBITMAP_TYPE_XPM;
      case IFM_MEMORY_XPM: return wxBitmapType::wxBITMAP_TYPE_XPM_DATA;
      case IFM_TIFF: return wxBitmapType::wxBITMAP_TYPE_TIFF;
      case IFM_MEMORY_TIFF: return wxBitmapType::wxBITMAP_TYPE_TIFF_RESOURCE;
      case IFM_GIF: return wxBitmapType::wxBITMAP_TYPE_GIF;
      case IFM_MEMORY_GIF: return wxBitmapType::wxBITMAP_TYPE_GIF_RESOURCE;
      case IFM_PNG: return wxBitmapType::wxBITMAP_TYPE_PNG;
      case IFM_MEMORY_PNG: return wxBitmapType::wxBITMAP_TYPE_PNG_RESOURCE;
      case IFM_JPEG: return wxBitmapType::wxBITMAP_TYPE_JPEG;
      case IFM_MEMORY_JPEG: return wxBitmapType::wxBITMAP_TYPE_JPEG_RESOURCE;
      case IFM_PNM: return wxBitmapType::wxBITMAP_TYPE_PNM;
      case IFM_MEMORY_PNM: return wxBitmapType::wxBITMAP_TYPE_PNM_RESOURCE;
      case IFM_PCX: return wxBitmapType::wxBITMAP_TYPE_PCX;
      case IFM_MEMORY_PCX: return wxBitmapType::wxBITMAP_TYPE_PCX_RESOURCE;
      case IFM_PICT: return wxBitmapType::wxBITMAP_TYPE_PICT;
      case IFM_MEMORY_PICT: return wxBitmapType::wxBITMAP_TYPE_PICT_RESOURCE;
      case IFM_ICON: return wxBitmapType::wxBITMAP_TYPE_ICON;
      case IFM_MEMORY_ICON: return wxBitmapType::wxBITMAP_TYPE_ICON_RESOURCE;
      case IFM_ANI: return wxBitmapType::wxBITMAP_TYPE_ANI;
      case IFM_IIF: return wxBitmapType::wxBITMAP_TYPE_IFF;
      case IFM_TGA: return wxBitmapType::wxBITMAP_TYPE_TGA;
      case IFM_MACCUR: return wxBitmapType::wxBITMAP_TYPE_MACCURSOR;
      case IFM_MEMORY_MACCUR: return wxBitmapType::wxBITMAP_TYPE_MACCURSOR_RESOURCE;
      default: return wxBitmapType::wxBITMAP_TYPE_ANY;
    }
  }
  
  size_t to_raw_format(wxBitmapType bitmap_type) {
    switch (bitmap_type) {
      case wxBITMAP_TYPE_BMP: return IFM_BMP;
      case wxBITMAP_TYPE_BMP_RESOURCE: return IFM_MEMORY_BMP;
      case wxBITMAP_TYPE_ICO: return IFM_ICO;
      case wxBITMAP_TYPE_ICO_RESOURCE: return IFM_MEMORY_ICO;
      case wxBITMAP_TYPE_CUR: return IFM_CUR;
      case wxBITMAP_TYPE_CUR_RESOURCE: return IFM_MEMORY_CUR;
      case wxBITMAP_TYPE_XBM: return IFM_XBM;
      case wxBITMAP_TYPE_XBM_DATA: return IFM_MEMORY_XBM;
      case wxBITMAP_TYPE_XPM: return IFM_XPM;
      case wxBITMAP_TYPE_XPM_DATA: return IFM_MEMORY_XPM;
      case wxBITMAP_TYPE_TIFF: return IFM_TIFF;
      case wxBITMAP_TYPE_TIFF_RESOURCE: return IFM_MEMORY_TIFF;
      case wxBITMAP_TYPE_GIF: return IFM_GIF;
      case wxBITMAP_TYPE_GIF_RESOURCE: return IFM_MEMORY_GIF;
      case wxBITMAP_TYPE_PNG: return IFM_PNG;
      case wxBITMAP_TYPE_PNG_RESOURCE: return IFM_MEMORY_PNG;
      case wxBITMAP_TYPE_JPEG: return IFM_JPEG;
      case wxBITMAP_TYPE_JPEG_RESOURCE: return IFM_MEMORY_JPEG;
      case wxBITMAP_TYPE_PNM: return IFM_PNM;
      case wxBITMAP_TYPE_PNM_RESOURCE: return IFM_MEMORY_PNM;
      case wxBITMAP_TYPE_PCX: return IFM_PCX;
      case wxBITMAP_TYPE_PCX_RESOURCE: return IFM_MEMORY_PCX;
      case wxBITMAP_TYPE_PICT: return IFM_PICT;
      case wxBITMAP_TYPE_PICT_RESOURCE: return IFM_MEMORY_PICT;
      case wxBITMAP_TYPE_ICON: return IFM_ICON;
      case wxBITMAP_TYPE_ICON_RESOURCE: return IFM_MEMORY_ICON;
      case wxBITMAP_TYPE_ANI: return IFM_ANI;
      case wxBITMAP_TYPE_IFF: return IFM_IIF;
      case wxBITMAP_TYPE_TGA: return IFM_TGA;
      case wxBITMAP_TYPE_MACCURSOR: return IFM_MACCUR;
      case wxBITMAP_TYPE_MACCURSOR_RESOURCE: return IFM_MEMORY_MACCUR;
      default: return bitmap_type == wxBITMAP_TYPE_EXIF ? IFM_EXIF : IFM_UNKNOWN;
    }
  }
  
  size_t get_frame_resolution(const wxImage& image) {
    switch (image.GetType()) {
      case wxBitmapType::wxBITMAP_TYPE_BMP: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_BMP_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_ICO: return FD_RESOLUTION;
      case wxBitmapType::wxBITMAP_TYPE_ICO_RESOURCE: return FD_RESOLUTION;
      case wxBitmapType::wxBITMAP_TYPE_CUR: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_CUR_RESOURCE: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_XBM: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_XBM_DATA: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_XPM: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_XPM_DATA: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_TIFF: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_TIFF_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_GIF: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_GIF_RESOURCE: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_PNG: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PNG_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_JPEG: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_JPEG_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PNM: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PNM_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PCX: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PCX_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PICT: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_PICT_RESOURCE: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_ICON: return FD_RESOLUTION;
      case wxBitmapType::wxBITMAP_TYPE_ICON_RESOURCE: return FD_RESOLUTION;
      case wxBitmapType::wxBITMAP_TYPE_ANI: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_IFF: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_TGA: return FD_PAGE;
      case wxBitmapType::wxBITMAP_TYPE_MACCURSOR: return FD_TIME;
      case wxBitmapType::wxBITMAP_TYPE_MACCURSOR_RESOURCE: return FD_TIME;
      default: return FD_PAGE;
    }
  }
  
  void init_alpha(wxImage* img) {
    if (!img->HasAlpha()) img->InitAlpha();
    for (auto y = 0; y < img->GetHeight(); y++)
      for (auto x = 0; x < img->GetWidth(); x++)
        img->SetAlpha(x, y, 0);
  }
}

void image::color_palette(intptr image, std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>>& entries, int32& flags) {
  wxPalette palette = reinterpret_cast<wxImage*>(image)->GetPalette();
  entries.clear();
  if (palette.GetColoursCount() == 0) return;
  for (int32 index = 0; index < palette.GetColoursCount(); index++) {
    xtd::byte r = 0, g = 0, b = 0;
    palette.GetRGB(index, &r, &g, &b);
    entries.push_back({255, r, g, b});
  }
  flags = 1;
}

intptr image::create(const string& filename, bool use_icm, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  auto extension = xtd::io::path::get_extension(filename).to_lower();
  auto bitmap_type = wxBitmapType::wxBITMAP_TYPE_ANY;
  if (extension == ".ani") bitmap_type = wxBitmapType::wxBITMAP_TYPE_ANI;
  else if (extension == ".bmp") bitmap_type = wxBitmapType::wxBITMAP_TYPE_BMP;
  else if (extension == ".cur") bitmap_type = wxBitmapType::wxBITMAP_TYPE_CUR;
  else if (extension == ".exif") bitmap_type = wxBITMAP_TYPE_EXIF;
  else if (extension == ".icns") bitmap_type = wxBitmapType::wxBITMAP_TYPE_ICON;
  else if (extension == ".ico") bitmap_type = wxBitmapType::wxBITMAP_TYPE_ICO;
  else if (extension == ".iff") bitmap_type = wxBitmapType::wxBITMAP_TYPE_IFF;
  else if (extension == ".jpeg") bitmap_type = wxBitmapType::wxBITMAP_TYPE_JPEG;
  else if (extension == ".jpg") bitmap_type = wxBitmapType::wxBITMAP_TYPE_JPEG;
  else if (extension == ".gif") bitmap_type = wxBitmapType::wxBITMAP_TYPE_GIF;
  else if (extension == ".pcx") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PCX;
  else if (extension == ".pct") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PICT;
  else if (extension == ".pic") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PICT;
  else if (extension == ".pict") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PICT;
  else if (extension == ".png") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PNG;
  else if (extension == ".pnm") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PNM;
  else if (extension == ".ppm") bitmap_type = wxBitmapType::wxBITMAP_TYPE_PNM;
  else if (extension == ".tga") bitmap_type = wxBitmapType::wxBITMAP_TYPE_TGA;
  else if (extension == ".tif") bitmap_type = wxBitmapType::wxBITMAP_TYPE_TIFF;
  else if (extension == ".tiff") bitmap_type = wxBitmapType::wxBITMAP_TYPE_TIFF;
  else if (extension == ".xbm") bitmap_type = wxBitmapType::wxBITMAP_TYPE_XBM;
  else if (extension == ".xpm") bitmap_type = wxBitmapType::wxBITMAP_TYPE_XPM;
  auto img = new wxImage(wxString(convert_string::to_wstring(filename)), bitmap_type == wxBitmapType::wxBITMAP_TYPE_XPM ? wxBitmapType::wxBITMAP_TYPE_XPM : wxBitmapType::wxBITMAP_TYPE_ANY);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  if (bitmap_type != wxBitmapType::wxBITMAP_TYPE_ANY && img->GetType() != bitmap_type) img->SetType(bitmap_type);
  // wxWidgets does not have a parameter or a method to set color correction when creating from a filename.
  frame_resolutions[get_frame_resolution(*img)] = wxImage::GetImageCount(wxString {filename.chars()});
  return reinterpret_cast<intptr>(img);
}

intptr image::create(std::istream& stream, bool use_icm, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  StdInputStreamAdapter std_stream(stream);
  auto img = new wxImage(std_stream);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  // wxWidgets does not have a parameter or a method to set color correction when creating from a stream.
  frame_resolutions[get_frame_resolution(*img)] = wxImage::GetImageCount(std_stream);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(const char* const* bits, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  auto img = new wxImage(bits);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  frame_resolutions[get_frame_resolution(*img)] = 1;
  return reinterpret_cast<intptr>(img);
}

intptr image::create(const unsigned char* bits, int32 width, int32 height, std::map<size_t, size_t>& frame_resolutions) {
  toolkit::initialize(); // Must be first
  auto img = new wxImage(wxBitmap(reinterpret_cast<const char*>(bits), width, height).ConvertToImage());
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  frame_resolutions[get_frame_resolution(*img)] = 1;
  return reinterpret_cast<intptr>(img);
}

intptr image::create(int32 width, int32 height) {
  toolkit::initialize(); // Must be first
  wxImage* img = new wxImage(width, height);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  init_alpha(img);
  img->SetType(wxBITMAP_TYPE_BMP_RESOURCE);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(int32 width, int32 height, float horizontal_resolution, float vertical_resolution) {
  toolkit::initialize(); // Must be first
  wxImage* img = new wxImage(width, height);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  set_resolution(reinterpret_cast<intptr>(img), horizontal_resolution, vertical_resolution);
  init_alpha(img);
  img->SetType(wxBITMAP_TYPE_BMP_RESOURCE);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(int32 width, int32 height, int32 format) {
  toolkit::initialize(); // Must be first
  wxImage* img = new wxImage(width, height);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  /// @todo see how to set pixel format with wxWidgets.
  init_alpha(img);
  img->SetType(wxBITMAP_TYPE_BMP_RESOURCE);
  return reinterpret_cast<intptr>(img);
}

intptr image::create(int32 width, int32 height, int32 stride, int32 format, intptr scan0) {
  toolkit::initialize(); // Must be first
  wxImage* img = new wxImage(width, height);
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  /// @todo see how to set pixel format and data with wxWidgets.
  init_alpha(img);
  img->SetType(wxBITMAP_TYPE_BMP_RESOURCE);
  return reinterpret_cast<intptr>(img);
}

void image::destroy(intptr image) {
  reinterpret_cast<wxImage*>(image)->Destroy();
  delete reinterpret_cast<wxImage*>(image);
}

size_t image::flags(intptr image) {
  /// @todo see how to get flags dimension with wxWidgets.
  auto result = IFL_NONE;
  if (reinterpret_cast<wxImage*>(image)->HasAlpha()) result += IFL_HAS_ALPHA;
  return result;
}

intptr image::from_hicon(intptr icon) {
  toolkit::initialize(); // Must be first
  wxBitmap bitmap;
  bitmap.CopyFromIcon(*reinterpret_cast<wxIcon*>(icon));
  wxImage* img = new wxImage(bitmap.ConvertToImage());
  if (!img->IsOk()) {
    delete img;
    return invalid_handle;
  }
  return reinterpret_cast<intptr>(img);
}

xtd::byte* image::get_alpha(intptr image) {
  if (image == 0) return 0;
  if (!reinterpret_cast<wxImage*>(image)->HasAlpha()) reinterpret_cast<wxImage*>(image)->InitAlpha();
  return reinterpret_cast<xtd::byte*>(reinterpret_cast<wxImage*>(image)->GetAlpha());
}

xtd::byte* image::get_data(intptr image) {
  if (image == 0) return 0;
  return reinterpret_cast<xtd::byte*>(reinterpret_cast<wxImage*>(image)->GetData());
}

intptr image::get_hbitmap(intptr image) {
  wxBitmap* result = new wxBitmap(*reinterpret_cast<wxImage*>(image));
  return reinterpret_cast<intptr>(result);
}

intptr image::get_hbitmap(intptr image, xtd::byte a, xtd::byte r, xtd::byte g, xtd::byte b) {
  wxBitmap* result = new wxBitmap(*reinterpret_cast<wxImage*>(image));
  /// @todo see how to set background color to wxBitmap.
  return reinterpret_cast<intptr>(result);
}

intptr image::get_hicon(intptr image) {
  toolkit::initialize(); // Must be first
  if (image == 0) return 0;
  wxIconBundle* result = new wxIconBundle;
  wxIcon icon;
  icon.CopyFromBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image)));
  result->AddIcon(icon);
  return reinterpret_cast<intptr>(result);
}

float image::horizontal_resolution(intptr image) {
  auto resolution = reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONX) ? static_cast<float>(reinterpret_cast<wxImage*>(image)->GetOptionInt(wxIMAGE_OPTION_RESOLUTIONX)) : 96.0f;
  return reinterpret_cast<wxImage*>(image)->GetOptionInt(wxIMAGE_OPTION_RESOLUTIONUNIT) == wxIMAGE_RESOLUTION_CM ? resolution * 2.54 : resolution;
}

void image::lock_bits(intptr image, int32 left, int32 top, int32 width, int32 height, int32 flags, int32 format, int32& image_data_height, int32& image_data_pixel_format, int32& image_data_reserved, intptr& image_data_scan0, int32& image_data_stride, int32& image_data_width) {
  /// @todo see how to implement lock bits with wxWidgets.
}

void image::make_transparent(intptr image, xtd::byte transparent_color_a, xtd::byte transparent_color_r, xtd::byte transparent_color_g, xtd::byte transparent_color_b) {
  if (!image) throw_helper::throws(exception_case::argument);
  reinterpret_cast<wxImage*>(image)->InitAlpha();
  for (int32 y = 0; y < reinterpret_cast<wxImage*>(image)->GetHeight(); y++)
    for (int32 x = 0; x < reinterpret_cast<wxImage*>(image)->GetWidth(); x++)
      if (reinterpret_cast<wxImage*>(image)->GetRed(x, y) == transparent_color_r && reinterpret_cast<wxImage*>(image)->GetGreen(x, y) == transparent_color_g && reinterpret_cast<wxImage*>(image)->GetBlue(x, y) == transparent_color_b && reinterpret_cast<wxImage*>(image)->GetAlpha(x, y) == transparent_color_a)
        reinterpret_cast<wxImage*>(image)->SetAlpha(x, y, 0);
}

void image::physical_dimension(intptr image, int32& width, int32& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

size_t image::pixel_format(intptr image) {
  /// @todo see how to get pixel format with wxWidgets.
  size_t result = 0; // pixel_format::dont_care
  result += 0x00200000; // pixel_format::canonical
  result += 0x00020000; // pixel_format::gdi
  if (reinterpret_cast<wxImage*>(image)->HasAlpha()) result += 0x00040000; // pixel_format::alpha
  result += 0x0000200A; // 32 bits per pixel
  return result;
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

void image::rescale(intptr image, int32 width, int32 height) {
  toolkit::initialize(); // Must be first
  if (image == 0) return;
  auto backup_type = reinterpret_cast<wxImage*>(image)->GetType();
  reinterpret_cast<wxImage*>(image)->Rescale(width, height, wxIMAGE_QUALITY_HIGH);
  reinterpret_cast<wxImage*>(image)->SetType(backup_type);
}

void image::save(intptr image, const string& filename) {
  reinterpret_cast<wxImage*>(image)->SaveFile(wxString(convert_string::to_wstring(filename)));
}

void image::save(intptr image, const string& filename, size_t raw_format) {
  reinterpret_cast<wxImage*>(image)->SaveFile(wxString(convert_string::to_wstring(filename)), to_bitmap_type(raw_format));
}

void image::save(intptr image, std::ostream& stream, size_t raw_format) {
  StdOutputStreamAdapter output_stream(stream);
  reinterpret_cast<wxImage*>(image)->SaveFile(output_stream, to_bitmap_type(raw_format));
}

float image::screen_dpi() {
  return static_cast<float>(wxDisplay::GetStdPPIValue());
}

void image::set_resolution(intptr image, int32 x_dpi, int32 y_dpi) {
  reinterpret_cast<wxImage*>(image)->SetOption(wxIMAGE_OPTION_RESOLUTIONUNIT, string::format("{}", wxIMAGE_RESOLUTION_INCHES).c_str());
  reinterpret_cast<wxImage*>(image)->SetOption(wxIMAGE_OPTION_RESOLUTIONX, string::format("{}", x_dpi).c_str());
  reinterpret_cast<wxImage*>(image)->SetOption(wxIMAGE_OPTION_RESOLUTIONY, string::format("{}", y_dpi).c_str());
}

void image::size(intptr image, int32& width, int32& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

void image::unlock_bits(intptr image, int32& image_data_height, int32& image_data_pixel_format, int32& image_data_reserved, intptr& image_data_scan0, int32& image_data_stride, int32& image_data_width) {
  /// @todo see how to implement unlock bits with wxWidgets.
}

float image::vertical_resolution(intptr image) {
  auto resolution = reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONY) ? static_cast<float>(reinterpret_cast<wxImage*>(image)->GetOptionInt(wxIMAGE_OPTION_RESOLUTIONY)) : 96.0f;
  return reinterpret_cast<wxImage*>(image)->GetOptionInt(wxIMAGE_OPTION_RESOLUTIONUNIT) == wxIMAGE_RESOLUTION_CM ? resolution * 2.54 : resolution;
}
