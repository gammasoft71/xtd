/// @file
/// @brief Contains xtd::forms::about_dialog dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.hpp"
#include "component.hpp"
#include "dialog_appearance.hpp"
#include "iwin32_window.hpp"
#include "tab_page.hpp"
#include "tab_control.hpp"
#include <xtd/drawing/icon>
#include <xtd/reflection/assembly>
#include <xtd/delegate>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/about_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_about_dialog_w.png   |  @image html dialog_about_dialog_m.png   |  @image html dialog_about_dialog_g.png   |
    /// | Dark  |  @image html dialog_about_dialog_wd.png  |  @image html dialog_about_dialog_md.png  |  @image html dialog_about_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog.
    /// @include about_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog with dialog_styledialog_style to system.
    /// @include about_dialog_system.cpp
    class forms_export_ about_dialog final : public xtd::forms::component {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents an author collection.
      using author_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents an artist collection.
      using artist_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents a documenter collection.
      using documenter_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents a translator collection.
      using translator_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents user tab page collection.
      using user_tab_page_collection = tab_control::tab_page_collection;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog();
      /// @}
      
      /// @cond
      ~about_dialog();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the artists array.
      /// @return The artists array.
      [[nodiscard]] auto artists() const noexcept -> const artist_collection&;
      /// @brief Gets the artists array.
      /// @return The artists array.
      [[nodiscard]] auto artists() noexcept -> artist_collection&;
      /// @brief Sets the artists array.
      /// @param artists The artists array.
      /// @return Current about_dialog instance.
      auto artists(const artist_collection& artists) -> about_dialog&;
      
      /// @brief Gets the authors array.
      /// @return The author array.
      [[nodiscard]] auto authors() const noexcept -> const author_collection&;
      /// @brief Gets the authors array.
      /// @return The authors array.
      [[nodiscard]] auto authors() noexcept -> author_collection&;
      /// @brief Sets the authors array.
      /// @param authors The authors array.
      /// @return Current about_dialog instance.
      auto authors(const author_collection& authors) -> about_dialog&;
      
      /// @brief Gets the product copyright.
      /// @return The product copyright.
      [[nodiscard]] auto copyright() const noexcept -> xtd::string;
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_dialog instance.
      auto copyright(const xtd::string& copyright) -> about_dialog&;
      
      /// @brief Gets the product description.
      /// @return The product description.
      [[nodiscard]] auto description() const noexcept -> xtd::string;
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current about_dialog instance.
      auto description(const xtd::string& description) -> about_dialog&;
      
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      [[nodiscard]] auto documenters() const noexcept -> const documenter_collection&;
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      [[nodiscard]] auto documenters() noexcept -> documenter_collection&;
      /// @brief Sets the documentation writers array.
      /// @param documenters The documentation writers array.
      /// @return Current about_dialog instance.
      auto documenters(const documenter_collection& documenters) -> about_dialog&;
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      [[nodiscard]] auto dialog_appearance() const noexcept -> xtd::forms::dialog_appearance;
      /// @brief Sets the dialog appearance.
      /// @param dialog_appearance One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current about_dialog instance.
      auto dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) -> about_dialog&;
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      [[nodiscard]] auto icon() const noexcept -> xtd::drawing::icon;
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current about_dialog instance.
      auto icon(const xtd::drawing::icon& icon) -> about_dialog&;
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current about_dialog instance.
      auto icon(const xtd::drawing::image& image) -> about_dialog&;
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current about_dialog instance.
      auto icon(const xtd::drawing::bitmap& bitmap) -> about_dialog&;
      
      /// @brief Gets the product license.
      /// @return The product license.
      [[nodiscard]] auto license() const noexcept -> xtd::string;
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_dialog instance.
      auto license(const xtd::string& license) -> about_dialog&;
      
      /// @brief Gets the product long version.
      /// @return The product long version.
      [[nodiscard]] auto long_version() const noexcept -> xtd::string;
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      auto long_version(const xtd::string& long_version) -> about_dialog&;
      
      /// @brief Gets the product name.
      /// @return The product name.
      [[nodiscard]] auto name() const noexcept -> xtd::string;
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_dialog instance.
      auto name(const xtd::string& name) -> about_dialog&;
      
      /// @brief Gets the translators array.
      /// @return The translators array.
      [[nodiscard]] auto translators() const noexcept -> const translator_collection&;
      /// @brief Gets the translators array.
      /// @return The translators array.
      [[nodiscard]] auto translators() noexcept -> translator_collection&;
      /// @brief Sets the translators array.
      /// @param translators The translators array.
      /// @return Current about_dialog instance.
      auto translators(const translator_collection& translators) -> about_dialog&;
      
      /// @brief Gets the collection of user tab pages in this about box.
      /// @return A xtd::forms::about_dialog::user_tab_page_collection that contains the control objects in this about box.
      /// @remarks This property is used to add user tab pages in this about dialog.
      [[nodiscard]] auto user_tab_pages() noexcept -> user_tab_page_collection&;
      /// @brief Gets the collection of user tab pages in this about box.
      /// @return A xtd::forms::about_dialog::user_tab_page_collection that contains the control objects in this about box.
      /// @remarks This property is used to add user tab pages in this about dialog.
      [[nodiscard]] auto user_tab_pages() const noexcept -> const user_tab_page_collection&;
      
      /// @brief Gets the product version.
      /// @return The product version.
      [[nodiscard]] auto version() const noexcept -> xtd::string;
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      auto version(const xtd::string& version) -> about_dialog&;
      
      /// @brief Gets the product website.
      /// @return The website.
      [[nodiscard]] auto website() const noexcept -> xtd::string;
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_dialog instance.
      auto website(const xtd::string& website) -> about_dialog&;
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      [[nodiscard]] auto website_label() const noexcept -> xtd::string;
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_dialog instance.
      auto website_label(const xtd::string& website_label) -> about_dialog&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      auto reset() noexcept -> void;
      
      /// @brief Runs about dialog box.
      auto show() -> void;
      /// @brief Runs about dialog box with specified owner.
      /// @param owner The owner of the about box dialog.
      auto show(const iwin32_window& owner) -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a new xtd::forms::about_dialog from specified assembly.
      /// @param assembly The xtd::reflection::assembly object containing the information for filling in the dialog.
      /// @return New xtd::forms::about_dialog with xtd::reflection::assembly informations.
      [[nodiscard]] static auto from_assembly(const xtd::reflection::assembly& assembly) -> about_dialog;
      /// @brief Create a new xtd::forms::about_dialog from executing xtd::reflection::assembly informations.
      /// @return New xtd::forms::about_dialog with executing xtd::reflection::assembly informations.
      [[nodiscard]] static auto from_executing_assembly_informations() -> about_dialog;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
