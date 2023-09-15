#include <xtd/drawing/devices_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(devices_system_images_tests) {
  public:
    void test_method_(default_size) {
      auto s = devices_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(audio_card) {
      auto i = devices_system_images::audio_card();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-card"), i, csf_);
    }

    void test_method_(audio_card_with_specified_size) {
      auto i = devices_system_images::audio_card({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-card", size {64, 64}), i, csf_);
    }

    void test_method_(audio_input_microphone) {
      auto i = devices_system_images::audio_input_microphone();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-input-microphone"), i, csf_);
    }

    void test_method_(audio_input_microphone_with_specified_size) {
      auto i = devices_system_images::audio_input_microphone({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("audio-input-microphone", size {64, 64}), i, csf_);
    }

    void test_method_(battery) {
      auto i = devices_system_images::battery();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery"), i, csf_);
    }

    void test_method_(battery_with_specified_size) {
      auto i = devices_system_images::battery({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("battery", size {64, 64}), i, csf_);
    }

    void test_method_(camera_photo) {
      auto i = devices_system_images::camera_photo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-photo"), i, csf_);
    }

    void test_method_(camera_photo_with_specified_size) {
      auto i = devices_system_images::camera_photo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-photo", size {64, 64}), i, csf_);
    }

    void test_method_(camera_video) {
      auto i = devices_system_images::camera_video();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-video"), i, csf_);
    }

    void test_method_(camera_video_with_specified_size) {
      auto i = devices_system_images::camera_video({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-video", size {64, 64}), i, csf_);
    }

    void test_method_(camera_web) {
      auto i = devices_system_images::camera_web();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-web"), i, csf_);
    }

    void test_method_(camera_web_with_specified_size) {
      auto i = devices_system_images::camera_web({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("camera-web", size {64, 64}), i, csf_);
    }

    void test_method_(computer) {
      auto i = devices_system_images::computer();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("computer"), i, csf_);
    }

    void test_method_(computer_with_specified_size) {
      auto i = devices_system_images::computer({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("computer", size {64, 64}), i, csf_);
    }

    void test_method_(drive_harddisk) {
      auto i = devices_system_images::drive_harddisk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-harddisk"), i, csf_);
    }

    void test_method_(drive_harddisk_with_specified_size) {
      auto i = devices_system_images::drive_harddisk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-harddisk", size {64, 64}), i, csf_);
    }

    void test_method_(drive_optical) {
      auto i = devices_system_images::drive_optical();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-optical"), i, csf_);
    }

    void test_method_(drive_optical_with_specified_size) {
      auto i = devices_system_images::drive_optical({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-optical", size {64, 64}), i, csf_);
    }

    void test_method_(drive_removable_media_usb_pendrive) {
      auto i = devices_system_images::drive_removable_media_usb_pendrive();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-removable-media-usb-pendrive"), i, csf_);
    }

    void test_method_(drive_removable_media_usb_pendrive_with_specified_size) {
      auto i = devices_system_images::drive_removable_media_usb_pendrive({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-removable-media-usb-pendrive", size {64, 64}), i, csf_);
    }

    void test_method_(drive_removable_media) {
      auto i = devices_system_images::drive_removable_media();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-removable-media"), i, csf_);
    }

    void test_method_(drive_removable_media_with_specified_size) {
      auto i = devices_system_images::drive_removable_media({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("drive-removable-media", size {64, 64}), i, csf_);
    }

    void test_method_(input_gaming) {
      auto i = devices_system_images::input_gaming();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-gaming"), i, csf_);
    }

    void test_method_(input_gaming_with_specified_size) {
      auto i = devices_system_images::input_gaming({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-gaming", size {64, 64}), i, csf_);
    }

    void test_method_(input_keyboard) {
      auto i = devices_system_images::input_keyboard();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-keyboard"), i, csf_);
    }

    void test_method_(input_keyboard_with_specified_size) {
      auto i = devices_system_images::input_keyboard({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-keyboard", size {64, 64}), i, csf_);
    }

    void test_method_(input_mouse) {
      auto i = devices_system_images::input_mouse();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-mouse"), i, csf_);
    }

    void test_method_(input_mouse_with_specified_size) {
      auto i = devices_system_images::input_mouse({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-mouse", size {64, 64}), i, csf_);
    }

    void test_method_(input_tablet) {
      auto i = devices_system_images::input_tablet();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-tablet"), i, csf_);
    }

    void test_method_(input_tablet_with_specified_size) {
      auto i = devices_system_images::input_tablet({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("input-tablet", size {64, 64}), i, csf_);
    }

    void test_method_(media_flash) {
      auto i = devices_system_images::media_flash();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-flash"), i, csf_);
    }

    void test_method_(media_flash_with_specified_size) {
      auto i = devices_system_images::media_flash({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-flash", size {64, 64}), i, csf_);
    }

    void test_method_(media_floppy) {
      auto i = devices_system_images::media_floppy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-floppy"), i, csf_);
    }

    void test_method_(media_floppy_with_specified_size) {
      auto i = devices_system_images::media_floppy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-floppy", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_audio) {
      auto i = devices_system_images::media_optical_audio();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-audio"), i, csf_);
    }

    void test_method_(media_optical_audio_with_specified_size) {
      auto i = devices_system_images::media_optical_audio({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-audio", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_blu_ray) {
      auto i = devices_system_images::media_optical_blu_ray();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-blu-ray"), i, csf_);
    }

    void test_method_(media_optical_blu_ray_with_specified_size) {
      auto i = devices_system_images::media_optical_blu_ray({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-blu-ray", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_data) {
      auto i = devices_system_images::media_optical_data();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-data"), i, csf_);
    }

    void test_method_(media_optical_data_with_specified_size) {
      auto i = devices_system_images::media_optical_data({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-data", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_dvd_video) {
      auto i = devices_system_images::media_optical_dvd_video();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-dvd-video"), i, csf_);
    }

    void test_method_(media_optical_dvd_video_with_specified_size) {
      auto i = devices_system_images::media_optical_dvd_video({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-dvd-video", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_dvd) {
      auto i = devices_system_images::media_optical_dvd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-dvd"), i, csf_);
    }

    void test_method_(media_optical_dvd_with_specified_size) {
      auto i = devices_system_images::media_optical_dvd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-dvd", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_mixed_cd) {
      auto i = devices_system_images::media_optical_mixed_cd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-mixed-cd"), i, csf_);
    }

    void test_method_(media_optical_mixed_cd_with_specified_size) {
      auto i = devices_system_images::media_optical_mixed_cd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-mixed-cd", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_recordable) {
      auto i = devices_system_images::media_optical_recordable();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-recordable"), i, csf_);
    }

    void test_method_(media_optical_recordable_with_specified_size) {
      auto i = devices_system_images::media_optical_recordable({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-recordable", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_video) {
      auto i = devices_system_images::media_optical_video();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-video"), i, csf_);
    }

    void test_method_(media_optical_video_with_specified_size) {
      auto i = devices_system_images::media_optical_video({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-video", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical) {
      auto i = devices_system_images::media_optical();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical"), i, csf_);
    }

    void test_method_(media_optical_with_specified_size) {
      auto i = devices_system_images::media_optical({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical", size {64, 64}), i, csf_);
    }

    void test_method_(media_tape) {
      auto i = devices_system_images::media_tape();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-tape"), i, csf_);
    }

    void test_method_(media_tape_with_specified_size) {
      auto i = devices_system_images::media_tape({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-tape", size {64, 64}), i, csf_);
    }

    void test_method_(modem) {
      auto i = devices_system_images::modem();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("modem"), i, csf_);
    }

    void test_method_(modem_with_specified_size) {
      auto i = devices_system_images::modem({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("modem", size {64, 64}), i, csf_);
    }

    void test_method_(multimedia_player) {
      auto i = devices_system_images::multimedia_player();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("multimedia-player"), i, csf_);
    }

    void test_method_(multimedia_player_with_specified_size) {
      auto i = devices_system_images::multimedia_player({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("multimedia-player", size {64, 64}), i, csf_);
    }

    void test_method_(network_wired) {
      auto i = devices_system_images::network_wired();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-wired"), i, csf_);
    }

    void test_method_(network_wired_with_specified_size) {
      auto i = devices_system_images::network_wired({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-wired", size {64, 64}), i, csf_);
    }

    void test_method_(network_wireless) {
      auto i = devices_system_images::network_wireless();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-wireless"), i, csf_);
    }

    void test_method_(network_wireless_with_specified_size) {
      auto i = devices_system_images::network_wireless({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-wireless", size {64, 64}), i, csf_);
    }

    void test_method_(pda) {
      auto i = devices_system_images::pda();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("pda"), i, csf_);
    }

    void test_method_(pda_with_specified_size) {
      auto i = devices_system_images::pda({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("pda", size {64, 64}), i, csf_);
    }

    void test_method_(phone) {
      auto i = devices_system_images::phone();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("phone"), i, csf_);
    }

    void test_method_(phone_with_specified_size) {
      auto i = devices_system_images::phone({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("phone", size {64, 64}), i, csf_);
    }

    void test_method_(printer) {
      auto i = devices_system_images::printer();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer"), i, csf_);
    }

    void test_method_(printer_with_specified_size) {
      auto i = devices_system_images::printer({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("printer", size {64, 64}), i, csf_);
    }

    void test_method_(scanner) {
      auto i = devices_system_images::scanner();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("scanner"), i, csf_);
    }

    void test_method_(scanner_with_specified_size) {
      auto i = devices_system_images::scanner({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("scanner", size {64, 64}), i, csf_);
    }

    void test_method_(video_display) {
      auto i = devices_system_images::video_display();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("video-display"), i, csf_);
    }

    void test_method_(video_display_with_specified_size) {
      auto i = devices_system_images::video_display({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("video-display", size {64, 64}), i, csf_);
    }
  };
}
