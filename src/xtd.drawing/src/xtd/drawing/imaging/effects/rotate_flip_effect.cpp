#include "../../../../../include/xtd/drawing/helpers/alpha.hpp"
#include "../../../../../include/xtd/drawing/helpers/rgb.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/rotate_flip_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

rotate_flip_effect::rotate_flip_effect(xtd::drawing::rotate_flip_type rotate_flip_type) : rotate_flip_type {rotate_flip_type} {
}

void rotate_flip_effect::apply(xtd::drawing::image& image) const {
  image.rotate_flip(rotate_flip_type);
  if ((rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_90_flip_none ||
       rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_270_flip_none ||
       rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_90_flip_x ||
       rotate_flip_type == xtd::drawing::rotate_flip_type::rotate_270_flip_x) &&
      image.width() != image.height())
    image.rescale(image.height(), image.width());
}

