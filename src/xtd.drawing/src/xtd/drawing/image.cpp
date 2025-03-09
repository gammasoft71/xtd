#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/imaging/effects/rotate_flip_effect.hpp"
#include "../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../include/xtd/drawing/image.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"
#include "../../../include/xtd/drawing/graphics.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/drawing/native/image>
#include <xtd/drawing/native/image_formats>
#include <xtd/drawing/native/frame_dimension>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/helpers/throw_helper>
#include <xtd/as>
#include <algorithm>
#include <iostream>
#include <memory>
#include <tuple>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::drawing::helpers;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;
using namespace xtd::io;

image image::empty;

namespace {
  image flip_x(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {width, height};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = y * width + width - x - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image rotate_180(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {width, height};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = (height - y - 1) * width + width - x - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image rotate_270(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {height, width};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = (width - x -1) * height + y;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image rotate_90(const image& source_image) {
    auto width = source_image.width();
    auto height = source_image.height();
    auto source_alpha = reinterpret_cast<const alpha*>(source_image.alpha());
    auto source_rgb = reinterpret_cast<const rgb*>(source_image.rgb());
    auto result_image = bitmap {height, width};
    auto result_alpha = reinterpret_cast<alpha*>(result_image.alpha());
    auto result_rgb = reinterpret_cast<rgb*>(result_image.rgb());
    
    for (auto y = 0; y < height; ++y)
      for (auto x = 0; x < width; ++x) {
        auto source_pixel = y * width + x;
        auto result_pixel = x * height + height - y - 1;
        result_alpha[result_pixel] = source_alpha[source_pixel];
        result_rgb[result_pixel] = source_rgb[source_pixel];
      }
    return result_image;
  }
  
  image_format to_image_format(xtd::size raw_fomat) {
    static auto raw_formats = std::map<xtd::size, image_format> {{IFM_BMP, imaging::image_format::bmp()}, {IFM_EMF, imaging::image_format::emf()}, {IFM_EXIF, imaging::image_format::exif()}, {IFM_GIF, imaging::image_format::gif()}, {IFM_ICO, imaging::image_format::ico()}, {IFM_JPEG, imaging::image_format::jpeg()}, {IFM_MEMORY_BMP, imaging::image_format::memory_bmp()}, {IFM_PNG, imaging::image_format::png()}, {IFM_TIFF, imaging::image_format::tiff()}, {IFM_WMF, imaging::image_format::wmf()}, {IFM_MEMORY_GIF, imaging::image_format::memory_gif()}, {IFM_MEMORY_ICO, imaging::image_format::memory_ico()}, {IFM_MEMORY_JPEG, imaging::image_format::memory_jpeg()}, {IFM_MEMORY_PNG, imaging::image_format::memory_png()}, {IFM_MEMORY_TIFF, imaging::image_format::memory_tiff()}, {IFM_CUR, imaging::image_format::cur()}, {IFM_MEMORY_CUR, imaging::image_format::memory_cur()}, {IFM_XBM, imaging::image_format::xbm()}, {IFM_MEMORY_XBM, imaging::image_format::memory_xbm()}, {IFM_XPM, imaging::image_format::xpm()}, {IFM_MEMORY_XPM, imaging::image_format::memory_xpm()}, {IFM_PNM, imaging::image_format::pnm()}, {IFM_MEMORY_PNM, imaging::image_format::memory_pnm()}, {IFM_PCX, imaging::image_format::pcx()}, {IFM_MEMORY_PCX, imaging::image_format::memory_pcx()}, {IFM_PICT, imaging::image_format::pict()}, {IFM_MEMORY_PICT, imaging::image_format::memory_pict()}, {IFM_ICON, imaging::image_format::icon()}, {IFM_MEMORY_ICON, imaging::image_format::memory_icon()}, {IFM_MACCUR, imaging::image_format::cursor()}, {IFM_MEMORY_MACCUR, imaging::image_format::memory_cursor()}, {IFM_ANI, imaging::image_format::ani()}, {IFM_IIF, imaging::image_format::iif()}, {IFM_TGA, imaging::image_format::tga()}};
    auto it = raw_formats.find(raw_fomat);
    return it == raw_formats.end() ? image_format() : it->second;
  }
  
  xtd::size to_raw_format(const class image_format& image_format) {
    static auto image_formats = std::map<class image_format, xtd::size> {{imaging::image_format::bmp(), IFM_BMP}, {imaging::image_format::emf(), IFM_EMF}, {imaging::image_format::exif(), IFM_EXIF}, {imaging::image_format::gif(), IFM_GIF}, {imaging::image_format::ico(), IFM_ICO}, {imaging::image_format::jpeg(), IFM_JPEG}, {imaging::image_format::memory_bmp(), IFM_MEMORY_BMP}, {imaging::image_format::png(), IFM_PNG}, {imaging::image_format::tiff(), IFM_TIFF}, {imaging::image_format::wmf(), IFM_WMF}, {imaging::image_format::memory_gif(), IFM_MEMORY_GIF}, {imaging::image_format::memory_ico(), IFM_MEMORY_ICO}, {imaging::image_format::memory_jpeg(), IFM_MEMORY_JPEG}, {imaging::image_format::memory_png(), IFM_MEMORY_PNG}, {imaging::image_format::memory_tiff(), IFM_MEMORY_TIFF}, {imaging::image_format::cur(), IFM_CUR}, {imaging::image_format::memory_cur(), IFM_MEMORY_CUR}, {imaging::image_format::xbm(), IFM_XBM}, {imaging::image_format::memory_xbm(), IFM_MEMORY_XBM}, {imaging::image_format::xpm(), IFM_XPM}, {imaging::image_format::memory_xpm(), IFM_MEMORY_XPM}, {imaging::image_format::pnm(), IFM_PNM}, {imaging::image_format::memory_pnm(), IFM_MEMORY_PNM}, {imaging::image_format::pcx(), IFM_PCX}, {imaging::image_format::memory_pcx(), IFM_MEMORY_PCX}, {imaging::image_format::pict(), IFM_PICT}, {imaging::image_format::memory_pict(), IFM_MEMORY_PICT}, {imaging::image_format::icon(), IFM_ICON}, {imaging::image_format::memory_icon(), IFM_MEMORY_ICON}, {imaging::image_format::cursor(), IFM_MACCUR}, {imaging::image_format::memory_cursor(), IFM_MEMORY_MACCUR}, {imaging::image_format::ani(), IFM_ANI}, {imaging::image_format::iif(), IFM_IIF}, {imaging::image_format::tga(), IFM_TGA}};
    auto it = image_formats.find(image_format);
    return it == image_formats.end() ? IFM_UNKNOWN : it->second;
  }

  std::tuple<array<xtd::byte>, int32, int32> get_data_from_xbm(const string& filename) {
    auto lines = file::read_all_lines(filename);
    auto offset = 0_z;
    lines[offset] = lines[offset].substring(lines[offset].last_index_of("width") + 5);
    ++offset;
    lines[offset] = lines[offset].substring(lines[offset].last_index_of("height") + 6);
    offset += 1 + (lines[offset].contains("x_hot") ? 1 : 0) + (lines[offset].contains("y_hot") ? 1 : 0);
    lines[offset] = lines[offset].substring(lines[offset].last_index_of("{") + 1);
    lines[lines.size() - 1] = lines[lines.size() - 1].replace("};", "");
    auto width = int32_object::parse(lines[0].trim());
    auto height = int32_object::parse(lines[1].trim());
    auto bits = list<xtd::byte> {};
    for (auto index = offset; index < lines.size(); ++index)
      for (auto b : lines[index].split(","))
        bits.add(byte_object::parse(b.trim(), xtd::number_styles::hex_number));
    return std::make_tuple(bits.to_array(), width, height);
  }

  ptr<char*[]> get_data_from_xpm(const string& filename) {
    static thread_local std::vector<string> lines;
    lines = file::read_all_lines(filename);
    auto data = new char*[lines.size()];
    for (auto index = 0_z; index < lines.size() - 2; ++index) {
      lines[index + 1] = lines[index + 1].trim().replace("\"", "").replace(",", "");
      data[index] = const_cast<char*>(lines[index + 1].c_str());
    }
    return ptr<char *[]> {data};
  }
}

struct image::data {
  imaging::image_flags flags = imaging::image_flags::none;
  std::map<xtd::guid, xtd::size> frame_dimensions = {{frame_dimension::page().guid(), 1}};
  intptr handle = 0;
  float horizontal_resolution = .0f;
  imaging::color_palette palette;
  imaging::pixel_format pixel_format = imaging::pixel_format::undefined;
  size_f physical_dimension;
  xtd::array<int32> property_id_list;
  xtd::array<imaging::property_item> property_items;
  imaging::image_format raw_format;
  drawing::size size;
  std::any tag;
  float vertical_resolution = .0f;
  encoder_parameters encoder_parameter_list;
};

image::image() : data_(xtd::new_sptr<data>()) {
}

image::image(intptr hbitmap) : data_(xtd::new_sptr<data>()) {
  if (hbitmap) data_->handle = hbitmap;
  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  update_properties();
}

image::image(const string& filename) : image::image(filename, false) {
}

image::image(const string& filename, bool use_icm) : data_(xtd::new_sptr<data>()) {
  if (!xtd::io::file::exists(filename)) throw_helper::throws(exception_case::argument);
  auto frame_resolutions = std::map<xtd::size, xtd::size> {};
  if (path::get_extension(filename) == ".xbm") {
    auto [bits, width, height] = get_data_from_xbm(filename);
    data_->handle = native::image::create(reinterpret_cast<const unsigned char*>(bits.data()), width, height, frame_resolutions);
    data_->raw_format = imaging::image_format::xbm();
  } else if (path::get_extension(filename) == ".xpm") {
    auto bits = get_data_from_xpm(filename);
    data_->handle = native::image::create(bits.get(), frame_resolutions);
    data_->raw_format = imaging::image_format::xpm();
  } else data_->handle = native::image::create(filename, use_icm, frame_resolutions);

  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  data_->frame_dimensions.clear();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) data_->frame_dimensions[imaging::frame_dimension::page().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) data_->frame_dimensions[imaging::frame_dimension::time().guid()] = frame_resolution.second;
    else throw_helper::throws(exception_case::argument);
  }
  update_properties();
}

image::image(std::istream& stream) : image::image(stream, false) {
}

image::image(std::istream& stream, bool use_icm) : data_(xtd::new_sptr<data>()) {
  auto frame_resolutions = std::map<xtd::size, xtd::size> {};
  data_->handle = native::image::create(stream, use_icm, frame_resolutions);
  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  data_->frame_dimensions.clear();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) data_->frame_dimensions[imaging::frame_dimension::page().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) data_->frame_dimensions[imaging::frame_dimension::time().guid()] = frame_resolution.second;
    else throw_helper::throws(exception_case::argument);
  }
  update_properties();
}

