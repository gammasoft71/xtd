#include "../../../include/xtd/drawing/image_converter.hpp"

using namespace xtd::drawing;

void image_converter::rescale(xtd::drawing::image& image, const xtd::drawing::size& size) {
  image.rescale(size.width, size.height);
}

xtd::drawing::image image_converter::rescale(const xtd::drawing::image& image, const xtd::drawing::size& size) {
  // https://stackoverflow.com/questions/1922040/how-to-resize-an-image-c-sharp
  auto result = image.clone();
  rescale(result, size);
  return result;
}
