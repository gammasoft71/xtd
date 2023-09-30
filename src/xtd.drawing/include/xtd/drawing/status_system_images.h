/// @file
/// @brief Contains xtd::drawing::status_system_images factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::status_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ status_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::status_system_images
    /// @par Header
    /// @code #include <xtd/drawing/status_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ status_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the status system image "appointment-missed".
      /// @return The xtd::drawing::image "appointment-missed".
      static xtd::drawing::image appointment_missed() noexcept;
      /// @brief Gets the status system image "appointment-missed" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "appointment-missed".
      static xtd::drawing::image appointment_missed(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "appointment-soon".
      /// @return The xtd::drawing::image "appointment-soon".
      static xtd::drawing::image appointment_soon() noexcept;
      /// @brief Gets the status system image "appointment-soon" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "appointment-soon".
      static xtd::drawing::image appointment_soon(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "audio-volume-high".
      /// @return The xtd::drawing::image "audio-volume-high".
      static xtd::drawing::image audio_volume_high() noexcept;
      /// @brief Gets the status system image "audio-volume-high" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-high".
      static xtd::drawing::image audio_volume_high(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "audio-volume-low".
      /// @return The xtd::drawing::image "audio-volume-low".
      static xtd::drawing::image audio_volume_low() noexcept;
      /// @brief Gets the status system image "audio-volume-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-low".
      static xtd::drawing::image audio_volume_low(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "audio-volume-medium".
      /// @return The xtd::drawing::image "audio-volume-medium".
      static xtd::drawing::image audio_volume_medium() noexcept;
      /// @brief Gets the status system image "audio-volume-medium" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-medium".
      static xtd::drawing::image audio_volume_medium(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "audio-volume-muted".
      /// @return The xtd::drawing::image "audio-volume-muted".
      static xtd::drawing::image audio_volume_muted() noexcept;
      /// @brief Gets the status system image "audio-volume-muted" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "audio-volume-muted".
      static xtd::drawing::image audio_volume_muted(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "battery-caution".
      /// @return The xtd::drawing::image "battery-caution".
      static xtd::drawing::image battery_caution() noexcept;
      /// @brief Gets the status system image "battery-caution" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "battery-caution".
      static xtd::drawing::image battery_caution(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "battery-low".
      /// @return The xtd::drawing::image "battery-low".
      static xtd::drawing::image battery_low() noexcept;
      /// @brief Gets the status system image "battery-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "battery-low".
      static xtd::drawing::image battery_low(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "dialog-error".
      /// @return The xtd::drawing::image "dialog-error".
      static xtd::drawing::image dialog_error() noexcept;
      /// @brief Gets the status system image "dialog-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-error".
      static xtd::drawing::image dialog_error(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "dialog-information".
      /// @return The xtd::drawing::image "dialog-information".
      static xtd::drawing::image dialog_information() noexcept;
      /// @brief Gets the status system image "dialog-information" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-information".
      static xtd::drawing::image dialog_information(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "dialog-password".
      /// @return The xtd::drawing::image "dialog-password".
      static xtd::drawing::image dialog_password() noexcept;
      /// @brief Gets the status system image "dialog-password" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-password".
      static xtd::drawing::image dialog_password(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "dialog-question".
      /// @return The xtd::drawing::image "dialog-question".
      static xtd::drawing::image dialog_question() noexcept;
      /// @brief Gets the status system image "dialog-question" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-question".
      static xtd::drawing::image dialog_question(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "dialog-warning".
      /// @return The xtd::drawing::image "dialog-warning".
      static xtd::drawing::image dialog_warning() noexcept;
      /// @brief Gets the status system image "dialog-warning" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "dialog-warning".
      static xtd::drawing::image dialog_warning(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "folder-drag-accept".
      /// @return The xtd::drawing::image "folder-drag-accept".
      static xtd::drawing::image folder_drag_accept() noexcept;
      /// @brief Gets the status system image "folder-drag-accept" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-drag-accept".
      static xtd::drawing::image folder_drag_accept(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "folder-open".
      /// @return The xtd::drawing::image "folder-open".
      static xtd::drawing::image folder_open() noexcept;
      /// @brief Gets the status system image "folder-open" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-open".
      static xtd::drawing::image folder_open(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "folder-visiting".
      /// @return The xtd::drawing::image "folder-visiting".
      static xtd::drawing::image folder_visiting() noexcept;
      /// @brief Gets the status system image "folder-visiting" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "folder-visiting".
      static xtd::drawing::image folder_visiting(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "image-loading".
      /// @return The xtd::drawing::image "image-loading".
      static xtd::drawing::image image_loading() noexcept;
      /// @brief Gets the status system image "image-loading" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "image-loading".
      static xtd::drawing::image image_loading(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "image-missing".
      /// @return The xtd::drawing::image "image-missing".
      static xtd::drawing::image image_missing() noexcept;
      /// @brief Gets the status system image "image-missing" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "image-missing".
      static xtd::drawing::image image_missing(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-attachment".
      /// @return The xtd::drawing::image "mail-attachment".
      static xtd::drawing::image mail_attachment() noexcept;
      /// @brief Gets the status system image "mail-attachment" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-attachment".
      static xtd::drawing::image mail_attachment(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-unread".
      /// @return The xtd::drawing::image "mail-unread".
      static xtd::drawing::image mail_unread() noexcept;
      /// @brief Gets the status system image "mail-unread" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-unread".
      static xtd::drawing::image mail_unread(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-read".
      /// @return The xtd::drawing::image "mail-read".
      static xtd::drawing::image mail_read() noexcept;
      /// @brief Gets the status system image "mail-read" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-read".
      static xtd::drawing::image mail_read(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-replied".
      /// @return The xtd::drawing::image "mail-replied".
      static xtd::drawing::image mail_replied() noexcept;
      /// @brief Gets the status system image "mail-replied" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-replied".
      static xtd::drawing::image mail_replied(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-signed".
      /// @return The xtd::drawing::image "mail-signed".
      static xtd::drawing::image mail_signed() noexcept;
      /// @brief Gets the status system image "mail-signed" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-signed".
      static xtd::drawing::image mail_signed(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "mail-signed-verified".
      /// @return The xtd::drawing::image "mail-signed-verified".
      static xtd::drawing::image mail_signed_verified() noexcept;
      /// @brief Gets the status system image "mail-signed-verified" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "mail-signed-verified".
      static xtd::drawing::image mail_signed_verified(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "media-playlist-repeat".
      /// @return The xtd::drawing::image "media-playlist-repeat".
      static xtd::drawing::image media_playlist_repeat() noexcept;
      /// @brief Gets the status system image "media-playlist-repeat" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "media-playlist-repeat".
      static xtd::drawing::image media_playlist_repeat(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "media-playlist-shuffle".
      /// @return The xtd::drawing::image "media-playlist-shuffle".
      static xtd::drawing::image media_playlist_shuffle() noexcept;
      /// @brief Gets the status system image "media-playlist-shuffle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "media-playlist-shuffle".
      static xtd::drawing::image media_playlist_shuffle(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-error".
      /// @return The xtd::drawing::image "network-error".
      static xtd::drawing::image network_error() noexcept;
      /// @brief Gets the status system image "network-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-error".
      static xtd::drawing::image network_error(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-idle".
      /// @return The xtd::drawing::image "network-idle".
      static xtd::drawing::image network_idle() noexcept;
      /// @brief Gets the status system image "network-idle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-idle".
      static xtd::drawing::image network_idle(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-offline".
      /// @return The xtd::drawing::image "network-offline".
      static xtd::drawing::image network_offline() noexcept;
      /// @brief Gets the status system image "network-offline" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-offline".
      static xtd::drawing::image network_offline(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-receive".
      /// @return The xtd::drawing::image "network-receive".
      static xtd::drawing::image network_receive() noexcept;
      /// @brief Gets the status system image "network-receive" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-receive".
      static xtd::drawing::image network_receive(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-transmit".
      /// @return The xtd::drawing::image "network-transmit".
      static xtd::drawing::image network_transmit() noexcept;
      /// @brief Gets the status system image "network-transmit" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-transmit".
      static xtd::drawing::image network_transmit(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "network-transmit-receive".
      /// @return The xtd::drawing::image "network-transmit-receive".
      static xtd::drawing::image network_transmit_receive() noexcept;
      /// @brief Gets the status system image "network-transmit-receive" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "network-transmit-receive".
      static xtd::drawing::image network_transmit_receive(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "printer-error".
      /// @return The xtd::drawing::image "printer-error".
      static xtd::drawing::image printer_error() noexcept;
      /// @brief Gets the status system image "printer-error" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "printer-error".
      static xtd::drawing::image printer_error(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "printer-printing".
      /// @return The xtd::drawing::image "printer-printing".
      static xtd::drawing::image printer_printing() noexcept;
      /// @brief Gets the status system image "printer-printing" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "printer-printing".
      static xtd::drawing::image printer_printing(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "security-high".
      /// @return The xtd::drawing::image "security-high".
      static xtd::drawing::image security_high() noexcept;
      /// @brief Gets the status system image "security-high" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-high".
      static xtd::drawing::image security_high(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "security-medium".
      /// @return The xtd::drawing::image "security-medium".
      static xtd::drawing::image security_medium() noexcept;
      /// @brief Gets the status system image "security-medium" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-medium".
      static xtd::drawing::image security_medium(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "security-low".
      /// @return The xtd::drawing::image "security-low".
      static xtd::drawing::image security_low() noexcept;
      /// @brief Gets the status system image "security-low" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "security-low".
      static xtd::drawing::image security_low(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "software-update-available".
      /// @return The xtd::drawing::image "software-update-available".
      static xtd::drawing::image software_update_available() noexcept;
      /// @brief Gets the status system image "software-update-available" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "software-update-available".
      static xtd::drawing::image software_update_available(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "software-update-urgent".
      /// @return The xtd::drawing::image "software-update-urgent".
      static xtd::drawing::image software_update_urgent() noexcept;
      /// @brief Gets the status system image "software-update-urgent" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "software-update-urgent".
      static xtd::drawing::image software_update_urgent(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "task-due".
      /// @return The xtd::drawing::image "task-due".
      static xtd::drawing::image task_due() noexcept;
      /// @brief Gets the status system image "task-due" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "task-due".
      static xtd::drawing::image task_due(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "task-past-due".
      /// @return The xtd::drawing::image "task-past-due".
      static xtd::drawing::image task_past_due() noexcept;
      /// @brief Gets the status system image "task-past-due" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "task-past-due".
      static xtd::drawing::image task_past_due(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "user-available".
      /// @return The xtd::drawing::image "user-available".
      static xtd::drawing::image user_available() noexcept;
      /// @brief Gets the status system image "user-available" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-available".
      static xtd::drawing::image user_available(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "user-away".
      /// @return The xtd::drawing::image "user-away".
      static xtd::drawing::image user_away() noexcept;
      /// @brief Gets the status system image "user-away" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-away".
      static xtd::drawing::image user_away(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "user-idle".
      /// @return The xtd::drawing::image "user-idle".
      static xtd::drawing::image user_idle() noexcept;
      /// @brief Gets the status system image "user-idle" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-idle".
      static xtd::drawing::image user_idle(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "user-offline".
      /// @return The xtd::drawing::image "user-offline".
      static xtd::drawing::image user_offline() noexcept;
      /// @brief Gets the status system image "user-offline" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-offline".
      static xtd::drawing::image user_offline(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "user-trash-full".
      /// @return The xtd::drawing::image "user-trash-full".
      static xtd::drawing::image user_trash_full() noexcept;
      /// @brief Gets the status system image "user-trash-full" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "user-trash-full".
      static xtd::drawing::image user_trash_full(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-clear".
      /// @return The xtd::drawing::image "weather-clear".
      static xtd::drawing::image weather_clear() noexcept;
      /// @brief Gets the status system image "weather-clear" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-clear".
      static xtd::drawing::image weather_clear(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-clear-night".
      /// @return The xtd::drawing::image "weather-clear-night".
      static xtd::drawing::image weather_clear_night() noexcept;
      /// @brief Gets the status system image "weather-clear-night" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-clear-night".
      static xtd::drawing::image weather_clear_night(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-few-clouds".
      /// @return The xtd::drawing::image "weather-few-clouds".
      static xtd::drawing::image weather_few_clouds() noexcept;
      /// @brief Gets the status system image "weather-few-clouds" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-few-clouds".
      static xtd::drawing::image weather_few_clouds(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-few-clouds-night".
      /// @return The xtd::drawing::image "weather-few-clouds-night".
      static xtd::drawing::image weather_few_clouds_night() noexcept;
      /// @brief Gets the status system image "weather-few-clouds-night" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-few-clouds-night".
      static xtd::drawing::image weather_few_clouds_night(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-fog".
      /// @return The xtd::drawing::image "weather-fog".
      static xtd::drawing::image weather_fog() noexcept;
      /// @brief Gets the status system image "weather-fog" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-fog".
      static xtd::drawing::image weather_fog(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-overcast".
      /// @return The xtd::drawing::image "weather-overcast".
      static xtd::drawing::image weather_overcast() noexcept;
      /// @brief Gets the status system image "weather-overcast" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-overcast".
      static xtd::drawing::image weather_overcast(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-severe-alert".
      /// @return The xtd::drawing::image "weather-severe-alert".
      static xtd::drawing::image weather_severe_alert() noexcept;
      /// @brief Gets the status system image "weather-severe-alert" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-severe-alert".
      static xtd::drawing::image weather_severe_alert(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-showers".
      /// @return The xtd::drawing::image "weather-showers".
      static xtd::drawing::image weather_showers() noexcept;
      /// @brief Gets the status system image "weather-showers" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-showers".
      static xtd::drawing::image weather_showers(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-showers-scattered".
      /// @return The xtd::drawing::image "weather-showers-scattered".
      static xtd::drawing::image weather_showers_scattered() noexcept;
      /// @brief Gets the status system image "weather-showers-scattered" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-showers-scattered".
      static xtd::drawing::image weather_showers_scattered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-snow".
      /// @return The xtd::drawing::image "weather-snow".
      static xtd::drawing::image weather_snow() noexcept;
      /// @brief Gets the status system image "weather-snow" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-snow".
      static xtd::drawing::image weather_snow(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the status system image "weather-storm".
      /// @return The xtd::drawing::image "weather-storm".
      static xtd::drawing::image weather_storm() noexcept;
      /// @brief Gets the status system image "weather-storm" with specified size.
      /// @param size The status system image size in pixels.
      /// @return The xtd::drawing::image "weather-storm".
      static xtd::drawing::image weather_storm(const xtd::drawing::size& size) noexcept;

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