image::image(int32 width, int32 height) : data_(xtd::new_sptr<data>()) {
  if (width < 1 || height < 1) throw_helper::throws(exception_case::argument);
  data_->handle = native::image::create(width, height);
  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  update_properties();
}

image::image(int32 width, int32 height, float horizontal_resolution, float vertical_resolution) : data_(xtd::new_sptr<data>()) {
  if (width < 1 || height < 1) throw_helper::throws(exception_case::argument);
  data_->handle = native::image::create(width, height, horizontal_resolution, vertical_resolution);
  update_properties();
}

image::image(int32 width, int32 height, enum pixel_format format) {
  if (width < 1 || height < 1) throw_helper::throws(exception_case::argument);
  data_->handle = native::image::create(width, height, as<int32>(format));
  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  update_properties();
}

image::image(int32 width, int32 height, int32 stride, enum pixel_format format, intptr scan0) {
  if (width < 1 || height < 1) throw_helper::throws(exception_case::argument);
  data_->handle = native::image::create(width, height, stride, as<int32>(format), scan0);
  if (data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  update_properties();
}

image::image(const image& image, int32 width, int32 height) : data_(xtd::new_sptr<data>()) {
  if (width < 1 || height < 1) throw_helper::throws(exception_case::argument);
  *this = image.clone();
  scale({width, height}, drawing_2d::interpolation_mode::default_value);
  update_properties();
}

image::image(const image& image, const rectangle& rect) : data_(xtd::new_sptr<data>()) {
  if (rect.left() < 0 || rect.top() < 0 || rect.width < 1 || rect.height < 1) throw_helper::throws(exception_case::argument);
  *this = image.clone();
  resize(rect, color::transparent);
  update_properties();
}

image::~image() {
  if (data_.use_count() == 1 && data_->handle)
    native::image::destroy(data_->handle);
}

const xtd::byte* image::alpha() const {
  return native::image::get_alpha(handle());
}

xtd::byte* image::alpha() {
  return native::image::get_alpha(handle());
}

int32 image::flags() const noexcept {
  return static_cast<int32>(data_->flags);
}

std::vector<guid> image::frame_dimentions_list() const noexcept {
  auto result = std::vector<guid> {};
  std::for_each(data_->frame_dimensions.begin(), data_->frame_dimensions.end(), [&](auto frame) {result.push_back(frame.first);});
  return result;
}

intptr image::handle() const noexcept {
  return data_->handle;
}

int32 image::height() const noexcept {
  return data_->size.height;
}

float image::horizontal_resolution() const noexcept {
  return data_->horizontal_resolution;
}

imaging::color_palette image::palette() const noexcept {
  return data_->palette;
}

void image::palette(const imaging::color_palette& palette) noexcept {
  data_->palette = palette;
}

const size_f& image::physical_dimension() const noexcept {
  return data_->physical_dimension;
}

imaging::pixel_format image::pixel_format() const noexcept {
  return data_->pixel_format;
}

const array<int32>& image::property_id_list() const noexcept {
  return data_->property_id_list;
}

const array<imaging::property_item>& image::property_items() const noexcept {
  return data_->property_items;
}

const imaging::image_format& image::raw_format() const noexcept {
  return data_->raw_format;
}

const xtd::byte* image::rgb() const {
  return native::image::get_data(handle());
}

xtd::byte* image::rgb() {
  return native::image::get_data(handle());
}

const drawing::size& image::size() const noexcept {
  return data_->size;
}

const std::any& image::tag() const noexcept {
  return data_->tag;
}

void image::tag(const std::any& tag) noexcept {
  data_->tag = tag;
}

float image::vertical_resolution() const noexcept {
  return data_->vertical_resolution;
}

int32 image::width() const noexcept {
  return data_->size.width;
}

image image::clone() const {
  if (*this == image::empty) return *this;

  auto result = xtd::drawing::image {width(), height()};
  auto graphics = result.create_graphics();
  graphics.draw_image(*this, rectangle({0, 0, width(), height()}));
  result.update_properties();
  return result;
}

graphics image::create_graphics() {
  return graphics::from_image(*this);
}

bool image::equals(const object& obj) const noexcept {
  return is<image>(obj) && equals(static_cast<const image&>(obj));
}

bool image::equals(const image& other) const noexcept {
  if (handle() == other.handle()) return true;
  if (flags() != other.flags()) return false;
  if (frame_dimentions_list() != other.frame_dimentions_list()) return false;
  if (horizontal_resolution() != other.horizontal_resolution()) return false;
  if (palette() != other.palette()) return false;
  if (physical_dimension() != other.physical_dimension()) return false;
  if (pixel_format() != other.pixel_format()) return false;
  if (property_id_list() != other.property_id_list()) return false;
  if (property_items() != other.property_items()) return false;
  if (raw_format() != other.raw_format()) return false;
  if (size() != other.size()) return false;
  //if (tag() != other.tag()) return false;
  if (vertical_resolution() != other.vertical_resolution()) return false;
  auto bmp1 = bitmap {*this};
  auto bmp2 = bitmap {other};
  for (auto x = 0; x < width(); ++x)
    for (auto y = 0; y < height(); ++y)
      if (bmp1.get_pixel(x, y) != bmp2.get_pixel(x, y)) return false;
  return true;
}

rectangle_f image::get_bounds(graphics_unit page_unit) const noexcept {
  return rectangle_f {0.0f, 0.0f, graphics::to_page_unit(as<float>(data_->size.width), page_unit, 1.0f, native::image::screen_dpi()), graphics::to_page_unit(as<float>(data_->size.height), page_unit, 1.0f, native::image::screen_dpi())};
}

encoder_parameters image::get_encoder_parameter_list(guid encoder) const noexcept {
  auto parameters = list<encoder_parameter> {};
  for (const auto& encoder_parameter : data_->encoder_parameter_list.params)
    if (encoder_parameter.encoder().guid() == encoder)
      parameters.add(encoder_parameter);
  auto result = encoder_parameters {};
  result.params = parameters.to_array();
  return result;
}

xtd::size image::get_frame_count(const frame_dimension& dimension) const {
  auto iterator = std::find_if(data_->frame_dimensions.begin(), data_->frame_dimensions.end(), [&](auto frame) {return frame.first == dimension.guid();});
  if (iterator == data_->frame_dimensions.end()) throw_helper::throws(exception_case::argument);
  return iterator->second;
}

xtd::size image::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(handle());
  result.add(flags());
  for (const auto& frame_dimention : frame_dimentions_list())
    result.add(frame_dimention);
  result.add(horizontal_resolution());
  result.add(palette());
  result.add(physical_dimension());
  result.add(pixel_format());
  for (const auto& property_id : property_id_list())
    result.add(property_id);
  for (const auto& property_item : property_items())
  result.add(property_item);
  result.add(raw_format());
  result.add(size());
  //result.add(tag());
  result.add(vertical_resolution());
  auto bmp = bitmap {*this};
  for (auto x = 0; x < width(); ++x)
    for (auto y = 0; y < height(); ++y)
      result.add(get_pixel(x, y));
  return result.to_hash_code();
}

