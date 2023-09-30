#include "../../../include/xtd/drawing/status_system_images.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

drawing::size status_system_images::default_size() noexcept {
  return system_images_base::default_size();
}

image status_system_images::appointment_missed() noexcept {
  return appointment_missed(default_size());
}

image status_system_images::appointment_missed(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("appointment-missed", size);
}

image status_system_images::appointment_soon() noexcept {
  return appointment_soon(default_size());
}

image status_system_images::appointment_soon(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("appointment-soon", size);
}

image status_system_images::audio_volume_high() noexcept {
  return audio_volume_high(default_size());
}

image status_system_images::audio_volume_high(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-volume-high", size);
}

image status_system_images::audio_volume_low() noexcept {
  return audio_volume_low(default_size());
}

image status_system_images::audio_volume_low(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-volume-low", size);
}

image status_system_images::audio_volume_medium() noexcept {
  return audio_volume_medium(default_size());
}

image status_system_images::audio_volume_medium(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-volume-medium", size);
}

image status_system_images::audio_volume_muted() noexcept {
  return audio_volume_muted(default_size());
}

image status_system_images::audio_volume_muted(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("audio-volume-muted", size);
}

image status_system_images::battery_caution() noexcept {
  return battery_caution(default_size());
}

image status_system_images::battery_caution(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("battery-caution", size);
}

image status_system_images::battery_low() noexcept {
  return battery_low(default_size());
}

image status_system_images::battery_low(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("battery-low", size);
}

image status_system_images::dialog_error() noexcept {
  return dialog_error(default_size());
}

image status_system_images::dialog_error(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("dialog-error", size);
}

image status_system_images::dialog_information() noexcept {
  return dialog_information(default_size());
}

image status_system_images::dialog_information(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("dialog-information", size);
}

image status_system_images::dialog_password() noexcept {
  return dialog_password(default_size());
}

image status_system_images::dialog_password(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("dialog-password", size);
}

image status_system_images::dialog_question() noexcept {
  return dialog_question(default_size());
}

image status_system_images::dialog_question(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("dialog-question", size);
}

image status_system_images::dialog_warning() noexcept {
  return dialog_warning(default_size());
}

image status_system_images::dialog_warning(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("dialog-warning", size);
}

image status_system_images::folder_drag_accept() noexcept {
  return folder_drag_accept(default_size());
}

image status_system_images::folder_drag_accept(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("folder-drag-accept", size);
}

image status_system_images::folder_open() noexcept {
  return folder_open(default_size());
}

image status_system_images::folder_open(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("folder-open", size);
}

image status_system_images::folder_visiting() noexcept {
  return folder_visiting(default_size());
}

image status_system_images::folder_visiting(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("folder-visiting", size);
}

image status_system_images::image_loading() noexcept {
  return image_loading(default_size());
}

image status_system_images::image_loading(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("image-loading", size);
}

image status_system_images::image_missing() noexcept {
  return image_missing(default_size());
}

image status_system_images::image_missing(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("image-missing", size);
}

image status_system_images::mail_attachment() noexcept {
  return mail_attachment(default_size());
}

image status_system_images::mail_attachment(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-attachment", size);
}

image status_system_images::mail_unread() noexcept {
  return mail_unread(default_size());
}

image status_system_images::mail_unread(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-unread", size);
}

image status_system_images::mail_read() noexcept {
  return mail_read(default_size());
}

image status_system_images::mail_read(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-read", size);
}

image status_system_images::mail_replied() noexcept {
  return mail_replied(default_size());
}

image status_system_images::mail_replied(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-replied", size);
}

image status_system_images::mail_signed() noexcept {
  return mail_signed(default_size());
}

image status_system_images::mail_signed(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-signed", size);
}

image status_system_images::mail_signed_verified() noexcept {
  return mail_signed_verified(default_size());
}

image status_system_images::mail_signed_verified(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("mail-signed-verified", size);
}

image status_system_images::media_playlist_repeat() noexcept {
  return media_playlist_repeat(default_size());
}

