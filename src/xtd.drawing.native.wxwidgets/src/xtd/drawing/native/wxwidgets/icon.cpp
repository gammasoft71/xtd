#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/icon.h>
#include <xtd/drawing/native/image_format.h>
#include <xtd/drawing/native/toolkit.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <xtd/strings.h>
#include <atomic>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/iconbndl.h>
#include <wx/image.h>
#include <wx/stream.h>

using namespace xtd;
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
    auto it = raw_formats.find(raw_format);
    return it == raw_formats.end() ? wxBitmapType::wxBITMAP_TYPE_ANY : it->second;
  }
}

intptr_t icon::create(const ustring& filename) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxIconBundle(wxString(convert_string::to_wstring(filename))));
}

intptr_t icon::create(std::istream& stream) {
  toolkit::initialize(); // Must be first
  StdInputStreamAdapter std_stream(stream);
  return reinterpret_cast<intptr_t>(new wxIconBundle(std_stream));
}

intptr_t icon::create(const char* const* bits) {
  toolkit::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxIconBundle(wxIcon(bits)));
}

intptr_t icon::create(intptr_t image) {
  toolkit::initialize(); // Must be first
  if (image == 0) return 0;
  wxIconBundle* result = new wxIconBundle;
  wxIcon icon;
  icon.CopyFromBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image)));
  result->AddIcon(icon);
  return reinterpret_cast<intptr_t>(result);
}

intptr_t icon::create(intptr_t icon, int32_t width, int32_t height) {
  toolkit::initialize(); // Must be first
  if (icon == 0) return 0;
  wxIconBundle* result = new wxIconBundle(reinterpret_cast<wxIconBundle*>(icon)->GetIcon({width, height}));
  return reinterpret_cast<intptr_t>(result);
}

void icon::destroy(intptr_t icon) {
  delete reinterpret_cast<wxImage*>(icon);
}

void icon::save(intptr_t icon, const ustring& filename) {
  reinterpret_cast<wxImage*>(icon)->SaveFile(wxString(convert_string::to_wstring(filename)));
}

void icon::save(intptr_t icon, std::ostream& stream, size_t raw_format) {
  StdOutputStreamAdapter output_stream(stream);
  reinterpret_cast<wxImage*>(icon)->SaveFile(output_stream, to_bitmap_type(raw_format));
}

intptr_t icon::to_image(intptr_t icon) {
  if (icon == 0) return 0;
  wxIconBundle* icon_bundle = reinterpret_cast<wxIconBundle*>(icon);
  wxIcon wx_icon = icon_bundle->GetIcon();
  if (!wx_icon.IsOk()) return 0;
  wxBitmap wx_bitmap;
  wx_bitmap.CopyFromIcon(wx_icon);
  return reinterpret_cast<intptr_t>(new wxImage(wx_bitmap.ConvertToImage()));
}