int32 image::get_pixel_format_size(enum pixel_format pixfmt) noexcept {
  return (static_cast<int32>(pixfmt) >> 8) & 0xFF;
}

property_item image::get_property_item(int32 propid) {
  for (auto property_tiem : data_->property_items)
    if (property_tiem.id() == propid) return property_tiem;
  throw_helper::throws(exception_case::argument);
}

xtd::drawing::image image::get_thmbnail_image(int32 thumb_width, int32 thunb_height) noexcept {
  return image(*this, thumb_width, thunb_height);
}

bool image::is_alpha_pixel_format(enum pixel_format pixfmt) noexcept {
  return (pixfmt & pixel_format::alpha) == pixel_format::alpha;
}

bool image::is_canonical_pixel_format(enum pixel_format pixfmt) noexcept {
  return (pixfmt & pixel_format::canonical) == pixel_format::canonical;
}

bool image::is_extended_pixel_format(enum pixel_format pixfmt) noexcept {
  return (pixfmt & pixel_format::extended) == pixel_format::extended;
}

void image::rotate_flip(xtd::drawing::rotate_flip_type rotate_flip_type) {
  switch (rotate_flip_type) {
    case rotate_flip_type::rotate_none_flip_none: break;
    case rotate_flip_type::rotate_90_flip_none: *this = rotate_90(*this); break;
    case rotate_flip_type::rotate_180_flip_none: *this = rotate_180(*this); break;
    case rotate_flip_type::rotate_270_flip_none: *this = rotate_270(*this); break;
    case rotate_flip_type::rotate_none_flip_x: *this = flip_x(*this); break;
    case rotate_flip_type::rotate_90_flip_x: *this = flip_x(rotate_90(*this)); break;
    case rotate_flip_type::rotate_180_flip_x: *this = flip_x(rotate_180(*this)); break;
    case rotate_flip_type::rotate_270_flip_x: *this = flip_x(rotate_270(*this)); break;
    default: break;
  }
}

