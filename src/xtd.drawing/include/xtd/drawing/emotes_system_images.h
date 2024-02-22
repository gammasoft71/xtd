/// @file
/// @brief Contains xtd::drawing::emotes_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::emotes_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ emotes_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::emotes_system_images
    /// @par Header
    /// @code #include <xtd/drawing/emotes_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ emotes_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the emotes system image "face-angel".
      /// @return The xtd::drawing::image "face-angel".
      static xtd::drawing::image face_angel() noexcept;
      /// @brief Gets the emotes system image "face-angel" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-angel".
      static xtd::drawing::image face_angel(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-angry".
      /// @return The xtd::drawing::image "face-angry".
      static xtd::drawing::image face_angry() noexcept;
      /// @brief Gets the emotes system image "face-angry" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-angry".
      static xtd::drawing::image face_angry(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-cool".
      /// @return The xtd::drawing::image "face-cool".
      static xtd::drawing::image face_cool() noexcept;
      /// @brief Gets the emotes system image "face-cool" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-cool".
      static xtd::drawing::image face_cool(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-crying".
      /// @return The xtd::drawing::image "face-crying".
      static xtd::drawing::image face_crying() noexcept;
      /// @brief Gets the emotes system image "face-crying" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-crying".
      static xtd::drawing::image face_crying(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-devilish".
      /// @return The xtd::drawing::image "face-devilish".
      static xtd::drawing::image face_devilish() noexcept;
      /// @brief Gets the emotes system image "face-devilish" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-devilish".
      static xtd::drawing::image face_devilish(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-embarrassed".
      /// @return The xtd::drawing::image "face-embarrassed".
      static xtd::drawing::image face_embarrassed() noexcept;
      /// @brief Gets the emotes system image "face-embarrassed" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-embarrassed".
      static xtd::drawing::image face_embarrassed(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-kiss".
      /// @return The xtd::drawing::image "face-kiss".
      static xtd::drawing::image face_kiss() noexcept;
      /// @brief Gets the emotes system image "face-kiss" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-kiss".
      static xtd::drawing::image face_kiss(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-laugh".
      /// @return The xtd::drawing::image "face-laugh".
      static xtd::drawing::image face_laugh() noexcept;
      /// @brief Gets the emotes system image "face-laugh" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-laugh".
      static xtd::drawing::image face_laugh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-monkey".
      /// @return The xtd::drawing::image "face-monkey".
      static xtd::drawing::image face_monkey() noexcept;
      /// @brief Gets the emotes system image "face-monkey" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-monkey".
      static xtd::drawing::image face_monkey(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-plain".
      /// @return The xtd::drawing::image "face-plain".
      static xtd::drawing::image face_plain() noexcept;
      /// @brief Gets the emotes system image "face-plain" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-plain".
      static xtd::drawing::image face_plain(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-raspberry".
      /// @return The xtd::drawing::image "face-raspberry".
      static xtd::drawing::image face_raspberry() noexcept;
      /// @brief Gets the emotes system image "face-raspberry" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-raspberry".
      static xtd::drawing::image face_raspberry(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-sad".
      /// @return The xtd::drawing::image "face-sad".
      static xtd::drawing::image face_sad() noexcept;
      /// @brief Gets the emotes system image "face-sad" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-sad".
      static xtd::drawing::image face_sad(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-sick".
      /// @return The xtd::drawing::image "face-sick".
      static xtd::drawing::image face_sick() noexcept;
      /// @brief Gets the emotes system image "face-sick" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-sick".
      static xtd::drawing::image face_sick(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-smile".
      /// @return The xtd::drawing::image "face-smile".
      static xtd::drawing::image face_smile() noexcept;
      /// @brief Gets the emotes system image "face-smile" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smile".
      static xtd::drawing::image face_smile(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-smile-big".
      /// @return The xtd::drawing::image "face-smile-big".
      static xtd::drawing::image face_smile_big() noexcept;
      /// @brief Gets the emotes system image "face-smile-big" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smile-big".
      static xtd::drawing::image face_smile_big(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-smirk".
      /// @return The xtd::drawing::image "face-smirk".
      static xtd::drawing::image face_smirk() noexcept;
      /// @brief Gets the emotes system image "face-smirk" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-smirk".
      static xtd::drawing::image face_smirk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-surprise".
      /// @return The xtd::drawing::image "face-surprise".
      static xtd::drawing::image face_surprise() noexcept;
      /// @brief Gets the emotes system image "face-surprise" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-surprise".
      static xtd::drawing::image face_surprise(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-tired".
      /// @return The xtd::drawing::image "face-tired".
      static xtd::drawing::image face_tired() noexcept;
      /// @brief Gets the emotes system image "face-tired" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-tired".
      static xtd::drawing::image face_tired(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-uncertain".
      /// @return The xtd::drawing::image "face-uncertain".
      static xtd::drawing::image face_uncertain() noexcept;
      /// @brief Gets the emotes system image "face-uncertain" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-uncertain".
      static xtd::drawing::image face_uncertain(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-wink".
      /// @return The xtd::drawing::image "face-wink".
      static xtd::drawing::image face_wink() noexcept;
      /// @brief Gets the emotes system image "face-wink" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-wink".
      static xtd::drawing::image face_wink(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emotes system image "face-worried".
      /// @return The xtd::drawing::image "face-worried".
      static xtd::drawing::image face_worried() noexcept;
      /// @brief Gets the emotes system image "face-worried" with specified size.
      /// @param size The emotes system image size in pixels.
      /// @return The xtd::drawing::image "face-worried".
      static xtd::drawing::image face_worried(const xtd::drawing::size& size) noexcept;

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
