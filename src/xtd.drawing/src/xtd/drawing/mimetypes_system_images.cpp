#include "../../../include/xtd/drawing/mimetypes_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size mimetypes_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image mimetypes_system_images::application_x_executable() noexcept {
  return application_x_executable(default_size());
}

image mimetypes_system_images::application_x_executable(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("application-x-executable", size);
}

image mimetypes_system_images::audio_x_generic() noexcept {
  return audio_x_generic(default_size());
}

image mimetypes_system_images::audio_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-x-generic", size);
}

image mimetypes_system_images::font_x_generic() noexcept {
  return font_x_generic(default_size());
}

image mimetypes_system_images::font_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("font-x-generic", size);
}

image mimetypes_system_images::image_x_generic() noexcept {
  return image_x_generic(default_size());
}

image mimetypes_system_images::image_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("image-x-generic", size);
}

image mimetypes_system_images::package_x_generic() noexcept {
  return package_x_generic(default_size());
}

image mimetypes_system_images::package_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("package-x-generic", size);
}

image mimetypes_system_images::text_html() noexcept {
  return text_html(default_size());
}

image mimetypes_system_images::text_html(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("text-html", size);
}

image mimetypes_system_images::text_x_generic() noexcept {
  return text_x_generic(default_size());
}

image mimetypes_system_images::text_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("text-x-generic", size);
}

image mimetypes_system_images::text_x_generic_template() noexcept {
  return text_x_generic_template(default_size());
}

image mimetypes_system_images::text_x_generic_template(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("text-x-generic-template", size);
}

image mimetypes_system_images::text_x_script() noexcept {
  return text_x_script(default_size());
}

image mimetypes_system_images::text_x_script(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("text-x-script", size);
}

image mimetypes_system_images::video_x_generic() noexcept {
  return video_x_generic(default_size());
}

image mimetypes_system_images::video_x_generic(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("video-x-generic", size);
}

image mimetypes_system_images::x_office_address_book() noexcept {
  return x_office_address_book(default_size());
}

image mimetypes_system_images::x_office_address_book(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-address-book", size);
}

image mimetypes_system_images::x_office_calendar() noexcept {
  return x_office_calendar(default_size());
}

image mimetypes_system_images::x_office_calendar(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-calendar", size);
}

image mimetypes_system_images::x_office_contact() noexcept {
  return x_office_contact(default_size());
}

image mimetypes_system_images::x_office_contact(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-contact", size);
}

image mimetypes_system_images::x_office_document() noexcept {
  return x_office_document(default_size());
}

image mimetypes_system_images::x_office_document(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-document", size);
}

image mimetypes_system_images::x_office_presentation() noexcept {
  return x_office_presentation(default_size());
}

image mimetypes_system_images::x_office_presentation(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-presentation", size);
}

image mimetypes_system_images::x_office_spreadsheet() noexcept {
  return x_office_spreadsheet(default_size());
}

image mimetypes_system_images::x_office_spreadsheet(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("x-office-spreadsheet", size);
}

const vector<image>& mimetypes_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> mimetypes_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {application_x_executable(size), audio_x_generic(size), font_x_generic(size), image_x_generic(size), package_x_generic(size), text_html(size), text_x_generic(size), text_x_generic_template(size), text_x_script(size), video_x_generic(size), x_office_address_book(size), x_office_calendar(size), x_office_contact(size), x_office_document(size), x_office_presentation(size), x_office_spreadsheet(size), };
}

const vector<ustring>& mimetypes_system_images::get_image_names() noexcept {
  static auto names = vector {"application-x-executable"_s, "audio-x-generic"_s, "font-x-generic"_s, "image-x-generic"_s, "package-x-generic"_s, "text-html"_s, "text-x-generic"_s, "text-x-generic-template"_s, "text-x-script"_s, "video-x-generic"_s, "x-office-address-book"_s, "x-office-calendar"_s, "x-office-contact"_s, "x-office-document"_s, "x-office-presentation"_s, "x-office-spreadsheet"_s, };
  return names;
}