void image::save(const string& filename) const {
  native::image::save(data_->handle, filename);
}

void image::save(const string& filename, const imaging::image_format& format) const {
  native::image::save(data_->handle, filename, to_raw_format(format));
}

void image::save(std::ostream& stream, const imaging::image_format& format) const {
  native::image::save(data_->handle, stream, to_raw_format(format));
}

image image::from_file(const xtd::string& filename) {
  return image(filename);
}

bitmap image::from_hbitmap(intptr hbitmap) {
  return bitmap {image {hbitmap}};
}

image image::from_stream(std::istream& stream) { // stream param can't be const by design.
  return image {stream};
}

image image::from_hicon(intptr hicon) {
  auto result = image {};
  result.data_->handle = native::image::from_hicon(hicon);
  if (result.data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  result.update_properties();
  return result;
}

bitmap image::from_xbm_data(const unsigned char* bits, int32 width, int32 height) {
  auto img = image {};
  auto frame_resolutions = std::map<xtd::size, xtd::size> {};
  img.data_->handle = native::image::create(bits, width, height, frame_resolutions);
  if (img.data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  img.data_->raw_format = imaging::image_format::memory_xpm();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) img.data_->frame_dimensions[imaging::frame_dimension::page().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) img.data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) img.data_->frame_dimensions[imaging::frame_dimension::time().guid()] = frame_resolution.second;
    else throw_helper::throws(exception_case::argument);
  }
  img.update_properties();
  return bitmap {img};
}

