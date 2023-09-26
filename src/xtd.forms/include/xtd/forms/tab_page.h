/// @file
/// @brief Contains xtd::forms::tab_page container.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "image_list"
#include "panel"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a single tab page in a tab_control.
    /// @par Header
    /// @code #include <xtd/forms/tab_page> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html containers_tab_control_w.png   |  @image html containers_tab_control_m.png   |  @image html containers_tab_control_g.png   |
    /// | Dark  |  @image html containers_tab_control_wd.png  |  @image html containers_tab_control_md.png  |  @image html containers_tab_control_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of tab_page container.
    /// @include tab_control.cpp
    /// @par Examples
    /// The following code example demonstrates the use of tab_control and colored tab_page containers.
    /// @include colored_tab_pages.cpp
    class forms_export_ tab_page : public panel {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the tab_page class.
      tab_page();
      /// @}
      
      /// @name Properties
      
      /// @{
      using panel::auto_scroll;
      /// @brief Sets a value indicating whether the container enables the user to scroll to any controls placed outside of its visible boundaries.
      /// @param value true if the container enables auto-scrolling; otherwise, false. The default value is false.
      /// @return Current scrollable_control instance.
      scrollable_control& auto_scroll(bool value) override;
      
      /// @brief Gets the image list index value of the image displayed on the tab_page control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a tab_page control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the tab_page, the image_index value changes to 1.
      virtual size_t image_index() const noexcept;
      /// @brief Sets the image list index value of the image displayed on the tab_page control.
      /// @return A zero-based index, which represents the image position in an image_list. The default is -1.
      /// @remarks When the image_index or image_list properties are set, the Image property is set to its default value, xtd::drawing::image::empty.
      /// @remarks image_key and image_index are mutually exclusive, meaning if one is set, the other is set to an invalid value and ignored. If you set the image_key property, the image_index property is automatically set to -1. Alternatively, if you set the image_index property, the image_key is automatically set to an empty string ("").
      /// @remarks If the image_list property value is changed to xtd::forms::image_list::empty, the image_index property returns its default value, -1. However, the assigned image_index value is retained internally and used when another image_list object is assigned to the image_list property. If the new image_list assigned to the image_list property has an imageList::_image_collection::size property value that is less than or equal to the value assigned to the image_index property minus one (to account for the collection being a zero-based index), the image_index property value is adjusted to one less than the size property value. For example, consider a tab_page control whose image_list has three images and whose image_index property is set to 2. If a new image_list that has only two images is assigned to the tab_page, the image_index value changes to 1.
      virtual tab_page& image_index(size_t value);
      
      using panel::parent;
      control& parent(const control& parent) override;
      
      using panel::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control instance.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      using control::create;
      /// @brief A factory to create an xtd::forms::tab_page with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::tab_page.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_page.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_page.
      /// @param name The name of the xtd::forms::tab_page.
      /// @return New xtd::forms::tab_page created.
      static tab_page create(const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::tab_page with specified parent, text, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::tab_page.
      /// @param text A string that represent text of the xtd::forms::tab_page.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_page.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_page.
      /// @param name The name of the xtd::forms::tab_page.
      /// @return New xtd::forms::tab_page created.
      static tab_page create(const control& parent, const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      
      void destroy_handle() override;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
