/// @file
/// @brief Contains xtd::drawing::devices_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::devices_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ devices_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::devices_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/devices_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ devices_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the devices system image "audio-card".
      /// @return The xtd::drawing::image "audio-card".
      [[nodiscard]] static auto audio_card() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "audio-card" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "audio-card".
      [[nodiscard]] static auto audio_card(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "audio-input-microphone".
      /// @return The xtd::drawing::image "audio-input-microphone".
      [[nodiscard]] static auto audio_input_microphone() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "audio-input-microphone" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "audio-input-microphone".
      [[nodiscard]] static auto audio_input_microphone(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "battery".
      /// @return The xtd::drawing::image "battery".
      [[nodiscard]] static auto battery() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "battery" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "battery".
      [[nodiscard]] static auto battery(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "camera-photo".
      /// @return The xtd::drawing::image "camera-photo".
      [[nodiscard]] static auto camera_photo() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "camera-photo" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-photo".
      [[nodiscard]] static auto camera_photo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "camera-video".
      /// @return The xtd::drawing::image "camera-video".
      [[nodiscard]] static auto camera_video() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "camera-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-video".
      [[nodiscard]] static auto camera_video(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "camera-web".
      /// @return The xtd::drawing::image "camera-web".
      [[nodiscard]] static auto camera_web() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "camera-web" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "camera-web".
      [[nodiscard]] static auto camera_web(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "computer".
      /// @return The xtd::drawing::image "computer".
      [[nodiscard]] static auto computer() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "computer" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "computer".
      [[nodiscard]] static auto computer(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "drive-harddisk".
      /// @return The xtd::drawing::image "drive-harddisk".
      [[nodiscard]] static auto drive_harddisk() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "drive-harddisk" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-harddisk".
      [[nodiscard]] static auto drive_harddisk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "drive-optical".
      /// @return The xtd::drawing::image "drive-optical".
      [[nodiscard]] static auto drive_optical() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "drive-optical" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-optical".
      [[nodiscard]] static auto drive_optical(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "drive-removable-media-usb-pendrive".
      /// @return The xtd::drawing::image "drive-removable-media-usb-pendrive".
      [[nodiscard]] static auto drive_removable_media_usb_pendrive() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "drive-removable-media-usb-pendrive" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-removable-media-usb-pendrive".
      [[nodiscard]] static auto drive_removable_media_usb_pendrive(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "drive-removable-media".
      /// @return The xtd::drawing::image "drive-removable-media".
      [[nodiscard]] static auto drive_removable_media() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "drive-removable-media" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "drive-removable-media".
      [[nodiscard]] static auto drive_removable_media(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "input-gaming".
      /// @return The xtd::drawing::image "input-gaming".
      [[nodiscard]] static auto input_gaming() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "input-gaming" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-gaming".
      [[nodiscard]] static auto input_gaming(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "input-keyboard".
      /// @return The xtd::drawing::image "input-keyboard".
      [[nodiscard]] static auto input_keyboard() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "input-keyboard" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-keyboard".
      [[nodiscard]] static auto input_keyboard(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "input-mouse".
      /// @return The xtd::drawing::image "input-mouse".
      [[nodiscard]] static auto input_mouse() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "input-mouse" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-mouse".
      [[nodiscard]] static auto input_mouse(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "input-tablet".
      /// @return The xtd::drawing::image "input-tablet".
      [[nodiscard]] static auto input_tablet() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "input-tablet" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "input-tablet".
      [[nodiscard]] static auto input_tablet(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-flash".
      /// @return The xtd::drawing::image "media-flash".
      [[nodiscard]] static auto media_flash() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-flash" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-flash".
      [[nodiscard]] static auto media_flash(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-floppy".
      /// @return The xtd::drawing::image "media-floppy".
      [[nodiscard]] static auto media_floppy() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-floppy" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-floppy".
      [[nodiscard]] static auto media_floppy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-audio".
      /// @return The xtd::drawing::image "media-optical-audio".
      [[nodiscard]] static auto media_optical_audio() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-audio" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-audio".
      [[nodiscard]] static auto media_optical_audio(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-blu-ray".
      /// @return The xtd::drawing::image "media-optical-blu-ray".
      [[nodiscard]] static auto media_optical_blu_ray() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-blu-ray" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-blu-ray".
      [[nodiscard]] static auto media_optical_blu_ray(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-data".
      /// @return The xtd::drawing::image "media-optical-data".
      [[nodiscard]] static auto media_optical_data() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-data" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-data".
      [[nodiscard]] static auto media_optical_data(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-dvd-video".
      /// @return The xtd::drawing::image "media-optical-dvd-video".
      [[nodiscard]] static auto media_optical_dvd_video() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-dvd-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-dvd-video".
      [[nodiscard]] static auto media_optical_dvd_video(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-dvd".
      /// @return The xtd::drawing::image "media-optical-dvd".
      [[nodiscard]] static auto media_optical_dvd() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-dvd" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-dvd".
      [[nodiscard]] static auto media_optical_dvd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-mixed-cd".
      /// @return The xtd::drawing::image "media-optical-mixed-cd".
      [[nodiscard]] static auto media_optical_mixed_cd() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-mixed-cd" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-mixed-cd".
      [[nodiscard]] static auto media_optical_mixed_cd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-recordable".
      /// @return The xtd::drawing::image "media-optical-recordable".
      [[nodiscard]] static auto media_optical_recordable() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-recordable" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-recordable".
      [[nodiscard]] static auto media_optical_recordable(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical-video".
      /// @return The xtd::drawing::image "media-optical-video".
      [[nodiscard]] static auto media_optical_video() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical-video" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-video".
      [[nodiscard]] static auto media_optical_video(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-optical".
      /// @return The xtd::drawing::image "media-optical".
      [[nodiscard]] static auto media_optical() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-optical" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-optical".
      [[nodiscard]] static auto media_optical(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "media-tape".
      /// @return The xtd::drawing::image "media-tape".
      [[nodiscard]] static auto media_tape() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "media-tape" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "media-tape".
      [[nodiscard]] static auto media_tape(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "modem".
      /// @return The xtd::drawing::image "modem".
      [[nodiscard]] static auto modem() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "modem" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "modem".
      [[nodiscard]] static auto modem(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "multimedia-player".
      /// @return The xtd::drawing::image "multimedia-player".
      [[nodiscard]] static auto multimedia_player() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "multimedia-player" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "multimedia-player".
      [[nodiscard]] static auto multimedia_player(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "network-wired".
      /// @return The xtd::drawing::image "network-wired".
      [[nodiscard]] static auto network_wired() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "network-wired" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "network-wired".
      [[nodiscard]] static auto network_wired(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "network-wireless".
      /// @return The xtd::drawing::image "network-wireless".
      [[nodiscard]] static auto network_wireless() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "network-wireless" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "network-wireless".
      [[nodiscard]] static auto network_wireless(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "pda".
      /// @return The xtd::drawing::image "pda".
      [[nodiscard]] static auto pda() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "pda" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "pda".
      [[nodiscard]] static auto pda(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "phone".
      /// @return The xtd::drawing::image "phone".
      [[nodiscard]] static auto phone() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "phone" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "phone".
      [[nodiscard]] static auto phone(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "printer".
      /// @return The xtd::drawing::image "printer".
      [[nodiscard]] static auto printer() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "printer" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "printer".
      [[nodiscard]] static auto printer(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "scanner".
      /// @return The xtd::drawing::image "scanner".
      [[nodiscard]] static auto scanner() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "scanner" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "scanner".
      [[nodiscard]] static auto scanner(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the devices system image "video-display".
      /// @return The xtd::drawing::image "video-display".
      [[nodiscard]] static auto video_display() noexcept -> xtd::drawing::image;
      /// @brief Gets the devices system image "video-display" with specified size.
      /// @param size The devices system image size in pixels.
      /// @return The xtd::drawing::image "video-display".
      [[nodiscard]] static auto video_display(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      [[nodiscard]] static auto get_images() noexcept -> const xtd::array<xtd::drawing::image>&;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      [[nodiscard]] static auto get_images(const xtd::drawing::size& size) noexcept -> xtd::array<xtd::drawing::image>;
      
      /// @brief Gets an array of image names.
      /// @return The array of image names.
      [[nodiscard]] static auto get_image_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
