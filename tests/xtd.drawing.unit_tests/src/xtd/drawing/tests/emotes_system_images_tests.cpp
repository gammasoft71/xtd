#include <xtd/drawing/emotes_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(emotes_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = emotes_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(face_angel) {
      auto i = emotes_system_images::face_angel();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-angel"), i, csf_);
    }

    void test_method_(face_angel_with_specified_size) {
      auto i = emotes_system_images::face_angel({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-angel", size {64, 64}), i, csf_);
    }

    void test_method_(face_angry) {
      auto i = emotes_system_images::face_angry();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-angry"), i, csf_);
    }

    void test_method_(face_angry_with_specified_size) {
      auto i = emotes_system_images::face_angry({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-angry", size {64, 64}), i, csf_);
    }

    void test_method_(face_cool) {
      auto i = emotes_system_images::face_cool();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-cool"), i, csf_);
    }

    void test_method_(face_cool_with_specified_size) {
      auto i = emotes_system_images::face_cool({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-cool", size {64, 64}), i, csf_);
    }

    void test_method_(face_crying) {
      auto i = emotes_system_images::face_crying();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-crying"), i, csf_);
    }

    void test_method_(face_crying_with_specified_size) {
      auto i = emotes_system_images::face_crying({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-crying", size {64, 64}), i, csf_);
    }

    void test_method_(face_devilish) {
      auto i = emotes_system_images::face_devilish();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-devilish"), i, csf_);
    }

    void test_method_(face_devilish_with_specified_size) {
      auto i = emotes_system_images::face_devilish({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-devilish", size {64, 64}), i, csf_);
    }

    void test_method_(face_embarrassed) {
      auto i = emotes_system_images::face_embarrassed();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-embarrassed"), i, csf_);
    }

    void test_method_(face_embarrassed_with_specified_size) {
      auto i = emotes_system_images::face_embarrassed({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-embarrassed", size {64, 64}), i, csf_);
    }

    void test_method_(face_kiss) {
      auto i = emotes_system_images::face_kiss();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-kiss"), i, csf_);
    }

    void test_method_(face_kiss_with_specified_size) {
      auto i = emotes_system_images::face_kiss({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-kiss", size {64, 64}), i, csf_);
    }

    void test_method_(face_laugh) {
      auto i = emotes_system_images::face_laugh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-laugh"), i, csf_);
    }

    void test_method_(face_laugh_with_specified_size) {
      auto i = emotes_system_images::face_laugh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-laugh", size {64, 64}), i, csf_);
    }

    void test_method_(face_monkey) {
      auto i = emotes_system_images::face_monkey();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-monkey"), i, csf_);
    }

    void test_method_(face_monkey_with_specified_size) {
      auto i = emotes_system_images::face_monkey({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-monkey", size {64, 64}), i, csf_);
    }

    void test_method_(face_plain) {
      auto i = emotes_system_images::face_plain();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-plain"), i, csf_);
    }

    void test_method_(face_plain_with_specified_size) {
      auto i = emotes_system_images::face_plain({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-plain", size {64, 64}), i, csf_);
    }

    void test_method_(face_raspberry) {
      auto i = emotes_system_images::face_raspberry();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-raspberry"), i, csf_);
    }

    void test_method_(face_raspberry_with_specified_size) {
      auto i = emotes_system_images::face_raspberry({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-raspberry", size {64, 64}), i, csf_);
    }

    void test_method_(face_sad) {
      auto i = emotes_system_images::face_sad();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-sad"), i, csf_);
    }

    void test_method_(face_sad_with_specified_size) {
      auto i = emotes_system_images::face_sad({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-sad", size {64, 64}), i, csf_);
    }

    void test_method_(face_sick) {
      auto i = emotes_system_images::face_sick();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-sick"), i, csf_);
    }

    void test_method_(face_sick_with_specified_size) {
      auto i = emotes_system_images::face_sick({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-sick", size {64, 64}), i, csf_);
    }

    void test_method_(face_smile) {
      auto i = emotes_system_images::face_smile();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smile"), i, csf_);
    }

    void test_method_(face_smile_with_specified_size) {
      auto i = emotes_system_images::face_smile({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smile", size {64, 64}), i, csf_);
    }

    void test_method_(face_smile_big) {
      auto i = emotes_system_images::face_smile_big();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smile-big"), i, csf_);
    }

    void test_method_(face_smile_big_with_specified_size) {
      auto i = emotes_system_images::face_smile_big({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smile-big", size {64, 64}), i, csf_);
    }

    void test_method_(face_smirk) {
      auto i = emotes_system_images::face_smirk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smirk"), i, csf_);
    }

    void test_method_(face_smirk_with_specified_size) {
      auto i = emotes_system_images::face_smirk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-smirk", size {64, 64}), i, csf_);
    }

    void test_method_(face_surprise) {
      auto i = emotes_system_images::face_surprise();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-surprise"), i, csf_);
    }

    void test_method_(face_surprise_with_specified_size) {
      auto i = emotes_system_images::face_surprise({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-surprise", size {64, 64}), i, csf_);
    }

    void test_method_(face_tired) {
      auto i = emotes_system_images::face_tired();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-tired"), i, csf_);
    }

    void test_method_(face_tired_with_specified_size) {
      auto i = emotes_system_images::face_tired({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-tired", size {64, 64}), i, csf_);
    }

    void test_method_(face_uncertain) {
      auto i = emotes_system_images::face_uncertain();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-uncertain"), i, csf_);
    }

    void test_method_(face_uncertain_with_specified_size) {
      auto i = emotes_system_images::face_uncertain({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-uncertain", size {64, 64}), i, csf_);
    }

    void test_method_(face_wink) {
      auto i = emotes_system_images::face_wink();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-wink"), i, csf_);
    }

    void test_method_(face_wink_with_specified_size) {
      auto i = emotes_system_images::face_wink({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-wink", size {64, 64}), i, csf_);
    }

    void test_method_(face_worried) {
      auto i = emotes_system_images::face_worried();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-worried"), i, csf_);
    }

    void test_method_(face_worried_with_specified_size) {
      auto i = emotes_system_images::face_worried({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("face-worried", size {64, 64}), i, csf_);
    }
  };
}
