/// @file
/// @brief Contains xtd::forms::native::image_list API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/static>
#include <xtd/drawing/image>
#include <xtd/drawing/size>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class image_list;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains image list native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ image_list final static_ {
        friend xtd::forms::image_list;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates image list.
        /// @param image_size A xtd::drawing::size image size.
        /// @return The created control window handle.
        /// @warning Internal use only
        static intptr create(const drawing::size& image_size);
        /// @brief Deletes specified image index.
        /// @param image_list image list handle.
        /// @param index The item index to delete.
        /// @warning Internal use only
        static void delete_item(intptr image_list, size_t index);
        /// @brief Destroys image list.
        /// @param image_list image list handle.
        /// @warning Internal use only
        static void destroy(intptr image_list);
        /// @brief Inserts at specified image index a specified image.
        /// @param image_list image list handle.
        /// @param index The image index to insert.
        /// @param image The xtd::drawing::image image.
        /// @warning Internal use only
        static void insert_item(intptr image_list, size_t index, const drawing::image& image);
        /// @brief Updates a specified item index with specified value.
        /// @param image_list image list handle.
        /// @param index The image index to update.
        /// @param image The xtd::drawing::image image.
        /// @warning Internal use only
        static void update_item(intptr image_list, size_t index, const drawing::image& image);
        /// @}
      };
    }
  }
}
