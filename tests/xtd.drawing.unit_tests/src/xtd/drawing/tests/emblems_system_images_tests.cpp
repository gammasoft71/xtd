#include <xtd/drawing/emblems_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(emblems_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = emblems_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(emblem_default) {
      auto i = emblems_system_images::emblem_default();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-default"), i, csf_);
    }

    void test_method_(emblem_default_with_specified_size) {
      auto i = emblems_system_images::emblem_default({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-default", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_documents) {
      auto i = emblems_system_images::emblem_documents();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-documents"), i, csf_);
    }

    void test_method_(emblem_documents_with_specified_size) {
      auto i = emblems_system_images::emblem_documents({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-documents", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_downloads) {
      auto i = emblems_system_images::emblem_downloads();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-downloads"), i, csf_);
    }

    void test_method_(emblem_downloads_with_specified_size) {
      auto i = emblems_system_images::emblem_downloads({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-downloads", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_favorite) {
      auto i = emblems_system_images::emblem_favorite();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-favorite"), i, csf_);
    }

    void test_method_(emblem_favorite_with_specified_size) {
      auto i = emblems_system_images::emblem_favorite({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-favorite", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_important) {
      auto i = emblems_system_images::emblem_important();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-important"), i, csf_);
    }

    void test_method_(emblem_important_with_specified_size) {
      auto i = emblems_system_images::emblem_important({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-important", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_locked) {
      auto i = emblems_system_images::emblem_locked();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-locked"), i, csf_);
    }

    void test_method_(emblem_locked_with_specified_size) {
      auto i = emblems_system_images::emblem_locked({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-locked", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_mail) {
      auto i = emblems_system_images::emblem_mail();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-mail"), i, csf_);
    }

    void test_method_(emblem_mail_with_specified_size) {
      auto i = emblems_system_images::emblem_mail({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-mail", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_new) {
      auto i = emblems_system_images::emblem_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-new"), i, csf_);
    }

    void test_method_(emblem_new_with_specified_size) {
      auto i = emblems_system_images::emblem_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-new", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_photos) {
      auto i = emblems_system_images::emblem_photos();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-photos"), i, csf_);
    }

    void test_method_(emblem_photos_with_specified_size) {
      auto i = emblems_system_images::emblem_photos({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-photos", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_readonly) {
      auto i = emblems_system_images::emblem_readonly();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-readonly"), i, csf_);
    }

    void test_method_(emblem_readonly_with_specified_size) {
      auto i = emblems_system_images::emblem_readonly({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-readonly", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_shared) {
      auto i = emblems_system_images::emblem_shared();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-shared"), i, csf_);
    }

    void test_method_(emblem_shared_with_specified_size) {
      auto i = emblems_system_images::emblem_shared({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-shared", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_symbolic_link) {
      auto i = emblems_system_images::emblem_symbolic_link();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-symbolic-link"), i, csf_);
    }

    void test_method_(emblem_symbolic_link_with_specified_size) {
      auto i = emblems_system_images::emblem_symbolic_link({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-symbolic-link", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_synchronizing) {
      auto i = emblems_system_images::emblem_synchronizing();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-synchronizing"), i, csf_);
    }

    void test_method_(emblem_synchronizing_with_specified_size) {
      auto i = emblems_system_images::emblem_synchronizing({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-synchronizing", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_system) {
      auto i = emblems_system_images::emblem_system();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-system"), i, csf_);
    }

    void test_method_(emblem_system_with_specified_size) {
      auto i = emblems_system_images::emblem_system({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-system", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_unlocked) {
      auto i = emblems_system_images::emblem_unlocked();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-unlocked"), i, csf_);
    }

    void test_method_(emblem_unlocked_with_specified_size) {
      auto i = emblems_system_images::emblem_unlocked({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-unlocked", size {64, 64}), i, csf_);
    }

    void test_method_(emblem_unreadable) {
      auto i = emblems_system_images::emblem_unreadable();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-unreadable"), i, csf_);
    }

    void test_method_(emblem_unreadable_with_specified_size) {
      auto i = emblems_system_images::emblem_unreadable({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("emblem-unreadable", size {64, 64}), i, csf_);
    }
  };
}
