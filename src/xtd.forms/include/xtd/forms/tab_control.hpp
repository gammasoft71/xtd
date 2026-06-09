/// @file
/// @brief Contains xtd::forms::tab_control container.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#include "const_tab_page_ref.hpp"
#include "control.hpp"
#include "image_list.hpp"
#include "tab_alignment.hpp"
#include "tab_page_ref.hpp"
#include <xtd/usize_object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Manages a related set of tab pages.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/tab_control>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html containers_tab_control_w.png   |  @image html containers_tab_control_m.png   |  @image html containers_tab_control_g.png   |
    /// | Dark  |  @image html containers_tab_control_wd.png  |  @image html containers_tab_control_md.png  |  @image html containers_tab_control_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of tab_control container.
    /// @include tab_control.cpp
    class forms_export_ tab_control : public xtd::forms::control {
      struct data;
      
    public:
      /// @brief Represents a collection of controls.
      class tab_page_collection : public xtd::forms::layout::arranged_element_collection<tab_page_ref> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<tab_page_ref>;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::control::tab_page_collection with specified allocator (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit tab_page_collection() = default;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::add;
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        auto add(const xtd::string& text) -> void;
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        /// @param name The name of element to add.
        auto add(const xtd::string& text, const string& name) -> void;
        
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::insert;
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        auto insert(xtd::usize index, const xtd::string& text) -> void;
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        /// @param name The name of element to insert.
        auto insert(xtd::usize index, const xtd::string& text, const xtd::string& name) -> void;
        /// @}
        
        /// @cond
        auto add(const char* text) -> void;
        auto add(const char8* text) -> void;
        auto add(const char16* text) -> void;
        auto add(const char32* text) -> void;
        auto add(const wchar* text) -> void;
        /// @endcond
        
        /// @name Operators
        
        /// @{
        using base::operator [];
        /// @brief Gets the first xtd::forms::control::tab_page_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        [[nodiscard]] auto operator [](const xtd::string& name) const -> std::optional<value_type>;
        /// @brief Gets the first xtd::forms::control::tab_page_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        [[nodiscard]] auto operator [](const xtd::string& name) -> std::optional<value_type>;
        /// @}
        
        /// @name Public Deprecated Methods
        
        /// @{
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param text The text of element to insert.
        /// @deprecated Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.")]]
        [[nodiscard]] auto insert(const_iterator pos, const xtd::string& text) -> iterator;
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param text The text of element to insert.
        /// @param name The name of element to insert.
        /// @deprecated Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.")]]
        [[nodiscard]] auto insert(const_iterator pos, const xtd::string& text, const xtd::string& name) -> iterator;
        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::insert_at;
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        /// @deprecated Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.")]]
        auto insert_at(xtd::usize index, const xtd::string& text) -> void;
        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param text The text of element to insert.
        /// @param name The name of element to insert.
        /// @deprecated Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::layout::tab_page_collection::insert - Will be removed in version 1.2.0.")]]
        auto insert_at(xtd::usize index, const xtd::string& text, const xtd::string& name) -> void;

        using xtd::forms::layout::arranged_element_collection<tab_page_ref>::push_back;
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        /// @deprecated Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const xtd::string& text) -> void;
        /// @brief Adds an element to the end.
        /// @param text The text of element to add.
        /// @param name The name of element to add.
        /// @deprecated Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const xtd::string& text, const string& name) -> void;
        
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const char* text) -> void;
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const char8* text) -> void;
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const char16* text) -> void;
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const char32* text) -> void;
        [[deprecated("Replaced by xtd::forms::tab_control::tab_page_collection::add - Will be removed in version 1.2.0.")]]
        auto push_back(const wchar* text) -> void;
        /// @}
        
      private:
        friend tab_control;
        xtd::event<tab_page_collection, xtd::delegate<void(xtd::usize index, const xtd::string& text, const xtd::string& name)>> text_added;
        xtd::event<tab_page_collection, xtd::delegate<iterator(const_iterator pos, const xtd::string& text, const xtd::string& name)>> text_inserted;
      };
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the tab_control class.
      tab_control();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the area of the control (for example, along the top) where the tabs are aligned.
      /// @return One of the xtd::forms::tab_alignment values. The default is top.
      [[nodiscard]] virtual auto alignment() const noexcept -> xtd::forms::tab_alignment;
      /// @brief Sets the area of the control (for example, along the top) where the tabs are aligned.
      /// @param value One of the xtd::forms::tab_alignment values. The default is top.
      /// @return Current tab_control instance.
      virtual auto alignment(xtd::forms::tab_alignment value) -> tab_control&;
      
      /// @brief Gets the images to display on the control's tabs.
      /// @return An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      [[nodiscard]] virtual auto image_list() const noexcept -> const xtd::forms::image_list&;
      /// @brief Sets the images to display on the control's tabs.
      /// @param value An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @return Current tab_control instance.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual auto image_list(const forms::image_list& value) -> tab_control&;
      
      /// @brief Gets the index of the currently selected tab page.
      /// @return The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      [[nodiscard]] virtual auto selected_index() const noexcept -> xtd::usize;
      /// @brief Sets the index of the currently selected tab page.
      /// @param value The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      /// @return Current tab_control instance.
      virtual auto selected_index(xtd::usize value) -> tab_control&;
      
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A tab_page_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      [[nodiscard]] virtual auto tab_pages() noexcept -> tab_page_collection&;
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A tab_page_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      [[nodiscard]] virtual auto tab_pages() const noexcept -> const tab_page_collection&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create() -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @param name The name of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::tab_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::tab_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> tab_control;
      /// @brief A factory to create an xtd::forms::tab_control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::tab_control.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::tab_control.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::tab_control.
      /// @param name The name of the xtd::forms::tab_control.
      /// @return New xtd::forms::tab_control created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> tab_control;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the selected_index property has changed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<tab_control, xtd::event_handler> selected_index_changed;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      auto on_control_added(const xtd::forms::control_event_args& e) -> void override;
      auto on_control_removed(const xtd::forms::control_event_args& e) -> void override;
      
      auto on_handle_created(const xtd::event_args& e) -> void override;
      
      /// @brief Raises the tab_control::selected_index_changed event.
      /// @param An xtd::event_args that contains the event data.
      virtual auto on_selected_index_changed(const xtd::event_args& e) -> void;
      
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
      /// @cond
      friend class tab_page;
      [[nodiscard]] auto get_child_index(xtd::intptr page) -> xtd::usize;
      /// @endcond
      
    private:
      friend class xtd::forms::form;
      using control::controls;
      
      auto wm_command_control(xtd::forms::message& message) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
