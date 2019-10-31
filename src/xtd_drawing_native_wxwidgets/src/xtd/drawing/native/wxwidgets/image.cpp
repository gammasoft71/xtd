#include <xtd/drawing/native/image.hpp>
#include <xtd/drawing/native/frame_dimension.hpp>
#include <xtd/drawing/native/image_flags.hpp>
#include <xtd/drawing/native/image_format.hpp>
#include <xtd/xtd.strings>
#include <wx/image.h>
#include <wx/palette.h>
#include <wx/stream.h>

using namespace xtd::drawing::native;

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
      else return stream_.readsome(static_cast<std::istream::char_type *>(buffer), size);
      return 0;
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

  void init_image_handlers() {
    static bool first_run = true;
    if (!first_run) return;
    wxInitAllImageHandlers();
    first_run = false;
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

intptr_t image::create(std::istream& stream) {
  init_image_handlers();
  StdInputStreamAdapter std_stream(stream);
  return reinterpret_cast<intptr_t>(new wxImage(std_stream));
}

intptr_t image::create(const char* const* bits) {
  init_image_handlers();
  return reinterpret_cast<intptr_t>(new wxImage(bits));
}

intptr_t image::create(int32_t width, int32_t height) {
  init_image_handlers();
  return reinterpret_cast<intptr_t>(new wxImage(width, height));
}

void image::destroy(intptr_t image) {
  delete reinterpret_cast<wxImage*>(image);
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
  float horizontal_resolution = xtd::strings::parse<float>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONX).ToStdString());
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return horizontal_resolution;
  if (xtd::strings::parse<int>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).ToStdString()) == wxIMAGE_RESOLUTION_CM)
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
  wxBitmapType type = reinterpret_cast<wxImage*>(image)->GetType();
  switch (type) {
    case wxBITMAP_TYPE_BMP: return IFM_BMP;
    case wxBITMAP_TYPE_BMP_RESOURCE: return IFM_MEMORY_BMP;
    case wxBITMAP_TYPE_ICO: return IFM_ICO;
    case wxBITMAP_TYPE_ICO_RESOURCE:  return IFM_MEMORY_ICO;
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
    default: return IFM_UNKNOWN;
  }
  return IFM_UNKNOWN;
}

void image::size(intptr_t image, int32_t& width, int32_t& height) {
  width = reinterpret_cast<wxImage*>(image)->GetWidth();
  height = reinterpret_cast<wxImage*>(image)->GetHeight();
}

float image::vertical_resolution(intptr_t image) {
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONY))
    return 96.0f;
  float vertical_resolution = xtd::strings::parse<float>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONY).ToStdString());
  if (!reinterpret_cast<wxImage*>(image)->HasOption(wxIMAGE_OPTION_RESOLUTIONUNIT))
    return vertical_resolution;
  if (xtd::strings::parse<int>(reinterpret_cast<wxImage*>(image)->GetOption(wxIMAGE_OPTION_RESOLUTIONUNIT).ToStdString()) == wxIMAGE_RESOLUTION_CM)
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
