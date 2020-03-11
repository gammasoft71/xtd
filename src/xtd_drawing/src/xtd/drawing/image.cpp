#include "../../../include/xtd/drawing/image.h"
#include <fstream>
#include <xtd/drawing/native/image.h>
#include <xtd/drawing/native/image_format.h>
#include <xtd/drawing/native/frame_dimension.h>

using namespace xtd;
using namespace xtd::drawing;

image image::empty;

namespace {
  xtd::drawing::imaging::image_format to_image_format(size_t raw_fomat) {
    static std::map<size_t, xtd::drawing::imaging::image_format> raw_formats {{IFM_BMP, imaging::image_format::bmp()}, {IFM_EMF, imaging::image_format::emf()}, {IFM_EXIF, imaging::image_format::exif()}, {IFM_GIF, imaging::image_format::gif()}, {IFM_ICO, imaging::image_format::ico()}, {IFM_JPEG, imaging::image_format::jpeg()}, {IFM_MEMORY_BMP, imaging::image_format::memory_bmp()}, {IFM_PNG, imaging::image_format::png()}, {IFM_TIFF, imaging::image_format::tiff()}, {IFM_WMF, imaging::image_format::wmf()}, {IFM_MEMORY_GIF, imaging::image_format::memory_gif()}, {IFM_MEMORY_ICO, imaging::image_format::memory_ico()}, {IFM_MEMORY_JPEG, imaging::image_format::memory_jpeg()}, {IFM_MEMORY_PNG, imaging::image_format::memory_png()}, {IFM_MEMORY_TIFF, imaging::image_format::memory_tiff()}, {IFM_CUR, imaging::image_format::cur()}, {IFM_MEMORY_CUR, imaging::image_format::memory_cur()}, {IFM_XBM, imaging::image_format::xbm()}, {IFM_MEMORY_XBM, imaging::image_format::memory_xbm()}, {IFM_XPM, imaging::image_format::xpm()}, {IFM_MEMORY_XPM, imaging::image_format::memory_xpm()}, {IFM_PNM, imaging::image_format::pnm()}, {IFM_MEMORY_PNM, imaging::image_format::memory_pnm()}, {IFM_PCX, imaging::image_format::pcx()}, {IFM_MEMORY_PCX, imaging::image_format::memory_pcx()}, {IFM_PICT, imaging::image_format::pict()}, {IFM_MEMORY_PICT, imaging::image_format::memory_pict()}, {IFM_ICON, imaging::image_format::icon()}, {IFM_MEMORY_ICON, imaging::image_format::memory_icon()}, {IFM_MACCUR, imaging::image_format::cursor()}, {IFM_MEMORY_MACCUR, imaging::image_format::memory_cursor()}, {IFM_ANI, imaging::image_format::ani()}, {IFM_IIF, imaging::image_format::iif()}, {IFM_TGA, imaging::image_format::tga()}};
    return raw_formats.find(raw_fomat) == raw_formats.end() ? xtd::drawing::imaging::image_format() : raw_formats[raw_fomat];
  }
  
  size_t to_raw_format(xtd::drawing::imaging::image_format image_format) {
    static std::map<xtd::drawing::imaging::image_format, size_t> image_formats {{imaging::image_format::bmp(), IFM_BMP}, {imaging::image_format::emf(), IFM_EMF}, {imaging::image_format::exif(), IFM_EXIF}, {imaging::image_format::gif(), IFM_GIF}, {imaging::image_format::ico(), IFM_ICO}, {imaging::image_format::jpeg(), IFM_JPEG}, {imaging::image_format::memory_bmp(), IFM_MEMORY_BMP}, {imaging::image_format::png(), IFM_PNG}, {imaging::image_format::tiff(), IFM_TIFF}, {imaging::image_format::wmf(), IFM_WMF}, {imaging::image_format::memory_gif(), IFM_MEMORY_GIF}, {imaging::image_format::memory_ico(), IFM_MEMORY_ICO}, {imaging::image_format::memory_jpeg(), IFM_MEMORY_JPEG}, {imaging::image_format::memory_png(), IFM_MEMORY_PNG}, {imaging::image_format::memory_tiff(), IFM_MEMORY_TIFF}, {imaging::image_format::cur(), IFM_CUR}, {imaging::image_format::memory_cur(), IFM_MEMORY_CUR}, {imaging::image_format::xbm(), IFM_XBM}, {imaging::image_format::memory_xbm(), IFM_MEMORY_XBM}, {imaging::image_format::xpm(), IFM_XPM}, {imaging::image_format::memory_xpm(), IFM_MEMORY_XPM}, {imaging::image_format::pnm(), IFM_PNM}, {imaging::image_format::memory_pnm(), IFM_MEMORY_PNM}, {imaging::image_format::pcx(), IFM_PCX}, {imaging::image_format::memory_pcx(), IFM_MEMORY_PCX}, {imaging::image_format::pict(), IFM_PICT}, {imaging::image_format::memory_pict(), IFM_MEMORY_PICT}, {imaging::image_format::icon(), IFM_ICON}, {imaging::image_format::memory_icon(), IFM_MEMORY_ICON}, {imaging::image_format::cursor(), IFM_MACCUR}, {imaging::image_format::memory_cursor(), IFM_MEMORY_MACCUR}, {imaging::image_format::ani(), IFM_ANI}, {imaging::image_format::iif(), IFM_IIF}, {imaging::image_format::tga(), IFM_TGA}};
    return image_formats.find(image_format) == image_formats.end() ? IFM_UNKNOWN : image_formats[image_format];
  }
}

