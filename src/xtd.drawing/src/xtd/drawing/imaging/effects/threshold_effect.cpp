#include "../../../../../include/xtd/drawing/imaging/effects/bitonal_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/threshold_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/image_effector.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;

threshold_effect::threshold_effect(int32 threshold) : threshold {threshold} {
}

void threshold_effect::apply(xtd::drawing::image& image) const {
  image_effector::set_effect(image, bitonal_effect {threshold, color::white, color::black});
}
