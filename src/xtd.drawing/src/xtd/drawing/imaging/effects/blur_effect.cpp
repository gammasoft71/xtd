#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/blur_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

blur_effect::blur_effect(int32 radius) : radius {radius} {
}

void blur_effect::apply(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& rectangle) const {
  auto image = bitmap {rectangle.size()};
  auto img_graphics = image.create_graphics();
  img_graphics.copy_from_graphics(graphics, rectangle.location(), {0, 0}, rectangle.size());
  image.blur(radius);
  graphics.draw_image(image, rectangle);
}
