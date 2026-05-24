/// @file
/// @brief Contains xtd::drawing::mimetypes_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::mimetypes_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ mimetypes_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::mimetypes_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/mimetypes_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ mimetypes_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the mimetypes system image "application-x-executable".
      /// @return The xtd::drawing::image "application-x-executable".
      [[nodiscard]] static auto application_x_executable() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "application-x-executable" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "application-x-executable".
      [[nodiscard]] static auto application_x_executable(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "audio-x-generic".
      /// @return The xtd::drawing::image "audio-x-generic".
      [[nodiscard]] static auto audio_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "audio-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "audio-x-generic".
      [[nodiscard]] static auto audio_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "font-x-generic".
      /// @return The xtd::drawing::image "font-x-generic".
      [[nodiscard]] static auto font_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "font-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "font-x-generic".
      [[nodiscard]] static auto font_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "image-x-generic".
      /// @return The xtd::drawing::image "image-x-generic".
      [[nodiscard]] static auto image_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "image-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "image-x-generic".
      [[nodiscard]] static auto image_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "package-x-generic".
      /// @return The xtd::drawing::image "package-x-generic".
      [[nodiscard]] static auto package_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "package-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "package-x-generic".
      [[nodiscard]] static auto package_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "text-html".
      /// @return The xtd::drawing::image "text-html".
      [[nodiscard]] static auto text_html() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "text-html" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-html".
      [[nodiscard]] static auto text_html(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "text-x-generic".
      /// @return The xtd::drawing::image "text-x-generic".
      [[nodiscard]] static auto text_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "text-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-generic".
      [[nodiscard]] static auto text_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "text-x-generic-template".
      /// @return The xtd::drawing::image "text-x-generic-template".
      [[nodiscard]] static auto text_x_generic_template() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "text-x-generic-template" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-generic-template".
      [[nodiscard]] static auto text_x_generic_template(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "text-x-script".
      /// @return The xtd::drawing::image "text-x-script".
      [[nodiscard]] static auto text_x_script() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "text-x-script" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "text-x-script".
      [[nodiscard]] static auto text_x_script(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "video-x-generic".
      /// @return The xtd::drawing::image "video-x-generic".
      [[nodiscard]] static auto video_x_generic() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "video-x-generic" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "video-x-generic".
      [[nodiscard]] static auto video_x_generic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-address-book".
      /// @return The xtd::drawing::image "x-office-address-book".
      [[nodiscard]] static auto x_office_address_book() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-address-book" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-address-book".
      [[nodiscard]] static auto x_office_address_book(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-calendar".
      /// @return The xtd::drawing::image "x-office-calendar".
      [[nodiscard]] static auto x_office_calendar() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-calendar" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-calendar".
      [[nodiscard]] static auto x_office_calendar(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-contact".
      /// @return The xtd::drawing::image "x-office-contact".
      [[nodiscard]] static auto x_office_contact() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-contact" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-contact".
      [[nodiscard]] static auto x_office_contact(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-document".
      /// @return The xtd::drawing::image "x-office-document".
      [[nodiscard]] static auto x_office_document() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-document" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-document".
      [[nodiscard]] static auto x_office_document(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-presentation".
      /// @return The xtd::drawing::image "x-office-presentation".
      [[nodiscard]] static auto x_office_presentation() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-presentation" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-presentation".
      [[nodiscard]] static auto x_office_presentation(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the mimetypes system image "x-office-spreadsheet".
      /// @return The xtd::drawing::image "x-office-spreadsheet".
      [[nodiscard]] static auto x_office_spreadsheet() noexcept -> xtd::drawing::image;
      /// @brief Gets the mimetypes system image "x-office-spreadsheet" with specified size.
      /// @param size The mimetypes system image size in pixels.
      /// @return The xtd::drawing::image "x-office-spreadsheet".
      [[nodiscard]] static auto x_office_spreadsheet(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