image status_system_images::media_playlist_repeat(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-playlist-repeat", size);
}

image status_system_images::media_playlist_shuffle() noexcept {
  return media_playlist_shuffle(default_size());
}

image status_system_images::media_playlist_shuffle(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("media-playlist-shuffle", size);
}

image status_system_images::network_error() noexcept {
  return network_error(default_size());
}

image status_system_images::network_error(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-error", size);
}

image status_system_images::network_idle() noexcept {
  return network_idle(default_size());
}

image status_system_images::network_idle(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-idle", size);
}

image status_system_images::network_offline() noexcept {
  return network_offline(default_size());
}

image status_system_images::network_offline(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-offline", size);
}

image status_system_images::network_receive() noexcept {
  return network_receive(default_size());
}

image status_system_images::network_receive(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-receive", size);
}

image status_system_images::network_transmit() noexcept {
  return network_transmit(default_size());
}

image status_system_images::network_transmit(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-transmit", size);
}

image status_system_images::network_transmit_receive() noexcept {
  return network_transmit_receive(default_size());
}

image status_system_images::network_transmit_receive(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("network-transmit-receive", size);
}

image status_system_images::printer_error() noexcept {
  return printer_error(default_size());
}

image status_system_images::printer_error(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("printer-error", size);
}

image status_system_images::printer_printing() noexcept {
  return printer_printing(default_size());
}

image status_system_images::printer_printing(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("printer-printing", size);
}

image status_system_images::security_high() noexcept {
  return security_high(default_size());
}

image status_system_images::security_high(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("security-high", size);
}

image status_system_images::security_medium() noexcept {
  return security_medium(default_size());
}

image status_system_images::security_medium(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("security-medium", size);
}

image status_system_images::security_low() noexcept {
  return security_low(default_size());
}

image status_system_images::security_low(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("security-low", size);
}

image status_system_images::software_update_available() noexcept {
  return software_update_available(default_size());
}

image status_system_images::software_update_available(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("software-update-available", size);
}

image status_system_images::software_update_urgent() noexcept {
  return software_update_urgent(default_size());
}

image status_system_images::software_update_urgent(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("software-update-urgent", size);
}

image status_system_images::task_due() noexcept {
  return task_due(default_size());
}

image status_system_images::task_due(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("task-due", size);
}

image status_system_images::task_past_due() noexcept {
  return task_past_due(default_size());
}

image status_system_images::task_past_due(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("task-past-due", size);
}

image status_system_images::user_available() noexcept {
  return user_available(default_size());
}

image status_system_images::user_available(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("user-available", size);
}

image status_system_images::user_away() noexcept {
  return user_away(default_size());
}

image status_system_images::user_away(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("user-away", size);
}

image status_system_images::user_idle() noexcept {
  return user_idle(default_size());
}

image status_system_images::user_idle(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("user-idle", size);
}

image status_system_images::user_offline() noexcept {
  return user_offline(default_size());
}

image status_system_images::user_offline(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("user-offline", size);
}

image status_system_images::user_trash_full() noexcept {
  return user_trash_full(default_size());
}

image status_system_images::user_trash_full(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("user-trash-full", size);
}

image status_system_images::weather_clear() noexcept {
  return weather_clear(default_size());
}

image status_system_images::weather_clear(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-clear", size);
}

image status_system_images::weather_clear_night() noexcept {
  return weather_clear_night(default_size());
}

image status_system_images::weather_clear_night(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-clear-night", size);
}

image status_system_images::weather_few_clouds() noexcept {
  return weather_few_clouds(default_size());
}

image status_system_images::weather_few_clouds(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-few-clouds", size);
}

image status_system_images::weather_few_clouds_night() noexcept {
  return weather_few_clouds_night(default_size());
}

image status_system_images::weather_few_clouds_night(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-few-clouds-night", size);
}

image status_system_images::weather_fog() noexcept {
  return weather_fog(default_size());
}

image status_system_images::weather_fog(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-fog", size);
}

image status_system_images::weather_overcast() noexcept {
  return weather_overcast(default_size());
}

