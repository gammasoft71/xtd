/// @file
/// @brief Contains xtd::forms::menu_item menu.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "menu.hpp"
#include "menu_item_kind.hpp"
#include "shortcut.hpp"
#include <xtd/drawing/image>
#include <xtd/event>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class main_menu;
    class context_menu;
    /// @endcond
    
    /// @brief Represents an individual item that is displayed within a main_menu or context_menu.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/menu_item>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    class forms_export_ menu_item : public xtd::forms::menu {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a menu_item with a blank caption.
      /// @remarks Once you have created a blank menu_item using this constructor, you can use the properties and methods of the menu_item class to specify the appearance and behavior of your menu_item.
      menu_item();
      /// @brief Initializes a new instance of the menu_item class with a specified caption for the menu item.
      /// @param text The caption for the menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      explicit menu_item(const xtd::string& text);
      /// @brief Initializes a new instance of the class with a specified caption, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, and image menu item.
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image);
      /// @brief Initializes a new instance of the class with a specified caption, and image menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, and kind the menu item.
      /// @param text The caption for the menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::forms::menu_item_kind kind);
      /// @brief Initializes a new instance of the class with a specified caption, kind the menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, image menu item, and kind the menu item.
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      /// @brief Initializes a new instance of the class with a specified caption, image menu item, kind the menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, kind the menu item and checked.
      /// @param text The caption for the menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::forms::menu_item_kind kind, bool checked);
      /// @brief Initializes a new instance of the class with a specified caption, kind the menu item, checked, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, image menu item, kind the menu item, and checked
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      /// @brief Initializes a new instance of the class with a specified caption, image menu item, kind the menu item, checked, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption and event handler for the Click event of the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, and image menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, and image menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, and kind the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, kind the menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, image menu item, and kind the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, image menu item, kind the menu item, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, kind the menu item and checked.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, kind the menu item, checked, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, image menu item, kind the menu item, and checked
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      /// @brief Initializes a new instance of the class with a specified caption, event handler, image menu item, kind the menu item, checked, and associated shortcut key for the menu item.
      /// @param text The caption for the menu item.
      /// @param on_click The event_handler that handles the Click event for this menu item.
      /// @param image A xtd::drawing::image menu item.
      /// @param kind One of the xtd::forms::menu_item_kind value.
      /// @param checked `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @param shortcut One of the xtd::forms::shortcut values.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      menu_item(const xtd::string& text, xtd::event_handler on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      
      /// @cond
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click) : menu_item(text, xtd::event_handler(on_click)) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, xtd::forms::shortcut shortcut) : menu_item(text, xtd::event_handler(on_click), shortcut) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, const xtd::drawing::image& image) : menu_item(text, xtd::event_handler(on_click), image) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut) : menu_item(text, xtd::event_handler(on_click), image, shortcut) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind) : menu_item(text, xtd::event_handler(on_click), kind) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut) : menu_item(text, xtd::event_handler(on_click), kind, shortcut) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, bool checked) : menu_item(text, xtd::event_handler(on_click), kind, checked) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu_item(text, xtd::event_handler(on_click), kind, checked, shortcut) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked) : menu_item(text, xtd::event_handler(on_click), image, kind, checked) {}
      template<typename delegate_type>
      menu_item(const xtd::string& text, delegate_type on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut) : menu_item(text, xtd::event_handler(on_click), image, kind, checked, shortcut) {}
      menu_item(const xtd::string& text, const std::initializer_list<const_menu_item_ref>& items);
      /// @endcond
      
      /// @brief Initializes a new instance of the class with a specified caption and an array of submenu items defined for the menu item.
      /// @param text The caption for the menu item.
      /// @param items An array of menu_item objects that contains the submenu items for this menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      /// @remarks The items parameter enables you to assign an array of menu items to define a submenu of this menu item. Each item in the array can also have an array of menu items assigned to it. This enables you to create complete menu structures and assign them to the constructor for the menu item.
      menu_item(const xtd::string& text, const std::vector<menu_item_ref>& items);
      menu_item(menu_item&&) = default;
      menu_item(const menu_item&) = default;
      menu_item& operator =(const menu_item&) = default;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating the Windows identifier for this menu item.
      /// @return The Windows identifier for this menu item.
      [[nodiscard]] auto menu_id() const noexcept -> xtd::intptr;
      
      /// @brief Gets a value indicating whether a check mark appears next to the text of the menu item.
      /// @return `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      [[nodiscard]] auto checked() const noexcept -> bool;
      /// @brief Sets a value indicating whether a check mark appears next to the text of the menu item.
      /// @param value `true` if there is a check mark next to the menu item; otherwise, `false`. The default is `false`.
      /// @return Current menu_item.
      auto checked(bool value) -> menu_item&;
      
      /// @brief Gets a value indicating whether the menu item is enabled.
      /// @return `true` if the menu item is enabled; otherwise, `false`. The default is `true`.
      [[nodiscard]] auto enabled() const noexcept -> bool;
      /// @brief Gets a value indicating whether the menu item is enabled.
      /// @param value `true` if the menu item is enabled; otherwise, `false`. The default is `true`.
      /// @return Current menu_item.
      auto enabled(bool value) -> menu_item&;
      
      [[nodiscard]] auto is_parent() const noexcept -> bool override;
      
      /// @brief Gets a value that represents the kind of menu item.
      /// @return One of the xtd::forms::menu_item_kind value.
      [[nodiscard]] auto kind() const noexcept -> xtd::forms::menu_item_kind;
      /// @brief Sets a value that represents the kind of menu item.
      /// @param value One of the xtd::forms::menu_item_kind value.
      /// @return Current menu_item.
      auto kind(xtd::forms::menu_item_kind value) -> menu_item&;
      
      /// @brief Gets a value indicating the shortcut key associated with the menu item.
      /// @return One of the xtd::forms::shortcut values. The default is xtd::forms::shortcut::none.
      [[nodiscard]] auto shortcut() const noexcept -> xtd::forms::shortcut;
      /// @brief Sets a value indicating the shortcut key associated with the menu item.
      /// @param value One of the xtd::forms::shortcut values. The default is xtd::forms::shortcut::none.
      /// @return Current menu_item.
      auto shortcut(xtd::forms::shortcut value) -> menu_item&;
      
      /// @brief Gets a value indicating the caption of the menu item.
      /// @return The text caption of the menu item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      [[nodiscard]] auto text() const noexcept -> const xtd::string&;
      /// @brief Sets a value indicating the caption of the menu item.
      /// @param value The text caption of the menu item.
      /// @return Current menu_item.
      /// @remarks When you specify a caption for your menu item with the text parameter, you can also specify an access key by placing an '&' before the character to be used as the access key. For example, to specify the "F" in "File" as an access key, you would specify the caption for the menu item as "&File". You can use this feature to provide keyboard navigation for your menus.
      /// @remarks Setting the text parameter to "-" causes your menu item to be displayed as a separator (a horizontal line) rather than a standard menu item.
      auto text(const xtd::string& value) -> menu_item&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Generates a xtd::forms::menu_item::click event for the xtd::forms::menu_item, simulating a click by a user.
      /// @remarks You can use this menu to activate a menu item through code without passing any event information. For example, if you want to activate a menu item based on an action that occurs in your application, you can call the xtd::forms::menu_item::perform_click method for that xtd::forms::menu_item.
      void perform_click();
      
      /// @brief Returns a string that represents the menu control.
      /// @return A string that represents the current menu.
      /// @remarks The to_string method returns a string that includes the type and the number of items in the menu_items property of the control.
      [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the menu item is clicked or selected using a shortcut key or access key defined for the menu item.
      /// @remarks The xtd::forms::menu_item::click event occurs when this xtd::forms::menu_item is clicked by the user. This event also occurs if the user selects the menu item using the keyboard and presses the Enter key. It can also occur if an access key or shortcut key is pressed that is associated with the xtd::forms::menu_item.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<menu_item, xtd::event_handler> click;
      /// @}
      
    protected:
      friend main_menu;
      friend context_menu;
      
      /// @name Protected Methods
      
      /// @{
      auto create_menu_handle() -> xtd::intptr override;
      auto destroy_menu_handle(xtd::intptr handle) -> void override;
      
      /// @brief Raises the Click event.
      /// @param e An xtd::event_args that contains the event data.
      /// @remarks Raising an event invokes the event handler through a delegate.
      virtual auto on_click(const event_args& e) -> void;
      
      auto on_item_added(xtd::usize pos, menu_item_ref item) -> void override;
      auto on_item_removed(xtd::usize pos, menu_item_ref item) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
