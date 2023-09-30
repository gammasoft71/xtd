#include "../../../include/xtd/drawing/devices_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size devices_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image devices_system_images::audio_card() noexcept {
  return audio_card(default_size());
}

image devices_system_images::audio_card(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-card", size);
}

image devices_system_images::audio_input_microphone() noexcept {
  return audio_input_microphone(default_size());
}

image devices_system_images::audio_input_microphone(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-input-microphone", size);
}

image devices_system_images::battery() noexcept {
  return battery(default_size());
}

image devices_system_images::battery(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("battery", size);
}

image devices_system_images::camera_photo() noexcept {
  return camera_photo(default_size());
}

image devices_system_images::camera_photo(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("camera-photo", size);
}

image devices_system_images::camera_video() noexcept {
  return camera_video(default_size());
}

image devices_system_images::camera_video(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("camera-video", size);
}

image devices_system_images::camera_web() noexcept {
  return camera_web(default_size());
}

image devices_system_images::camera_web(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("camera-web", size);
}

image devices_system_images::computer() noexcept {
  return computer(default_size());
}

image devices_system_images::computer(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("computer", size);
}

image devices_system_images::drive_harddisk() noexcept {
  return drive_harddisk(default_size());
}

image devices_system_images::drive_harddisk(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("drive-harddisk", size);
}

image devices_system_images::drive_optical() noexcept {
  return drive_optical(default_size());
}

image devices_system_images::drive_optical(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("drive-optical", size);
}

image devices_system_images::drive_removable_media_usb_pendrive() noexcept {
  return drive_removable_media_usb_pendrive(default_size());
}

image devices_system_images::drive_removable_media_usb_pendrive(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("drive-removable-media-usb-pendrive", size);
}

image devices_system_images::drive_removable_media() noexcept {
  return drive_removable_media(default_size());
}

image devices_system_images::drive_removable_media(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("drive-removable-media", size);
}

image devices_system_images::input_gaming() noexcept {
  return input_gaming(default_size());
}

image devices_system_images::input_gaming(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("input-gaming", size);
}

image devices_system_images::input_keyboard() noexcept {
  return input_keyboard(default_size());
}

image devices_system_images::input_keyboard(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("input-keyboard", size);
}

image devices_system_images::input_mouse() noexcept {
  return input_mouse(default_size());
}

image devices_system_images::input_mouse(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("input-mouse", size);
}

image devices_system_images::input_tablet() noexcept {
  return input_tablet(default_size());
}

image devices_system_images::input_tablet(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("input-tablet", size);
}

image devices_system_images::media_flash() noexcept {
  return media_flash(default_size());
}

image devices_system_images::media_flash(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-flash", size);
}

image devices_system_images::media_floppy() noexcept {
  return media_floppy(default_size());
}

image devices_system_images::media_floppy(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-floppy", size);
}

image devices_system_images::media_optical_audio() noexcept {
  return media_optical_audio(default_size());
}

image devices_system_images::media_optical_audio(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-audio", size);
}

image devices_system_images::media_optical_blu_ray() noexcept {
  return media_optical_blu_ray(default_size());
}

image devices_system_images::media_optical_blu_ray(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-blu-ray", size);
}

image devices_system_images::media_optical_data() noexcept {
  return media_optical_data(default_size());
}

image devices_system_images::media_optical_data(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-data", size);
}

image devices_system_images::media_optical_dvd_video() noexcept {
  return media_optical_dvd_video(default_size());
}

image devices_system_images::media_optical_dvd_video(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-dvd-video", size);
}

image devices_system_images::media_optical_dvd() noexcept {
  return media_optical_dvd(default_size());
}

image devices_system_images::media_optical_dvd(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-dvd", size);
}

image devices_system_images::media_optical_mixed_cd() noexcept {
  return media_optical_mixed_cd(default_size());
}

image devices_system_images::media_optical_mixed_cd(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-mixed-cd", size);
}

image devices_system_images::media_optical_recordable() noexcept {
  return media_optical_recordable(default_size());
}

image devices_system_images::media_optical_recordable(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-recordable", size);
}

image devices_system_images::media_optical_video() noexcept {
  return media_optical_video(default_size());
}

image devices_system_images::media_optical_video(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical-video", size);
}

image devices_system_images::media_optical() noexcept {
  return media_optical(default_size());
}

image devices_system_images::media_optical(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-optical", size);
}

image devices_system_images::media_tape() noexcept {
  return media_tape(default_size());
}

image devices_system_images::media_tape(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-tape", size);
}

image devices_system_images::modem() noexcept {
  return modem(default_size());
}

image devices_system_images::modem(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("modem", size);
}

image devices_system_images::multimedia_player() noexcept {
  return multimedia_player(default_size());
}

image devices_system_images::multimedia_player(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("multimedia-player", size);
}

image devices_system_images::network_wired() noexcept {
  return network_wired(default_size());
}

image devices_system_images::network_wired(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-wired", size);
}

image devices_system_images::network_wireless() noexcept {
  return network_wireless(default_size());
}

image devices_system_images::network_wireless(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-wireless", size);
}

image devices_system_images::pda() noexcept {
  return pda(default_size());
}

image devices_system_images::pda(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("pda", size);
}

image devices_system_images::phone() noexcept {
  return phone(default_size());
}

image devices_system_images::phone(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("phone", size);
}

image devices_system_images::printer() noexcept {
  return printer(default_size());
}

image devices_system_images::printer(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("printer", size);
}

image devices_system_images::scanner() noexcept {
  return scanner(default_size());
}

image devices_system_images::scanner(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("scanner", size);
}

image devices_system_images::video_display() noexcept {
  return video_display(default_size());
}

image devices_system_images::video_display(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("video-display", size);
}

const vector<image>& devices_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> devices_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {audio_card(size), audio_input_microphone(size), battery(size), camera_photo(size), camera_video(size), camera_web(size), computer(size), drive_harddisk(size), drive_optical(size), drive_removable_media_usb_pendrive(size), drive_removable_media(size), input_gaming(size), input_keyboard(size), input_mouse(size), input_tablet(size), media_flash(size), media_floppy(size), media_optical_audio(size), media_optical_blu_ray(size), media_optical_data(size), media_optical_dvd_video(size), media_optical_dvd(size), media_optical_mixed_cd(size), media_optical_recordable(size), media_optical_video(size), media_optical(size), media_tape(size), modem(size), multimedia_player(size), network_wired(size), network_wireless(size), pda(size), phone(size), printer(size), scanner(size), video_display(size), };
}

const vector<ustring>& devices_system_images::get_image_names() noexcept {
  static auto names = vector {"audio-card"_s, "audio-input-microphone"_s, "battery"_s, "camera-photo"_s, "camera-video"_s, "camera-web"_s, "computer"_s, "drive-harddisk"_s, "drive-optical"_s, "drive-removable-media-usb-pendrive"_s, "drive-removable-media"_s, "input-gaming"_s, "input-keyboard"_s, "input-mouse"_s, "input-tablet"_s, "media-flash"_s, "media-floppy"_s, "media-optical-audio"_s, "media-optical-blu-ray"_s, "media-optical-data"_s, "media-optical-dvd-video"_s, "media-optical-dvd"_s, "media-optical-mixed-cd"_s, "media-optical-recordable"_s, "media-optical-video"_s, "media-optical"_s, "media-tape"_s, "modem"_s, "multimedia-player"_s, "network-wired"_s, "network-wireless"_s, "pda"_s, "phone"_s, "printer"_s, "scanner"_s, "video-display"_s, };
  return names;
}