image status_system_images::weather_overcast(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-overcast", size);
}

image status_system_images::weather_severe_alert() noexcept {
  return weather_severe_alert(default_size());
}

image status_system_images::weather_severe_alert(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-severe-alert", size);
}

image status_system_images::weather_showers() noexcept {
  return weather_showers(default_size());
}

image status_system_images::weather_showers(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-showers", size);
}

image status_system_images::weather_showers_scattered() noexcept {
  return weather_showers_scattered(default_size());
}

image status_system_images::weather_showers_scattered(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-showers-scattered", size);
}

image status_system_images::weather_snow() noexcept {
  return weather_snow(default_size());
}

image status_system_images::weather_snow(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-snow", size);
}

image status_system_images::weather_storm() noexcept {
  return weather_storm(default_size());
}

image status_system_images::weather_storm(const xtd::drawing::size& size) noexcept {
  return system_images_base::from_name("weather-storm", size);
}

const vector<image>& status_system_images::get_images() noexcept {
  static auto images = get_images(default_size());
  return images;
}

vector<image> status_system_images::get_images(const xtd::drawing::size& size) noexcept {
  return vector {appointment_missed(size), appointment_soon(size), audio_volume_high(size), audio_volume_low(size), audio_volume_medium(size), audio_volume_muted(size), battery_caution(size), battery_low(size), dialog_error(size), dialog_information(size), dialog_password(size), dialog_question(size), dialog_warning(size), folder_drag_accept(size), folder_open(size), folder_visiting(size), image_loading(size), image_missing(size), mail_attachment(size), mail_unread(size), mail_read(size), mail_replied(size), mail_signed(size), mail_signed_verified(size), media_playlist_repeat(size), media_playlist_shuffle(size), network_error(size), network_idle(size), network_offline(size), network_receive(size), network_transmit(size), network_transmit_receive(size), printer_error(size), printer_printing(size), security_high(size), security_medium(size), security_low(size), software_update_available(size), software_update_urgent(size), task_due(size), task_past_due(size), user_available(size), user_away(size), user_idle(size), user_offline(size), user_trash_full(size), weather_clear(size), weather_clear_night(size), weather_few_clouds(size), weather_few_clouds_night(size), weather_fog(size), weather_overcast(size), weather_severe_alert(size), weather_showers(size), weather_showers_scattered(size), weather_snow(size), weather_storm(size), };
}

const vector<ustring>& status_system_images::get_image_names() noexcept {
  static auto names = vector {"appointment-missed"_s, "appointment-soon"_s, "audio-volume-high"_s, "audio-volume-low"_s, "audio-volume-medium"_s, "audio-volume-muted"_s, "battery-caution"_s, "battery-low"_s, "dialog-error"_s, "dialog-information"_s, "dialog-password"_s, "dialog-question"_s, "dialog-warning"_s, "folder-drag-accept"_s, "folder-open"_s, "folder-visiting"_s, "image-loading"_s, "image-missing"_s, "mail-attachment"_s, "mail-unread"_s, "mail-read"_s, "mail-replied"_s, "mail-signed"_s, "mail-signed-verified"_s, "media-playlist-repeat"_s, "media-playlist-shuffle"_s, "network-error"_s, "network-idle"_s, "network-offline"_s, "network-receive"_s, "network-transmit"_s, "network-transmit-receive"_s, "printer-error"_s, "printer-printing"_s, "security-high"_s, "security-medium"_s, "security-low"_s, "software-update-available"_s, "software-update-urgent"_s, "task-due"_s, "task-past-due"_s, "user-available"_s, "user-away"_s, "user-idle"_s, "user-offline"_s, "user-trash-full"_s, "weather-clear"_s, "weather-clear-night"_s, "weather-few-clouds"_s, "weather-few-clouds-night"_s, "weather-fog"_s, "weather-overcast"_s, "weather-severe-alert"_s, "weather-showers"_s, "weather-showers-scattered"_s, "weather-snow"_s, "weather-storm"_s, };
  return names;
}
