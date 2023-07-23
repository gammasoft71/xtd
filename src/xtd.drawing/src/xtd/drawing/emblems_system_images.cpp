#include "../../../include/xtd/drawing/emblems_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size emblems_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image emblems_system_images::emblem_default() noexcept {
  return emblem_default(default_size());
}

image emblems_system_images::emblem_default(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-default", size);
}

image emblems_system_images::emblem_documents() noexcept {
  return emblem_documents(default_size());
}

image emblems_system_images::emblem_documents(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-documents", size);
}

image emblems_system_images::emblem_downloads() noexcept {
  return emblem_downloads(default_size());
}

image emblems_system_images::emblem_downloads(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-downloads", size);
}

image emblems_system_images::emblem_favorite() noexcept {
  return emblem_favorite(default_size());
}

image emblems_system_images::emblem_favorite(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-favorite", size);
}

image emblems_system_images::emblem_important() noexcept {
  return emblem_important(default_size());
}

image emblems_system_images::emblem_important(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-important", size);
}

image emblems_system_images::emblem_locked() noexcept {
  return emblem_locked(default_size());
}

image emblems_system_images::emblem_locked(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-locked", size);
}

image emblems_system_images::emblem_mail() noexcept {
  return emblem_mail(default_size());
}

image emblems_system_images::emblem_mail(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-mail", size);
}

image emblems_system_images::emblem_new() noexcept {
  return emblem_new(default_size());
}

image emblems_system_images::emblem_new(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-new", size);
}

image emblems_system_images::emblem_photos() noexcept {
  return emblem_photos(default_size());
}

image emblems_system_images::emblem_photos(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-photos", size);
}

image emblems_system_images::emblem_readonly() noexcept {
  return emblem_readonly(default_size());
}

image emblems_system_images::emblem_readonly(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-readonly", size);
}

image emblems_system_images::emblem_shared() noexcept {
  return emblem_shared(default_size());
}

image emblems_system_images::emblem_shared(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-shared", size);
}

image emblems_system_images::emblem_symbolic_link() noexcept {
  return emblem_symbolic_link(default_size());
}

image emblems_system_images::emblem_symbolic_link(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-symbolic-link", size);
}

image emblems_system_images::emblem_synchronizing() noexcept {
  return emblem_synchronizing(default_size());
}

image emblems_system_images::emblem_synchronizing(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-synchronizing", size);
}

image emblems_system_images::emblem_system() noexcept {
  return emblem_system(default_size());
}

image emblems_system_images::emblem_system(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-system", size);
}

image emblems_system_images::emblem_unlocked() noexcept {
  return emblem_unlocked(default_size());
}

image emblems_system_images::emblem_unlocked(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-unlocked", size);
}

image emblems_system_images::emblem_unreadable() noexcept {
  return emblem_unreadable(default_size());
}

image emblems_system_images::emblem_unreadable(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("emblem-unreadable", size);
}

const vector<image>& emblems_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> emblems_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {emblem_default(size), emblem_documents(size), emblem_downloads(size), emblem_favorite(size), emblem_important(size), emblem_locked(size), emblem_mail(size), emblem_new(size), emblem_photos(size), emblem_readonly(size), emblem_shared(size), emblem_symbolic_link(size), emblem_synchronizing(size), emblem_system(size), emblem_unlocked(size), emblem_unreadable(size), };
}

const vector<ustring>& emblems_system_images::get_image_names() noexcept {
  static auto names = vector {"emblem-default"_s, "emblem-documents"_s, "emblem-downloads"_s, "emblem-favorite"_s, "emblem-important"_s, "emblem-locked"_s, "emblem-mail"_s, "emblem-new"_s, "emblem-photos"_s, "emblem-readonly"_s, "emblem-shared"_s, "emblem-symbolic-link"_s, "emblem-synchronizing"_s, "emblem-system"_s, "emblem-unlocked"_s, "emblem-unreadable"_s, };
  return names;
}
