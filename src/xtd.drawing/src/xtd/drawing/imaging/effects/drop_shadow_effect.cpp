#include "../../../../../include/xtd/drawing/imaging/effects/drop_shadow_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/image_effector.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/bitonal_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/blur_effect.hpp"
#include "../../../../../include/xtd/drawing/imaging/effects/crop_effect.hpp"
#include "../../../../../include/xtd/drawing/bitmap"
#include "../../../../../include/xtd/drawing/color_converter.hpp"
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;
using namespace xtd::drawing::imaging::effects;
using namespace xtd::helpers;

drop_shadow_effect::drop_shadow_effect(const xtd::drawing::size& shadow) : drop_shadow_effect {shadow, 0, color::black} {
}

drop_shadow_effect::drop_shadow_effect(const xtd::drawing::size& shadow, int32 blur) : drop_shadow_effect {shadow, blur, color::black} {
}

drop_shadow_effect::drop_shadow_effect(const xtd::drawing::size& shadow, int32 blur, const drawing::color& color) : blur {blur}, color {color}, shadow {shadow} {
}

void drop_shadow_effect::apply(xtd::drawing::image& image) const {
  if (image == drawing::image::empty) return;
  
  auto shadow_image = image.clone();
  image_effector::set_effect(shadow_image, bitonal_effect {0, color, color});
  if (blur) {
    image_effector::set_effect(shadow_image, blur_effect {blur, true});
    image_effector::set_effect(shadow_image, crop_effect {rectangle {shadow.width < 0 ? 0 : blur * 2, shadow.height < 0 ? 0 : blur * 2, image.width(), image.height()}});
  }
  
  auto result_image = bitmap {image.width() + math::abs(shadow.width), image.height() + math::abs(shadow.height)};
  auto graphics_result_image = result_image.create_graphics();
  graphics_result_image.draw_image(shadow_image, point {shadow.width < 0 ? 0 : math::abs(shadow.width), shadow.height < 0 ? 0 : math::abs(shadow.height)});
  graphics_result_image.draw_image(image, point {shadow.width < 0 ? math::abs(shadow.width) : 0, shadow.height < 0 ? math::abs(shadow.height) : 0});
  image = result_image;
}