image::image(const std::string &filename) {
  this->data_->handle_ = native::image::create(filename);
  this->update_properties();
}

image::image(std::istream& stream) {
  this->data_->handle_ = native::image::create(stream);
  this->update_properties();
}

image::image(const char* const* bits) {
  this->data_->handle_ = native::image::create(bits);
  this->data_->raw_format_ = imaging::image_format::memory_xpm();
  this->update_properties();
}

image::image(int32_t width, int32_t height) {
  this->data_->handle_ = native::image::create(width, height);
  this->update_properties();
}

image::image(const image& image, int32_t width, int32_t height) {
  this->data_->handle_ = native::image::create(image.handle(), width, height);
  this->update_properties();
}

image::image(const image& image, const rectangle& rect) {
  this->data_->handle_ = native::image::create(image.handle(), rect.left(), rect.top(), rect.width(), rect.height());
  this->update_properties();
}

image::~image() {
  if (this->data_.use_count() == 1 && this->data_->handle_)
    native::image::destroy(this->data_->handle_);
}

void image::update_properties() {
  this->data_->flags_ = static_cast<imaging::image_flags>(native::image::flags(this->data_->handle_));
  
  size_t frame_dimensions = native::image::frame_resolutions(this->data_->handle_);
  if ((frame_dimensions & FD_PAGE) == FD_PAGE) this->data_->frame_dimentions_list_.push_back(imaging::frame_dimension::page().guid());
  if ((frame_dimensions & FD_RESOLUTION) == FD_RESOLUTION) this->data_->frame_dimentions_list_.push_back(imaging::frame_dimension::resolution().guid());
  if ((frame_dimensions & FD_TIME) == FD_TIME) this->data_->frame_dimentions_list_.push_back(imaging::frame_dimension::time().guid());

  this->data_->horizontal_resolution_ = native::image::horizontal_resolution(this->data_->handle_);

  std::vector<native::argb> palette_entries;
  native::image::color_palette(this->data_->handle_, palette_entries, this->data_->palette_.flags_);
  for (native::argb color : palette_entries)
    this->data_->palette_.entries_.push_back(color::from_argb(color.a, color.r, color.g, color.b));
    
  this->data_->pixel_format_ = static_cast<imaging::pixel_format>(native::image::pixel_format(this->data_->handle_));
  
  int32_t physical_width, physical_height;
  native::image::physical_dimension(this->data_->handle_, physical_width, physical_height);
  this->data_->physical_dimension_ = drawing::size_f(static_cast<float>(physical_width), static_cast<float>(physical_height));
  
  this->data_->property_id_list_ = native::image::property_id_list(this->data_->handle_);
  
  for(const native::image::property_item& i : native::image::property_items(this->data_->handle_)) {
    imaging::property_item item;
    item.id(i.id);
    item.len(i.len);
    item.value(i.value);
    this->data_->property_ityems_.push_back(item);
  }

  data_->raw_format_ = to_image_format(native::image::raw_format(this->data_->handle_));
  
  int32_t width, height;
  native::image::size(this->data_->handle_, width, height);
  this->data_->size_ = drawing::size(width, height);

  this->data_->vertical_resolution_ = native::image::vertical_resolution(this->data_->handle_);
}

void image::save(const std::string& filename) const {
  native::image::save(data_->handle_, filename);
}

void image::save(const std::string& filename, const imaging::image_format& format) const {
  native::image::save(data_->handle_, filename, to_raw_format(format));
}

void image::save(std::ostream& stream, const imaging::image_format& format) const {
  native::image::save(data_->handle_, stream, to_raw_format(format));
}