bitmap image::from_xpm_data(const char* const* bits) {
  auto img = image {};
  auto frame_resolutions = std::map<xtd::size, xtd::size> {};
  img.data_->handle = native::image::create(bits, frame_resolutions);
  if (img.data_->handle == invalid_handle) throw_helper::throws(exception_case::argument);
  img.data_->raw_format = imaging::image_format::memory_xpm();
  for (auto frame_resolution : frame_resolutions) {
    if (frame_resolution.first == FD_PAGE) img.data_->frame_dimensions[imaging::frame_dimension::page().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_RESOLUTION) img.data_->frame_dimensions[imaging::frame_dimension::resolution().guid()] = frame_resolution.second;
    else if (frame_resolution.first == FD_TIME) img.data_->frame_dimensions[imaging::frame_dimension::time().guid()] = frame_resolution.second;
    else throw_helper::throws(exception_case::argument);
  }
  img.update_properties();
  return bitmap {img};
}

drawing::color image::get_pixel(int32 x, int32 y) const {
  if (x < 0 || x > width() || y < 0 || y > height()) throw_helper::throws(exception_case::argument);
  
  auto alpha = this->alpha();
  auto rgb = reinterpret_cast<const helpers::rgb*>(this->rgb());
  auto pixel = y * width() + x;
  return color::from_argb(alpha[pixel], rgb[pixel].r, rgb[pixel].g, rgb[pixel].b);
}

