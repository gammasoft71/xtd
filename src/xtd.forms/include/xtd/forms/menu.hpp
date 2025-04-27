/// @file
/// @brief Contains xtd::forms::menu menu.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.hpp"
#include "component.hpp"
#include "const_menu_item_ref.hpp"
#include "menu_item_ref.hpp"
#include <xtd/optional>
#include <xtd/any>
#include <xtd/iequatable>
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class context_menu;
    class main_menu;
    /// @endcond
    
    /// @brief Represents the base functionality for all menus. Although tool_strip_drop_down and tool_strip_drop_down_menu replace and add functionality to the menu control of previous versions, menu is retained for both backward compatibility and future use if you choose.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/menu>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This class is the base class for the main_menu, menu_item, and context_menu classes. You cannot create an instance of this class. The menus for an application consist of menu_item objects. These can contain other menu_item objects, representing submenu items. The menu_item objects can be stored in a main_menu for display as an entire menu structure for a form or a context_menu that is used to display shortcut menus. This class provides functionality that is common for all the menu classes.
    /// @remarks Unlike many base classes, the menu class uses its derived classes to define many of its properties. If you are using your menu in a multiple-document interface (MDI) application, you can use the mdi_list_item property to specify a menu_item that displays a list of open MDI child forms in your application. The menu_items property contains a list of menu_item objects stored in the menu class. For a main_menu or context_menu, this property contains all the menu_item objects that are displayed. For a menu_item, the menu_items property represents the submenu items associated with it.
    /// @remarks In addition to the properties that are provided for all the derived menu classes, the menu class also provides methods, such as clone_menu and merge_menu, that enable you to create new menus from existing menus, and also merge two menu structures together.
    /// @remarks The menu class also defines the nested class menu::menu_item_collection. This class defines the collection of menu_item objects used by the menu_items property. You can use the methods of the menu::menu_item_collection class to add and remove menu items from a main_menu, context_menu, or menu_item.
    class forms_export_ menu : public component, public xtd::iequatable<menu> {
      struct data;
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents a collection of menu_item objects.
      using menu_item_collection = layout::arranged_element_collection<menu_item_ref>;
      /// @}
      
      /// @name Public Fields
      
      /// @{
      /// @brief Specifies that the find_menu_item(int32, intptr) method should search for a handle.
      static constexpr int32 find_handle = 0;
      /// @brief Specifies that the find_menu_item(int32, intptr) method should search for a shortcut.
      static constexpr int32 find_shortcut = 1;
      /// @}
      
      /// @cond
      ~menu();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value representing the window handle for the menu.
      /// @return The HMENU value of the menu.
      /// @remarks You can use this property to obtain the handle to the menu to perform special operations to the menu outside of the functionality provided by this class or its derived classes.
      intptr handle() const noexcept;
      
      /// @brief Gets a value indicating whether this menu contains any menu items.
      /// @return `true` if this menu contains menu_item objects; otherwise, `false`. The default is `false`.
      virtual bool is_parent() const noexcept;
      
      /// @brief Gets a value indicating the menu_item that is used to display a list of multiple document interface (MDI) child forms.
      /// @return A MenuItem that represents the menu item displaying a list of MDI child forms that are open in the application.
      /// @remarks You can use this property to determine whether a menu_item has been specified to display the list of open child windows in an MDI application. To use a specific menu_item as an MDI list, set the mdi_list property in the menu_item to be used.
      const menu_item& mdi_list_item() const noexcept;
      
      /// @brief Gets a value indicating the collection of menu_item objects associated with the menu.
      /// @return A menu::menu_item_collection that represents the list of menu_item objects stored in the menu.
      /// @remarks You can use this property to obtain a reference to the list of menu items that are currently stored in the menu. For main_menu and context_menu objects, the menu_items property contains the entire menu structure in the control. For the menu_item class, the menu_items property contains the list of submenu items associated with the menu_item. With the reference to the collection of menu items for the menu (provided by this property), you can add and remove menu items, determine the total number of menu items, and clear the list of menu items from the collection. For more information on maintaining the menu item collection for a menu, see the xtd::forms::menu::menu_item_collection documentation.
      const menu_item_collection& menu_items() const noexcept;
      /// @brief Gets a value indicating the collection of menu_item objects associated with the menu.
      /// @return A menu::menu_item_collection that represents the list of menu_item objects stored in the menu.
      /// @remarks You can use this property to obtain a reference to the list of menu items that are currently stored in the menu. For main_menu and context_menu objects, the menu_items property contains the entire menu structure in the control. For the menu_item class, the menu_items property contains the list of submenu items associated with the menu_item. With the reference to the collection of menu items for the menu (provided by this property), you can add and remove menu items, determine the total number of menu items, and clear the list of menu items from the collection. For more information on maintaining the menu item collection for a menu, see the xtd::forms::menu::menu_item_collection documentation.
      menu_item_collection& menu_items() noexcept;
      /// @brief Sets a value indicating the collection of menu_item objects associated with the menu.
      /// @param value A menu::menu_item_collection that represents the list of menu_item objects stored in the menu.
      /// @return Current menu class.
      /// @remarks You can use this property to obtain a reference to the list of menu items that are currently stored in the menu. For main_menu and context_menu objects, the menu_items property contains the entire menu structure in the control. For the menu_item class, the menu_items property contains the list of submenu items associated with the menu_item. With the reference to the collection of menu items for the menu (provided by this property), you can add and remove menu items, determine the total number of menu items, and clear the list of menu items from the collection. For more information on maintaining the menu item collection for a menu, see the xtd::forms::menu::menu_item_collection documentation.
      menu& menu_items(const menu_item_collection& value);
      /// @cond
      menu& menu_items(const std::initializer_list<menu_item_ref>& value);
      menu& menu_items(const std::vector<menu_item_ref>& value);
      /// @endcond
      
      /// @brief Gets the name of the menu.
      /// @return A string representing the name.
      /// @remarks At design time, this property is set to the programmatic identifier of the control. However, this property has no bearing on the control at run time.
      const xtd::string& name() const noexcept;
      
      /// @brief Sets the name of the menu.
      /// @param value A string representing the name.
      /// @return Current menu class.
      /// @remarks At design time, this property is set to the programmatic identifier of the control. However, this property has no bearing on the control at run time.
      menu& name(const xtd::string& value);
      
      /// @brief Gets user-defined data associated with the control.
      /// @return An object representing the data.
      const xtd::any_object& tag() const noexcept;
      /// @brief Sets user-defined data associated with the control.
      /// @param value An object representing the data.
      /// @return Current menu class.
      menu& tag(const xtd::any_object& value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const menu& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;

      /// @brief Gets the context_menu that contains this menu.
      /// @return The context_menu that contains this menu. The default is no value.
      /// @remarks This method allows you to obtain a reference to the context_menu that this menu is contained in. This property returns no value if the menu is not contained in a context_menu. This can occur if the menu is contained in a menu_item or main_menu, or if the menu is not contained in any menu. You can use this property to determine whether a menu is currently being used, and also to determine where.
      std::optional<xtd::ref<context_menu>> get_context_menu() const noexcept;
      
      /// @brief Gets the main_menu that contains this menu.
      /// @return The main_menu that contains this menu. The default is has no value.
      /// @remarks This method allows you to obtain a reference to the main_menu that this menu is contained in. This property returns no value if the menu is not contained in a main_menu. This can occur if the menu is contained in a menu_item or context_menu, or if the menu is not contained in any menu. You can use this property to determine whether a menu is currently being used, and also to determine where.
      std::optional<xtd::ref<main_menu>> get_main_menu() const noexcept;
      
      /// @brief Merges the MenuItem objects of one menu with the current menu.
      /// @param menu_src The menu whose menu items are merged with the menu items of the current menu.
      /// @exception std::invalid_argument It was attempted to merge the menu with itself.
      virtual void merge_menu(const menu& menu_src);
      
      /// @brief Returns a string that represents the menu control.
      /// @return A string that represents the current menu.
      /// @remarks The to_string method returns a string that includes the type and the number of items in the menu_items property of the control.
      xtd::string to_string() const noexcept override;
      /// @}
      
    protected:
      friend menu_item;
      
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the Menu class.
      /// @remarks Since menu is an abstract class, only inherited classes can call the menu constructor.
      menu();
      /// @brief Initializes a new instance of the Menu class.
      /// @param items An array of type MenuItem containing the objects to add to the menu.
      /// @remarks Since menu is an abstract class, only inherited classes can call the menu constructor.
      explicit menu(const menu_item_collection& items);
      /// @}
      
      /// @cond
      explicit menu(const std::initializer_list<menu_item_ref>& items);
      explicit menu(const std::vector<menu_item_ref>& items);
      menu(menu&& rhs);
      menu(const menu&) = default;
      menu& operator =(const menu&) = default;
      /// @endcond
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Copies the menu that is passed as a parameter to the current menu.
      /// @param menu_src The Menu to copy.
      /// @remarks This method copies the entire list of menuItem objects (stored in the menu passed in to menu_src) into the current menu. You can use this method in your derived class to clone menu_item objects. They can then be reused by other classes that derive from menu, such as main_menu, context_menu, and menu_item.
      void clone_menu(const menu& menu_src);
      
      /// @brief Creates a new handle to the Menu.
      /// @return A handle to the menu if the method succeeds; otherwise, 0.
      virtual intptr create_menu_handle() = 0;
      
      /// @brief Destroys the handle to the Menu.
      /// @param handle A handle to the menu.
      virtual void destroy_menu_handle(intptr handle);
      
      virtual void on_item_added(size_t pos, menu_item_ref item);
      virtual void on_item_removed(size_t pos, menu_item_ref item);
      /// @}
      
      /// @cond
      virtual void create_menu();
      virtual void destroy_menu();
      void recreate_menu();
      
      xtd::sptr<data> data_;
      static std::map<intptr, xtd::ref<menu>> handles_;
      /// @endcond
    };
  }
}
