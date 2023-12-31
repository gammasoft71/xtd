/// @file
/// @brief Contains xtd::drawing::devices_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::devices_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ devices_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::devices_system_images
    /// @par Header
    /// @code #include <xtd/drawing/devices_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ devices_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the devices system image "audio-card".
      /// @return The xtd::drawing::image "audio-card".
      static xtd::drawing::image audio_card() noexcept;
      /// @brief Gets the devices system image "audio-card" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "audio-card".
      static xtd::drawing::image audio_card(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "audio-input-microphone".
      /// @return The xtd::drawing::image "audio-input-microphone".
      static xtd::drawing::image audio_input_microphone() noexcept;
      /// @brief Gets the devices system image "audio-input-microphone" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "audio-input-microphone".
      static xtd::drawing::image audio_input_microphone(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "battery".
      /// @return The xtd::drawing::image "battery".
      static xtd::drawing::image battery() noexcept;
      /// @brief Gets the devices system image "battery" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "battery".
      static xtd::drawing::image battery(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "camera-photo".
      /// @return The xtd::drawing::image "camera-photo".
      static xtd::drawing::image camera_photo() noexcept;
      /// @brief Gets the devices system image "camera-photo" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-photo".
      static xtd::drawing::image camera_photo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "camera-video".
      /// @return The xtd::drawing::image "camera-video".
      static xtd::drawing::image camera_video() noexcept;
      /// @brief Gets the devices system image "camera-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-video".
      static xtd::drawing::image camera_video(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "camera-web".
      /// @return The xtd::drawing::image "camera-web".
      static xtd::drawing::image camera_web() noexcept;
      /// @brief Gets the devices system image "camera-web" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-web".
      static xtd::drawing::image camera_web(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "computer".
      /// @return The xtd::drawing::image "computer".
      static xtd::drawing::image computer() noexcept;
      /// @brief Gets the devices system image "computer" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "computer".
      static xtd::drawing::image computer(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "drive-harddisk".
      /// @return The xtd::drawing::image "drive-harddisk".
      static xtd::drawing::image drive_harddisk() noexcept;
      /// @brief Gets the devices system image "drive-harddisk" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-harddisk".
      static xtd::drawing::image drive_harddisk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "drive-optical".
      /// @return The xtd::drawing::image "drive-optical".
      static xtd::drawing::image drive_optical() noexcept;
      /// @brief Gets the devices system image "drive-optical" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-optical".
      static xtd::drawing::image drive_optical(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "drive-removable-media-usb-pendrive".
      /// @return The xtd::drawing::image "drive-removable-media-usb-pendrive".
      static xtd::drawing::image drive_removable_media_usb_pendrive() noexcept;
      /// @brief Gets the devices system image "drive-removable-media-usb-pendrive" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-removable-media-usb-pendrive".
      static xtd::drawing::image drive_removable_media_usb_pendrive(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "drive-removable-media".
      /// @return The xtd::drawing::image "drive-removable-media".
      static xtd::drawing::image drive_removable_media() noexcept;
      /// @brief Gets the devices system image "drive-removable-media" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-removable-media".
      static xtd::drawing::image drive_removable_media(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "input-gaming".
      /// @return The xtd::drawing::image "input-gaming".
      static xtd::drawing::image input_gaming() noexcept;
      /// @brief Gets the devices system image "input-gaming" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-gaming".
      static xtd::drawing::image input_gaming(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "input-keyboard".
      /// @return The xtd::drawing::image "input-keyboard".
      static xtd::drawing::image input_keyboard() noexcept;
      /// @brief Gets the devices system image "input-keyboard" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-keyboard".
      static xtd::drawing::image input_keyboard(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "input-mouse".
      /// @return The xtd::drawing::image "input-mouse".
      static xtd::drawing::image input_mouse() noexcept;
      /// @brief Gets the devices system image "input-mouse" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-mouse".
      static xtd::drawing::image input_mouse(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "input-tablet".
      /// @return The xtd::drawing::image "input-tablet".
      static xtd::drawing::image input_tablet() noexcept;
      /// @brief Gets the devices system image "input-tablet" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-tablet".
      static xtd::drawing::image input_tablet(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-flash".
      /// @return The xtd::drawing::image "media-flash".
      static xtd::drawing::image media_flash() noexcept;
      /// @brief Gets the devices system image "media-flash" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-flash".
      static xtd::drawing::image media_flash(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-floppy".
      /// @return The xtd::drawing::image "media-floppy".
      static xtd::drawing::image media_floppy() noexcept;
      /// @brief Gets the devices system image "media-floppy" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-floppy".
      static xtd::drawing::image media_floppy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-audio".
      /// @return The xtd::drawing::image "media-optical-audio".
      static xtd::drawing::image media_optical_audio() noexcept;
      /// @brief Gets the devices system image "media-optical-audio" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-audio".
      static xtd::drawing::image media_optical_audio(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-blu-ray".
      /// @return The xtd::drawing::image "media-optical-blu-ray".
      static xtd::drawing::image media_optical_blu_ray() noexcept;
      /// @brief Gets the devices system image "media-optical-blu-ray" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-blu-ray".
      static xtd::drawing::image media_optical_blu_ray(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-data".
      /// @return The xtd::drawing::image "media-optical-data".
      static xtd::drawing::image media_optical_data() noexcept;
      /// @brief Gets the devices system image "media-optical-data" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-data".
      static xtd::drawing::image media_optical_data(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-dvd-video".
      /// @return The xtd::drawing::image "media-optical-dvd-video".
      static xtd::drawing::image media_optical_dvd_video() noexcept;
      /// @brief Gets the devices system image "media-optical-dvd-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-dvd-video".
      static xtd::drawing::image media_optical_dvd_video(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-dvd".
      /// @return The xtd::drawing::image "media-optical-dvd".
      static xtd::drawing::image media_optical_dvd() noexcept;
      /// @brief Gets the devices system image "media-optical-dvd" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-dvd".
      static xtd::drawing::image media_optical_dvd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-mixed-cd".
      /// @return The xtd::drawing::image "media-optical-mixed-cd".
      static xtd::drawing::image media_optical_mixed_cd() noexcept;
      /// @brief Gets the devices system image "media-optical-mixed-cd" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-mixed-cd".
      static xtd::drawing::image media_optical_mixed_cd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-recordable".
      /// @return The xtd::drawing::image "media-optical-recordable".
      static xtd::drawing::image media_optical_recordable() noexcept;
      /// @brief Gets the devices system image "media-optical-recordable" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-recordable".
      static xtd::drawing::image media_optical_recordable(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical-video".
      /// @return The xtd::drawing::image "media-optical-video".
      static xtd::drawing::image media_optical_video() noexcept;
      /// @brief Gets the devices system image "media-optical-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-video".
      static xtd::drawing::image media_optical_video(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-optical".
      /// @return The xtd::drawing::image "media-optical".
      static xtd::drawing::image media_optical() noexcept;
      /// @brief Gets the devices system image "media-optical" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical".
      static xtd::drawing::image media_optical(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "media-tape".
      /// @return The xtd::drawing::image "media-tape".
      static xtd::drawing::image media_tape() noexcept;
      /// @brief Gets the devices system image "media-tape" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-tape".
      static xtd::drawing::image media_tape(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "modem".
      /// @return The xtd::drawing::image "modem".
      static xtd::drawing::image modem() noexcept;
      /// @brief Gets the devices system image "modem" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "modem".
      static xtd::drawing::image modem(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "multimedia-player".
      /// @return The xtd::drawing::image "multimedia-player".
      static xtd::drawing::image multimedia_player() noexcept;
      /// @brief Gets the devices system image "multimedia-player" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "multimedia-player".
      static xtd::drawing::image multimedia_player(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "network-wired".
      /// @return The xtd::drawing::image "network-wired".
      static xtd::drawing::image network_wired() noexcept;
      /// @brief Gets the devices system image "network-wired" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "network-wired".
      static xtd::drawing::image network_wired(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "network-wireless".
      /// @return The xtd::drawing::image "network-wireless".
      static xtd::drawing::image network_wireless() noexcept;
      /// @brief Gets the devices system image "network-wireless" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "network-wireless".
      static xtd::drawing::image network_wireless(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "pda".
      /// @return The xtd::drawing::image "pda".
      static xtd::drawing::image pda() noexcept;
      /// @brief Gets the devices system image "pda" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "pda".
      static xtd::drawing::image pda(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "phone".
      /// @return The xtd::drawing::image "phone".
      static xtd::drawing::image phone() noexcept;
      /// @brief Gets the devices system image "phone" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "phone".
      static xtd::drawing::image phone(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "printer".
      /// @return The xtd::drawing::image "printer".
      static xtd::drawing::image printer() noexcept;
      /// @brief Gets the devices system image "printer" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "printer".
      static xtd::drawing::image printer(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "scanner".
      /// @return The xtd::drawing::image "scanner".
      static xtd::drawing::image scanner() noexcept;
      /// @brief Gets the devices system image "scanner" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "scanner".
      static xtd::drawing::image scanner(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the devices system image "video-display".
      /// @return The xtd::drawing::image "video-display".
      static xtd::drawing::image video_display() noexcept;
      /// @brief Gets the devices system image "video-display" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "video-display".
      static xtd::drawing::image video_display(const xtd::drawing::size& size) noexcept;

      /// @}

      /// @name Methods

      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      static const std::vector<xtd::drawing::image>& get_images() noexcept;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      static std::vector<xtd::drawing::image> get_images(const xtd::drawing::size& size) noexcept;

      /// @brief Gets an array of image names.
      /// @return The array of image names.
      static const std::vector<xtd::ustring>& get_image_names() noexcept;
      /// @}
    };
  }
}
