/// @file
/// @brief Contains xtd::drawing::emotes_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::emotes_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ emotes_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::emotes_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/emotes_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ emotes_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the emotes system image "face-angel".
      /// @return The xtd::drawing::image "face-angel".
      [[nodiscard]] static auto face_angel() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-angel" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-angel".
      [[nodiscard]] static auto face_angel(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-angry".
      /// @return The xtd::drawing::image "face-angry".
      [[nodiscard]] static auto face_angry() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-angry" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-angry".
      [[nodiscard]] static auto face_angry(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-cool".
      /// @return The xtd::drawing::image "face-cool".
      [[nodiscard]] static auto face_cool() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-cool" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-cool".
      [[nodiscard]] static auto face_cool(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-crying".
      /// @return The xtd::drawing::image "face-crying".
      [[nodiscard]] static auto face_crying() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-crying" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-crying".
      [[nodiscard]] static auto face_crying(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-devilish".
      /// @return The xtd::drawing::image "face-devilish".
      [[nodiscard]] static auto face_devilish() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-devilish" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-devilish".
      [[nodiscard]] static auto face_devilish(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-embarrassed".
      /// @return The xtd::drawing::image "face-embarrassed".
      [[nodiscard]] static auto face_embarrassed() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-embarrassed" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-embarrassed".
      [[nodiscard]] static auto face_embarrassed(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-kiss".
      /// @return The xtd::drawing::image "face-kiss".
      [[nodiscard]] static auto face_kiss() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-kiss" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-kiss".
      [[nodiscard]] static auto face_kiss(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-laugh".
      /// @return The xtd::drawing::image "face-laugh".
      [[nodiscard]] static auto face_laugh() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-laugh" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-laugh".
      [[nodiscard]] static auto face_laugh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-monkey".
      /// @return The xtd::drawing::image "face-monkey".
      [[nodiscard]] static auto face_monkey() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-monkey" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-monkey".
      [[nodiscard]] static auto face_monkey(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-plain".
      /// @return The xtd::drawing::image "face-plain".
      [[nodiscard]] static auto face_plain() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-plain" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-plain".
      [[nodiscard]] static auto face_plain(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-raspberry".
      /// @return The xtd::drawing::image "face-raspberry".
      [[nodiscard]] static auto face_raspberry() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-raspberry" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-raspberry".
      [[nodiscard]] static auto face_raspberry(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-sad".
      /// @return The xtd::drawing::image "face-sad".
      [[nodiscard]] static auto face_sad() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-sad" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-sad".
      [[nodiscard]] static auto face_sad(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-sick".
      /// @return The xtd::drawing::image "face-sick".
      [[nodiscard]] static auto face_sick() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-sick" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-sick".
      [[nodiscard]] static auto face_sick(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-smile".
      /// @return The xtd::drawing::image "face-smile".
      [[nodiscard]] static auto face_smile() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-smile" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smile".
      [[nodiscard]] static auto face_smile(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-smile-big".
      /// @return The xtd::drawing::image "face-smile-big".
      [[nodiscard]] static auto face_smile_big() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-smile-big" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smile-big".
      [[nodiscard]] static auto face_smile_big(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-smirk".
      /// @return The xtd::drawing::image "face-smirk".
      [[nodiscard]] static auto face_smirk() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-smirk" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smirk".
      [[nodiscard]] static auto face_smirk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-surprise".
      /// @return The xtd::drawing::image "face-surprise".
      [[nodiscard]] static auto face_surprise() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-surprise" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-surprise".
      [[nodiscard]] static auto face_surprise(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-tired".
      /// @return The xtd::drawing::image "face-tired".
      [[nodiscard]] static auto face_tired() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-tired" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-tired".
      [[nodiscard]] static auto face_tired(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-uncertain".
      /// @return The xtd::drawing::image "face-uncertain".
      [[nodiscard]] static auto face_uncertain() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-uncertain" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-uncertain".
      [[nodiscard]] static auto face_uncertain(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-wink".
      /// @return The xtd::drawing::image "face-wink".
      [[nodiscard]] static auto face_wink() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-wink" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-wink".
      [[nodiscard]] static auto face_wink(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emotes system image "face-worried".
      /// @return The xtd::drawing::image "face-worried".
      [[nodiscard]] static auto face_worried() noexcept -> xtd::drawing::image;
      /// @brief Gets the emotes system image "face-worried" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-worried".
      [[nodiscard]] static auto face_worried(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
