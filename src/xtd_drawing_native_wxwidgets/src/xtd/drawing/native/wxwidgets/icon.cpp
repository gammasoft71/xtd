#include <xtd/drawing/native/icon.h>
#include <xtd/xtd.io>
#include <xtd/xtd.strings>
#include <atomic>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/iconbndl.h>
#include <wx/image.h>
#include <wx/stream.h>

using namespace xtd;
using namespace xtd::drawing::native;

void __xtd_init_image_handlers__();
void __xtd_clean_image_handlers__();

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
}

intptr_t icon::create(const std::string& filename) {
  __xtd_init_image_handlers__();
  return reinterpret_cast<intptr_t>(new wxIconBundle({filename.c_str(), wxMBConvUTF8()}));
}

intptr_t icon::create(std::istream& stream) {
  __xtd_init_image_handlers__();
  StdInputStreamAdapter std_stream(stream);
  return reinterpret_cast<intptr_t>(new wxIconBundle(std_stream));
}

intptr_t icon::create(const char* const* bits) {
  __xtd_init_image_handlers__();
  return reinterpret_cast<intptr_t>(new wxIconBundle(wxIcon(bits)));
}

intptr_t icon::create(intptr_t image) {
  if (image == 0) return 0;
  __xtd_init_image_handlers__();
  wxIconBundle* result = new wxIconBundle;
  wxIcon icon;
  icon.CopyFromBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image)));
  result->AddIcon(icon);
  return reinterpret_cast<intptr_t>(result);
}

intptr_t icon::create(intptr_t icon, int32_t width, int32_t height) {
  if (icon == 0) return 0;
  __xtd_init_image_handlers__();
  wxIconBundle* result = new wxIconBundle(reinterpret_cast<wxIconBundle*>(icon)->GetIcon({width, height}));
  return reinterpret_cast<intptr_t>(result);
}

void icon::destroy(intptr_t icon) {
  delete reinterpret_cast<wxImage*>(icon);
  __xtd_clean_image_handlers__();
}

void icon::save(intptr_t icon, const std::string& filename) {
  //reinterpret_cast<wxImage*>(image)->SaveFile({filename.c_str(), wxMBConvUTF8()});
}

void icon::save(intptr_t icon, std::ostream& stream) {
  StdOutputStreamAdapter output_stream(stream);
  //reinterpret_cast<wxImage*>(image)->SaveFile(output_stream, to_bitmap_type(raw_format));
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
