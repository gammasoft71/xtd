#include <xtd/drawing/native/image.h>
#include <xtd/drawing/native/frame_dimension.h>
#include <xtd/drawing/native/image_flags.h>
#include <xtd/drawing/native/image_format.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>
#include <atomic>
#include <wx/image.h>
#include <wx/palette.h>
#include <wx/stream.h>

using namespace xtd;
using namespace xtd::drawing::native;


std::atomic<uint32_t> __xtd_count_image_handler__ = 0;

void __xtd_init_image_handlers__() {
  if (__xtd_count_image_handler__ == 0)
    wxInitAllImageHandlers();
  ++__xtd_count_image_handler__;
}

void __xtd_clean_image_handlers__() {
  --__xtd_count_image_handler__;
  if (__xtd_count_image_handler__ == 0)
    wxImage::CleanUpHandlers();
}

namespace {
  class StdInputStreamAdapter : public wxInputStream {
  public:
    StdInputStreamAdapter(std::istream& stream): stream_{stream} {}

  protected:
    bool IsSeekable()  const override {return true;}
    
    size_t OnSysRead(void* buffer, size_t size) override {
      stream_.peek();
      if (stream_.fail() || stream_.bad()) m_lasterror = wxSTREAM_READ_ERROR;
      else if (stream_.eof()) m_lasterror = wxSTREAM_EOF;
      return stream_.readsome(static_cast<std::istream::char_type *>(buffer), size);
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
    std::istream &stream_;
  };

  class StdOutputStreamAdapter : public wxOutputStream {
  public:
    StdOutputStreamAdapter(std::ostream& stream): stream_{stream} {}
    
  protected:
    bool IsSeekable()  const override {return false;}
    
    size_t OnSysWrite(const void* buffer, size_t size) override {
      if (stream_.fail() || stream_.bad()) m_lasterror = wxSTREAM_WRITE_ERROR;
      stream_.write(static_cast<const std::ostream::char_type *>(buffer), size);
      return size;
    }
    
  private:
    std::ostream &stream_;
  };

  wxBitmapType to_bitmap_type(size_t raw_format) {
    static std::map<size_t, wxBitmapType> raw_formats {{IFM_BMP, wxBITMAP_TYPE_BMP}, {IFM_MEMORY_BMP, wxBITMAP_TYPE_BMP_RESOURCE}, {IFM_ICO, wxBITMAP_TYPE_ICO}, {IFM_MEMORY_ICO, wxBITMAP_TYPE_ICO_RESOURCE}, {IFM_CUR, wxBITMAP_TYPE_CUR}, {IFM_MEMORY_CUR, wxBITMAP_TYPE_CUR_RESOURCE}, {IFM_XBM, wxBITMAP_TYPE_XBM}, {IFM_MEMORY_XBM, wxBITMAP_TYPE_XBM_DATA}, {IFM_XPM, wxBITMAP_TYPE_XPM}, {IFM_MEMORY_XPM, wxBITMAP_TYPE_XPM_DATA}, {IFM_TIFF, wxBITMAP_TYPE_TIFF}, {IFM_MEMORY_TIFF, wxBITMAP_TYPE_TIFF_RESOURCE}, {IFM_GIF, wxBITMAP_TYPE_GIF}, {IFM_MEMORY_GIF, wxBITMAP_TYPE_GIF_RESOURCE}, {IFM_PNG, wxBITMAP_TYPE_PNG}, {IFM_MEMORY_PNG, wxBITMAP_TYPE_PNG_RESOURCE}, {IFM_JPEG, wxBITMAP_TYPE_JPEG}, {IFM_MEMORY_JPEG, wxBITMAP_TYPE_JPEG_RESOURCE}, {IFM_PNM, wxBITMAP_TYPE_PNM}, {IFM_MEMORY_PNM, wxBITMAP_TYPE_PNM_RESOURCE}, {IFM_PCX, wxBITMAP_TYPE_PCX}, {IFM_MEMORY_PCX, wxBITMAP_TYPE_PCX_RESOURCE}, {IFM_PICT, wxBITMAP_TYPE_PICT}, {IFM_MEMORY_PICT, wxBITMAP_TYPE_PICT_RESOURCE}, {IFM_ICON, wxBITMAP_TYPE_ICON}, {IFM_MEMORY_ICON, wxBITMAP_TYPE_ICON_RESOURCE}, {IFM_ANI, wxBITMAP_TYPE_ANI}, {IFM_IIF, wxBITMAP_TYPE_IFF}, {IFM_TGA, wxBITMAP_TYPE_TGA}, {IFM_MACCUR, wxBITMAP_TYPE_MACCURSOR}, {IFM_MEMORY_MACCUR, wxBITMAP_TYPE_MACCURSOR_RESOURCE}};
    return raw_formats.find(raw_format) == raw_formats.end() ? wxBitmapType::wxBITMAP_TYPE_ANY : raw_formats[raw_format];
  }

