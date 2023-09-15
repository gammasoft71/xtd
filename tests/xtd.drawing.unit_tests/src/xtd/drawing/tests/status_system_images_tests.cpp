#include <xtd/drawing/status_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(status_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = status_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(appointment_missed) {
      auto i = status_system_images::appointment_missed();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-missed"), i, csf_);
    }

    void test_method_(appointment_missed_with_specified_size) {
      auto i = status_system_images::appointment_missed({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-missed", size {64, 64}), i, csf_);
    }

    void test_method_(appointment_soon) {
      auto i = status_system_images::appointment_soon();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-soon"), i, csf_);
    }

    void test_method_(appointment_soon_with_specified_size) {
      auto i = status_system_images::appointment_soon({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-soon", size {64, 64}), i, csf_);
    }

    void test_method_(audio_volume_high) {
      auto i = status_system_images::audio_volume_high();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-high"), i, csf_);
    }

    void test_method_(audio_volume_high_with_specified_size) {
      auto i = status_system_images::audio_volume_high({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-high", size {64, 64}), i, csf_);
    }

    void test_method_(audio_volume_low) {
      auto i = status_system_images::audio_volume_low();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-low"), i, csf_);
    }

    void test_method_(audio_volume_low_with_specified_size) {
      auto i = status_system_images::audio_volume_low({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-low", size {64, 64}), i, csf_);
    }

    void test_method_(audio_volume_medium) {
      auto i = status_system_images::audio_volume_medium();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-medium"), i, csf_);
    }

    void test_method_(audio_volume_medium_with_specified_size) {
      auto i = status_system_images::audio_volume_medium({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-medium", size {64, 64}), i, csf_);
    }

    void test_method_(audio_volume_muted) {
      auto i = status_system_images::audio_volume_muted();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-muted"), i, csf_);
    }

    void test_method_(audio_volume_muted_with_specified_size) {
      auto i = status_system_images::audio_volume_muted({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-volume-muted", size {64, 64}), i, csf_);
    }

    void test_method_(battery_caution) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = status_system_images::battery_caution();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery-caution"), i, csf_);
    }

    void test_method_(battery_caution_with_specified_size) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = status_system_images::battery_caution({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery-caution", size {64, 64}), i, csf_);
    }

    void test_method_(battery_low) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = status_system_images::battery_low();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery-low"), i, csf_);
    }

    void test_method_(battery_low_with_specified_size) {
      if (environment::os_version().is_linux()) assert::ignore();
      auto i = status_system_images::battery_low({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery-low", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_error) {
      auto i = status_system_images::dialog_error();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-error"), i, csf_);
    }

    void test_method_(dialog_error_with_specified_size) {
      auto i = status_system_images::dialog_error({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-error", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_information) {
      auto i = status_system_images::dialog_information();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-information"), i, csf_);
    }

    void test_method_(dialog_information_with_specified_size) {
      auto i = status_system_images::dialog_information({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-information", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_password) {
      auto i = status_system_images::dialog_password();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-password"), i, csf_);
    }

    void test_method_(dialog_password_with_specified_size) {
      auto i = status_system_images::dialog_password({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-password", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_question) {
      auto i = status_system_images::dialog_question();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-question"), i, csf_);
    }

    void test_method_(dialog_question_with_specified_size) {
      auto i = status_system_images::dialog_question({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-question", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_warning) {
      auto i = status_system_images::dialog_warning();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-warning"), i, csf_);
    }

    void test_method_(dialog_warning_with_specified_size) {
      auto i = status_system_images::dialog_warning({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-warning", size {64, 64}), i, csf_);
    }

    void test_method_(folder_drag_accept) {
      auto i = status_system_images::folder_drag_accept();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-drag-accept"), i, csf_);
    }

    void test_method_(folder_drag_accept_with_specified_size) {
      auto i = status_system_images::folder_drag_accept({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-drag-accept", size {64, 64}), i, csf_);
    }

    void test_method_(folder_open) {
      auto i = status_system_images::folder_open();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-open"), i, csf_);
    }

    void test_method_(folder_open_with_specified_size) {
      auto i = status_system_images::folder_open({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-open", size {64, 64}), i, csf_);
    }

    void test_method_(folder_visiting) {
      auto i = status_system_images::folder_visiting();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-visiting"), i, csf_);
    }

    void test_method_(folder_visiting_with_specified_size) {
      auto i = status_system_images::folder_visiting({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-visiting", size {64, 64}), i, csf_);
    }

    void test_method_(image_loading) {
      auto i = status_system_images::image_loading();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-loading"), i, csf_);
    }

    void test_method_(image_loading_with_specified_size) {
      auto i = status_system_images::image_loading({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-loading", size {64, 64}), i, csf_);
    }

    void test_method_(image_missing) {
      auto i = status_system_images::image_missing();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-missing"), i, csf_);
    }

    void test_method_(image_missing_with_specified_size) {
      auto i = status_system_images::image_missing({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("image-missing", size {64, 64}), i, csf_);
    }

    void test_method_(mail_attachment) {
      auto i = status_system_images::mail_attachment();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-attachment"), i, csf_);
    }

    void test_method_(mail_attachment_with_specified_size) {
      auto i = status_system_images::mail_attachment({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-attachment", size {64, 64}), i, csf_);
    }

    void test_method_(mail_unread) {
      auto i = status_system_images::mail_unread();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-unread"), i, csf_);
    }

    void test_method_(mail_unread_with_specified_size) {
      auto i = status_system_images::mail_unread({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-unread", size {64, 64}), i, csf_);
    }

    void test_method_(mail_read) {
      auto i = status_system_images::mail_read();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-read"), i, csf_);
    }

    void test_method_(mail_read_with_specified_size) {
      auto i = status_system_images::mail_read({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-read", size {64, 64}), i, csf_);
    }

    void test_method_(mail_replied) {
      auto i = status_system_images::mail_replied();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-replied"), i, csf_);
    }

    void test_method_(mail_replied_with_specified_size) {
      auto i = status_system_images::mail_replied({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-replied", size {64, 64}), i, csf_);
    }

    void test_method_(mail_signed) {
      auto i = status_system_images::mail_signed();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-signed"), i, csf_);
    }

    void test_method_(mail_signed_with_specified_size) {
      auto i = status_system_images::mail_signed({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-signed", size {64, 64}), i, csf_);
    }

    void test_method_(mail_signed_verified) {
      auto i = status_system_images::mail_signed_verified();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-signed-verified"), i, csf_);
    }

    void test_method_(mail_signed_verified_with_specified_size) {
      auto i = status_system_images::mail_signed_verified({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-signed-verified", size {64, 64}), i, csf_);
    }

    void test_method_(media_playlist_repeat) {
      auto i = status_system_images::media_playlist_repeat();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playlist-repeat"), i, csf_);
    }

    void test_method_(media_playlist_repeat_with_specified_size) {
      auto i = status_system_images::media_playlist_repeat({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playlist-repeat", size {64, 64}), i, csf_);
    }

    void test_method_(media_playlist_shuffle) {
      auto i = status_system_images::media_playlist_shuffle();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playlist-shuffle"), i, csf_);
    }

    void test_method_(media_playlist_shuffle_with_specified_size) {
      auto i = status_system_images::media_playlist_shuffle({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playlist-shuffle", size {64, 64}), i, csf_);
    }

    void test_method_(network_error) {
      auto i = status_system_images::network_error();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-error"), i, csf_);
    }

    void test_method_(network_error_with_specified_size) {
      auto i = status_system_images::network_error({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-error", size {64, 64}), i, csf_);
    }

    void test_method_(network_idle) {
      auto i = status_system_images::network_idle();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-idle"), i, csf_);
    }

    void test_method_(network_idle_with_specified_size) {
      auto i = status_system_images::network_idle({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-idle", size {64, 64}), i, csf_);
    }

    void test_method_(network_offline) {
      auto i = status_system_images::network_offline();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-offline"), i, csf_);
    }

    void test_method_(network_offline_with_specified_size) {
      auto i = status_system_images::network_offline({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-offline", size {64, 64}), i, csf_);
    }

    void test_method_(network_receive) {
      auto i = status_system_images::network_receive();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-receive"), i, csf_);
    }

    void test_method_(network_receive_with_specified_size) {
      auto i = status_system_images::network_receive({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-receive", size {64, 64}), i, csf_);
    }

    void test_method_(network_transmit) {
      auto i = status_system_images::network_transmit();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-transmit"), i, csf_);
    }

    void test_method_(network_transmit_with_specified_size) {
      auto i = status_system_images::network_transmit({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-transmit", size {64, 64}), i, csf_);
    }

    void test_method_(network_transmit_receive) {
      auto i = status_system_images::network_transmit_receive();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-transmit-receive"), i, csf_);
    }

    void test_method_(network_transmit_receive_with_specified_size) {
      auto i = status_system_images::network_transmit_receive({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-transmit-receive", size {64, 64}), i, csf_);
    }

    void test_method_(printer_error) {
      auto i = status_system_images::printer_error();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer-error"), i, csf_);
    }

    void test_method_(printer_error_with_specified_size) {
      auto i = status_system_images::printer_error({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer-error", size {64, 64}), i, csf_);
    }

    void test_method_(printer_printing) {
      auto i = status_system_images::printer_printing();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer-printing"), i, csf_);
    }

    void test_method_(printer_printing_with_specified_size) {
      auto i = status_system_images::printer_printing({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer-printing", size {64, 64}), i, csf_);
    }

    void test_method_(security_high) {
      auto i = status_system_images::security_high();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-high"), i, csf_);
    }

    void test_method_(security_high_with_specified_size) {
      auto i = status_system_images::security_high({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-high", size {64, 64}), i, csf_);
    }

    void test_method_(security_medium) {
      auto i = status_system_images::security_medium();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-medium"), i, csf_);
    }

    void test_method_(security_medium_with_specified_size) {
      auto i = status_system_images::security_medium({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-medium", size {64, 64}), i, csf_);
    }

    void test_method_(security_low) {
      auto i = status_system_images::security_low();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-low"), i, csf_);
    }

    void test_method_(security_low_with_specified_size) {
      auto i = status_system_images::security_low({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("security-low", size {64, 64}), i, csf_);
    }

    void test_method_(software_update_available) {
      auto i = status_system_images::software_update_available();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("software-update-available"), i, csf_);
    }

    void test_method_(software_update_available_with_specified_size) {
      auto i = status_system_images::software_update_available({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("software-update-available", size {64, 64}), i, csf_);
    }

    void test_method_(software_update_urgent) {
      auto i = status_system_images::software_update_urgent();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("software-update-urgent"), i, csf_);
    }

    void test_method_(software_update_urgent_with_specified_size) {
      auto i = status_system_images::software_update_urgent({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("software-update-urgent", size {64, 64}), i, csf_);
    }

    void test_method_(task_due) {
      auto i = status_system_images::task_due();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("task-due"), i, csf_);
    }

    void test_method_(task_due_with_specified_size) {
      auto i = status_system_images::task_due({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("task-due", size {64, 64}), i, csf_);
    }

    void test_method_(task_past_due) {
      auto i = status_system_images::task_past_due();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("task-past-due"), i, csf_);
    }

    void test_method_(task_past_due_with_specified_size) {
      auto i = status_system_images::task_past_due({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("task-past-due", size {64, 64}), i, csf_);
    }

    void test_method_(user_available) {
      auto i = status_system_images::user_available();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-available"), i, csf_);
    }

    void test_method_(user_available_with_specified_size) {
      auto i = status_system_images::user_available({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-available", size {64, 64}), i, csf_);
    }

    void test_method_(user_away) {
      auto i = status_system_images::user_away();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-away"), i, csf_);
    }

    void test_method_(user_away_with_specified_size) {
      auto i = status_system_images::user_away({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-away", size {64, 64}), i, csf_);
    }

    void test_method_(user_idle) {
      auto i = status_system_images::user_idle();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-idle"), i, csf_);
    }

    void test_method_(user_idle_with_specified_size) {
      auto i = status_system_images::user_idle({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-idle", size {64, 64}), i, csf_);
    }

    void test_method_(user_offline) {
      auto i = status_system_images::user_offline();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-offline"), i, csf_);
    }

    void test_method_(user_offline_with_specified_size) {
      auto i = status_system_images::user_offline({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-offline", size {64, 64}), i, csf_);
    }

    void test_method_(user_trash_full) {
      auto i = status_system_images::user_trash_full();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-trash-full"), i, csf_);
    }

    void test_method_(user_trash_full_with_specified_size) {
      auto i = status_system_images::user_trash_full({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-trash-full", size {64, 64}), i, csf_);
    }

    void test_method_(weather_clear) {
      auto i = status_system_images::weather_clear();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-clear"), i, csf_);
    }

    void test_method_(weather_clear_with_specified_size) {
      auto i = status_system_images::weather_clear({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-clear", size {64, 64}), i, csf_);
    }

    void test_method_(weather_clear_night) {
      auto i = status_system_images::weather_clear_night();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-clear-night"), i, csf_);
    }

    void test_method_(weather_clear_night_with_specified_size) {
      auto i = status_system_images::weather_clear_night({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-clear-night", size {64, 64}), i, csf_);
    }

    void test_method_(weather_few_clouds) {
      auto i = status_system_images::weather_few_clouds();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-few-clouds"), i, csf_);
    }

    void test_method_(weather_few_clouds_with_specified_size) {
      auto i = status_system_images::weather_few_clouds({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-few-clouds", size {64, 64}), i, csf_);
    }

    void test_method_(weather_few_clouds_night) {
      auto i = status_system_images::weather_few_clouds_night();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-few-clouds-night"), i, csf_);
    }

    void test_method_(weather_few_clouds_night_with_specified_size) {
      auto i = status_system_images::weather_few_clouds_night({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-few-clouds-night", size {64, 64}), i, csf_);
    }

    void test_method_(weather_fog) {
      auto i = status_system_images::weather_fog();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-fog"), i, csf_);
    }

    void test_method_(weather_fog_with_specified_size) {
      auto i = status_system_images::weather_fog({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-fog", size {64, 64}), i, csf_);
    }

    void test_method_(weather_overcast) {
      auto i = status_system_images::weather_overcast();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-overcast"), i, csf_);
    }

    void test_method_(weather_overcast_with_specified_size) {
      auto i = status_system_images::weather_overcast({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-overcast", size {64, 64}), i, csf_);
    }

    void test_method_(weather_severe_alert) {
      auto i = status_system_images::weather_severe_alert();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-severe-alert"), i, csf_);
    }

    void test_method_(weather_severe_alert_with_specified_size) {
      auto i = status_system_images::weather_severe_alert({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-severe-alert", size {64, 64}), i, csf_);
    }

    void test_method_(weather_showers) {
      auto i = status_system_images::weather_showers();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-showers"), i, csf_);
    }

    void test_method_(weather_showers_with_specified_size) {
      auto i = status_system_images::weather_showers({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-showers", size {64, 64}), i, csf_);
    }

    void test_method_(weather_showers_scattered) {
      auto i = status_system_images::weather_showers_scattered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-showers-scattered"), i, csf_);
    }

    void test_method_(weather_showers_scattered_with_specified_size) {
      auto i = status_system_images::weather_showers_scattered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-showers-scattered", size {64, 64}), i, csf_);
    }

    void test_method_(weather_snow) {
      auto i = status_system_images::weather_snow();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-snow"), i, csf_);
    }

    void test_method_(weather_snow_with_specified_size) {
      auto i = status_system_images::weather_snow({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-snow", size {64, 64}), i, csf_);
    }

    void test_method_(weather_storm) {
      auto i = status_system_images::weather_storm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-storm"), i, csf_);
    }

    void test_method_(weather_storm_with_specified_size) {
      auto i = status_system_images::weather_storm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("weather-storm", size {64, 64}), i, csf_);
    }
  };
}
