#include "../../../../../include/xtd/drawing/imaging/effects/scale_effect.hpp"
#include "../../../../../include/xtd/drawing/image.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

scale_effect::scale_effect(const xtd::drawing::size& size) : size {size} {
}

// For more information about algorithm see https://stackoverflow.com/questions/1922040/how-to-resize-an-image-c-sharp
void scale_effect::apply(xtd::drawing::image& image) const {
  auto size = this->size;
  if (size.width < 1) size.width = 1;
  if (size.height < 1) size.height = 1;
  image.rescale(size.width, size.height);
}
