/// @file
/// @brief Contains xtd::drawing::status_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::status_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ status_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::status_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/status_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ status_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the status system image "appointment-missed".
      /// @return The xtd::drawing::image "appointment-missed".
      [[nodiscard]] static auto appointment_missed() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "appointment-missed" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "appointment-missed".
      [[nodiscard]] static auto appointment_missed(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "appointment-soon".
      /// @return The xtd::drawing::image "appointment-soon".
      [[nodiscard]] static auto appointment_soon() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "appointment-soon" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "appointment-soon".
      [[nodiscard]] static auto appointment_soon(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "audio-volume-high".
      /// @return The xtd::drawing::image "audio-volume-high".
      [[nodiscard]] static auto audio_volume_high() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "audio-volume-high" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-high".
      [[nodiscard]] static auto audio_volume_high(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "audio-volume-low".
      /// @return The xtd::drawing::image "audio-volume-low".
      [[nodiscard]] static auto audio_volume_low() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "audio-volume-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-low".
      [[nodiscard]] static auto audio_volume_low(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "audio-volume-medium".
      /// @return The xtd::drawing::image "audio-volume-medium".
      [[nodiscard]] static auto audio_volume_medium() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "audio-volume-medium" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-medium".
      [[nodiscard]] static auto audio_volume_medium(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "audio-volume-muted".
      /// @return The xtd::drawing::image "audio-volume-muted".
      [[nodiscard]] static auto audio_volume_muted() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "audio-volume-muted" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-muted".
      [[nodiscard]] static auto audio_volume_muted(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "battery-caution".
      /// @return The xtd::drawing::image "battery-caution".
      [[nodiscard]] static auto battery_caution() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "battery-caution" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "battery-caution".
      [[nodiscard]] static auto battery_caution(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "battery-low".
      /// @return The xtd::drawing::image "battery-low".
      [[nodiscard]] static auto battery_low() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "battery-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "battery-low".
      [[nodiscard]] static auto battery_low(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "dialog-error".
      /// @return The xtd::drawing::image "dialog-error".
      [[nodiscard]] static auto dialog_error() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "dialog-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-error".
      [[nodiscard]] static auto dialog_error(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "dialog-information".
      /// @return The xtd::drawing::image "dialog-information".
      [[nodiscard]] static auto dialog_information() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "dialog-information" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-information".
      [[nodiscard]] static auto dialog_information(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "dialog-password".
      /// @return The xtd::drawing::image "dialog-password".
      [[nodiscard]] static auto dialog_password() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "dialog-password" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-password".
      [[nodiscard]] static auto dialog_password(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "dialog-question".
      /// @return The xtd::drawing::image "dialog-question".
      [[nodiscard]] static auto dialog_question() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "dialog-question" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-question".
      [[nodiscard]] static auto dialog_question(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "dialog-warning".
      /// @return The xtd::drawing::image "dialog-warning".
      [[nodiscard]] static auto dialog_warning() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "dialog-warning" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-warning".
      [[nodiscard]] static auto dialog_warning(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "folder-drag-accept".
      /// @return The xtd::drawing::image "folder-drag-accept".
      [[nodiscard]] static auto folder_drag_accept() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "folder-drag-accept" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-drag-accept".
      [[nodiscard]] static auto folder_drag_accept(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "folder-open".
      /// @return The xtd::drawing::image "folder-open".
      [[nodiscard]] static auto folder_open() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "folder-open" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-open".
      [[nodiscard]] static auto folder_open(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "folder-visiting".
      /// @return The xtd::drawing::image "folder-visiting".
      [[nodiscard]] static auto folder_visiting() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "folder-visiting" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-visiting".
      [[nodiscard]] static auto folder_visiting(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "image-loading".
      /// @return The xtd::drawing::image "image-loading".
      [[nodiscard]] static auto image_loading() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "image-loading" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "image-loading".
      [[nodiscard]] static auto image_loading(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "image-missing".
      /// @return The xtd::drawing::image "image-missing".
      [[nodiscard]] static auto image_missing() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "image-missing" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "image-missing".
      [[nodiscard]] static auto image_missing(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-attachment".
      /// @return The xtd::drawing::image "mail-attachment".
      [[nodiscard]] static auto mail_attachment() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-attachment" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-attachment".
      [[nodiscard]] static auto mail_attachment(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-unread".
      /// @return The xtd::drawing::image "mail-unread".
      [[nodiscard]] static auto mail_unread() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-unread" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-unread".
      [[nodiscard]] static auto mail_unread(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-read".
      /// @return The xtd::drawing::image "mail-read".
      [[nodiscard]] static auto mail_read() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-read" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-read".
      [[nodiscard]] static auto mail_read(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-replied".
      /// @return The xtd::drawing::image "mail-replied".
      [[nodiscard]] static auto mail_replied() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-replied" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-replied".
      [[nodiscard]] static auto mail_replied(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-signed".
      /// @return The xtd::drawing::image "mail-signed".
      [[nodiscard]] static auto mail_signed() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-signed" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-signed".
      [[nodiscard]] static auto mail_signed(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "mail-signed-verified".
      /// @return The xtd::drawing::image "mail-signed-verified".
      [[nodiscard]] static auto mail_signed_verified() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "mail-signed-verified" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-signed-verified".
      [[nodiscard]] static auto mail_signed_verified(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "media-playlist-repeat".
      /// @return The xtd::drawing::image "media-playlist-repeat".
      [[nodiscard]] static auto media_playlist_repeat() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "media-playlist-repeat" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "media-playlist-repeat".
      [[nodiscard]] static auto media_playlist_repeat(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "media-playlist-shuffle".
      /// @return The xtd::drawing::image "media-playlist-shuffle".
      [[nodiscard]] static auto media_playlist_shuffle() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "media-playlist-shuffle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "media-playlist-shuffle".
      [[nodiscard]] static auto media_playlist_shuffle(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-error".
      /// @return The xtd::drawing::image "network-error".
      [[nodiscard]] static auto network_error() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-error".
      [[nodiscard]] static auto network_error(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-idle".
      /// @return The xtd::drawing::image "network-idle".
      [[nodiscard]] static auto network_idle() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-idle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-idle".
      [[nodiscard]] static auto network_idle(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-offline".
      /// @return The xtd::drawing::image "network-offline".
      [[nodiscard]] static auto network_offline() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-offline" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-offline".
      [[nodiscard]] static auto network_offline(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-receive".
      /// @return The xtd::drawing::image "network-receive".
      [[nodiscard]] static auto network_receive() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-receive" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-receive".
      [[nodiscard]] static auto network_receive(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-transmit".
      /// @return The xtd::drawing::image "network-transmit".
      [[nodiscard]] static auto network_transmit() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-transmit" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-transmit".
      [[nodiscard]] static auto network_transmit(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "network-transmit-receive".
      /// @return The xtd::drawing::image "network-transmit-receive".
      [[nodiscard]] static auto network_transmit_receive() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "network-transmit-receive" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-transmit-receive".
      [[nodiscard]] static auto network_transmit_receive(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "printer-error".
      /// @return The xtd::drawing::image "printer-error".
      [[nodiscard]] static auto printer_error() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "printer-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "printer-error".
      [[nodiscard]] static auto printer_error(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "printer-printing".
      /// @return The xtd::drawing::image "printer-printing".
      [[nodiscard]] static auto printer_printing() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "printer-printing" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "printer-printing".
      [[nodiscard]] static auto printer_printing(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "security-high".
      /// @return The xtd::drawing::image "security-high".
      [[nodiscard]] static auto security_high() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "security-high" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-high".
      [[nodiscard]] static auto security_high(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "security-medium".
      /// @return The xtd::drawing::image "security-medium".
      [[nodiscard]] static auto security_medium() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "security-medium" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-medium".
      [[nodiscard]] static auto security_medium(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "security-low".
      /// @return The xtd::drawing::image "security-low".
      [[nodiscard]] static auto security_low() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "security-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-low".
      [[nodiscard]] static auto security_low(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "software-update-available".
      /// @return The xtd::drawing::image "software-update-available".
      [[nodiscard]] static auto software_update_available() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "software-update-available" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "software-update-available".
      [[nodiscard]] static auto software_update_available(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "software-update-urgent".
      /// @return The xtd::drawing::image "software-update-urgent".
      [[nodiscard]] static auto software_update_urgent() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "software-update-urgent" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "software-update-urgent".
      [[nodiscard]] static auto software_update_urgent(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "task-due".
      /// @return The xtd::drawing::image "task-due".
      [[nodiscard]] static auto task_due() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "task-due" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "task-due".
      [[nodiscard]] static auto task_due(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "task-past-due".
      /// @return The xtd::drawing::image "task-past-due".
      [[nodiscard]] static auto task_past_due() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "task-past-due" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "task-past-due".
      [[nodiscard]] static auto task_past_due(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "user-available".
      /// @return The xtd::drawing::image "user-available".
      [[nodiscard]] static auto user_available() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "user-available" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-available".
      [[nodiscard]] static auto user_available(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "user-away".
      /// @return The xtd::drawing::image "user-away".
      [[nodiscard]] static auto user_away() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "user-away" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-away".
      [[nodiscard]] static auto user_away(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "user-idle".
      /// @return The xtd::drawing::image "user-idle".
      [[nodiscard]] static auto user_idle() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "user-idle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-idle".
      [[nodiscard]] static auto user_idle(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "user-offline".
      /// @return The xtd::drawing::image "user-offline".
      [[nodiscard]] static auto user_offline() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "user-offline" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-offline".
      [[nodiscard]] static auto user_offline(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "user-trash-full".
      /// @return The xtd::drawing::image "user-trash-full".
      [[nodiscard]] static auto user_trash_full() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "user-trash-full" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-trash-full".
      [[nodiscard]] static auto user_trash_full(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-clear".
      /// @return The xtd::drawing::image "weather-clear".
      [[nodiscard]] static auto weather_clear() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-clear" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-clear".
      [[nodiscard]] static auto weather_clear(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-clear-night".
      /// @return The xtd::drawing::image "weather-clear-night".
      [[nodiscard]] static auto weather_clear_night() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-clear-night" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-clear-night".
      [[nodiscard]] static auto weather_clear_night(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-few-clouds".
      /// @return The xtd::drawing::image "weather-few-clouds".
      [[nodiscard]] static auto weather_few_clouds() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-few-clouds" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-few-clouds".
      [[nodiscard]] static auto weather_few_clouds(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-few-clouds-night".
      /// @return The xtd::drawing::image "weather-few-clouds-night".
      [[nodiscard]] static auto weather_few_clouds_night() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-few-clouds-night" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-few-clouds-night".
      [[nodiscard]] static auto weather_few_clouds_night(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-fog".
      /// @return The xtd::drawing::image "weather-fog".
      [[nodiscard]] static auto weather_fog() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-fog" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-fog".
      [[nodiscard]] static auto weather_fog(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-overcast".
      /// @return The xtd::drawing::image "weather-overcast".
      [[nodiscard]] static auto weather_overcast() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-overcast" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-overcast".
      [[nodiscard]] static auto weather_overcast(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-severe-alert".
      /// @return The xtd::drawing::image "weather-severe-alert".
      [[nodiscard]] static auto weather_severe_alert() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-severe-alert" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-severe-alert".
      [[nodiscard]] static auto weather_severe_alert(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-showers".
      /// @return The xtd::drawing::image "weather-showers".
      [[nodiscard]] static auto weather_showers() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-showers" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-showers".
      [[nodiscard]] static auto weather_showers(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-showers-scattered".
      /// @return The xtd::drawing::image "weather-showers-scattered".
      [[nodiscard]] static auto weather_showers_scattered() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-showers-scattered" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-showers-scattered".
      [[nodiscard]] static auto weather_showers_scattered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-snow".
      /// @return The xtd::drawing::image "weather-snow".
      [[nodiscard]] static auto weather_snow() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-snow" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-snow".
      [[nodiscard]] static auto weather_snow(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the status system image "weather-storm".
      /// @return The xtd::drawing::image "weather-storm".
      [[nodiscard]] static auto weather_storm() noexcept -> xtd::drawing::image;
      /// @brief Gets the status system image "weather-storm" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-storm".
      [[nodiscard]] static auto weather_storm(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
