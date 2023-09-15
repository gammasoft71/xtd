#include <xtd/drawing/categories_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(categories_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = categories_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(applications_accessories) {
      auto i = categories_system_images::applications_accessories();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-accessories"), i, csf_);
    }

    void test_method_(applications_accessories_with_specified_size) {
      auto i = categories_system_images::applications_accessories({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-accessories", size {64, 64}), i, csf_);
    }

    void test_method_(applications_development) {
      auto i = categories_system_images::applications_development();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-development"), i, csf_);
    }

    void test_method_(applications_development_with_specified_size) {
      auto i = categories_system_images::applications_development({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-development", size {64, 64}), i, csf_);
    }

    void test_method_(applications_engineering) {
      auto i = categories_system_images::applications_engineering();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-engineering"), i, csf_);
    }

    void test_method_(applications_engineering_with_specified_size) {
      auto i = categories_system_images::applications_engineering({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-engineering", size {64, 64}), i, csf_);
    }

    void test_method_(applications_games) {
      auto i = categories_system_images::applications_games();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-games"), i, csf_);
    }

    void test_method_(applications_games_with_specified_size) {
      auto i = categories_system_images::applications_games({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-games", size {64, 64}), i, csf_);
    }

    void test_method_(applications_graphics) {
      auto i = categories_system_images::applications_graphics();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-graphics"), i, csf_);
    }

    void test_method_(applications_graphics_with_specified_size) {
      auto i = categories_system_images::applications_graphics({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-graphics", size {64, 64}), i, csf_);
    }

    void test_method_(applications_internet) {
      auto i = categories_system_images::applications_internet();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-internet"), i, csf_);
    }

    void test_method_(applications_internet_with_specified_size) {
      auto i = categories_system_images::applications_internet({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-internet", size {64, 64}), i, csf_);
    }

    void test_method_(applications_multimedia) {
      auto i = categories_system_images::applications_multimedia();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-multimedia"), i, csf_);
    }

    void test_method_(applications_multimedia_with_specified_size) {
      auto i = categories_system_images::applications_multimedia({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-multimedia", size {64, 64}), i, csf_);
    }

    void test_method_(applications_office) {
      auto i = categories_system_images::applications_office();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-office"), i, csf_);
    }

    void test_method_(applications_office_with_specified_size) {
      auto i = categories_system_images::applications_office({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-office", size {64, 64}), i, csf_);
    }

    void test_method_(applications_other) {
      auto i = categories_system_images::applications_other();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-other"), i, csf_);
    }

    void test_method_(applications_other_with_specified_size) {
      auto i = categories_system_images::applications_other({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-other", size {64, 64}), i, csf_);
    }

    void test_method_(applications_science) {
      auto i = categories_system_images::applications_science();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-science"), i, csf_);
    }

    void test_method_(applications_science_with_specified_size) {
      auto i = categories_system_images::applications_science({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-science", size {64, 64}), i, csf_);
    }

    void test_method_(applications_system) {
      auto i = categories_system_images::applications_system();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-system"), i, csf_);
    }

    void test_method_(applications_system_with_specified_size) {
      auto i = categories_system_images::applications_system({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-system", size {64, 64}), i, csf_);
    }

    void test_method_(applications_utilities) {
      auto i = categories_system_images::applications_utilities();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-utilities"), i, csf_);
    }

    void test_method_(applications_utilities_with_specified_size) {
      auto i = categories_system_images::applications_utilities({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("applications-utilities", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop) {
      auto i = categories_system_images::preferences_desktop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop"), i, csf_);
    }

    void test_method_(preferences_desktop_with_specified_size) {
      auto i = categories_system_images::preferences_desktop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_peripherals) {
      auto i = categories_system_images::preferences_desktop_peripherals();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-peripherals"), i, csf_);
    }

    void test_method_(preferences_desktop_peripherals_with_specified_size) {
      auto i = categories_system_images::preferences_desktop_peripherals({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-peripherals", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_desktop_personal) {
      auto i = categories_system_images::preferences_desktop_personal();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-personal"), i, csf_);
    }

    void test_method_(preferences_desktop_personal_with_specified_size) {
      auto i = categories_system_images::preferences_desktop_personal({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-desktop-personal", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_other) {
      auto i = categories_system_images::preferences_other();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-other"), i, csf_);
    }

    void test_method_(preferences_other_with_specified_size) {
      auto i = categories_system_images::preferences_other({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-other", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_system) {
      auto i = categories_system_images::preferences_system();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-system"), i, csf_);
    }

    void test_method_(preferences_system_with_specified_size) {
      auto i = categories_system_images::preferences_system({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-system", size {64, 64}), i, csf_);
    }

    void test_method_(preferences_system_network) {
      auto i = categories_system_images::preferences_system_network();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-system-network"), i, csf_);
    }

    void test_method_(preferences_system_network_with_specified_size) {
      auto i = categories_system_images::preferences_system_network({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("preferences-system-network", size {64, 64}), i, csf_);
    }

    void test_method_(system_help) {
      auto i = categories_system_images::system_help();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-help"), i, csf_);
    }

    void test_method_(system_help_with_specified_size) {
      auto i = categories_system_images::system_help({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-help", size {64, 64}), i, csf_);
    }
  };
}
