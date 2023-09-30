/// @file
/// @brief Contains xtd::drawing::mimetypes_system_images factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::mimetypes_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ mimetypes_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::mimetypes_system_images
    /// @par Header
    /// @code #include <xtd/drawing/mimetypes_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ mimetypes_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the mimetypes system image "application-x-executable".
      /// @return The xtd::drawing::image "application-x-executable".
      static xtd::drawing::image application_x_executable() noexcept;
      /// @brief Gets the mimetypes system image "application-x-executable" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "application-x-executable".
      static xtd::drawing::image application_x_executable(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "audio-x-generic".
      /// @return The xtd::drawing::image "audio-x-generic".
      static xtd::drawing::image audio_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "audio-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "audio-x-generic".
      static xtd::drawing::image audio_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "font-x-generic".
      /// @return The xtd::drawing::image "font-x-generic".
      static xtd::drawing::image font_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "font-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "font-x-generic".
      static xtd::drawing::image font_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "image-x-generic".
      /// @return The xtd::drawing::image "image-x-generic".
      static xtd::drawing::image image_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "image-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "image-x-generic".
      static xtd::drawing::image image_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "package-x-generic".
      /// @return The xtd::drawing::image "package-x-generic".
      static xtd::drawing::image package_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "package-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "package-x-generic".
      static xtd::drawing::image package_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "text-html".
      /// @return The xtd::drawing::image "text-html".
      static xtd::drawing::image text_html() noexcept;
      /// @brief Gets the mimetypes system image "text-html" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-html".
      static xtd::drawing::image text_html(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "text-x-generic".
      /// @return The xtd::drawing::image "text-x-generic".
      static xtd::drawing::image text_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "text-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-generic".
      static xtd::drawing::image text_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "text-x-generic-template".
      /// @return The xtd::drawing::image "text-x-generic-template".
      static xtd::drawing::image text_x_generic_template() noexcept;
      /// @brief Gets the mimetypes system image "text-x-generic-template" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-generic-template".
      static xtd::drawing::image text_x_generic_template(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "text-x-script".
      /// @return The xtd::drawing::image "text-x-script".
      static xtd::drawing::image text_x_script() noexcept;
      /// @brief Gets the mimetypes system image "text-x-script" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-script".
      static xtd::drawing::image text_x_script(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "video-x-generic".
      /// @return The xtd::drawing::image "video-x-generic".
      static xtd::drawing::image video_x_generic() noexcept;
      /// @brief Gets the mimetypes system image "video-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "video-x-generic".
      static xtd::drawing::image video_x_generic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-address-book".
      /// @return The xtd::drawing::image "x-office-address-book".
      static xtd::drawing::image x_office_address_book() noexcept;
      /// @brief Gets the mimetypes system image "x-office-address-book" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-address-book".
      static xtd::drawing::image x_office_address_book(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-calendar".
      /// @return The xtd::drawing::image "x-office-calendar".
      static xtd::drawing::image x_office_calendar() noexcept;
      /// @brief Gets the mimetypes system image "x-office-calendar" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-calendar".
      static xtd::drawing::image x_office_calendar(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-contact".
      /// @return The xtd::drawing::image "x-office-contact".
      static xtd::drawing::image x_office_contact() noexcept;
      /// @brief Gets the mimetypes system image "x-office-contact" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-contact".
      static xtd::drawing::image x_office_contact(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-document".
      /// @return The xtd::drawing::image "x-office-document".
      static xtd::drawing::image x_office_document() noexcept;
      /// @brief Gets the mimetypes system image "x-office-document" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-document".
      static xtd::drawing::image x_office_document(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-presentation".
      /// @return The xtd::drawing::image "x-office-presentation".
      static xtd::drawing::image x_office_presentation() noexcept;
      /// @brief Gets the mimetypes system image "x-office-presentation" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-presentation".
      static xtd::drawing::image x_office_presentation(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the mimetypes system image "x-office-spreadsheet".
      /// @return The xtd::drawing::image "x-office-spreadsheet".
      static xtd::drawing::image x_office_spreadsheet() noexcept;
      /// @brief Gets the mimetypes system image "x-office-spreadsheet" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-spreadsheet".
      static xtd::drawing::image x_office_spreadsheet(const xtd::drawing::size& size) noexcept;

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
