#include "../../../include/xtd/drawing/emotes_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size emotes_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image emotes_system_images::face_angel() noexcept {
  return face_angel(default_size());
}

image emotes_system_images::face_angel(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-angel", size);
}

image emotes_system_images::face_angry() noexcept {
  return face_angry(default_size());
}

image emotes_system_images::face_angry(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-angry", size);
}

image emotes_system_images::face_cool() noexcept {
  return face_cool(default_size());
}

image emotes_system_images::face_cool(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-cool", size);
}

image emotes_system_images::face_crying() noexcept {
  return face_crying(default_size());
}

image emotes_system_images::face_crying(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-crying", size);
}

image emotes_system_images::face_devilish() noexcept {
  return face_devilish(default_size());
}

image emotes_system_images::face_devilish(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-devilish", size);
}

image emotes_system_images::face_embarrassed() noexcept {
  return face_embarrassed(default_size());
}

image emotes_system_images::face_embarrassed(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-embarrassed", size);
}

image emotes_system_images::face_kiss() noexcept {
  return face_kiss(default_size());
}

image emotes_system_images::face_kiss(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-kiss", size);
}

image emotes_system_images::face_laugh() noexcept {
  return face_laugh(default_size());
}

image emotes_system_images::face_laugh(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-laugh", size);
}

image emotes_system_images::face_monkey() noexcept {
  return face_monkey(default_size());
}

image emotes_system_images::face_monkey(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-monkey", size);
}

image emotes_system_images::face_plain() noexcept {
  return face_plain(default_size());
}

image emotes_system_images::face_plain(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-plain", size);
}

image emotes_system_images::face_raspberry() noexcept {
  return face_raspberry(default_size());
}

image emotes_system_images::face_raspberry(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-raspberry", size);
}

image emotes_system_images::face_sad() noexcept {
  return face_sad(default_size());
}

image emotes_system_images::face_sad(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-sad", size);
}

image emotes_system_images::face_sick() noexcept {
  return face_sick(default_size());
}

image emotes_system_images::face_sick(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-sick", size);
}

image emotes_system_images::face_smile() noexcept {
  return face_smile(default_size());
}

image emotes_system_images::face_smile(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-smile", size);
}

image emotes_system_images::face_smile_big() noexcept {
  return face_smile_big(default_size());
}

image emotes_system_images::face_smile_big(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-smile-big", size);
}

image emotes_system_images::face_smirk() noexcept {
  return face_smirk(default_size());
}

image emotes_system_images::face_smirk(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-smirk", size);
}

image emotes_system_images::face_surprise() noexcept {
  return face_surprise(default_size());
}

image emotes_system_images::face_surprise(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-surprise", size);
}

image emotes_system_images::face_tired() noexcept {
  return face_tired(default_size());
}

image emotes_system_images::face_tired(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-tired", size);
}

image emotes_system_images::face_uncertain() noexcept {
  return face_uncertain(default_size());
}

image emotes_system_images::face_uncertain(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-uncertain", size);
}

image emotes_system_images::face_wink() noexcept {
  return face_wink(default_size());
}

image emotes_system_images::face_wink(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-wink", size);
}

image emotes_system_images::face_worried() noexcept {
  return face_worried(default_size());
}

image emotes_system_images::face_worried(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("face-worried", size);
}

const vector<image>& emotes_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> emotes_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {face_angel(size), face_angry(size), face_cool(size), face_crying(size), face_devilish(size), face_embarrassed(size), face_kiss(size), face_laugh(size), face_monkey(size), face_plain(size), face_raspberry(size), face_sad(size), face_sick(size), face_smile(size), face_smile_big(size), face_smirk(size), face_surprise(size), face_tired(size), face_uncertain(size), face_wink(size), face_worried(size), };
}

const vector<ustring>& emotes_system_images::get_image_names() noexcept {
  static auto names = vector {"face-angel"_s, "face-angry"_s, "face-cool"_s, "face-crying"_s, "face-devilish"_s, "face-embarrassed"_s, "face-kiss"_s, "face-laugh"_s, "face-monkey"_s, "face-plain"_s, "face-raspberry"_s, "face-sad"_s, "face-sick"_s, "face-smile"_s, "face-smile-big"_s, "face-smirk"_s, "face-surprise"_s, "face-tired"_s, "face-uncertain"_s, "face-wink"_s, "face-worried"_s, };
  return names;
}