void image::resize(const xtd::drawing::rectangle& rect, const xtd::drawing::color& fill_color) {
  if (rect.x == 0 && rect.y == 0 && rect.width == width() && rect.height == height()) return;
  if (rect.x < 0 || rect.y < 0 || rect.width < 1 || rect.height < 1) throw_helper::throws(xtd::helpers::exception_case::argument);
  if (rect.width < width() && (rect.x + rect.width) > width()) throw_helper::throws(exception_case::argument);
  if (rect.height < height() && (rect.y + rect.height) > height()) throw_helper::throws(exception_case::argument);
  if (rect.width >= width() && (rect.x + width()) > rect.width) throw_helper::throws(exception_case::argument);
  if (rect.height >= height() && (rect.y + height()) > rect.height) throw_helper::throws(exception_case::argument);
  
  auto resized_image = image {rect.width, rect.height};
  auto resized_image_graphics = resized_image.create_graphics();
  
  auto offset_image_x = rect.width < width() ? rect.x : 0;
  auto offset_image_y = rect.height < height() ? rect.y : 0;
  auto offset_x = rect.width >= width() ? rect.x : 0;
  auto offset_y = rect.height >= height() ? rect.y : 0;
  resized_image_graphics.draw_image(*this, drawing::rectangle {offset_x, offset_y, rect.width, rect.height}, drawing::rectangle {offset_image_x, offset_image_y, rect.width, rect.height});
  
  if (fill_color != color::transparent) {
    auto alpha = reinterpret_cast<helpers::alpha*>(resized_image.alpha());
    auto rgb = reinterpret_cast<helpers::rgb*>(resized_image.rgb());
    
    for (auto x = 0; x < rect.width; ++x) {
      for (auto y = 0; y < offset_y; ++y) {
        auto pixel = y * rect.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
      
      for (auto y = offset_y + height(); y < rect.height; ++y) {
        auto pixel = y * rect.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
    }
    
    for (auto y = offset_y; y < offset_y + height(); ++y) {
      for (auto x = 0; x < offset_x; ++x) {
        auto pixel = y * rect.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
      
      for (auto x = offset_x +width(); x < rect.width; ++x) {
        auto pixel = y * rect.width + x;
        alpha[pixel].a = fill_color.a();
        rgb[pixel] = {fill_color.r(), fill_color.g(), fill_color.b()};
      }
    }
  }
  
  *this = resized_image;
}

void image::scale(const xtd::drawing::size& size, xtd::drawing::drawing_2d::interpolation_mode interpolation_mode) {
  if (this->size() == size) return;
  auto result = bitmap {size};
  auto graphics = result.create_graphics();
  graphics.interpolation_mode(interpolation_mode);
  graphics.draw_image(*this, result.get_bounds(graphics_unit::pixel), 0, 0, width(), height());
  *this = result;
}

void image::set_pixel(int32 x, int32 y, const drawing::color& color) {
  if (x < 0 || x > width() || y < 0 || y > height()) throw_helper::throws(exception_case::argument);
  
  auto alpha = this->alpha();
  auto rgb = reinterpret_cast<helpers::rgb*>(this->rgb());
  auto pixel = y * width() + x;
  alpha[pixel] = color.a();
  rgb[pixel] = {color.r(), color.g(), color.b()};
}

void image::set_pixel_format(imaging::pixel_format value) {
  data_->pixel_format = value;
}

void image::update_properties() {
  if (!data_->handle) return;
  data_->flags = static_cast<imaging::image_flags>(native::image::flags(data_->handle));
  
  data_->horizontal_resolution = native::image::horizontal_resolution(data_->handle);
  
  auto palette_entries = std::vector<std::tuple<xtd::byte, xtd::byte, xtd::byte, xtd::byte>> {};
  native::image::color_palette(data_->handle, palette_entries, data_->palette.flags_);
  for (auto [a, r, g, b] : palette_entries)
    data_->palette.entries_.push_back(color::from_argb(a, r, g, b));
  
  data_->pixel_format = static_cast<imaging::pixel_format>(native::image::pixel_format(data_->handle));
  
  auto physical_width = 0, physical_height = 0;
  native::image::physical_dimension(data_->handle, physical_width, physical_height);
  data_->physical_dimension = drawing::size_f(static_cast<float>(physical_width), static_cast<float>(physical_height));
  
  data_->property_id_list = native::image::property_id_list(data_->handle);
  
  for (const native::image::property_item& i : native::image::property_items(data_->handle)) {
    auto item = imaging::property_item {};
    item.id(i.id);
    item.value(i.value);
    data_->property_items.resize(data_->property_items.length() + 1, item);
  }
  
  if (data_->raw_format == image_format {}) data_->raw_format = to_image_format(native::image::raw_format(data_->handle));
  
  auto w = 0, h = 0;
  native::image::size(data_->handle, w, h);
  data_->size = drawing::size(w, h);
  
  data_->vertical_resolution = native::image::vertical_resolution(data_->handle);
}