  size_t to_raw_format(wxBitmapType bitmap_type) {
    static std::map<wxBitmapType, size_t> bitmap_types {{wxBITMAP_TYPE_BMP, IFM_BMP}, {wxBITMAP_TYPE_BMP_RESOURCE, IFM_MEMORY_BMP}, {wxBITMAP_TYPE_ICO, IFM_ICO}, {wxBITMAP_TYPE_ICO_RESOURCE, IFM_MEMORY_ICO}, {wxBITMAP_TYPE_CUR, IFM_CUR}, {wxBITMAP_TYPE_CUR_RESOURCE, IFM_MEMORY_CUR}, {wxBITMAP_TYPE_XBM, IFM_XBM}, {wxBITMAP_TYPE_XBM_DATA, IFM_MEMORY_XBM}, {wxBITMAP_TYPE_XPM, IFM_XPM}, {wxBITMAP_TYPE_XPM_DATA, IFM_MEMORY_XPM}, {wxBITMAP_TYPE_TIFF, IFM_TIFF}, {wxBITMAP_TYPE_TIFF_RESOURCE, IFM_MEMORY_TIFF}, {wxBITMAP_TYPE_GIF, IFM_GIF}, {wxBITMAP_TYPE_GIF_RESOURCE, IFM_MEMORY_GIF}, {wxBITMAP_TYPE_PNG, IFM_PNG}, {wxBITMAP_TYPE_PNG_RESOURCE, IFM_MEMORY_PNG}, {wxBITMAP_TYPE_JPEG, IFM_JPEG}, {wxBITMAP_TYPE_JPEG_RESOURCE, IFM_MEMORY_JPEG}, {wxBITMAP_TYPE_PNM, IFM_PNM}, {wxBITMAP_TYPE_PNM_RESOURCE, IFM_MEMORY_PNM}, {wxBITMAP_TYPE_PCX, IFM_PCX}, {wxBITMAP_TYPE_PCX_RESOURCE, IFM_MEMORY_PCX}, {wxBITMAP_TYPE_PICT, IFM_PICT}, {wxBITMAP_TYPE_PICT_RESOURCE, IFM_MEMORY_PICT}, {wxBITMAP_TYPE_ICON, IFM_ICON}, {wxBITMAP_TYPE_ICON_RESOURCE, IFM_MEMORY_ICON}, {wxBITMAP_TYPE_ANI, IFM_ANI}, {wxBITMAP_TYPE_IFF, IFM_IIF}, {wxBITMAP_TYPE_TGA, IFM_TGA}, {wxBITMAP_TYPE_MACCURSOR, IFM_MACCUR}, {wxBITMAP_TYPE_MACCURSOR_RESOURCE, IFM_MEMORY_MACCUR}};
    return bitmap_types.find(bitmap_type) == bitmap_types.end() ? IFM_UNKNOWN : bitmap_types[bitmap_type];
  }
}

void image::color_palette(intptr_t image, std::vector<argb>& entries, int32_t& flags) {
  wxPalette palette = reinterpret_cast<wxImage*>(image)->GetPalette();
  entries.clear();
  for (int index = 0; index < palette.GetColoursCount(); index++) {
    argb color;
    color.a = 255;
    palette.GetRGB(index, &color.r, &color.g, &color.b);
    entries.push_back(color);
  }
  flags = 0;
}

intptr_t image::create(const std::string& filename) {
  __xtd_init_image_handlers__();
  return reinterpret_cast<intptr_t>(new wxImage({filename.c_str(), wxMBConvUTF8()}));
}

intptr_t image::create(std::istream& stream) {
  __xtd_init_image_handlers__();
  StdInputStreamAdapter std_stream(stream);
  return reinterpret_cast<intptr_t>(new wxImage(std_stream));
}

intptr_t image::create(const char* const* bits) {
  __xtd_init_image_handlers__();
  return reinterpret_cast<intptr_t>(new wxImage(bits));
}

intptr_t image::create(int32_t width, int32_t height) {
  __xtd_init_image_handlers__();
  wxImage* result = new wxImage(width, height);
  result->InitAlpha();
  for (int y = 0; y < height; y++)
    for (int x = 0; x < width; x++)
      result->SetAlpha(x, y, 0);
  return reinterpret_cast<intptr_t>(result);
}

intptr_t image::create(intptr_t image, int32_t width, int32_t height) {
  if (image == 0) return 0;
  __xtd_init_image_handlers__();
  wxImage* result = new wxImage(*reinterpret_cast<wxImage*>(image));
  result->Rescale(width, height);
  return reinterpret_cast<intptr_t>(result);
}

intptr_t image::create(intptr_t image, int32_t left, int32_t top, int32_t width, int32_t height) {
  if (image == 0) return 0;
  __xtd_init_image_handlers__();
  wxImage* result = new wxImage(reinterpret_cast<wxImage*>(image)->GetSubImage({left, top, width, height}));
  return reinterpret_cast<intptr_t>(result);
}

void image::destroy(intptr_t image) {
  reinterpret_cast<wxImage*>(image)->Destroy();
  delete reinterpret_cast<wxImage*>(image);
  __xtd_clean_image_handlers__();
}

size_t image::flags(intptr_t image) {
  /// @todo see how to get flags dimension with wxWidgets.
  return IFL_NONE;
}

size_t image::frame_resolutions(intptr_t image) {
  /// @todo see how to get frame dimension with wxWidgets.
  return FD_PAGE;
}

float image::horizontal_resolution(intptr_t image) {
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONX))
    return 96.0f;
  float horizontal_resolution = xtd::strings::parse<float>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONX).utf8_str().data());
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return horizontal_resolution;
  if (xtd::strings::parse<int>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).utf8_str().data()) == wxIMAGE_RESOLUTION_CM)
    horizontal_resolution *= 2.54f;
  return horizontal_resolution;
}

