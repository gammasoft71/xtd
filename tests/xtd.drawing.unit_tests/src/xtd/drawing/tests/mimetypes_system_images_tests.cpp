#include <xtd/drawing/mimetypes_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(mimetypes_system_images_tests) {
    void test_method_(default_size) {
      auto s = mimetypes_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(application_x_executable) {
      auto i = mimetypes_system_images::application_x_executable();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("application-x-executable"), i, csf_);
    }

    void test_method_(application_x_executable_with_specified_size) {
      auto i = mimetypes_system_images::application_x_executable({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("application-x-executable", size {64, 64}), i, csf_);
    }

    void test_method_(audio_x_generic) {
      auto i = mimetypes_system_images::audio_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-x-generic"), i, csf_);
    }

    void test_method_(audio_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::audio_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(font_x_generic) {
      auto i = mimetypes_system_images::font_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("font-x-generic"), i, csf_);
    }

    void test_method_(font_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::font_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("font-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(image_x_generic) {
      auto i = mimetypes_system_images::image_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-x-generic"), i, csf_);
    }

    void test_method_(image_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::image_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(package_x_generic) {
      auto i = mimetypes_system_images::package_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("package-x-generic"), i, csf_);
    }

    void test_method_(package_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::package_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("package-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(text_html) {
      auto i = mimetypes_system_images::text_html();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-html"), i, csf_);
    }

    void test_method_(text_html_with_specified_size) {
      auto i = mimetypes_system_images::text_html({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-html", size {64, 64}), i, csf_);
    }

    void test_method_(text_x_generic) {
      auto i = mimetypes_system_images::text_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-generic"), i, csf_);
    }

    void test_method_(text_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::text_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(text_x_generic_template) {
      auto i = mimetypes_system_images::text_x_generic_template();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-generic-template"), i, csf_);
    }

    void test_method_(text_x_generic_template_with_specified_size) {
      auto i = mimetypes_system_images::text_x_generic_template({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-generic-template", size {64, 64}), i, csf_);
    }

    void test_method_(text_x_script) {
      auto i = mimetypes_system_images::text_x_script();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-script"), i, csf_);
    }

    void test_method_(text_x_script_with_specified_size) {
      auto i = mimetypes_system_images::text_x_script({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("text-x-script", size {64, 64}), i, csf_);
    }

    void test_method_(video_x_generic) {
      auto i = mimetypes_system_images::video_x_generic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("video-x-generic"), i, csf_);
    }

    void test_method_(video_x_generic_with_specified_size) {
      auto i = mimetypes_system_images::video_x_generic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("video-x-generic", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_address_book) {
      auto i = mimetypes_system_images::x_office_address_book();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-address-book"), i, csf_);
    }

    void test_method_(x_office_address_book_with_specified_size) {
      auto i = mimetypes_system_images::x_office_address_book({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-address-book", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_calendar) {
      auto i = mimetypes_system_images::x_office_calendar();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-calendar"), i, csf_);
    }

    void test_method_(x_office_calendar_with_specified_size) {
      auto i = mimetypes_system_images::x_office_calendar({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-calendar", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_contact) {
      auto i = mimetypes_system_images::x_office_contact();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-contact"), i, csf_);
    }

    void test_method_(x_office_contact_with_specified_size) {
      auto i = mimetypes_system_images::x_office_contact({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-contact", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_document) {
      auto i = mimetypes_system_images::x_office_document();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-document"), i, csf_);
    }

    void test_method_(x_office_document_with_specified_size) {
      auto i = mimetypes_system_images::x_office_document({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-document", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_presentation) {
      auto i = mimetypes_system_images::x_office_presentation();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-presentation"), i, csf_);
    }

    void test_method_(x_office_presentation_with_specified_size) {
      auto i = mimetypes_system_images::x_office_presentation({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-presentation", size {64, 64}), i, csf_);
    }

    void test_method_(x_office_spreadsheet) {
      auto i = mimetypes_system_images::x_office_spreadsheet();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-spreadsheet"), i, csf_);
    }

    void test_method_(x_office_spreadsheet_with_specified_size) {
      auto i = mimetypes_system_images::x_office_spreadsheet({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("x-office-spreadsheet", size {64, 64}), i, csf_);
    }
  };
}
