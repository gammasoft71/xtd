#include "../../../../../include/xtd/drawing/imaging/effects/rotate_flip_effect.hpp"
#include "../../../../../include/xtd/drawing/image.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

rotate_flip_effect::rotate_flip_effect(xtd::drawing::rotate_flip_type rotate_flip_type) : rotate_flip_type {rotate_flip_type} {
}

void rotate_flip_effect::apply(xtd::drawing::image& image) const {
  image.rotate_flip(rotate_flip_type);
}
