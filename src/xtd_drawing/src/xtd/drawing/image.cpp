#include "../../../include/xtd/drawing/image.hpp"
#include <fstream>
#include <xtd/drawing/native/image.hpp>
#include <xtd/drawing/native/image_format.hpp>
#include <xtd/drawing/native/frame_dimension.hpp>

using namespace xtd;
using namespace xtd::drawing;

image image::empty;

image::image(const ustring &filename) {
  std::fstream stream(filename, std::ios::in);
  this->data_->handle_ = native::image::create(stream);
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

  switch (native::image::raw_format(this->data_->handle_)) {
    case IFM_BMP: this->data_->raw_format_ = imaging::image_format::bmp(); break;
    case IFM_EMF: this->data_->raw_format_ = imaging::image_format::emf(); break;
    case IFM_EXIF: this->data_->raw_format_ = imaging::image_format::exif(); break;
    case IFM_GIF: this->data_->raw_format_ = imaging::image_format::gif(); break;
    case IFM_ICO: this->data_->raw_format_ = imaging::image_format::ico(); break;
    case IFM_JPEG: this->data_->raw_format_ = imaging::image_format::jpeg(); break;
    case IFM_MEMORY_BMP: this->data_->raw_format_ = imaging::image_format::memory_bmp(); break;
    case IFM_PNG: this->data_->raw_format_ = imaging::image_format::png(); break;
    case IFM_TIFF: this->data_->raw_format_ = imaging::image_format::tiff(); break;
    case IFM_WMF: this->data_->raw_format_ = imaging::image_format::wmf(); break;
    case IFM_MEMORY_GIF: this->data_->raw_format_ = imaging::image_format::memory_gif(); break;
    case IFM_MEMORY_ICO: this->data_->raw_format_ = imaging::image_format::memory_ico(); break;
    case IFM_MEMORY_JPEG: imaging::image_format::memory_jpeg(); break;
    case IFM_MEMORY_PNG: imaging::image_format::memory_png(); break;
    case IFM_MEMORY_TIFF: this->data_->raw_format_ = imaging::image_format::memory_tiff(); break;
    case IFM_CUR: this->data_->raw_format_ = imaging::image_format::cur(); break;
    case IFM_MEMORY_CUR: this->data_->raw_format_ = imaging::image_format::memory_cur(); break;
    case IFM_XBM: this->data_->raw_format_ = imaging::image_format::xbm(); break;
    case IFM_MEMORY_XBM: this->data_->raw_format_ = imaging::image_format::memory_xbm(); break;
    case IFM_XPM: this->data_->raw_format_ = imaging::image_format::xpm(); break;
    case IFM_MEMORY_XPM: this->data_->raw_format_ = imaging::image_format::memory_xpm(); break;
    case IFM_PNM: this->data_->raw_format_ = imaging::image_format::pnm(); break;
    case IFM_MEMORY_PNM: this->data_->raw_format_ = imaging::image_format::memory_pnm(); break;
    case IFM_PCX: this->data_->raw_format_ = imaging::image_format::pcx(); break;
    case IFM_MEMORY_PCX: this->data_->raw_format_ = imaging::image_format::memory_pcx(); break;
    case IFM_PICT: this->data_->raw_format_ = imaging::image_format::pict(); break;
    case IFM_MEMORY_PICT: this->data_->raw_format_ = imaging::image_format::memory_pict(); break;
    case IFM_ICON: this->data_->raw_format_ = imaging::image_format::icon(); break;
    case IFM_MEMORY_ICON: this->data_->raw_format_ = imaging::image_format::memory_icon(); break;
    case IFM_MACCUR: this->data_->raw_format_ = imaging::image_format::cursor(); break;
    case IFM_MEMORY_MACCUR: this->data_->raw_format_ = imaging::image_format::memory_cursor(); break;
    case IFM_ANI: this->data_->raw_format_ = imaging::image_format::ani(); break;
    case IFM_IIF: this->data_->raw_format_ = imaging::image_format::iif(); break;
    case IFM_TGA: this->data_->raw_format_ = imaging::image_format::tga(); break;
  }
  
  int32_t width, height;
  native::image::size(this->data_->handle_, width, height);
  this->data_->size_ = drawing::size(width, height);

  this->data_->vertical_resolution_ = native::image::vertical_resolution(this->data_->handle_);
}
