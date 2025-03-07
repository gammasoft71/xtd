#include "../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../include/xtd/drawing/bitmap.hpp"
#include "../../../include/xtd/drawing/image_converter.hpp"
#include <xtd/bit_converter.hpp>
#include <xtd/convert.hpp>
#include <xtd/sizeof.hpp>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::drawing;
using namespace xtd::drawing::helpers;
using namespace xtd::drawing::imaging;

image image_converter::from_base64_string(const string& value) {
  if (value.empty()) return image::empty;
  return to_image(convert::from_base64_string(value));
}

array<byte> image_converter::to_array(const image& value) {
  if (value == image::empty) return {};
  
  auto height = value.height();
  auto width = value.width();
  auto value_alpha = reinterpret_cast<const alpha*>(value.alpha());
  auto value_rgb = reinterpret_cast<const rgb*>(value.rgb());
  auto result = array<byte>(sizeof_(width) + sizeof_(height) + width * height * 4);
  auto index = 0_z;
  for (auto b : bit_converter::get_bytes(width))
    result[index++] = b;
  for (auto b : bit_converter::get_bytes(height))
    result[index++] = b;
  for (auto y = 0; y < height; ++y)
    for (auto x = 0; x < width; ++x) {
      auto pixel = y * width + x;
      result[index++] = value_alpha[pixel].a;
      result[index++] = value_rgb[pixel].r;
      result[index++] = value_rgb[pixel].g;
      result[index++] = value_rgb[pixel].b;
    }
  return result;
}

string image_converter::to_base64_string(const image& value) {
  if (value == image::empty) return {};
  return convert::to_base64_string(to_array(value));
}

void image_converter::to_file(const image& value, const string& filename) {
  value.save(filename);
}

void image_converter::to_file(const image& value, const string& filename, const image_format& format) {
  value.save(filename, format);
}

image image_converter::to_image(const array<byte>& value) {
  return to_image(read_only_span<byte>(value));
}

image image_converter::to_image(const xtd::read_only_span<xtd::byte>& value) {
  if (value.size() == 0) return image::empty;
  if (value.size() % 4 != 0) throw_helper::throws(xtd::helpers::exception_case::argument);
  if (value.size() < 8) throw_helper::throws(xtd::helpers::exception_case::argument);
  auto index = 0_z;
  auto width = bit_converter::to_int32(value, index);
  index += 4;
  auto height = bit_converter::to_int32(value, index);
  index += 4;
  if (value.size() < static_cast<xtd::size>(8 + width * height * 4)) throw_helper::throws(xtd::helpers::exception_case::argument);
  if (width < 1 || height < 1) throw_helper::throws(xtd::helpers::exception_case::argument);

  auto result = bitmap {width, height};
  auto result_alpha = reinterpret_cast<alpha*>(result.alpha());
  auto result_rgb = reinterpret_cast<rgb*>(result.rgb());
  for (auto y = 0; y < height; ++y)
    for (auto x = 0; x < width; ++x) {
      auto pixel = y * width + x;
      result_alpha[pixel].a = value[index++];
      result_rgb[pixel].r = value[index++];
      result_rgb[pixel].g = value[index++];
      result_rgb[pixel].b = value[index++];
    }
  return result;
}

image image_converter::image_converter::to_image(const string& filename) {
  return image::from_file(filename);
}

image image_converter::to_image(std::istream& stream) {
  return image::from_stream(stream);
}

void image_converter::to_stream(const xtd::drawing::image& value, std::ostream& stream, const image_format& format) {
  value.save(stream, format);
}