void image::physical_dimension(intptr_t image, int32_t& width, int32_t& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

size_t image::pixel_format(intptr_t image) {
  /// @todo see how to get pixel format with wxWidgets.
  return 0;
}

std::vector<int32_t> image::property_id_list(intptr_t image) {
   /// @todo see how to get property id list with wxWidgets.
   return {};
}

std::vector<image::property_item> image::property_items(intptr_t image) {
  /// @todo see how to get property items with wxWidgets.
  return {};
}

size_t image::raw_format(intptr_t image) {
  return to_raw_format(reinterpret_cast<wxImage*>(image)->GetType());
}

void image::size(intptr_t image, int32_t& width, int32_t& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

float image::vertical_resolution(intptr_t image) {
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONY))
    return 96.0f;
  float vertical_resolution = xtd::strings::parse<float>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONY).utf8_str().data());
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return vertical_resolution;
  if (xtd::strings::parse<int>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).utf8_str().data()) == wxIMAGE_RESOLUTION_CM)
    vertical_resolution *= 2.54f;
  return vertical_resolution;
}

void image::get_pixel(intptr_t image, int32_t x, int32_t y, argb& color) {
  if (reinterpret_cast<wxImage*>(image)->IsTransparent(x, y, 1))
    color.a = color.r = color.g = color.b = 0;
  else {
    color.a = reinterpret_cast<wxImage*>(image)->HasAlpha() ? reinterpret_cast<wxImage*>(image)->GetAlpha(x, y) : 255;
    color.r = reinterpret_cast<wxImage*>(image)->GetRed(x, y);
    color.g = reinterpret_cast<wxImage*>(image)->GetGreen(x, y);
    color.b = reinterpret_cast<wxImage*>(image)->GetBlue(x, y);
  }
}

void image::set_pixel(intptr_t image, int32_t x, int32_t y, const argb& color) {
  if (reinterpret_cast<wxImage*>(image)->HasAlpha()) reinterpret_cast<wxImage*>(image)->SetAlpha(x, y, color.a);
  reinterpret_cast<wxImage*>(image)->SetRGB(x, y, color.r, color.g, color.b);
}

void image::save(intptr_t image, const std::string& filename) {
  reinterpret_cast<wxImage*>(image)->SaveFile({filename.c_str(), wxMBConvUTF8()});
}

void image::save(intptr_t image, const std::string& filename, size_t raw_format) {
  reinterpret_cast<wxImage*>(image)->SaveFile({filename.c_str(), wxMBConvUTF8()}, to_bitmap_type(raw_format));
}

void image::save(intptr_t image, std::ostream& stream, size_t raw_format) {
  StdOutputStreamAdapter output_stream(stream);
  reinterpret_cast<wxImage*>(image)->SaveFile(output_stream, to_bitmap_type(raw_format));
}
