/// @file
/// @brief Contains xtd::forms::image_list component.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "component.h"
#include <xtd/any>
#include <xtd/iequatable>
#include <xtd/drawing/image>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides methods to manage a collection of xtd::drawing::image objects. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/image_list> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks image_list is typically used by other controls, such as the list_view, tree_view, or tool_bar. You can add bitmaps or icons to the image_list, and the other controls are able to use the images as they require.
    /// @remarks image_list uses a handle to manage the list of images. The handle is not created until certain operations, such as getting the handle or calling draw, are performed on the image list. Performing other operations, such as setting the color_depth or image_size will cause the handle to be recreated. Therefore, you should perform these operations before you add images to the image_list.
    /// @par Examples
    /// The following code example demonstrates the use of image_list class.
    /// @include image_list.cpp
    class forms_export_ image_list final : public component, public xtd::iequatable<image_list> {
      struct data;
      
    public:
      /// @name Alias
      
      /// @{
      /// @brief Encapsulates the collection of xtd::drawing::image objects in an image_list.
      using image_collection = layout::arranged_element_collection<drawing::image>;
      /// @}
      
      /// @name Fields
      
      /// @{
      /// @brief Represents an image_list empty.
      static image_list empty;
      
      inline static const size_t npos = image_collection::npos;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance ao image_list class.
      image_list();
      /// @}
      
      /// @cond
      ~image_list();
      image_list(const image_list&) = default;
      image_list& operator =(const image_list&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the handle of the image list object.
      /// @return The handle for the image list. The default is 0.
      intptr handle() const noexcept;
      
      /// @brief Gets a value indicating whether the underlying Win32 handle has been created.
      /// @return true if the Handle has been created; otherwise, false. The default is false.
      bool handle_created() const noexcept;
      
      /// @brief Gets the xtd::forms::image_list::image_collection for this image list.
      /// @return The collection of images.
      /// @remarks If the image collection has not yet been created, it is created when you retrieve this property.
      image_collection& images();
      /// @brief Gets the xtd::forms::image_list::image_collection for this image list.
      /// @return The collection of images.
      /// @remarks If the image collection has not yet been created, it is created when you retrieve this property.
      const image_collection& images() const noexcept;
      
      /// @brief Gets the size of the images in the image list.
      /// @return The xtd::drawing::size that defines the height and width, in pixels, of the images in the list. The default size is 16 by 16. The maximum size is 256 by 256.
      const drawing::size image_size() const noexcept;
      /// @brief Sets the size of the images in the image list.
      /// @param value The xtd::drawing::size that defines the height and width, in pixels, of the images in the list. The default size is 16 by 16. The maximum size is 256 by 256.
      /// @remarks Setting the image_size property prior to adding images to the image collection causes the images to be resized to the image size specified.
      /// @remarks When you set the image_size property to a new value, the handle for the image list is recreated.
      /// @remarks Because setting the image_size property causes the handle to be recreated, you should set image_size prior to setting the Images property. When the handle for the image_list has been created, setting the color_depth or image_size properties in code, after setting the images property, will cause the collection of images set for the images property to be deleted.
      const image_list& image_size(const drawing::size& value);
      
      /// @brief Gets an object that contains additional data about the image_list.
      /// @return A object that contains additional data about the image_list.
      std::any tag() const noexcept;
      /// @brief Sets an object that contains additional data about the image_list.
      /// @param tag A object that contains additional data about the image_list.
      image_list& tag(const std::any& tag);
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const image_list& value) const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
